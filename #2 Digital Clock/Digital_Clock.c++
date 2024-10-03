#include <iostream>
#include <cstdlib>   // for system()
#include <Windows.h> // for sleep()

using namespace std;

int main()
{
    // Variables
    int Hours = 0;
    int Min   = 0;
    int Sec   = 0;
    // end of variables

    // Enter time values
    cout << "Hour: ";
    cin >> Hours;

    cout << "Min: ";
    cin >> Min;

    cout << "Sec: ";
    cin >> Sec;
    cout << endl;

    // start a while loop to print time
    while (true)
    {
        system("cls"); // cls ==> clear screen

        if (Sec > 59)
        {
            Min++;
            Sec = 0;
        }

        if (Min > 59)
        {
            Hours++;
            Min = 0;
        }

        if (Hours > 11)
        {
            Hours = 0;
        }

        cout << Hours << " : " << Min << " : " << Sec;
        Sec++;

        Sleep(1000); // 1000 milisecond (1 Second) 
    }
}