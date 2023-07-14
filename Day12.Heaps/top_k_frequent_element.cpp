class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i:nums){
            m[i]++;
        }
        vector<int> counts = {};
        for(auto it = m.begin(); it != m.end(); it++)
        {
            counts.push_back(it->second);
        }
        sort(counts.begin(),counts.end(), greater<int>());
        vector<int> ans = {};
        int a = 0;
        while(ans.size() != k)
        {
            for(auto it = m.begin(); it != m.end(); it++){
                if(it->second == counts[a] && a < k){
                    ans.push_back(it->first);
                    a++;
                }
            }
        }
        return ans;
    }
};