#include <iostream>
using namespace std;

int main()
{
    // Having a fixed int value of type 'int' by default
    enum class MyWeekday
    {
        Monday = 1, // If the val wasn't provided, it'll be like 0,1,2,3,4
        Tuesday,
        Wednesday,
        Thursday,
        Friday
    };

    MyWeekday today{MyWeekday::Friday};

    // We do need to cast it before printing
    cout << "The 1st  day is " << static_cast<int>(MyWeekday::Monday) << "\n"
         << "The last day is " << static_cast<int>(MyWeekday::Friday) << endl;

    enum class WeirdDayMultiStar
    {
        Mon = 3,
        Tue,
        Wed,
        Thu,
        Fri = 1,
        Sat,
        Sun
    };
    cout << "The 'Tue' (4) day is " << static_cast<int>(WeirdDayMultiStar::Tue) << "\n"
         << "The 'Sat' (2) day is " << static_cast<int>(WeirdDayMultiStar::Sat) << endl;

    enum class WeirdDaySameValAndAssign
    {
        Monday = 1,
        Mon = 1,
        FirstDay = Mon, // Define the value in terms of a prev enumerator
        Tue,
        Wed
    };
    cout << "The 'FirstDay' (1) day is " << static_cast<int>(WeirdDaySameValAndAssign::FirstDay) << "\n"
         << "The 'Wed'      (3) day is " << static_cast<int>(WeirdDaySameValAndAssign::Wed) << endl;

    enum class Punctuation : char
    {
        Comma = ',',
        Exclamation = '!',
        Question = '?'
    };

    cout << "The puncs (,!?): [ "
         << static_cast<char>(Punctuation::Comma) << " "
         << static_cast<char>(Punctuation::Exclamation) << " "
         << static_cast<char>(Punctuation::Question) << " ]"
         << endl;
}
