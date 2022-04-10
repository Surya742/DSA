class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(auto &itr: ops){
            if(itr=="C"){
                st.pop();
            }
            else if(itr=="D"){
                st.push(st.top()*2);
            }
            else if(itr=="+"){
                int tmp=st.top();
                st.pop();
                int tmp2=tmp+st.top();
                st.push(tmp);
                st.push(tmp2);
            }
            else{
                st.push(stoi(itr));
            }
        }
        int score=0;
        while(!st.empty()){
            score+=st.top();
            st.pop();
        }
        return score;
    }	
};