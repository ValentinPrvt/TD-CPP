#include <iostream>
#include "my_class.h"
using namespace std;

int main()
{
    my_class a;
    my_class b("Hello World !");

    a.print_my_element();
    b.print_my_element();

    return 0;
}
