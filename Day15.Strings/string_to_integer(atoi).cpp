class Solution {
public:
    int myAtoi(string s) {
        long int res = 0;
        bool neg = false;
        int n = s.length();
        int i=0;
        while(i<n && s[i] == ' ')
            i++;
        if(s[i] == '-'){
            neg = true;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }
        if(s[i] >='a' && s[i]<='z'){
            return 0;
        }
        while(i<n){
            if(s[i] >='0' && s[i] <= '9'){
                res = res*10 + (s[i] - '0');
                if(res>2147483647){
                    if(neg == true)
                        return INT_MIN;
                    else
                        return INT_MAX;
                }
            }
            else{
                break;
            }
            i++;
        }
        if(neg == true)
            return (-1)*res;
        return res;
    }
};