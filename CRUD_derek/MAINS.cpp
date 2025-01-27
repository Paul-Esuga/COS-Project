#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

std::vector<std::string> matlines;//VECTOR CONTAINING MAT NUMBERS
std::vector<std::string> namelines;//VECTOR CONTAINING NAMES
std::vector<std::string> scorelines;//VECTOR CONTAINING SCORES

void addrecords()//FUNCTION TO ADD NEW RECORDS
{
    int myear;//MATRICULATION YEAR
    int nscore;//SCORES
    string nname;//FULLNAME
    string fname;//FIRSTNAME
    string lname;//LASTNAME
    string nmatsize = to_string(matlines.size());//SIZE OF VECTOR CONVERTED TO STRING

    cout << "GENETRATING MATRICULATION NUMBER......" << endl;
    cout << "ENTER YEAR OF MATRICULATION:" ;

    while (!(cin >> myear)) {//FUNCTION TO ENSURE VALID INTEGER INPUT
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    string smyear = to_string(myear);//MATRIC YEAR CONVERTED TO STRING
    if (smyear.size() == 4) { //ENSURING THE YEAR IS 4 DIGITS
        std::cout << "Input is within the allowed size.\n";
    }
    else
    {
        std::cout << "INVALID MATRIC YEAR ENTERED, NOW RESTARTING PROCESS" <<"\n\n";
        smyear.clear();
        cin.clear();
        addrecords();//MAKING THE FUNCTION RECURSIVE IN CASE OF WRONG INPUT
        return;
    }

    cout << "ENTER STUDENT LAST NAME: ";
    cin >> lname;
    cout<< "ENTER STUDENT FIRST NAME: ";
    cin >> fname;
    nname = lname + " " + fname; //FULLNAME MADE BY APPENDING FIRST AND LAST YEAR

    cout << "ENTER STUDENT SCORE: ";
    cin >> nscore;

    if(!(nscore))//CASE TO MAKE SURE INPUT IS AN INTEGER
        {
            cout << "ENTER A VALID INTEGER: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    else
        {
            if(nscore >= 0 && nscore <= 100)
                {
                    string snscore = to_string(nscore);//SCORE CONVERTED TO STRING
                    string nsmyear = smyear+"/SEN/0"+nmatsize;//MATRIC NUMBER BEING PUT TOGETHER
                    matlines.push_back(nsmyear);//ADDING THE NEW MATRIC NUMBER TO THE BACK OF THE VECTOR
                    namelines.push_back(nname);//ADDING THE NEW NAME TO THE BACK OF THE VECTOR
                    scorelines.push_back(snscore);//ADDING THE NEW SCORE TO THE BACK OF THE VECTOR

                    string YORN;//TO ADD ANOTHER USER
                    cout << "ENTER ANOTHER USER?" << endl;
                    cout << "ENTER Y FOR YES AND N FOR NO" << endl;
                    cin >> YORN;
                    if(YORN == "Y" || YORN == "y")
                        {
                            addrecords();
                            return;
                        }
                    else if (YORN == "N" || YORN == "n")
                        {
                            cout << "\n";
                            cout << "NOW RECOMMENCING PROCESS" << "\n\n";
                        }
                    else
                        {
                            cout << "INVALID ENTRY, NOW RESTARTING PROCESS";
                            addrecords();
                            return;
                        }

                }
            else
                {
                    cout << "INVALID SCORE ENTERED, NOW RESTARTING PROCESS"<<"\n\n";
                    addrecords();
                    return;
                }
        }

}






void saveupdates()
{
    std::ofstream file("UPDATEDMATNO.txt");//TO SAVE THE UPDATES TO A FILE
    vector<string> data = {matlines};

    if (file.is_open()) {
        for (size_t i = 0; i < data.size(); ++i) {
            file << data[i];
            if (i < data.size() - 1) {
                file << "\n";
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file";
    }

    std::ofstream filen("UPDATEDNAME.txt");//TO SAVE THE UPDATES TO A FILE
    vector<string> datan = {namelines};

    if (filen.is_open()) {
        for (size_t i = 0; i < datan.size(); ++i) {
            filen << datan[i];
            if (i < datan.size() - 1) {
                filen << "\n"; // Change ',' to your delimiter
            }
        }
        filen.close();
    } else {
        std::cerr << "Unable to open file";
    }

    std::ofstream filesc("UPDATEDSCORE.txt");//TO SAVE THE UPDATES TO A FILE
    vector<string> datasc = {scorelines};

    if (filesc.is_open()) {
        for (size_t i = 0; i < datasc.size(); ++i) {
            filesc << datasc[i];
            if (i < datasc.size() - 1) {
                filesc << "\n"; // Change ',' to your delimiter
            }
        }
        filesc.close();
    } else {
        std::cerr << "Unable to open file";
    }
}





void updatexisting()//to edit existing records
{
    int matselect;//LAST DIGIT OF MAT NO
    int newscore;//UPDATED SCORE
    cout << "ENTER THE LAST TWO DIGITS OF THE MATRICULATION NUMBER OF THE RECORD YOU WISH TO UPDATE" << endl;//THIS SECTION FOCUSES ON SELECTING A SPECIFIC RECORD
    cout << "2023/SEN/0";
    cin >> matselect;
    cout << "\n";

    if(!(matselect))//TO ENSURE THAT INPUT IS AN INTEGER
        {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    string smatselect = to_string(matselect);//CONVERT THE DIGITS TO STRING

    if (smatselect.size() < 3 && smatselect.size() > 0)//TO ENSURE THE STRING IS LESS THAN 3 BUT GREATER THAN 0
        {
            std::cout << "Input is within the allowed size.\n";
        }
    else
        {
            std::cout << "INVALID NUMBER ENTERED, NOW RESTARTING PROCESS" <<"\n\n";
            cin.clear();
            updatexisting();
            return;
        }

    cout << "MATRICULATION NUMBER: " << matlines[matselect] << "\n";//DISPLAYING THE SPECIFIC MATNO
    cout << "STUDENT NAME: " << namelines[matselect] << "\n";//DISPLAY THE SPECIFIC NAME
    cout << "STUDENT SCORE: " << scorelines[matselect] << "\n\n";//DISPLAY THE SPECIFIC SCORE
    cout << "ENTER NEW SCORE: " << "\n";
    cin >> newscore;
    string snewscore = to_string(newscore); //CONVERT NEW SCORE TO STRING
    scorelines[matselect] = snewscore;// REPLACING THE OLD SCORE IN THE VECTOR BY TAKING ITS LOCATION
}




void displayall()
{
    for(int I = 0; I < matlines.size() ;I++)
        {
            cout << matlines[I] <<" | "<< scorelines[I] << " | " << namelines[I] << endl;
        }
}





int main() {
    std::ifstream matfile("MATRICNUMBERS.txt");//LOADING THE TEXT FILES INTO VECTORS
    std::string matline;

    if (matfile.is_open()) {
        while (std::getline(matfile, matline)) {
            matlines.push_back(matline);
        }
        matfile.close();
    } else {
        std::cerr << "Unable to open file";
    }

    ////////////////////////////////////////////////////////////////////////////////////////
    std::ifstream namefile("NAME.txt");//LOADING THE TEXT FILES INTO VECTORS
    std::string nameline;

    if (namefile.is_open()) {
        while (std::getline(namefile, nameline)) {
            namelines.push_back(nameline);
        }
        namefile.close();
    } else {
        std::cerr << "Unable to open file";
    }
    //////////////////////////////////////////////////////////////////////////////////////
    std::ifstream scorefile("SCORES.txt");//LOADING THE TEXT FILES INTO VECTORS
    std::string scoreline;

    if (scorefile.is_open()) {
        while (std::getline(scorefile, scoreline)) {
            scorelines.push_back(scoreline);
        }
        scorefile.close();
    } else {
        std::cerr << "Unable to open file";
    }

    // Output the contents of the vector
    displayall();


    cout << "HERE IS THE FUNCTION TO ADD RECORDS" << "\n\n";
    addrecords();
    cout << "HERE IS THE FUNCTION TO EDIT RECORDS" << "\n\n";
    updatexisting();
    cout << "NOW A FUNCTION TO SAVE RECORDS TO FILE" << "\n\n";
    saveupdates();
    cout << "NOW A FUNCTION TO DISPLAY ALL RECORDS(WITH UPDATES)" << "\n\n";
    displayall();

    return 0;
}

