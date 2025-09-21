class MovieRentingSystem {
public:
    map<int,multiset<pair<int,int>>> mp; 
    set<pair<int,pair<int,int>>> st; 
    map<pair<int,int>,int> movie_to_price; 

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(int i=0;i<entries.size();i++) {
            int s=entries[i][0]; 
            int m=entries[i][1]; 
            int p=entries[i][2]; 
            mp[m].insert({p,s});
            movie_to_price[{m,s}] = p;
        }
      
    }

    vector<int> search(int movie) {
        vector<int> temp;
        for(auto i : mp[movie])
        {
            if(temp.size()<5)
            {
                temp.push_back(i.second); 
            }
            else break;
        }
            
        return temp;
    }

    void rent(int shop, int movie) {
        int price = movie_to_price[{movie,shop}];
        mp[movie].erase({price,shop});
        st.insert({price,{shop,movie}});
    }

    void drop(int shop, int movie) {
        int price = movie_to_price[{movie,shop}];
        st.erase({price,{shop,movie}});
        mp[movie].insert({price,shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt = 0;
        for(auto it : st) {
            ans.push_back({it.second.first, it.second.second});
            if(++cnt == 5) break;
        }
        return ans;
    }
};
