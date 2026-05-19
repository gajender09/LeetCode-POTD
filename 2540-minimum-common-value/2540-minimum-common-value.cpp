class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        int common = INT_MAX;
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (nums1[i] == nums2[j]) {
                common = min(common, nums1[i]);
                i++, j++;
            }

            else if (nums1[i] < nums2[j])
                i++;

            else
                j++;
        }

        return common == INT_MAX ? -1 : common;
    }
};