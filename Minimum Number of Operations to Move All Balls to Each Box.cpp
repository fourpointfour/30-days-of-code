class Solution {
public:
    // create set to store indices of all the boxes which contain balls
    // now for a particular index, we have to add the difference of all the indices
    // to the current index
    vector<int> minOperations(string boxes) {
        if(boxes.empty())
            return {};
        
        vector<int> res(boxes.size(), 0);
        set<int> st;
        for(int i = 0; i < boxes.size(); ++i)
        {
            if(boxes[i] == '1')
                st.insert(i);
        }
        
        for(int i = 0; i < res.size(); ++i)
        {
            int moves = 0;
            for(int val : st)
            {
                if(val != i)
                    moves += abs(val - i);
            }
            res[i] = moves;
        }
        return res;
    }
};