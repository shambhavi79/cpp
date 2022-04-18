#include <iostream>
#include <string>

using namespace std;

int factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);
}

int factorial_1(int n){
    int fact=1;
    for(int i=2; i<=n; i++){
        fact=fact*i;
    }
    return fact;
}

int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1)+ fibonacci(n-2);
}

int fibonacci_1(int n){
    int n3;
    int n1=0;
    int n2=1;
    for(int i=2; i<n; i++){
        int n3=n1+n2;
        n1=n2;
        n2=n3;
    }
    return n3;
}

int power(int a, int n){
    if(n==0){
        return 1;
    }
    // if(n==1){
    //     return a;
    // }
    int temp=power(a, n/2);
    if(n%2==0){
        return temp*temp;
    }
    else{
        return temp*temp*a;
    }
}

void subsets(string s, string output="",int i=0){
    if(i==s.length()){
        cout<<output<<endl;
        return;
    }
    
    subsets(s, output+s[i], i+1);
    
    subsets(s, output, i+1);
}

int countsubsets(int arr[], int n, int sum){
    if(n==0){
        if(sum==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    return countsubsets(arr, n-1, sum-arr[n-1])+countsubsets(arr, n-1, sum);
}
int main()
{
    cout<<power(2, 3)<<endl;
    cout<<power(2,4)<<endl;
    string str="ABCDEF";
    subsets(str);
    int arr[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout<<countsubsets(arr, 10, 11)<<endl;
    cout<<"Hello World";

    return 0;
}
