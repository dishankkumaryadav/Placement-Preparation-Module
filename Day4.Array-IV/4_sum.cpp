#define ll long long 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.empty())
            return ans;
        ll n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ll remaining = 1LL*target - 1LL*nums[i] - 1LL*nums[j];

                ll left = j+1;
                ll right = n-1;
                while(left<right){
                    int two_sum = nums[left] + nums[right];
                    if(two_sum < remaining) 
                        left++;
                    else if(two_sum > remaining)
                        right--;

                    else{
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[left];
                        quadruplet[3] = nums[right];
                        ans.push_back(quadruplet);

                        while(left < right && nums[left] == quadruplet[2])
                            left++;
                        while(left < right && nums[right] == quadruplet[3])
                            right--;
                    }
                }
                while(j+1 < n && nums[j+1] == nums[j])
                    j++;
            }
            while(i+1<n && nums[i+1] == nums[i])
                i++;
        }
        return ans;
    }
};