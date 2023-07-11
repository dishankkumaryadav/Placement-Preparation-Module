class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> nums, int index, vector<int> &subset){
        if(index == nums.size()){
            ans.push_back(subset);
            return;
        }
        else{
            //include
            subset.push_back(nums[index]);
            solve(ans, nums, index + 1, subset);
            subset.pop_back();

            //exclude
            while(index + 1 < nums.size() && nums[index] == nums[index+1]) index++;
            solve(ans, nums, index + 1, subset);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        solve(ans, nums, 0, subset);
        return ans;
    }
};