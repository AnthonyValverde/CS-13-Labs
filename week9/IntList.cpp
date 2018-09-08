#include "IntList.h"
#include <iostream>

using namespace std;

// Initializes an empty list.

IntList::IntList(){
    head = 0;
    tail = 0;
}

// Deallocates all remaining dynamically allocated memory (all remaining IntNodes).

IntList::~IntList(){
    
    while(head != 0){
        IntNode* tmp = head;
        head = head -> next;
        delete tmp;
    }
}

/* Displays to a single line all of the int values stored in the list, 
each separated by a space. This function does NOT output a newline 
or space at the end. */

void IntList::display() const{
    
    if(head == 0){
        
        return;
    }
    
    IntNode* c = head;
    
    while(c != 0){
        
        cout << c -> data;
        
        if (c != tail){
            cout << ' ';
        }
        
        c = c-> next;
    }
    
    
    
}
// Inserts a data value (within a new node) at the front end of the list.

void IntList::push_front(int value){
    
    IntNode* tmp = head;
    head = new IntNode(value);
    head -> next = tmp;
    
    if(tail == 0){
        tail = head;
    }
    
}

/* Removes the value (actually removes the node that contains the value) 
at the front end of the list. Does nothing if the list is already empty. */

void IntList::pop_front(){
    
    if(head == 0){
        return; 
    }
    
    IntNode* tmp = head;
    head = head -> next;
    delete tmp;
    
    if(head == 0){
        
        tail = 0;
    }
}

/* Returns true if the list does not store any data values (does not have any nodes),
otherwise returns false. */

bool IntList::empty() const{
    
    if(tail == 0){
        
        return true;
    }
    
    return false;
}
