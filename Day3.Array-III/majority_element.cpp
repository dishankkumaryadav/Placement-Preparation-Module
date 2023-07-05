class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Using Moore's Voting Algorithm
        int count=0, element=0;
        for(int i=0; i<nums.size(); i++){
            if(count==0)
                element = nums[i];
            if(element == nums[i])
                count++;
            else
                count--;
        }
        return element;
    }
};