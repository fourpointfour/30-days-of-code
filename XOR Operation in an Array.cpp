class Solution {
public:
    int xorOperation(int n, int start) {
        int xorResult = 0;
        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i)
        {
            res[i] = start + 2 * i;
            xorResult ^= res[i];
        }
        return xorResult;
    }
};