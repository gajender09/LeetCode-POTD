class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (target == nums[mid])
                return mid;

            // left half sorted (mid is in left half)
            if (nums[l] <= nums[mid]) {

                if (target >= nums[l] && target < nums[mid]) // target in left
                    r = mid - 1;

                else
                    l = mid + 1; // target in right
            }

            // right half sorted (mid is in right half)
            else {

                if (target > nums[mid] && target <= nums[r]) // target in right
                    l = mid + 1;

                else
                    r = mid - 1; // target in left
            }
        }

        return -1;
    }
};