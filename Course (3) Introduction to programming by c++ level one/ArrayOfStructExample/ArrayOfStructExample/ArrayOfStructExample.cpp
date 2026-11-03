#include <iostream>
#include <string>
using namespace std;

struct Person 
{
     string FName;
     string LName;
     short Age;
     string Phone;

};

void ReadPersonInfo(Person& person)
{
    cout << "Please enter your first name :" << endl;
    cin >> person.FName;

    cout << "Please enter your last name :" << endl;
    cin >> person.LName;

    cout << "Please enter your age :" << endl;
    cin >> person.Age;

    cout << "Please enter your phone :" << endl;
    cin >> person.Phone;
}

void ReadPersonsInfo(Person persons[2])
{
    ReadPersonInfo(persons[0]);
    ReadPersonInfo(persons[1]);
}

void WritePersonsInfo(Person persons[2])
{
    cout << "*****************************\n";
    cout << "First Name: " << persons[0].FName << endl;
    cout << "Last Name: " << persons[0].LName << endl;
    cout << "Age: " << persons[0].Age  << endl;
    cout << "Phone: " << persons[0].Phone << endl;
    cout << "*****************************\n";

    cout << "*****************************\n";
    cout << "First Name: " << persons[1].FName << endl;
    cout << "Last Name: " << persons[1].LName << endl;
    cout << "Age: " << persons[1].Age << endl;
    cout << "Phone: " << persons[1].Phone << endl;
    cout << "*****************************\n";
}

int main()
{
    Person persons[2];

    ReadPersonsInfo(persons);
    WritePersonsInfo(persons);
}


