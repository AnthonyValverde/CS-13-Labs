#include <iostream>
#ifndef INTLIST_H
#define INTLIST_H

using namespace std;

struct IntNode {
    int data;
    IntNode *next;
    IntNode( int data ) : data(data), next(0) {}
};

class IntList {
    private:
    
        IntNode* head;
        IntNode* tail;
    public:
    
        IntList(); //default constructor
        ~IntList(); //default destructor
        void display() const; //displays all the int values stored in the list
        void push_front(int val); //adds a value to the beginning of the list
        void push_back(int val); //adds a value to the end of the list
        void pop_front(); //deletes first value in the list
        void selection_sort(); //sorts list in order
        IntList(const IntList &cpy);
        IntList &operator=(const IntList &rhs);
        friend ostream & operator<<(ostream &out, const IntList &rhs);
        void insert_ordered(int val); //inserts value to list in correct order
        void remove_duplicates(); //remove all duplicates in list
        
};
#endif