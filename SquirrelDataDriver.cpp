#include <iostream>
#include "Squirrel.h"
#include "CSVParser.h"
#include "SquirrelDataTests.h"
using namespace std;

int main(int argc, char const *argv[])
{   
    // instantiate new CSVParser object
    CSVParser::parseCSV(argv[1]);

    // run tests
    if(runTests(1)){
        cout << "tests passing!" << endl;
    }
    else{
        cout << "tests failed, die in a hole." << endl;
    }
    Squirrel squirrel;
    return 0;
}
