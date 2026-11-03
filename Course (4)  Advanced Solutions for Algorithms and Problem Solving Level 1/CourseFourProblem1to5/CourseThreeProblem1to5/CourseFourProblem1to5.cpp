// CourseThreeProblem1to5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

#pragma region Problem 1
// Problem one Print name 
void PrintName(string name)
{
	cout << "Your name is " << name << endl;
}
#pragma endregion

#pragma region Problem 2
// Problem two (read user name and print it)
string ReadName()
{
	string name;

	cout << "Please enter your name : " << endl;
	getline(cin,name);

	return name;
}
#pragma endregion

#pragma region Problem 3
// Problem three (read number and show → odd or even)
int ReadNumber()
{
	int number;

	cout << "Please enter your number : " << endl;
	cin >> number;

	return number;
}

void OddOrEven(int number)
{
	if (number % 2 == 0)
	{
		cout << "number is even";
	}
	else
	{
		cout << "number is odd";
	}
}

// Problem 3 Dr soution
enum enNumberType { Odd = 1, Even };

// then readnumber method

enNumberType CheckNumberType(int number)
{
	if (number % 2 == 0)
		return enNumberType::Even;
	else
		return enNumberType::Odd;
}

void PrintNumberType(enNumberType numType)
{
	switch (numType)
	{
	case enNumberType::Even:
		cout << "Even" << endl;
		break;
	case enNumberType::Odd:
		cout << "Odd" << endl;
		break;
	}
}
#pragma endregion

#pragma region Problem 4
enum enHasDriverLicense { NotHave = 0, Have = 1 };

void PrintDriverLicenseMenu()
{
	cout << "Enter if you have a driver licese\n";
	cout << "(0) Not have one\n";
	cout << "(1) Have one\n";
	cout << "any else or defult is not have one (0)\n";
}

int ReadIfHaveDriverLicense()
{
	PrintDriverLicenseMenu();

	int DriverLicenceChoose;
	cin >> DriverLicenceChoose;

	return DriverLicenceChoose;
}

enHasDriverLicense CheckDriverLicese()
{
	int UserChoose = ReadIfHaveDriverLicense();

	switch (UserChoose)
	{
		case enHasDriverLicense::Have:
			return enHasDriverLicense::Have;
			break;
		case enHasDriverLicense::NotHave:
			return enHasDriverLicense::NotHave;
			break;
		default:
			return enHasDriverLicense::NotHave;
	}
}

int ReadUserAge()
{
	cout << "Please enter your age : " << endl;

	int age;
	cin >> age;

	return age;
}

bool CheckAge(int age)
{
	return age >= 21;
}

void HireOrRejected(int age, enHasDriverLicense driverLicenceChoose)
{
	if (CheckAge(age) && driverLicenceChoose == enHasDriverLicense::Have)
		cout << "Hired" << endl;
	else
		cout << "Rejected" << endl;

}

// Dr Solve 
struct stInfo
{
	int Age;
	bool HasDrivingLicense;
};


stInfo ReadInfo()
{
	stInfo Info;

	cout << "Please Enter Your Age?" << endl;
	cin >> Info.Age;

	cout << "Do you have driver License?" << endl;
	cin >> Info.HasDrivingLicense;

	return Info;
}

bool IsAccepted(stInfo Info) 
{
	return (Info.Age >= 21 && Info.HasDrivingLicense);
}

void PrintResult(stInfo Info)
{
	if (IsAccepted(Info))
		cout << "\n Hired" << endl;
	else
		cout << "\n Rejected" << endl;
}


#pragma endregion


int main()
{
	//PrintName("Ahmed");

	
	//PrintName(ReadName());

	//OddOrEven(ReadNumber()); // My solve
	//PrintNumberType(CheckNumberType(ReadNumber())); // Dr solve

	// Problem Four 
	HireOrRejected(ReadUserAge(), CheckDriverLicese());
	PrintResult(ReadInfo()); // Dr solved
}

