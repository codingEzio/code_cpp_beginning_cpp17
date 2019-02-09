#include <iostream>
using namespace std;

int main()
{
    /*
        The old way is using 'typedef'.
        I'll just skip it since the author doesn't recommend it :D

        Just use common sense when deciding if an alias should be used or not.
    */

    typedef unsigned long long ReallyBigOne;  // Not recommended 
    using ReallyBigOnes = unsigned long long;

    unsigned long long NumberOne{100L};
    ReallyBigOnes NumberTwo{100L};

    cout << "NumberOne == NumberOne -> "
         << boolalpha
         << static_cast<bool>(NumberOne == NumberTwo) << endl;
}