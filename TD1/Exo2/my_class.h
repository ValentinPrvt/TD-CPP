#pragma once
#include <string>

class my_class
{
private:
    std::string texte;

public:
    my_class();
    my_class(std::string t);
    void print_my_element();
};
