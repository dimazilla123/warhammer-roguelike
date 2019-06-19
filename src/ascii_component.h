#ifndef ASCII_COMPONENT_H
#define ASCII_COMPONENT_H

#include "component.h"

class AsciiComponent : public Component {
public:
    AsciiComponent() {}
    AsciiComponent(char ch) : c(ch) {}
    void setChar(char ch);
    char getChar() const;
private:
    char c;
};

#endif
