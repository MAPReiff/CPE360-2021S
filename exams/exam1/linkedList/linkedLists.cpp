// I pledge my honor that I have abided by the Stevens Honor System - Mitchell Reiff
#include <iostream>
#include <stdlib.h>
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

class linkedList {
  public:
   Node *head;
   int count; //keep track of how many positions there are

   linkedList() {
	  head = NULL;
	  count = 0;
   }

   // insert at head
   void insertAtHead(int value) {
	  Node *temp;
	  temp = new Node;
	  temp->value = value;

	  temp->next = head;
	  head = temp;
	  cout << "Added " << value << " to the head!" << endl;
	  count++;
   }

   //insert at pos
   void insertAtPosition(int pos, int value) {
	  if (pos > 0 && pos <= count + 1) {
		 // if pos is more than 0 and within the count
		 Node *temp;
		 temp = new Node;
		 temp->value = value;

		 if (pos == 1) {
			// just in case someone does pos 1 instead of insertAtHead function
			temp->next = head;
			head = temp;
			cout << "Added " << value << " to the head!" << endl;
			count++;

		 } else { //pos not one
			Node *helper = head; //another temp
			for (int i = 1; i <= pos - 2; i++) {
			   helper = helper->next; //keep going deeper into list
			}
			temp->next = helper->next;
			helper->next = temp;
			cout << "Just added " << value << " at position " << pos << "!"
				 << endl;
			count++;
		 }
	  } else {
		 cout << "Invalid position, not adding this item!" << endl;
	  }
   }

   // remove from pos
   void removeFromPosition(int pos) {
	  if (pos > 0 && pos <= count) {
		 //if pos is greater than 0 and within the count
		 Node *temp;
		 temp = head;
		 if (pos == 1) {
			//if head
			int data = head->value;
			head = temp->next; // head is now the next value of temp
			cout << "Removed " << data << " at position " << pos
				 << " from the list!" << endl;
			count--;
		 } else {
			// if not head
			Node *helper = head; //another temp
			Node *helperPrev = head;

			for (int i = 1; i <= pos - 2; i++) {
			   helperPrev = helperPrev->next;
			}
			// cout << "previous: " << helperPrev->value << endl;

			for (int i = 1; i <= pos - 1; i++) {
			   helper = helper->next;
			}
			if (helper->next == NULL) {
			   //  cout << "next: NULL" << endl;
			   int data = helper->value;
			   helperPrev->next = NULL;
			   cout << "Removed " << data << " from position " << pos << endl;
			} else {
			   //  cout << "next: " << helper->next->value << endl;
			   int data = helper->value;
			   helperPrev->next = helperPrev->next->next; // next = next's next
			   cout << "Removed " << data << " from position " << pos << endl;
			}
			count--;
		 }
	  } else {
		 cout << "Invalid position, not removing anything!" << endl;
	  }
   }

   //display list
   void displayContents() {
	  Node *temp;
	  temp = head;
	  while (temp != NULL) {
		 cout << temp->value << " ---> ";
		 temp = temp->next;
	  }
	  cout << "NULL" << endl;
   }

   void reverseLinkedList() { // exam 1 question
	  Node *position = head;
	  Node *last = NULL;
	  Node *next = NULL;

	  while (position != NULL) { //while not at the end
		 next = position->next; //next is set to pointer to next
		 position->next = last; //current next is now pointing back
		 last = position; //previous is now current position
		 position = next; // move to next position
	  }
	  head = last;
   }

   void removeEveryOtherNode() { //exam 1 question
	  if (head == NULL) {
		 return; // empty list
	  }

	  Node *last = head;
	  Node *next = head->next;

	  while (next != NULL && last != NULL) { //next and last not NULL
		 last->next = next->next; // previous's next is now the next one's next
			 // I realize now this was bad var naming but I'm already this far and it works
		 last = last->next; // last node is now the next one
		 free(next); // clear the now non needed next node

		 if (last != NULL) {
			next = last->next; // if this isnt the end, next is the last's next
		 }
	  }
   }
};

int main() {
   linkedList LL;
   int value;
   int pos;
   int input;
   //  LL.insertAtHead(5); //dummy values for testing
   //  LL.insertAtHead(5);
   //  LL.insertAtHead(4);
   //  LL.insertAtHead(4);
   //  LL.insertAtHead(3);
   //  LL.insertAtHead(3);
   //  LL.insertAtHead(2);
   //  LL.insertAtHead(2);
   //  LL.insertAtHead(1);
   //  LL.insertAtHead(1);

   while (1) {
	  cout << "Press 1 to add to the head" << endl;
	  cout << "Press 2 to add at a position" << endl;
	  cout << "Press 3 to delete from a position" << endl;
	  cout << "Press 4 to display the list" << endl;
	  cout << "Press 5 to reverse the list" << endl;
	  cout << "Press 6 to remove every other element from the list" << endl;
	  cout << "Anything else to quit" << endl;
	  cin >> input;

	  switch (input) {
		 case 1:
			cout << "Add what to the head?" << endl;
			cin >> value;
			LL.insertAtHead(value);
			break;

		 case 2:
			cout << "Add what?" << endl;
			cin >> value;
			cout << "At what position?" << endl;
			cin >> pos;
			LL.insertAtPosition(pos, value);
			break;

		 case 3:
			cout << "What position to remove from?" << endl;
			cin >> pos;
			LL.removeFromPosition(pos);
			break;

		 case 4:
			LL.displayContents();
			break;

		 case 5:
			LL.reverseLinkedList();
			break;

		 case 6:
			LL.removeEveryOtherNode();
			break;

		 default:
			cout << "Bye Bye!" << endl;
			exit(1);
	  }
   }
}