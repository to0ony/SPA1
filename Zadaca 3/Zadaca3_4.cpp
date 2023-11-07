#include <iostream>
#include <vector>

using namespace std;

int unimodalArrayMaxFinder(const vector<int>& vec, int sizeOfVec){
    int minIndex = 0;
    int maxIndex = sizeOfVec - 1;
    while(minIndex < maxIndex){
        int midIndex = (minIndex + maxIndex) / 2;
        if(vec[midIndex] < vec[midIndex + 1]){
            minIndex += 1;
        }else if(vec[midIndex] < vec[midIndex - 1]){
            maxIndex -= 1;
        }else{
            return vec[midIndex];
        }
    }
}

void showMax (const vector<int> array){
    int size = array.size();
    cout << unimodalArrayMaxFinder(array, size) << " is highest value of array." << endl;
}

int main(){
vector<int> arr  = {1,2,4,8,16,32,22,12,2,1};
vector<int> arr1 = {5,10,15,50,15,10,1};
vector<int> arr2 = {100,200,300,666,550,440,330,220,110};

showMax(arr);
showMax(arr1);
showMax(arr2);
}