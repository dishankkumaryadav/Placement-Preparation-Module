class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1, k=nums.size()-1;
        while(j<=k){
            if(nums[i] == nums[j]){
                j++;
            }
            else{
                i++;
                nums[i] = nums[j];
                j++;
            }
        }
        return i+1;
    }
};