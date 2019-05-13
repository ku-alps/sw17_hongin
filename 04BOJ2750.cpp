#include <iostream>
using namespace std;
void swap(int *arr, int i, int j){
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

int split(int *arr, int first, int last, int init){
	int i;
	// send initial pivot to the end of array
	swap(arr, init, last);
	int left = first, right = last - 1, pivot = last;
	while (left <= right) {
		while (arr[left] < arr[pivot] && left <= last)
			left++;
		while (arr[right] > arr[pivot] && right >= 0)
			right--;
		if (left <= right)
			swap(arr, left, right);
	}
	// swap pivot into correct spot
	swap(arr, left, pivot);
	return left;
}
void quicksort(int *arr, int first, int last) {
	if (first >= last)
		return;
	int pivot = split(arr, first, last, last);
	quicksort(arr, first, pivot - 1);
	quicksort(arr, pivot + 1, last);
}
void casetest(){
	int cases = 8;
	cin >> cases;
	int *arr = new int[cases];
	for (int i = 0 ; i < cases; i++) 
		cin >> arr[i];
	quicksort(arr, 0, cases - 1);
	for (int i = 0 ; i < cases; i++) 
		cout << arr[i] << endl;
	delete[] arr;
}
int main(){
	casetest();
}
