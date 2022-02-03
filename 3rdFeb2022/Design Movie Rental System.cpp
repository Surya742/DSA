// Design Movie Rental System
// You have a movie renting company consisting of n shops. You want to implement a renting 
// system that supports searching for, booking, and returning movies. The system should also 
// support generating a report of the currently rented movies.

// Each movie is given as a 2D integer array entries where entries[i] = [shopi, moviei, pricei] 
// indicates that there is a copy of movie moviei at shop shopi with a rental price of pricei. 
// Each shop carries at most one copy of a movie moviei.

// The system should support the following functions:

// Search: Finds the cheapest 5 shops that have an unrented copy of a given movie. The shops should 
// be sorted by price in ascending order, and in case of a tie, the one with the smaller shopi should 
// appear first. If there are less than 5 matching shops, then all of them should be returned. If no 
// shop has an unrented copy, then an empty list should be returned.
// Rent: Rents an unrented copy of a given movie from a given shop.
// Drop: Drops off a previously rented copy of a given movie at a given shop.
// Report: Returns the cheapest 5 rented movies (possibly of the same movie ID) as a 2D list res where 
// res[j] = [shopj, moviej] describes that the jth cheapest rented movie moviej was rented from the shop 
// shopj. The movies in res should be sorted by price in ascending order, and in case of a tie, the one 
// with the smaller shopj should appear first, and if there is still tie, the one with the smaller moviej 
// should appear first. If there are fewer than 5 rented movies, then all of them should be returned. 
// If no movies are currently being rented, then an empty list should be returned.
// Implement the MovieRentingSystem class:

// MovieRentingSystem(int n, int[][] entries) Initializes the MovieRentingSystem object with n shops and the movies in entries.
// List<Integer> search(int movie) Returns a list of shops that have an unrented copy of the given movie as described above.
// void rent(int shop, int movie) Rents the given movie from the given shop.
// void drop(int shop, int movie) Drops off a previously rented movie at the given shop.
// List<List<Integer>> report() Returns a list of cheapest rented movies as described above.
// Note: The test cases will be generated such that rent will only be called if the shop has an unrented 
// copy of the movie, and drop will only be called if the shop had previously rented out the movie.

class MovieRentingSystem {
public://5,1
    unordered_map<int, unordered_map<int, int>> mp;
    unordered_map<int, unordered_map<int, int>> mpRef;
    map<pair<int,int>, int> rentedMovies;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
          for(auto it: entries){
              mp[it[0]][it[1]] = it[2];
              mpRef[it[0]][it[1]] = it[2];
          }
    }
    
    vector<int> search(int movie) {
        priority_queue<pair<int, int>> maxH;
        
        for(auto it: mp){
            int shop = it.first;
            auto movies = it.second;
            if(movies[movie]){
                int price = movies[movie];
                maxH.push({price, shop});
                if(maxH.size() > 5){
                    maxH.pop();
                }
            }
        }
        
        stack<pair<int,int>> st;
        while(!maxH.empty()){
            if(st.size() == 0){
                st.push(maxH.top());
                maxH.pop();
            }else{
                if(st.top().first == maxH.top().first){
                    pair<int,int> pr = st.top();
                    st.pop();
                    if(maxH.top().second > pr.second){
                        st.push(maxH.top());
                        st.push(pr);
                        maxH.pop();
                    }else{
                        st.push(pr);
                        st.push(maxH.top());
                        maxH.pop();
                    }
                }else{
                    st.push(maxH.top());
                    maxH.pop();
                }
            }
        }
        
        vector<int> ans;
        while(st.empty() == false){
            pair<int,int> pr = st.top();
            st.pop();
            ans.push_back(pr.second);
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        rentedMovies[{shop,movie}] = mp[shop][movie];
        mp[shop][movie] = 0;
    }
    
    void drop(int shop, int movie) {
        rentedMovies[{shop,movie}] = 0;
        mp[shop][movie] = mpRef[shop][movie];
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int,int>>> maxH;
        for(auto it: rentedMovies){
            if(it.second == 0) continue;
            maxH.push({it.second,{it.first.first, it.first.second}});
            if(maxH.size() > 5){
                maxH.pop();
            }
        }
        stack<pair<int,pair<int,int>>> st;
        while(!maxH.empty()){
            if(st.size() == 0){
                st.push(maxH.top());
                maxH.pop();
            }else{
                if(st.top().first == maxH.top().first){
                    pair<int,pair<int,int>> pr = st.top();
                    st.pop();
                    if(maxH.top().second.second > pr.second.second){
                        st.push(maxH.top());
                        st.push(pr);
                        maxH.pop();
                    }else{
                        st.push(pr);
                        st.push(maxH.top());
                        maxH.pop();
                    }
                }else{
                    st.push(maxH.top());
                    maxH.pop();
                }
            }
        }
        while(!st.empty()){
            pair<int,pair<int,int>> pr = st.top();
            st.pop();
            vector<int> v;
            v.push_back(pr.second.first);
            v.push_back(pr.second.second);
            ans.push_back(v);
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */