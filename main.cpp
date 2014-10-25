#include <iostream>
#include <fstream>
#include "konstants.h"
#include <limits>
//#define STR(x) #x << '=' << x

using namespace std;

konstants* K;
int option;
string data;
string newFileName;

void setup()
{
    K = new konstants();
}

string& createNewFile(string newFileName){
    string newFileDir = K->dirFile;
    newFileDir.append(newFileName);
    //cout << newFileDir << endl;
    return &newFileDir;
}

string& toChar(int *toChar){
    string s;
    stringstream out;
    out << toChar;
    s = out.str();    
    return &s;
}

void checkSize(string* add, int count){
    string hola = "0";
    string tmp;

    for (int a = 1 ; a < count ; a++){
        if((tmp.length() + *add.length()) == count){
            break;
        }
        tmp.append(hola);
    }
    tmp.append(*add);
    add = tmp;
}


void createTable(int *registerSize, int* columnSizes, int *columns){
    cout << "**** Insert name for new table ***" << endl;
    cin >> newFileName;
    ofstream database ((*createNewFile(newFileName)).c_str() , ios::trunc); //append database name to path and creates it there.
    if(database.is_open())
        cout << "****Database succesfully created***" << endl;
    else
        cout << "****Database could not be created***" << endl;

    if(registerSize >= 999)
        cout << "Error: Register size beyond max size" << endl;
    else
    {
        database.seekp(3 , ios::beg);
        string* add = toChar(&registerSize);]
        checkSize(add,4);
        database << *add;
    }

    for (int i = 0 ; i < columns ; i++)
    {
        add = toChar(columnSizes[i]);
        checkColSize(add,3);
        database << *add;
    }
    database.seekp(*getDataInit(&newFileName)); //Place char pointer on the data start pointer.
}

int& getDataInit(string *newFileName){

}

void updateField(){
    ofstream file (K->dirFile.c_str() , ios::app);
    if(data.size() <= 64){

    }
    file.close();
}

void readField(){
    ifstream file (K->dirFile.c_str());
    char character;

    int row = (6 - 1) * 128;
    //show name
    file.seekg(row);
    while (file.tellg() < (64 * row)){
        character = file.get();
        if( character == '*'){
            cout << ' ' << endl;
            break;
        }
        cout << character;
    }

    cout << "------------------------------------------" << endl;

    //show lastname
    file.seekg(row + 64, ios::beg);
    while (file.tellg() < (128 * row)){
        character = file.get();
        if( character == '*'){
            cout << ' ' << endl;
            break;
        }
        cout << character;
    }

    /*
    //show adress
    file.seekg(row + 128, ios::beg);
    while (file.tellg() < 256 * row){
        character = file.get();
        if( character == '*'){
            cout << ' ' << endl;
            break;
        }
        cout << number;
    }

    //show country
    file.seekg(row + 256, ios::beg);
    while (file.tellg() < 320 * row){
        character = file.get();
        if( character == '*'){
            cout << ' ' << endl;
            break;
        }
        cout << number;
    }

    //show line
    string t;
    while(getline (file,t)){
        if(t != "\n"){
            cout << t << endl;
        }
    }*/
}

int main()
{
    setup();
    cout << "****Field operations***" << endl;
    cout << "****1. Edit ****" << endl;
    cout << "****2. Read ****" << endl;

    cin >> option;
    switch (option) {
        case 1:
        {
            updateField();
            break;
        }
        case 2:
        {
            readField();
            break;
        }
        default:
        {
            cout << "The cat said miau...\n";
            break;
}
    }

    return 0;
}

