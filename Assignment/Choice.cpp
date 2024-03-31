#include "Choice.h"
#include <cctype>
#include <string>


std::string toLowerAndRemoveSpaces(const std::string& str) {
    std::string result;

    for (char c : str) {
        if (!std::isspace(c)) {
            result += std::tolower(c);
        }
    }
    return result;

    
}

Choice ConvertStringToChoice(const std::string input)
{
    std::string lowercase = toLowerAndRemoveSpaces(input);

    if (lowercase == "moons")
        return Choice::Moons;
    else if (lowercase == "store")
        return Choice::Store;
    else if (lowercase == "inventory")
        return Choice::Inventory;
    else if (lowercase == "exit")
        return Choice::Exit;
    else
        return Choice::Unknown; // Handle invalid input
}
