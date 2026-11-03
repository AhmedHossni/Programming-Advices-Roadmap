#include <iostream>
#include <String>
using namespace std;

#pragma region Lesson 43 (Memory Management : new and delete)
void DynamicVariablesByPointers()
{
    // declare an int pointer
    int* ptrX;
    // declare a float pointer
    float* ptrY;
    // dynamically allocate memory
    ptrX = new int;
    ptrY = new float;
    // assigning value to the memory
    *ptrX = 45;
    *ptrY = 58.35f;
    cout << *ptrX << endl;
    cout << *ptrY << endl;
    // deallocate the memory
    delete ptrX;
    delete ptrY;
}
#pragma endregion

#pragma region Lesson 44 (Dynamic Arrays: new and delete)
void DynamicArrayByPointers()
{
    int num;
    cout << "Enter total number of students: ";
    cin >> num;
    float* ptr;

    // memory allocation of num number of floats
    ptr = new float[num];
    cout << "Enter grades of students." << endl;
    for (int i = 0; i < num; i++) {
        cout << "Student" << i + 1 << ": ";
        cin >> *(ptr + i);
    }

    cout << "\nDisplaying grades of students." << endl;
    for (int i = 0; i < num; i++) {
        cout << "Student" << i + 1 << ": " << *(ptr + i) << endl;
    }
    // ptr memory is released
    delete[] ptr;
}
#pragma endregion

int main()
{
    //DynamicVariablesByPointers();

    DynamicArrayByPointers();
}
