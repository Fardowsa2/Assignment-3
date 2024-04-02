/*
Name: Fardowsa Muhumed
Due date: 04/02/2024
Section: Tu/Thu 4:00 pm - 5:15 pm
Assignment: 3
*/

#include "Queue.h"
#include <iostream>

using namespace std;

int main() {
  // Creating a queue of integers
  Queue<int> que;

  // Pushing 10 values into the queue
  cout << "Pushing 10 values into the queue..." << endl;
  for (int i = 1; i <= 10; ++i) {
    que.push(i);
  }

  // Displaying the current contents of the queue
  cout << "Current queue: ";
  que.printQueue();
  cout << endl << endl;

  // The rest of the code remains unchanged
  // Removing an element from the front of the queue
  cout << "Removing an element from the front of the queue..." << endl;
  que.pop();
  cout << "Updated queue: ";
  que.printQueue();
  cout << endl << endl;

  // Displaying the front element of the queue
  cout << "Front element of the queue: " << que.front() << endl;
  cout << "Current queue: ";
  que.printQueue();
  cout << endl << endl;

  // Checking if the queue is empty
  cout << "Is the queue empty? " << (que.empty() ? "Yes" : "No") << endl;
  if (que.empty())
    cout << "The queue is empty." << endl;
  else
    cout << "The queue is not empty." << endl << endl;

  // Moving the first element of the queue to the end
  cout << "Moving the first element of the queue to the end..." << endl;
  que.move_rear();
  cout << "Updated queue: ";
  que.printQueue();
  cout << endl << endl;

  // Searching for the last occurrence of an item in the queue
  int j = 2;
  cout << "The last occurrence of " << j
       << " in the queue is at index: " << que.last(j) << endl
       << endl;

  // Sorting the queue using insertion sort
  cout << "Sorting the queue using insertion sort..." << endl;
  que.wrapper();
  cout << "Sorted queue: ";
  que.printQueue();

  return 0;
}
