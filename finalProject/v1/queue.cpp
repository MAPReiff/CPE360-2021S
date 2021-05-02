//I pledge my honor that I have abided by the Stevens Honor Syetem - Mitchell Reiff
#include <iostream>
#include <stdlib.h> //needed for linux for exit function
using namespace std;

class Node {
  public:
   int value;
   Node *next;

   Node() {
	  value = 0;
	  next = NULL;
   }
};

class Queue {
  public:
   Node *head;

   Queue() {
	  head = NULL;
   }

   //add to queue (enqueue)
   void enqueue(int x) {
	  Node *temp;
	  temp = new Node;
	  temp->value = x;

	  if (head == NULL) { //check if empty
		 head = temp;
	  } else {
		 Node *another;
		 another = head;
		 while (another->next != NULL) { //while the next one is not NULL
			another = another->next; //set another to the next sub pointer
		 }
		 another->next = temp; //set the next sub pointer to be temp
		 temp->next = NULL;
		 cout << "Added " << x << " to the queue!" << endl;
	  }
   }

   //remove from the queue (dequeue)
   void dequeue() {
	  if (head == NULL) { //check if queue is empty
		 cout << "The queue is empty, nothing to delete" << endl;
	  } else {
		 Node *temp;
		 temp = head; //grab address of first Node
		 head = head->next; //head moves to next Node
		 cout << "Deleted " << temp->value << " from the queue!" << endl;
		 delete temp; //kills values stored in temp
	  }
   }

   //display queue contents
   void printContents() {
	  Node *temp;
	  temp = head;

	  while (temp != NULL) {
		 cout << temp->value << " ---> "; //print value
		 temp = temp->next; //set temp to next sub pointer
	  }
	  cout << "NULL" << endl; //print null at end
   }

   int queueSize() { //check how many in line
	  Node *temp;
	  temp = head;
	  int length = 0;

	  while (temp != NULL) {
		 length++;
		 temp = temp->next; //set temp to next sub pointer
	  }
	  return length;
   }
};

int main() {

   Queue Q;
   int input;
   int x;

   while (1) {
	  cout << "Press 1 to enqueue" << endl;
	  cout << "Press 2 to dequeue" << endl;
	  cout << "Press 3 to display the queue" << endl;
	  cout << "Press 4 to display the queue length" << endl;
	  cout << "Press anything else to quit" << endl;
	  cin >> input;

	  switch (input) {
		 case 1:
			cout << "What to enqueue?" << endl;
			cin >> x;
			Q.enqueue(x);
			break;
		 case 2:
			Q.dequeue();
			break;
		 case 3:
			Q.printContents();
			break;
		 case 4:
			cout << Q.queueSize() << endl;
			break;
		 default:
			cout << "Bye bye!" << endl;
			exit(1);
	  }
   }
}
