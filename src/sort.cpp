#include "./sort.h"
//path: src/sort.cpp

// Function definitions

//Required Functions
void sort(vector<int>& arr, const unsigned int n, const unsigned int k)
{
    time_t start,end;
    cout<<"Initial Array: ";
    print(arr, n);
    cout<<endl;

    cout<<"Quick Sort: ";
    time(&start);
    quickSort(arr, n);
    time(&end);
    cout<<"Sorted Array: ";
    print(arr, n);
    cout<<"Time taken by Quick Sort: "<<fixed<<double(end - start)<<setprecision(5);cout<<" sec"<<endl;

    cout<<"Insertion Sort: ";
    time(&start);
    insertionSort(arr, n);
    time(&end);
    cout<<"Sorted Array: ";
    print(arr, n);
    cout<<"Time taken by Insertion Sort: "<<fixed<<double(end - start)<<setprecision(5);cout<<" sec"<<endl;

    cout<<"Merge Sort: ";
    time(&start);
    mergeSort(arr, n);
    time(&end);
    print(arr, n);
    cout<<"Time taken by Merge Sort: "<<fixed<<double(end - start)<<setprecision(5);cout<<" sec"<<endl;

    cout<<"Quick Insertion Sort: ";
    time(&start);
    quickInsertionSort(arr, n, k);
    time(&end);
    print(arr, n);
    cout<<"Time taken by Quick Insertion Sort: "<<fixed<<double(end - start)<<setprecision(5);cout<<" sec"<<endl;
}
int findBest(vector<int>& arr, const unsigned int n, const unsigned int k)
{
    return -1;
}

//Sorters

//Worst Case O(n^2), Average Case O(nlogn)
bool quickSort(vector<int>& arr, const unsigned int n)
{
    return false;
}

//Worst Case O(n^2)
bool insertionSort(vector<int>& arr, const unsigned int n)
{
    for(int i = 1 ; i < n-1; i++){
        int v = arr[i];
        int j = i-1;
        while (j >=0 and arr[j] > v){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;
    }
}
//Worst Case O(nlogn)
bool mergeSort(vector<int>& arr, int l, int r)
{
    int m;
    if(l < r){
        m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
    
}
bool quickInsertionSort(vector<int>& arr, const unsigned int n, const unsigned int k)
{
    return false;
}

// Finders
int findBestCaseInsertion(vector<int>& arr, const unsigned int n)
{
    return -1;
}
int findBestCaseQuickInsertion(vector<int>& arr, const unsigned int n, const unsigned int k)
{
    return -1;
}
int findBestCaseQuickSort(vector<int>& arr, const unsigned int n)
{
    return -1;
}


// Helpers
void print(vector<int>& arr, const unsigned int n)
{
    cout<<"[ ";
    for(int i = 0 ; i < n; i++){
        if(i == n-1){
            cout<<arr[i];
        }
        else{
            cout<<arr[i]<<", ";
        }
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merge(vector<int>& arr, int left, int middle, int right)
{
    int l = middle - left + 1;
    int r = right - middle;
    int Larr[l], Rarr[r];

    for(int i = 0 ; i < l; i++){
        Larr[i] = arr[left + i];
    }
    for(int i = 0 ; i < r; i++){
        Rarr[i] = arr[middle + 1 + i];
    }

    //Loop Control Variables
    int i = 0, j = 0, k = left;

    while(i < l and j < r){
        if(Larr[i] <= Rarr[j]){
            arr[k] = Larr[i];
            i++;
        }
        else{
            arr[k] = Rarr[j];
            j++;
        }
            k++;
    }
    while(i < l){
        arr[k] = Larr[i];
        i++;
        k++;
    }
    while(j < r){
        arr[k] = Rarr[j];
        j++;
        k++;
    }
}