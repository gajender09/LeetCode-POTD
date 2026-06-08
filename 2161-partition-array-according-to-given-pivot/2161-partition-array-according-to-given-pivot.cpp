class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        int n = nums.size();
        vector<int> smaller;
        vector<int> equal;
        vector<int> greater;

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot)
                smaller.push_back(nums[i]);

            else if (nums[i] > pivot)
                greater.push_back(nums[i]);

            else
                equal.push_back(nums[i]);
        }

        vector<int> res;

        res.insert(res.end(), smaller.begin(), smaller.end());
        res.insert(res.end(), equal.begin(), equal.end());
        res.insert(res.end(), greater.begin(), greater.end());

        return res;
    }
};