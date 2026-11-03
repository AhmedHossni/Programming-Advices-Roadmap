#include <iostream>
#include <string>
using namespace std;

int RandomNumber(int From, int To)
{
    // Generate a random number between 0 and (To - From) using rand(),
    // then add From to shift the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}
enum enRockPaperScissors {Rock = 1, Paper, Scissors,None};
enum enTheWinner {User = 1, Computer, Tie};

enRockPaperScissors RandomRockPaperScissors()
{
    int RandomNumber1to3 = RandomNumber(1, 3);
    return (enRockPaperScissors)RandomNumber1to3;
}

enRockPaperScissors ConvertUserInput(char userInput)
{
    switch (userInput)
    {
        case 'r':
        case 'R':
            return enRockPaperScissors::Rock;
        case 'p':
        case 'P':
            return enRockPaperScissors::Paper;
        case 's':
        case 'S':
            return enRockPaperScissors::Scissors;
        default:
            return enRockPaperScissors::None;
    }
}

enRockPaperScissors ReadUserGameValue()
{
    char UserChoose = 0;
    enRockPaperScissors GameChoose = enRockPaperScissors::None;

    while (true)
    {
        cout << "Please enter your choose:[r]Rock, [p]Paper, [s]Scissors" << endl;
        cin >> UserChoose;
        GameChoose = ConvertUserInput(UserChoose);
        if (GameChoose == enRockPaperScissors::None)
        {
            cout << "Invalid Value!!!" << endl;
            continue;
        }
        return GameChoose;
    }
}

enTheWinner HowIsTheWinner(enRockPaperScissors userChoose, enRockPaperScissors computerChoose)
{
    if (userChoose == computerChoose)
        return enTheWinner::Tie;

    if ((userChoose == enRockPaperScissors::Paper && computerChoose == enRockPaperScissors::Rock)
        || (userChoose == enRockPaperScissors::Rock && computerChoose == enRockPaperScissors::Scissors)
        || (userChoose == enRockPaperScissors::Scissors && computerChoose == enRockPaperScissors::Paper))
        return enTheWinner::User;

    return enTheWinner::Computer;
}
string ChoiceToString(enRockPaperScissors choose)
{
    switch (choose)
    {
    case enRockPaperScissors::Rock:     return "Rock";
    case enRockPaperScissors::Paper:    return "Paper";
    case enRockPaperScissors::Scissors: return "Scissors";
    default:                            return "None";
    }
}
void FullGame()
{
    enRockPaperScissors UserChoose = ReadUserGameValue();
    enRockPaperScissors ComputerRandomChoose = RandomRockPaperScissors();

    enTheWinner Winner = HowIsTheWinner(UserChoose, ComputerRandomChoose);

    cout << endl << "Your choose : " << ChoiceToString(UserChoose)
        << "\nComputer choose : " << ChoiceToString(ComputerRandomChoose)
        << endl;

    if (Winner == enTheWinner::User)
    {
        std::
        cout << "You win !!!";
    }
    else if (Winner == enTheWinner::Computer)
        cout << "You lost !!!";
    else
        cout << "It's a tie !!!";
}

int main()
{
    srand(time(NULL));

    FullGame();
}
