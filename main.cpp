#include <iostream>
#include "HashMap.h"

int main()
{
    HashMap<int, std::string> Map;

    for (int i = 0; i < 1000; i++) {
        Map.Add(i, "Test");
    }
    for (int i = 0; i < 1000; i++) {
        Map.Remove(i);
    }
    Map.Print();

    //std::cout << Map.Find(800);

    return 777;
}
