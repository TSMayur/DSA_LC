class Solution {
public:
   bool isVowel(char ch){
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
   }
    long long countVowels(string word) {
      int n=word.size();
      long long total=0;
      for(int i=0;i<n;i++){
        if(isVowel(word[i])){
            long long contribution=(long long)(i+1)*(n-i);
            total+=contribution;
        }
      }
      return total;
    }
};