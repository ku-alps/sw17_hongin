#include <iostream>
using namespace std;
int merge(int *array, int start, int mid, int end){
	int temp [end - start + 1];
	int left = start, right = mid + 1, index =0;

	while (left <= mid && right <= end){
		if(array[left] < array[right]) 
			temp[index++] = array[left++];
		else 
			temp[index++] = array[right++];
	}

	while (left <= mid)
		temp[index++] = array[left++];
	while (right <= end)
		temp[index++] = array[right++];

	for (index = start; index<= end; index++)
		array[index] = temp[index - start];	
}
void sort(int *array, int start, int end) {
	if (start >= end)
		return;	
	
	int mid = (start+end) /2;
	sort(array, start, mid);
	sort(array, mid + 1, end);
	merge(array, start, mid, end);
}
int main(){
	
	int length, *array;
	cin >> length;
	array = new int[length];
	for (int i = 0 ; i < length; i++)
		cin >> array[i];

	sort(array, 0, length-1);
	for (int i = 0; i < length; i++)
		cout << array[i] << endl;	
}	
