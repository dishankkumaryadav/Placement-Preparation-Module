#include <bits/stdc++.h> 

void sort(stack<int> &s, int temp){
    if(s.empty() || s.top()<temp){
        s.push(temp);
        return;
    }
    int x = s.top();
    s.pop();
    sort(s,temp);
    s.push(x);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty()){
        return;
    }
    int temp = stack.top(); 
    stack.pop();
    sortStack(stack);
    sort(stack, temp);
}