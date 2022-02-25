class Solution {
public:
    string strWithout3a3b(int a, int b) {
        // if(a == 0 && b == 0 && c > 2){
        //     return "cc";
        // }
        // if(b == 0 && c == 0 && a > 2){
        //     return "aa";
        // }
        // if(a == 0 && c == 0 && b > 2){
        //     return "bb";
        // }
        string ans = "";
        priority_queue<pair<int,char>> pq;
        pq.push({a,'a'});pq.push({b,'b'});
        
        while(pq.top().first != 0){
            string t = "";
            auto it1 = pq.top();
            pq.pop();
            if(it1.first > 0){
                t.push_back(it1.second);
                it1.first--;
            }
            pq.push(it1);
            auto it3 = pq.top();
            pq.pop();
            if(it3.first > 0){
                t.push_back(it3.second);
                it3.first--;
            }
            auto it2 = pq.top();
            pq.pop();
            if(it2.first > 0){
                t.push_back(it2.second);
                it2.first--;
            }
            ans += t;
            pq.push(it2);
            pq.push(it3);
        }
        int cnt = 1;
        for(int i = ans.length()-2; i >= 0; i--){
            if(ans[i] == ans[ans.length()-1]){
                cnt++;
            }else{
                break;
            }
        }
        string mainAns = "";
        if(cnt > 2){
            char extra = ans[ans.length()-1];
            for(int i = 0; i <= ans.length()-1-cnt; i++){
                mainAns.push_back(ans[i]);
            }
            mainAns.push_back(extra);
            mainAns.push_back(extra);
        }
        return mainAns.length() == 0 ? ans : mainAns;
    }
};