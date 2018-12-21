#include "drink.h"
#include <map>
#include <string>

struct HotDrinkFactory
{
    virtual unique_ptr<Drink> Make(int volume) = 0;
};

struct TeaFactory : HotDrinkFactory
{
    unique_ptr<Drink> Make(int volume) override
    {
        unique_ptr<Tea> drink = make_unique<Tea>();
        drink->prepare(volume);
        return drink;
    }
};

struct CoffeeFactory : HotDrinkFactory
{
    unique_ptr<Drink> Make(int volume) override
    {
        unique_ptr<Coffee> drink = make_unique<Coffee>();
        drink->prepare(volume);
        return drink;
    }
};

struct DrinkFactory
{
  public:
    DrinkFactory()
    {
        factories["tea"] = make_unique<TeaFactory>();
        factories["coffee"] = make_unique<CoffeeFactory>();
    }

    unique_ptr<Drink> MakeDrink(string type, int volume)
    {
        unique_ptr<Drink> drink;
        drink = factories[type]->Make(volume);
        return drink;
    }

  private:
    map<string, unique_ptr<HotDrinkFactory>> factories;
};