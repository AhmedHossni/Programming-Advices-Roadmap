#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

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

    if (S1 != "")
        stringWords.push_back(S1);

    return stringWords;
}

string ReadStringFromUser(string message)
{
    string UserInput = "";
    cout << message;

    // (cin >> ws) تخبر البرنامج بأن يتجاهل أي Enter أو مسافة متبقية في الذاكرة 
    // وينتظر حتى يكتب المستخدم نصاً حقيقياً ويضغط Enter من جديد
    getline(cin >> ws, UserInput);

    return UserInput;
}

char ReadCharFromUser(string message)
{
    cout << message << endl;
    char UserInput = ' ';

    cin >> ws >> UserInput;

    return UserInput;
}

bool HaveThisPermission(int permissions, int permissionNumber)
{
    return (permissions == enPermissions::pAll) || ((permissions & permissionNumber) == permissionNumber) ;
}

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

vector<strClient> LoadClientsDataToStructVector(string fileName = "Clients Data.txt");


void ReadClientData(strClient& client, bool UpdateAccountNumber = true)
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

bool isClientExit(string AccountNumber, vector<strClient> &clients)
{
    for (strClient& client : clients)
    {
        if (client.AccountNumber == AccountNumber)
            return true;
    }
    return false;
}

void AddCientDataToFile(strClient& Client, string fileName = "Clients Data.txt")
{
    vector<strClient> Clients = LoadClientsDataToStructVector();
    if (isClientExit(Client.AccountNumber, Clients))
    {
        cout << "Client with with account number (" << Client.AccountNumber << ") is allready exist" << endl;
        return;
    }

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

vector<strClient> LoadClientsDataToStructVector(string fileName)
{
    string line;

    fstream fs;
    fs.open(fileName,  ios::in | ios::app );

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

void PrintClientRecord(strClient& Client)
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
    for (strClient& c : Clients)
    {
        if (c.AccountNumber == AccountNumber)
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

void SaveClientsToFile(vector<strClient> clients, string fileName = "Clients Data.txt")
{
    fstream fs;
    fs.open(fileName, ios::out | ios::trunc);

    if (fs.is_open())
        fs.close();

    for (strClient& c : clients)
    {
        AddCientDataToFile(c, fileName);
    }
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
    for (strClient& c : Clients)
    {
        if (c.AccountNumber == AccountNumber)
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

#pragma region User/Login/Permissions



struct stUser
{
    string Username = "";
    string Password = "";
    int Permissions = 0;
};

void PrintUserData(const stUser &user)
{
    cout << "\n===================================\n";
    cout << "         USER DETAILS             \n";
    cout << "===================================\n";
    cout << "Username : " << user.Username << endl;
    cout << "Password : " << user.Password << endl;
    cout << "Password : " << user.Permissions << endl;
    cout << "===================================\n";
}

void ConvertUserDataLineToRecord(stUser& user, string lineData, string seperator = "#//#")
{
    vector <string> vUsersData = MySplit(lineData, seperator);

    if (vUsersData.size() == 3)
    {
        user.Username = vUsersData[0];
        user.Password = vUsersData[1];
        user.Permissions = stoi(vUsersData[2]);
    }
}

vector<stUser> LoadUsersDataToStructVector(string fileName = "Users.txt")
{
    stUser User;

    fstream fs;
    fs.open(fileName, ios::in | ios::app);

    vector<stUser> UsersRecords;

    string line;

    if (fs.is_open())
    {
        while (getline(fs, line))
        {
            ConvertUserDataLineToRecord(User, line);
            UsersRecords.push_back(User);
        }

        fs.close();
    }
    return UsersRecords;
}

stUser SearchForUserBy(string username)
{
    vector<stUser> vUsers = LoadUsersDataToStructVector();
    for (stUser& user : vUsers)
    {
        if (user.Username == username)
        {
            return user;
        }
    }
    stUser u;
    return u;
}

#include <iostream>
#include <cctype>

using namespace std;

enum enPermissions {
    pAll = -1,
    pShowClientList = 1, pAddNewClient = 2, pDeleteClient = 4,
    pUpdateClient = 8, pFindClient = 16, pTransactions = 32,
    pManageUsers = 64
};

// دالة مساعدة لتقليل التكرار
bool AskForPermission(string Message)
{
    char Answer;
    cout << Message << " : [Y]yes ";
    cin >> ws >> Answer;
    return (tolower(Answer) == 'y');
}

int ReadUserPermissions()
{
    if (AskForPermission("Do you want to give this user full control"))
        return enPermissions::pAll; // Full Control

    cout << "\nDo you want to give access to :\n" << endl;
    int UserPermissions = 0;

    if (AskForPermission("Show client list")) UserPermissions |= enPermissions::pShowClientList;
    if (AskForPermission("Add new client"))   UserPermissions |= enPermissions::pAddNewClient;
    if (AskForPermission("Delete client"))    UserPermissions |= enPermissions::pDeleteClient;
    if (AskForPermission("Update client"))    UserPermissions |= enPermissions::pUpdateClient;
    if (AskForPermission("Find client"))      UserPermissions |= enPermissions::pFindClient;
    if (AskForPermission("Transactions"))     UserPermissions |= enPermissions::pTransactions;
    if (AskForPermission("Manage users"))     UserPermissions |= enPermissions::pManageUsers;

    return UserPermissions;
}

stUser UserLogin()
{
    stUser User;
    vector<stUser> Users = LoadUsersDataToStructVector();
    
    stUser SearchedForUser;

    while(true)
    {
        cout << "------ Login ------ \n" << endl;

        cout << "Please enter user name : " << endl;
        getline(cin >> ws, User.Username);

        cout << "Please enter user password : " << endl;
        getline(cin >> ws, User.Password);

        SearchedForUser = SearchForUserBy(User.Username);
        if ( !(SearchedForUser.Username == "" || SearchedForUser.Password != User.Password))
        {
            User.Permissions = SearchedForUser.Permissions;
            break;
        }
        system("cls");
        cout << "Invalid user or password :( " << endl;
        
    }

    return User;
}

stUser ReadNewUser()
{
    stUser User;

    cout << "Please enter user name : " << endl;
    getline(cin >> ws, User.Username);

    cout << "Please enter user password : " << endl;
    getline(cin >> ws, User.Password);


    User.Permissions = ReadUserPermissions();

    return User;
}

stUser ReadUpdatedUser()
{
    stUser User;

    cout << "Please enter new password : " << endl;
    getline(cin >> ws, User.Password);

    User.Permissions = ReadUserPermissions();

    return User;
}

string ConvertUserDataToOneLine(stUser& user, string seperator = "#//#")
{
    return user.Username
        + seperator + user.Password
        + seperator + to_string(user.Permissions);
}

bool isUserExits(string username, vector<stUser>& users)
{
    for (stUser & user : users)
    {
        if (user.Username == username)
            return true;
    }
    return false;
}

void AddUserToFile(stUser &user, string fileName = "Users.txt")
{
    vector<stUser> Users = LoadUsersDataToStructVector();

    if (isUserExits(user.Username, Users))
    {
        cout << "User with with username (" << user.Username << ") is already exist" << endl;
        return;
    }

    fstream fs;
    fs.open(fileName, ios::out | ios::app);

    if (fs.is_open())
    {
        string line = ConvertUserDataToOneLine(user);
        if (line != "")
            fs << line << endl;

        fs.close();
    }
}

vector<string> LoadUsersDataToStringVector(string fileName = "Users.txt")
{
    string line;

    fstream fs;
    fs.open(fileName, ios::in);

    vector<string> UsersRecords;

    if (fs.is_open())
    {
        while (getline(fs, line))
        {
            UsersRecords.push_back(line);
        }

        fs.close();
    }

    return UsersRecords;
}


void AddUsersToFile()
{
    char breakChar = 'y';
    stUser User;

    do
    {
        User = ReadNewUser();
        AddUserToFile(User);

        cout << "Do you want to add more clients : [y] yes" << endl;
        cin >> breakChar;

        if (tolower(breakChar) != 'y')
            break;

    } while (true);

}

void PrintUserRecord(stUser& user)
{
    cout << "| " << setw(15) << left << user.Username;
    cout << "| " << setw(10) << left << user.Password;
    cout << "| " << setw(3) << left << user.Permissions;
    cout << endl;
}

void PrintAllUsersData()
{
    vector<string> UsersRecords = LoadUsersDataToStringVector();
    stUser user;

    cout << "\n\t\t\t\t\tUser List (" << UsersRecords.size() << ") Client(s).";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Username";
    cout << "| " << left << setw(10) << "Password";
    cout << "| " << left << setw(3) << "Permissions";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    for (short i = 0; i < UsersRecords.size(); i++)
    {
        ConvertUserDataLineToRecord(user, UsersRecords[i]);
        PrintUserRecord(user);
    }

    cout <<
        "_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

void DeleteUserRecordBy(string username, string fileName = "Users.txt")
{
    if (username == "Admin")
    {
        cout << "You can't delete this user" << endl;
        return;
    }

    vector<stUser> Users = LoadUsersDataToStructVector();

    fstream fs;
    fs.open(fileName, ios::out | ios::trunc);

    if (fs.is_open())
        fs.close();

    bool isExit = false;

    char UserChar = 'n';
    for (stUser &u : Users)
    {
        if (u.Username == username)
        {
            PrintUserData(u);

            cout << "Are you sure you want to delete this user : [Y] yes" << endl;
            cin >> ws;
            cin >> UserChar;

            isExit = true;

            if (tolower(UserChar) == 'y')
            {
                cout << "\User Deleted Successfully" << endl;
                continue;
            }
        }
        AddUserToFile(u);
    }

    if (!isExit)
        cout << "\User with username  (" << username << ") not found :(" << endl;
}

void SaveUserToFile(vector<stUser> users, string fileName = "Users.txt")
{
    fstream fs;
    fs.open(fileName, ios::out | ios::trunc);

    if (fs.is_open())
        fs.close();

    for (stUser &user : users)
    {
        AddUserToFile(user, fileName);
    }
}


void UpdateUserBy(string username, string fileName = "Users.txt")
{
    vector<stUser> Users = LoadUsersDataToStructVector();

    fstream fs;
    fs.open(fileName, ios::out | ios::trunc);

    if (fs.is_open())
        fs.close();

    bool isExit = false;

    char UserChar = 'n';
    for (stUser& User : Users)
    {
        if (User.Username == username)
        {
            PrintUserRecord(User);
            cout << "Are you sure you want to update this user : [Y] yes" << endl;
            cin >> UserChar;
            isExit = true;

            if (tolower(UserChar) == 'y')
            {
                User = ReadUpdatedUser();
                cout << "\User Update Successfully" << endl;
            }
        }
        AddUserToFile(User);
    }

    if (!isExit)
        cout << "\User with username (" << username << ") not found :(" << endl;
}

#pragma endregion

#pragma region Bank Project
void ShowMainMenu() 
{
    system("cls");
    std::cout << "============================================================\n";
    std::cout << "                       Main Menue Screen                    \n";
    std::cout << "============================================================\n";
    std::cout << "     [1] Show Client List.\n";
    std::cout << "     [2] Add New Client.\n";
    std::cout << "     [3] Delete Client.\n";
    std::cout << "     [4] Update Client Info.\n";
    std::cout << "     [5] Find Client.\n";
    std::cout << "     [6] Transactions.\n";
    std::cout << "     [7] Manage users.\n";
    std::cout << "     [8] Logout.\n";
    std::cout << "============================================================\n";
}

#pragma region Transactions Menu Extention
void TransactionsMenu()
{
    std::cout << "============================================================\n";
    std::cout << "                       Transactions Menue Screen                    \n";
    std::cout << "============================================================\n";
    std::cout << "     [1] Deposit.\n";
    std::cout << "     [2] Withdraw.\n";
    std::cout << "     [3] Total Balances.\n";
    std::cout << "     [4] Main Menue.\n";
    std::cout << "============================================================\n";
}

void UsersMenu()
{
    std::cout << "============================================================\n";
    std::cout << "                  Manage Users Menue Screen                    \n";
    std::cout << "============================================================\n";
    std::cout << "     [1] List Users.\n";
    std::cout << "     [2] Add new user.\n";
    std::cout << "     [3] Delete user.\n";
    std::cout << "     [4] Update user.\n";
    std::cout << "     [5] Find user.\n";
    std::cout << "     [6] Main Menu.\n";
    std::cout << "============================================================\n";
}

void Deposit(string accountNumber, float amountOfDeposit, vector<strClient> clients)
{
    strClient Client = SearchForClientByAccountNumber(accountNumber);

    if (Client.AccountNumber == "")
    {
        cout << "Client with account number [" << accountNumber << "] does not exist" << endl;
        return;
    }

    if ((amountOfDeposit * -1) > Client.Balance && amountOfDeposit < 0)
    {
        cout << "Client balance is : " << Client.Balance << " .then, you can't withdraw " << -1 * amountOfDeposit << endl;
        return;
    }

    for (strClient& c : clients)
    {
        if (c.AccountNumber == accountNumber)
        {
            c.Balance += amountOfDeposit;
            break;
        }
    }

    SaveClientsToFile(clients, "Clients Data.txt");
}

void Withdraw(string accountNumber, float amountOfWithdraw, vector<strClient> clients)
{
    Deposit(accountNumber, (amountOfWithdraw * -1), clients);
}

void PrintClientRecordBalanceLine(strClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Balance;
}

void ShowTotalBalances()
{
    vector <strClient> vClients = LoadClientsDataToStructVector();
    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    double TotalBalances = 0;
    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else
        for (strClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            TotalBalances += Client.Balance;
            cout << endl;
        }
    cout <<
        "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t Total Balances = " << TotalBalances;
    cout << endl;
}

void ShowDepositScreen()
{
    std::cout << "============================================================\n";
    std::cout << "                       Deposit Screen                    \n";
    std::cout << "============================================================\n";
}

void ShowWithdrawScreen()
{
    cout << "============================================================\n";
    cout << "                       Withdraw Screen                    \n";
    cout << "============================================================\n";
}

void getFloatInput(float& number) {
    cout << "Enter a decimal (float) number: ";

    // Read the user input directly into the reference variable
    while (!(cin >> number)) 
    {
        // If the user enters invalid input (like text), handle the error safely
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear(); // Clear the error flag
        cin.ignore(132, '\n'); // Discard the invalid line
    }
}

void ExecuteUserTransactionMenu()
{
    string AccountNumber = "";
    float Amount = 0;
    strClient Client;

    char choose = ' ';

    while (true)
    {

        choose = ReadCharFromUser("Choose what you want to do: [1 to 4]");
        if (choose != '1'
            && choose != '2'
            && choose != '3'
            && choose != '4')
        {
            cout << "Invalid input :(" << endl;
            continue;
        }

        switch (choose)
        {
        case '1':
            ShowDepositScreen();
            AccountNumber = ReadStringFromUser("Please enter your user account number : ");
            cout << endl;
            getFloatInput(Amount);
            Deposit(AccountNumber, Amount, LoadClientsDataToStructVector());
            break;
        case '2':
            ShowWithdrawScreen();
            AccountNumber = ReadStringFromUser("Please enter your user account number : ");
            getFloatInput(Amount);
            Withdraw(AccountNumber, Amount, LoadClientsDataToStructVector());
            break;
        case '3':
            ShowTotalBalances();
            break;
        case '4':
            return;
        default:
            cout << "Invalid input :(" << endl;
            break;
        }
        system("pause");
        system("cls");
        TransactionsMenu();
    }
}
#pragma endregion

void ExecuteManageUsersMenu()
{
    string Username = "";
    stUser User;

    char choose = ' ';

    while (true)
    {
        choose = ReadCharFromUser("Choose what you want to do: [1 to 6]");
        if (choose != '1'
            && choose != '2'
            && choose != '3'
            && choose != '4'
            && choose != '5'
            && choose != '6')
        {
            cout << "Invalid input :(" << endl;
            continue;
        }

        switch (choose)
        {
        case '1':
            system("cls");
            PrintAllUsersData();
            break;
        case '2':
            system("cls");
            AddUsersToFile();
            break;
        case '3':
            system("cls");
            Username = ReadStringFromUser("Please enter username for user that you want to delete : ");
            DeleteUserRecordBy(Username);
            break;
        case '4':
            system("cls");
            Username = ReadStringFromUser("Please enter username for user that you want to update : ");
            UpdateUserBy(Username);
            break;
        case '5':
            system("cls");
            Username = ReadStringFromUser("Please enter username for user that you want to find : ");
            User = SearchForUserBy(Username);
            PrintUserRecord(User);
            return;
        case '6':
            return;
        default:
            cout << "Invalid input :(" << endl;
            break;
        }
        system("pause");
        system("cls");
        UsersMenu();
    }
}

void ExecuteUserMainMenuChoose(char choose, stUser &user)
{
    string AccountNumber = "";
    strClient Client;

    while (true)
    {
        switch (choose)
        {
        case '1':
            // تم إضافة (!) لأننا نريد المنع إذا *لم* يكن يملك الصلاحية
            if (!HaveThisPermission(user.Permissions, enPermissions::pShowClientList))
            {
                cout << "You don't have the permission for this choice!" << endl;
                break; // نستخدم break وليس continue
            }
            system("cls");
            PrintAllClientsData();
            break;

        case '2':
            if (!HaveThisPermission(user.Permissions, enPermissions::pAddNewClient))
            {
                cout << "You don't have the permission for this choice!" << endl;
                break;
            }
            system("cls");
            AddClientsToFile();
            break;

        case '3':
            if (!HaveThisPermission(user.Permissions, enPermissions::pDeleteClient))
            {
                cout << "You don't have the permission for this choice!" << endl;
                break;
            }
            system("cls");
            AccountNumber = ReadStringFromUser("Please enter account number for client that you want to delete him : ");
            DeleteClientRecordByAccountNumber(AccountNumber);
            break;

        case '4':
            if (!HaveThisPermission(user.Permissions, enPermissions::pUpdateClient))
            {
                cout << "You don't have the permission for this choice!" << endl;
                break;
            }
            system("cls");
            AccountNumber = ReadStringFromUser("Please enter account number for client that you want to update him :");
            UpdateClientRecordByAccountNumber(AccountNumber);
            break;

        case '5':
            if (!HaveThisPermission(user.Permissions, enPermissions::pFindClient))
            {
                cout << "You don't have the permission for this choice!" << endl;
                break;
            }
            system("cls");
            AccountNumber = ReadStringFromUser("Please enter account number for client that you search for :");
            Client = SearchForClientByAccountNumber(AccountNumber);
            if (Client.AccountNumber != "")
            {
                PrintClientData(Client);
            }
            else
            {
                cout << "Client not found........" << endl;
            }
            break;

        case '6':
            if (!HaveThisPermission(user.Permissions, enPermissions::pTransactions))
            {
                cout << "You don't have the permission for this choice!" << endl;
                break;
            }
            system("cls");
            TransactionsMenu();
            ExecuteUserTransactionMenu();
            break;

        case '7':
            if (!HaveThisPermission(user.Permissions, enPermissions::pManageUsers))
            {
                cout << "You don't have the permission for this choice!" << endl;
                break;
            }
            system("cls");
            UsersMenu();
            ExecuteManageUsersMenu();
            break;

        case '8':
            return; // للخروج من الدالة والبرنامج/القائمة الرئيسية

        default:
            cout << "Invalid input :(" << endl;
            break;
        }

        // السطور التالية ستنفذ دائماً بعد انتهاء أي Case (إلا في حال اختيار 8)
        system("pause");
        system("cls");
        ShowMainMenu();
        // تم حذف كلمة char لتحديث المتغير الأصلي وليس إنشاء واحد جديد
        choose = ReadCharFromUser("Choose what you want to do: [1 to 8]");
    }
}

void MainProgram()
{
    stUser user;
    while (true)
    {
        user = UserLogin();

        ShowMainMenu();

        char UserChoose = ReadCharFromUser("Choose what you want to do: [1 to 8]");

        if (UserChoose != '8')
        {
            ExecuteUserMainMenuChoose(UserChoose, user);
        }

        system("Pause");
        system("cls");
    }
}
#pragma endregion

int main()
{
    MainProgram();
}
