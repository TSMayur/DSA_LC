#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        if (n < 3) return false;

        for (int i = 1; i <= n / 2; ++i) {
            for (int j = 1; max(i, j) <= n - i - j; ++j) {
                if (check(num.substr(0, i), num.substr(i, j), num.substr(i + j))) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    // Recursively checks if the rest of the string can be formed by the sequence
    bool check(const string& n1, const string& n2, const string& rest) {
        if ((n1.length() > 1 && n1[0] == '0') || (n2.length() > 1 && n2[0] == '0')) {
            return false;
        }

        string sum_str = addStrings(n1, n2);
        
        // If the rest of the string is exactly the sum, we found a valid sequence
        if (rest == sum_str) {
            return true;
        }
        
        // If the rest of the string starts with the sum, recurse
        if (rest.rfind(sum_str, 0) == 0) {
            return check(n2, sum_str, rest.substr(sum_str.length()));
        }

        // Otherwise, this is not a valid sequence
        return false;
    }

    // Helper to add two numbers represented as strings
    string addStrings(const string& num1, const string& num2) {
        string result = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            result += to_string(sum % 10);
            carry = sum / 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};