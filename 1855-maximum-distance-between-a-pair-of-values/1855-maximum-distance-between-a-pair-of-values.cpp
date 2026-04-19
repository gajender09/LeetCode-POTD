class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0, j = 0;
        int maxD = 0;

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                maxD = max(maxD, j - i);
                j++;   // expand window
            } else {
                i++;   // shrink from left
            }
        }

        return maxD;
    }
};