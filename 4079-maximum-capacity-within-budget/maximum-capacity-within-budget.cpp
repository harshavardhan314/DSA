class Solution {
public:
    int maxCapacity(vector<int>& c, vector<int>& cap, int b) {

        vector<pair<int,int>>vp;
        int ans=0;
        int n=c.size();
        for(int i=0;i<n;i++)
        {
            vp.push_back({c[i],cap[i]});
            if(c[i]<b)
            ans=max(ans,cap[i]);
        }
        sort(vp.begin(),vp.end());

        vector<int>pre_max(n,0);
        pre_max[0]=vp[0].second;
        for(int i=1;i<n;i++)
        {
            pre_max[i]=max(pre_max[i-1],vp[i].second);
        }

        for(int i=1;i<n;i++)
        {
            int rem=b-vp[i].first-1;
            int l=0; int h=i-1;
            int idx=-1;
            while(l<=h)
            {
                int mid=(l+h)/2;
                if(vp[mid].first<=rem)
                {
                    idx=mid;
                    l=mid+1;
                }
                else
                h=mid-1;
            }
            if(idx>=0)
            ans=max(ans,vp[i].second+pre_max[idx]);

        }
        return ans;
        
        
        
    }
};