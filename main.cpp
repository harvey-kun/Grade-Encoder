#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void header(string txt);
int choices(string txt1, string txt2);


int main(){
    int option = 0;

    header("GRADE ENCODING");
    option = choices("Start Recording", "Exit");

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
            system("CLS");
            header("GRADE ENCODING");
        }

    } while (picked != 1 && picked != 2);

    return picked;
}
