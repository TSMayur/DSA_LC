class Solution {
public:
    string intToRoman(int num) {
        // Paired values and symbols, sorted from largest to smallest
        vector<pair<int, string>> values = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        string result = "";
        
        for (const auto& pair : values) {
            int value = pair.first;
            string symbol = pair.second;
            
            // While the number is large enough, append the symbol and subtract the value
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        
        return result;
    }
};