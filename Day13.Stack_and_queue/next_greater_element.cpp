class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        int n= nums2.size();
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            int element = nums2[i];
            while(!st.empty() && st.top() <= element){
                st.pop();
            }
            int res = (st.empty()) ? -1 : st.top();
            m.insert({element, res});
            st.push(element);
        }
        vector<int> ans;
        for(auto i:nums1){
            ans.push_back(m[i]);
        }
        return ans;
    }
};