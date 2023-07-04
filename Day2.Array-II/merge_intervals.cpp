class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> interval;
        if(intervals.size() == 0)
            return intervals;
        sort(intervals.begin(), intervals.end());
        interval = intervals[0];
        for(auto i: intervals){
            if(i[0] <= interval[1]){
                interval[1] = max(i[1], interval[1]);
            }
            else{
                ans.push_back(interval);
                interval = i;
            }
        }
        ans.push_back(interval);
        return ans;
    }
};