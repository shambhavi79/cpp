#include <iostream>
#include <climits>

using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int x= arr[i];
        int j=i-1;
        while(arr[j]>x && j>=0){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=x;
    }
}


// Kadane's Algorithm

int maxSubarraySum(int arr[], int n){
    int maxsum= INT_MIN;
    int currsum= 0;
    for(int i=0; i<n; i++){
        currsum+=arr[i];
        if(currsum>maxsum){
            maxsum=currsum;
        }
        if(currsum<0){
            currsum=0;
        }
    }
    return maxsum;
}

int main()
{
    int arr[]={1, -1, 2, -3, -2, 3, 1};
    cout<<maxSubarraySum(arr, 7);

    return 0;
}
