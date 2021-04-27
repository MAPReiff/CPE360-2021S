#include <iostream>
#include <stdlib.h> //needed for linux for exit function
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

//BST of such treenodes
class BST {
  public:
   TreeNode *root;
   BST() {
	  root = NULL;
   }

   //1. add nodes to bst
   void addNode(int value) {
	  TreeNode *temp = new TreeNode;
	  temp->data = value;
	  //if tree is empty, make the first value the root node
	  if (root == NULL) {
		 root = temp;
	  } else {
		 TreeNode *slow, *fast;
		 slow = fast = root; //start at top

		 while (fast != NULL) {
			if (fast->data == value) { //if it already exists
			   cout << "Duplicate value, we will not add X" << endl;
			   return;
			}
			if (value < fast->data) { //if value is less than current
			   slow = fast;
			   fast = fast->left; //go left
			} else { //if value is greater than current
			   slow = fast;
			   fast = fast->right; //go right
			}
		 }
		 // this is great! Fast has now fallen off the tree
		 // we will use "slow" (new parent to be) to add a new value

		 if (value < slow->data) { //if value is less than last
			slow->left = temp; //put value to left
		 } else { //if value is greater than last
			slow->right = temp; //put value to right
		 }
		 cout << "Just added: " << value << "  to the BST!" << endl;
	  }
   }

   //2. search for a value (primary)
   void search(int key, TreeNode *start) {
	  if (start == NULL) {
		 cout << "I could not find this value in the tree" << endl;
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
   //3. delete a value from bst
   void remove(int key, TreeNode *start) {
	  if (start == NULL) {
		 cout << "Empty tree, nothing to delete" << endl;
		 return;
	  }
	  //lets try to find the value (key) and see if we can delete it
	  TreeNode *slow, *fast;
	  slow = fast = root;

	  while (fast != NULL && fast->data != key) {
		 if (key < fast->data) { //if desired is less than
			slow = fast;
			fast = fast->left;
		 } else {
			slow = fast;
			fast = fast->right;
		 }
	  }

	  //right outside this loop, we get to see if we have fallen off (not found)
	  //or if we have found the value
	  if (fast == NULL) {
		 cout << "Value not found, cannot delete" << endl;
		 return;
	  }
	  //if we are here now, the value does exist
	  //fast points to this node, and slow points to the parent of the node
	  //now we classify what kind of case we are dealing with

	  if (fast->left == NULL && fast->right == NULL) {
		 //case 1 delete
		 cout << "case 1 delete" << endl;
		 if (slow->left == fast) {
			slow->left == NULL;
			cout << "About to delete: " << fast->data << endl;
			delete fast;
		 } else {
			slow->right = NULL;
			cout << "About to delete: " << fast->data << endl;
			delete fast;
		 }

	  } else if (fast->left != NULL && fast->right == NULL) {
		 //case 2 delete
		 cout << "case 2 delete" << endl;
		 if (slow->left == fast) {
			slow->left = fast->left;
			cout << "About to delete: " << fast->data << endl;
			delete fast;
		 } else {
			slow->right = fast->left;
			cout << "About to delete: " << fast->data << endl;
			delete fast;
		 }
	  } else if (fast->left == NULL && fast->right != NULL) {
		 //case 2 delete
		 cout << "case 2 delete" << endl;
	  } else {
		 //case 3 delete
		 cout << "case 3 delete" << endl;
		 int minVal = minValueRightSubtree(fast->right);
		 //swa[ the current node with minVal
		 fast->data = minVal;
		 //we need to delete minVal from right subtree!
		 remove(minVal, fast->right);
	  }
   }

   int minValueRightSubtree(TreeNode *start) {
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

   //4. function(s) to display
   //4.1 preorder
   void preorder(TreeNode *start) {
	  if (start == NULL) {
		 //base case
		 return;
	  } else {
		 //recursive step
		 //ROOT
		 cout << start->data << endl;
		 //LEFT
		 preorder(start->left);
		 //RIGHT
		 preorder(start->right);
	  }
   }

   //4.2 post order
   void postorder(TreeNode *start) {
	  if (start == NULL) {
		 //base case
		 return;
	  } else {
		 //LEFT
		 postorder(start->left);
		 //RIGHT
		 postorder(start->right);
		 //ROOT
		 cout << start->data << endl;
	  }
   }

   //4.3 inorder
   void inorder(TreeNode *start) {
	  if (start == NULL) {
		 //base case
		 return;
	  } else {
		 //LEFT
		 inorder(start->left);
		 //ROOT
		 cout << start->data << endl;
		 //RIGHT
		 inorder(start->right);
	  }
   }
};

int main() {
   BST myTree;
   int choice, value;
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
	  cout << "Press 2 for preorder" << endl;
	  cout << "Press 3 for posorder" << endl;
	  cout << "Press 4 for inorder" << endl;
	  cout << "Press 5 for search" << endl;
	  cout << "Press 6 to delete" << endl;
	  cin >> choice;

	  switch (choice) {
		 case 1:
			cout << "What do you want to add?" << endl;
			cin >> value;
			myTree.addNode(value);
			break;
		 case 2:
			cout << "=========" << endl;
			myTree.preorder(myTree.root);
			break;
		 case 3:
			cout << "=========" << endl;
			myTree.postorder(myTree.root);
			break;
		 case 4:
			cout << "=========" << endl;
			myTree.inorder(myTree.root);
			break;
		 case 5:
			cout << "=========" << endl;
			cout << "What are you searching for?" << endl;
			cin >> value;
			myTree.search(value, myTree.root);
			break;
		 case 6:
			cout << "What value?" << endl;
			cin >> value;
			myTree.remove(value, myTree.root);
			break;


		 default:
			exit(1);
	  }
   }
}
