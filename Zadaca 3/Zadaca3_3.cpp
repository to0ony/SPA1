#include <iostream>
#include <vector>

using namespace std;

//Binary Search Tree Implementation

int binarySearchTree(vector<int>& vec, int sizeOfVec, int x){
    int minIndex = 0;
    int maxIndex = sizeOfVec - 1;
    while(minIndex <= maxIndex){
        int midIndex = minIndex + (maxIndex - minIndex) / 2;
        if(vec[midIndex] == x){
            cout << "X is located on " << midIndex << " index!" << endl;
            return midIndex;
        }
        if(vec[midIndex] < x){
            minIndex += midIndex;
        }
        if(vec[midIndex] > x){
            maxIndex -= midIndex;
        }
    }
    cout << "X is not located in array!" << endl;
    return -1;
}

int main(){
vector<int> elements = {2,4,6,12,24,48};
int size = elements.size();
binarySearchTree(elements, size, 50);
binarySearchTree(elements, size, 4);
binarySearchTree(elements, size, 2);
binarySearchTree(elements, size, 48);
}