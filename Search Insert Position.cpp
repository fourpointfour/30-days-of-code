class Solution {
public:
    // use binary search to find the target element
    // if target element is not found then the search ends up at the position
    // where the element is supposed to be
    int binarySearch(vector<int> &nums, int target, int beg, int end)
    {
        int mid = beg + (end-beg)/2;
        if(beg <= end)
        {
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                return binarySearch(nums, target, mid+1, end);
            else
                return binarySearch(nums, target, beg, mid-1);
        }
        else
            return beg;
    }
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        
        return binarySearch(nums, target, 0, nums.size()-1);
    }
};