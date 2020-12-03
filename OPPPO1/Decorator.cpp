#include "Decorator.h"

Decorator::Decorator(Figures* f)
{
    {
        figure = f;
    }
}

void Decorator::getData()
{
    figure->getData();
}
