void rec(int idx,int n,string &temp,vector<string>&res){

    if(idx==n){
        res.push_back(temp);
        return;
    }
    if(idx==0 || temp[idx-1]=='1'){
        temp.push_back('0');
        rec(idx+1,n,temp,res);
        temp.pop_back();
        temp.push_back('1');
        rec(idx+1,n,temp,res);
        temp.pop_back();
    }
    else if(temp[idx-1]=='0'){
        temp.push_back('1');
        rec(idx+1,n,temp,res);
        temp.pop_back();
    }

    return;


}
class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string>res;
        string temp="";
        rec(0,n,temp,res);
        return res;

    }
};