/**
*  https://leetcode.com/problems/two-sum/description
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> lookup;
        for (int i = 0; i < nums.size(); i++) {
            lookup[i] = nums[i];
        }
        std::sort (nums.begin(), nums.end() );

        int start = 0;
        int end = nums.size()-1;
        while(start != end) {
            int currentValue = nums[start] + nums[end];
            if(currentValue > target) {
                end--;
            } else if (currentValue < target) {
                start++;
            } else {
                vector<int> answer;
                answer.push_back(searchForValue(lookup, nums[start]));
                answer.push_back(searchForValue(lookup, nums[end]));
                return answer;
            }
        }
    }

    int searchForValue(std::unordered_map<int,int>& lookup, int target) {
        for (auto i : lookup) {
            if (i.second == target) {
                int ans = i.first;
                lookup.erase(i.first);
                return ans;
            }
        }
        return -1;
    }
};
