class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        vector<int>v;
        int n=gas.size();
        int val=0;
        int st=0;
        int total_gas=0;
        for(int i=0;i<n;i++){

            int diff=gas[i]-cost[i];
            total_gas+=diff;
            val+=diff;
            if(val<0){
                val=0;
                st=i+1;
            }

        }
        return total_gas<0? -1 : st;
          
        
    }
};