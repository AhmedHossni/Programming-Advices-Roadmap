#include <iostream>
#include "clsLoginScreen.h"

// Bank Project To Login Lesson
//int main()
//{
//    while (true)
//    {
//        if (clsLoginScreen::ShowLoginScreen() == clsLoginScreen::eLoginError)
//            break;
//    }
//    return 0;
//}

#include <iostream>
#include "clsCurrency.h"

static void _PrintCurrency(clsCurrency Currency)
{
    cout << "\nCurrency Card:\n";
    cout << "_____________________________\n";
    cout << "\nCountry    : " << Currency.Country();
    cout << "\nCode       : " << Currency.CurrencyCode();
    cout << "\nName       : " << Currency.CurrencyName();
    cout << "\nRate(1$) = : " << Currency.Rate();

    cout << "\n_____________________________\n";

}

static void CurrencyCalculator()
{
    cout << "------------------------\n";
    cout << "Currency Calculator:\n";
    cout << "------------------------\n";

    string Currency1Code = "";
    string Currency2Code = "";
    float amount = 0;

    cout << "Please enter your curreny 1 code : " << endl;
    cin >> Currency1Code;
    
    cout << "Please enter your curreny 2 code : " << endl;
    cin >> Currency2Code;
    
    cout << "Please your amount : " << endl;
    cin >> amount;

    clsCurrency C1 = clsCurrency::FindByCode(Currency1Code);
    clsCurrency C2 = clsCurrency::FindByCode(Currency2Code);

    if (C1.CurrencyCode() == "USD")
    {
        _PrintCurrency(C2);

        cout << amount << " " << C2.CurrencyCode() << " = " 
            << amount / C2.Rate() << " " << C1.CurrencyCode();
    }
    else if (C2.CurrencyCode() == "USD")
    {
        _PrintCurrency(C1);

        cout << amount << " " << C1.CurrencyCode() << " = "
            << amount /C1.Rate()  << " " << C2.CurrencyCode();
    }
    else
    {
        _PrintCurrency(C1);

        cout << amount << " " << C1.CurrencyCode() << " = "
            << amount / C1.Rate() << " USD";

        cout << "\n\n";
        
        _PrintCurrency(C2);

        cout << amount << " " << C1.CurrencyCode() << " = "
            << (amount / C1.Rate()) * C2.Rate() << " " << C2.CurrencyCode();
        cout << "\n\n";

    }
}

void TestclsCurrencyClass()
{
    clsCurrency Currency1 = Currency1.FindByCode("jod");

    if (Currency1.IsEmpty())
    {
        cout << "\nCurrency Is Not Found!\n";
    }
    else
    {
        _PrintCurrency(Currency1);
    }

    clsCurrency Currency2 = Currency2.FindByCountry("Egypt");

    if (Currency2.IsEmpty())
    {
        cout << "\nCurrency Is Not Found!\n";
    }
    else
    {
        _PrintCurrency(Currency2);
    }

    cout << "Currency1 after updating Rate:\n";
    Currency1.UpdateRate(0.71);
    _PrintCurrency(Currency1);
}

int main()

{
    //TestclsCurrencyClass();

    CurrencyCalculator();
    return 0;
}

