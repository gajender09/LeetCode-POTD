class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int swaps = 0;
        int left = 0;
        int right = n - 1;

        while (left < right) {

            while (left < right && nums[left] != 0) {
                left++;
            }

            while (left < right && nums[right] == 0) {
                right--;
            }

            if (left < right) {
                swap(nums[left], nums[right]);
                swaps++;
                left++;
                right--;
            }
        }
        return swaps;
    }
};