#include "../sort.h"

int main(){
    vector<int> arr;
    unsigned int n, k;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"Enter the elements of the array: ";
    for(unsigned int i = 0; i < n; i++){
        int temp;
        cout<<"Enter element "<<i+1<<": ";
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr, n, k);
    return 0;
}