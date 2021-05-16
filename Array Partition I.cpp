class Solution {
public:
    // we can sort the array and then make pairs of two
    // in that way we will maximize the sum of min(a, b)
    int arrayPairSum(vector<int>& nums) {
        if(nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int maxSum = 0;
        for(int i = 0; i < nums.size(); i += 2)
            maxSum += nums[i];
        
        return maxSum;
    }
};