//5.20
#include <iostream>
const int Cities = 5;
const int Years = 4;

int main() {
    using namespace std;
    const char *cities[Cities] = {
        "Gri",
        "Gribb",
        "New Gribb",
        "San Grib",
        "Gribble"
    };
    
    int maxtemps [Years][Cities] = {
        {93, 35, 23, 36, 90},
        {70, 75, 23, 36, 90},
        {48, 48, 23, 36, 90},
        {96, 80, 23, 36, 90},
    };
    
    cout << "Maximum temperatures for 2008 - 2011\n\n";
    for (int city = 0; city < Years ; ++city){
        cout << cities[city] << ":\t";
        for (int year = 0; year < Years; ++ year){
            cout << maxtemps[year][city] << "\t";
        }
        cout << endl;
    }
    return 0;
    
}

