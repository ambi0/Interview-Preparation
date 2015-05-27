#include <iostream>
#include <algorithm> //used for std::max

struct Node{
	Node* left;
	Node* right;
	Node(int n = 0): datum_(n) {};
	int datum_;
};

int getHeight(Node*);

int main(){
	Node root;
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	root.left = n1;
	root.right = n2;
	n1->left = n3;
	n3->left = n4;
	std::cout << "The height of the binary tree is " << getHeight(&root) << std::endl;
}

//test

/*defined as the number of edges in a tree
 *from its root to its deepest leaf.
 */
int getHeight(Node* root){
	if(root == nullptr){
		return 0;
	}
	return 1 + std::max(getHeight(root->left),getHeight(root->right));
}