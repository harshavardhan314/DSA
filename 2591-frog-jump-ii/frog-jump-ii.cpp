bool check(int mid,vector<int>&stones){

    int ans=stones[1]-stones[0];
    int n=stones.size();
    for(int i=2;i<n;i++){
        ans=max(ans,stones[i]-stones[i-2]);
    }
    return ans<=mid;
    
}

class Solution {
public:
    int maxJump(vector<int>& stones) {

        int n=stones.size();
        int l=0;
        int h=stones.back()-stones[0]+1;
        int ans=h;

        if(n==2){
            return stones[1]-stones[0];
        }
        while(l<=h){
            int mid=(l+h)/2;
            if(check(mid,stones)){
                ans=min(ans,mid);
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};