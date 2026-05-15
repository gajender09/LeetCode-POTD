class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int minEle = INT_MAX;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (nums[r] <= nums[mid]) {
                minEle = min(minEle, nums[mid]);
                l = mid + 1;
            } 
            else {
                minEle = min(minEle, nums[mid]);
                r = mid - 1;
            }
        }

        return minEle;
    }
};