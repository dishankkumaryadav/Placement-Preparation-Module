#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
    pair<int, int> p;
    vector<int> temp(n+1);
    for(int i=0; i<n; i++){
        temp[arr[i]]++;
    }
    for(int i=1; i<=n; i++){
        if(temp[i] == 0)
            p.first = i;
        if(temp[i] > 1)
            p.second = i;
    }
    return p;
}