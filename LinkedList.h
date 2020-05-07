/* LinkedList.h
 * Header file for the Linked List class
 * Created by Dilya Anvarbekova and Teddy Hsieh
 * Last Modified: 05/06/2020
 */

#ifndef CHEATERS_LINKEDLIST_H
#define CHEATERS_LINKEDLIST_H

#include <iostream>
#include <string>
#include <vector>

struct Node{
    int data;
    Node *next;
};

class LinkedList {

private:
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }

/* Returns the value stored at the head of the list
 * Inputs:
 *      - None
 * Outputs:
 *      - Integer value of the data at the head of the list
 */
    Node *getHead();


/* Returns the value stored at the tail of the list
 * Inputs:
 *      - None
 * Outputs:
 *      - Integer value of the data at the tail of the list
 */
    Node * getTail();


/* Checks if the list is empty
 * Inputs:
 *      - None
 * Outputs:
 *      - True if the list is empty
 *      - False if the list is not empty
 */
    bool isEmpty();


/* Adds a node at the head of the list
 * Inputs:
 *      - New data to insert
 * Outputs:
 *      - None
 *      - A new node with the data is added to the head of the list
 */
    void push(int data);


/* Prints the data stored in the list
 * FOR DEBUGGING
 * Inputs:
 *      - None
 * Outputs:
 *      - Prints data values in the reverse order they were added
 */
    void showList();


/* Returns the size of the linked list
 * FOR DEBUGGING
 * Inputs:
 *      - None
 * Outputs:
 *      - Returns the size of the list
 */
    int getSize();


    void deleteList();
/* Destructor - Clears memory
 * Inputs:
 *      - None
 * Outputs:
 *      - Deleted linked list and freed memory
 */
    ~LinkedList();

};

#endif //CHEATERS_LINKEDLIST_H