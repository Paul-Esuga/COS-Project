#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void Start();
bool Authenticate(string user, string pass);


class Users { //class to save user credentials
    public: 
        string usern;
        string pass;
    public: 
        Users();
        Users(string user, string passw) {usern = user; pass = passw;};
        bool authenticate(string user, string passw); 
}; 

bool Users::authenticate(string user, string passw) {
    return ((user == Users::usern) && (passw == Users::pass));
};

Users userarr[6] = { //array stores the user classes
    Users("Timothy", "Tim123"),
    Users("Gregory", "BlockChainz3"),
    Users("Emmanuel", "H@rtL1v3d"),
    Users("Maji", "1234"),
    Users("Yaya", "He15"),
    Users("Moses", "Welcome2PAU")
};

bool Authenticate(string user, string pass) { //function compares user input to preset credentials
    bool x = false;
    for (int i = 0; i < 6; i++) {
        if (userarr[i].authenticate(user, pass)) {
            x = true;
        }
    }
    return x;
};

void Start() { // main function for the program, sets the authentication process in motion
    string US, PW;
    cout << "Kindly input your username: ";
    cin >> US;
    cout << "Kindly input your password: ";
    cin >> PW;

    while (!Authenticate(US, PW)) {
        cout << "\nWrong login details \n\n";
        cout << "Kindly input your username: ";
        cin >> US;
        cout << "Kindly input your password: ";
        cin >> PW;
    }
    
    if (Authenticate(US, PW)) {
        //Test();
        cout << "Welcome in" << endl;
    }
};

string arr[3][2];
string arr2[9];

int main() {
    Start();
    ifstream file("data.txt"); // Open the file
    string line;
    int count1 = 0;
    if (file.is_open()) {
        while (getline(file, line)) { // Read each line from the file
            stringstream ss(line);    // Create a stringstream for the line
            string value;

            // Extract and process values separated by the delimiter
            while (getline(ss, value, ',')) {

                cout << value << " "; // Print the value
                arr2[count1] = value;
                count1++;
            }
            cout << endl; // Newline after processing each line
        }
        file.close(); // Close the file
    } else {
        cout << "Unable to open file." << endl;
    }
    for (int i = 0; i < 9; i++) {
        cout << arr2[i] << "\t";
    }
    
    return 0;
}
