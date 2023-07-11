class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void solve(int index, string s, vector<vector<string>> &ans, vector<string> &substring){
        if(index == s.size()){
            ans.push_back(substring);
            return;
        }
        for(int i=index; i<s.size(); i++){
            if(isPalindrome(s, index, i)){
                substring.push_back(s.substr(index,i - index + 1));
                solve(i+1, s, ans, substring);
                substring.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> substring;
        solve(0, s, ans, substring);
        return ans;
    }
};