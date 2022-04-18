#include <iostream>

using namespace std;

int secondLargest(int arr[], int size){
    int a;
    int b;
    if(size<=1){
        return 0;
    }
    else{
        
        if(arr[0]>arr[1]){
          a=arr[0];
          b=arr[1];
        }
        
        else{
            a=arr[1];
            b=arr[0];
        }
        
        for(int i=2; i<size; i++){
            if(arr[i]>a){
                b=a;
                a=arr[i];
            }
            else if(arr[i]>b){
                b=arr[i];
            }
        }
    }
    return b;
}

void rotate(int arr[], int size, int d){
    // rotation formula for d;
    // reverse(0, d-1)
    // reverse(d, n-1)
    // reverse(0, n)
}
void rightrotate(int arr[], int size, int d){
    // rotation formula for d;
    // reverse(0, n-1)
    // reverse(d, d-1)
    // reverse(d, n-1)
}

void matrixBorder(int arr[][], int r, int c){
    for(int i=0; i<c; i++){
        cout<<arr[0][i];
    }
    for(int i=1; i<r; i++){
        cout<<[i][c-1];
    }
    if(r>1){
        for(int i=c-2; i>=0; i--){
        cout<<[r-1][i];
            
        }
    }
    if(c>1){
        for(int i=r-2; i>0; i--){
            cout<<[i][0]
        }
    }
}

void wave(int arr[][], int r, int c){
    for(int i=0; i<c; i++){
        if(i%2==0){
            for(int j=0; j<r; j++){
                cout<<arr[i][j];
            }
        }
        else{
            for(int j=r-1; j>=0; j--){
                cout<<arr[i][j];
            }
        }
    }
}

void transpose(int arr[][], int n){
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(A[i][j], A[j][i]);
        }
       
    }
}

int main()
{
    int arr[3][3];
    for(int i)

    return 0;
}
