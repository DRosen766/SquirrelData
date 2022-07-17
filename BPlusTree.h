#include <iostream>
#include <stdio.h>
#include <string>
#include "Squirrel.h"
using namespace std;

#ifndef BPlusTree_H
#define BPlusTree_H
    // hardcode the order of the BPlusTree
    static int order = 5;


    // template <class T>
    class BPlusTreeNode{
        // all properties are public for testing purposes
        // normally I would hide this data and use getters and setters to allow clients to interact with information
        public:
        // boolean that is true iff this node is a leaf node
        bool isLeaf_;
        // the number of elements or keys currently held in this node
        int numberElements_;
        // array of keys held in this node
        float* keys_;
        // array of elements in this node, null if this is an internal node
        Squirrel* elements_;
        BPlusTreeNode* children_;
        // constructor
        // param isLeaf: boolean that is true iff this node is a leaf node
        BPlusTreeNode(bool isLeaf){
            isLeaf_ = isLeaf;
            numberElements_ = 0;
            // allocate memory for keys, elements and children
            keys_ = (float*)calloc(order, sizeof(float*));
            elements_ = (Squirrel*)calloc(order, sizeof(Squirrel));
            children_ = (BPlusTreeNode*)calloc(order, sizeof(BPlusTreeNode));
        }

        // inserts new element into this node's list of elements
        // all elements in this node should be ordered after inserting this new element
        // param newSquirrel: Squirrel object to be added into elements array
        void addElement(Squirrel newSquirrel){            
            // find insertion index
            int index = 0;
            while(((Squirrel)elements_[index]).compareTo(newSquirrel) < 0 && index < numberElements_){
                index++;
            }
            // shift elements greater than newSquirrel
            // iterate backwords through elements and keys that come after newSquirrel
            for(int i = numberElements_; i > index; i--){
                // shift each element one index down
                elements_[i] = elements_[i - 1];

                // shift each key one index down
                keys_[i] = keys_[i - 1];
            }
            // insert newSquirrel element
            elements_[index] = newSquirrel;
            // insert newSquirrel key
            keys_[index] = newSquirrel.getLat();
            // increase number of elements counter
            numberElements_++;
        }

        // display elements in this node

        void display(){
            // iterate through all elements in node
            for(int i = 0; i < numberElements_; i++){
                // display latitude of current element to output
                printf("key: %.3f lat: %2.3f lon: %.3f ID: %s\n", keys_[i], elements_[i].getLat(), elements_[i].getLon(), elements_[i].getID().c_str());
            }
            cout << "End of display function\n";
        }
    };

    // declare generic BPlusTree class
    // template <typename T>
    class BPlusTree{
        public:
        // root node
        BPlusTreeNode* root;
        // default constructor
        BPlusTree(){
            root = new BPlusTreeNode(true);
        }
        // insert an elem
        // writes contents of BPlusTree to provided file
        void display(){

        }
    };

#endif