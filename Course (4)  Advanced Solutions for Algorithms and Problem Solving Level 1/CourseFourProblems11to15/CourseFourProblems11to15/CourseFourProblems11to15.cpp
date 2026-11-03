#include <iostream>
#include <string>
using namespace std;

int ReadNumber()
{
	int Num;

	cout << "Please enter your number ?" << endl;
	cin >> Num ;

	return Num;
}

int SumOfNumbers(int numOfNumbers)
{
	int Sum = 0;

	for (int i = 0; i < numOfNumbers; i++)	
		Sum += ReadNumber();

	

	return Sum;
}

float CalculateAvg(int num, int numOfNumbers)
{
	return (float)num / numOfNumbers;
}

void PrintResult(float num)
{
	cout << "Your avg result is : " << num << endl;
}

bool IsPass(int num)
{
	return num >= 50;
}
void FailOrPass(int num)
{
	if (IsPass(num))
		cout << "Pass" << endl;
	else
		cout << "Fail" << endl;
}

int main()
{
	int AvrageResult = CalculateAvg(SumOfNumbers(3), 3);
	PrintResult(AvrageResult);

	FailOrPass(AvrageResult);
}