#include "BST.h"

int main()
{

	int arr[] = { 6, 2, 3, 4, 7, 1, 5 };

	int n = sizeof(arr) / sizeof(arr[0]);

	struct Node* root = arrayToBST(arr, 0, n - 1);

	preOrder(root);

	cout << "\n";

	root = insertInBST(root, 0);

	preOrder(root);

	cout << "\n";

	root = deleteNode(root, 0);

	preOrder(root);

	cout << "\n";
}