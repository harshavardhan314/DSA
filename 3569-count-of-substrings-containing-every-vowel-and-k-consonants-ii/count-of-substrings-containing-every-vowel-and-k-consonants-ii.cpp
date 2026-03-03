bool isvowel(char ch){
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' ||ch=='u';
}

class Solution {
public:

    long long countOfSubstrings(string word, int k) {

        int n=word.size();
        vector<int>next(n);
        int lastc=n;
        for(int i=n-1;i>=0;i--){
            next[i]=lastc;
            if(!isvowel(word[i]))lastc=i;
            
        }
        int l=0;
        int c=0;
        long long ans=0;
        unordered_map<char,int>mp;
        for(int r=0;r<n;r++){

            if(isvowel(word[r]))mp[word[r]]++;
            else c++;

            while(l<r && c>k){
                if(!isvowel(word[l]))c--;
                else
                {
                    mp[word[l]]--;
                    if(mp[word[l]]==0)mp.erase(word[l]);
                }
                l++;
            }

            while(l<r && c==k && mp.size()==5){
                ans+=next[r]-r;

                if(!isvowel(word[l]))c--;
                else
                {
                    mp[word[l]]--;
                    if(mp[word[l]]==0)mp.erase(word[l]);
                }
                l++;

            }


        }
        return ans;

        
    }
};