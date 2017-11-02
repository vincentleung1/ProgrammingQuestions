/**
 *  https://leetcode.com/problems/missing-number/description/
 *
 *  Runs in O(n) time with O(1) space. This problem is the same problem as 
 *  the first missing positive problem, with the indexes at num[i] = i instead of i+1.
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Do an in-place swap of the array.
        for ( int i = 0; i < nums.size(); i++ ) {
            while ( nums[i] >= 0 && nums[i] < nums.size() && nums[i] != nums[nums[i]] ) {
                int temp = nums[i];
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        for ( int i = 0; i < nums.size(); i++ ) {
            if (nums[i] != i) {
                return i;
            }
        }
        return nums.size();
    }
};