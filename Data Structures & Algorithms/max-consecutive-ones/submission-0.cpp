class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Have one variable to store the current count
        // And another one to hold the maximum count of 1's
        // Start looking at first element
            // If 1, increase current count
            // If 0, 
                // If current > maximum, add current count to maximum count
                // Reset current count
        // Go to the next element and repeat the process
        // Return the maximum count

        int currentCount = 0;
        int maximumCount = 0;
        int numsSize = nums.size() - 1;

        for (int i = 0; i <= numsSize; i++) {
           if (nums[i] == 1) {
                currentCount++;
                if (i == numsSize && currentCount > maximumCount) {
                    maximumCount = currentCount;
                }
           } else {
                if (currentCount > maximumCount) {
                    maximumCount = currentCount;
                }
                currentCount = 0;
           }
        }
        return maximumCount;
    }
};