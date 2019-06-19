#ifndef ASCII_COMPONENT_H
#define ASCII_COMPONENT_H

#include "component.h"

class AsciiComponent : public Component {
public:
    AsciiComponent() {}
    AsciiComponent(char ch, int l) : c(ch), level(l) {}
    void setChar(char ch);
    char getChar() const;
    void setLevel(int l);
    int getLevel() const;
private:
    char c;
    int level; // 0 -- floor, 1 -- on floor (items), 2 -- upper (creatures)
};

#endif
