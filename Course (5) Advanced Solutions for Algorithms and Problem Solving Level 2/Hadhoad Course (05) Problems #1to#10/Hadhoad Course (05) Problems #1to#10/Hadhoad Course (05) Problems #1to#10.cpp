// Hadhoad Course (05) Problems #1to#10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
// or 
// using std::cout; // قمنا باختصار cout فقط

#pragma region 01
void PrintTableheader()
{
    cout << "\t\t\t\t Multipliaction Table From 1 to 10\n" << endl;

    for (int i = 1; i <= 10; i++)
    {
        cout << "\t" << i;
    }
    cout << endl;

    cout << "-----------------------------------------------------------------------------------";
    cout << endl;
}

string GetSpacesByNumDigits(int row)
{
    if (row != 10)
        return "  ";
    else
        return " ";
}

void Problem01_WriteMultiplicationTableWithTheSameVideoStructure()
{

    PrintTableheader();

    for (int row = 1; row <= 10; row++)
    {
        cout << " " << row;
        for (int col = 1; col <= 10; col++)
        {
            cout << GetSpacesByNumDigits(row);

            if (col == 1)
                cout << "|";

            cout << "\t";
            cout << row * col;
        }
        cout << endl;
    }

}
#pragma endregion
#pragma region 02

bool IsPrimeNumber(int num)
{
    if (num <= 1)
        return false;

    if (num == 2)
        return true;

    int loopLimit = num / 2;

    for (int i = 2; i <= loopLimit; i++)
    {
        if (num % i == 0) 
            return false;
    }

    return true;
}

int TakeNumFromUser()
{
    int num;

    do
    {
        cout << "Please enter a number bigger than 0: ";
        cin >> num;

        if (num <= 0)
        {
            cout << "Invalid input! The number must be greater than 0. Try again.\n\n";
        }

    } while (num <= 0);

    return num;
}

void PrintPrimeNumbersFrom1ToN()
{
    int num = TakeNumFromUser();

    for (int i = 1; i <= num; i++)
    {
        if (IsPrimeNumber(i))
            cout << i << "\n";
    }
    cout << endl;
}
#pragma endregion
#pragma region 03

int ReadPositiveNumFromUser()
{
    int num;

    do
    {
        cout << "Please enter a number bigger than 0: ";
        cin >> num;

        if (num <= 0)
        {
            cout << "Invalid input! The number must be greater than 0. Try again.\n\n";
        }

    } while (num <= 0);

    return num;
}
bool IsPerfectNum(int num)
{

    int sum = 0;
    for (int i = 1; i <= num/2; i++)
    {
        if (num % i == 0)
            sum += i;
    }

    return (num == sum);
}

void PrintIfPerfectOrNotToUser()
{
    int num = ReadPositiveNumFromUser();

    if (IsPerfectNum(num))
        cout << num << " is a perfect number" << endl;
    else
        cout << num << " is not a perfect number" << endl;
}
#pragma endregion
#pragma region 04
void PrintAllPerfectNumbersFrom1ToN()
{
    int Num = ReadPositiveNumFromUser();

    for (int i = 1; i <= Num; i++)
    {
        if (IsPerfectNum(i))
            cout << i << endl;
    }
}
#pragma endregion
#pragma region 05

#include <string>
void WriteAllNumberDigitsInReverse()
{
    int Num = ReadPositiveNumFromUser();

    string ReverseNum = to_string(Num);

    for (int x = ReverseNum.length() - 1; x >= 0; x--)
    {
        cout << ReverseNum[x] << endl;
    }
}

// Doctor Abo-hadhoad solution
void PrintDigits()
{
    int Num = ReadPositiveNumFromUser();

    int Remainder = 0;
    while (Num != 0)
    {
        Remainder = Num % 10;
        Num = Num / 10;
        cout << Remainder << endl;
    }
}
#pragma endregion
#pragma region 06

int SumOfNumberDigits()
{
    int Num = ReadPositiveNumFromUser();
    int Remainder = 0;
    int Sum = 0;

    while (Num != 0)
    {
        Remainder = Num % 10;
        Num = Num / 10;
        Sum += Remainder;
    }
    return Sum;
}
#pragma endregion
#pragma region 07

int NumberOfDigitsInNumber(int num)
{
    if (num == 0)
        return 1;

    int NumOfDigits = 0;

    while (num != 0)
    {
        NumOfDigits++; 
        num = num / 10;
    }

    return NumOfDigits;
}
#include <cmath>
int ReversedNumber()
{
    int Num = ReadPositiveNumFromUser();
    int Remainder = 0;
    int Sum = 0;
    int NumberOfDigits = NumberOfDigitsInNumber(Num);

    while (Num != 0)
    {
        Remainder = Num % 10;
        Num = Num / 10;
        Sum += Remainder * pow(10 ,(NumberOfDigits - 1));

        NumberOfDigits--;
    }
    return Sum;
}

// Doctor Code
int DoctorReverseNumber(int Number)
{
    int Remainder = 0;  // Variable to store the last digit extracted from the number.
    int Number2 = 0;    // Variable to accumulate the reversed number.

    // Loop until there are no more digits left in Number.
    while (Number > 0)
    {
        Remainder = Number % 10;   // Extract the last digit of Number.
        Number = Number / 10;      // Remove the last digit from Number.
        Number2 = Number2 * 10 + Remainder;  // Append the digit to Number2 by shifting left and adding Remainder.
    }

    return Number2;  // Return the reversed number.
}
#pragma endregion
#pragma region 8
int DigitFreqInNumber(int num, short digit)
{
    int Remainder = 0;
    int FreqCount = 0;

    while (num != 0)
    {
        Remainder = num % 10;
        num = num / 10;

        if (Remainder == digit)
            FreqCount++;
    }
    return FreqCount;
}
#pragma endregion
#pragma region 9
void AllDigitsFreqInNum(int num)
{
    int FreqOfDigit = 0;
    for (int x = 0; x <= 9; x++)
    {
        FreqOfDigit = DigitFreqInNumber(num, x);

        if (FreqOfDigit != 0)
            cout << "Digit " << x << " Frequency is " << FreqOfDigit << " Time(s)." << endl;
    }
}
#pragma endregion
#pragma region 10
// My solve but with a little change made by gemini
void PrintDigitsInNumberFromLeftToRight(int num)
{
    if (num == 0) {
        cout << 0 << endl;
        return;
    }

    int NumberOfDigitsInNum = NumberOfDigitsInNumber(num);
    int NumberToDivideBy = pow(10, NumberOfDigitsInNum - 1);

    // (Gemini)
    // التعديل هنا: نضمن أن نمر على كل الخانات حتى الآحاد
    while (NumberToDivideBy > 0)
    {
        cout << num / NumberToDivideBy << endl;

        num = num % NumberToDivideBy;
        NumberToDivideBy /= 10; // سينزل من 100 إلى 10 إلى 1 ثم إلى 0 فتنتهي الـ loop
    }
}

// Abo-hadhoad Solve 
// Function: ReadPositiveNumber
// Purpose: Prompts the user with a custom message to enter a positive number.
//          Continues to prompt until the user inputs a number greater than zero.
// Parameter: Message - a string containing the prompt to display.
// Returns: A positive integer provided by the user.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to store the user's input.
    do
    {
        cout << Message << endl;  // Display the prompt message.
        cin >> Number;            // Read the number entered by the user.
    } while (Number <= 0);        // Repeat if the number is not positive.

    return Number;  // Return the valid positive number.
}

// Function: ReverseNumber
// Purpose: Reverses the digits of a given number.
//          For example, if the input is 123, the function returns 321.
// Parameter: Number - the positive integer whose digits are to be reversed.
// Returns: The reversed number.
int ReverseNumber(int Number)
{
    int Remainder = 0;  // Variable to store the last digit extracted from the number.
    int Number2 = 0;    // Variable to accumulate the reversed number.

    // Process each digit until the original number becomes 0.
    while (Number > 0)
    {
        Remainder = Number % 10;          // Extract the last digit from Number.
        Number = Number / 10;             // Remove the last digit from Number.
        Number2 = Number2 * 10 + Remainder; // Append the extracted digit to Number2.
    }

    return Number2;  // Return the reversed number.
}

// Function: PrintDigits
// Purpose: Prints each digit of the given number on a new line.
//          It extracts the digits using the modulo operator and division.
// Parameter: Number - the positive integer whose digits will be printed.
void PrintDigits(int Number)
{
    int Remainder = 0;  // Variable to store the digit extracted from the number.

    // Continue processing until there are no digits left in Number.
    while (Number > 0)
    {
        Remainder = Number % 10;  // Extract the last digit.
        Number = Number / 10;     // Remove the last digit.
        cout << Remainder << endl; // Print the extracted digit on a new line.
    }
}

#pragma endregion

int main()
{
    //Problem01_WriteMultiplicationTableWithTheSameVideoStructure();

    //PrintPrimeNumbersFrom1ToN();

    //PrintIfPerfectOrNotToUser();

    //PrintAllPerfectNumbersFrom1ToN();

    //WriteAllNumberDigitsInReverse();
    //PrintDigits();

    //cout << SumOfNumberDigits() << endl;

    //cout << ReversedNumber(); // My Solve 
    //DoctorReverseNumber(ReadPositiveNumFromUser()); // Hadhoad Solve

    //cout << DigitFreqInNumber(33233233, 3) << endl;

    //AllDigitsFreqInNum(ReadPositiveNumFromUser());

    //PrintDigitsInNumberFromLeftToRight(ReadPositiveNumFromUser());// My Solve 
    //PrintDigits(ReverseNumber(ReadPositiveNumber("Please enter a positive number?"))); // Hadhoad Solve

}
