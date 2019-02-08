#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    /*
        I don't really looked into the details, sry :P
    */

    unsigned int red{0xFF0000u};   // red
    unsigned int white{0xFFFFFFu}; // white

    cout << hex
         << setfill('0');

    cout << "Try out bitwise complement, AND and OR operators:";
    cout << "\nInitial values:  red     = " << setw(8) << red;
    cout << "\nComplement:      ~red    = " << setw(8) << ~red;

    cout << "\nInitial value:   white   = " << setw(8) << white;
    cout << "\nComplement:      ~white  = " << setw(8) << ~white;

    cout << "\nBitwise AND: red & white = " << setw(8) << (red & white);
    cout << "\nBitwise OR:  red | white = " << setw(8) << (red | white);

    cout << "\n\nNow try successive exclusive OR opts:";
    unsigned int mask{red ^ white};
    cout << "\n mask = red & white  = " << setw(8) << mask;
    cout << "\n mask ^ red          = " << setw(8) << (mask ^ red);
    cout << "\n mask ^ white        = " << setw(8) << (mask ^ white);

    unsigned int flags{0xFF};
    unsigned int bit1mask{0x1};
    unsigned int bit6mask{0b100000};
    unsigned int bit20mask{1u << 19};

    cout << "\n\nUse masks to select/set a particular flag bit:";
    cout << "\n Select bit 1 from flags     :" << setw(8) << (flags & bit1mask);
    cout << "\n Select bit 6 from flags     :" << setw(8) << (flags & bit6mask);
    cout << "\n Switch off bit 6 in flags   :" << setw(8) << (flags &= ~bit6mask);
    cout << "\n Switch on bit 20 in flags   :" << setw(8) << (flags |= bit20mask) << endl;
}