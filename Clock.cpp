

// Name: Jason McDaniel
// Date: 5-21-2024

#include <iostream>
#include <iomanip>

using namespace std;

int hr = 12; //hours for the clock
int minute = 0; //minutes for the clock
int sec = 0; //seconds for the clock
bool running = true;
int menuInput; //variable for menu input

void addHour(){
    hr = (hr + 1) % 24;
}

void addMinute(){
    if(++minute==60){
        minute = 0;
        addHour();
    }
}

void addSecond() {
    if(++sec==60){
        sec = 0;
        addMinute();
    }
}
void printClock(){
    int hr12 = (hr % 12);
    if(hr12 == 0) hr12 = 12;
    cout<< "***************************  ***************************" << endl;
    cout<< "*       12-Hour Clock     *  *        24-Hour Clock    *" << endl;
    cout<< "*       " << setw(2) << setfill('0') << hr12 << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << sec << " ";
    cout << (hr >= 12 ? "PM" : "AM");
    cout<< "       *  *        "<< setw(2) << setfill('0') << hr << ":"<< setw(2) << setfill('0') << minute << ":"<< setw(2) << setfill('0') << sec << "         *" << endl;
    cout<< "***************************  ***************************" << endl;
}
//displays menu
void displayMenu() {

    cout << "***************************\n";
    cout << "* 1 - Add One Hour        *\n";
    cout << "* 2 - Add One Minute      *\n";
    cout << "* 3 - Add One Second      *\n";
    cout << "* 4 - Exit Program        *\n";
    cout << "***************************\n";
}

void menu(){
    switch (menuInput){
        case 1:
            addHour();
            break;
        case 2:
            addMinute();
            break;
        case 3:
            addSecond();
            break;
        case 4:
            cout << "Exit Clock Program" << endl;
            running = false;

            break;
        default:
            cout << "Invalid Input Entered. Please Enter A Valid Input." << endl;
    }

}

int main() {

    while(running) {


        printClock();
        displayMenu();
        cin >> menuInput;
        menu();
    }

}
