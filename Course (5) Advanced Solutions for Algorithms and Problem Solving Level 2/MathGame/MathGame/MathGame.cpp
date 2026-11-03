#include <iostream>
using namespace std;

int RandomNumber(int From, int To)
{
    // Generate a random number between 0 and (To - From) using rand(),
    // then add From to shift the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

enum enGameDifficulty { VeryEasy=1, Easy, Medium, Hard, Max, NoAnswer};
enum enMathGameOperation { Addition = 1, Subtraction, Division, Multiplication, Mix, None};

struct stUserGameResultsInfo
{
    int NumberOfCorrectAnswers = 0;
    int NumberOfWrongAnswers = 0;
};

int ReadNumber(string message)
{
    cout << message << endl;
    int Number = 0;
    cin >> Number;

    return Number;
}
int ReadPositiveNumber(string message)
{
    int Number = 0;
    while (true)
    {
        Number = ReadNumber(message);
        if (Number <= 0)
        {
            cout << "Invalid value!!!" << endl;
            continue;
        }
        break;
    }

    return Number;
}

enGameDifficulty ConvertUserValueToGameDifficultyEnum(int userChoose)
{
    switch (userChoose)
    {
    case 1:
        return enGameDifficulty::VeryEasy;
    case 2:
        return enGameDifficulty::Easy;
    case 3:
        return enGameDifficulty::Medium;
    case 4:
        return enGameDifficulty::Hard;
    case 5:
        return enGameDifficulty::Max;
    default:
        return enGameDifficulty::NoAnswer;
    }
}
enGameDifficulty ReadGameDifficulty()
{
    int Number = 0;
    enGameDifficulty GameDifficulty = enGameDifficulty::NoAnswer;

    while (true)
    {
        Number = ReadNumber("Enter Your Game Difficulty : ([1]VeryEasy, [2]Easy, [3]Medium, [4]Hard, [5]Max) ");
        GameDifficulty = ConvertUserValueToGameDifficultyEnum(Number);
        if (GameDifficulty == enGameDifficulty::NoAnswer)
        {
            cout << "Invalid value!!!" << endl;
            continue;
        }
        return GameDifficulty;
    }
}

enMathGameOperation ConvertUserValueMathOperationEnum(int userChoose)
{
    switch (userChoose)
    {
    case 1:
        return enMathGameOperation::Addition;
    case 2:
        return enMathGameOperation::Subtraction;
    case 3:
        return enMathGameOperation::Division;
    case 4:
        return enMathGameOperation::Multiplication;
    case 5:
        return enMathGameOperation::Mix;
    default:
        return enMathGameOperation::None;
    }
}
enMathGameOperation ReadGameOperation()
{
    int Number = 0;
    enMathGameOperation GameOperation = enMathGameOperation::None;

    while (true)
    {
        Number = ReadNumber("Enter Your Game Difficulty : ([1]Addition, [2]Subtraction, [3]Division, [4]Multiplication, [5]Mix) ");
        GameOperation = ConvertUserValueMathOperationEnum(Number);
        if (GameOperation == enMathGameOperation::None)
        {
            cout << "Invalid value!!!" << endl;
            continue;
        }
        return GameOperation;
    }
}

int GenerateNumberByDifficulty(enGameDifficulty GameDifficulty)
{
    int num;
    switch (GameDifficulty)
    {
        case VeryEasy:
            num = RandomNumber(1, 3);
            break;
        case Easy:
            num = RandomNumber(4, 6);
            break;
        case Medium:
            num = RandomNumber(7, 12);
            break;
        case Hard:
            num = RandomNumber(13, 99);
            break;
        case Max:
            num = RandomNumber(101, 199);
            break;
        default:
            num = RandomNumber(4, 6);
            break;
    }
    return num;
}
enMathGameOperation RandomOperation()
{
    return (enMathGameOperation)RandomNumber(1,4);
}

char ReturnOperationAsChar(enMathGameOperation gameOperation)
{
    switch (gameOperation)
    {
    case Addition:
        return '+';
    case Subtraction:
        return '-';
    case Division:
        return '/';
    case Multiplication:
        return '*';
    default:
        return '+';
    }
}

void PrintExpression(enMathGameOperation gameOperation, int NumberOne, int NumberTwo)
{
    cout << "----------------------------" << endl;
    cout << NumberOne << endl;
    cout << ReturnOperationAsChar(gameOperation) << endl;
    cout << NumberTwo << endl;
    cout << "__________" << endl;
}

int ExpressionValue(enMathGameOperation gameOperation, int NumberOne, int NumberTwo)
{
    switch (gameOperation)
    {
        case Addition:
            return NumberOne + NumberTwo;
        case Subtraction:
            return NumberOne - NumberTwo;
        case Division:
            if (NumberTwo == 0)
            {
                cout << "You can't divide by 0 i will change 0 to 1" << endl;
                NumberTwo = 1;
            }
            return NumberOne / NumberTwo;
        case Multiplication:
            return NumberOne * NumberTwo;
    }
}

int CreateRoundExpression(enMathGameOperation gameOperation, int NumberOne, int NumberTwo)
{
    switch (gameOperation)
    {
        case enMathGameOperation::Addition:
            PrintExpression(enMathGameOperation::Addition, NumberOne, NumberTwo);
            return ExpressionValue(enMathGameOperation::Addition, NumberOne, NumberTwo);
        case enMathGameOperation::Subtraction:
            PrintExpression(enMathGameOperation::Subtraction, NumberOne, NumberTwo);
            return ExpressionValue(enMathGameOperation::Subtraction, NumberOne, NumberTwo);
        case enMathGameOperation::Division:
            PrintExpression(enMathGameOperation::Division, NumberOne, NumberTwo);
            return ExpressionValue(enMathGameOperation::Division, NumberOne, NumberTwo);
        case enMathGameOperation::Multiplication:
            PrintExpression(enMathGameOperation::Multiplication, NumberOne, NumberTwo);
            return ExpressionValue(enMathGameOperation::Multiplication, NumberOne, NumberTwo);
        case Mix:
            gameOperation = RandomOperation();
            PrintExpression(gameOperation, NumberOne, NumberTwo);
            return ExpressionValue(gameOperation, NumberOne, NumberTwo);
        default:
            PrintExpression(enMathGameOperation::Addition, NumberOne, NumberTwo);
            return ExpressionValue(enMathGameOperation::Addition, NumberOne, NumberTwo);
    }
}

bool CheckTheAnswer(int Result)
{   
    return ReadNumber("") == Result;
}

int CreateRound(enGameDifficulty GameDifficulty, enMathGameOperation MathOperation)
{
    int NumberOne = 0;
    int NumberTwo = 0;
    

    NumberOne = GenerateNumberByDifficulty(GameDifficulty);
    NumberTwo = GenerateNumberByDifficulty(GameDifficulty);
    return CreateRoundExpression(MathOperation, NumberOne, NumberTwo);
}

void PrintGameResult(stUserGameResultsInfo UserResults)
{
    cout << "\n\n*********************" << endl;
    cout << "Game End" << endl;
    cout << "*********************" << endl;
    cout << "Number of correct answers : " << UserResults.NumberOfCorrectAnswers << endl;
    cout << "Number of wrong answers : " << UserResults.NumberOfWrongAnswers << endl;
    cout << "*********************" << endl;

}

void MathGame()
{
    int GameRounds = ReadPositiveNumber("Please enter number of rounds that you want :");

    enGameDifficulty GameDifficulty = ReadGameDifficulty();
    enMathGameOperation MathOperation = ReadGameOperation();

    stUserGameResultsInfo UserResults;

    bool isAnswerCorrect = true;
    while (GameRounds > 0)
    {
        isAnswerCorrect = CheckTheAnswer(CreateRound(GameDifficulty, MathOperation));
        if (isAnswerCorrect)
            UserResults.NumberOfCorrectAnswers++;
        else
            UserResults.NumberOfWrongAnswers++;

        GameRounds--;
    }

    PrintGameResult(UserResults);
}

int main()
{
    srand(time(NULL));

    MathGame();
}
