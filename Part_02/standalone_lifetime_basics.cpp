#include <iostream>
using namespace std;

void functionX();

long value1{100L};

int main()
{
    int value2{};

    {
        int value3{};
    }
    
    functionX();
}

int value4;

void functionX()
{
    long value5{};
    int value1{10};

    cout << "Global value1  :   " << ::value1 << endl;
    cout << "Local value1   :   " << value1 << endl;
}