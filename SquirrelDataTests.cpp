#include "SquirrelDataTests.h"
#include "BPlusTree.h"
#include "Squirrel.h"

// runs tests
// param numberPhases: number of phases of tests to be run through
bool runTests(int numberPhases)
{
    bool testsPassing = true;

    // if first phase should be run
    if (numberPhases >= 1)
    {
        runTestPhase1();
    }
    return testsPassing;
}

// run phase 1 tests
bool runTestPhase1()
{
    bool testsPassing = true;

    // Instantiate a node with order n
    // n is currently hardcoded to 5
    BPlusTreeNode bPlusTreeNode = BPlusTreeNode(true);
    // Insert n-1 elements into node out of order
    bPlusTreeNode.addElement(Squirrel(1));
    bPlusTreeNode.addElement(Squirrel(5));
    bPlusTreeNode.addElement(Squirrel(3));
    bPlusTreeNode.addElement(Squirrel(2));
    bPlusTreeNode.addElement(Squirrel(4));

    // Verify that the elements and keys have been inserted into the node in ascending order
    for (int i = 1; i < order; i++)
    {
        if (((Squirrel)bPlusTreeNode.elements_[i]).compareTo((Squirrel)bPlusTreeNode.elements_[i - 1]) <= 0 ||
            bPlusTreeNode.keys_[i] < bPlusTreeNode.keys_[i - 1])
        {
            testsPassing = false;
        }
    }
    return testsPassing;
}

// run phase 2 tests
bool runTestPhase2()
{
    bool testsPassing = true;

    // create new BPlusTree object
    BPlusTree bPlusTree = BPlusTree();
    // fill root node
    // Insert n-1 elements into node out of order
    bPlusTree.insert(Squirrel(1));
    bPlusTree.insert(Squirrel(5));
    bPlusTree.insert(Squirrel(3));
    bPlusTree.insert(Squirrel(4));
    bPlusTree.insert(Squirrel(2));

    // Verify that the elements and keys have been inserted into the node in ascending order
    for (int i = 1; i < order; i++)
    {
        if (((Squirrel)(*bPlusTree.root).elements_[i]).compareTo((Squirrel)(*bPlusTree.root).elements_[i - 1]) <= 0)
        {
            testsPassing = false;
        }
    }

    return testsPassing;
}