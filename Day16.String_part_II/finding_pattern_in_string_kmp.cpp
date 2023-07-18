#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    // Write your code here.
    int m = p.length();
    int n = s.length();

    if(m == 0)
        return 0;
    if(m > n)
        return 0;
    for(int i=0; i<n; i++){
        if(s[i] == p[0]){
            if(s.substr(i, m) == p)
                return true;
        }
    }
    return false;
}