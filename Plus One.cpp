class Solution {
public:
    // begin iteration from the end
    // add 1 to the digit
    // if sum exceeds 10, then store sum % 10 and carry = 1
    // if carry becomes 0, then no need to iterate further --> break
    vector<int> plusOne(vector<int>& digits) {
        // carry is 1 because we have to ultimately add one (1) to the LSB
        int carry = 1, sum = 0;
        for(int i = digits.size() - 1; i >= 0; --i)
        {
            sum = carry + digits[i];
            if(sum > 9)
            {
                digits[i] = sum % 10;
                carry = 1;
            }
            else
            {
                digits[i] = sum;
                carry = 0;
                
                // carry is now 0, so we can exit from the loop because there is no need
                // to add further
                break;
            }
        }
        if(carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};