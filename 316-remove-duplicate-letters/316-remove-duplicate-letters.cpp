class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        stack <char> st;
        vector<int> mp(26, 0), visited(26, 0);
        for(auto &x : s) mp[x - 'a']++;
        
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            // if the stack is empty
            // 1. push the current character
            // 2. mark the character as visited
            // 3. decrement its counter by 1
            if(st.empty()) {
                st.push(ch);
                visited[ch - 'a'] = 1;
                mp[ch - 'a']--;
            }
            // if the stack already contains some elements
            // check the conditions
            // 1. current character 'ch' is smaller than the topmost character of the stack
            // 2. count of the topmost character of stack > 0 => topmost character comes again somewhere in
            // in the string therefore we can remove the topmost character and push the current smaller
            // character 'ch'
            // current character 'ch' was never pushed into the stack => if it was already pushed then we dont push it again
            else {
                while(st.size() > 0 and ch < st.top() and mp[st.top() - 'a'] > 0 and visited[ch - 'a'] == 0) {
                    char t = st.top();
                    visited[t - 'a'] = 0;
                    st.pop();
                }
                // if the current character was never seen mark it visited, push it into the stack, decrement its counter by 1
                if(not visited[ch - 'a']) {
                    st.push(ch); mp[ch - 'a']--;
                    visited[ch - 'a'] = 1;
                }
                // else just decrement its counter
                else mp[ch - 'a']--;
            }
        }
        // generate the string from the stack
        string out = "";
        while(not st.empty()) {
            out += st.top();
            st.pop();
        }
        // reverse the string (use a dequeue instead of a stack to avoid doing reversing the string)
        reverse(out.begin(), out.end());
        return out;
    }
};