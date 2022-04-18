#include <iostream>

using namespace std;

// void allSets(int arr[], int n, vector<int> v, int sum){
//     if(sum==0){
//         for(int i=0; i<v.length(); i++){
//             cout<<v[i]<<
//         }
//     }
// }
void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void merge(int arr[], int s, int e){
    int temp[100];
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=e){
        temp[k]=arr[j];
        k++;
        j++;
    }
    for(int a=s; a<=e; a++){
        arr[a]=temp[a];
    }
}
void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, e);
}

int partition(int arr[], int s, int e){
    int i=s-1;
    // int j=s;
    int pivot=arr[e];
    for(int j=s; j<e; j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[e]);
    return i+1;
}

void quickSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }

    int p= partition(arr, s, e);\
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
    
    
}




int main()
{
    int arr[]={4, 3, 2, 1};
    quickSort(arr, 0, 3);
    for(int i=0; i<4; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}