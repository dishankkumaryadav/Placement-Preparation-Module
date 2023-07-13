class Solution {
private: 
    int binarySearch(vector<int> nums, int target, int s, int e){
        int mid = s + (e-s)/2;
        while(s<=e){
            if(nums[mid] == target)
                return mid;
            if(nums[mid]>target)
                e = mid - 1;
            else
                s = mid + 1;
            mid = s + (e-s)/2;
        }
        return -1;
    }
    int getPivot(vector<int> nums, int target){
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e-s)/2;
        
        while(s<e){
            if(nums[mid] >= nums[0])
                s = mid + 1;
            else
                e = mid;
            mid = s + (e - s)/2;
        }
        return s;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivot = getPivot(nums, target);
        // return pivot;
        int ans;
        if(nums[pivot] == target)
            ans = pivot;
        else if(nums[pivot]<target && nums[nums.size() - 1] >= target)
            ans = binarySearch(nums, target, pivot, nums.size()-1);
        else
            ans = binarySearch(nums, target, 0, pivot - 1);
        return ans;
    }
};