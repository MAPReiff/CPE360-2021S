// I pledge my honor that I have abided by the Stevens Honor System - Mitchell Reiff
#include <iostream>
#include <stdlib.h> //needed for linux for exit function
using namespace std;

class TreeNode {
  public:
   int data;
   TreeNode *left;
   TreeNode *right;

   TreeNode() {
	  left = NULL;
	  right = NULL;
	  data = 0;
   }
};

class BST {
  public:
   TreeNode *root;

   BST() {
	  root = NULL;
   }

   void addNode(int value) {

	  TreeNode *temp = new TreeNode;
	  temp->data = value;

	  if (root == NULL) {
		 root = temp;
	  } else {
		 TreeNode *slow;
		 TreeNode *fast;
		 slow = fast = root;

		 while (fast != NULL) {
			if (fast->data == value) {
			   cout << "Value already exists, will not add " << value << endl;
			   return;
			}
			if (value < fast->data) {
			   slow = fast;
			   fast = fast->left;
			} else {
			   slow = fast;
			   fast = fast->right;
			}
		 }
		 if (value < slow->data) {
			slow->left = temp;
		 } else {
			slow->right = temp;
		 }
	  }
	  cout << "Added " << value << " to the BST" << endl;
   }

   void search(int key, TreeNode *start) {
	  if (start == NULL) {
		 cout << "Value does not exist in the tree" << endl;
		 return;
	  } else {
		 if (key == start->data) {
			cout << "Found " << start->data << endl;
			return;
		 } else if (key < start->data) {
			search(key, start->left);
		 } else {
			search(key, start->right);
		 }
	  }
   }

   void remove(int key, TreeNode *start) {
	  if (start == NULL) {
		 cout << "Tree is empty, nothing to delete!" << endl;
		 return;
	  }

	  TreeNode *slow;
	  TreeNode *fast;
	  slow = fast = root;

	  while (fast != NULL && fast->data != key) {
		 if (key < fast->data) {
			slow = fast;
			fast = fast->left;
		 } else {
			slow = fast;
			fast = fast->right;
		 }
	  }

	  if (fast == NULL) {
		 cout << "Value not found, nothing to delete" << endl;
		 return;
	  }

	  if (fast->left == NULL && fast->right == NULL) { //case 1
		 cout << "Case 1" << endl;

		 if (slow->left == fast) {
			slow->left = NULL;
			cout << "Deleting: " << fast->data << endl;
			delete fast;
		 } else {
			slow->right = NULL;
			cout << "Deleting: " << fast->data << endl;
			delete fast;
		 }
	  } else if (fast->left != NULL && fast->right == NULL) { //case 2
		 cout << "Case 2" << endl;

		 if (slow->left == fast) {
			slow->left = fast->left;
			cout << "Deleting: " << fast->data << endl;
			delete fast;
		 } else {
			slow->right = fast->left;
			cout << "Deleting: " << fast->data << endl;
			delete fast;
		 }
	  } else if (fast->left == NULL && fast->right != NULL) { //case 2
		 cout << "Case 2" << endl;

		 if (slow->left == fast) {
			slow->left = fast->left;
			cout << "Deleting: " << fast->data << endl;
			delete fast;
		 } else {
			slow->right = fast->left;
			cout << "Deleting: " << fast->data << endl;
			delete fast;
		 }
	  } else { //case 3
		 cout << "Case 3" << endl;

		 int minVal = miniValueRightSubtree(fast->right);
		 cout << "Replacing "
			  << " with " << minVal << endl;
		 remove(minVal, fast->right);
		 fast->data = minVal;
	  }
   }

   int miniValueRightSubtree(TreeNode *start) {
	  if (start == NULL) {
		 return -1;
	  } else {
		 TreeNode *temp = start;
		 while (temp->left != NULL) {
			temp = temp->left;
		 }
		 return temp->data;
	  }
   }

   void preOrder(TreeNode *start) {
	  if (start == NULL) {
		 return;
	  } else {
		 //ROOT
		 cout << start->data << endl;
		 //LEFT
		 preOrder(start->left);
		 //RIGHT
		 preOrder(start->right);
	  }
   }

   void postOrder(TreeNode *start) {
	  if (start == NULL) {
		 return;
	  } else {
		 //LEFT
		 postOrder(start->left);
		 //RIGHT
		 postOrder(start->right);
		 //ROOT
		 cout << start->data << endl;
	  }
   }

   void inOrder(TreeNode *start) {
	  if (start == NULL) {
		 return;
	  } else {
		 //LEFT
		 inOrder(start->left);
		 //ROOT
		 cout << start->data << endl;
		 //RIGHT
		 inOrder(start->right);
	  }
   }

   int height(TreeNode *start) {
	  if (start == NULL) {
		 return 0;
	  } else {
		 int heightRight = height(start->right);
		 int heightLeft = height(start->left);
		 if (heightRight > heightLeft) {
			return heightRight + 1;
		 } else {
			return heightLeft + 1;
		 }
	  }
   }

   void deleteTree(TreeNode *start) {
	  if (start == NULL) {
		 return;
	  } else {
		 deleteTree(start->left);
		 deleteTree(start->right);
		 delete start;
		 start = NULL;
	  }
   }

   int minVal(TreeNode *start) {
	  if (start == NULL) {
		 return 0;
	  } else {
		 while (start->left != NULL) {
			start = start->left;
		 }
		 return start->data;
	  }
   }

   int maxVal(TreeNode *start) {
	  if (start == NULL) {
		 return 0;
	  } else {
		 while (start->right != NULL) {
			start = start->right;
		 }
		 return start->data;
	  }
   }

   bool treeBalance(TreeNode *start) {
	  if (start == NULL) {
		 return true;
	  } else { //easy balance check if heights of left and right are close
		 int heightRight = height(start->right);
		 int heightLeft = height(start->left);

		 if (treeBalance(start->left) && treeBalance(start->right) &&
			 abs(heightRight - heightLeft) <= 1) {
			return true;
		 } else {
			return false;
		 }
	  }
   }
};

int main() {
   int choice, val;
   BST myTree;

   // dummy testing values
   myTree.addNode(30);
   myTree.addNode(15);
   myTree.addNode(60);
   myTree.addNode(7);
   myTree.addNode(22);
   myTree.addNode(17);
   myTree.addNode(27);
   myTree.addNode(45);
   myTree.addNode(75);
   myTree.addNode(100);
   myTree.addNode(200);
   myTree.addNode(250);

   while (1) {
	  cout << "Press 1 to add a value" << endl;
	  cout << "Press 2 for preOrder" << endl;
	  cout << "Press 3 for postOrder" << endl;
	  cout << "Press 4 for inOrder" << endl;
	  cout << "Press 5 for search" << endl;
	  cout << "Press 6 to delete" << endl;
	  cout << "Press 7 to get the height of the tree" << endl;
	  cout << "Press 8 to delete the entire tree" << endl;
	  cout << "Press 9 for the min value" << endl;
	  cout << "Press 10 for the max value" << endl;
	  cout << "Press 11 to see if the tree is balanced" << endl;
	  cout << "Press any other key to exit" << endl;
	  cin >> choice;

	  switch (choice) {
		 case 1:
			cout << "What do you want to add?" << endl;
			cin >> val;
			myTree.addNode(val);
			break;

		 case 2:
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			myTree.preOrder(myTree.root);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;

		 case 3:
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			myTree.postOrder(myTree.root);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;

		 case 4:
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			myTree.inOrder(myTree.root);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			break;

		 case 5:
			cout << "What are you searching for?" << endl;
			cin >> val;
			myTree.search(val, myTree.root);
			break;

		 case 6:
			cout << "What do you want to delete?" << endl;
			cin >> val;
			myTree.remove(val, myTree.root);
			break;

		 case 7:
			cout << "The height of the tree is " << myTree.height(myTree.root)
				 << endl;
			break;

		 case 8:
			myTree.deleteTree(myTree.root);
			myTree.root = NULL; //clean up. not  in function b/c recursion
			cout << "You just deleted the entire tree!" << endl;
			break;

		 case 9:
			cout << "The smallest value in the tree is: "
				 << myTree.minVal(myTree.root) << endl;
			break;

		 case 10:
			cout << "The largest value in the tree is: "
				 << myTree.maxVal(myTree.root) << endl;
			break;

		 case 11:
			if (myTree.treeBalance(myTree.root)) {
			   cout << "The tree is balanced!" << endl;
			} else {
			   cout << "The tree is not balanced!" << endl;
			}
			break;

		 default:
			exit(1);
	  }
   }
}
