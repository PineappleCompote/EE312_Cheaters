/* LinkedList.cpp
 * Methods for the Linked List class used for separate chaining
 * Created by Dilya Anvarbekova and Teddy Hsieh
 * Last Modified: 05/06/2020
 */

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int LinkedList::getHead() {
    return head->data;
}

int LinkedList::getTail() {
    return tail->data;
}

bool LinkedList::isEmpty() {
    return head == NULL;
}

void LinkedList::push(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;

    if(isEmpty()){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

void LinkedList::showList() {
    if(isEmpty()){
        cout << "EMPTY" << endl;
    }
    else{
        Node *curr = head;
        while (curr != NULL){
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
}


LinkedList::~LinkedList() {
    Node *prev;
    Node *curr = head;
    while(curr != NULL){
        prev = curr;
        curr = curr->next;
        delete prev;
    }
}