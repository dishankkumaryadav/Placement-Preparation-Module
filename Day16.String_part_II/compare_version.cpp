class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0, j = 0;
        int m = version1.size();
        int n = version2.size();
        while(i<m || j<n){
            long x = 0, y = 0;
            while(i<m && version1[i] != '.')
                x = x*10 + (version1[i++] - '0');
            while(j<n && version2[j] != '.')
                y = y*10 + (version2[j++] - '0');
            
            if(x > y)
                return 1;
            else if(x < y)
                return -1;
            i++;
            j++;
        }
        return 0;
    }
};