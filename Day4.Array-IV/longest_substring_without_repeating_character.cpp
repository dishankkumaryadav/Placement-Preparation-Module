class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ans(256, -1);
        int maxlen = 0, start = -1;
        for(int i =0; i<s.length(); i++){
            if(ans[s[i]]>start)
                start = ans[s[i]];
            ans[s[i]] = i;
            maxlen = max(maxlen, i-start);
        }
        return maxlen;
    }
};