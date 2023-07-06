class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        if(n == 0)
            return 0;
        int maxi = 1;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        for(int it:st){
            if(st.find(it -1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x = x+1;
                    cnt++;
                }
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};