/**
 *  https://leetcode.com/problems/first-missing-positive/description/
 *
 *  Runs in O(n) time with O(1) space
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Iterate through the vector
        for ( int i = 0; i < nums.size(); i++){
            // Swap the value of the current index to it's correct position
            // or if the current position contains an invalid number (out of range)
            // The ordering assumes that nums[0] should contain 1, nums[1] = 2 .. etc
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1] ) {
                // Do swap while checking for repeated numbers in the array.
                int temp = nums[i];
                nums[i] = nums[temp - 1]; // take nums[i]-1 to swap with
                nums[temp - 1] = temp;
            }
        }
        // Each index should contain the correct number
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i+1){
                // The first index that contains the incorrect number is the answer.
                return i+1;
            }
        }
        // If everything is correct in the vector, then the answer is size + 1
        return nums.size() + 1;
    }
};
