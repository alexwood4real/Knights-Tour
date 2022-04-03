// Alexander Wood
// Assignment 7
// CSE 310 - Nakamura
// T TH 10:30-11:45

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings
#pragma once

// struct Node represents some node for a graph
struct Node
{
    std::string name; // key
    int weight;
    
    struct Node * next;
};

// class LinkedList will contains a linked list of nodes
class LinkedList
{
private:
    struct Node * head;
    
public:
    LinkedList();
    bool addNode(int, std::string); // insert node at end of Linked List
    void printList(); // will print each publication in the current linked list
    bool moveUp(); // used for dequeue
    // defined getters for queue mostly
    Node* getHead();
};

// constructor
LinkedList::LinkedList()
{
    // set head to NULL
    head = NULL;
}

// inserting from the back
bool LinkedList::addNode(int weight, std::string name)
{
    // create new node
    Node * newNode = new Node();
    
    // set name and weight for node
    newNode->name = name;
    newNode->weight = weight;
    
    // create pointer to head
    Node * curr = head;
    
    // check if the head is NULL
    if(curr == NULL)
    {
        head = newNode;
        return 1;
    }
    
    // add to the back
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newNode;
    newNode->next = NULL;
    
    // added
    return 1;
}

// printing each node in the linked list
void LinkedList::printList()
{
    // create reference to head
    Node * curr = head;
    
    // print the first node: the from or starting city
    std::cout << "From: " << curr->name << std::endl;
    
    // now will print each other one: the neighbor of the starting node
    curr = curr->next;
    while(curr != NULL)
    {
        std::cout << "To: " << curr->name << std::endl;
        curr = curr->next;
    }
}

// used to dequeue
bool LinkedList::moveUp()
{
    // checks if list is empty
    if(head == NULL)
    {
        // list is empty
        return 0;
    }
    else
    {
        // move up
        head = head->next;
        return 1;
    }
}

Node* LinkedList::getHead()
{
    return head;
}
