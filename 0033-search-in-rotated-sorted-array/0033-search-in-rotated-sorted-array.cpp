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

                if (target >= nums[l] && target < nums[mid])
                    r = mid - 1;

                else
                    l = mid + 1; // when mid in in left but target is in right
            }

            // right half sorted (mid is in right half)
            else {

                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;

                else
                    r = mid - 1; // when mid in in right but target is in left
            }
        }

        return -1;
    }
};