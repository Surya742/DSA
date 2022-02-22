class Solution {
public:
bool isPalindrome(string s)
{
    int n=s.length();
    for(int i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
}
bool validPalindrome(string s) {
    if(isPalindrome(s))
        return true;
    string s2=s;
    reverse(s2.begin(),s2.end());
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=s2[i])
        {
            s.erase(i,1);
            s2.erase(i,1);
            break;
        }       
    }
    if(isPalindrome(s)||isPalindrome(s2))
        return true;
    return false;
}
};