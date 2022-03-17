class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        int d = 0, prev=0;
        for(char c : s){
            if(c == '(')
                st.push(0);
            else {
               d = st.top(); st.pop();
               prev = st.top(); st.pop();
               st.push(prev + max(d * 2, 1));
            }//end else
        }//end for
        return st.top();
    }
};