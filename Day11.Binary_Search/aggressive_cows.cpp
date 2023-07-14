bool canplacecows(vector<int> stalls, int n, int k, int dist){
    int first = stalls[0];
    int count = 1;
    for(int i=1; i<n; i++){
        if(stalls[i] - first >= dist){
            count++;
            first = stalls[i];
        }
        if(count == k){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n-1] - stalls[0];
    int res = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(canplacecows(stalls, n, k, mid)){
            res = mid;
            low = mid + 1;
        }
        else
            high = mid -1;
    }
    return res;
}