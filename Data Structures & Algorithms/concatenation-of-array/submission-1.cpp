class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        short len = nums.size();
        vector<int> ans(len * 2);

        for (size_t i = 0; i < len; i++) {
           ans[i] = nums[i];
           ans[i + len] = nums[i];
        }
        return ans;
    }
};