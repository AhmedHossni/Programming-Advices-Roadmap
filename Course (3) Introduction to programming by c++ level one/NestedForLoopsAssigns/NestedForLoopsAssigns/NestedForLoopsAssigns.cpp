#include <iostream>
using namespace std;

void PrintAWtihAllLetters()
{
    for (int x = 65; x <= 90; x++)
    {
        for (int i = 65;i <= 90; i++)
        {
            cout << char(x) << char(i) << endl;
             
        }
    }
}

void PrintRevercedPiramed()
{
    for (int x = 10; x >= 1; x--)
    {
        for (int i = 1;i <= x; i++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

void PrintRevercedPiramedOfNumbers()
{
    for (int x = 10; x >= 1; x--)
    {
        for (int i = 1;i <= x; i++)
        {
            cout << i;
        }
        cout << "\n";
    }
}

void PrintPiramedOfNumbers()
{
    for (int x = 1; x <= 10; x++)
    {
        for (int i = 1;i <= x; i++)
        {
            cout << i;
        }
        cout << "\n";
    }
}

void PrintPiramedOfLetters()
{
    for (int x = 1; x <= 6; x++)
    {
        for (int i = 1;i <= x; i++)
        {
            cout << char(64 + i);
        }
        cout << "\n";
    }
}

int main()
{
    //PrintAWtihAllLiters();

    //PrintRevercedPiramed();

    //PrintRevercedPiramedOfNumbers();

    //PrintPiramedOfNumbers();

    PrintPiramedOfLetters();
}

