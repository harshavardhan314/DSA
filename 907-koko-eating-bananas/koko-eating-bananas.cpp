bool can_eat(long long int mid,vector<int>&piles,int h){
    int val=0;
    int n=piles.size();
    for(int i=0;i<n;i++){
        val+=piles[i]/mid;
        if(piles[i]%mid)val++;
    }
    return val<=h;
}
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hours) {
        long long int l=1;
        long long int h=accumulate(piles.begin(),piles.end(),0LL);
        long long int ans=h;
        while(l<=h){
            long long int mid=(l+h)/2;
            if(can_eat(mid,piles,hours)){
                ans=min(ans,mid);
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return (int)ans;
    }
};