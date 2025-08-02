class Solution {
private:
    // Helper function to convert a word to its numerical value.
    int getNumericalValue(const string& word) {
        int value = 0;
        for (char c : word) {
            value = value * 10 + (c - 'a');
        }
        return value;
    }

public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int firstVal = getNumericalValue(firstWord);
        int secondVal = getNumericalValue(secondWord);
        int targetVal = getNumericalValue(targetWord);

        return (firstVal + secondVal) == targetVal;
    }
};