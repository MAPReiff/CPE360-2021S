//I pledge my honor that I have abided by the Stevens Honor Syetem - Mitchell Reiff
#include <iostream>
#include <stdlib.h> //needed for linux for exit function
#include <stdlib.h>
#include <time.h>

using namespace std;

int currentTime = 0; //store clock time in min
int totalTime = 1020; //8am-1am = 1020min

class Customer {
  public:
   int enterTime; //when they come ine
   int exitTime; //when they leave
   int waitTime; //time in line
   int orderTime; //time to wait for orders
   int orderWaitTime; //time currently waiting for order
   Customer *next;

   Customer() {
	  enterTime = currentTime;
	  exitTime = 0;
	  waitTime = 0;
	  orderTime = rand() % 6 + 1; //random 1-6min
	  orderWaitTime = 0;
	  next = NULL;
   }
};

class Queue {
  public:
   Customer *head;

   Queue() {
	  head = NULL;
   }

   //add to queue (enqueue)
   void enqueue(int enter) {
	  Customer *temp;
	  temp = new Customer;
	  temp->enterTime = enter;

	  if (head == NULL) { //check if empty
		 head = temp;
	  } else {
		 Customer *another;
		 another = head;
		 while (another->next != NULL) { //while the next one is not NULL
			another = another->next; //set another to the next sub pointer
		 }
		 another->next = temp; //set the next sub pointer to be temp
		 temp->next = NULL;
		 //  cout << "Added " << x << " to the queue!" << endl;
	  }
   }

   void dequeue() {
	  if (head == NULL) { //check if queue is empty
		 //  cout << "The queue is empty, nothing to delete" << endl;
	  } else {
		 Customer *temp;
		 temp = head; //grab address of first Node
		 head = head->next; //head moves to next Node
		 //  cout << "Deleted " << temp->value << " from the queue!" << endl;
		 delete temp; //kills values stored in temp
	  }
   }

   int queueSize() { //check how many in line
	  Customer *temp;
	  temp = head;
	  int length = 0;

	  while (temp != NULL) {
		 length++;
		 temp = temp->next; //set temp to next sub pointer
	  }
	  return length;
   }

   void waitInLine() {
	  Customer *temp;
	  temp = head->next; //head doesnt wait in line!

	  while (temp != NULL) {
		 temp->waitTime = temp->waitTime + 1; //add 1 min to their wait
		 temp = temp->next; //set temp to next sub pointer
	  }
   }

   void waitOrder() {
	  Customer *temp;
	  temp = head;

	  temp->orderWaitTime = temp->orderWaitTime + 1;
   }

   bool orderReady() {
	  Customer *temp;
	  temp = head;
	  if (temp->orderTime = temp->orderWaitTime) {
		 return true;
	  } else {
		 return false;
	  }
   }
};

int main() {
   int spawn;
   Queue line;
   srand(time(NULL)); //seed random with timestamp of run

   int totalWait = 0;
   int totalService = 0;
   int totalCustomers = 0;

   int avgWait = 0;
   int avgService = 0;
   int averageLineLength = 0;

   int leastWait[2] = {0, 0};
   int leastService[2] = {0, 0};
   int leaseLineLenghth[2] = {0, 0};

   int mostWait[2] = {0, 0};
   int mostService[2] = {0, 0};
   int mostLineLenghth[2] = {0, 0};

   int lineSize = 0;

   while (currentTime < totalTime) { //while it is in the allowed time
	  // if (currentTime != 0) {
	  currentTime++; //add a min
	  cout << currentTime << endl;
	  cout << "hit" << endl;

	  // int lineSize = line.queueSize();

	  if (lineSize != 0) {
		 //operate on existing customers in line
		 line.waitInLine(); //add 1 min to each person in line (excludes the head)
		 if (line.orderReady()) { //if the order is ready
			line.dequeue(); //kick head off, new head ready
		 } else { //if order not ready
			line.waitOrder(); //add 1 min to person in fron order wait
		 }
	  }

	  // check if someone new will spawn
	  if (currentTime <= 120) { //8am-10am = 2h = 120m
		 //0.3 prob
		 spawn = rand() % 100 + 1;
		 if (spawn <= 30) {
			line.enqueue(currentTime);
			totalCustomers++;
			lineSize++;
		 }
	  } else if (
		  currentTime > 120 && currentTime <= 210) { //10-11:30=1.5h 120+90=210
		 //0.1 prob
		 spawn = rand() % 100 + 1;
		 if (spawn <= 10) {
			line.enqueue(currentTime);
			totalCustomers++;
			lineSize++;
		 }
	  } else if (
		  currentTime > 210 && currentTime <= 330) { //11:30-1:30=2h 210+120=330
		 //0.4 prob
		 spawn = rand() % 100 + 1;
		 if (spawn <= 40) {
			line.enqueue(currentTime);
			totalCustomers++;
			lineSize++;
		 }
	  } else if (
		  currentTime > 330 && currentTime <= 570) { //1:30-5:30=4h 330+240=570
		 //0.1 prob
		 spawn = rand() % 100 + 1;
		 if (spawn <= 10) {
			line.enqueue(currentTime);
			totalCustomers++;
			lineSize++;
		 }
	  } else if (
		  currentTime > 570 && currentTime <= 720) { //5:30-8=2.5h 570+150=720
		 //0.25 prob
		 spawn = rand() % 100 + 1;
		 if (spawn <= 25) {
			line.enqueue(currentTime);
			totalCustomers++;
			lineSize++;
		 }
	  } else if (
		  currentTime > 720 && currentTime <= 900) { //8-11=3h 720+180=900
		 //0.2 prob
		 spawn = rand() % 100 + 1;
		 if (spawn <= 20) {
			line.enqueue(currentTime);
			totalCustomers++;
			lineSize++;
		 }
	  } else if (
		  currentTime > 900 && currentTime <= 1020) { //11-1am=2h 900+120=1020
		 //0.1 prob
		 spawn = rand() % 100 + 1;
		 if (spawn <= 10) {
			line.enqueue(currentTime);
			totalCustomers++;
			lineSize++;
		 }
	  }
	  // //end spawn checking

	  // //logic
	  // //
	  // // }
   }
}