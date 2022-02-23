class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans = "";
        int i = 0;
        int j = 0;
        while(i < word1.length() && j < word2.length()){
            if(word1[i] > word2[j]){
                ans.push_back(word1[i]);
                i++;
            }else if(word2[j] > word1[i]){
                ans.push_back(word2[j]);
                j++;
            }else if(word1[i] == word2[j]){
                string temp1 = word1.substr(i, word1.length()-i);
                string temp2 = word2.substr(j, word2.length()-j);
                if(temp1 > temp2){
                    ans.push_back(word1[i]);
                    i++;
                }else{
                    ans.push_back(word2[j]);
                    j++;
                }
            }
        }
        while(i < word1.length()){
            ans.push_back(word1[i]);
            i++;
        }
        while(j < word2.length()){
            ans.push_back(word2[j]);
            j++;
        }
        return ans;
    }
};