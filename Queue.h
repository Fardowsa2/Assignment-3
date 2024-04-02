#pragma once
#include <iostream>
#include <vector>

using namespace std;

// Structure to represent an object in the queue
template <typename T> struct Node {
    T value;        // Value of the node
    Node<T>* next;  // Pointer to the next node

    // Constructor to initialize node with a value
    Node(T val) : value(val), next(nullptr) {}
};

// Queue class for storing elements in First-In-First-Out order
template <typename T> class Queue {
private:
    Node<T>* head;   // Pointer to the head of the queue
    Node<T>* tail;   // Pointer to the tail of the queue
    int num_items;   // Number of items in the queue

public:

// Constructor to initialize an empty queue
Queue() : head(nullptr), tail(nullptr), num_items(0) {}

// Print all elements in the queue
  void printQueue();

// Move the front element to the rear of the queue
  void move_rear();

// Perform insertion sort on the queue
  void wrapper();

// Perform modified linear search on the queue
  int last(T& target);

// Add an element to the rear of the queue
    void push(const T& item);

// Remove and return the element from the front of the queue
    void pop();

// Get the element at the front of the queue without removing it
    T front();

// Check if the queue is empty
    bool empty();

private:
    
// Helper function for insertion sort
    void insertion_sort(vector <T>& num);

// Helper function for modified linear search
    int modified_linear(T& target, Node<T>* pos_first, int spot, int max);
};

// Remove and return the element from the front of the queue
template <typename T>
void Queue<T>::pop() {
    if (head == nullptr) {
        tail = nullptr;
        cout << "Queue is empty. Cannot perform pop operation." << endl;
        return;
    }

    Node<T>* temp = head;
    head = head->next;
    delete temp;

    num_items--;
}

// Perform insertion sort on the queue
template <typename T>
void Queue<T>::wrapper() {
    vector<T> v;
    Node<T>* temp = head;
    while (temp != nullptr) {
        v.push_back(temp->value);
        temp = temp->next;
    }
    insertion_sort(v);

    temp = head;
    for (int i = 0; i < v.size(); i++) {
        temp->value = v[i];
        temp = temp->next;
    }
}

// Add an element to the rear of the queue
template <typename T>
void Queue<T>::push(const T& item) {
    Node<T>* new_node = new Node<T>(item);
    if (head == nullptr) {
        tail = new_node;
        head = new_node;
    }
    else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

// Get the element at the front of the queue without removing it
template <typename T>
T Queue<T>::front() {
    if (head == nullptr) {
        cout << "Queue is empty." << endl;
        return T();
    }

    return head->value;
}

// Check if the queue is empty
template <typename T>
bool Queue<T>::empty() {
    return head == nullptr;
}

// Print all elements in the queue
template <typename T>
void Queue<T>::printQueue() {
    Node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Move the front element to the rear of the queue
template <typename T>
void Queue<T>::move_rear() {
    push(front());
    pop();
}

// Helper function for insertion sort
template <typename T>
void Queue<T>::insertion_sort(vector <T>& num) {
    int i, j;
    T key;
    bool insertionNeeded = false;
    for (j = 1; j < num.size(); j++) {
        key = num[j];
        insertionNeeded = false;
        for (i = j - 1; i >= 0; i--) {
            if (key < num[i]) {
                num[i + 1] = num[i];
                insertionNeeded = true;
            }
            else
                break;
        }
        if (insertionNeeded) num[i + 1] = key;
    }
}

// Helper function for modified linear search
template <typename T>
int Queue<T>::modified_linear(T& target, Node<T>* pos_first, int spot, int max) {
    if (pos_first->value == target) {
        max = spot;
    }
    if (pos_first->next == nullptr) {
        return max;
    }
    else {
        return modified_linear(target, pos_first->next, spot + 1, max);
    }
}

// Perform modified linear search on the queue
template <typename T>
int Queue<T>::last(T& target) {
    return modified_linear(target, head, 0, 0);
}
