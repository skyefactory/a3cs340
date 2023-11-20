#include "../sort.h"
#include "../time.h"

double measureTimeInsertion(vector<int>& arr, const unsigned int n)
{
    auto t1 = chrono::high_resolution_clock::now();
    insertionSort(arr,0,n-1);
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> ms_double = t2 - t1;
    return ms_double.count();
}
double measureTimeQuick(vector<int>& arr, const unsigned int n)
{
    auto t1 = chrono::high_resolution_clock::now();
    quickSort(arr,0,n-1);
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> ms_double = t2 - t1;
    return ms_double.count();
}
double measureTimeQuickInsert(vector<int>& arr, const unsigned int n, const unsigned int k)
{
    auto t1 = chrono::high_resolution_clock::now();
    quickInsertionSort(arr,0,n-1,k);
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> ms_double = t2 - t1;
    return ms_double.count();
}
double measureTimeMerge(vector<int>& arr, const unsigned int n)
{
    auto t1 = chrono::high_resolution_clock::now();
    mergeSort(arr,0,n-1);
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> ms_double = t2 - t1;
    return ms_double.count();
}

// Finders
vector<int> findBestCaseInsertion()
{
    //Insertion sort would typically outperform quicksort at lower values of n.
    int n = 5;
    int k = 0;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        {
            arr[i] = rand()%1000;
        }
    double insertionTime = measureTimeInsertion(arr,n), quickTime = measureTimeQuick(arr,n), quickInsertionTime = measureTimeQuickInsert(arr,n,k);
    while(insertionTime >= quickTime && insertionTime >= quickInsertionTime)
    {
        insertionTime = measureTimeInsertion(arr,n);
        quickTime = measureTimeQuick(arr,n);
        quickInsertionTime = measureTimeQuickInsert(arr,n,k);
        n++; k++;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i] = rand()%1000;
        }
    }
    return {n, k};
}
vector<int> findBestCaseQuickInsertion()
{
    int n = 5;
    int k = 1;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        {
            arr[i] = rand()%1000;
        }
    double insertionTime = measureTimeInsertion(arr,n), quickTime = measureTimeQuick(arr,n), quickInsertionTime = measureTimeQuickInsert(arr,n,k);
    while(quickInsertionTime >= insertionTime && quickInsertionTime >= quickTime)
    {
        insertionTime = measureTimeInsertion(arr,n);
        quickTime = measureTimeQuick(arr,n);
        quickInsertionTime = measureTimeQuickInsert(arr,n,k);
        n++; k++;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i] = rand()%1000;
        }
    }
    return {n, k};
}
vector<int> findBestCaseQuickSort()
{
    int n = 5;
    int k = 0;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        {
            arr[i] = rand()%1000;
        }
    double insertionTime = measureTimeInsertion(arr,n), quickTime = measureTimeQuick(arr,n), quickInsertionTime = measureTimeQuickInsert(arr,n,k);
    while(quickTime >= insertionTime && quickTime >= quickInsertionTime)
    {
        insertionTime = measureTimeInsertion(arr,n);
        quickTime = measureTimeQuick(arr,n);
        quickInsertionTime = measureTimeQuickInsert(arr,n,k);
        n++; k++;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i] = rand()%1000;
        }
    }
    return {n, k};
} 