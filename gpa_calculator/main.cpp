#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

void WelcomeScreen();
void CalculateGPAFromProfile();
void CreateNewProfile();
void CalculateGPAFromScratch();
double CalculateCVxGPV(int classLevel, int classGrade, double classCredits);

int main()
{
    WelcomeScreen();

    return 0;
}

void WelcomeScreen()
{
    bool flag = false;
    int choice;

    // Checks whether or not the user has already set up a profile
    ifstream dataFile ("GPACalculatorData.txt");
    if (dataFile.is_open()) flag = true;

    cout << "Welcome to the SVSD GPA calculator programmed by Grant!" << endl;
    cout << endl;
    cout << "What would you like to do?" << endl;

    //Inputs what the user would like to do
    cout << "1 - Use previous profile to calculate GPA";
    if (flag == false) cout << "(not preferred - you have not set up a profile yet)" << endl;
    else cout << endl;

    cout << "2 - Create a new profile";
    if (flag == false) cout << "(recommended - you're a new user!)" << endl;
    else cout << endl;

    cout << "3 - Calculate your GPA from scratch(recommended for anyone, at anytime!)" << endl;
    cout << "Choice: ";
    cin >> choice;
    cout << endl;

    // Calls the appropriate method for the user's choice
    switch(choice)
    {
        case 1:
        CalculateGPAFromProfile();
        break;

        case 2:
        CreateNewProfile();
        break;

        case 3:
        CalculateGPAFromScratch();
        break;

        default:
        system("cls");
        cout << "You have entered an incorrect number. Try again." << endl;
        WelcomeScreen();
    }

    dataFile.close();
}

// Calculates the GPA from a previously created profile
void CalculateGPAFromProfile()
{
    string className, input = "", returnToWelcome;
    double classCredits, CVxGPV = 0, GPA, totalCreditValue = 0;
    int classLevel, classGrade;

    system("cls"); // Clears the screen

    // Opens the data file
    ifstream dataFile;
    dataFile.open("GPACalculatorData.txt");

    // If the data file is open, continue
    if (dataFile.is_open())
    {
        dataFile >> input;

        // Continues to loop until there are no more classes to input
        while (!dataFile.eof()) {

            getline(dataFile, className); // Inputs the class name
            cout << "Class Name:" << className << endl;

            dataFile >> input;
            dataFile >> classCredits; // Inputs the class credits
            cout << "Class Credits: " << classCredits << endl;

            totalCreditValue += classCredits; // Keeps track of the total credit value

            dataFile >> input;
            dataFile >> classLevel; // Inputs the class level
            cout << "Class Level: " << classLevel << endl;

            // Has the user enter the class grade
            cout << "Enter the Class Grade (Percent): ";
            cin >> classGrade;
            cout << endl;

            // Calculates the credit value multiplied by the grade point value
            CVxGPV += CalculateCVxGPV(classLevel, classGrade, classCredits);

            dataFile >> input;
        }
    }

    dataFile.close(); // Closes the data file
    GPA = CVxGPV / totalCreditValue; // Calculates GPA

    // Outputs the GPA
    cout << "Your GPA is: " << GPA << endl;
    cout << "You're Welcome! ~Grant" << endl;
    cout << endl;

    // Returns the user back to the welcome screen if they want to continue
    cout << "Would you like to return back to the welcome screen? (y/n): ";
    cin >> returnToWelcome;

    if (returnToWelcome == "y" || returnToWelcome == "Y")
    {
        system("cls");
        WelcomeScreen();
    }
}

// Creates a new profile that can be used later
void CreateNewProfile()
{
    std::string returnToWelcome, className;
    double classCredits;
    int classLevel;
    bool done = false;
    ofstream dataFile;

    system("cls"); // Clears the screen

    cout << "Time to create your new profile!" << endl;

    dataFile.open("GPACalculatorData.txt"); // This is the text file that the data is stored in

    cout << "Now it's time to enter the data for your profile." << endl;
    cout << "Enter all of the data asked." << endl;
    cout << "When you are finished, enter 'done' in the class name, or 0 in the class credits field." << endl;
    cout << endl;
    cout << "Note: Level 0 classes are all classes that aren't listed below." << endl;
    cout << "Note: Level 1 classes consist of: Accounting III, Advanced CAD, Anatomy & Physiology, C++, Calculus, Chemistry II, Environmental Science, German 3, German 4, Physics Honors, Pre-Calculus/Trigonometry, Spanish 3, Spanish 4." << endl;
    cout << "Note: Level 2 classes are all AP classes." << endl;
    cout << endl;

    // Inputs the user's classes and data and saves them to a text file
    while (done == false)
    {
        string temp;
        std::getline(cin, temp);

        cout << "Class Name: ";
        //cin >> className;
        std::getline(cin, className);

        cout << className << " - Class Credits: ";
        cin >> classCredits;

        cout << className << " - Class Level (0, 1, or 2): ";
        cin >> classLevel;
        cout << endl;

        // Saves the user's classes and data to a text file if they aren't done
        if (classCredits == 0 || className == "done") done = true;
        else
        {
            dataFile << "Name: " << className << endl; // Outputs to the text file the class name
            dataFile << "Credits: " << classCredits << endl; // Outputs to the text file the class credits
            dataFile << "Level: " << classLevel << endl; // Outputs to the text file the class level
        }
    }

    dataFile.close();

    cout << "Thanks! Your classes have been saved." << endl;

    // Returns the user back to the welcome screen if they want to continue
    cout << "Would you like to return back to the welcome screen? (y/n): ";
    cin >> returnToWelcome;

    if (returnToWelcome == "y" || returnToWelcome == "Y")
    {
        system("cls");
        WelcomeScreen();
    }
}

// Calculates the user's GPA from scratch
void CalculateGPAFromScratch()
{
    bool done = false;
    int classNum = 1;
    int classLevel, classGrade;
    double classCredits, totalCreditValue = 0, CVxGPV = 0;
    double GPA;
    string returnToWelcome;

    system("cls"); // Clears the screen

    // Gives the user instructions on what to do
    cout << "Enter the appropriate information in order to find your GPA." << endl;
    cout << "When you are done, enter 0 for the class credits." << endl;
    cout << endl;
    cout << "Note: Level 0 classes are all classes that aren't listed below." << endl;
    cout << "Note: Level 1 classes consist of: Accounting III, Advanced CAD, Anatomy & Physiology, C++, Calculus, Chemistry II, Environmental Science, German 3, German 4, Physics Honors, Pre-Calculus/Trigonometry, Spanish 3, Spanish 4." << endl;
    cout << "Note: Level 2 classes are all AP classes." << endl;
    cout << endl;

    // Inputs the user's data until the user is done
    while (done == false)
    {
        // Inputs class grade
        cout << "Class " << classNum << " Grade (Percent): ";
        cin >> classGrade;

        // Inputs class credits
        cout << "Class " << classNum << " Credits: ";
        cin >> classCredits;

        totalCreditValue += classCredits; // Keeps track of the total credit value

        // Inputs the class level
        cout << "Class " << classNum << " Level (0, 1, or 2): ";
        cin >> classLevel;
        cout << endl;

        // If the user is not done, then call CalculateCVxGPV
        if (classCredits == 0) done = true;
        else CVxGPV += CalculateCVxGPV(classLevel, classGrade, classCredits);

        classNum++; // Keeps track of the number of classes
    }

    GPA = CVxGPV / totalCreditValue; // Calculates GPA

    // Outputs GPA
    cout << "Your GPA is: " << GPA << endl;
    cout << "You're Welcome! ~Grant" << endl;
    cout << endl;

    // Returns the user back to the welcome screen if they want to continue
    cout << "Would you like to return back to the welcome screen? (y/n): ";
    cin >> returnToWelcome;

    if (returnToWelcome == "y" || returnToWelcome == "Y")
    {
        system("cls");
        WelcomeScreen();
    }
}

// Calculates the credit value multiplied by the grade point value
double CalculateCVxGPV(int classLevel, int classGrade, double classCredits)
{
    double GPV = 0.0;

    // Assigns GPV to the correct value according to the class grade and class level
    switch(classLevel)
    {
        case 0:
        if (classGrade <= 100 && classGrade >= 97) GPV = 4.3300;
        else if (classGrade <= 96 && classGrade >= 93) GPV = 4.0000;
        else if (classGrade <= 92 && classGrade >= 90) GPV = 3.6700;
        else if (classGrade <= 89 && classGrade >= 87) GPV = 3.3300;
        else if (classGrade <= 86 && classGrade >= 83) GPV = 3.0000;
        else if (classGrade <= 82 && classGrade >= 80) GPV = 2.6700;
        else if (classGrade <= 79 && classGrade >= 77) GPV = 2.3300;
        else if (classGrade <= 76 && classGrade >= 73) GPV = 2.0000;
        else if (classGrade <= 72 && classGrade >= 70) GPV = 1.6700;
        else if (classGrade <= 69 && classGrade >= 67) GPV = 1.3300;
        else if (classGrade <= 66 && classGrade >= 63) GPV = 1.0000;
        else if (classGrade <= 62 && classGrade >= 60) GPV = 0.6700;
        break;

        case 1:
        if (classGrade <= 100 && classGrade >= 97) GPV = 4.5465;
        else if (classGrade <= 96 && classGrade >= 93) GPV = 4.20;
        else if (classGrade <= 92 && classGrade >= 90) GPV = 3.8535;
        else if (classGrade <= 89 && classGrade >= 87) GPV = 3.4965;
        else if (classGrade <= 86 && classGrade >= 83) GPV = 3.1500;
        else if (classGrade <= 82 && classGrade >= 80) GPV = 2.8035;
        else if (classGrade <= 79 && classGrade >= 77) GPV = 2.4465;
        else if (classGrade <= 76 && classGrade >= 73) GPV = 2.1000;
        else if (classGrade <= 72 && classGrade >= 70) GPV = 1.7535;
        else if (classGrade <= 69 && classGrade >= 67) GPV = 1.3965;
        else if (classGrade <= 66 && classGrade >= 63) GPV = 1.0500;
        else if (classGrade <= 62 && classGrade >= 60) GPV = 0.7035;
        break;

        case 2:
        if (classGrade <= 100 && classGrade >= 97) GPV = 4.7630;
        else if (classGrade <= 96 && classGrade >= 93) GPV = 4.4000;
        else if (classGrade <= 92 && classGrade >= 90) GPV = 4.0370;
        else if (classGrade <= 89 && classGrade >= 87) GPV = 3.6630;
        else if (classGrade <= 86 && classGrade >= 83) GPV = 3.3000;
        else if (classGrade <= 82 && classGrade >= 80) GPV = 2.9370;
        else if (classGrade <= 79 && classGrade >= 77) GPV = 2.5630;
        else if (classGrade <= 76 && classGrade >= 73) GPV = 2.2000;
        else if (classGrade <= 72 && classGrade >= 70) GPV = 1.8370;
        else if (classGrade <= 69 && classGrade >= 67) GPV = 1.4630;
        else if (classGrade <= 66 && classGrade >= 63) GPV = 1.1000;
        else if (classGrade <= 62 && classGrade >= 60) GPV = 0.7370;
        break;
    }

    return GPV * classCredits; // Returns GPV multiplied by the class credits
}
