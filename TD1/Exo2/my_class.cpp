#include <iostream>
#include "my_class.h"
using namespace std;

my_class::my_class()
{
    texte = "";
}

my_class::my_class(string t)
{
    texte = t;
}

void my_class::print_my_element()
{
    cout << texte << endl;
}
