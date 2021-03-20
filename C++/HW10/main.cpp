// HW10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
#include "cpersoninfo.h"

template <typename ObjType>
void DisplayInfo(const ObjType &object);

int main()
{
    
    CPersonInfo<int> P1;

    CPersonInfo<double> P2(260.3, 67.1, 90, "James Bunchanan Barnes");

    CPersonInfo<double> P3(P2);

    int weight;
    int height;
    int age;
    string fName;

    void (*rami)(const CPersonInfo<double>(&)) = DisplayInfo;

    rami(P3);

    string line;
    getline(cin, line);
    int count;
    weight = atof(line.c_str());
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == ' ')
        {
            line.erase(0, i + 1);
            height = atof(line.c_str());
            break;
        }
    }
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == ' ')
        {
            line.erase(0, i + 1);
            age = atof(line.c_str());
            break;
        }
    }
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == ' ')
        {
            line.erase(0, i + 1);
            break;
        }
    }

    
    
    fName = line;
    P1.SetWeight(weight);
    P1.SetHeight(height);
    P1.SetAge(age);
    P1.SetName(fName);

    cout << "P1: " << endl;
    DisplayInfo(P1);
    cout << "P2: " << endl;
    DisplayInfo(P2);
    cout << "P3: " << endl;
    DisplayInfo(P3);
    

}

template <typename ObjType>
void DisplayInfo(const ObjType &object)
{
    cout << "\t\t\t Weight = " << object.GetWeight() << endl;
    cout << "\t\t\t Height = " << object.GetHeight() << endl;
    cout << "\t\t\t Age = " << object.GetAge() << endl;
    cout << "\t\t\t Name = " << object.GetName() << endl;
    cout << "\t\t\t Total Name Length = " << object.GetNameLength() << endl;
}

