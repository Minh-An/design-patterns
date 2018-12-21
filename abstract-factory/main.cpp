#include "factory.h"

int main()
{
    DrinkFactory df;
    auto tea = df.MakeDrink("tea", 100);
    auto coffee = df.MakeDrink("coffee", 200);
}