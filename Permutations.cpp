class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& temp, vector<vector<int>>& result, vector<bool>& used) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            temp.push_back(nums[i]);

            backtrack(nums, temp, result, used);

            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(nums.size(), false);

        backtrack(nums, temp, result, used);
        return result;
    }
};
