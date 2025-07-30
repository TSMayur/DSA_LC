class Solution {
public:
    string intToRoman(int num) {
        string ans {""};
        int M =  num / 1000,
            C = (num / 100) % 10,
            X = (num / 10)  % 10,
            I = num % 10;
        if (M != 0) {                      // 1234
            for (int i = M; i > 0; --i)    // ^
                ans.push_back('M');
        }

        if (C != 0) {                           // 1234
            if      (C == 9) ans.append("CM");  //  ^
            else if (C == 4) ans.append("CD");
            else if (C >= 5) {
                ans.push_back('D');
                for (int i = C; i > 5; --i)
                    ans.push_back('C');
            }
            else {
                for (int i = C; i > 0; --i)
                    ans.push_back('C');
            }
        }

        if (X != 0) {                           // 1234
            if      (X == 9) ans.append("XC");  //   ^
            else if (X == 4) ans.append("XL");
            else if (X >= 5) {
                ans.push_back('L');
                for (int i = X; i > 5; --i)
                    ans.push_back('X');
            }
            else {
                for (int i = X; i > 0; --i)
                    ans.push_back('X');
            }
        }

        if (I != 0) {                           // 1234
            if      (I == 9) ans.append("IX");  //    ^
            else if (I == 4) ans.append("IV");
            else if (I >= 5) {
                ans.push_back('V');
                for (int i = I; i > 5; --i)
                    ans.push_back('I');
            }
            else {
                for (int i = I; i > 0; --i)
                    ans.push_back('I');
            }
        }

        return ans;
    }
};