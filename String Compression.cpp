class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        int charCount = 0;
        char ch = chars[0];
        // increment count because there is one character now
        charCount++;
        for(int i = 1; i < chars.size(); ++i)
        {
            if(chars[i] == ch)
                charCount++;
            else
            {
                s += ch;
                if(charCount != 1)
                {
                    if(charCount >= 10)
                        s += char((charCount / 10) + 48);
                    
                    s += char((charCount % 10) + 48);
                }
                // now replace the running character and its count
                ch = chars[i];
                charCount = 1;
            }
        }
        // adding a boundary case for the last encountered character
        s += ch;
        if(charCount != 1)
        {
            if(charCount >= 10)
                s += char((charCount / 10) + 48);
            s += char((charCount % 10) + 48);
        }
        
        
        chars.clear();
        for(int i = 0; i < s.size(); ++i)
            chars.push_back(s[i]);
        
        return chars.size();
    }
};