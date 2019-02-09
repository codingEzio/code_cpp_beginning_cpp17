#include <iostream>
using namespace std;

int count1{88};
double count2{88.8};
long count3{888L};

int main()
{
    int count1{10};
    int count3{30};

    // My guess is 10, 88, 88.8
    cout << "Value of outer 'count1'    = " << count1 << endl;
    cout << "Value of global 'count1'   = " << ::count1 << endl;
    cout << "Value of global 'count2'   = " << count2 << endl;

    {
        int count1{10};
        int count2{20};

        // My guess is 10, 88, 20, 88.8
        cout << "\nValue of inner 'count1'    = " << count1 << endl;
        cout << "Value of global 'count1'   = " << ::count1 << endl;
        cout << "Value of inner 'count2'    = " << count2 << endl;
        cout << "Value of global 'count2'   = " << ::count2 << endl;

        count1 = ::count1 + 3;
        ++::count1;

        // My guess is 91, 89
        cout << "\nValue of inner 'count1'    = " << count1 << endl;
        cout << "Value of global 'count1'   = " << ::count1 << endl;

        count3 += count2;
    }

    // My guess is 10, 30 (WRONG)
    //  The 'count3' was altered in the {..} block
    //  That is, the value of 'count3' should be 50 (local count3 + local count2)
    cout << "\nValue of outer 'count1'    = " << count1 << endl
         << "Value of outer 'count3'    = " << count3 << endl;

    // My guess is 888, 88.8
    cout << "Value of global 'count3'   = " << ::count3 << endl;
    cout << "Value of global 'count3'   = " << count2 << endl;
}