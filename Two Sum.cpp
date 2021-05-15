class Solution {
public:
    // use hash map to store the index of the number
    // look for mp[target-val], if it is present then
    // return both the indices
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        int ind1 = -1, ind2 = -1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(mp.find(target-nums[i]) != mp.end())
            {
                ind1 = i;
                ind2 = mp[target - nums[i]];
                break;
            }
            else
                mp[nums[i]] = i;
        }
        return {ind1, ind2};
    }
};