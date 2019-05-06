#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
public:
	Node(){ }
	Node(int entry) {
		data = entry;
		left = NULL;
		right = NULL;
	}
};

class BinarySearchTree {
public:
	Node *root;
public:
	BinarySearchTree(){
		root = NULL;	
	}
	void insert(Node *entry, int data){ 
		//cout << "inserting elements : " << data << endl;
		Node *parent = search(entry, data);
		Node *child = new Node(data);
		//cout << "adding " << child << " to " << parent << endl;
		if (root == NULL) {
			root = child;
			//cout << "root is " << child << endl;
		} else if (data < parent->data) {
			parent->left = child;
		} else if (data > parent->data) {
			parent->right = child;
		} else {
			cout << "Something wrong!" << endl;
		}
	}
	Node *search(Node *entry, int data){
		if (root == NULL){
			//cout << "root! " << root << endl;
			return root;
		} else if (entry->left != NULL && data < entry->data) {
			//cout << "visiting elements : " << entry->data << endl;
			return search(entry->left, data);
		} else if (entry->right != NULL && data > entry->data) {
			//cout << "visiting elements : " << entry->data << endl;
			return search(entry->right, data);
		} else {
			//cout << "visiting elements : " << entry->data << endl;
			return entry;
		}
	}
public:
	bool compare(Node *entry, Node *other) const{
		//cout << "comparing " << entry->data << " with " << other->data << endl;

		if (entry->data != other->data)
			return false;

		if (entry->left != NULL && other->left != NULL && entry->right != NULL && other->right != NULL)	
			return compare(entry->left, other->left) && compare(entry->right, other->right);	
		else if (entry->left != NULL && other->left != NULL && entry->right == NULL && other->right == NULL)	
			return compare(entry->left, other->left);
		else if (entry->left == NULL && other->left == NULL && entry->right != NULL && other->right != NULL)	
			return compare(entry->right, other->right);
		else if (entry->left == NULL && other->left == NULL && entry->right == NULL && other->right == NULL)	
			return entry->data == other->data; // return true
	}
};

void Swap(int *array, int startind, int endind) {
	int temp = array[startind];
	array[startind] = array[endind];
	array[endind] = temp;
}

void Permutate(int keys[], int swapind, int length, BinarySearchTree *bst, int *identical) {
	if (swapind == length - 1){
		/*BinarySearchTree *bst2 = new BinarySearchTree();
		for (int i = 0; i < length; i++) {
			bst2->insert(bst2->root, keys[i]);
			//cout << bst->search(bst->root, keys[i])->data << endl;
		}
		if(bst->compare(bst->root, bst2->root))
			(*identical)++;

		delete bst2;*/
		return;
	}
	
	for (int i = 0; swapind + i < length ; i++) {
		Swap(keys, swapind, swapind + i);
		//cout << swapind << "-" << swapind + i << endl;
		Permutate(keys, swapind + 1, length, bst, identical);
		for (int j = 0 ; j < length; j++)
			cout << keys[j] << ", ";
		cout << endl;
		Swap(keys, swapind, swapind + i);
	}
}


int FindTheNumberOfPermutationProducingIdenticalBinarySearchTree(int *keys, int keysize) {
	BinarySearchTree *bst = new BinarySearchTree();
	for (int i = 0; i < keysize; i++) {
		bst->insert(bst->root, keys[i]);
		//cout << bst->search(bst->root, keys[i])->data << endl;
	}
	/* test
	int temp[5]= {2, 1, 3, 4, 5};
	BinarySearchTree *bst2 = new BinarySearchTree();
	for (int i = 0; i < keysize; i++) {
		bst2->insert(bst2->root, temp[i]);
		//cout << bst->search(bst->root, keys[i])->data << endl;
	}
	if (bst->compare(bst->root, bst2->root))
		cout << "bst is equal to bst2" << endl;

	delete bst2;
	*/
	int identical = 0, swapind = 0;
	Permutate(keys, swapind, keysize, bst, &identical);
	delete bst;
	
	return identical;
}

void CaseTest(){
	int cases, *answers;
	cin >> cases;
	answers = new int[cases];
	for (int i = 0 ; i < cases; i++) {
		int keysize;
		cin >> keysize;
		int *keys = new int[keysize];
		for (int j = 0 ; j < keysize; j++){
			cin >> keys[j];
		}
		cout << "call finder" << endl;
		answers[i] = FindTheNumberOfPermutationProducingIdenticalBinarySearchTree(keys, keysize);
		delete[] keys;
	}
	for (int i = 0 ; i < cases; i++)
		cout << answers[i] << endl;
	delete[] answers;
}
int main(){
	int keys[3] =  {1, 2,3};
	//int keys[5]= {2, 1, 4, 3, 5};
	//int keys[4]= {2, 4, 1, 3};
	//int keys[12]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	cout << FindTheNumberOfPermutationProducingIdenticalBinarySearchTree(keys, 3);
	//CaseTest();
	return 0;
}
