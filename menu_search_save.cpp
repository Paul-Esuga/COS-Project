#include <iostream>
#include <fstream>//file stuff
#include <sstream>
#include <string> //I imported this to use getline
#include <algorithm>//I imported this to use transform for the lowercase function
#include <vector>
using namespace std;
//function to trim trailing and leading whitespace 
string trim(string str) {
  size_t start = 0;
  size_t end = str.length();
  // Find the first non-whitespace character
  while (start < end && isspace(str[start])) {
      ++start;
    }
    // Find the last non-whitespace character
  while (end > start && isspace(str[end - 1])) {
      --end;
    }
    // Return the trimmed substring
  return str.substr(start, end - start);
}
//function to make user input lowercase
string LowerCase(string basketcase) {
  string lower = basketcase;
  transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
  return lower;
}
void searchStudentRecord(string matricNumber){
  cout <<"----------------------"<<endl;
      ifstream ip("STUDENTS_RECORDS.csv");
    if (!ip.is_open()) {
        cout << "Error. File not open" << "\n";
    }

    string matric_no, student_name, math, sa, na, qc, pc, gpa;
    vector<vector<string>> student_records; // Multidimensional vector to store student data

    while (ip.good()) {
        getline(ip, matric_no, ',');
        getline(ip, student_name, ',');
        getline(ip, math, ',');
        getline(ip, sa, ',');
        getline(ip, na, ',');
        getline(ip, qc, ',');
        getline(ip, pc, ',');
        getline(ip, gpa, '\n'); // Assume GPA ends with a newline

        // Append the current student's data to the multidimensional vector
        student_records.push_back({matric_no, student_name, math, sa, na, qc, pc, gpa});//this is a record being pushed to the vector
    }

    ip.close(); // Always close the file after usage
    string target = matricNumber;//This is what were looking for from the vector
    bool found = false;
    // Print the data from the vector
    for (size_t row = 0; row < student_records.size(); ++row) {
        for (size_t col = 0; col < student_records[row].size(); ++col) {
            if (student_records[row][col] == target) {
                cout << "Matric No: " << student_records[row][0] << endl;
                cout << "Student Name: " << student_records[row][1] << endl;
                cout << "Math Score: " << student_records[row][2] << endl;
                cout << "System Analysis Score: " << student_records[row][3] << endl;
                cout << "Network Analysis Score: " << student_records[row][4] << endl;
                cout << "Quantum Chaos Score: " << student_records[row][5] << endl;
                cout << "Protein Topology Score: " << student_records[row][6] << endl;
                cout << "GPA: " << student_records[row][7] << endl; 
                found = true;
                break; // Stop inner loop once the element is found
            }
        }
        if (found) break; // Stop outer loop if the element is found
    }
        if (!found) {
        cout << target << "\" was not found in the database." << endl;
    }

}
int main() {
  //variables for the menu system
  string menu_choice;
  bool valid_choice = false;//was the users input valid?
  string searching_mat;
  string restart;
  //User introduction to result management software
  reprompt_restart://if the user chooses to start again after finishing their task
  cout << "Welcome to the student result management system"<< endl;
  cout << "               MAIN-MENU                       "<< endl;
  cout<<"To SEARCH for student result press--- S"<<endl;
  cout<<"To UPDATE a student's result press--- U"<<endl;
  cout<<"To SAVE a student's result press--- F"<<endl;
  cout<<"To VIEW a student's result press--- V"<<endl;
  cout<<"To EXIT the program--- E\n"<<endl;
  while(valid_choice == false){
  cout<<"What would you like to do?"<<endl;
  getline(cin,menu_choice);//user input for menu prompt
  //input conversion(trimming whitespace and converting to lowecase)
  string lower_menu_choice = LowerCase(menu_choice);
  string modo_menu_choice = trim(lower_menu_choice);
  //conditionals block for checking user input
  if (modo_menu_choice == "s" || modo_menu_choice == "search"){
    valid_choice = true;
    cout << "---YOU CHOSE TO SEARCH FOR A STUDENT---" <<endl;
    cout <<"What is their matric number?\n";
    getline(cin,searching_mat);
    //activate search function
    searchStudentRecord(trim(searching_mat));
    //prompt the user to start again if they finish searching
    cout << "--------------------"<<endl;
    cout <<"Would you like to do anything else(yes/no)?\n";
    string lower_restart = LowerCase(restart);
    string modo_restart = trim(lower_restart);
    getline(cin,modo_restart);
      if (modo_restart=="yes" || modo_restart =="y"){
        goto reprompt_restart;
      }
      else if (modo_restart=="no" || modo_restart=="n"){
        cout <<"----------------"<<endl;
        cout <<"Have a nice day"<<endl;
      } else {
        cout << "Invalid input"<<endl;
      }
  }
  else if(modo_menu_choice == "u" || modo_menu_choice == "update"){
    valid_choice = true;
    //pass
  }
  //user chose to save a students result
  else if(modo_menu_choice == "f" || modo_menu_choice == "save"){
    valid_choice = true;
    //pass
  }
  else if(modo_menu_choice == "v" || modo_menu_choice == "view"){
    valid_choice = true;
    //pass
  }else if(modo_menu_choice == "e" || modo_menu_choice == "exit"){
    valid_choice = true;
    cout <<"---YOU HAVE EXITED THE PROGRAM---"<< endl;
    goto end_of_program;
  }
  else {
    cout<<"That doesnt seem quite right. Please enter a valid option" << endl;
  }
  //while loop exit indent
  }
  end_of_program:
  return 0;
}
