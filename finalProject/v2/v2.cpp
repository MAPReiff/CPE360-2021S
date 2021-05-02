#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int storeClock;

class Customer {
  public:
   int inTime;
   int outTime;
   int waitTime;
   int orderTime;
   Customer *next;

   Customer() {
	  inTime = storeClock; //when they come in
	  outTime = 0; //dont know yet
	  waitTime = 0; //dont know yet
	  orderTime = rand() % 6 + 1; //how long their order is 1-6min
	  next = NULL;
   }
};

class Queue {
  public:
   Customer *head;

   Queue() {
	  head = NULL;
   }

   void enqueue() {
	  Customer *temp = new Customer();
	  //code for qneue to add customer to the queue
	  cout << "Just added a new customer to line: " << temp->inTime
		   << " and order: " << temp->orderTime << endl;


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
	  }
   }

   void dequeue() {
	  if (head == NULL) { //check if queue is empty
		 cout << "The queue is empty, nothing to delete" << endl;
	  } else {
		 Customer *temp;
		 temp = head; //grab address of first Node
		 head = head->next; //head moves to next Node
		 cout << "At time " << storeClock << " a customer is leaving!" << endl;
		 delete temp; //kills values stored in temp
	  }
   }

   //  int queueSize() { //check how many in line
   //  }
};

int main() {
   srand(time(NULL));
   Queue myStore;

   int customerCount = 0;
   int queueLength = 0;
   int waitTimeSum = 0;
   int serviceTimeSum = 0;
   int minWaitTime = 99999;
   int maxWaitTime = -1;
   int minServiceTime = 99999;
   int maxServiceTime = -1;
   int spawnRand;


   while (storeClock < 1020) { //while less than 1020min (8am-1am)
	  storeClock++; //add a min
	  if (storeClock <= 120) {
		 //lets check if a new customer will spawn
		 spawnRand = rand() % 100 + 1;

		 if (spawnRand <= 30) {
			//spawn a new customer
			cout << "At time " << storeClock << " we have 1 new customer!"
				 << endl;
			customerCount++;
			myStore.enqueue();
		 }

		 else {
			cout << "No new customer at time " << storeClock << endl;
		 }
	  }

	  else if (storeClock > 120 && storeClock <= 210) {
		 //lets check if a new customer will spawn
		 spawnRand = rand() % 100 + 1;
		 if (spawnRand <= 10) {
			//spawn a new customer
			cout << "At time " << storeClock << " we have 1 new customer!"
				 << endl;
			customerCount++;
			myStore.enqueue();
		 } else {
			cout << "No new customer at time " << storeClock << endl;
		 }
	  } else if (storeClock > 210 && storeClock <= 330) {
		 //lets check if a new customer will spawn
		 spawnRand = rand() % 100 + 1;
		 if (spawnRand <= 40) {
			//spawn a new customer
			cout << "At time " << storeClock << " we have 1 new customer!"
				 << endl;
			customerCount++;
			myStore.enqueue();
		 } else {
			cout << "No new customer at time " << storeClock << endl;
		 }
	  } else if (storeClock > 330 && storeClock <= 570) {
		 //lets check if a new customer will spawn
		 spawnRand = rand() % 100 + 1;
		 if (spawnRand <= 10) {
			//spawn a new customer
			cout << "At time " << storeClock << " we have 1 new customer!"
				 << endl;
			customerCount++;
			myStore.enqueue();
		 } else {
			cout << "No new customer at time " << storeClock << endl;
		 }
	  } else if (storeClock > 570 && storeClock <= 720) {
		 //lets check if a new customer will spawn
		 spawnRand = rand() % 100 + 1;
		 if (spawnRand <= 25) {
			//spawn a new customer
			cout << "At time " << storeClock << " we have 1 new customer!"
				 << endl;
			customerCount++;
			myStore.enqueue();
		 } else {
			cout << "No new customer at time " << storeClock << endl;
		 }
	  } else if (storeClock > 720 && storeClock <= 900) {
		 //lets check if a new customer will spawn
		 spawnRand = rand() % 100 + 1;
		 if (spawnRand <= 20) {
			//spawn a new customer
			cout << "At time " << storeClock << " we have 1 new customer!"
				 << endl;
			customerCount++;
			myStore.enqueue();
		 } else {
			cout << "No new customer at time " << storeClock << endl;
		 }
	  } else if (storeClock > 900 && storeClock <= 1020) {
		 //lets check if a new customer will spawn
		 spawnRand = rand() % 100 + 1;
		 if (spawnRand <= 25) {
			//spawn a new customer
			cout << "At time " << storeClock << " we have 1 new customer!"
				 << endl;
			customerCount++;
			myStore.enqueue();
		 } else {
			cout << "No new customer at time " << storeClock << endl;
		 }
	  }

	  else {
		 //late night
	  }

	  if (myStore.head != NULL) {
		 if (myStore.head->orderTime == 0) {
			cout << "Customer departing" << endl;
			myStore.dequeue();
		 } else {
			myStore.head->orderTime--;
		 }
	  }

	  //1. is a new person going to spawn?
	  //		if yes, enqueue
	  //2. is a new customer done with an order this min?
	  //		if yes, dequeue
	  //3. check vital states: wait time, service time, queue length
   }


   //this is when you get to print the final stats
   //1. avg customer wait time
   //2. avg customer service time
   //3. avg queue length
   //4. best and worst case and WHEN it happened
}
