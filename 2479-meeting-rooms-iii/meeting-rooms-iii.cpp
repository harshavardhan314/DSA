class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<int>cnt(n,0);
        vector<long long >end_time(n,0);
        for(auto it:arr)
        {
            int start=it[0];
            int end=it[1];
            bool found=false;
            long long min_end_time=LLONG_MAX;
            int min_avail=0;
            for(int i=0;i<n;i++)
            {
                if(end_time[i]<=start)
                {
                    cnt[i]+=1;
                    end_time[i]=end;
                    found=true;
                    break;

                }

                if (min_end_time>end_time[i])
                {
                    min_end_time=end_time[i];
                    min_avail=i;
                }
                
            }
            if(!found)
            {
                
                end_time[min_avail]+=end-start;
                cnt[min_avail]+=1;
            }


        }
        int ans_idx=0;
        int ans_max=0;
        for(int i=0;i<n;i++)
        {
            if(cnt[i]>ans_max)
            {
                ans_idx=i;
                ans_max=cnt[i];
            }
        }
        return ans_idx;
        
    }
};