class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleDigitSum = 0;
        int doubleDigitSum = 0;
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);    

        for (int num : nums) {
            if (num >= 1 && num <= 9) {
                singleDigitSum += num;
            } else if (num >= 10 && num <= 99) {
                doubleDigitSum += num;
            }
        }    
        int bobSumWhenAlicePicksSingleDigits = totalSum - singleDigitSum;
        int bobSumWhenAlicePicksDoubleDigits = totalSum - doubleDigitSum;

        if (singleDigitSum > bobSumWhenAlicePicksSingleDigits) {
            return true;
        }
        if (doubleDigitSum > bobSumWhenAlicePicksDoubleDigits) {
            return true;
        }
        return false;
        }
};
