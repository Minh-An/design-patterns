#include <iostream>
#include <memory>

using namespace std;

struct Drink
{
    virtual void prepare(int volume) = 0;
};

struct Tea : Drink
{
    void prepare(int volume) override
    {
        cout << "Making tea... volume = " << volume << endl;
    }
};

struct Coffee : Drink
{
    void prepare(int volume) override
    {
        cout << "Making coffee... volume = " << volume << endl;
    }
};