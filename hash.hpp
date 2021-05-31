#ifndef HASH_HPP
#define HASH_HPP

#include <string>

//Cowritten by Marcus and Matthew
//Based off the attached hash.hpp file given for this assignment
//Matthew built the general functions
//Marcus developed the output formats for each experiment set of data and the driver for this. 

using namespace std;

struct node
{
    int key;
    struct node* next;
};

class Hash
{
    private:
        int tableSize;  // No. of buckets (linked lists)

        // Pointer to an array containing buckets
        node* *table;
        int numOfcolision = 0;
        node* createNode(int key, node* next)
        {
            node* newNode = new node;
            newNode->key = key;
            newNode->next = next;
            return newNode;
        }

    public:
        Hash(int bsize);  // Constructor

        // hash function to map values to key

        unsigned int hashFunction(int key);

        // inserts a key into hash table

        void insertItem(int key); //insert function through chainedl linked list
        void insertLin(int key);  //insert with linear probing
        void insertQuad(int key); //insert with quadratic probing

        // searches for a key in the table

        node* searchItem(int key); //search function through chained linked list
        node* searchLin(int key);  //search with linear opening addresses
        node* searchQuad(int key); //search with quadratic opening addresses

        // assorted class functions

        void printTable();
        int getNumOfCollision();
        int randSearch(int testData[], float se[], int count);


        

        

        
};

#endif
