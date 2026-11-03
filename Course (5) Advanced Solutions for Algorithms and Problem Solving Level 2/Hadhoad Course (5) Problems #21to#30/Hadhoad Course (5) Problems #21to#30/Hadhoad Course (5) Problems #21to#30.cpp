#include <string>
#include <iostream>
using namespace std;
// Function: ReadPositiveNumber
// Purpose: Prompts the user to enter a positive number and reads the input.
// Parameters:
//   - Message: A string containing the prompt to display.
// Returns: A positive integer entered by the user.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to store the user's input.
    do
    {
        cout << Message << endl; // Display the prompt message.
        cin >> Number;           // Read the number from the user.
    } while (Number <= 0);       // Continue prompting until a positive number is entered.
    return Number;
}

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
enum enCharType { SmallLetter, CapitalLetter, SpecialLetter, Digit };
char GetRandom(enCharType Type)
{
    switch (Type)
    {
    case SmallLetter:
        return char(RandomNumber(97, 122));
    case CapitalLetter:
        return char(RandomNumber(65, 90));
    case SpecialLetter:
        return char(RandomNumber(33, 47));
    case Digit:
        return char(RandomNumber(48, 57));
    default:
        return char(RandomNumber(65, 90));
    }
}

#pragma endregion
#pragma region 21


string CreateRandomKeyPart(int keyLength,enCharType type)
{
    string KeyPart = "";

    for (int i = 0; i < keyLength; i++)
    {
        KeyPart += GetRandom(type);
    }

    return KeyPart;
}

string CreateRandomKey(int keyLength, int numOfKeyParts, char dividerChar, enCharType type)
{
    string key = "";
    for (int i = 0; i < numOfKeyParts; i++)
    {
        key += CreateRandomKeyPart(keyLength, type);

        if (i != numOfKeyParts - 1)
            key += dividerChar;
    }

    return key;
}

void CreateRandomKeys(int numberOfKeys)
{
    for (int i = 0; i < numberOfKeys; i++)
    {
        cout << "Key [" << i+1 << "] : " << CreateRandomKey(4, 4, '-', enCharType::CapitalLetter) << endl;
    }
}
#pragma endregion
#pragma region 22
void PrintArrayItems(int numbers[],short arrayLength)
{
    
    for (int i = 0; i < arrayLength; i++)
    {
        cout << numbers[i] << " ";
    }
}

void CreateArray(int numbers[],int &arrayLength)
{
    arrayLength = ReadPositiveNumber("Please enter your array length: ");
    for (int i = 0; i < arrayLength; i++)
    {
        cout << "Element [" << (i + 1) << "] : ";
        cin >> numbers[i];
    }
}

int TimesRepeated(int item, int numbers[],short arrayLength)
{
    int RepeatedCount = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if (numbers[i] == item)
            RepeatedCount++;
    }
    return RepeatedCount;
}

#pragma endregion
#pragma region 23
void FillArrayWithRandomNumbers(int numbers[], int &arrayLength)
{
    arrayLength = ReadPositiveNumber("Please enter your array length: ");

    for (int i = 0; i < arrayLength; i++)
    {
        numbers[i] = RandomNumber(1,100);
    }
}
#include <iostream>
#pragma endregion
#pragma region 24
int GetMaxNumberInArray(int numbers[], int arrayLength)
{
    int MaxNum = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if (MaxNum < numbers[i])
            MaxNum = numbers[i];
    }
    return MaxNum;
}
#include <iostream>
#pragma endregion
#pragma region 25
int GetMinNumberInArray(int numbers[], int arrayLength)
{
    int MinNum = 100;
    for (int i = 0; i < arrayLength; i++)
    {
        if (MinNum > numbers[i])
            MinNum = numbers[i];
    }
    return MinNum;
}
#include <iostream>
#pragma endregion
#pragma region 26
int SumOfArray(int numbers[], int arrayLength)
{
    int Sum = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        Sum += numbers[i];
    }
    return Sum;
}
#include <iostream>
#pragma endregion
#pragma region 27
float AvgOfArray(int numbers[], int arrayLength)
{
    return (float)SumOfArray(numbers, arrayLength) / arrayLength;
}
#include <iostream>
#pragma endregion
#pragma region 28
void CopyArray(int array[],int copiedArray[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        copiedArray[i] = array[i];
    }
}
#include <iostream>
#pragma endregion
#pragma region 29
// Enumeration: enPrimNotPrime
// Purpose: To classify a number as either Prime or NotPrime.
// Values:
//   Prime    = 1 (indicating the number is prime)
//   NotPrime = 2 (indicating the number is not prime)
enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

// Function: CheckPrime
// Purpose: Checks whether a given integer is a prime number.
// Parameters:
//   - Number: The integer to check for primality.
// Returns: enPrimNotPrime::Prime if Number is prime,
//          enPrimNotPrime::NotPrime if Number is not prime.
enPrimNotPrime CheckPrime(int Number)
{
    // Compute M as roughly half of Number.
    // Note: Using round(Number / 2) here might not be the best approach
    // since for small numbers it may not be accurate; typically, we check until sqrt(Number).
    int M = round(Number / 2);

    // Loop from 2 to M to test for divisibility.
    for (int Counter = 2; Counter <= M; Counter++)
    {
        // If Number is divisible by any Counter, then it is not a prime.
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;  // Return NotPrime immediately.
    }

    // If no divisors were found, return Prime.
    return enPrimNotPrime::Prime;
}
void CopyArrayPrimeNumber(int array[], int copiedArray[], int arrayLength, int &newArrayLength)
{
    int Counter = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if (CheckPrime(array[i]) == enPrimNotPrime::Prime)
        {
            copiedArray[Counter] = array[i];
            Counter++;
        }
    }
    newArrayLength = Counter;
}
#include <iostream>
#pragma endregion
#pragma region 30
void ArrayOfSum(int arrayOne[], int arrayTwo[], int arrayOfSum[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
        arrayOfSum[i] = arrayOne[i] + arrayTwo[i];
}
#include <iostream>
#pragma endregion

int main()
{
    //// Seed the random number generator with the current time.
    //// This ensures that we get a different sequence of random numbers on each run.
    srand((unsigned)time(NULL));
    //CreateRandomKeys(ReadPositiveNumber("Please enter a number of keys you want : "));
    
    //int Numbers[100];
    //int arrayLength = 0;
    //CreateArray(Numbers, arrayLength);
    //int item = ReadPositiveNumber("Please enter the item you want count it");
    //int RepeatedCount = TimesRepeated(item, Numbers, arrayLength);
    //cout << "Original array: ";
    //PrintArrayItems(Numbers, arrayLength);
    //cout << "\n" << item << " is repeated " << RepeatedCount << " time(s)" << endl;

    //int Numbers[100];
    //int ArrayLength = 0;
    //FillArrayWithRandomNumbers(Numbers, ArrayLength);
    //cout << "Array Elements: ";
    //PrintArrayItems(Numbers, ArrayLength);

    //int Numbers[100];
    //int ArrayLength = 0;
    //FillArrayWithRandomNumbers(Numbers, ArrayLength);
    //cout << "Array Elements: ";
    //PrintArrayItems(Numbers, ArrayLength);
    //cout << endl <<"Max Number is : " << GetMaxNumberInArray(Numbers, ArrayLength);
    
    //int Numbers[100];
    //int ArrayLength = 0;
    //FillArrayWithRandomNumbers(Numbers, ArrayLength);
    //cout << "Array Elements: ";
    //PrintArrayItems(Numbers, ArrayLength);
    //cout << endl << "Min Number is : " << GetMinNumberInArray(Numbers, ArrayLength);

    //int Numbers[100];
    //int ArrayLength = 0;
    //FillArrayWithRandomNumbers(Numbers, ArrayLength);
    //cout << "Array Elements: ";
    //PrintArrayItems(Numbers, ArrayLength);
    //cout << endl << "Sum of all numbers is : " << SumOfArray(Numbers, ArrayLength);

    //int Numbers[100];
    //int ArrayLength = 0;
    //FillArrayWithRandomNumbers(Numbers, ArrayLength);
    //cout << "Array Elements: ";
    //PrintArrayItems(Numbers, ArrayLength);
    //cout << endl << "Avg of all numbers is : " << AvgOfArray(Numbers, ArrayLength);

    //int Numbers[100];
    //int Numbers2[100];
    //int ArrayLength = 0;
    //FillArrayWithRandomNumbers(Numbers, ArrayLength);
    //cout << "Array1 Elements: " ;
    //PrintArrayItems(Numbers, ArrayLength);
    //CopyArray(Numbers,Numbers2, ArrayLength);
    //cout << endl <<"Array2 Elements: ";
    //PrintArrayItems(Numbers2, ArrayLength);

    //int Numbers[100];
    //int Numbers2[100];
    //int ArrayLength = 0;
    //FillArrayWithRandomNumbers(Numbers, ArrayLength);
    //cout << "Array1 Elements: " ;
    //PrintArrayItems(Numbers, ArrayLength);
    //int NewArrayLength = 0;
    //CopyArrayPrimeNumber(Numbers,Numbers2, ArrayLength, NewArrayLength);
    //cout << endl <<"Array2 Elements: ";
    //PrintArrayItems(Numbers2, NewArrayLength);

    //int Numbers[100];
    //int Numbers2[100];
    //int Numbers3[100];
    //int ArrayLength = 0;
    //FillArrayWithRandomNumbers(Numbers, ArrayLength);
    //FillArrayWithRandomNumbers(Numbers2, ArrayLength);
    //cout << "Array1 Elements: " ;
    //PrintArrayItems(Numbers, ArrayLength);
    //cout << endl <<"Array2 Elements: ";
    //PrintArrayItems(Numbers2, ArrayLength);
    //ArrayOfSum(Numbers,Numbers2, Numbers3, ArrayLength);
    //cout << endl <<"Array Of Sum Elements: ";
    //PrintArrayItems(Numbers3, ArrayLength);
}
