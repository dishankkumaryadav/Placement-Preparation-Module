class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> candidates, int target, int sum, int i, vector<int> &comb){
        if(sum > target)
            return;
        
        if(i == candidates.size()){
            if(sum == target){
                ans.push_back(comb);
            }
            return;
        }
        comb.push_back(candidates[i]);
        solve(ans, candidates, target, sum + candidates[i], i+1, comb);
        comb.pop_back();

        while(i+1< candidates.size() && candidates[i] == candidates[i+1]) i++;
        solve(ans, candidates, target, sum, i+1, comb);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        solve(ans, candidates, target, 0, 0, comb);
        return ans;
    }
};