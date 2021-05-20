class Solution {
public:
    int findSubsets(vector<int> &nums, int xorTillNow, int pos)
    {
        if(pos == nums.size())
        {
            return xorTillNow;
        }
        
        return findSubsets(nums, xorTillNow, pos + 1) + findSubsets(nums, xorTillNow ^ nums[pos], pos + 1);
    }
    int subsetXORSum(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        return findSubsets(nums, 0, 0);
    }
};