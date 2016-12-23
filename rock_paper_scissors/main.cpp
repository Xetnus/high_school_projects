#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <windows.h>

using namespace std;

void usersChoice(int userScore, int compScore, int ties);
void computersChoice(int intChoice, string userChoice, int userScore, int compScore, int ties);
void winner(int intChoice, string userChoice, int randNum, string compChoice, int userScore, int compScore, int ties);

int main()
{
    int userScore = 0, compScore = 0, ties = 0;

    usersChoice(userScore, compScore, ties);

    return 0;
}

void usersChoice(int userScore, int compScore, int ties){
    string userChoice;
    string choice;
    int intChoice;

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Has the user enter a number signifying their choice
    cout << endl;
    cout << "Choose either Rock(R), Paper(P), or Scissors(S) - " << endl << "and the computer will randomly choose one as well." << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    choice = toupper(choice[0]);

    while(choice != "R" && choice != "P" && choice != "S"){	// If the user did enter a correct number, allow the user to enter another
        cout << endl;
        SetConsoleTextAttribute(hConsole, 12);
        cout << "You have entered an incorrect number." << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << endl;
        cout << "Choose either Rock(R), Paper(P), or Scissors(S) - " << endl << "and the computer will randomly choose one as well." << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        choice = toupper(choice[0]);
    }

    // Puts either rock, paper, or scissors to the number the user entered
    if (choice == "R")
    {
        userChoice = "Rock";
        intChoice = 1;	// Allows the number that the computer generates be compared to what the user entered
    }
    else if (choice == "P")
    {
        userChoice = "Paper";
        intChoice = 2;	// Allows the number that the computer generates be compared to what the user entered
    }
    else if (choice == "S")
    {
        userChoice = "Scissors";
        intChoice = 3;	// Allows the number that the computer generates be compared to what the user entered
    }

    computersChoice(intChoice, userChoice, userScore, compScore, ties);
}

// Finds a random number between 1 and 3 to randomly get a number for rock, paper, or scissors
void computersChoice(int intChoice, string userChoice, int userScore, int compScore, int ties){
    int randNum, seedRandNum;
    string compChoice;

    // Makes a random number each time for the seed
    seedRandNum = rand() % (60845 - 1096 + 1) + 1096;
    // Finds a random number from 1 to 3
    //time_t seconds;	// Uses the time for a random number
    //time(&seconds);	// Accesses the seconds element to create a random number
    srand(seedRandNum);	// Creates a random number with the random seed
    //srand((unsigned int) seconds);
    randNum = rand() % (3 - 1 + 1) + 1;

    switch(randNum){	// Puts rock, paper, or scissors to the random number
        case 1:
            compChoice = "Rock";
            break;
        case 2:
            compChoice = "Paper";
            break;
        case 3:
            compChoice = "Scissors";
            break;
    }

    winner(intChoice, userChoice, randNum, compChoice, userScore, compScore, ties);

}

void winner(int intChoice, string userChoice, int randNum, string compChoice, int userScore, int compScore, int ties){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << endl;

    if(intChoice == randNum){	// If it was a tie...
        SetConsoleTextAttribute(hConsole, 3);
        ties++;
        cout << "Both you and the computer chose " << userChoice << "." << endl;
        cout << "This means that it was a tie, so no points were rewarded." << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }

    if(intChoice == 1 && randNum == 3){	// If user: Rock and computer: Scissors
        SetConsoleTextAttribute(hConsole, 2);
        userScore++;
        cout << "You chose " << userChoice << " and the computer chose " << compChoice << "." << endl;
        cout << "Rock smashes scissors." << endl;
        cout << "You win!" << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }

    if(intChoice == 2 && randNum == 1){	// If user: Paper and computer: Rock
        SetConsoleTextAttribute(hConsole, 2);
        userScore++;
        cout << "You chose " << userChoice << " and the computer chose " << compChoice << "." << endl;
        cout << "Paper covers rock." << endl;
        cout << "You win!" << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }

    if(intChoice == 3 && randNum == 2){	// If user: Scissors and computer: Paper
        SetConsoleTextAttribute(hConsole, 2);
        userScore++;
        cout << "You chose " << userChoice << " and the computer chose " << compChoice << "." << endl;
        cout << "Scissors cut paper." << endl;
        cout << "You win!" << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }

    if(randNum == 1 && intChoice == 3){	// If computer: Rock and user: Scissors
        SetConsoleTextAttribute(hConsole, 12);
        compScore++;
        cout << "The computer chose " << compChoice << " and you chose " << userChoice << "." << endl;
                cout << "Rock smashes scissors." << endl;
        cout << "You lose." << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }

    if(randNum == 2 && intChoice == 1){	// If computer: Paper and user: Rock
        SetConsoleTextAttribute(hConsole, 12);
        compScore++;
        cout << "The computer chose " << compChoice << " and you chose " << userChoice << "." << endl;
        cout << "Paper covers rock." << endl;
        cout << "You lose." << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }

    if(randNum == 3 && intChoice == 2){	// If computer: Scissors and user: Paper
        SetConsoleTextAttribute(hConsole, 12);
        compScore++;
        cout << "The computer chose " << compChoice << " and you chose " << userChoice << "." << endl;
        cout << "Scissors cut paper." << endl;
        cout << "You lose." << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }

    // Prints the current score
    cout << endl;
    cout << "The current score is: " << endl;
    cout << "You: " << userScore << endl;
    cout << "Computer: " << compScore << endl;
    cout << "Ties: " << ties << endl;

    usersChoice(userScore, compScore, ties);
}
