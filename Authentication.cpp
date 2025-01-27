#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void Start();
bool Authenticate(string u, string p);

bool Authenticate(string u, string p) {
    bool Us = false, Pass = false;
    ifstream file("data.txt"); // Open the file
    string line;
    int count1 = 0;
    if (file.is_open()) {
        while (getline(file, line)) { // Read each line from the file
            stringstream ss(line);    // Create a stringstream for the line
            string value;
            // Extract and process values separated by the delimiter
            while (getline(ss, value, ',')) {
                if (count1 < 1) {
                    if (u == value) { Us = true; }
                }
                else {
                    if (p == value) { Pass = true; }
                }
                count1++;
            }
            count1 = 0;
        }
        file.close(); // Close the file
    } else {
        cout << "Unable to open file." << endl;
    }
    return (Us && Pass);
}

void Start() {
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
        cout << "Welcome in" << endl;
    }
};

int main() {
    Start();
    return 0;
}
