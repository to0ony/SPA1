#include <iostream>
using namespace std;

void selectionSort(int numbers[], int n) {
	//Prolazim kroz indexe arraya
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i; //Krecem s pretpostavkom da prvi index (0) sadrzi najmanji broj
		//Pokusavam kontrirat pretpostavci, pokusavam pronaci index s manjim brojem
		for (int j = i + 1; j < n; j++) {
			if (numbers[j] < numbers[minIndex])
				minIndex = j;
		}
		if (minIndex != i)
			swap(numbers[i], numbers[minIndex]);
	}
}

int main()
{
	int brojevi[5] = { 6,4,7,1,1 };
	int n = 5;

	cout << "Before InsertionSort: \n";

	for (auto element : brojevi) {
		cout << element << "|";
	}
	cout << "\n";

	selectionSort(brojevi, n);

	cout << "After InsertionSort: \n";

	for (auto element : brojevi) {
		cout<< element << "|";
	}
}