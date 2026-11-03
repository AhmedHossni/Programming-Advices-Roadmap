// Hadhoad Course (05) Problems #11to#20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>  
using namespace std;

#pragma region 11
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
bool IsPalindromeNumber(int num)
{
    return (num == ReverseNumber(num));
}
#pragma endregion
#pragma region 12
void InvertedNumberPattern(int num)
{
    if (num <= 0 || num > 9)
    {
        cout << "Invalid number!!!" << endl;
        return;
    }
     
    for (int i = num; i >= 1 ; i--)
    {
        for (int x = i; x > 0 ; x--)
        {
            cout << i;
        }

        cout << endl;
    }
}
#pragma endregion
#pragma region 13
void NumberPattern(int num)
{
    if (num <= 0 || num > 9)
    {
        cout << "Invalid number!!!" << endl;
        return;
    }

    cout << endl;
    for (int i = 1; i <= num; i++)
    {
        for (int x = i; x > 0 ; x--)
        {
            cout << i;
        }

        cout << endl;
    }
}
#pragma endregion
#pragma region 14
void InvertedLetterPattern(int num)
{
    cout << endl;
    for (int i = 64 + num; i >= 65 ; i--)
    {
        for (int x = num; x > 0; x--)
        {
            cout << char(i);
        }
        num--;
        cout << endl;
    }
}
#pragma endregion
#pragma region 15
void LetterPattern(int num)
{
    cout << endl;
    for (int i = 65 ; i < 65 + num; i++)
    {
        for (int x = (i-65) + 1; x > 0; x--)
        {
            cout << char(i);
        }
        cout << endl;
    }
}
#pragma endregion
#pragma region 16
void PrintAllLettersFromAAAToZZZ()
{
    for (int i1 = 65; i1 <= 90; i1++)
    {
        for (int i2 = 65; i2 <= 90; i2++)
        {
            for (int i3 = 65; i3 <= 90; i3++)
            {
                cout << char(i1) << char(i2) << char(i3) << endl;
            }
        }
    }
}
#pragma endregion
#pragma region 17
void ThreeLettersPasswordBreak(string password)
{
    int Trials = 0;
    string word = "";

    for (int i1 = 65; i1 <= 90; i1++)
    {
        for (int i2 = 65; i2 <= 90; i2++)
        {
            for (int i3 = 65; i3 <= 90; i3++)
            {
                word = word + char(i1);
                word = word + char(i2);
                word = word + char(i3);

                
                Trials++;
                
                cout << "Trial[" << Trials << "] : " << word << endl;

                if (word == password)
                {
                    cout << "\n\n\n";
                    cout << "Password is " << password << endl;
                    cout << "Found after " << Trials << " Trial(s)" << endl;
                    return;

                }

                word = "";
            }
        }
    }
}
#pragma endregion
#pragma region 18
// Function: ReadText
// Purpose: Prompts the user to enter a line of text and reads the full line.
// Returns: The text entered by the user as a string.
string ReadText()
{
    string Text;  // Declare a string variable to store the input text.

    cout << "Please enter Text?\n"; // Prompt the user for input.
    getline(cin, Text);              // Read an entire line from standard input.

    return Text; // Return the entered text.
}

string Encrypt(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = char((int)text[i] + 2);
    }
    return text;
}

string Decrypt(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = char((int)text[i] - 2);
    }
    return text;
}
#pragma endregion
#pragma region 19
#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
#include <ctime>      // Include ctime for the time() function.

// Function: RandomNumber
// Purpose: Generates a random integer between the specified range [From, To].
// Parameters:
//    From - the lower bound of the range.
//    To   - the upper bound of the range.
// Returns: A random integer between From and To (inclusive).
int RandomNumber(int From, int To)
{
    // Generate a random number between 0 and (To - From) using rand(),
    // then add From to shift the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}
#pragma endregion
#pragma region 20
enum enCharType{SmallLetter, CapitalLetter, SpecialLetter, Digit};
char GetRandom(enCharType Type)
{
    switch (Type)
    {
        case SmallLetter:
            return char(RandomNumber(97, 122));
        case CapitalLetter:
            return char(RandomNumber(65,90));
        case SpecialLetter:
            return char(RandomNumber(33, 47));
        case Digit:
            return char(RandomNumber(48, 57));
        default:
            break;
    }
}

#pragma endregion

int main()
{
    //if (IsPalindromeNumber(ReadPositiveNumber("Please enter a positive number?")));

    //InvertedNumberPattern(ReadPositiveNumber("Please enter a positive number less than 10"));

    //NumberPattern(ReadPositiveNumber("Please enter a positive number less than 10"));

    //InvertedLetterPattern(ReadPositiveNumber("Please enter a positive number"));

    //LetterPattern(ReadPositiveNumber("Please enter a positive number"));

    //PrintAllLettersFromAAAToZZZ();

    //ThreeLettersPasswordBreak("ZZZ");

    //cout << Encrypt(ReadText()) << endl;
    //cout << Decrypt(ReadText()) << endl;

    //// Seed the random number generator with the current time.
    //// This ensures that we get a different sequence of random numbers on each run.
    //srand((unsigned)time(NULL));
    //// Call RandomNumber three times to generate random numbers between 1 and 10,
    //// and output each number on a new line.
    //cout << RandomNumber(1, 10) << endl;
    //cout << RandomNumber(1, 10) << endl;
    //cout << RandomNumber(1, 10) << endl;
       
    //// Seed the random number generator with the current time.
    //// This ensures that we get a different sequence of random numbers on each run.
    //srand((unsigned)time(NULL));
    //cout << GetRandom(enCharType::SmallLetter) << endl;
    //cout << GetRandom(enCharType::CapitalLetter) << endl;
    //cout << GetRandom(enCharType::SpecialLetter) << endl;
    //cout << GetRandom(enCharType::Digit) << endl;
}
