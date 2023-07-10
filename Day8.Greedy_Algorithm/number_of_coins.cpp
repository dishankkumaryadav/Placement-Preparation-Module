//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
{ 
    int maxCoin=0;
    for(int i=0; i < M; i++) if(coins[i] > maxCoin) maxCoin = coins[i];
    
    vector<int> dp(V+maxCoin, INT_MAX);
    dp[V] = 0;
    
    for(int i=V-1; i >= 0; i--){
        int ans = INT_MAX-1;
	    for(int j=0; j < M; j++) ans = min(ans, dp[i+coins[j]]);
	    dp[i]=ans+1;
    }
    
    if(dp[0] != INT_MAX) return dp[0];
    else return -1;
}
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends