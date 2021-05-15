class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        // initializing original pointer at first position so that the first element
        // is always copied into the new modified array
        int og_ptr = 0, temp_ptr = 1;
        while(temp_ptr < nums.size())
        {
            if(nums[og_ptr] != nums[temp_ptr])
                nums[++og_ptr] = nums[temp_ptr++];
            else
                temp_ptr++;
        }
        return (og_ptr + 1);
    }
};