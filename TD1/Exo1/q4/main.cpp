#include <iostream>
#include <string>
using namespace std;

class my_class
{
private:
    string texte;

public:
    my_class()
    {
        texte = "";
    }
    
    my_class(string t)
    {
        texte = t;
    }

    void print_my_element()
    {
        cout << texte << endl;
    }
};

int main()
{
    my_class a;
    my_class b("Hello World !");

    a.print_my_element();
    b.print_my_element();

    return 0;
}
