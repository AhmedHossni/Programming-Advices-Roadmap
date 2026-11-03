#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{
public : 
    enum enLoginStatus {eLoginError, eLoginAccepted};
private:

    static  enLoginStatus _Login()
    {
        bool LoginFaild = false;
        short Trials = 2;
        string Username, Password;
        enLoginStatus LoginStatus;
        do
        {
            if (Trials == 0)
            {
                cout << "Your are Locked after 3 faild trails" << endl;
                LoginStatus = eLoginError;
                break;
            }

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!";
                cout << "\nYou have " << Trials-- <<  " trial(s) to login!\n\n";
            }

            

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

            LoginStatus = eLoginAccepted;

        } while (LoginFaild);

        if(LoginStatus == eLoginAccepted)
        {
            CurrentUser.SaveInLogFile();
            clsMainScreen::ShowMainMenue();
        }

        return LoginStatus;
    }

public:


    static clsLoginScreen::enLoginStatus ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");

        if (_Login() == clsLoginScreen::eLoginError)
            return eLoginError;
        else
            return eLoginAccepted;
    }

};