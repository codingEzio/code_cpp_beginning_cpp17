#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double fish_factor{2.0 / 0.5};
    const double inches_per_foot{12.0};
    const double pi{3.1415926535};

    double fish_count{};
    double fish_length{};

    cout << "Enter the number of fishes you wanna keep: ";
    cin >> fish_count;
    cout << "Enter the average fish length in inches: ";
    cin >> fish_length;

    fish_length /= inches_per_foot;

    const double pond_area{fish_count * fish_length * fish_factor};
    const double pond_diameter{2.0 * sqrt(pond_area / pi)};

    cout << "\nPond diameter requried for " << fish_count
         << " fish is " << pond_diameter << " feet.\n"
         << endl;
}