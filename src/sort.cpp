#include "../sort.h"
//path: src/sort.cpp


// Sorting Functions
void insertionSort(vector<int>& arr, const unsigned int left, const unsigned int right)
{
    for(int i = left+1 ; i <= right; i++){
        int v = arr[i];
        int j = i-1;
        while (j >= 0 and arr[j] > v){
            arr[j+1] = arr[j];
            j--;
        }
        arr[++j] = v;
    }
}
void mergeSort(vector<int>& arr, int l, int r)

{
    int m;
    if(l < r){
        m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
    
}
void quickSort(vector<int>& arr, const unsigned int left, const unsigned int right)
{
    int p;
    if(left<right)
    {
        p = findPiv(arr,left,right);
        quickSort(arr,left,p-1);
        quickSort(arr,p+1,right);
    }
}
void quickInsertionSort(vector<int>& arr, const unsigned int left, const unsigned int right, const unsigned int k)
{
    int p;
    if((left-right)>k)
    {    
        if(left<right)
        {
            p = findPiv(arr,left,right);
            quickSort(arr,left,p-1);
            quickSort(arr,p+1,right);
        }
    }
    else
    {
        insertionSort(arr,left,right);
    }
}



// Helpers
void print(vector<int>& arr, const unsigned int n)
{
    cout<<"[ ";
    for(int i = 0 ; i < n; i++){
        if(i == n-1){
            cout<<arr[i]<<' '<<']'<<endl;
        }
        else{
            cout<<arr[i]<<", ";
        }
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
int findPiv(vector<int>& arr,int left, int right)
{
    int pivot = arr[(left+right/2)];
    int i = (left-1);
    for(int j = left; j <= right-1; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;
    return (i+1);
}



