#pragma once

#include <string>
#include <iostream>

using namespace std;

struct PersonBuilder;

struct Person
{
    string address_;
    string zipcode_;
    string city_;

    string company_;
    string title_;
    int income_;

    static PersonBuilder create();
    Person(){};
};