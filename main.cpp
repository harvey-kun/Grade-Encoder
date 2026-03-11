#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

// Function declarations
void header(string txt);
int choices(string txt1, string txt2);
int firstscreen(string txt);
void inputStudentData(int grades[][100], string names[], int stu_max, int quiz_max);
void displayGrades(int grades[][100], string names[], int stu_max, int quiz_max);
void insertionSort(string names[], int grades[][100], int stu_max);
int findHighestScore(int grades[][100], int stu_max);
int findHighestScoreIndex(int grades[][100], int stu_max);

int main(){
    int option = 0, stu_max = 0, quiz_max = 0;

    header("GRADE ENCODING");
    option = choices("Start Recording", "Exit");

    if(option == 1){
        option = 0;
        system("clear");
        header("GETTING INFO");
        stu_max = firstscreen("How many Students should be recorded? :");
        quiz_max = firstscreen("What's the total score of the activity? :");

        // 2D Array Declaration - Fixed second dimension of 100
        int grades[stu_max][100];
        string names[stu_max];

        cout << "Total number of Student: " << stu_max << endl;
        cout << "Quiz Total Score: " << quiz_max << endl;

        cout << "Is this correct?(1 for Yes | 2 for no): ";
        cin >> option;

        if(option == 1){
            inputStudentData(grades, names, stu_max, quiz_max);
            displayGrades(grades, names, stu_max, quiz_max);
        }else{
            system("clear");
            header("GRADE ENCODING");
            option = choices("Start Recording", "Exit");
        }
    }else{
        return 0;
    }

    return 0;
}

void header(string txt){
    cout << "======================================================" << endl;
    cout << "=" << setw(26 + txt.length()/2) << txt << setw(27 - txt.length()/2) << "=" << endl;
    cout << "======================================================" << endl;
}

int choices(string txt1, string txt2){
    int picked;

    do {
        cout << endl << endl;
        cout << setw(20) << "[1] " << txt1 << endl;
        cout << setw(20) << "[2] " << txt2 << endl;
        cout << endl << endl << endl;
        cout << "Enter your choice: ";
        cin >> picked;

        if (picked != 1 && picked != 2) {
            system("clear");
            header("GRADE ENCODING");
        }

    } while (picked != 1 && picked != 2);

    return picked;
}

int firstscreen(string txt){
    int maxcount = 0;

    cout << setw(5) << txt;
    cin >> maxcount;

    return maxcount;
}

void inputStudentData(int grades[][100], string names[], int stu_max, int quiz_max){
    for(int i = 0; i < stu_max; i++){
        system("clear");
        header("STUDENT " + to_string(i + 1));

        cout << "Family Name: ";
        cin >> names[i];

        cout << "First Name: ";
        string firstName;
        cin >> firstName;
        names[i] += " " + firstName;

        cin.ignore();

        cout << "Middle Initial (optional, press Enter to skip): ";
        string initial;
        getline(cin, initial);
        if(initial != ""){
            names[i] += " " + initial;
        }

        cout << "Quiz Score: ";
        cin >> grades[i][0];

        cout << endl << endl;
        cout << setw(20) << "[1] " << "Continue to Next Student" << endl;
        cout << setw(20) << "[2] " << "Re-input Current Student" << endl;
        cout << setw(20) << "[3] " << "Exit the program" << endl;
        cout << endl << endl << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 3){
            exit(0);
        }
        else if(choice == 2){
            i--;
        }
    }
}

// Function to find highest score using sequential search
int findHighestScore(int grades[][100], int stu_max){
    int highest = grades[0][0];
    for(int i = 1; i < stu_max; i++){
        if(grades[i][0] > highest){
            highest = grades[i][0];
        }
    }
    return highest;
}

// Function to find index of highest score
int findHighestScoreIndex(int grades[][100], int stu_max){
    int highestIndex = 0;
    for(int i = 1; i < stu_max; i++){
        if(grades[i][0] > grades[highestIndex][0]){
            highestIndex = i;
        }
    }
    return highestIndex;
}

//Function to sort by family name using insertion sort
void insertionSort(string names[], int grades[][100], int stu_max){
    for(int i = 1; i < stu_max; i++){
        string keyName = names[i];
        int keyScore = grades[i][0];
        int j = i - 1;

        //Extract first letter of family name for comparison
        //Get first character
        char keyFamily = keyName[0];

        while(j >= 0){
            string currentName = names[j];
            //Get first character
            char currentFamily = currentName[0];

            if(currentFamily > keyFamily){
                names[j + 1] = names[j];
                grades[j + 1][0] = grades[j][0];
                j = j - 1;
            }
            else{
                break;
            }
        }
        names[j + 1] = keyName;
        grades[j + 1][0] = keyScore;
    }
}

// Function to dsply grde w sort and remarks
void displayGrades(int grades[][100], string names[], int stu_max, int quiz_max){
    system("clear");
    header("GRADE SUMMARY");

    // Find highest score BEFORE sorting
    int highestScore = findHighestScore(grades, stu_max);
    int highestIndex = findHighestScoreIndex(grades, stu_max);
    string highestName = names[highestIndex];

    // Calculate passing grade (50% of quiz total)
    int passingGrade = quiz_max / 2;

    // Sort by family name
    insertionSort(names, grades, stu_max);

    // Display highest score
    cout << endl << "Student with the Highest Score: " << highestName << endl;
    cout << "Highest Score: " << highestScore << endl;
    cout << "Passing Grade: " << passingGrade << endl << endl;

    // Display table header
    cout << left << setw(30) << "Student name"
         << setw(25) << "Score"
         << setw(15) << "Remarks" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    // Display each student
    for(int i = 0; i < stu_max; i++){
        string remarks;
        if(grades[i][0] >= passingGrade){
            remarks = "Pass";
        }
        else{
            remarks = "Fail";
        }
        cout << left << setw(30) << names[i] << setw(25) << grades[i][0] << setw(15) << remarks << endl;
    }
}
