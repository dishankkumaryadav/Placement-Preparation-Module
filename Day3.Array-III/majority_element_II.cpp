class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        set<int> ans;
        unordered_map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            mpp[nums[i]]++;

            if(mpp[nums[i]] > nums.size()/3)
                ans.insert(nums[i]);
        }
        vector<int> result(ans.begin(), ans.end());
        return result;
    }
};