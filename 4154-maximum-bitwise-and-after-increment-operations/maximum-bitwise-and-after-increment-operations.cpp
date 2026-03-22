    // to get the y>=x we go from msb to lsb where we have :
    // x   y
    // 1   0---> keep as same as x
    // 1   1---> keep as same as x
    // 0   1---> this is the point where y > x and keep the remaining bits same ...
    // 0   0---> keep same

int get_ops(int x,int target){
    int y=0;
    bool match=true;
    for(int i=31;i>=0;i--){
        int curr_bit=1LL<<i;
        if(!(curr_bit&x) && (target&curr_bit))
        {
            match=false;
        }
        if(match){
            if(x&curr_bit)
            y|=curr_bit;
        }
        else{
            if(target&curr_bit)y|=curr_bit;
        }
    }
    return y-x;

}
class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {

        int n=nums.size();
        int mask=0;

        for(int i=30;i>=0;i--){

            vector<int>cost;
            for(int j=0;j<nums.size();j++){
                cost.push_back(get_ops(nums[j],mask|(1LL<<i)));
            }

            sort(cost.begin(),cost.end());
            int sum=0;
            for(int j=0;j<m;j++){
                sum+=cost[j];
                if(sum>k)break;
            }
            if(sum<=k)mask|=(1LL<<i);
        }
        return mask;
    }
};