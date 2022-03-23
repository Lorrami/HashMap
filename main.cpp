#include <iostream>
#include "HashMap.h"

int main()
{
    HashMap<int, std::string> Map;

    Map.Add(4, "Lorrami");

    Map.Print();

    return 777;
}
