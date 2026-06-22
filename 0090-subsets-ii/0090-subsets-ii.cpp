class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Pick
        temp.push_back(nums[idx]);
        solve(idx + 1, nums);
        temp.pop_back();

        // Not Pick
        int i = idx;
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        solve(i + 1, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(0, nums);
        return ans;
    }
};
    