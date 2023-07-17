class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int len_a = a.length();
        int len_b = b.length();

        int n = (len_b/len_a);
        int count = n;
        string ans = "";
        while(count--){
            ans += a;
        }
        if(ans.find(b) != string::npos)
            return n;
        ans += a;
        if(ans.find(b) != string::npos)
            return n+1;
        
        ans += a;
        if(ans.find(b) != string::npos)
            return n+2;
        return -1;
    }
};