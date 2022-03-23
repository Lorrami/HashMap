#include <iostream>
#include "HashMap.h"

int main()
{
    HashMap<int, std::string> Map;

    Map.Add(4, "Lorrami");
    Map.Add(1, "BloodRedTape");
    Map.Add(16, "Jeytery");
    Map.Add(69, "Abobus");

    Map.Remove(1);

    std::cout << Map.Find(16) << std::endl;

    Map.Print();

    return 777;
}
