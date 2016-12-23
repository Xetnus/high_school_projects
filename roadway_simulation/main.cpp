#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

bool activeLeftCar = false;
bool activeRightCar = false;
bool activeCarCrash = false;
int lengthOfLeftCar = 1;
int lengthOfRightCar = 1;
int leftCarColor = 0;
int rightCarColor = 0;
int randRightInt;
int randLeftInt;

HANDLE  hConsole;

void leftLane();
void rightLane();
void coutLeftCar();
void coutRightCar();
void changeCarColor(int carColor);
void carCrash();

int main()
{
    srand(time(0)); // Used to generate a random number using the current time
    int countMiddleLane = 0;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int randomCarCrash;

    while(true){    // Infinitely loops

        countMiddleLane++;  // Variable is used for the middle lane

        // Colors the very left line on the road yellow, like it would appear on a real road
        SetConsoleTextAttribute(hConsole, 6);
        cout << "|";
        SetConsoleTextAttribute(hConsole, 7);

        if (lengthOfLeftCar != 4){
            leftLane(); // Decides whether or not it should display a car in the left lane
        } else {
            randomCarCrash = rand() % (50 - 1 + 1) + 1;   // Random number for a random car crash (1 in 50 cars will crash)

            if (randomCarCrash == 1) {
                carCrash();
                lengthOfLeftCar = 1;
            } else
                leftLane();
        }

        // Displays a middle line every other time
        if (countMiddleLane % 2 == 0)
        {
            cout << "|";
        }
        else
        {
            cout << " ";
        }

        rightLane(); // Call rightLane, this decides whether or not it should display a car in the right lane

        cout << "|" << endl;    // Displays the far right line

        Sleep(30);  // Sleeps for 35 millisecs, in order for the program to not go by too fast
    }
    return 0;
}

// This function decides what happens with the left lane
void leftLane()
{
    randLeftInt = rand() % (12 - 1 + 1) + 1;    // Makes a random number to decide whether or not to display a car

    // If the random number is 1, or if the program needs to finish displaying the rest of a car and the current car isn't too long...
    if ((randLeftInt == 1 || activeLeftCar == true) && lengthOfLeftCar < 5)
    {
        activeLeftCar = true;   // Tells the program that there is currently an active car in the left lane
        coutLeftCar();  // Calls coutLeftCar, to print out the car
    }
    else
    {
        activeLeftCar = false;  // Tells the program that there is currently no car that needs to be printed to the screen
        lengthOfLeftCar = 0;    // Resets the variable, waiting for the next car to come around
        cout << "        ";
    }
}

// This function decides what happens with the right lane
void rightLane()
{
    randRightInt = rand() % (10 - 1 + 1) + 1;   // Makes a random number to decide whether or not to display a car

    // If the random number is 1, or if the program needs to finish displaying the rest of a car and the current car isn't too long...
    if ((randRightInt == 1 || activeRightCar == true) && lengthOfRightCar < 5)
    {
        activeRightCar = true;  // Tells the program that there is currently an active car in the left lane
        coutRightCar();     // Calls coutLeftCar, to print out the car
    }
    else
    {
        activeRightCar = false; // Tells the program that there is currently no car that needs to be printed to the screen
        lengthOfRightCar = 0;   // Resets the variable, waiting for the next car to come around
        cout << "        ";
    }
}

// This function prints out a car in the left lane
void coutLeftCar()
{
    // Prints out the car
    switch(lengthOfLeftCar)
    {
        case 1:
            leftCarColor = rand() % (8 - 1 + 1) + 1;    // Generates a random color
            changeCarColor(leftCarColor);   // Passes the random color to changeCarColor
            cout << "   MM   "; // Prints out the front of the vehicle
            break;
        case 2:
            changeCarColor(leftCarColor);   // Passes the random color to changeCarColor
            cout << "  O||O  "; // Prints out the middle-upper part of the vehicle
            break;
        case 3:
            changeCarColor(leftCarColor);   // Passes the random color to changeCarColor
            cout << "   ||   "; // Prints out the middle-lower part of the vehicle
            break;
        case 4:
            changeCarColor(leftCarColor);   // Passes the random color to changeCarColor
            cout << "  OUUO  "; // Prints out the end of the vehicle
            break;
        default:
            cout << "        ";
    }
    SetConsoleTextAttribute(hConsole, 7);   // Sets the text color back to normal
    lengthOfLeftCar++;
}

// Same as previous function
void coutRightCar()
{

    switch(lengthOfRightCar)
    {
        case 1:
            rightCarColor = rand() % (8 - 1 + 1) + 1;
            changeCarColor(rightCarColor);
            cout << "   MM   ";
            break;
        case 2:
            changeCarColor(rightCarColor);
            cout << "  O||O  ";
            break;
        case 3:
            changeCarColor(rightCarColor);
            cout << "   ||   ";
            break;
        case 4:
            changeCarColor(rightCarColor);
            cout << "  OUUO  ";
            break;
        default:
            cout << "        ";
    }
    SetConsoleTextAttribute(hConsole, 7);
    lengthOfRightCar++;
}

// This function just changes to color of each car
void changeCarColor(int carColor)
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    switch(carColor)
    {
        case 1:
            SetConsoleTextAttribute(hConsole, 6);
            break;
        case 2:
            SetConsoleTextAttribute(hConsole, 2);
            break;
        case 3:
            SetConsoleTextAttribute(hConsole, 3);
            break;
        case 4:
            SetConsoleTextAttribute(hConsole, 11);
            break;
        case 5:
            SetConsoleTextAttribute(hConsole, 8);
            break;
        case 6:
            SetConsoleTextAttribute(hConsole, 13);
            break;
        case 7:
            SetConsoleTextAttribute(hConsole, 14);
            break;
        case 8:
            SetConsoleTextAttribute(hConsole, 12);
            break;
        default:
            SetConsoleTextAttribute(hConsole, 7);
    }
}

void carCrash()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
    cout << "   XX   ";
    SetConsoleTextAttribute(hConsole, 7);
}
