#include <iostream>

using namespace std;

void numberOfPrime(int n){
    int arr[1000]={0};
    arr[2]=1;
    for(int i=3; i<=n; i+=2){
        arr[i]=1;
    }
    for(int i=3; i<=n; i+=2){
        if(arr[i]==1){
            for(int j=i*i; j<=n; j+=i){
                arr[j]=0;
            }
        }
    }
    cout<<2<<" ";
    for(int i=3; i<=n; i+=2){
        if(arr[i]==1){
            cout<<i<<" ";
        }
    }
}

bool isSet(int n, int k){
    int y= n>>k-1;
    // if(y%2==0){
    //     return false;
    // }
    // return true;
    // OR 
    return y & 1;
}

int setBits(int n){
    // int count = 0;
    // while(n>0){
    //     if(n & 1==1){
    //         count++;
    //     }
    //     n=n>>1;
    // }
    //return count;
    
    // OR
    
    int ans=0;
    while(n!=0){
        n= n & (n-1);
        ans++;
    }
    return ans;
    
    // OR use
    //_builtin popcount(int n)
}

void findUnique_2(int arr[], int size){
    int xor_1=0;
    for(int i=0; i<size; i++){
        xor= xor ^ arr[i];
    }
    
}


int findUnique(int ar[], int size)

    {
        int res = ar[0];
        for (int i = 1; i < size; i++)
            res = res ^ ar[i];
        return res;
    }

int main()
{
    // numberOfPrime(100);
    // cout<<endl;
    cout<<setBits(15);

    return 0;
}