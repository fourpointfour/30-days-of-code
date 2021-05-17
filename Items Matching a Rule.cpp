class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int numberOfItems = 0;
        for(vector<string> item : items)
        {
            if((ruleKey == "type" && ruleValue == item[0]) ||
              (ruleKey == "color" && ruleValue == item[1]) ||
              (ruleKey == "name" && ruleValue == item[2]))
                numberOfItems++;
        }
        return numberOfItems;
    }
};