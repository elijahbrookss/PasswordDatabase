#include <iostream>
#include <fstream>

// Program to hold passwords for websites and programs.
// Uses files to store passwords and websites,
// When loading, ask user if they need to get a password or enter a password.

using namespace std;

void enterInfo(); //function to enter passwords and usernames
void gainInfo(); //function to get passwords and usernames back
void clr(); // clears prompt
void customizeScreen(); //customizes screen.


int main(void){

    customizeScreen();

    string user_input;

    cout<<"Welcome to your personal Password Database.\n"<<endl;
    while(user_input!="3"){


        cout<<"Enter the number next to the option."<<endl;
        cout<<"1) Retrieve a password."<<endl;
        cout<<"2) Enter website and password into database."<<endl;
        cout<<"3) Exit."<<endl;
        cout<<"Input: ";

        cin>>user_input;

        cout<<endl;

        if (user_input=="1")gainInfo();
        else if(user_input=="2")enterInfo();

    }

    system("exit");

    //enterInfo();
    //gainInfo();
    return 0;
}

// EnterInfo function
void enterInfo(){

    cout<<"Enter website name and password."<<endl;
    cout<<"Enter 'quit' to quit.\n----------------------"<<endl;

    string website;
    string password;
    string ui;

    ofstream pass_database("PasswordDatabase.txt", ios::app);

    cout<<"Input: ";

    if (pass_database.is_open()){
        while (cin>>website>>password && website!="quit" && password!= "quit"){

            pass_database << website << ' '<<password<<endl;

            cout<<"-------------------\n";
            cout<<"Input: ";

        }

    }

    clr();
    //cout<<"Terminating, returning to menu.\n";

    pass_database.close();
}

//GainInfo Function

void gainInfo(){

    int found = 0;

    string user_string;
    string website;
    string password;

    cout<<"Enter the website you need the password from."<<endl;
    cout<<"Enter 'quit' to quit."<<endl;
    cout<<"Input: ";
    cin>>user_string;


    while(user_string!="quit"){

        ifstream pass_database("PasswordDatabase.txt");

        while(pass_database.good()&& found==0){
            pass_database>>website>>password;

            if(user_string == website){
                found = 1;
                cout<<"The password for "<<website<<" is "<<password<<".\n"<<endl;
            }

        }
        if(found == 0){
            cout<<user_string<<" isn't in the database.\n"<<endl;
        }
        found = 0;

        pass_database.close();

        cout<<"Enter the website you need the password from."<<endl;
        cout<<"Enter 'quit' to quit."<<endl;
        cout<<"Input: ";
        cin>>user_string;

    }

    clr();

}

//Clear Screen function

void clr(){system("cls");}

void customizeScreen(){

    system("@echo off");
    system("color 40");
    system("cls");

}
