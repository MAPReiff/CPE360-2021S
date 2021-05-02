//I pledge my Honor that I have abided by the Stevens Honor System - Mitchell Reiff
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int storeClock;

class Customer {
  public:
   int inTime; //enter at
   int outTime; //leave at
   int waitTime; //time in line
   int orderTime; //length of order
   int orderWaitTime; //same as above but not used to count
   Customer *next;

   Customer() {
	  inTime = storeClock; //when they come in
	  outTime = 0; //dont know yet
	  waitTime = 0; //dont know yet
	  orderTime = rand() % 6 + 1; //how long their order is 1-6min
	  orderWaitTime = orderTime;
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
	  Customer *tmp = new Customer();
	  //code for qneue to add customer to the queue
	  cout << "Just added a new customer to line: " << tmp->inTime
		   << " and order: " << tmp->orderTime << endl;

	  if (head == NULL) { //check if empty
		 head = tmp;
	  } else {
		 Customer *another;
		 another = head;
		 while (another->next != NULL) { //while the next one is not NULL
			another = another->next; //set another to the next sub pointer
		 }
		 another->next = tmp; //set the next sub pointer to be tmp
		 tmp->next = NULL;
	  }
   }

   void dequeue() {
	  if (head == NULL) { //check if queue is empty
		 cout << "The queue is empty, nothing to delete" << endl;
	  } else {
		 Customer *tmp;
		 tmp = head; //grab address of first Node
		 head = head->next; //head moves to next Node
		 cout << "At time " << storeClock << " a customer is leaving!" << endl;
		 delete tmp; //kills values stored in tmp
	  }
   }

   int queueSize() { //check how many in line
	  Customer *tmp;
	  tmp = head;
	  int length = 0;

	  while (tmp != NULL) {
		 length++;
		 tmp = tmp->next; //set tmp to next sub pointer
	  }
	  return length;
   }

   void waitInLine() {
	  Customer *tmp;
	  tmp = head->next;
	  while (tmp != NULL) {
		 tmp->waitTime++; //add 1 to wait time
		 tmp = tmp->next; //set tmp to next sub pointer
	  }
   }
};

int main() {
   srand(time(NULL)); //seed random with run time
   Queue myStore;

   int customerCount = 0; //total customers

   int queueLengthSum = 0; //sum of ALL lize size
   int minQueueLength[2] = {99999, 0}; //least line size
   int maxQueueLength[2] = {-1, 0}; //most line size

   int waitTimeSum = 0; //sum of ALL times in line
   int minWaitTime[2] = {99999, 0}; //least time in line
   int maxWaitTime[2] = {-1, 0}; //most time in line

   int serviceTimeSum = 0; //sum of ALL wait and order time
   int minServiceTime[2] = {99999, 0}; //least time in line + order time
   int maxServiceTime[2] = {-1, 0}; //most time in line + order time

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
	  } else if (storeClock > 120 && storeClock <= 210) {
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
		 //past closing
		 //this should never trigger due to while loop
	  }

	  if (myStore.head != NULL) { //if there is a line
		 if (myStore.head->next != NULL) {
			myStore.waitInLine(); //add 1 min all wait times execpt head
		 }
	  }


	  if (myStore.head != NULL) { //if someone is at head
		 if (myStore.head->orderTime == 0) {
			cout << "Customer departing" << endl;

			int serviceTime = storeClock - myStore.head->inTime;
			int waitTime = serviceTime - myStore.head->orderWaitTime;
			int queueSize = myStore.queueSize();

			if (minWaitTime[0] > waitTime) {
			   //if record min wait is more than this
			   minWaitTime[0] = waitTime;
			   minWaitTime[1] = storeClock;
			}
			if (maxWaitTime[0] < waitTime) {
			   //if record max wait is less than this
			   maxWaitTime[0] = waitTime;
			   maxWaitTime[1] = storeClock;
			}

			if (minServiceTime[0] > serviceTime) {
			   //if record min service is more than this
			   minServiceTime[0] = serviceTime;
			   minServiceTime[1] = storeClock;
			}
			if (maxServiceTime[0] < serviceTime) {
			   //if record max service is less than this
			   maxServiceTime[0] = serviceTime;
			   maxServiceTime[1] = storeClock;
			}

			if (minQueueLength[0] > queueSize) {
			   //if record min queue is more than this
			   minQueueLength[0] = queueSize;
			   minQueueLength[1] = storeClock;
			}
			if (maxQueueLength[0] < queueSize) {
			   //if record max queue is less than this
			   maxQueueLength[0] = queueSize;
			   maxQueueLength[1] = storeClock;
			}

			//add current values to sum vars
			waitTimeSum += waitTime;
			serviceTimeSum += serviceTime;
			queueLengthSum += queueSize;

			myStore.dequeue();
		 } else {
			myStore.head->orderTime--;
		 }
	  }
   }

   //after closing, keep going till line is empty

   cout << "People in left in line at closing: " << myStore.queueSize() << endl;
   while (myStore.queueSize() != 0) {
	  storeClock++; //add a min

	  if (myStore.head != NULL) {
		 if (myStore.head->next != NULL) {
			myStore.waitInLine(); //add 1 min all wait times execpt head
		 }
	  }

	  if (myStore.head != NULL) { //if someone is at head
		 if (myStore.head->orderTime == 0) {
			cout << "Customer departing" << endl;

			int serviceTime = storeClock - myStore.head->inTime;
			int waitTime = serviceTime - myStore.head->orderWaitTime;
			int queueSize = myStore.queueSize();

			if (minWaitTime[0] > waitTime) {
			   //if record min wait is more than this
			   minWaitTime[0] = waitTime;
			   minWaitTime[1] = storeClock;
			}
			if (maxWaitTime[0] < waitTime) {
			   //if record max wait is less than this
			   maxWaitTime[0] = waitTime;
			   maxWaitTime[1] = storeClock;
			}

			if (minServiceTime[0] > serviceTime) {
			   //if record min service is more than this
			   minServiceTime[0] = serviceTime;
			   minServiceTime[1] = storeClock;
			}
			if (maxServiceTime[0] < serviceTime) {
			   //if record max service is less than this
			   maxServiceTime[0] = serviceTime;
			   maxServiceTime[1] = storeClock;
			}

			if (minQueueLength[0] > queueSize) {
			   minQueueLength[0] = queueSize;
			   minQueueLength[1] = storeClock;
			}
			if (maxQueueLength[0] < queueSize) {
			   maxQueueLength[0] = queueSize;
			   maxQueueLength[1] = storeClock;
			}

			waitTimeSum += waitTime;
			serviceTimeSum += serviceTime;
			queueLengthSum += queueSize;

			myStore.dequeue();
		 } else {
			myStore.head->orderTime--;
		 }
	  }
   }


   cout << "People in left in line: " << myStore.queueSize() << endl;

   cout << endl << "==========Avg==========" << endl;
   cout << "Avg wait time: " << (double)waitTimeSum / customerCount << endl;
   cout << "Avg service time: " << (double)serviceTimeSum / customerCount
		<< endl;
   cout << "Avg queue size: " << (double)queueLengthSum / storeClock << endl;

   cout << "==========Best==========" << endl;
   cout << "Min wait time: " << minWaitTime[0] << " at time " << minWaitTime[1]
		<< endl;
   cout << "Min service time: " << minServiceTime[0] << " at time "
		<< minServiceTime[1] << endl;
   cout << "Min queue size: " << minQueueLength[0] << " at time "
		<< minQueueLength[1] << endl;

   cout << "==========Worst==========" << endl;
   cout << "Max wait time: " << maxWaitTime[0] << " at time " << maxWaitTime[1]
		<< endl;
   cout << "Max service time: " << maxServiceTime[0] << " at time "
		<< maxServiceTime[1] << endl;
   cout << "Max queue size: " << maxQueueLength[0] << " at time "
		<< maxQueueLength[1] << endl;

   cout << "==========Total==========" << endl;
   cout << "Total wait time: " << waitTimeSum << endl;
   cout << "Total service time: " << serviceTimeSum << endl;
   cout << "Total customers: " << customerCount << endl;
}
