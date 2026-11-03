#include <iostream>
#include "clsUtil.h"

using namespace std;

int main()
{
    clsUtil::Srand();
    cout << clsUtil::RandomNumber(1, 10) << endl;
    cout << clsUtil::GetRandomCharacter(clsUtil::enCharType::CapitalLetter) << endl;
    cout << clsUtil::GenerateWord(clsUtil::enCharType::MixChars, 8) << endl;
    cout << clsUtil::GenerateKey(clsUtil::enCharType::MixChars) << endl;
    clsUtil::GenerateKeys(10, clsUtil::enCharType::MixChars);
    
}