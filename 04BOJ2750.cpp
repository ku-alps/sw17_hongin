#include <iostream>
using namespace std;
void swap(int *arr, int i, int j){
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
//	cout << "swap : " << arr[j] << arr[i] << endl;
}

int split(int *arr, int first, int last, int init){
	// send initial pivot to the end of array
//	cout << "Split "	;
	swap(arr, init, last);
	int left = first - 1, right = last, pivot = last;
//	cout  << left << right << pivot << endl;
//	for (int i = first ; i <=last; i++) 
//		cout << arr[i];
//	cout << endl;
//	cin >> arr[pivot];	
	while (left + 1 != right) {
		while (arr[left+1] < arr[pivot]){
			left++;
//			cout << "left : " << arr[left] << endl;
		}
//		cin >> left;
		while (arr[right-1] > arr[pivot]){
			right--;
//			cout << "right : " << arr[right] << endl;
		}
		if (left + 1 == right)
			break;
		swap(arr, left + 1, right - 1);
//		for (int i = first ; i <= last; i++) 
//			cout << arr[i];
//		cout << endl;
//		cout << "pivot : " << arr[pivot];
//		cin >> arr[pivot] ;
	}
	// swap pivot into correct spot
//	cout << "last swap" <<endl;
	swap(arr, right, pivot);
//	for (int i = first ; i <= last; i++) 
//		cout << arr[i];
//	cout << endl;
	return right;
}
void quicksort(int *arr, int first, int last) {
	int pivot = split(arr, first, last, last);
	if (first < pivot - 1)
		quicksort(arr, first, pivot - 1);
	if (pivot + 1< last)
		quicksort(arr, pivot + 1, last);
}
void casetest(){
	int cases = 8;
	cin >> cases;
	int *arr = new int[cases];
	for (int i = 0 ; i < cases; i++) 
		cin >> arr[i];
	//int arr[] = {1, 5, 6, 8, 7, 2, 4, 3};
	quicksort(arr, 0, cases - 1);
	for (int i = 0 ; i < cases; i++) 
		cout << arr[i];
	delete[] arr;
}
int main(){
	casetest();
}
