#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Implementation of stacks using the STL library in c++. 
    // This library has functions push(), pop(), size(), top(), empty(), swap() and emplace()
    // Swap function is used to swap 2 stacks. Emplace does almost the same function as push
    stack<int> s1;
    s1.push(20);
    s1.push(19);
    s1.push(18);
    s1.push(17);
    
    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }

    return 0;
}