class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int maxD = 0;

        for (int j = m - 1; j >= 0; j--) {
            int left = 0;
            int right = n - 1;

            while (left <= right) {
                int mid = (left + right) / 2;

                if (nums1[mid] <= nums2[j]) {
                    maxD = max(maxD, j - mid);
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }

        return maxD;
    }
};