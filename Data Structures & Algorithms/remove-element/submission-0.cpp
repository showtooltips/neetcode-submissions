class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            if (nums[l] == val) {
                if (nums[r] != val) {
                    int temp = nums[l];
                    nums[l] = nums[r];
                    nums[r] = temp;
                    l++;
                }
                r--;
            } else {
                l++;
            }
        }
        return r + 1;
    }
};