//
//  main.cpp
//  RandomWriter
//
//  Created by Anish Seth on 5/25/16.
//  Copyright © 2016 Anish Seth. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
//reads file into a string
string readfile()
{
    string text;
    string line;
    ifstream myfile ("words.txt");
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            getline(myfile, line);
            text += line + " ";
        }
        myfile.close();
    }
    return text;
}
//finds a random string of text with given seedlength from random position in text
int findString(string text, int length, int seed)
{
    int seedlength = seed;
    int index = rand() % (text.length() - seedlength);
    string textfile = text;
    string String = text.substr(index, seedlength);
    string output = "";
    for(int count = 0; count < length; count++)
    {
        string following = "";
        for(int i = 0; i < text.length() - seed - 1; i++)
        {
            if(text.substr(i, seed) == String)
                following += text.substr(i + seed, 1);
        }
        int random = (rand() % following.length());
        String = String.substr(1, seed - 1) + following.substr(random, 1);
        textfile += following.substr(random, 1);
    }
    cout << textfile;
    return 0;
}
int main(int argc, const char * argv[])
{
//asks for seed length
    int seedlength;
    cout << "Welcome to Random Writer. Please select your seed length: ";
    cin>>seedlength;
//determines number of characters the code parses through
    int filelength = 1000;
    string follow;
//reads file
    string text = readfile();
//finds string
    findString(text, filelength, seedlength);
}