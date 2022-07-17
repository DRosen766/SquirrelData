#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

#include "SquirrelDataDriver.h"
#include "Squirrel.h"
#include "BPlusTree.h"
#include "CSVParser.h"

using namespace std;

BPlusTree* parseCSV(string csvFileName)
{
    // open csv file
    ifstream csvFile;
    csvFile.open(csvFileName);
    // instantiate pointer to data structure
    BPlusTree* bPlusTree = new BPlusTree();

    // declare string to hold current line
    string currentLine;
    // read header line
    getline(csvFile, currentLine);

    // instantiate line counter
    int lineCounter = 1;

    // for each record in csvFile
    while(getline(csvFile, currentLine)){
        lineCounter++;
        // read longitude, first element of current record
        float currentLongitude = stof(currentLine.substr(0, currentLine.find(",")));
        // erase first element from current line
        currentLine.erase(0, currentLine.find(",") + 1);
        // read latitude, second element of current record
        float currentLatitude = stof(currentLine.substr(0, currentLine.find(",")));
        // erase second element from current line
        currentLine.erase(0, currentLine.find(",") + 1);
        // read ID, third element of current record
        string currentID = currentLine.substr(0, currentLine.find(","));
        // erase third element from current line
        currentLine.erase(0, currentLine.find(",") + 1);
        // Create squirrel Object
        Squirrel currentSquirrel = Squirrel(currentLongitude, currentLatitude, currentID);
        // insert squirrel into BPlusTree
    }

    // print number of lines
    cout<<"numberLines: "<<lineCounter<<endl;
    // return pointer to data structure
    return bPlusTree;
}