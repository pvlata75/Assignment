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

enum class Planet {
    Corporation,
    Prototyping,
    Insurance,
    Pledge,
    Defence
};

Choice ConvertStringToChoice(std::string input);

#endif // CHOICE_H
