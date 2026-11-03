
#include <iostream>
// to use all methods in this namespace without calling it with name (std::)
using namespace std;

int main()
{

}

void PrintOutputTask()
{

    //// Assign One
    //cout << "<<<<<<<< Assign One >>>>>>>>" << endl << endl;

    //cout << "*********************" << endl;
    //cout << "Name : Ahmed hosny" << endl;
    //cout << "Age : 22" << endl;
    //cout << "City : Dekerns" << endl;
    //cout << "Country : Egypt" << endl;
    //cout << "*********************" << endl;
    //// Assign Two
    //cout << "<<<<<<<< Assign Two >>>>>>>>" << endl << endl;

    //cout << "**************"<< endl;
    //cout << "**************"<< endl;
    //cout << "**************"<< endl;
    //cout << "**************"<< endl;
    //// Assign Three
    //cout << "<<<<<<<< Assign Three >>>>>>>>" << endl << endl;

    //cout << "I love programming!" << endl << endl;

    //cout << "I promise to be the best developer ever!" << endl << endl;

    //cout << "I know it will take some time to be but i" << endl<< "i will achive my goal" << endl << endl;

    //cout << "Best Regards," << endl << "Ahmed hosny" << endl << endl;

    //// Assign Four
    //cout << "<<<<<<<< Assign Four >>>>>>>>" << endl << endl;
    //cout << "*    *" << endl;
    //cout << "*    *" << endl;
    //cout << "******" << endl;
    //cout << "*    *" << endl;
    //cout << "*    *" << endl;
}

void endlinetypes() // endl vs \n
{
    // remove things from buffer
    cout << "Mohammed Abu-Hadhoud." << endl;

    // not remove things from buffer

    cout << "Mohammed Abu-Hadhoud. \n";
}

void literals() // course 3 v #16
{
    /*
    * literals types

    Integer Literals:
    decimal (base 10)
    octal (base 8)
    hexadecimal (base 16)

    Decimal: 0, -9, 22 etc
    Octal: 021, 077, 033 etc
    Hexadecimal: 0x7f, 0x2a, 0x521 etc

    In C++ programming, octal starts with a O, and hexadecimal starts with a 0x.
    2. Floating-Point Literals: 13.5, 1.99, -8.07
    3. Characters Literals: A, b, z, $, #
    4. Escape Sequences Literals: \n, it will be explained next .

    Literal Types:
        In C++ programming, octal starts with a O, and hexadecimal starts with a 0x.

    2. Floating-Point Literals: 13.5, 1.99, -8.07
    3. Characters Literals: A, b, z, $, #
    4. Escape Sequences Literals: \n, it will be explained next .
    */

    /*
        Escape Sequence

        \\ Backslash
        \n Newline
        \t tab
        \a audio bell
        \' single quote
        \" double quote
    */

}

void VariablesHomework() // course 3 v #17
{
    // very easy i will not solve this 
}

static void TakeInputFromUser()
{
    string Name;
    unsigned short Age;
    string Country;
    string City;
    char Gender;
    bool IsMarried;
    float MonthlySalary;

    cout << "What is your name ? ";
    cin >> Name;

    cout << "how old are you ? ";
    cin >> Age;

    cout << "what is your city ? ";
    cin >> City;

    cout << "What is your country ? ";
    cin >> Country;

    cout << "What is your gender ? (m/f) ";
    cin >> Gender;

    cout << "are you married ? ";
    cin >> IsMarried;

    cout << "how much your salary in month ? ";
    cin >> MonthlySalary;

    cout << "************************\n";
    cout << "Name: " << Name << endl;
    cout << "Age: " << Age << endl;
    cout << "Country: " << Country << endl;
    cout << "City: " << City << endl;
    cout << "Gender: " << Gender << endl;
    cout << "Is married: " << IsMarried << endl;
    cout << "Monthly Salary: " << MonthlySalary << endl;
    cout << "************************\n";

}

void ArithmaticOperators()
{
    int FNumber;
    int SNumber;

    cout << "Please enter your first number : ";
    cin >> FNumber;
    cout << "Please enter your Second number : ";
    cin >> SNumber;

    cout << "************************\n";
    cout << FNumber << " + " <<  SNumber << " = " <<FNumber + SNumber << endl;
    cout << FNumber << " - " <<  SNumber << " = " <<FNumber - SNumber << endl;
    cout << FNumber << " * " <<  SNumber << " = " <<FNumber * SNumber << endl;
    cout << FNumber << " / " <<  SNumber << " = " <<FNumber / SNumber << endl;
    cout << FNumber << " % " <<  SNumber << " = " <<FNumber % SNumber << endl;
    cout << "************************\n";
    
}

struct PersonContactInfo
{
    string Phone;
    string Email;
};

struct Person
{
    string Name;
    unsigned short Age;
    string Country;
    string City;
    char Gender ;
    bool IsMarried ;
    float MonthlySalary;

    // you can use struct inside another one
    PersonContactInfo Person_Contact_Info;
};

void UsePersonStruct()
{
    Person p1;

    cout << "What is your name ? ";
    cin >> p1.Name;

    cout << "how old are you ? ";
    cin >> p1.Age;

    cout << "what is your city ? ";
    cin >> p1.City;

    cout << "What is your country ? ";
    cin >> p1.Country;

    cout << "What is your gender ? (m/f) ";
    cin >> p1.Gender;

    cout << "are you married ? ";
    cin >> p1.IsMarried;

    cout << "how much your salary in month ? ";
    cin >> p1.MonthlySalary;

    cout << "************************\n";
    cout << "Name: " << p1.Name << endl;
    cout << "Age: " << p1.Age << endl;
    cout << "Country: " << p1.Country << endl;
    cout << "City: " << p1.City << endl;
    cout << "Gender: " << p1.Gender << endl;
    cout << "Is married: " << p1.IsMarried << endl;
    cout << "Monthly Salary: " << p1.MonthlySalary << endl;
    cout << "************************\n";
}

#include <string>
void TypeConversion()
{
    // Convert from float to int

    int x;
    float y = 99.9;

    x = y; // implicit convert
    x = (int)y; // explicit convert
    x = int(y); // explicit convert

    // From string to → (int, float , double)
    // Use this libary → #include <string>

    string stringNumber = "1542.54";
    double dNumber;
    x = stoi(stringNumber);
    y = stof(stringNumber);
    dNumber = stod(stringNumber);

    // Number to string
    string s1 = to_string(x);

}

// Using The gloable variables
int x = 10;
int y = 20;
void GloubleVariableUsage()
{
    cout << x;

    // if there is a local variable with the same name of glouble one you should use "::"
    int y = 200;
    cout << y;
    cout << ::y;
}

// pass parameter by ref by using → &parameterName
void MyFunction(int &Num1)
{
    int Num1 = 16000;

    cout << Num1 << endl; // output 16000
    cout << &Num1; // address of variable in memory 
}
