#include <iostream>
using namespace std;


#pragma region Pointer lesson 1 (Course Lesson 35)
void PointerSimpleTestL35()
{
    int num = 10;
    // Pointer is a variable makes you able to store another variable address
    // Pointer should be the same type of variable that he store his address (int Variable => int * Pointer)
    int* numPointer = &num;
    int** Pointer = &numPointer;

    cout << "Variable Value : " << num << endl;
    cout << "Variable Address : " << &num << endl;
    cout << "Pointer Value : " << numPointer << endl;
    cout << "Address Pointer Itself : " << &numPointer << endl;
}
#pragma endregion
#pragma region Pointer lesson 2 Dereferencing Pointer (Course Lesson 36)
void PointerSimpleTestL36()
{
    //عملية Dereferencing a pointer( فك السير / الوصول إلى القيمة) في لغة ) C++
    // تعني ببساطة
    // الذهاب إلى العنوان الذي يشير إليه المؤشر 
    // (Pointer) وجلب القيمة المخزنة في ذلك العنوان أو تعديلها

    // Referencing => int * p = &a; // store address of another variable
    // Dereferencing => *p // call another variable by pointer store his address
    int a = 10;

    cout << "a value = " << a << endl;
    cout << "a address = " << &a << endl;

    int* p;
    p = &a;

    cout << "Pointer Value = " << p << endl;
    cout << "Value of the address that p is pointing to is " << *p << endl;

    *p = 20;

    cout << a << endl;
    cout << *p << endl;

    a = 30;

    cout << a << endl;
    cout << *p << endl;

    cout << endl;
}
#pragma endregion
#pragma region Lesson 39 - Call by Reference: Using Pointers  (Course Lesson 39)
void SwapFuncByPointers(int * a , int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
#pragma endregion
#pragma region   Lesson 40 - Pointers and Arrays (Course Lesson 40)
void PointersAndArrays()
{
    int arr[4] = { 10,20,30,40 };
    int* ptr;
    ptr = arr;

    //ptr is equivalent to &arr[0];
    //ptr + 1 is equivalent to &arr[1];
    //ptr + 2 is equivalent to &arr[2];
    //ptr + 3 is equivalent to &arr[3];

    cout << "Addresses are:\n";
    cout << ptr << endl;
    cout << ptr + 1 << endl;
    cout << ptr + 2 << endl;
    cout << ptr + 3 << endl;

    cout << "\nValues are: \n";
    cout << *(ptr) << endl;
    cout << *(ptr + 1) << endl;
    cout << *(ptr + 2) << endl;
    cout << *(ptr + 3) << endl;

    cout << "\nValues with pointers for loop: \n";
    for (int i = 0; i < 4; i++)
        cout << *(ptr+i) << endl;

}
#pragma endregion
#pragma region   Lesson 41 - Pointers and Structure (Course Lesson 41)
struct stEmplyee
{
    string Name;
    float Salary;
};

void PointerAndStructure()
{
    stEmplyee Employee1, * ptr;
    Employee1.Name = "Mohammed Abu-Hadhoud";
    Employee1.Salary = 5000;
    cout << Employee1.Name << endl;
    cout << Employee1.Salary << endl;
    ptr = &Employee1;
    cout << "\nUsing Pointer:\n";
    cout << ptr->Name << endl; // == (*ptr).Name but "->" for make the code more readable and it easy to write
    cout << ptr->Salary << endl;

}
#pragma endregion
#pragma region   Lesson #42 - Pointer to Void (Course Lesson 42)
struct stEmplyee
{
    string Name;
    float Salary;
};

void PointerToVoid()
{
    void* ptr;
    float f1 = 10.5;

    int x = 50;
    ptr = &f1;

    cout << ptr << endl;
    cout << *(static_cast<float*>(ptr)) << endl;

    ptr = &x;
    cout << ptr << endl;

    cout << *(static_cast<int*>(ptr)) << endl;

}
#pragma endregion

int main()
{
    /*
        Pointers (All videos in this section):-
 
        Lesson #35 - What is Pointer? (19:56)
 
        Lesson #36 - Dereferencing Pointer (11:47)
 
        Lesson #37 - Common Mistakes with Pointers (3:25)
 
        Lesson #38 - Pointers vs References (6:37)
 
        Lesson #39 - Call by Reference: Using pointers (12:52)
 
        Lesson #40 - Pointers and Arrays (6:09)
 
        Lesson #41 - Pointers and Structure (3:32)
 
        Lesson #42 - Pointer to Void
    */


    //PointerSimpleTestL35();
    //PointerSimpleTestL36();

    //int x = 10, y = 20;
    //SwapFuncByPointers(&x , &y);

    //PointersAndArrays();

    PointerAndStructure();
}

