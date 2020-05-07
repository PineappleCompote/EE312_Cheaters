/* LinkedList.cpp
 * Methods for the Linked List class used for separate chaining
 * Created by Dilya Anvarbekova and Teddy Hsieh
 * Last Modified: 05/06/2020
 */

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

Node *LinkedList::getHead() {
    return head;
}

Node* LinkedList::getTail() {
    return tail;
}

bool LinkedList::isEmpty() {
    return head == NULL;
}

void LinkedList::push(int data) {
    Node* temp = new Node;
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
    size += 1;
}

void LinkedList::showList() {
    if(isEmpty()){
        cout << "EMPTY" << endl;
    }
    else{
        Node *curr = head;
        while (curr != NULL){
            cout << curr->data << "  ";
            curr = curr->next;
        }
        cout << endl;
    }
}

int LinkedList::getSize() {
    return size;
}

void LinkedList::deleteList() {
    Node *current = getHead();
    Node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

LinkedList::~LinkedList(){
}