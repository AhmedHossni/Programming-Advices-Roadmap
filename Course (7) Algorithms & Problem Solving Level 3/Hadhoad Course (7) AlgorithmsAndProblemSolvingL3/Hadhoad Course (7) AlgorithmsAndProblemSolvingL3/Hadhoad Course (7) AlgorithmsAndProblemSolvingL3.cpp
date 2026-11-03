#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

int RandomIntNumber(int from, int to) {
    // Ensure 'from' is the smaller number for the distribution
    int min = (from < to) ? from : to;
    int max = (from > to) ? from : to;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(min, max);

    return distrib(gen); // Returns 1 random integer
}
void PrintVector(vector<int> v,string message) {
    std::cout << std::endl;
    cout << message << " ";
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl; // Print a new line at the end
}

#pragma region Problems 1-10

#pragma region Problems 1
void Fill2DArrayWithRandomNumbers(int numbers[3][3],int from, int to)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
            numbers[row][col] = RandomIntNumber(from, to);
    }
}
void Problem1_3x3RandomArrayFrom1To100(int numbers[3][3])
{
    Fill2DArrayWithRandomNumbers(numbers, 1, 100);
}
void PrintMatrix(int matrix[3][3],int rows,int cols,string printedMessage)
{
    cout << printedMessage << endl;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            cout << setw(3) << matrix[row][col] << " ";
        }

        cout << endl;
    }
}
void PrintMatrixWithFormat(int matrix[3][3],int rows,int cols,string printedMessage)
{
    cout << printedMessage << endl;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            printf("%0*d ", 2 ,matrix[row][col]);
        }

        cout << endl;
    }
}
#pragma endregion
#pragma region Problem 2

int RowSum(int numbers[3][3],int rowNumber,int cols)
{
    int sumOfRow = 0;

    for (int col = 0; col < cols; col++)
        sumOfRow += numbers[rowNumber][col];

    return sumOfRow;
}

vector<int> SumOfAllRowsIn2DArray(int numbers[3][3],int rows, int cols)
{
    vector<int> allSumsOfRows;
    int sumOfRow = 0;

    for (int row = 0; row < rows; row++)
    {
        allSumsOfRows.push_back(RowSum(numbers, row, cols));
    }

    return allSumsOfRows;
}
#pragma endregion
#pragma region Problem 3
// Very like the problem 2 and i make it in problem 2
#pragma endregion
#pragma region Problem 4

int ColSum(int numbers[3][3], int rows, int colNumber)
{
    int sumOfCol = 0;

    for (int row = 0; row < rows; row++)
        sumOfCol += numbers[row][colNumber];

    return sumOfCol;
}

vector<int> SumOfAllColsIn2DArray(int numbers[3][3], int rows, int cols)
{
    vector<int> allSumsOfColms;
    int sumOfRow = 0;

    for (int col = 0; col < cols; col++)
    {
        allSumsOfColms.push_back(ColSum(numbers, rows, col));
    }

    return allSumsOfColms;
}
#pragma endregion
#pragma region Problem 6
void FillMatrixWithOrderedNumbers(int numbers [3][3],short rows,short cols)
{
    short order = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
            numbers[row][col] = ++order;
    }
}
#pragma endregion
#pragma region Problem 7
void TransposeMatrix(int matrix[3][3], int transposeMatrix[3][3], int rows, int cols)
{
    for (int col = 0; col < cols; col++)
    {
        for (int row = 0; row < rows; row++)
            transposeMatrix[row][col] = matrix[col][row];

        cout << endl;
    }
}
#pragma endregion
#pragma region Problem 8
void MultiplyMatrix(int matrixOne[3][3], int matrixTwo[3][3], int matrixOfResult[3][3], int rows, int cols)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
            matrixOfResult[row][col] = matrixOne[row][col] * matrixTwo[row][col];
    }
}
#pragma endregion
#pragma region Problem 9
void PrintMiddleRow(int matrix[3][3], int rows, int cols)
{
    short targetRow = cols / 2;

    cout << "Middle row in matrix : " << endl;
    for (int col = 0; col < cols; col++)
    {
        cout << setw(3) << matrix[targetRow][col] << " ";
    }
    cout << endl;
}
void PrintMiddleColm(int matrix[3][3], int rows, int cols)
{
    short targetCol = cols / 2;

    cout << "Middle col in matrix : " << endl;
    for (int row = 0; row < rows; row++)
    {
        cout << setw(3) << matrix[row][targetCol] << " ";
    }
    cout << endl;
}
#pragma endregion
#pragma region Problem 10
int SumOfMatrix(int matrix[3][3], int rows, int cols)
{
    short sumOfMatrix = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
            sumOfMatrix += matrix[row][col];
    }
    return sumOfMatrix;
}
#pragma endregion

#pragma endregion

#pragma region Problems 11-20

#pragma region Problem 11
bool areMatricesEqualInSum(int matrixOne[3][3], int matrixTwo[3][3], int rows, int cols)
{
    return SumOfMatrix(matrixOne, rows, cols)
        == SumOfMatrix(matrixTwo, rows, cols);
}
#pragma endregion
#pragma region Problem 12
bool AreTypicalMatrics(int matrixOne[3][3], int matrixTwo[3][3], int rows, int cols)
{
    short sumOfMatrix = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (matrixOne[row][col] != matrixTwo[row][col])
                return false;
        }
    }
    return true;
}
#pragma endregion
#pragma region Problem 13
bool isIdentityMatrix(int matrix[3][3], int rows, int cols)
{

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (row == col && matrix[row][col] != 1)
            {
                return false;
            }
            else if (row != col && matrix[row][col] != 0)
            {
                return false;
            }
        }
    }
    return true;
}
#pragma endregion
#pragma region Problem 14
bool isScalarMatrix(int matrix[3][3], int rows, int cols)
{
    int itemToCheckBy = matrix[0][0];
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (row == col && matrix[row][col] != itemToCheckBy)
            {
                return false;
            }
            else if (row != col && matrix[row][col] != 0)
            {
                return false;
            }
        }
    }
    return true;
}
#pragma endregion
#pragma region Problem 15
int NumberRedundancyInMatrix(int matrix[3][3], int rows, int cols,int numberForCheck)
{
    int sum = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (matrix[row][col] == numberForCheck)
                sum++;
        }
    }
    return sum;
}
#pragma endregion
#pragma region Problem 16
bool isSparceMatrix(int matrix[3][3], int rows, int cols)
{
    int NumberOfZeros = 0;
    int NumberOfElseNumbersThanZeros = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (matrix[row][col] == 0)
                NumberOfZeros++;
            else
                NumberOfElseNumbersThanZeros++;
        }
    }
    return NumberOfZeros >= NumberOfElseNumbersThanZeros;
}
bool isSparceMatrixDoctorSolution(int matrix[3][3], int rows, int cols)
{
    int matrixSize = rows * cols;
    return NumberRedundancyInMatrix(matrix, rows, cols,0) >= (matrixSize/2);
}
#pragma endregion
#pragma region Problem 17
bool isNumberInMatrix(int matrix[3][3], int rows, int cols,int checkedNumber)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (matrix[row][col] == checkedNumber)
                return true;
        }
    }
    return false;
}
#pragma endregion
#pragma region Problem 18
vector<int> IntersectedNumbers(int matrixOne[3][3], int matrixTwo[3][3], int rows, int cols)
{
    vector<int> existedNumbers;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (isNumberInMatrix(matrixTwo, 3, 3, matrixOne[row][col]))
                existedNumbers.push_back(matrixOne[row][col]);
        }
    }
    return existedNumbers;
}
#pragma endregion
#pragma region Problem 19
int MaxNumberInMatrix(int matrixOne[3][3],int rows, int cols)
{
    int MaxNumber = matrixOne[0][0];
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (matrixOne[row][col] > MaxNumber)
                MaxNumber = matrixOne[row][col];
        }
    }
    return MaxNumber;
}
int MinNumberInMatrix(int matrixOne[3][3],int rows, int cols)
{
    int MinNumber = matrixOne[0][0];
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (matrixOne[row][col] < MinNumber)
                MinNumber = matrixOne[row][col];
        }
    }
    return MinNumber;
}
#pragma endregion
#pragma region Problem 20
bool IsPalindromeMatrix(int matrixOne[3][3],int rows, int cols)
{
    int MaxNumber = matrixOne[0][0];
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols / 2; col++)
        {
            if (matrixOne[row][col] != matrixOne[row][cols - 1 - col])
                return false;
        }
    }
    return true;
}
#pragma endregion

#pragma endregion

#pragma region Problems 21-30

#pragma region Problem 20-22
void FillArrayFibonacciSeries(int matrix[10],int arrayLength)
{
    matrix[0] = 1;
    matrix[1] = 1;

    for (int index = 1; index < arrayLength - 1; index++)
    {
        matrix[index + 1] = matrix[index] + matrix[index - 1];
    }
}
void PrintArray(int matrix[10], int arrayLength,string message)
{
    cout << message << endl;
    for (int index = 0; index < arrayLength; index++)
        cout << matrix[index] << " ";

    cout << endl;
}
void PrintFibonacciUsingLoop(short Number)
{
    int FebNumber = 0;
    int Prev2 = 0, Prev1 = 1;
    cout << "1 ";
    for (short i = 2; i <= Number; ++i)
    {
        FebNumber = Prev1 + Prev2;
        cout << FebNumber << " ";
        Prev2 = Prev1;
        Prev1 = FebNumber;
    }
}
void PrintFibonacciUsingRecurssion(short Number, int Prev1,int Prev2)
{
    int FebNumber = 0;

    FebNumber = Prev1 + Prev2;
    if (Prev1 + Prev2 == 1)
        cout << "1 ";

    cout << FebNumber << " ";
    Prev2 = Prev1;
    Prev1 = FebNumber;

    if (Number - 2 != 0)
        PrintFibonacciUsingRecurssion(--Number, Prev1,Prev2);

}

#pragma endregion
#pragma region Problem 20-22
string ReadStringFromUser(string message)
{
    cout << message << endl;
    string UserInput = "";
    getline(cin, UserInput);

    return UserInput;
}
vector<string> Split(string fullString,char splitChar)
{
    vector<string> splittingVector;
    int FirstOfSplittingNewString = 0;
    int countOfLettersToSplit = 0;

    for (int i = 0; i < fullString.size(); i++)
    {
        if (fullString[i] == splitChar)
        {
            // تجنب إضافة نصوص فارغة إذا تكرر حرف الفصل متتالياً
            if (countOfLettersToSplit > 0) {
                splittingVector.push_back(fullString.substr(FirstOfSplittingNewString, countOfLettersToSplit));
            }

            // التعديل: البداية الجديدة تكون الحرف الذي يليه (i + 1) وليس حرف الفصل نفسه
            FirstOfSplittingNewString = i + 1;
            countOfLettersToSplit = 0;

            continue;
        }
        countOfLettersToSplit++;
    }

    // إصلاح الخطأ الأول: إضافة الكلمة الأخيرة المتبقية بعد انتهاء الحلقة
    if (countOfLettersToSplit > 0) {
        splittingVector.push_back(fullString.substr(FirstOfSplittingNewString, countOfLettersToSplit));
    }

    return splittingVector;
}

vector<char> FirstLetterInVectorOfStrings(vector<string> vectorOfStrings)
{
    vector<char> Chars;

    for (int i = 0; i < vectorOfStrings.size(); i++)
        Chars.push_back(vectorOfStrings[i][0]);

    return Chars;
}

vector<char> FirstLetterOfStringWords(string fullString)
{
    vector<string> FirstOfSplittingNewString = Split(fullString, ' ');

    return FirstLetterInVectorOfStrings(FirstOfSplittingNewString);
}

void PrintVectorOfChars(const vector<char>& vectorOfChars, const string& message) 
{
    cout << message << endl;

    for (int i = 0; i < vectorOfChars.size(); i++)
    {
        cout << vectorOfChars[i] << endl;
    }
}
void PrintFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            cout << S1[i] << endl;
        }

        isFirstLetter = S1[i] == ' ' ? true : false;
    }
}

#include <cctype>

void PrintUpperCaseOfEachStringWord(string S1)
{
    bool isFirstLetter = true;
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
             cout << (char)toupper(S1[i]) << endl;
        }

        isFirstLetter = S1[i] == ' ' ? true : false;
    }
}

string UpperFirstLetterInEachWord(string S1)
{
    bool isFirstLetter = true;

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            S1[i] = (char)towupper(S1[i]);
        }

        isFirstLetter = S1[i] == ' ' ? true : false;
    }

    return S1;
}
string LowerFirstLetterInEachWord(string S1)
{
    bool isFirstLetter = true;

    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            S1[i] = (char)tolower(S1[i]);
        }

        isFirstLetter = S1[i] == ' ' ? true : false;
    }

    return S1;
}
string StringToUpper(string S1)
{
    for (short i = 0; i < S1.length(); i++)
        S1[i] = (char)toupper(S1[i]);

    return S1;
}

string StringToLower(string S1)
{
    for (short i = 0; i < S1.length(); i++)
        S1[i] = (char)tolower(S1[i]);

    return S1;
}

char InvertCharCase(char c1)
{

    return isupper(c1) ? tolower(c1) : toupper(c1);
}

string InvertStringCharsCase(string s1)
{
    for (short i = 0; i < s1.length(); i++)
    {
        s1[i] = InvertCharCase(s1[i]);
    }

    return s1;
}

int StringNumberOfUpperLetters(string s1)
{
    int num = 0;
    for (short i = 0; i < s1.length(); i++)
    {
        if (isupper(s1[i]))
            num++;
    }

    return num;
}

int StringNumberOfLowerLetters(string s1)
{
    int num = 0;
    for (short i = 0; i < s1.length(); i++)
    {
        if (islower(s1[i]))
            num++;
    }

    return num;
}

int CountCharInString(string s1,char letter)
{
    int num = 0;
    for (short i = 0; i < s1.length(); i++)
    {
        if ((s1[i] == letter))
            num++;
    }

    return num;
}

int CountCharInStringWithIgnoreCase(string s1,char letter)
{
    int num = 0;
    for (short i = 0; i < s1.length(); i++)
    {
        if (s1[i] == InvertCharCase(letter) || s1[i] == letter)
            num++;
    }

    return num;
}

int CountCharInString(string s1,char letter, bool matchCase = true)
{
    int num = 0;
    for (short i = 0; i < s1.length(); i++)
    {
        if (s1[i] == letter && matchCase)
            num++;
        else if(toupper(s1[i]) == toupper(letter) && !matchCase)
            num++;
    }

    return num;
}

bool IsAVowel(char c)
{
    char Vowels[] = {'a','e','i','o','u'};

    for (short i = 0; i < 5; i++)
    {
        if (tolower(c) == Vowels[i])
            return true;
    }
    return false;
}

bool IsVowelByDoctor(char Ch1)

{

    Ch1 = tolower(Ch1);

    return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1

        == 'o') || (Ch1 == 'u'));

}

bool IsVowelByGemeni(char ch) 
{
    switch (tolower(ch)) 
    {
    case 'a':
    case 'e': 
    case 'i': 
    case 'o': 
    case 'u':
        return true;
    default:
        return false;
    }
}

void PrintEachWordInString(string s1)
{

    string Word = "";
    for (short i = 0; i < s1.length(); i++)
    {
        if (s1[i] == ' ')
        {
            cout << Word << endl;
            Word = "";
        }
        else if(i == s1.length() - 1)
        {
            Word += s1[i];
            cout << Word << endl;
        }           
        else
        {
            Word += s1[i];
        }
    }
}

void PrintEachWordInStringDoctorSolve(string S1)
{
    string delim = " "; // delimiter
    cout << "\nYour string words are: \n\n";
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            cout << sWord << endl;
        }
        S1.erase(0, pos + delim.length()); /* erase() until
        positon and move to next word. */
    }
    if (S1 != "")
    {
        cout << S1 << endl; // it print last word of the string.
    }
}
short CountOfWordsInString(string S1)
{
    string delim = " ";
    short pos = 0;
    string word;
    short wordsCounter = 0;

    while ((pos = S1.find(delim)) != string::npos)
    {
        word = S1.substr(0, pos);
        if (word != "")
        {
            wordsCounter++;
        }
        S1.erase(0, pos + 1);
    }

    if(S1 != "")
        return ++wordsCounter;

    return wordsCounter;
}

// problem 37
vector<string> MySplit(string S1, string delim)
{
    short pos = 0;
    string word;
    vector<string> stringWords;

    while ((pos = S1.find(delim)) != string::npos)
    {
        word = S1.substr(0, pos);

        if (word != "")
        {
            stringWords.push_back(word);
        }
        S1.erase(0, pos + delim.length());
    }

    if(S1 != "")
        stringWords.push_back(S1);

    return stringWords;
}

// Problem 38
string TrimLeft(string S1)
{
    short LastEmptyPos = 0;

    for(const char &c : S1)
    {
        if (c == ' ')
            LastEmptyPos++;
        else
            break;
    }
    S1.erase(0, LastEmptyPos);
   
    return S1;
}
string TrimRight(string S1)
{
    short LastEmptyPos = 0;

    for (short i = S1.length() - 1; i >= 0; i--)
    {
        if (S1[i] == ' ')
            LastEmptyPos++;
        else
            break;
    }
    S1.erase(S1.length() - LastEmptyPos, LastEmptyPos);
   
    return S1;
}
string Trim(string S1)
{
    return TrimLeft(TrimRight(S1));
}

// Problem 39
string Join(vector<string> stringsToJoin, string joinDelim)
{
    if (stringsToJoin.size() == 0)
        return "";

    string joinedString = "";


    for (short i = 0; i < stringsToJoin.size() - 1; i++)
    {
        joinedString.append(stringsToJoin[i]);
        joinedString.append(joinDelim);
    }
    joinedString.append(stringsToJoin[stringsToJoin.size() - 1]);
    return joinedString;
}

// Problem 41 
string ReverseString(string s1)
{
    if (s1 == "")
        return "";
    vector<string> strings = MySplit(s1," ");
    string newReverseString = "";
    for(short i = strings.size() - 1; i > 0; i--)
    {
        newReverseString.append(strings[i]);
        newReverseString.append(" ");
    }
    newReverseString.append(strings[0]);
    return newReverseString;
}

// Problem 42 => logic error (the func is not correct)
string ReplaceSpecificWordInString(string s1,string replacedValue , string newWord)
{
    //short pos = 0;

    //if(!caseSensitive)
    //{
    //    pos = StringToLower(s1).find(StringToLower(replacedValue));
    //}
    //else
    //{
    //    pos = s1.find(replacedValue);
    //}

    //while (pos != string::npos)
    //{
    //    s1.replace(pos, replacedValue.size(), newWord);

    //    if (!caseSensitive)
    //    {
    //        pos = StringToLower(s1).find(StringToLower(replacedValue));
    //    }
    //    else
    //    {
    //        pos = s1.find(replacedValue);
    //    }
    //}

    //return s1;
    return "";
}
// my solve after watch doctor solve
string ReplaceSpecificWordInStringAfterWatchVideo(string s1,string replacedValue , string newWord)
{
    short pos = 0;

    while ((pos = s1.find(replacedValue)) != string::npos)
    {
        s1.replace(pos, replacedValue.size(), newWord);
    }

    return s1;
}
// Problem 43
string ReplaceSpecificWordInStringWithCaseSensitive(string s1, string replacedValue, string newWord, bool caseSensitive = true)
{
    short pos = 0;

    if (!caseSensitive)
    {
        pos = StringToLower(s1).find(StringToLower(replacedValue));
    }
    else
    {
        pos = s1.find(replacedValue);
    }

    while (pos != string::npos)
    {
        s1.replace(pos, replacedValue.size(), newWord);

        if (!caseSensitive)
        {
            pos = StringToLower(s1).find(StringToLower(replacedValue));
        }
        else
        {
            pos = s1.find(replacedValue);
        }
    }

    return s1;
}

// Problem 44
/*
مشكلة منطقي(Bug) : عند حذف علامة ترقيم باستخدام replace(أو مسحها)، حجم السلسلة النصية يقل،
وتتحرك الحروف التالية خطوة إلى اليسار.وبما أن العداد i يزداد في الخطوة التالية،
سيتخطى البرنامج الحرف الذي يليه مباشرة دون فحصه.فلو كان هناك علامتا ترقيم متتاليتان مثل !!،
سيحذف الأولى ويتخطى الثانية.بطء الأداء(Performance) : دالة replace(أو erase) عندما تحذف حرفاً من وسط النص،
تضطر إلى إزاحة(Shift) جميع الحروف المتبقية في النص إلى اليسار.هذا يجعل الكفاءة $O(N ^ 2)$

*/
string RemoveAllPunctuations(string s1)
{
    for (short i = 0 ; i < s1.size() ; i++)
    {
        if(ispunct(s1[i]))
            s1.replace(i,1,"");
    }

    return s1;
}
string RemovePunctuationsDoctorSolve(string S1)
{
    string S2 = "";
    for (short i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
        {
            S2 += S1[i];
        }
    }
    return S2;
}

#pragma endregion

#pragma endregion

#pragma region Last 6 Problems Client Problems (45 - 51)

// Problem 45
struct strClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    float Balance = 0;
};

void ReadClientData(strClient& client,bool UpdateAccountNumber = true)
{
    cout << "Enter your client data :-\n" << endl;
    if (UpdateAccountNumber)
    {
        cout << "Enter Account Number? ";
        // Usage of std::ws will extract allthe whitespace character
        getline(cin >> ws, client.AccountNumber);
    }
    
    cout << "Enter PinCode? ";
    getline(cin >> ws, client.PinCode);

    cout << "Enter Name? ";
    getline(cin, client.Name);
    
    cout << "Enter Phone? ";
    getline(cin, client.Phone);
    
    cout << "Enter AccountBalance? ";
    cin >> client.Balance;
}

string ConvertClientDataToOneLine(strClient& client, string seperator = "#//#")
{
    return client.AccountNumber
        + seperator + client.PinCode
        + seperator + client.Name
        + seperator + client.Phone
        + seperator + to_string(client.Balance);
}

void ConvertClientDataLineToRecord(strClient& client, string lineData, string seperator = "#//#")
{
    vector <string> vClientData = MySplit(lineData, seperator);

    if (vClientData.size() == 5)
    {
        client.AccountNumber = vClientData[0];
        client.PinCode = vClientData[1];
        client.Name = vClientData[2];
        client.Phone = vClientData[3];
        client.Balance = std::stof(vClientData[4]);
    }
}

void PrintClientData(const strClient& Client)
{
    cout << "\n===================================\n";
    cout << "         CLIENT DETAILS             \n";
    cout << "===================================\n";
    cout << "Account Number : " << Client.AccountNumber << endl;
    cout << "Pin Code       : " << Client.PinCode << endl;
    cout << "Client Name    : " << Client.Name << endl;
    cout << "Phone Number   : " << Client.Phone << endl;
    cout << "Account Balance: $" << fixed << setprecision(2) << Client.Balance << endl;
    cout << "===================================\n";
}
void AddCientDataToFile(strClient& Client, string fileName = "Clients Data.txt")
{
    fstream fs;
    fs.open(fileName, ios::out | ios::app);

    if (fs.is_open())
    {
        string line = ConvertClientDataToOneLine(Client);
        if (line != "")
            fs << line << endl;

        fs.close();
    }
}
vector<string> LoadClientsDataToStringVector(string fileName = "Clients Data.txt")
{
    string line;
    fstream fs;
    fs.open(fileName, ios::in);
    vector<string> ClientsRecords;
    if (fs.is_open())
    {
        while (getline(fs, line))
        {
            ClientsRecords.push_back(line);
        }
        fs.close();
    }

    return ClientsRecords;
}

vector<strClient> LoadClientsDataToStructVector(string fileName = "Clients Data.txt")
{
    string line;
    fstream fs;
    fs.open(fileName, ios::in);
    vector<strClient> ClientsRecords;
    strClient client;
    if (fs.is_open())
    {
        while (getline(fs, line))
        {
            ConvertClientDataLineToRecord(client, line);
            ClientsRecords.push_back(client);
        }

        fs.close();
    }
    return ClientsRecords;
}

void AddClientsToFile()
{
    char breakChar = 'y';
    strClient Client;
    do
    {
        ReadClientData(Client);
        AddCientDataToFile(Client);

        cout << "Do you want to add more clients : [y] yes" << endl;
        cin >> breakChar;

        if (tolower(breakChar) != 'y')
            break;
    } while (true);

}

void PrintClientRecord(strClient &Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.Balance;
    cout << endl;
}

void PrintAllClientsData()
{
    vector<string> ClientsRecords = LoadClientsDataToStringVector();
    strClient client;

    cout << "\n\t\t\t\t\tClient List (" << ClientsRecords.size() << ") Client(s).";
        cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    for (short i = 0; i < ClientsRecords.size(); i++)
    {
        ConvertClientDataLineToRecord(client, ClientsRecords[i]);
        PrintClientRecord(client);
    }
    
    cout <<
        "_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

strClient SearchForClientByAccountNumber(string accountNumber)
{
    vector<strClient> vClients = LoadClientsDataToStructVector();
    for (strClient& client : vClients)
    {
        if (client.AccountNumber == accountNumber)
        {
            return client;
        }
    }
    strClient c;
    return c;
}

void DeleteClientRecordByAccountNumber(string AccountNumber, string fileName = "Clients Data.txt")
{
    vector<strClient> Clients = LoadClientsDataToStructVector();

    fstream fs;
    fs.open(fileName, ios::out | ios::trunc);

    if (fs.is_open())
        fs.close();

    bool isExit = false;

    char UserChar = 'n';
    for (strClient &c : Clients)
    {
        if (c.AccountNumber == AccountNumber )
        {
            PrintClientData(c);
            
            cout << "Are you sure you want to delete this client : [Y] yes" << endl;
            cin >> UserChar;
            isExit = true;

            if (tolower(UserChar) == 'y')
            {
                cout << "\nClient Deleted Successfully" << endl;
                continue;
            }
        }
        AddCientDataToFile(c);
    }
    
    if (!isExit)
        cout << "\nClient with account number (" << AccountNumber << ") not found :(" << endl;
}

void UpdateClientRecordByAccountNumber(string AccountNumber, string fileName = "Clients Data.txt")
{
    vector<strClient> Clients = LoadClientsDataToStructVector();

    fstream fs;
    fs.open(fileName, ios::out | ios::trunc);

    if (fs.is_open())
        fs.close();

    bool isExit = false;

    char UserChar = 'n';
    for (strClient &c : Clients)
    {
        if (c.AccountNumber == AccountNumber )
        {
            PrintClientData(c);
            
            cout << "Are you sure you want to update this client : [Y] yes" << endl;
            cin >> UserChar;
            isExit = true;

            if (tolower(UserChar) == 'y')
            {
                ReadClientData(c, false);
                cout << "\nClient Update Successfully" << endl;          
            }
        }
        AddCientDataToFile(c);
    }
    
    if (!isExit)
        cout << "\nClient with account number (" << AccountNumber << ") not found :(" << endl;
}
#pragma endregion

int main()
{
    //int numbers[3][3];
    //Problem1_3x3RandomArrayFrom1To100(numbers);
    //PrintMatrix(numbers, 3, 3, "The Following is a 3x3 random matrix:"); // problem 1

    //PrintVector(SumOfAllRowsIn2DArray(numbers,3,3),"The sum of array rows :"); // problem 2 and 3

    //PrintVector(SumOfAllColsIn2DArray(numbers,3,3),"The sum of array colms :"); // problem 4 and 5

    //FillMatrixWithOrderedNumbers(numbers,3,3);
    //PrintMatrix(numbers, 3, 3, "The Following is a 3x3 order matrix:"); // problem 6

    //int transposeMatrix[3][3];
    //TransposeMatrix(numbers, transposeMatrix,3, 3); // problem 7
    //PrintMatrix(transposeMatrix, 3, 3, "The Following is a 3x3 transpose matrix:"); // problem 7

    //int MatrixOne[3][3];
    //int MatrixTwo[3][3];
    //int MatrixOfMultiResult[3][3];
    //Fill2DArrayWithRandomNumbers(MatrixOne,1,10);
    //Fill2DArrayWithRandomNumbers(MatrixTwo,1,10);
    //PrintMatrixWithFormat(MatrixOne, 3, 3, "Matrix One :"); // problem 8
    //PrintMatrixWithFormat(MatrixTwo, 3, 3, "Matrix Two :"); // problem 8
    //MultiplyMatrix(MatrixOne, MatrixTwo, MatrixOfMultiResult,3, 3); // problem 8
    //PrintMatrixWithFormat(MatrixOfMultiResult, 3, 3, "The Following is a 3x3 transpose matrix:"); // problem 8

    //int numbers[3][3];
    //FillMatrixWithOrderedNumbers(numbers,3,3);
    //PrintMatrix(numbers, 3, 3,"The orginal matrix: "); // problem 9
    //PrintMiddleRow(numbers, 3, 3); // problem 9
    //PrintMiddleColm(numbers, 3, 3); // problem 9

    //int numbers[3][3];
    //Fill2DArrayWithRandomNumbers(numbers,1,10);
    //PrintMatrix(numbers, 3, 3,"The orginal matrix: "); 
    //cout << "Sum of matrix is : " << SumOfMatrix(numbers,3,3) << endl; // problem 10

    int numbers[3][3];
    //int numbers2[3][3];
    Fill2DArrayWithRandomNumbers(numbers,1,10);
    //Fill2DArrayWithRandomNumbers(numbers2,1,10);
    //PrintMatrix(numbers, 3, 3,"The orginal matrix 1: "); 
    //PrintMatrix(numbers2, 3, 3,"The orginal matrix 2: "); 

    //cout << "Sum of matrix 1 is : " << SumOfMatrix(numbers,3,3) << endl;
    //cout << "Sum of matrix 2 is : " << SumOfMatrix(numbers2,3,3) << endl;
    //cout << "Two matrices are " << (areMatricesEqualInSum(numbers, numbers2, 3, 3) ? "equal" : "not equal") << endl; // problem 11

    //cout << "Two matrices are " << (AreTypicalMatrics(numbers, numbers2, 3, 3) ? "typical" : "not typical") << endl; // problem 12

    //int identityMatrix[3][3] = {
    //    {1,0,0},
    //    {0,1,0},
    //    {0,0,1}
    //};
    //int scalarMatrix[3][3] = {
    //    {5,0,0},
    //    {0,5,0},
    //    {0,0,5}
    //};
    //int notSparceMatrix[3][3] = {
    //    {5,1,2},
    //    {0,5,4},
    //    {0,0,5}
    //};

    //PrintMatrix(numbers, 3, 3,"The orginal matrix 2: "); 
    //PrintMatrix(identityMatrix, 3, 3,"The orginal matrix 2: ");
    //cout << "matrix is " << (isIdentityMatrix(numbers, 3, 3) ? "identity" : "not identity") << endl; // problem 13
    //cout << "matrix is " << (isIdentityMatrix(identityMatrix, 3, 3) ? "identity" : "not identity") << endl; // problem 13

    //PrintMatrix(scalarMatrix, 3, 3,"scalar matrix: ");
    //cout << "matrix is " << (isScalarMatrix(scalarMatrix, 3, 3) ? "scalar" : "not scalar") << endl; // problem 14
    //cout << "Number is redundant : " << NumberRedundancyInMatrix(scalarMatrix, 3, 3 ,5) << " time(s)" << endl; // problem 15

    //PrintMatrix(notSparceMatrix, 3, 3, "sparce matrix: ");
    //cout << "matrix is " << (isSparceMatrix(notSparceMatrix, 3, 3) ? "sparce" : "not sparce") << endl; // problem 16
    //cout << "matrix is " << (isSparceMatrixDoctorSolution(notSparceMatrix, 3, 3) ? "sparce" : "not sparce") << endl; // problem 16

    //PrintMatrix(numbers, 3, 3, "sparce matrix: ");
    //int checkedNumber = 10;
    //cout << "is number " << checkedNumber <<" in matrix " 
    //    << (isNumberInMatrix(numbers, 3, 3, checkedNumber) ? " yes" : " no") << endl; // problem 17

    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
    int Matrix2[3][3] = { {5,80,90},{22,77,1},{10,8,33} };
    //PrintMatrix(Matrix1,3,3,"Martix one : ");
    //PrintMatrix(Matrix2,3,3,"Martix two : ");
    //PrintVector(IntersectedNumbers(Matrix1, Matrix2,3,3), "Same numbers in two matrices is : "); // problem 18

    //int Matrix3[3][3] = { {77,5,12},{22,20,6},{14,3,9} };
    //PrintMatrix(Matrix3,3,3,"Martix one : ");
    //cout << "Max number in matrix is : " << MaxNumberInMatrix(Matrix3,3,3) << endl; // problem 19
    //cout << "Min number in matrix is : " << MinNumberInMatrix(Matrix3,3,3) << endl; // problem 19
    
    
    //int PalindromeMatrix[3][3] = { {1,2,1},{5,5,5},{7,3,7} };
    //int NotPalindromeMatrix[3][3] = { {1,2,1},{5,5,5},{7,3,4} };
    //PrintMatrix(PalindromeMatrix, 3, 3, "Palindrome Matrix :");
    //cout << "Is matrix Palindrome ? " 
    //    << (IsPalindromeMatrix(PalindromeMatrix, 3, 3) ? " yes" : " no") << endl; // problem 20
    //PrintMatrix(NotPalindromeMatrix, 3, 3, "Palindrome Matrix :");
    //cout << "Is matrix Palindrome ? " 
    //    << (IsPalindromeMatrix(NotPalindromeMatrix, 3, 3) ? " yes" : " no") << endl; // problem 20

    // Fibonacci Series Problem 21
    //int ArrayOfNumbers[10];
    //FillArrayFibonacciSeries(ArrayOfNumbers, 10);
    //PrintArray(ArrayOfNumbers, 10, "Fibonacci Series in array");
    //PrintFibonacciUsingLoop(15);

    // Fibonacci Series with recursion problem 22
    //PrintFibonacciUsingRecurssion(15,1,0);

    /*
    I solve this problem with very complicated type but the requirment of problem is very easy than this
    */
    //vector<char> chars = FirstLetterOfStringWords(ReadStringFromUser("Please enter your string : "));
    //PrintVectorOfChars(chars, "Your string first char in words : ");
    // 
    // easy solve if solve it after watch doctor solver
    //PrintFirstLetterOfEachWord(ReadStringFromUser("Please enter your string : "));

    // Problem 24
    //PrintUpperCaseOfEachStringWord(ReadStringFromUser("Please enter your string : "));
    //cout << UpperFirstLetterInEachWord(ReadStringFromUser("Please enter your string : ")) << endl;

    // Problem 25
    //cout << LowerFirstLetterInEachWord(ReadStringFromUser("Please enter your string : ")) << endl;

    // Problem 26
    //cout << StringToUpper(ReadStringFromUser("Please enter your string : ")) << endl;
    //cout << StringToLower(ReadStringFromUser("Please enter your string : ")) << endl;

    // Problem 27
    //cout << InvertCharCase('c') << endl;
    //cout << InvertCharCase('P') << endl;
    //cout << InvertCharCase('E') << endl;
    
    // Problem 28
    //cout << InvertStringCharsCase(ReadStringFromUser("Please enter your string : ")) << endl;
    
    // Problem 29
    //string s1 = ReadStringFromUser("Please enter your string : ");
    //cout << "String Length = " << (s1).length() << endl;
    //cout << "Capital Letters Count = " << StringNumberOfUpperLetters(s1) << endl;
    //cout << "Small Letters Count = " << StringNumberOfLowerLetters(s1) << endl;

    // Problem 30
    //string s1 = ReadStringFromUser("Please enter your string : ");
    //char c = 'c';
    //cout << "Cout of "<< c << "letter in your string is : " << CountCharInString(s1, c) << endl;

    // Problem 31
    //string s1 = ReadStringFromUser("Please enter your string : ");
    char c = 'c';
    //cout << "Cout of "<< c << " letter in your string is : " << CountCharInString(s1, c,true) << endl;
    //cout << "Cout of "<< c << " letter in your string is (With ignore char case) : " << CountCharInStringWithIgnoreCase(s1, c) << endl;
    //cout << "Cout of "<< c << " letter in your string is : " << CountCharInString(s1, c,true) << endl;
    //cout << "Cout of "<< c << " letter in your string is (With ignore char case) : " << CountCharInString(s1, c,false) << endl;
    
    // Problem 32
    //cout << "letter "<< c << " is a vowel  : " << (IsAVowel(c) ? "Yes" : "No") << endl;

    // Problem 35
    //PrintEachWordInString(ReadStringFromUser("Please enter your string that you want to split it to lines : "));
    //PrintEachWordInStringDoctorSolve(ReadStringFromUser("Please enter your string that you want to split it to lines : "));
    
    // Problem 36
    //short wordsCount = CountOfWordsInString(ReadStringFromUser("Please enter your string that you want to split it to lines : "));
    //cout << "Your number of words in string is : " << wordsCount << endl;
    
    // Problem 36
    //vector<string> vectorOfWords = MySplit(ReadStringFromUser("Please enter your string that you want to split it to lines : "),"h");
    //cout << "Tokens : " << vectorOfWords.size() << endl;
    //for (short i = 0; i < vectorOfWords.size(); i++)
    //    cout << vectorOfWords[i] << endl;
    
    // Problem 38
    //string sAfterLeftTrim = TrimLeft(ReadStringFromUser("Please enter your string that you want to trim it left : "));
    //cout << sAfterLeftTrim << endl;
    //string sAfterRightTrim = TrimRight(ReadStringFromUser("Please enter your string that you want to trim it right : "));
    //cout << sAfterRightTrim << endl;
    
    // Problem 39
    //vector<string> strings = { "Ahmed","hossny","ahmed" };
    //cout << "Vector after delim : " << Join(strings, " ") << endl;

    // Problem 40 
    // I'm not make this overload => join(string strings [],array size, string delim)
    // too easy

    // Problem 41
    //string ReversedString = ReverseString(ReadStringFromUser("Please enter string that you want to reverse it : "));
    //cout << ReversedString << endl;

    // Problem 42
    //string StringThatWithBeReplaced = "ahmed hossny ahmed";
    //string newValue = "ali";
    //cout << "String before repace (ahmed) to be " << newValue << " : " << StringThatWithBeReplaced << endl;
    //cout << "String after repace (ahmed) to be " << newValue << " : "
    //    << ReplaceSpecificWordInString(StringThatWithBeReplaced, "ahmed", newValue) << endl; // logic error
    //// Problem 42 After watch video
    //cout << ReplaceSpecificWordInStringAfterWatchVideo(StringThatWithBeReplaced, "ahmed", newValue) << endl;

    // Problem 43 case sensitive
    //cout << "case sensitive : " << ReplaceSpecificWordInStringWithCaseSensitive(StringThatWithBeReplaced, "Ahmed", newValue, true) << endl;
    //cout << "not case sensitive : "  << ReplaceSpecificWordInStringWithCaseSensitive(StringThatWithBeReplaced, "ahmed", newValue,false) << endl;

    //cout << "Before Remove All Punctuations : " << "Hi, i'm ahmed; and i'm from egypt." << endl;
    //cout << "After Remove All Punctuations: " << RemoveAllPunctuations("Hi, i'm ahmed; and i'm from egypt.") << endl;

    //// Problem 45 
    //strClient clientData;
    //ReadClientData(clientData);
    //cout << ConvertClientDataToOneLine(clientData) << endl;

    //// Problem 46
    //strClient clientDataFromString;
    //ConvertClientDataLineToRecord(clientDataFromString, ConvertClientDataToOneLine(clientData));
    //PrintClientData(clientDataFromString);

    // Problem 47
    //AddClientsToFile();

    // Problem 48
    //PrintAllClientsData();

    // Problem 49
    //strClient clientData = SearchForClientByAccountNumber("16161");
    //if (clientData.AccountNumber == "")
    //    cout << "Client not found :(" << endl;
    //else
    //    PrintClientData(clientData);

    // Problem 50
    //DeleteClientRecordByAccountNumber("545566");
    
    // Problem 51
    UpdateClientRecordByAccountNumber("1546546");
}
