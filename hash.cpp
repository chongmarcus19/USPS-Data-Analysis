#include "hash.hpp"
#include <string>
#include <iostream>
#include <chrono>


using namespace std;

Hash :: Hash (int bsize)
{
    table = new node*[bsize];
    tableSize = bsize;
}

unsigned int  Hash :: hashFunction(int key)
{
    return key % tableSize; //creates indices for use in the hash function
}

void Hash :: insertItem(int key)
{
    int pos = hashFunction(key); //solves/finds positional index

    if(table[pos] != NULL) //if position is not open/NULL
    {
        node* temp = table[pos]; //retrives node at pos
        
        while(temp->next != NULL) //traverese list
        {
            temp = temp->next;
        }

        node* newnode = createNode(key, NULL); //reaches position, creates new node
        temp->next = newnode; //inserts new node

    }
    else
    {
        //insert value as new node into table directly
        node* newnode = createNode(key, NULL);
        table[pos] = newnode;
    }
}

void Hash :: insertLin(int key) //mostly same as insert
{
    int pos = hashFunction(key); //solves/finds positional index
    node* temp = createNode(key, NULL);

    if(table[pos] != NULL) //if position is not open/NULL
    {
        int nextavl = pos;  
        while(table[nextavl%tableSize] != NULL) //traverese list linearly for next avaliable
        {
            nextavl++;
        }

        table[hashFunction(nextavl)] = temp; //inserts new node

    }
    else
    {
        //insert value as new node into table directly
        table[pos] = temp;
    }
}

void Hash :: insertQuad(int key) //mostly same as linear
{
    int pos = hashFunction(key); //solves/finds positional index
    node* temp = createNode(key, NULL);

    if(table[pos] != NULL) //if position is not open/NULL
    {
        int nextavl = pos;
        int power = 1;
        //did not trust hashFunction function, used literal calculation inside table
        while(table[nextavl%tableSize] != NULL) //traverese list linearly for next avaliable
        {
            nextavl = pos + power * power; //quadratically increments pos based on power value
            power ++;
        }

        table[hashFunction(nextavl)] = temp; //inserts new node

    }
    else
    {
        //insert value as new node into table directly
        table[pos] = temp;
    }
}

node* Hash :: searchItem(int key)
{
    int pos = hashFunction(key); //solves/finds positional index
    node* temp = table[pos]; //retrieves first node for pos

    while(temp != NULL) //loops to find value or end depending on what it hits first
    {
        if(temp->key == key)
        {
            return temp;
            
        }
        temp = temp->next;
    }
}

node* Hash :: searchLin(int key) //very similar to insert counterpart in terms of traversal
{
    int pos = hashFunction(key);

    if(table[pos]->key == pos) //if value is found immediatly or at all during function
    {
        return table[pos]; //returns found pointer 
    }
    else
    {
        int nextavl = pos;  
        while(table[nextavl%tableSize] != NULL) //traverese list linearly for next avaliable
        {
            nextavl++;
        }

        return table[hashFunction(nextavl)]; //returns found pointer
    }
     
}

node* Hash :: searchQuad(int key) //very similar to insert counterpart in terms of traversal
{
    int pos = hashFunction(key);

    if(table[pos]-> key == pos)
    {
        return table[pos];
    }

    else
    {
        int nextavl = pos;
        int power = 1;
        //did not trust hashFunction function, used literal calculation inside table
        while(table[nextavl%tableSize] != NULL) //traverese list linearly for next avaliable
        {
            nextavl = pos + power * power; //quadratically increments pos based on power value
            power ++;
        }

        return table[hashFunction(nextavl)];
    }
    
}

void Hash :: printTable()
{
    for(int i = 0; i < 100; i++) //testing for just the first 100 to see if they are correct.
    {
        cout << "Location " << i << ": ";
        node* temp = new node;
        temp = table[i];

        while(temp != NULL)
        {
            cout << temp->key << "-->";
            temp = temp->next;
        }
        cout << endl;
    }
}

int Hash :: randSearch(int testData[], float se[], int count)
{
    using namespace std::chrono;
	
	auto start = steady_clock::now();

    for (int i = 0; i < 100; i++) //only generates 100 pseudo searches 
    {
        searchItem(testData[rand() % count]); 
        //random positions of testData bounded by the current count
    }

	auto end = steady_clock::now();

    se[count/100] = duration_cast<nanoseconds>(end - start).count();
}









 