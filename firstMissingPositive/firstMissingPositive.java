/**
 *  https://leetcode.com/problems/first-missing-positive/description/
 *
 *  Runs in O(n) time with O(1) space
 */

class Solution {
    public int firstMissingPositive(int[] nums) {
        // Do an in-place sort of the array.
        for ( int i = 0; i < nums.length; i++ ) {
            // While nums[i] is in the range of 1-> size && 
            // is not in the correct place already...
            while ( nums[i] > 0 && nums[i] <= nums.length && nums[i] != nums[nums[i]-1] ) {
                int temp = nums[i]; // hold the value
                nums[i] = nums[temp-1]; // Put the value we're swapping with in nums[i]
                nums[temp-1] = temp; // Put nums[i] into nums[temp-1]
            }
        }
        // Search the array for the first value that isn't nums[i] = i+1
        for ( int i = 0; i < nums.length; i++ ) {
            if ( nums[i] != i+1 ) {
                return i+1;
            }
        }
        return nums.length+1;
    }
}