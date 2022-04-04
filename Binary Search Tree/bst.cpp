#include <iostream>

using namespace std;

class TreeNode {
public:
	int data;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int d) : data(d), left(NULL), right(NULL){}
};

TreeNode* insert(TreeNode* root, int val) {
	if (root == NULL) {
		return new TreeNode(val);
	}
	if (val <= root->data) {
		root->left = insert(root->left, val);
	}
	else {
		root->right = insert(root->right, val);
	}
	
	return root; 
}

void print(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	
	print(root->left);
	cout << root->data << ' ';
	print(root->right);
}

bool search(TreeNode* root, int val) {
	if (root == NULL) {
		return false;
	}
	if (root->data == val) {
		return true;
	}
	else if (root->data < val) {
		return search(root->right, val);
	}
	else {
		return search(root->left, val);
	}
}

TreeNode* findMin(TreeNode* root) {
	while (root->left != NULL) {
		root = root->left;
	}
	return root;
}

TreeNode* remove(TreeNode* root, int val) {
	if (root == NULL) {
		return NULL;
	}
	else if (root->data > val) {
		root->left = remove(root->left, val);
	}
	else if (root->data < val) {
		root->right = remove(root->right, val);
	}
	else {
		if (root->left == NULL and root->right == NULL) {
			delete root;
			root = NULL;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root;
			root = root->left;
			delete temp;
		}
		else if (root->left == NULL) {
			TreeNode* temp = root;
			root = root->right;
			delete temp;
		}
		else {
			TreeNode* temp = findMin(root->right);
			root->data = temp->data;
			root->right = remove(root->right, temp->data);
		}
	}
	return root;
}

int main() {
	
	TreeNode* root = NULL;
	int a[] = {1, 4, 7, 2, 2, 3, 8};
	for (int x : a) {
		root = insert(root, x);
	}	
	print(root);
	
}
