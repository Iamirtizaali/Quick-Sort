#include <iostream>
using namespace std;

//space complexity is O(n) and time complexity in worst case is O(n^2)


void printArray(int arr[], int size);
void quickSort(int arr[], int s, int e);
int partition(int arr[], int s, int e);

int main() {
	int n = 10;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = n - i;
	}
	printArray(arr, n);
	quickSort(arr, 0, n - 1);
	printArray(arr, n);
	return 0;
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int partition(int arr[], int s, int e) {
	int pivot = arr[s];
	int count = 0;
	for (int i = s+1; i <= e; i++)
	{
		if (arr[i] <= pivot) {
			count++;
		}
	}

	//place pivot at right position
	int pivotIndex = s + count;
	swap(arr[pivotIndex], arr[s]);
	//handle left and right part
	int i = s;
	int j = e;
	while (i<pivotIndex && j>pivotIndex)
	{
		while (arr[i] < pivot) { i++; }
		while (arr[j] > pivot) { j--; }
		if (i<pivotIndex && j>pivotIndex)
		{
			swap(arr[i++], arr[j--]);
		}
	}
	return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
	if (s>=e)
	{
		return;
	}
	int p = partition(arr, s, e);
	quickSort(arr, s, p - 1);
	quickSort(arr, p+1, e);
}