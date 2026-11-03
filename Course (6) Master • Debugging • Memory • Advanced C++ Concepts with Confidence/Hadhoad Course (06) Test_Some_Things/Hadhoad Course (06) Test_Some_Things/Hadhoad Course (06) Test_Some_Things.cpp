#include <iostream>
#include <string>
using namespace std;

#pragma region Dynamic Memory Allocation
void DynamicVariablesAllocationAndDeleteInRuntime()
{
	int* ptrX;

	ptrX = new int;
	*ptrX = 10;

	cout << *ptrX << endl;
	delete ptrX;
}
#pragma endregion


int main()
{
	DynamicVariablesAllocationAndDeleteInRuntime();
}
