#pragma once

#include "Vector/Vector.h"
#include "LinkedList/LinkedList.h"

template <typename Key, typename Value>
struct HashMap {
private:
    struct Node {
        Key key;
        Value value;
    };

    int m_Capacity = 5;
    LinkedList<Node> **m_Table = nullptr;
public:
    HashMap();
    //~HashMap();
    void Add(Key key, Value value);
    void Remove(Key key);
    Value &Find(Key key);
    void Print();
};

template<typename Key, typename Value>
HashMap<Key, Value>::HashMap() {
    m_Table = new LinkedList<Node>*[m_Capacity];
    for(int i = 0; i < m_Capacity; i++)
        m_Table[i] = nullptr;
}

/*template<typename Key, typename Value>
HashMap<Key, Value>::~HashMap() {
    delete[] Map;

}*/

template<typename Key, typename Value>
void HashMap<Key, Value>::Add(Key key, Value value) {
    std::hash<Key> hasher;
    size_t hash = hasher(key) % m_Capacity;

    auto *nodesCollection = new LinkedList<Node>;

    Node *newNode = new Node;
    newNode->key = key;
    newNode->value = value;
    nodesCollection->Add(*newNode);

    m_Table[hash] = nodesCollection;
}

template<typename Key, typename Value>
void HashMap<Key, Value>::Remove(Key key) {
    std::hash<Key> hasher;
    size_t hash = hasher(key) % m_Capacity;

    delete m_Table[hash];
    m_Table[hash] = nullptr;
}

template<typename Key, typename Value>
Value &HashMap<Key, Value>::Find(Key key) {
    std::hash<Key> hasher;
    size_t hash = hasher(key) % m_Capacity;

    return m_Table[hash]->value;
}

template<typename Key, typename Value>
void HashMap<Key, Value>::Print() {
    for (int i = 0; i < m_Capacity; i++)
    {
        if(m_Table[i]) {
            for (auto it = m_Table[i].begin(); it != m_Table[i].end(); ++it)
                std::cout << it->key << " --> " << it->value << std::endl;
        }
        else
            std::cout << "nullptr" << std::endl;
    }
}