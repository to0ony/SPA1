#include <iostream>
#include <vector>
using namespace std;

// BestCase scenario time complexity: O(n log n)
// WorstCase scenario time complexity: O(n^2)
// 
// worst case for QuickSort is when chosen pivot is always highest or lowest
// number in array
// BestCase scenario when chosen pivot is similiar to median of all numbers inside array

int partition(vector<int>& vector, int start, int end) {
	int middle = start + (end-start) / 2;
	int pivot = vector[middle];

	swap(vector[middle], vector[start]);

	int i = start;

	for (int j = i + 1; j <= end; j++)
	{
		if (vector[j] < pivot)
		{
			i++;
			swap(vector[i], vector[j]);
		}
	}

	swap(vector[start], vector[i]);

	return i;
}

void quickSort(vector<int>& vector, int start, int end) {
	if (start < end) {
		int pivot = partition(vector, start, end);
		quickSort(vector, start, pivot - 1);
		quickSort(vector, pivot + 1, end);
	}
}

void printVector(vector<int>& vector) {
	cout << "Vector:";
	for (int i = 0; i < vector.size(); i++) {
		cout << vector[i];
		if (i < vector.size() - 1) {
			cout << ", ";
		}
	}
	cout << endl;
}

int main(){
	vector<int> brojevi = {6,2,66,77,96,16,6,27,17};
	printVector(brojevi);
	int vectorSize = brojevi.size() -1;
	quickSort(brojevi, 0, vectorSize);
	printVector(brojevi);
}
