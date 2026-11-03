
#include <iostream>
#include <string>
using namespace std;

#pragma region Problem 6
struct Person
{
    string FirstName;
    string LastName;
};

void ReadPersonInfo(Person& person)
{
    cout << "Please enter your first name : " << endl;
    getline(cin, person.FirstName);
    cout << "Please enter your last name : " << endl;
    getline(cin, person.LastName);
}

string GetPersonFullName(Person person)
{
    return person.FirstName + " " + person.LastName;
}

void PrintPersonFullName(Person person)
{
    cout << "*****************************" << endl;
    cout << "full name : " << GetPersonFullName(person) << endl;
    cout << "*****************************" << endl;
}
#pragma endregion

#pragma region Problem 7


int ReadNumber()
{
    int number;
    cout << "Please enter your number : " << endl;
    cin >> number;

    return number;
}

float GetHalfNumber(int number)
{
    return number * 0.5f;
}

void PrintNumber(float number)
{
    cout << "half number is : " << number << endl;

}
#pragma endregion

#pragma region Problem 8
// Enum: enPassFail
// Purpose: Defines two possible outcomes for the mark evaluation: Pass (1) and Fail (2).
enum enPassFail { Pass = 1, Fail = 2 };

// Function: ReadMark
// Purpose: Prompts the user to enter their exam mark and reads it from input.
// Returns: The entered integer mark.
int ReadMark()
{
    int Mark;  // Variable to store the user's input.

    // Prompt the user to enter their mark.
    cout << "Please enter your mark? " << endl;

    cin >> Mark;  // Read the mark entered by the user.

    return Mark;  // Return the entered mark.
}

// Function: CheckMark
// Purpose: Determines whether a given mark is a passing or failing grade.
// Parameter: Mark - the integer mark to be checked.
// Returns: enPassFail::Pass if the mark is 50 or greater, otherwise enPassFail::Fail.
enPassFail CheckMark(int Mark)
{
    // If the mark is 50 or above, return Pass; otherwise, return Fail.
    if (Mark >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

// Function: PrintResults
// Purpose: Displays whether the student has passed or failed based on the entered mark.
// Parameter: Mark - the integer mark provided by the user.
void PrintResults(int Mark)
{
    // Check if the mark qualifies as a passing grade.
    if (CheckMark(Mark) == enPassFail::Pass)
        cout << "\n You Passed" << endl;
    else
        cout << "\n You Failed" << endl;
}
#pragma endregion

#pragma region Problem 9
// Function: ReadNumbers
// Purpose: Prompts the user to enter three integer numbers and stores them using reference variables.
// Parameters: 
//   - Num1: Reference to the first integer variable.
//   - Num2: Reference to the second integer variable.
//   - Num3: Reference to the third integer variable.
// Returns: None (values are stored in reference variables).
void ReadNumbers(int& Num1, int& Num2, int& Num3)
{
    // Prompt the user to enter the first number and store it in Num1.
    cout << "Please enter your Number 1 ? " << endl;
    cin >> Num1;

    // Prompt the user to enter the second number and store it in Num2.
    cout << "Please enter your Number 2 ? " << endl;
    cin >> Num2;

    // Prompt the user to enter the third number and store it in Num3.
    cout << "Please enter your Number 3 ? " << endl;
    cin >> Num3;
}

// Function: SumOf3Numbers
// Purpose: Calculates the sum of three integer numbers.
// Parameters: 
//   - Num1: First integer value.
//   - Num2: Second integer value.
//   - Num3: Third integer value.
// Returns: The sum of the three numbers as an integer.
int SumOf3Numbers(int Num1, int Num2, int Num3)
{
    return Num1 + Num2 + Num3;  // Compute and return the sum.
}

// Function: PrintResults
// Purpose: Displays the sum of the three numbers.
// Parameter: Total - the total sum of the numbers.
// Returns: None (prints the result).
void PrintResults(int Total)
{
    // Print the calculated sum of the numbers.
    cout << "\n The total sum of numbers is: " << Total << endl;
}

// Main function: Program entry point.
int main()
{
    int Num1, Num2, Num3;  // Declare three integer variables to store user input.

    // Read three numbers from the user.
    ReadNumbers(Num1, Num2, Num3);

    // Compute the sum and display the result.
    PrintResults(SumOf3Numbers(Num1, Num2, Num3));

    return 0;  // Return 0 to indicate successful execution.
}
#pragma endregion

#pragma region Problem 10
// Function: ReadNumbers
// Purpose: Prompts the user to enter three exam marks and stores them using reference variables.
// Parameters: 
//   - Mark1: Reference to the first mark.
//   - Mark2: Reference to the second mark.
//   - Mark3: Reference to the third mark.
// Returns: None (values are stored in reference variables).
void ReadNumbers(int& Mark1, int& Mark2, int& Mark3)
{
    // Prompt the user to enter the first mark and store it in Mark1.
    cout << "Please enter Mark 1 ? " << endl;
    cin >> Mark1;

    // Prompt the user to enter the second mark and store it in Mark2.
    cout << "Please enter Mark 2 ? " << endl;
    cin >> Mark2;

    // Prompt the user to enter the third mark and store it in Mark3.
    cout << "Please enter Mark 3 ? " << endl;
    cin >> Mark3;
}

// Function: SumOf3Marks
// Purpose: Calculates the total sum of three marks.
// Parameters: 
//   - Mark1: First exam mark.
//   - Mark2: Second exam mark.
//   - Mark3: Third exam mark.
// Returns: The sum of the three marks as an integer.
int SumOf3Marks(int Mark1, int Mark2, int Mark3)
{
    return Mark1 + Mark2 + Mark3;  // Compute and return the sum.
}

// Function: CalculateAverage
// Purpose: Computes the average of three marks.
// Parameters: 
//   - Mark1: First exam mark.
//   - Mark2: Second exam mark.
//   - Mark3: Third exam mark.
// Returns: A float value representing the average of the marks.
float CalculateAverage(int Mark1, int Mark2, int Mark3)
{
    // Compute the total sum using SumOf3Marks() and divide by 3 to get the average.
    return (float)SumOf3Marks(Mark1, Mark2, Mark3) / 3;
}

// Function: PrintResults
// Purpose: Displays the calculated average of the marks.
// Parameter: Average - the computed average of the three marks.
// Returns: None (prints the result).
void PrintResults(float Average)
{
    // Print the calculated average of the marks.
    cout << "\n The average is : " << Average << endl;
}

#pragma endregion


int main()
{
    // Problem 6
    //Person Person;
    //ReadPersonInfo(Person);
    //PrintPersonFullName(Person);


    // Problem 7
    PrintNumber(GetHalfNumber(ReadNumber()));
}

