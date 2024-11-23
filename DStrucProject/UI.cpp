#include "UI.h"

#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedQueue.h"
#include "PriQueue.h"
#include "Hospital.h"
#include "Patient.h"
#include "Car.h"

using namespace std;
void parseString(vector<string>& v, string s);

void UI::readFile()
{

    fstream Finput;
    vector<string> v1;
    Finput.open("Input.txt", ios::in);

    if (!Finput.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    int NoHp;

    if (!(Finput >> NoHp)) {
        cout << "Error reading integer from file!" << endl;
        Finput.close();
        return;
    }
    int SpeedScar, SpeedNcar;
    Finput >> SpeedScar;
    Finput >> SpeedNcar;

    cout << NoHp << endl << SpeedScar << endl << SpeedNcar << endl;

    int** arr = new int* [NoHp];
    for (int i = 0; i < NoHp; i++) {
        arr[i] = new int[NoHp];
    }
    for (int i = 0; i < NoHp; i++)
    {
        for (int j = 0; j < NoHp; j++)
        {
            Finput >> arr[i][j];
        }
    }
    for (int i = 0; i < NoHp; i++)
    {
        for (int j = 0; j < NoHp; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int** arrCars = new int* [NoHp];

    for (int i = 0; i < NoHp; i++) {
        arrCars[i] = new int[2];
    }
    for (int i = 0; i < NoHp; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            Finput >> arrCars[i][j];
        }
    }
    for (int i = 0; i < NoHp; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arrCars[i][j] << " ";
        }
        cout << endl;
    }
    int NoReq;
    Finput >> NoReq;
    cout << NoReq << endl;
    string line;
    int c = 0;
    do
    {
        v1.push_back(line);
        c++;

    } while (getline(Finput, line) && c <= NoReq);

    for (int i = 0; i < NoReq; i++)
    {
        cout << v1[i] << endl;
    }


    Finput.close();




}

void parseString(vector<string>& v, string s)
{
    string word;
    istringstream iss(s);
    while (iss >> word)
    {
        v.push_back(word);
    }
}
