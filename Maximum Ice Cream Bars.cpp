class Solution {
public:
    // sort the costs and start buying from the first icecream
    // if the boy cannot afford the first ice cream then the answer is zero
    // otherwise keep buying until coins == 0 or the complete array is iterated
    int maxIceCream(vector<int>& costs, int coins) {
        if(coins == 0 || costs.empty())
            return 0;
        
        int iceCreamCount = 0, i = 0;
        sort(costs.begin(), costs.end());
        
        if(coins < costs[0])
            return 0;
        while(coins > 0 && i < costs.size())
        {
            if(coins < costs[i])
                break;
            
            coins -= costs[i];
            iceCreamCount++;
            ++i;
        }
        return iceCreamCount;
    }
};