#include "builder.h"

ostream &operator<<(ostream &out, const Person &p)
{
    out << p.address_ << ", " << p.zipcode_ << ", " << p.city_ << ", " << p.company_;
    return out;
}

int main()
{
    Person p = Person::create()
                   .lives()
                   .at("1400 231st CT NE")
                   .with_zipcode("98074")
                   .in("Sammamish")
                   .works()
                   .at("Microsoft")
                   .as_a("Developer")
                   .earning(0);

    cout << p << endl;
}
