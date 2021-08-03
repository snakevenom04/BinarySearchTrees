// C++ header file containing heapsort, BST creation via per node insertion and Array input, delete BST node, 
// find min node in BST, print BST in preorder.
#include <iostream>
#include <queue>


using namespace std;


struct Node {
	int data;
	struct Node* left, * right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};



struct Node* insertInBST(struct Node* root, int data)
{
	if (root == NULL)
	{
		return new Node(data);
	}
		
	else
	{
	
		if (data <= root->data)
			root->left = insertInBST(root->left, data);
		else
			root->right = insertInBST(root->right, data);
	
		return root; //creating a tree as well so return root
	}
}

struct Node* search(struct Node* root, int key)
{
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->data == key)
		return root;

	// Key is greater than root's key
	if (root->data < key)
		return search(root->right, key);

	// Key is smaller than root's key
	return search(root->left, key);
}

struct Node* minValueNode(struct Node* Node)
{
	struct Node* current = Node;

	while (current && current->left != NULL)
		current = current->left;

	return current;
}

struct Node* deleteNode(struct Node* root, int key)
{
	// base case
	if (root == NULL)
		return root;

	// If the key to be deleted is
	// smaller than the root's
	// key, then it lies in left subtree
	if (key < root->data)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is
	// greater than the root's
	// key, then it lies in right subtree
	else if (key > root->data)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is the Node
	// to be deleted
	else {
		// Node has no child
		if (root->left == NULL and root->right == NULL)
			return NULL;

		// Node with only one child or no child
		else if (root->left == NULL) {
			struct Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct Node* temp = root->left;
			free(root);
			return temp;
		}

		// Node with two children: Get the inorder successor
		// (smallest in the right subtree)
		struct Node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this Node
		root->data = temp->data;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

void heapify(int arr[], int n, int i1)
{
	int largest = i1; // Initialize largest as root
	int l = 2 * i1 + 1; // left = 2*i + 1
	int r = 2 * i1 + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i1)
	{
		swap(arr[i1], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}


}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i1 = n / 2 - 1; i1 >= 0; i1--)
		heapify(arr, n, i1);

	// One by one extract an element from heap
	for (int i1 = n - 1; i1 > 0; i1--) {
		// Move current root to end
		swap(arr[0], arr[i1]);

		// call max heapify on the reduced heap
		heapify(arr, i1, 0);
	}
}

void preOrder(struct Node* node)
{
	if (node == NULL)
		return;
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}

struct Node* arrayToBST(int arr[], int start, int end)
{

	if (start > end)
		return NULL;

	//need to sort array for a balanced binary search tree

	heapSort(arr, end + 1);


	int mid = (start + end) / 2;
	struct Node* root = new Node(arr[mid]);


	root->left = arrayToBST(arr, start, mid - 1);

	root->right = arrayToBST(arr, mid + 1, end);

	return root;
}