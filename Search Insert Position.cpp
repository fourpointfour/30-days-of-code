class Solution {
public:
    // iterate over all the elements
    // keep a track of smaller elements (to know insertion position)
    // but if target is found, return index directly
    int searchInsert(vector<int>& nums, int target) {
        int ind = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == target)
            {
                ind = i;
                break;
            }
            else
            {
                if(nums[i] < target)
                    ind = i + 1;
            }
        }
        return ind;
    }
};