class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gp) {
        multiset<int>ms;
        int n=hand.size();
    
        for(auto it:hand){
            ms.insert(it);
        }
        if(n%gp!=0)return false;

        int val=n/gp;
        while(val>0){
            int temp=gp;
            int st_element=*ms.begin();
            while(temp>0){
                if(ms.find(st_element)==ms.end()){
                    return false;
                }
                ms.erase(ms.find(st_element));
                temp--;
                st_element++;
                
            }
            val--;
        }
        return true;
        
    }
};