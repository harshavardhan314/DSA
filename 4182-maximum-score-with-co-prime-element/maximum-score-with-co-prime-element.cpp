class Solution {
public:
    int maxScore(vector<int>& nums, int maxVal) {

        int limit=-1;
        for(int i=0;i<nums.size();i++)
        {
            limit=max(limit,nums[i]);
        }
        limit=max(limit,maxVal);
        vector<int> freq(limit+1,0);
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        vector<int> multiples(limit+1,0);
        for(int i=1;i<=limit;i++)
        {
            for(int j=i;j<=limit;j+=i)
            {
                multiples[i]+=freq[j];
            }
        }
        vector<int> spf(limit+1);
        for(int i=1;i<=limit;i++)
        spf[i]=i;

        for(int i=2;i<=limit;i++)
        {
            if(spf[i]==i){
            for(int j=i;j<=limit;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=limit;i++)
        {
            if (i > maxVal && freq[i] == 0) {
                continue;
            }
            int score=0;
            if (i==1) {
            if (freq[1] > 0) {
                score = 1; 
            } else {
                score = 0;
            }
        }
        else
        {
            vector<int> primes;
            int temp=i;
           
            while(temp>1)
            {
                 int val=spf[temp];
            primes.push_back(val);
                while(temp%val==0)
                {
                    temp/=val;
                }
                
            }
            int sz=primes.size();
            int k=(1<<sz);
            int non_coprimes=0;
            for(int mask=1;mask<k;mask++)
            {
                int product=1;
                int count_primes=0;
                for(int j=0;j<k;j++)
                {
                    if(mask&(1LL<<j))
                    {
                        count_primes++;
                        product*=primes[j];
                    }
                }
                if(count_primes%2==1)
                {
                  non_coprimes+=multiples[product];
                }
                else
                {
                    non_coprimes-=multiples[product];

                }


            }
            if(freq[i]>0)
            {
                score=i-non_coprimes+1;
            
            }
            else if(non_coprimes>0)
            {
                score=i-non_coprimes;
            }
            else
            {
                score=i-1;
            }
            

        }
        ans=max(ans,score);

        }

        return ans;
        
    }
};