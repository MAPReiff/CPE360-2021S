#include <iostream>
using namespace std;

int getNthTermFibonacci(int n) {
   static int x = 0; // perm var x which will not be over written, first run = 0
   static int y = 1; // perm var x which will not be over written, first run = 1

   cout << x << endl;
   if (n == 0) {
	  return x + y; // if 0 return x and y
   } else {
	  int tmpA = x; //temp to keep x in
	  int tmpB = y; //temp to keep y in
	  x = tmpB; //x is not last y
	  y = tmpA + tmpB; // y is now x+y
	  getNthTermFibonacci(n - 1); // recursion
   }
   return 0;
}

int main() {
   int n = 9;
   getNthTermFibonacci(n);
}