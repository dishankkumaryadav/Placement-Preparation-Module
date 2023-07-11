class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &candidates, vector<int> &comb, int target, int i, int sum){
        if(sum > target)
            return;
        
        // base case;
        if(i == candidates.size()){
            if(sum == target){
                ans.push_back(comb);
            }
            return;
        }
        sum += candidates[i];
        comb.push_back(candidates[i]);
        solve(ans, candidates, comb, target, i, sum);
        sum -= candidates[i];
        comb.pop_back();

        // exclude
        solve(ans, candidates, comb, target, i + 1, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;

        solve(ans, candidates, comb, target, 0, 0);
        return ans;
    }
};