#ifndef CHOICE_H
#define CHOICE_H

#include <string>

enum class Choice {
    Moons,
    Store,
    Inventory,
    Exit,
    Unknown
};


Choice ConvertStringToChoice(std::string input);

#endif // CHOICE_H
