//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void solve(vector<int> arr, vector<int> &output, int index, int sum, int n){
        if(index == n){
            output.push_back(sum);
            return;
        }
        
        // include
        solve(arr, output, index + 1, sum + arr[index], n);
        
        // exclude
        solve(arr, output, index + 1, sum, n);
            
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> output;
        int sum = 0;
        int index = 0;
        
        solve(arr, output, index, sum, N);
        return output;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends