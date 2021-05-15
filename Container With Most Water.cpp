class Solution {
public:
    // iterate from both the ends
    // keep track of the water in the current container formed by [beg, end]
    // keep track of maxCapacity
    int maxArea(vector<int>& height) {
        int beg = 0, end = height.size() - 1, maxCapacity = INT_MIN, currentContainerCapacity;
        while(beg < end)
        {
            currentContainerCapacity = min(height[beg], height[end]) * (end - beg);
            maxCapacity = max(maxCapacity, currentContainerCapacity);
            
            if(height[beg] < height[end])
                beg++;
            else
                end--;
        }
        return maxCapacity;
    }
};