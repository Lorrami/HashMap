#include <iostream>
#include "HashMap.h"

int main()
{
    HashMap<int, std::string> Map;

    Map.Add(4, "Lorrami");
    Map.Add(14, "BloodRedTape");
    Map.Add(17, "Jeytery");
    Map.Add(35, "Abobus");
    Map.Add(69, "KEp");
    Map.Add(71, "tteaman");
    Map.Add(83, "Andrew");
    Map.Add(89, "Dasha");
    Map.Add(101, "Gavnuke");
    Map.Add(134, "Klukwish");
    Map.Add(146, "Chel1");
    Map.Add(800, "Content");


    Map.Print();

    return 777;
}
