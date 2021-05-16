class Solution {
public:
    // we will use simulation of the process here in order to find the deck
    // revealing order

    /*
     * Store the indices in a queue
     * and start processing the queue
     * Add first card from sorted deck to queue front and pop the index
     * Now the top card or index needs to go to the end so push it to the end
     * and pop it from the front (wait till this index's turn now)
     */
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if(deck.empty())
            return {};
        
        queue<int> q;
        for(int i = 0; i < deck.size(); ++i)
            q.push(i);
        
        sort(deck.begin(), deck.end());
        vector<int> res(deck.size(), 0);
        for(int card : deck)
        {
            res[q.front()] = card;
            q.pop();
            if(!q.empty())
            {
                q.push(q.front());
                q.pop();
            }
        }
        return res;
    }
};