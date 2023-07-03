class Solution {
public:

vector<int> nCr(int n, vector<int> row){
    int ans = 1;
    row.push_back(ans);
    for(int i=1; i<n; i++){
        ans = ans*(n-i);
        ans = ans/i;
        row.push_back(ans);
    }
    return row;
}

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            vector<int> row;
            
            ans.push_back(nCr(i, row));
        }
        return ans;
    }
};