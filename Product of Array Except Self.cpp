class Solution {
public:
    // we will calculate the product of the complete array first
    // and then while filling the array res, we will divide the product by nums[i]
    
    // BOUNDARY CASE:
    // If there is only one zero, then all other elements in res would be zero except
    // at the position of zero, but if there are multiple zeros then the complete array
    // would become zero
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        int productOfArray = 1, productWithoutZero = 1;
        vector<int> res(nums.size(), 0);
        for(int val : nums)
        {
            productOfArray *= val;
            if(val == 0)
            {
                zeroCount++;
                // if zeroCount becomes greater than 1 then the complete resultant array would be 0
                // so no need to calculate further
                if(zeroCount > 1)
                    return res;
                continue;
            }
            productWithoutZero *= val;
        }
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0)
                res[i] = productWithoutZero;
            else
                res[i] = productOfArray / nums[i];
        }
        return res;
    }
};