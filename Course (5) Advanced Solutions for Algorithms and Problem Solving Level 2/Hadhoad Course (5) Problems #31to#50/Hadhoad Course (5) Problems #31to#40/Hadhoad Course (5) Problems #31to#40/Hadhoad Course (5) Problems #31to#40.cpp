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


string CreateRandomKeyPart(int keyLength, enCharType type)
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
        cout << "Key [" << i + 1 << "] : " << CreateRandomKey(4, 4, '-', enCharType::CapitalLetter) << endl;
    }
}
#pragma endregion
#pragma region 22
void PrintArray(int numbers[], short arrayLength)
{

    for (int i = 0; i < arrayLength; i++)
    {
        cout << numbers[i] << " ";
    }
}

void CreateArray(int numbers[], int& arrayLength)
{
    arrayLength = ReadPositiveNumber("Please enter your array length: ");
    for (int i = 0; i < arrayLength; i++)
    {
        cout << "Element [" << (i + 1) << "] : ";
        cin >> numbers[i];
    }
}

int TimesRepeated(int item, int numbers[], short arrayLength)
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
void FillArrayWithRandomNumbers(int numbers[], int& arrayLength)
{
    arrayLength = ReadPositiveNumber("Please enter your array length: ");

    for (int i = 0; i < arrayLength; i++)
    {
        numbers[i] = RandomNumber(1, 100);
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
void CopyArray(int array[], int copiedArray[], int arrayLength)
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
void CopyArrayPrimeNumber(int array[], int copiedArray[], int arrayLength, int& newArrayLength)
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

// these are new problems others are re-used code
#pragma region 31
#pragma region Another_Problem
int ArrayLinearSearch(int number, int array[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        if (array[i] == number)
            return i;
    }
    return -1;
}

void AnotherShuffleArray(int sourceArray[], int destArray[], int arrayLength)
{
    // حجز المصفوفة ديناميكياً
    int* Array = new int[arrayLength];

    int Counter = 0;
    while(Counter < arrayLength)
    {
        int RandomIndex = RandomNumber(0, arrayLength-1);

        if (RandomIndex != Counter && ArrayLinearSearch(RandomIndex, Array, arrayLength) == -1)
        {
            destArray[Counter] = sourceArray[RandomIndex];
            Array[Counter] = RandomIndex;

            Counter++;
        }
    }

    // مهم جداً: تحرير الذاكرة بعد الانتهاء
    delete[] Array;
}
#pragma endregion
void Swap(int& A, int& B)
{
    int Temp;    // Temporary variable to hold the value of A.
    Temp = A;    // Save the value of A in Temp.
    A = B;       // Copy the value of B into A.
    B = Temp;    // Copy the value of Temp (original A) into B.
}

void FillArrayWithOrderNumbersTo(int array[],int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        array[i] = i + 1;
    }
}
void ShuffleArray(int arr[], int arrLength)
{
    // نمر على المصفوفة من النهاية إلى البداية
    for (int i = arrLength - 1; i > 0; i--)
    {
        // نختار مؤشر عشوائي من العناصر المتبقية فقط (من 0 إلى i)
        // نفترض أن RandomNumber(min, max) تولد أرقام تشمل الحدين
        int randomIndex = RandomNumber(0, i);

        // نبدل العنصر الحالي بالعنصر العشوائي المختار
        Swap(arr[i], arr[randomIndex]);
    }
}
#include <iostream>
#pragma endregion
#pragma region 32
void ReverseArray(int array[], int arrayLength)
{
    for (int i = 0; i < arrayLength/2; i++)
        Swap(array[i], array[arrayLength - (i + 1)]);
}
void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
{
    // Loop through each element of the source array.
    // For each index i, copy the element at position (arrLength - 1 - i)
    // from the source array into the destination array at index i.
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[arrLength - 1 - i];
}   
#pragma endregion
#pragma region 33 of keys
void PrintArray(string array[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
        cout << array[i] << endl;
}
void PrintArrayOfKeys(string array[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        cout << "Array[" << i << "] : ";
        cout << array[i] << endl;
    }
}
void FillArrayOfKeys(string array[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        array[i] = CreateRandomKey(4, 4, '-', enCharType::CapitalLetter);
    }
}
#pragma endregion
#pragma region 34 Search in array
void SearchInArrayAndPrintResults(int number, int array[], int arrayLength)
{
    int SearchResult = ArrayLinearSearch(number, array, arrayLength);

    cout << "Number you are looking for is: " << number << endl;
    if(SearchResult != -1)
    {
        cout << "The number found at position : " << SearchResult << endl;
        cout << "The number found its order : " << SearchResult + 1 << endl;
    }
    else
    {
        cout << "The number is not found :-(" << endl;      
    }      
}
#pragma endregion
#pragma region 35 Search 2 in array
bool IsNumberInArray(int number, int array[], int arrayLength)
{
    return (ArrayLinearSearch(number, array, arrayLength) != -1);
}

void SearchInArrayByBoolAndPrintResults(int number, int array[], int arrayLength)
{
    bool SearchResult = IsNumberInArray(number, array, arrayLength);

    cout << "Number you are looking for is: " << number << endl;
    if (SearchResult)
    {
        cout << "The number found" << endl;
    }
    else
    {
        cout << "The number is not found :-(" << endl;
    }
}
#pragma endregion
#pragma region 36 add item to array
void AddElementToArray(int item,int array[], int& arrayLength)
{
    arrayLength++;
    array[arrayLength - 1] = item;
}
int AddItemsToArray(int array[], int arrayMaxLength)
{
    short Counter = 0;
    int Num = 0;
    char Key = ' ';
    while (true)
    {
        cout << "Please enter your number: ";
        cin >> Num;
        array[Counter] = Num;

        if (Counter == (short)arrayMaxLength)
            break;
        cout << endl << "Are you want to add more numbers ?[1]:Yes,[0]:No "<< endl;
        cin >> Key;

        if (Key == '0')
            break;
        Counter++;
    }

    return Counter+1;
}
#pragma endregion
#pragma region 37 Copy Array
void CopyArray2(int arraySource[], int arrayDest[], int arrayLength)
{
    int DestArrayLength = 0;
    for (int i = 0; i < arrayLength; i++)
        AddElementToArray(arraySource[i], arrayDest, DestArrayLength);
}
#pragma endregion
#pragma region 38 copy odd numbers in array
int CopyOddNumbersFromArray(int arraySource[], int arrayDest[], int arrayLength)
{
    int DestArrayLength = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if(arraySource[i] % 2 != 0)
            AddElementToArray(arraySource[i], arrayDest, DestArrayLength);
    }

    return DestArrayLength;
}
#pragma endregion
#pragma region 39 copy prime numbers in array
int CopyPrimeNumbersFromArray(int arraySource[], int arrayDest[], int arrayLength)
{
    int DestArrayLength = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if (CheckPrime(arraySource[i]) == enPrimNotPrime::Prime)
            AddElementToArray(arraySource[i], arrayDest, DestArrayLength);
    }

    return DestArrayLength;
}
#pragma endregion
#pragma region 40 distinct copy from array
int CopyDistinctNumbersFromArray(int sourceArray[], int destArray[], int arrayLength)
{
    int DestArrayLength = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if (!IsNumberInArray(sourceArray[i],destArray, DestArrayLength))
            AddElementToArray(sourceArray[i], destArray, DestArrayLength);
    }

    return DestArrayLength;
}
#pragma endregion

// 41-50
#pragma region 41 is palindrome array
int IsPalindromeArray(int sourceArray[], int arrayLength)
{
    int CopiedArray[100];
    CopyArray(sourceArray, CopiedArray, arrayLength);
    ReverseArray(sourceArray, arrayLength);

    for (int i = 0; i < arrayLength; i++)
    {
        if (sourceArray[i] != CopiedArray[i])
            return false;
    }
    return true;
}
bool IsPalindromeArrayDoctor(int arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        if (arr[i] != arr[Length - i - 1])
        {
            return false;
        }
    }
    return true;
}
#pragma endregion
#pragma region 42 Count odd numbers in array
int CountOddNumbersInArray(int array[], int arrayLength)
{
    int OddNumbersCounter = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if (array[i] % 2 != 0)
            OddNumbersCounter++;
    }
    return OddNumbersCounter;
}
#pragma endregion
#pragma region 43 Count even numbers in array
int CountEvenNumbersInArray(int array[], int arrayLength)
{
    int OddNumbersCounter = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if (array[i] % 2 == 0)
            OddNumbersCounter++;
    }
    return OddNumbersCounter;
}
#pragma endregion
#pragma region 44 Count even numbers in array
int CountPositiveNumbersInArray(int array[], int arrayLength)
{
    int OddNumbersCounter = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        if (array[i] > 0)
            OddNumbersCounter++;
    }
    return OddNumbersCounter;
}
#pragma endregion
#pragma region 46 abs
int My_abs(int number)
{
    if (number < 0)
        return number * -1;
    return number;
}
#pragma endregion
#pragma region 47 Round
float GetFractionPart(float number)
{
    return number - (int)number;
}

float MyRound(float number)
{
    float FractionPart = GetFractionPart(number);

    if (abs(FractionPart) >= 0.5)
    {
        if (number > 0)
            return (int)number+1;
        return (int)number-1;
    }
    return (int)number;
    
}
#pragma endregion
#pragma region 48 Floor
int MyFloor(float number)
{
    float FractionPart = GetFractionPart(number);

    if(abs(FractionPart) > 0 && number < 0)
        return (int)--number;

    return (int)number;
}
#pragma endregion
#pragma region 49 Ceil
int MyCeil(float number)
{
    float FractionPart = GetFractionPart(number);

    if (abs(FractionPart) > 0)
    {
        if(number > 0)
            return (int)++number;
    }

    return (int)number;
}
#pragma endregion
#pragma region 50 sqrt
float MySqrt(float number)
{
    return pow(number,0.5);
}
#pragma endregion

void CallProblem31()
{
    int Numbers[100];
    int NumberOfItemsInArray = ReadPositiveNumber("Please enter number of max number in array : ");
    cout << "Array One : ";
    FillArrayWithOrderNumbersTo(Numbers, NumberOfItemsInArray);
    PrintArray(Numbers, NumberOfItemsInArray);
    ShuffleArray(Numbers, NumberOfItemsInArray);
    cout << endl << "Array Two : ";
    PrintArray(Numbers, NumberOfItemsInArray);
}
void CallProblem32()
{
    int Numbers[100];
    int NumberOfItemsInArray = ReadPositiveNumber("Please enter number of max number in array : ");
    FillArrayWithRandomNumbers(Numbers, NumberOfItemsInArray);
    cout << "Array One : ";
    PrintArray(Numbers, NumberOfItemsInArray);
    ReverseArray(Numbers, NumberOfItemsInArray);
    cout << endl << "Array Two : ";
    PrintArray(Numbers, NumberOfItemsInArray);
}
void CallProblem33()
{
    string ArrayOfKeys[100];
    int NumberOfItemsInArray = ReadPositiveNumber("Please enter number of max number in array : ");
    cout << "Array elements :\n" << endl;
    FillArrayOfKeys(ArrayOfKeys, NumberOfItemsInArray);
    PrintArrayOfKeys(ArrayOfKeys, NumberOfItemsInArray);
}
void CallProblem34()
{
    int Numbers[100];
    int NumberOfItemsInArray = 0;
    FillArrayWithRandomNumbers(Numbers, NumberOfItemsInArray);
    cout << "Array elements :\n" << endl;
    PrintArray(Numbers, NumberOfItemsInArray);
    cout << endl;
    SearchInArrayAndPrintResults(ReadPositiveNumber("Please enter the number you want to search for : "), Numbers, NumberOfItemsInArray);
}
void CallProblem35()
{
    int Numbers[100];
    int NumberOfItemsInArray = 0;
    FillArrayWithRandomNumbers(Numbers, NumberOfItemsInArray);
    cout << "Array elements :\n" << endl;
    PrintArray(Numbers, NumberOfItemsInArray);
    cout << endl;
    SearchInArrayByBoolAndPrintResults(ReadPositiveNumber("Please enter the number you want to search for : "),
        Numbers, 
        NumberOfItemsInArray);
}
void CallProblem36()
{
    int Numbers[100];
    int ArrayMaxLength = 100;
    int ArrayLength = AddItemsToArray(Numbers, ArrayMaxLength);
    cout << "Array Length : " << ArrayLength << endl;
    cout << "Array elements : ";
    PrintArray(Numbers, ArrayLength);
}
void CallProblem37()
{
    int Numbers[100];
    int Numbers2[100];
    int ArrayLength = ReadPositiveNumber("Please enter arrays length");
    FillArrayWithOrderNumbersTo(Numbers, ArrayLength);
    CopyArray2(Numbers, Numbers2, ArrayLength);
    cout << "Array Length 1: " << ArrayLength << endl;
    cout << "Array 1 elements : ";
    PrintArray(Numbers, ArrayLength);
    cout << endl <<"Array Length 2: " << ArrayLength << endl;
    cout << "Array 2 elements : ";
    PrintArray(Numbers2, ArrayLength);
}
void CallProblem38()
{
    int Numbers[100];
    int Numbers2[100];
    int SourceArrayLength = 0;
    int DestArrayLength = 0;
    FillArrayWithRandomNumbers(Numbers, SourceArrayLength);
    DestArrayLength = CopyOddNumbersFromArray(Numbers, Numbers2, SourceArrayLength);
    cout << "Array Length 1: " << SourceArrayLength << endl;
    cout << "Array 1 elements : ";
    PrintArray(Numbers, SourceArrayLength);
    cout << endl <<"\nArray Length 2: " << DestArrayLength << endl;
    cout << "Array 2 elements : ";
    PrintArray(Numbers2, DestArrayLength);
}
void CallProblem39()
{
    int Numbers[100];
    int Numbers2[100];
    int SourceArrayLength = 0;
    int DestArrayLength = 0;
    FillArrayWithRandomNumbers(Numbers, SourceArrayLength);
    DestArrayLength = CopyPrimeNumbersFromArray(Numbers, Numbers2, SourceArrayLength);
    cout << "Array Length 1: " << SourceArrayLength << endl;
    cout << "Array 1 elements : ";
    PrintArray(Numbers, SourceArrayLength);
    cout << endl <<"\nArray Length 2: " << DestArrayLength << endl;
    cout << "Array 2 elements : ";
    PrintArray(Numbers2, DestArrayLength);
}
void CallProblem40()
{
    int Numbers[100];
    int Numbers2[100];
    int SourceArrayLength = 0;
    int DestArrayLength = 0;
    SourceArrayLength = AddItemsToArray(Numbers, 100);

    DestArrayLength = CopyDistinctNumbersFromArray(Numbers, Numbers2, SourceArrayLength);

    cout << "Array Length 1: " << SourceArrayLength << endl;
    cout << "Array 1 elements : ";
    PrintArray(Numbers, SourceArrayLength);
    cout << endl <<"\nArray Length 2: " << DestArrayLength << endl;
    cout << "Array 2 elements : ";
    PrintArray(Numbers2, DestArrayLength);
}
void CallProblem41()
{
    int Numbers[100] = {10,20,30,30,20,10};
    int ArrayLength = 6;

    cout << "Array Length 1: " << ArrayLength << endl;
    cout << "Array 1 elements : ";
    PrintArray(Numbers, ArrayLength);
    if (IsPalindromeArray(Numbers, ArrayLength))
        cout << endl << "\nYes array is palindrome";
    else
        cout << endl << "\nno array isn't palindrome";
}
void CallProblem42()
{
    int Numbers[100];
    int ArrayLength = 0;

    FillArrayWithRandomNumbers(Numbers, ArrayLength);

    cout << "Array Length: " << ArrayLength << endl;
    cout << "Array elements : ";
    PrintArray(Numbers, ArrayLength);
    cout << endl <<"Number of odd numbers in array : " << CountOddNumbersInArray(Numbers, ArrayLength);
}
void CallProblem43()
{
    int Numbers[100];
    int ArrayLength = 0;

    FillArrayWithRandomNumbers(Numbers, ArrayLength);

    cout << "Array Length: " << ArrayLength << endl;
    cout << "Array elements : ";
    PrintArray(Numbers, ArrayLength);
    cout << endl <<"Number of even numbers in array : " << CountEvenNumbersInArray(Numbers, ArrayLength);
}
void CallProblem44()
{
    int Numbers[100];
    int ArrayLength = 0;

    FillArrayWithRandomNumbers(Numbers, ArrayLength);

    cout << "Array Length: " << ArrayLength << endl;
    cout << "Array elements : ";
    PrintArray(Numbers, ArrayLength);
    cout << endl <<"Number of positive numbers in array : " << CountPositiveNumbersInArray(Numbers, ArrayLength);
}
void CallProblem46()
{
    cout << "Please enter any number : " << endl;
    int Num = 0;
    cin >> Num;

    cout << endl << "My abs result : " << My_abs(Num);
    cout << endl << "C++ abs result : " << abs(Num);
}
void CallProblem47()
{
    cout << "Please enter any number : " << endl;
    float Num = 0;
    cin >> Num;

    cout << endl << "My round result : " << MyRound(Num);
    cout << endl << "C++ round result : " << round(Num);
}
void CallProblem48()
{
    cout << "Please enter any number : " << endl;
    float Num = 0;
    cin >> Num;

    cout << endl << "My floor result : " << MyFloor(Num);
    cout << endl << "C++ floor result : " << floor(Num);
}
void CallProblem49()
{
    cout << "Please enter any number : " << endl;
    float Num = 0;
    cin >> Num;

    cout << endl << "My Ceil result : " << MyCeil(Num);
    cout << endl << "C++ Ceil result : " << ceil(Num);
}
void CallProblem50()
{
    cout << "Please enter any number : " << endl;
    float Num = 0;
    cin >> Num;

    cout << endl << "My sqrt result : " << MySqrt(Num);
    cout << endl << "C++ sqrt result : " << sqrt(Num);
}

int main()
{
    //// Seed the random number generator with the current time.
    //// This ensures that we get a different sequence of random numbers on each run.
    srand((unsigned)time(NULL));

    //CallProblem31();
    //CallProblem32();
    //CallProblem33();
    //CallProblem34();
    //CallProblem35();
    //CallProblem36();
    //CallProblem37();
    //CallProblem38();
    //CallProblem39();
    //CallProblem40();
   

    //CallProblem41();
    //CallProblem42();
    //CallProblem43();
    //CallProblem44();
    //CallProblem46();
    //CallProblem47();
    //CallProblem48();
    //CallProblem49();
    CallProblem50();
    RandomNumber();
}
