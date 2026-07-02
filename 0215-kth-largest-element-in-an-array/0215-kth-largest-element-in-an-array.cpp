class Solution {
public:
    void heapify(vector<int> &nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[left] > nums[largest])
            largest = left;
        if (right < n && nums[right] > nums[largest])
            largest = right;
        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
    void deletektimes(vector<int> &nums, int &n) {
        nums[0] = nums[n - 1];
        n--; 
        heapify(nums, n, 0); 
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }
        int count = 0;
        while (count < k - 1) {
            deletektimes(nums, n);
            count++;
        }
        return nums[0];
    }
};