#include "../sort.h"
#include "../time.h"
int main(){
    srand(time(0));
    int n,k;
    cout<<"Enter a sample value of n: ";
    cin>>n;
    cout<<"Enter a sample value of k: ";
    cin>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        arr[i] = rand()%1000;
    }

    cout<<endl;


    //https://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c - I was unable to get accurate results using time_t\

    vector<int> initial = arr;
    cout<<"Time taken by insertion sort : "<< measureTimeInsertion(arr,n) << " microseconds" << endl;
    cout<<"Sorted array : "; print(arr,n);
    cout<<endl;


    arr = initial;
    cout<<"Time taken by merge sort : "<< measureTimeMerge(arr,n) << " microseconds" << endl;
    cout<<"Sorted array : "; print(arr,n);
    cout<<endl;

    arr = initial;
    cout<<"Time taken by quick sort is : "<< measureTimeQuick(arr,n)<< " microseconds" << endl;
    cout<<"Sorted array : "; print(arr,n);
    cout<<endl;

    arr = initial;
    cout<<"Time taken by quick insertion sort is : "<< measureTimeQuickInsert(arr,n,k)<< " microseconds" << endl;
    cout<<"Sorted array : "; print(arr,n);
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    vector<int> best = findBestCaseInsertion();
    cout<<"The best case for insertion sort is : "<<"N:"<<best[0]<<"K"<<best[1]<<endl;
    cout<<endl;
    best = findBestCaseQuickSort();
    cout<<"The best case for quick sort is : "<<"N:"<<best[0]<<"K"<<best[1]<<endl;
    cout<<endl;
    best = findBestCaseQuickInsertion();
    cout<<"The best case for quick insertion sort is : "<<"N:"<<best[0]<<"K"<<best[1]<<endl;
    cout<<endl;


}