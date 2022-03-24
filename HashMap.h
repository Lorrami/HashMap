#pragma once

#include "LinkedList/LinkedList.h"

template <typename Key, typename Value>
struct HashMap {
private:
    struct Node {
        Key key;
        Value value;
    };
public:
    HashMap();
    ~HashMap();
    void Add(Key key, Value value);
    void Remove(Key key);
    Value &Find(Key key);
    void Print();
private:
    int m_Capacity = 3;
    int m_Size = 3;
    LinkedList<Node> *m_Table = nullptr;
private:
    void AddMemory();
};

template<typename Key, typename Value>
HashMap<Key, Value>::HashMap() {
    m_Table = new LinkedList<Node>[m_Capacity];
}
template<typename Key, typename Value>
HashMap<Key, Value>::~HashMap() {
    delete[] m_Table;
}
template <typename Key, typename Value>
void HashMap<Key, Value>::AddMemory() {
    m_Capacity *= 2;
    LinkedList<Node> *tmp =m_Table;
    m_Table = new LinkedList<Node>[m_Capacity];
    for (auto i = 0; i < m_Size; ++i) {
        for (auto it : tmp[i]) {
            std::hash<Key> hasher;
            size_t hash = hasher(it.key) % m_Capacity;
            m_Table[hash].Add(it);
        }
    }
    delete[] tmp;
}
template<typename Key, typename Value>
void HashMap<Key, Value>::Add(Key key, Value value) {
    if (m_Size >= m_Capacity)
        AddMemory();
    std::hash<Key> hasher;
    size_t hash = hasher(key) % m_Capacity;

    Node newNode = Node();
    newNode.key = key;
    newNode.value = value;
    m_Table[hash].Add(newNode);

    m_Size++;
}
template<typename Key, typename Value>
void HashMap<Key, Value>::Remove(Key key) {
    std::hash<Key> hasher;
    size_t hash = hasher(key) % m_Capacity;
    bool isFirstDeleted = false;

    if (m_Table[hash].Size() > 0) {
        if (m_Table[hash].begin()->key == key) {
            std::cout << "First delited" << std::endl;
            m_Size--;
            m_Table[hash] = LinkedList<Node>();
            isFirstDeleted = true;
        }
        if (!isFirstDeleted) {
            auto tmp = m_Table[hash].begin();
            for (auto it = ++m_Table[hash].begin(); it != m_Table[hash].end(); ++it) {
                if (it->key == key) {
                    m_Table[hash].RemoveAfter(tmp);
                    //Remove(key);
                    m_Size--;
                    break;
                } else
                    tmp = it;
            }
        }
    }
}
template<typename Key, typename Value>
Value &HashMap<Key, Value>::Find(Key key) {
    std::hash<Key> hasher;
    size_t hash = hasher(key) % m_Capacity;

    for (auto it = ++m_Table[hash].begin(); it != m_Table[hash].end(); ++it) {
        if (it->key == key)
            return it->value;
    }
}
template <typename Key, typename Value>
void HashMap<Key, Value>::Print() {
    for (int i = 0; i < m_Capacity; i++) {
        if (m_Table[i].Size() > 0) {
            for (auto it = m_Table[i].begin(); it != m_Table[i].end(); ++it) {
                std::cout << it->key << " --> " << it->value << "  ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Empty" << std::endl;
        }
    }
}