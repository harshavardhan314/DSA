class Solution {
public:
    bool isTrionic(vector<int>&v) {
       int n = v.size();
       int last=0;
       for(int i=1;i<n;i++)
       {
        if(v[i]>v[i-1])last=i;
        else break;
       }
       if(last==0) return false;
       int middle=last;
       for(int i=middle+1;i<n;i++)
       {
        if(v[i]<v[i-1])middle=i;
        else break;
       }
       if(middle==last) return false;
       int end=middle;
       for(int i=middle+1;i<n;i++)
       {
        if(v[i]>v[i-1])end=i;
        else break;
       }
       cout<<last<<endl;
       cout<<middle<<endl;
       cout<<end<<endl;
       if(end==middle)return false;
       if(end==n-1) return true;
       return  false;

        
    }
};