class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans;
        
        for(int i = 0; i < board.size(); i++){
            vector<int> t;
            for(int j = 0; j < board[i].size(); j++){
                t.push_back(board[i][j]);
            }
            ans.push_back(t);
        }
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 0){
                    int cnt1 = 0;
                    int cnt0 = 0;
                    if(i+1 < board.size()){
                        if(board[i+1][j] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    if(i-1 >= 0){
                        if(board[i-1][j] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    if(j+1 < board[i].size()){
                        if(board[i][j+1] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    if(j-1 >= 0){
                        if(board[i][j-1] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    if(i-1 >= 0 && j-1 >= 0){
                        if(board[i-1][j-1] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    if(i-1 >= 0 && j+1 < board[i].size()){
                        if(board[i-1][j+1] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    if(i+1 < board.size() && j-1 >= 0){
                        if(board[i+1][j-1] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    if(i+1 < board.size() && j+1 < board[i].size()){
                        if(board[i+1][j+1] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    
                    if(cnt1 == 3){
                        ans[i][j] = 1;
                    }else{
                        ans[i][j] = 0;
                    }
                }
                else{
                    int cnt1 = 0;
                    int cnt0 = 0;
                    if(i+1 < board.size()){
                        if(board[i+1][j] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    if(i-1 >= 0){
                        if(board[i-1][j] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    if(j+1 < board[i].size()){
                        if(board[i][j+1] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    if(j-1 >= 0){
                        if(board[i][j-1] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    if(i-1 >= 0 && j-1 >= 0){
                        if(board[i-1][j-1] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    if(i-1 >= 0 && j+1 < board[i].size()){
                        if(board[i-1][j+1] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    if(i+1 < board.size() && j-1 >= 0){
                        if(board[i+1][j-1] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    if(i+1 < board.size() && j+1 < board[i].size()){
                        if(board[i+1][j+1] == 1){
                            cnt1++;
                        }else{
                            cnt0++;
                        }
                    }
                    
                    
                    if(cnt1 < 2 || cnt1 > 3){
                        ans[i][j] = 0;
                    }else{
                        ans[i][j] = 1;
                    }
                }
                
            }
            
        }
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                board[i][j] = ans[i][j];
            }
        }
    }
};