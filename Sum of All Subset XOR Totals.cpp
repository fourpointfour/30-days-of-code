class Solution {
public:
    void findSubsets(vector<int> &nums, vector<int> &res, vector<int> temp, int pos)
    {
        if(pos == nums.size())
        {
            int xorOfArray = 0;
            for(int val : temp)
                xorOfArray ^= val;
            
            res.push_back(xorOfArray);
            return;
        }
        findSubsets(nums, res, temp, pos+1);
        temp.push_back(nums[pos]);
        findSubsets(nums, res, temp, pos+1);
    }
    int subsetXORSum(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        vector<int> res;
        findSubsets(nums, res, {}, 0);
        return accumulate(res.begin(), res.end(), 0);
    }
};