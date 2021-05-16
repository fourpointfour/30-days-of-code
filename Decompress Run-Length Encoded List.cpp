class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int freq, val;
        vector<int> res;
        for(int i = 0; i < nums.size(); i += 2)
        {
            freq = nums[i];
            val = nums[i + 1];
            for(int f = 0; f < freq; ++f)
                res.push_back(val);
        }
        return res;
    }
};