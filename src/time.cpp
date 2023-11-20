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
    double insertionTime , quickTime , quickInsertionTime;
    int n,k=1;
    for(n = 5; n < 100000; n++)
    {
        k++; 
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i] = rand()%1000;
        }
        insertionTime = measureTimeInsertion(arr,n);
        quickTime = measureTimeQuick(arr,n);
        quickInsertionTime = measureTimeQuickInsert(arr,n,k);
        if(insertionTime < quickInsertionTime && insertionTime < quickTime)
        {
            return {n, k};
        }

    }
}
vector<int> findBestCaseQuickInsertion()
{
    double insertionTime , quickTime , quickInsertionTime;
    int n,k=5;
    for(n = 5; n < 100000; n*=10)
    {
        k*=2;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i] = rand()%1000;
        }
        insertionTime = measureTimeInsertion(arr,n);
        quickTime = measureTimeQuick(arr,n);
        quickInsertionTime = measureTimeQuickInsert(arr,n,k);
        if(quickInsertionTime < insertionTime && quickInsertionTime < quickTime)
        {
            return {n, k};
        }

    }
    return {n, k};
}
vector<int> findBestCaseQuickSort()
{
    double insertionTime , quickTime , quickInsertionTime;
    int n,k=1;
    for(n = 5; n < 100000; n*=10)
    {
        k*=5;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i] = rand()%1000;
        }
        insertionTime = measureTimeInsertion(arr,n);
        quickTime = measureTimeQuick(arr,n);
        quickInsertionTime = measureTimeQuickInsert(arr,n,k);
        if(quickTime < insertionTime && quickTime < quickInsertionTime)
        {
            return {n, k};
        }

    }
    return {n, k};
} 