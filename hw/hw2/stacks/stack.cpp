//I pledge my honor that I have abided by the Stevens Honor System - Mitchell Reiff
#include <iostream>
#include <stdlib.h> //needed for exit function on linux
using namespace std;

class Node {
  public:
   int value;
   Node *next; //pointer for next node

   Node() {
	  value = 0; //default value
	  next = NULL; //next pointer default to NULL
   }
};

class Stack {
  public:
   Node *top;
   Stack() {
	  top = NULL; //top points to null
   }
   //adding to stack
   void push(int x) {
	  Node *temp = new Node;
	  temp->value = x; //temp's value = input

	  if (top == NULL) { //check if first
		 top = temp;
	  } else {
		 temp->next = top;
		 top = temp;
	  }
	  cout << "Added " << x << " to the stack!" << endl;
   }

   //removing from stack
   void pop() {
	  if (top == NULL) {
		 cout << "Nothing to pop" << endl;
	  } else {
		 Node *temp;
		 temp = top;
		 top = top->next;
		 cout << "Deleted " << temp->value << " from the stack!" << endl;
		 delete temp;
	  }
   }

   //listing the stack
   void displayContents() {
	  Node *temp = top;
	  while (temp != NULL) {
		 cout << temp->value << " ---> ";
		 temp = temp->next;
	  }
	  cout << "NULL" << endl; //add NULL to represent last pointer
   }
};

int main() {

   Stack myStack;
   int input;
   int x;
   while (1) {
	  cout << "Press 1 to push to the stack" << endl;
	  cout << "Press 2 to pop from the stack" << endl;
	  cout << "Press 3 to display contents of the stack" << endl;
	  cout << "Press anything else to quit" << endl;
	  cin >> input;

	  switch (input) {
		 case 1: //push
			cout << "What to push?" << endl;
			cin >> x;
			myStack.push(x);
			break;
		 case 2: //pop
			myStack.pop();
			break;
		 case 3: //display
			myStack.displayContents();
			break;
		 default: //kills program
			cout << "Bye bye!" << endl;
			exit(1);
	  }
   }
}