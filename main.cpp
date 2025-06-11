#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>&vec, int n){                // do all dat with lists
    for (int i = 1; i < n; ++i) {                     // start from 1 cause we compare i and i-1
        if (vec[i] < vec[i-1]) {
            int curr = vec[i];
            int j = i;
            while (curr < vec[j - 1] && j > 0) {              //shift till u reach proper index for misplaced curr
                vec[j] = vec[j - 1];
                j--;
            }
            vec[j] = curr;                                    //replace that index with curr
        }
    }
}
void selectionSort(vector<int>&vec, int n){
    for (int i = 0; i < n-1; ++i) {                           //loop till n-1 cause last iteration isn't needed (already sorted by then)
        int mini = i;                                         //initialize min value to be i
        for (int j = i + 1; j < n; ++j) {                     //iterate after i to find a the absolute min for evey iteration
            if (vec[j] < vec[mini]){
                mini = j;
            }
        }
        swap(vec[i], vec[mini]);                              //swap i and min (the min of that sub-array should be its first(ith for main arr) element)
    }
}
void bubbleSort(vector<int>&vec, int n){                    //can use boolean to make it adaptive
    for (int i = 0; i < n - 1; ++i) {                       //same as selection
        for (int j = 0; j < n - i - 1; ++j) {               //iterate over the unsorted part (-i) and we comparing j and j+1 so (-1)
            if(vec[j] > vec[j+1]){
                swap(vec[j], vec[j+1]);                 //swap to proper position //bubble up largest element to end
            }
        }
    }
}

int main() {
    vector<int> arr = {9, 5, 1, 4, 3};
    bubbleSort(arr, arr.size());

    cout << "Sorted: ";
    for (int num : arr)
        cout <<num<< " ";

    return 0;
}

