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
};

void CountChildren(Node *root, int *howmany) {
	(*howmany)++;
	if (root->left != NULL)
		CountChildren(root->left, howmany);
	if (root->right != NULL)
		CountChildren(root->right, howmany);
}

int fact(int n) {
   if (n == 0 || n == 1)
      return 1;
   else
      return n * fact(n - 1);
}

void MultiplyCombinationOfLeftRightChildrenOnEachSubtree(Node *root, int *numberofcase) {
	int leftchildren = 0, rightchildren = 0;
	if (root->left != NULL)
		CountChildren(root->left, &leftchildren);
	if (root->right != NULL)
		CountChildren(root->right, &rightchildren);
	if (leftchildren == 0 && rightchildren == 0)
		return;
//	if (leftchildren != 0 && rightchildren != 0) {
/*		int sum = leftchildren + rightchildren;
		int smaller = leftchildren > rightchildren ? rightchildren : leftchildren;
		int bigger = leftchildren > rightchildren ? leftchildren : rightchildren;

		int numerator = sum;
		for (int i = 1 ; sum - i > bigger; i++)
			numerator *= sum - i;
	
		int demnominator = smaller;
		for (int i = 1; smaller - i > 0; i++)
			demnominator *= smaller - i;
		
		int coefficient = numerator / demnominator;	
*/
		//(*numberofcase) *= coefficient;
//	}
	int n = leftchildren + rightchildren;
	int r = leftchildren;
	int coefficient = fact(n) / (fact(r) * fact(n-r));
	
	//cout << leftchildren << " " << root->data << " " << rightchildren << " cof : " << coefficient << endl;
	(*numberofcase) *= 	coefficient;
	if (root->left != NULL)
		MultiplyCombinationOfLeftRightChildrenOnEachSubtree(root->left, numberofcase);
	if (root->right != NULL)
		MultiplyCombinationOfLeftRightChildrenOnEachSubtree(root->right, numberofcase);
}	
int FindTheNumberOfPermutationProducingIdenticalBinarySearchTree(int *keys, int keysize) {
	BinarySearchTree *bst = new BinarySearchTree();
	for (int i = 0; i < keysize; i++) {
		bst->insert(bst->root, keys[i]);
		//cout << bst->search(bst->root, keys[i])->data << endl;
	}
	int identical = 1;
	MultiplyCombinationOfLeftRightChildrenOnEachSubtree(bst->root, &identical);
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
		answers[i] = FindTheNumberOfPermutationProducingIdenticalBinarySearchTree(keys, keysize);
		delete[] keys;
	}
	for (int i = 0 ; i < cases; i++)
		cout << answers[i] % 9999991 << endl;
	delete[] answers;
}
int main(){
	//int keys[3] =  {2,1,3};
	//int keys[5]= {2, 1, 4, 3, 5};
	//int keys[4]= {2, 4, 1, 3};
	//int keys[12]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	//int keys[9]= {1, 2, 3, 4, 5, 6, 7, 8, 9};
	//int keys[10]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//cout << FindTheNumberOfPermutationProducingIdenticalBinarySearchTree(keys, 10);
	
	CaseTest();
	return 0;
}
