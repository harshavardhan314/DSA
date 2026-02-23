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
    string longestPalindrome(string s) {

        manacher m(s);
        int center=0;
        int max_len=1;
        for(int i=1;i<m.p.size()-1;i++){
            if(m.p[i]-1>max_len){
                max_len=m.p[i]-1;
                center=i;
            }
        }

        int st=(center-max_len)/2;
        return s.substr(st,max_len);

        

        
    }
};