#include <iostream>
#include<fstream>
#include <string>

using namespace std;

// Function to create a contact
//===============================================================================================

void create_contact()
{
    string phone_num;
    string name;

    cout << "\n\t Name :    ";
    cin.ignore();
    getline(cin, name);
    cout << "\t Phone Number :     ";
    cin >> phone_num;

    ofstream outfile;
    outfile.open("Phonebook Contacts/" + name + ".txt");
    outfile << name << "\n" << phone_num << endl;
    outfile.close();

    ofstream list_contacts_file;
    list_contacts_file.open("phonebook.txt",ios::app );
    list_contacts_file << name << "\t" << phone_num << endl;
    list_contacts_file.close();

    cout << "\n\n\t\t>>>>> The Contact has been created successfully <<<<<\t\t\n\n";
}

// Function to show all the contacts
//===============================================================================================
void list_contacts()
{

    string read;

    ifstream infile;
    infile.open("phonebook.txt", ios::in);

    cout << "\n\t\t >>>>> LIST OF CONTACTS <<<<<\n\t\t";
    cout << "\n\t\tName\t\tPhone Number \n";
    while (getline(infile, read))
    {
        cout << "\n\t\t" << read << endl ;

    }
    infile.close();
}
// Function to search for a contact
//===============================================================================================

void search_()
{

    string name;
    string read;
    cout << "\n Enter The Contact Name : \t";
    cin.ignore();
    getline(cin, name);
    cout << "\n\n\t _______________________________________ \n";
    ifstream infile1;
    infile1.open("Phonebook Contacts/" + name + ".txt");

    if (infile1.is_open()) {
        while (getline(infile1, read)) {

         cout <<"\n\t\t\t"<< read << endl;

        }
         cout << "\t _______________________________________ \n";
    }
    else {
        cout << "\n\n\t\t Contact Not Found !!!! \n\n";
    }

    infile1.close();
}

// Function to edit a contact from the files
//==============================================================================================
void Edit_()
{

    //-----------------------------
    string name;
    string phone;

    cout << " \n\t Enter the Contact need to be edited : ";
    cin.ignore();
    getline(cin, name);

    //-------------------------------------------------------------------
    string name1, phone1;
    ifstream getdata;
    getdata.open("Phonebook Contacts/" + name + ".txt");
    getline (getdata , name1);
    getdata >> phone1;
    getdata.close();
    //----------------------------------------------------------------
    ifstream infile1;
    ofstream infile2;

    infile1.open("Phonebook Contacts/" + name + ".txt");
    if (infile1.is_open()) {
        infile2.open("Phonebook Contacts/" + name + ".txt", ios::in | ios::trunc);

        cout << " \n\t Enter The New Phone Number :  ";
        cin >> phone;

        infile2 << name << "\n" << phone << "\n";
        cout << "\n\n\t\t >>>>> Contact Updated Successfully <<<<<\n\n ";
    }
    else
    {
        cout << "\n\n\t\t\t Contact Not Found !!! \n\n";
    }
    infile1.close();
    infile2.close();

    //-------------------------------------------------------------------
    fstream myfile2; //for reading records
    myfile2.open("phonebook.txt");
    string line;
    ofstream temp;
    temp.open("temp.txt");

    while (getline(myfile2,line))
    {
        if (line != name1 + "      " + phone1)
            temp << line << endl;
    }
    temp << name << "      " << phone << "\n";
    myfile2.close();
    temp.close();
    remove("phonebook.txt");
    rename("temp.txt", "phonebook.txt");
}
//function to delete a contact from the files
//===============================================================================================

void delete_()
{
    string name;
    cout << "Enter the Name: ";
    cin.ignore();
    getline(cin , name);
    string fileName = "Phonebook Contacts/" + name + ".txt";

    if (remove(fileName.c_str()) != 0) {
        cout << "\n\t\t Error deleting contact! \n";
    } else {
        cout << "\n\t\t >>>> Contact Deleted Successfully! <<<< \n\n";
    }

    // Remove from the phonebook.txt file
    ifstream myfile2("phonebook.txt");
    ofstream temp("temp.txt");

    string line;
    while (getline(myfile2, line)) {
        if (line.find(name) == string::npos)
            temp << line << endl;
    }
    myfile2.close();
    temp.close();
    remove("phonebook.txt");
    rename("temp.txt", "phonebook.txt");
}
// the main Function
//===============================================================================================

int main()
{
    char op;
    bool cont = true;

    while (cont)
    {
        cout << "\n\t\t>>> Welcome to the PhoneBook <<< \t\n";
        cout << "\n\t [1] Create a Contact\n";
        cout << "\t [2] List The Contacts\n";
        cout << "\t [3] Search For A Contact\n";
        cout << "\t [4] Edit A Contact \n";
        cout << "\t [5] Delete A Contact \n";

        cin >> op;

        switch (op)
        {
        case '1': create_contact();
            break;

        case '2':list_contacts();
            break;

        case '3': search_();
            break;

        case '4': Edit_();
            break;


        case '5': delete_();
            break;


        default:cout << "\t\t!!!!  Wrong input  !!!!!\t\t\n";
            main();
            break;

        }

        char c;
        cout << "\n\t\t[1] MAIN MENU \t\t [2] EXIT\n";
        cin >> c;

        if (c == '1')
            continue;


        else if (c == '2')
        {
            cout << "\n\t\t\t Thank You For Using The PhoneBook ......\n\n\n\n\n";
            cont = false;
            break;
        }

        else
            cout << "\n\t\tWRONG INPUT , try again!!! \n";

    }

    return 0;
}
