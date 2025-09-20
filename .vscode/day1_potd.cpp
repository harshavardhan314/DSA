#include<bits/stdc++.h>
using namespace std;
class Router {   
public: 
    unordered_map<string,vector<int>>mp;
    queue<string>q;
    map<int,vector<int>>time;
    int max_size;

    Router(int memoryLimit) {
        max_size=memoryLimit;
    }
    
    bool addPacket(int s, int d, int t) {



        string key=to_string(s)+'_'+to_string(d)+'_'+to_string(t);

        if(mp.find(key)!=mp.end()) return false;
        if(q.size()>=max_size)
        {
            forwardPacket();
        }
        q.push(key);
        mp[key]={s,d,t};
        time[d].push_back(t);
        return true;

        
    }
    
    vector<int> forwardPacket() {

        if(q.size()==0)return {};

        string key=q.front();
        q.pop();
        vector<int>val=mp[key];
        mp.erase(key);
        int d=val[1];
        time[d].erase(time[d].begin());
        return val;
        
    }
    
    int getCount(int d, int s, int e) {

        int cnt=0;
        auto it=time.find(d);
        if(it==time.end() || it->second.empty()) return 0;
       
        int right=upper_bound(begin(it->second),end(it->second),e)-begin(it->second);
        int left=lower_bound(begin(it->second),end(it->second),s)-begin(it->second);

       
        return right-left;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */