class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n=gas.size();
        int curr=0;
        int st=-1;
        for(int i=0;i<2*n;i++){
            
            if(i<n && st==-1)
            st=i;
            curr+=gas[i%n]-cost[i%n];
            if(curr<0){
                st=-1;
                curr=0;
            }
        }
        return st;
    }
};