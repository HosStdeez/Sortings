#include <iostream>
#include <vector>


using namespace std;

void insertionSort(vector<int>&input, int n){                // do all dat with lists
    for (int i = 1; i < n; ++i) {                     // start from 1 cause we compare i and i-1
        if (input[i] < input[i - 1]) {
            int curr = input[i];
            int j = i;
            while (curr < input[j - 1] && j > 0) {              //shift till u reach proper index for misplaced curr
                input[j] = input[j - 1];
                j--;
            }
            input[j] = curr;                                    //replace that index with curr
        }
    }
}
void selectionSort(vector<int>&input, int n){
    for (int i = 0; i < n-1; ++i) {                           //loop till n-1 cause last iteration isn't needed (already sorted by then)
        int min = i;                                         //initialize min value to be i
        for (int j = i + 1; j < n; ++j) {                     //iterate after i to find a the absolute min for evey iteration
            if (input[j] < input[min]){
                min = j;
            }
        }
        swap(input[i], input[min]);                              //swap i and min (the min of that sub-array should be its first(ith for main arr) element)
    }
}
void bubbleSort(vector<int>&input, int n){
    bool swapped;                                           //boolean to stop sorting when array is already sorted(no swaps made at that iteration)
    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {               //iterate over the unsorted part (-i) and we comparing j and j+1 so (-1)
            if(input[j] > input[j + 1]){
                swap(input[j], input[j + 1]);               //swap to proper position and bubble up largest element to end
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}
void shellSort(vector<int>&input, int n){
    for (int gap = n/2; gap >= 1; gap/=2) {
        for (int j = gap; j < n; j++) {
            int i = j - gap;
            int temp = input[j];
            while (i >= 0 && temp < input[i]){
                input[i + gap] = input[i];
                i-=gap;
            }
            input[i + gap] = temp;
        }
    }
}

void merge(vector<int>&input, int mid, int l , int r){
    int i = l,k=0,j=mid+1;

    vector<int>vec2(r-l +1);                //new array to store merged sub arrays

    while(i<=mid && j<=r){
        if (input[i] < input[j])vec2[k++]=input[i++];
        else vec2[k++]=input[j++];
    }

    while(i<= mid)vec2[k++] = input[i++];        //if there is still elements in both subs
    while(j<= r)vec2[k++] = input[j++];

    for (int m = 0; m < k; ++m) {
        input[m + l] = vec2[m];
    }
}

void mergeSort(vector<int>&input, int n, int l, int r){
    if (l >= r)return;
    int mid = (l+r) /2;

    mergeSort(input, n, l, mid);
    mergeSort(input, n, mid + 1, r);
    merge(input, mid, l, r);
}

void mergeSort(vector<int>&vec, int n){             //wrapper function
    mergeSort(vec,n,0,n-1);
}


int partition(vector<int>&vec, int l ,int r){
    int i = l;
    int pivot = vec[l];                             //first element approach for pivot -> pivot Idx is l
    for (int j = i + 1; j <= r; ++j) {
        if (vec[j] <= pivot){
            i++;
            swap(vec[i],vec[j]);
        }
    }
    swap(vec[i],vec[l]);
    return i;
}

void quickSort(vector<int>&vec, int n, int l, int r){
    if (l >= r)return;
    int pivotIdx = partition(vec, l, r);                 //pivot after being properly positioned
    quickSort(vec, n, l, pivotIdx - 1);
    quickSort(vec, n, pivotIdx + 1, r);
}

void quickSort(vector<int>&input, int n){             //wrapper function
    quickSort(input, n, 0, n - 1);
}

void countSort(vector<int>&input, int n){
    int max = 0;                                //count array's size is max value in input array
    for (int i = 0; i < n; ++i) {
        if (input[i] > max) max = input[i];
    }

    vector<int>count(max+1,0);          //frequency for all values of input as indexes of count
    for (int i = 0; i < n; ++i) {
        count[input[i]]++;
    }

    for (int i = 1; i < max+1; ++i) {           //prefix sum
        count[i] += count[i-1];
    }

    vector<int>res(n,0);                  
    for (int i = n-1; i >= 0; --i) {
        res[count[input[i]] - 1] = input[i];
        count[input[i]]--;
    }
    input = res;
}


int main() {
    vector<int> arr = {9, 0, 4, 4, 3,0,80,40};
    countSort(arr, arr.size());

    cout << "Sorted: ";
    for (int num : arr)
        cout <<num<< " ";

    return 0;
}

