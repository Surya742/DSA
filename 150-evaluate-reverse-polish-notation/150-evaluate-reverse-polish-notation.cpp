class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it: tokens){
            if(it == "+" || it == "-" || it == "*" || it == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(it == "+"){
                    int temp = b+a;
                    st.push(temp);
                }
                else if(it == "-"){
                    int temp = b-a;
                    st.push(temp);
                }
                else if(it == "*"){
                    int temp = b*a;
                    st.push(temp);
                }
                else if(it == "/"){
                    int temp = b/a;
                    st.push(temp);
                }
            }else{
                stringstream geek(it);
                int x = 0;
                geek >> x;
                st.push(x);
            }
        }
        return st.top();
    }
};