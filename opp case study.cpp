#include <iostream>
using namespace std;

class Date {
    int day, month, year;

    bool isValid(int d, int m, int y) {
        int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
            daysInMonth[2] = 29;

        if (m < 1 || m > 12)
            return false;

        if (d < 1 || d > daysInMonth[m])
            return false;

        return true;
    }

public:
    Date() {
        day = 1;
        month = 1;
        year = 2000;
    }

    Date(int d, int m, int y) {
        if (isValid(d, m, y)) {
            day = d;
            month = m;
            year = y;
        } else {
            cout << "Invalid date!" << endl;
            day = 1;
            month = 1;
            year = 2000;
        }
    }

    void display() {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    Date d1;            
    d1.display();

    Date d2(29, 2, 2020);   
    d2.display();

    Date d3(31, 4, 2025);   
    d3.display();

    Date d4(15, 12, 2005);  
    d4.display();

    return 0;
}
