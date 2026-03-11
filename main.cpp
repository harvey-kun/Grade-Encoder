#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

void header(string txt);
int choices(string txt1, string txt2);
int firstscreen(string txt);


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
        //Array
        int grades[stu_max][quiz_max] = {0};
        cout << "Total number of Student: " << stu_max;
        cout << "Quiz Score Minimum: " << quiz_max;
        
        cout << "Is this correct?(1 for Yes | 2 for no): ";
            cin >> option;
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


