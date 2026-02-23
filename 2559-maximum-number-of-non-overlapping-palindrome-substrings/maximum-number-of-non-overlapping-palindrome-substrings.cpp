class manacher{
    public:
    vector<int>p;
    manacher(string &s){
        string temp="";
        temp+='^';
        for(int i=0;i<s.size();i++){
            temp+="#";
            temp+=s[i];
        }
        temp+="#$";
        p.assign(temp.size(),1);
        build(temp);
    }

    void build(string &s){
        int n=s.size();
        int l=1;
        int r=1;
        for(int i=1;i<s.size();i++){

            int mirror=l+r-i;

            p[i]=max(1,min(r-i,p[mirror]));

            while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]]==s[i-p[i]]){
                p[i]++;
            }

            if(i+p[i]>r){
                l=i-p[i];
                r=i+p[i];
            }
        }

    }

};




class Solution {
public:
    int maxPalindromes(string s, int k) {

        manacher m(s);
        vector<pair<int,int>>vp;
        int n=s.size();
        for(int i=0;i<m.p.size();i++){
            int len=m.p[i]-1;
            if(len>=k){
                int rem=len-k;
                int val=k;
                while(val%2 != len%2){
                    val++;
                }
                int st=(i-val)/2;
                vp.push_back({st,st+val-1});
            }
        }
        sort(vp.begin(),vp.end());
        int prev_end=-1;
        int cnt=0;
        for(auto [x,y]:vp){
            if(x>prev_end){
                prev_end=y;
                cnt++;
            }
        }
        return cnt;


        
    }
};