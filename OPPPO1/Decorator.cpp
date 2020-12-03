#include "Decorator.h"

Decorator::Decorator(Figures* f)
{
    {
        figure = f;
    }
}

void Decorator::getData(std::ostream& os)
{
    figure->getData(os);
}
