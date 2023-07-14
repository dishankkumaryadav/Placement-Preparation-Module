class Solution {
public:
    void heapify(vector<int> &arr, int n, int i){
        int largest = i;
        int left = 2*i+1;
        int right = 2*i + 2;
        if(left<n && arr[largest] < arr[left])
            largest = left;
        if(right < n && arr[largest] < arr[right]){
            largest = right;
        }
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest); 
        }
    }

    void heapSort(vector<int> &arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
    }
}
    int findKthLargest(vector<int>& nums, int k) {
        heapSort(nums, nums.size());
        return nums[nums.size()-k];
    }
};
        // using priority_queue
        /*
        priority_queue<int> pq;
        for(int i:nums){
            pq.push(i);
        }
        int count = 1;
        while(count != k){
            pq.pop();
            count++;
        }
        return pq.top();
        */