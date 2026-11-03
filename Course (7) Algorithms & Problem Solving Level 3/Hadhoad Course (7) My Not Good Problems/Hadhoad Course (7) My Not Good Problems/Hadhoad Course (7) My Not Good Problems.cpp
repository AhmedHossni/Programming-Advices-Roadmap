#include <iostream>
#include <string>
#include <vector>
using namespace std;

#pragma region Problem 35 Print Each Word In String
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
        else if (i == s1.length() - 1)
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

#include <iostream>
#include <sstream> // رئيسية لاستخدام stringstream

void PrintEachWordInStringGemeni(string s1)
{
    stringstream ss(s1);
    string word;

    cout << "\nYour string words are: \n\n";
    // تقوم بالقراءة كلمة كلمة تلقائياً وتتجاهل المسافات الزائدة
    while (ss >> word)
    {
        cout << word << endl;
    }
}
#pragma endregion
#pragma region is vowel problem
// my solve

bool IsAVowel(char c)
{
    char Vowels[] = { 'a','e','i','o','u' };

    for (short i = 0; i < 5; i++)
    {
        if (tolower(c) == Vowels[i])
            return true;
    }
    return false;
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
#pragma endregion
#pragma region Trim the string

string TrimLeft(string S1)
{
    short LastEmptyPos = 0;

    for (const char& c : S1)
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
string TrimLeftDoctor(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(i, S1.length() - i);
        }
    }
    return "";
}

string TrimRightDoctor(string S1)
{
    for (short i = S1.length() - 1; i >= 0; i--)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(0, i + 1);
        }
    }
    return "";
}
string TrimDoctor(string S1)
{
    return (TrimLeft(TrimRight(S1)));
}
#pragma endregion

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

    if (S1 != "")
        stringWords.push_back(S1);

    return stringWords;
}

string ReplaceWordInStringUsingBuiltInFunctionDoctor(string S1, string
    StringToReplace, string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(),
            sRepalceTo);
        pos = S1.find(StringToReplace);//find next
    }
    return S1;
}

// my func => logic error (the func is not correct)
string ReplaceWordInStringUsingBuiltInFunction(string s1, string replacedValue, string newWord)
{
    string newReplacedString = "";
    short pos = 0;
    short startIndex = 0;
    while ((pos = s1.find(replacedValue)) != string::npos)
    {
        s1.erase(pos, replacedValue.size());

        newReplacedString.append(s1.substr(startIndex, pos));
        newReplacedString.append(newWord);

        startIndex = pos + newWord.size();
    }

    return newReplacedString;
}


// Problem 44
string RemoveAllPunctuations(string s1)
{
    for (short i = 0; i < s1.size(); i++)
    {
        if (ispunct(s1[i]))
            s1.replace(i, 1, "");
    }

    return s1;
}
int main()
{


}
