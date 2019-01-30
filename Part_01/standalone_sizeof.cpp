#include <iostream>
using namespace std;

int main()
{
    int height{50};

    // Well.. Just use `sizeof()` is fine ...
    cout << "The height occupies " << sizeof height << " bytes.\n"
         << "Type 'long long' occupies " << sizeof(long long) << " bytes.\n"
         << "The result of the expr 'height * height / 2' occupies "
         << sizeof(height * height / 2) << " bytes.\n"
         << endl;
}