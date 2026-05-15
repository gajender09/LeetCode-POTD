class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) return true;

            // shrink search space due to duplicates (can't decide which half is sorted)
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l++;
                r--;
            }

            // left half sorted
            else if (nums[l] <= nums[mid]) {
                if (target >= nums[l] && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }

            // right half sorted
            else {
                if (target > nums[mid] && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }

        return false;
    }
};