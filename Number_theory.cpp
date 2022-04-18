#include <iostream>
#include <cmath>

using namespace std;

int numberOfDigits(int x){
    int count=0;
    while(x>0){
        count++;
        x=x/10;
    }
    return count;
}

bool palindrome(int n){
    int a=n;
    int x=0;
    int y;
    while(n>0){
        y=n%10;
        x= (x*10) + y;
        n=n/10;
    }
    
    if(x==a){
        return true;
    }
    else{
        return false;
    }
}

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

int traillingzeros(int n){
    int count=0;
    for(int i=5; i<=n; i*=5){
        count+=n/i;
    }
    return count;
}

bool checkPrime(int n){
    if(n==2 || n==3 || n==5){
        return true;
    }
    if(n%2==0 || n%3==0){
        return false;
    }
    for(int i=5; i<n; i=i+6){
        if(n%i==0 || n%(i+2)==0){
            return false;
        }
    }
    return true;
    //Every prime number after 6 is 6k +/- 1
    
}

void primeFactors(int n){
    if(n==1){
        return;
    }
    while(n%2==0){
        cout<<2<<" ";
        n=n/2;
    }
    while(n%3==0){
        cout<<3<<" ";
        n=n/3;
    }
    
    for(int i=5; i<=sqrt(n); i+=6){
        while(n%i==0){
            cout<<i<<" ";
            n=n/i;
        }
        while(n%(i+2)==0){
            cout<<i+2<<" ";
            n=n/(i+2);
        }
    }
    if(n>3){
        cout<<n;
    }
}

int main()
{
    int x=21;
    cout<<numberOfDigits(x)<<endl;
    if(palindrome(x)==true){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    int a=14;
    int b=21;
    cout<<"HCF or GCD is: "<<gcd(a, b)<<endl;
    
    cout<<"LCM is: "<<(a*b)/gcd(a,b)<<endl;
    primeFactors(3600);
    
    //OR another formula is 
    // cout<<floor(log10(n)+1);

    return 0;
}