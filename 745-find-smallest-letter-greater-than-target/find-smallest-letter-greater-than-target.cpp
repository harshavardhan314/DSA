class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        multiset<char>ms(letters.begin(),letters.end());
     
        auto it=ms.upper_bound(target);
        if(it!=ms.end())return *it;
        return letters[0];
        
    }
};