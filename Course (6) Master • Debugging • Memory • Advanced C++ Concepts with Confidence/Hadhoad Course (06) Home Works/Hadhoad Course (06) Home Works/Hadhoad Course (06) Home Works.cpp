#include <iostream>
#include <vector>
#include <string>
using namespace std;

#pragma region L27 Homework
void FillTwoDimensionalArray(int TwoDArray[][10], int rowsNumber, int colsNumber)
{
	for (int row = 0; row < rowsNumber; row++)
	{
		for (int col = 0; col < colsNumber; col++)
		{
			TwoDArray[row][col] = (row + 1) * (col + 1);
		}
	}
}

void PrintTwoDimensionalArray(int TwoDArray[][10], int rowsNumber, int colsNumber)
{
	for (int row = 0; row < rowsNumber; row++)
	{
		for (int col = 0; col < colsNumber; col++)
		{
			printf("%0*d ",2,TwoDArray[row][col]);
		}
		cout << endl;
	}
}
void L27TwoDimensionalArrays()
{
	int TwoDArray[10][10];
	FillTwoDimensionalArray(TwoDArray, 10, 10);
	PrintTwoDimensionalArray(TwoDArray, 10, 10);

}
#pragma endregion

#pragma region Vectors Part I
void VectorsL28To32()
{
	vector<int> vNumbers = {1,2,3};

	// Copy the item from vector to this new variable num
	for (int num : vNumbers)
		cout << num << endl;

	// Variable num will reference to the variable in vector without copy
	for (int &num : vNumbers)
		cout << num << endl;

	for (const int &num : vNumbers)
		cout << num << endl;

	for (int i = 0; i < vNumbers.size(); i++)
			cout << vNumbers[i] << endl;

}
#pragma region Lesson 29 homework (vectors) 

void AddItemsToVector(vector<int> &numbers)
{
	char c = ' ';
	int Number = 0;
	do
	{

		cout << "Please enter your item that you want to add it to vector" << endl;
		cin >> Number;
		numbers.push_back(Number);

		cout << "Please enter [Y] if you want to add more items to your vector" << endl;
		cin >> c;

	} while (c == 'y' || c == 'Y');
}
void PrintVector(vector<int> &numbers)
{
	cout << "Your Vector : ";

	for(int &n : numbers)
		cout << n << " ";

	cout << endl;
}
void FullLesson29Homework(vector<int> &numbers)
{
	AddItemsToVector(numbers);
	PrintVector(numbers);
}

#pragma endregion
#pragma region Lesson 30 homework (vectors) 
struct stEmployee
{
	string FirstName = "";
	string LastName = "";
	int Salary = 0;
};

void AddEmoloyeeItemsToVector(vector<stEmployee>& employees)
{
	char c = ' ';
	stEmployee employee;
	do
	{

		cout << "Please enter your employee first name : ";
		cin >> employee.FirstName;
		cout << endl << "Please enter your employee last name : ";
		cin >> employee.LastName;
		cout << endl <<"Please enter your employee salary : ";
		cin >> employee.Salary;
		employees.push_back(employee);

		cout << endl << "Please enter [Y] if you want to add more items to your vector : ";
		cin >> c;
		cout<< endl;

	} while (c == 'y' || c == 'Y');
}

void PrintEmployeeVector(vector<stEmployee>& employees)
{
	cout << "--------------------------------------------" << endl;
	for (stEmployee & emp : employees)
	{
		cout << "Employee First Name : " << emp.FirstName << endl;
		cout << "Employee Last Name : " << emp.LastName << endl;
		cout << "Employee Salary : " << emp.Salary << endl;
		cout << "--------------------------------------------" << endl;
	}
}
void FullLesson30Homework(vector<stEmployee>& employees)
{
	AddEmoloyeeItemsToVector(employees);
	PrintEmployeeVector(employees);
}

#pragma endregion
#pragma endregion
#pragma region Vectors Part II
void IteratorsWithVector()
{
	vector<int> nums = {1,2,3,3,4,5,6};
	vector<int>::iterator numsIterator;

	// walking into vector items using pointer
	for (numsIterator = nums.begin(); numsIterator != nums.end(); numsIterator++)
		cout << * numsIterator << " ";
	cout << endl;

}
#pragma endregion
int main()
{
	//L27TwoDimensionalArrays();

	//VectorsL28To32();
	//vector <int> Numbers;
	//FullLesson29Homework(Numbers);

	//vector<stEmployee> Employees;
	//FullLesson30Homework(Employees);

	//int x = 10;
	//int &y = x;
	//y++;
	//cout << &x;


	IteratorsWithVector();
}
