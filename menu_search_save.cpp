#include <iostream>
#include <fstream>//file stuff
#include <sstream>
#include <string> //I imported this to use getline
#include <algorithm>//I imported this to use transform for the lowercase function
using namespace std;
//function to trim trailing and leading whitespace 
string trim(const string& str) {
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
void search_func(string searcher_indiana){
  ifstream inputfile;
  string fileline;
  inputfile.open("Student_records.txt");
  string matric_no, name;
  int mth,sa,na,qc,pt;
  float gpa;
  if (inputfile.is_open()){
    bool found_record = false;
    while(getline(inputfile,fileline)){
        if (fileline.find(searcher_indiana) != string::npos){
          cout <<"------------" << endl;
          cout <<"RECORD FOUND" << endl;
          cout <<"------------"<< endl;
          cout <<fileline<<endl;
          found_record = true;
          break;
        }
    }
  }
}
int main() {
  //variables for the menu system
  string menu_choice;
  bool valid_choice = false;//was the users input valid?
  string stud_to_be;
  //User introduction to result management software
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
    getline(cin,stud_to_be);
    //activate search function
    search_func(stud_to_be);
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
