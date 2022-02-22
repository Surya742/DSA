class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            string ref = words[i];
            reverse(words[i].begin(),words[i].end());
            if(ref == words[i]) return words[i];
        }
        return "";
    }
};