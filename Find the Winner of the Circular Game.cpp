class Solution {
public:
    // A queue will help us in simulating the actual behaviour of the game
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i <= n; ++i)
            q.push(i);
        
        while(q.size() != 1)
        {
            for(int jump = 0; jump < k - 1; ++jump)
            {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};