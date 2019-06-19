#include "ascii_component.h"

void AsciiComponent::setChar(char ch)
{
    c = ch;
}

char AsciiComponent::getChar() const
{
    return c;
}

void AsciiComponent::setLevel(int l)
{
    level = l;
}

int AsciiComponent::getLevel() const
{
    return level;
}
