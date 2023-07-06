
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int> m;
        int maxi = 0, sum = 0;
        for(int i=0; i<n; i++){
            sum = sum + A[i];
            if(sum == 0)
                maxi = i + 1;
            else{
                if(m.find(sum) != m.end())
                    maxi = max(maxi, i - m[sum]);
                else
                    m[sum] = i;
            }
        }
        return maxi;
    }
};