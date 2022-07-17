#!/bin/bash
# compile c++ code
g++ -o SquirrelDataDriver -Wall SquirrelDataDriver.cpp Squirrel.cpp CSVParser.cpp SquirrelDataTests.cpp BPlusTree.cpp

# execute code
./SquirrelDataDriver 2018_Central_Park_Squirrel_Census_-_Squirrel_Data.csv > output.txt
echo "End of script"