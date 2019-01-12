#include "builder.h"

PersonAddressBuilder PersonBuilderBase::lives() const
{
    return PersonAddressBuilder(p_);
};
PersonJobBuilder PersonBuilderBase::works() const
{
    return PersonJobBuilder(p_);
};