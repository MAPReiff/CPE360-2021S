// I pledge my honor that I have abided by the Stevens Honor System - Mitchell Reiff
#include <iostream>
#include <stdlib.h>
using namespace std;

class TreeNode {
  public:
   int data;
   TreeNode *left;
   TreeNode *right;

   TreeNode() {
	  data = 0;
	  left = NULL;
	  right = NULL;
   }
};

class BST {
  public:
   TreeNode *root;
   BST() {
	  root = NULL;
   }

   void addNode(int val) {
	  TreeNode *tmp = new TreeNode;
	  tmp->data = val;
	  if (root == NULL) {
		 root = tmp;
	  } else {
		 TreeNode *fast;
		 TreeNode *slow;
		 slow = fast = root;

		 while (fast != NULL) {
			if (fast->data == val) {
			   cout << "Value already exists, will not add " << val << endl;
			   return;
			}
			if (val < fast->data) {
			   slow = fast;
			   fast = fast->left;
			} else {
			   slow = fast;
			   fast = fast->right;
			}
		 }

		 if (val < slow->data) {
			slow->left = tmp;
		 } else {
			slow->right = tmp;
		 }
		 cout << "Added " << val << " to the BST!" << endl;
	  }
   }

   void remove(int key, TreeNode *start) {
	  if (start == NULL) {
		 cout << "Tree is empty, nothing to delete!" << endl;
		 return;
	  }
	  TreeNode *fast;
	  TreeNode *slow;
	  fast = slow = root;

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

	  if (fast->left == NULL && fast->right == NULL) {
		 //case 1
		 cout << "c1";
		 if (slow->left == fast) {
			slow->left == NULL;
			cout << "Deleting " << fast->data << endl;
			delete fast;
		 } else {
			slow->right = NULL;
			cout << "Deleting " << fast->data << endl;
			delete fast;
		 }
	  } else if (fast->left != NULL && fast->right == NULL) {
		 //case 2
		 cout << "c2";
		 if (slow->left == fast) {
			slow->left = fast->left;
			cout << "Deleting " << fast->data << endl;
			delete fast;
		 } else {
			slow->right = fast->left;
			cout << "Deleting " << fast->data << endl;
			delete fast;
		 }
	  } else if (fast->left == NULL && fast->right != NULL) {
		 //case 2
		 cout << "case 2 delete" << endl;
	  } else {
		 //case 3
		 cout << "c3";
		 int min = minValueRightSubtree(fast->right);
		 fast->data = min;
		 remove(min, fast->right);
	  }
   }

   int minValueRightSubtree(TreeNode *start) {
	  if (start == NULL) {
		 return -1;
	  } else {
		 TreeNode *tmp = start;
		 while (tmp->left != NULL) {
			tmp = tmp->left;
		 }
		 return tmp->data;
	  }
   }

   void search(int key, TreeNode *start) {
	  if (start == NULL) {
		 cout << "Value does not exist in the tree" << endl;
		 return;
	  } else {
		 if (key == start->data) {
			cout << "FOUND IT!" << endl;
			return;
		 } else if (key < start->data) {
			search(key, start->left);
		 } else {
			search(key, start->right);
		 }
	  }
   }

   void preOrder(TreeNode *start) {
	  if (start == NULL) {
		 return; //base case
	  } else {
		 //recursive loop
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
		 return; //base case
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
		 return; //base case
	  } else {
		 //LEFT
		 inOrder(start->left);
		 //ROOT
		 cout << start->data << endl;
		 //RIGHT
		 inOrder(start->right);
	  }
   }
};

int main() {
   int choice, val;
   BST myTree;

   myTree.addNode(30);
   myTree.addNode(15);
   myTree.addNode(60);
   myTree.addNode(7);
   myTree.addNode(22);
   myTree.addNode(17);
   myTree.addNode(27);
   myTree.addNode(45);
   myTree.addNode(75);

   while (1) {
	  cout << "Press 1 to add a value" << endl;
	  cout << "Press 2 for preOrder" << endl;
	  cout << "Press 3 for postOrder" << endl;
	  cout << "Press 4 for inOrder" << endl;
	  cout << "Press 5 for search" << endl;
	  cout << "Press 6 to delete" << endl;
	  cout << "Press any other key to exit" << endl;
	  cin >> choice;

	  switch (choice) {
		 case 1:
			cout << "What do you want to add?" << endl;
			cin >> val;
			myTree.addNode(val);
			break;

		 case 2:
			myTree.preOrder(myTree.root);
			break;

		 case 3:
			myTree.postOrder(myTree.root);
			break;

		 case 4:
			myTree.inOrder(myTree.root);
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

		 default:
			exit(1);
	  }
   }
}
