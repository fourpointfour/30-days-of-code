class Solution {
public:
    int func(int n, vector<int> &arr)
    {
        if(arr[n] != -1)
            return arr[n];
        
        return arr[n] = func(n-1, arr) + func(n-2, arr) + func(n-3, arr);
        
    }
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        else if(n == 1 || n == 2)
            return 1;
        vector<int> arr(n+1, -1);
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        return func(n, arr);
    }
};