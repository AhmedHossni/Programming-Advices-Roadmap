// Hadhoad Course (06) DateTime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<ctime>
using namespace std;

void LocalAndUTCDateTime()
{
    time_t t = time(0); // get time now
    char* dt = ctime(&t); // convert in string form
    cout << "Local date and time is: " << dt << "\n";

    tm* gmtm = gmtime(&t);  // converting now to tm struct for UTC date/time
    dt = asctime(gmtm);
    cout << "UTC date and time is: " << dt;
}

/*
int tm_sec; // seconds of minutes from 0 to 61
int tm_min; // minutes of hour from 0 to 59
int tm_hour; // hours of day from 0 to 24
int tm_mday; // day of month from 1 to 31
int tm_mon; // month of year from 0 to 11
int tm_year; // year since 1900
int tm_wday; // days since sunday
int tm_yday; // days since January 1st
int tm_isdst; // hours of daylight savings time
*/
void DatetimeStructure()
{   
    time_t t = time(0); // get time now
    tm* now = localtime(&t);
    cout << "Year: " << now->tm_year + 1900 << endl;
    cout << "Month: " << now->tm_mon + 1 << endl;
    cout << "Day: " << now->tm_mday << endl;
    cout << "Hour: " << now->tm_hour << endl;
    cout << "Min: " << now->tm_min << endl;
    cout << "Second: " << now->tm_sec << endl;
    cout << "Week Day (Days since sunday): " << now->tm_wday << endl;
    cout << "Year Day (Days since Jan 1st): " << now->tm_yday << endl;
    cout << "hours of daylight savings:" << now->tm_isdst << endl;
}

int main()
{
    std::cout << "Hello World!\n";
}