#include <iostream>
#include "IntList.h"

using namespace std;

//Default constructor
IntList::IntList()
    :head(0), tail(0)
{}

//Destructor
IntList::~IntList()
{
    IntNode* temp;
    
    while(head != 0){
        temp = head;
        head = head->next;
        delete temp;
    }
}
IntList::IntList(const IntList &cpy) {
    head = cpy.head;
    tail = cpy.tail;
}
    

//Displays list all on single line
void IntList::display() const
{
    if(head != 0){
        IntNode* temp = head->next;
        cout << head->data;
        
        while(temp != 0){
            cout << " " << temp->data;
            temp = temp->next;
        }
    }
}

//Adds value to front of list
void IntList::push_front(int val)
{
    if(head == 0){
        head = new IntNode(val);
        tail = head;
    }
    else{
        IntNode* temp = new IntNode(val);
        temp->next = head;
        head = temp;
    }
    
}

//Adds value to end of list
void IntList::push_back(int val)
{
    if(head == 0){
        head = new IntNode(val);
        tail = head;
    }
    else{
        tail->next = new IntNode(val);
        tail = tail->next;
    }
    
}

//Deletes value at front of list only
void IntList::pop_front()
{
    if(head == 0){
        return;
    }
    
    IntNode* temp = head;
    head = head->next;
    delete temp;
    if(head == 0){
        tail = 0;
    }
}

//sorts list in order least to greatest
void IntList::selection_sort()
{
    for(IntNode* cur = head; cur != 0; cur = cur->next){
        IntNode* small = cur;
        
        for(IntNode* cur2= cur; cur2 != 0; cur2= cur2->next){
            if(cur2->data < small->data){
                small = cur2;
            }
        }
        
        int temp = cur->data;
        cur->data = small->data;
        small->data = temp;
    }
}

//insert value to list in correct order
void IntList::insert_ordered(int val)
{
    if(head == 0){
        push_front(val);
    }
    else if(head->next == 0){
        if(head->data >= val){
            push_front(val);
        }
        else{
            push_back(val);
        }
    }
    else if(tail->data <= val){
        push_back(val);
    }
    else if(head->data > val){
        push_front(val);
    }
    else{
        IntNode* before = head;
        IntNode* current = head->next;
        IntNode* temp = 0;
        
        for(temp = head; !(( before->data <= val) && (current->data >= val));
                                        temp = temp->next){
            before = temp->next;
            current = temp->next->next;         //WORK??????????
        }
        
        IntNode* temporary = new IntNode(val);
        temporary->next = current;
        before->next = temporary;
    }
}

//remove duplicates in list
void IntList::remove_duplicates()
{
    IntNode* temp;
    IntNode* ptr = head;
    
    for(IntNode* i = head; i != 0; i = i->next){
        
        temp = i->next;
        ptr = i;
        
        while(temp != 0){
            if( i->data == temp->data){
                IntNode* temp2 = temp;
                
                if( temp == tail){
                    temp = 0;
                    ptr->next = 0;
                    tail = ptr;
                    delete temp2;
                }
                else{
                    ptr->next = temp->next;
                    temp = temp->next;
                    delete temp2;
                }
            }
            else{
                temp = temp->next;
                ptr = ptr->next;
            }
        }
    }
}
    