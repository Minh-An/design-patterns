#include "person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

struct PersonBuilderBase
{
  protected:
    Person &p_;
    explicit PersonBuilderBase(Person &p) : p_(p){};

  public:
    operator Person()
    {
        return move(p_);
    }

    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;
};

struct PersonBuilder : public PersonBuilderBase
{
    Person p_;
    PersonBuilder() : PersonBuilderBase{p_} {};
};

struct PersonAddressBuilder : public PersonBuilderBase
{
  public:
    explicit PersonAddressBuilder(Person &p) : PersonBuilderBase{p} {};

    PersonAddressBuilder &at(string address)
    {
        p_.address_ = address;
        return *this;
    };
    PersonAddressBuilder &with_zipcode(string zipcode)
    {
        p_.zipcode_ = zipcode;
        return *this;
    };
    PersonAddressBuilder &in(string city)
    {
        p_.city_ = city;
        return *this;
    };
};

struct PersonJobBuilder : public PersonBuilderBase
{
  public:
    explicit PersonJobBuilder(Person &p) : PersonBuilderBase{p} {};

    PersonJobBuilder &at(string company)
    {
        p_.company_ = company;
        return *this;
    };
    PersonJobBuilder &as_a(string title)
    {
        p_.title_ = title;
        return *this;
    };
    PersonJobBuilder &earning(int income)
    {
        p_.income_ = income;
        return *this;
    };
};
