class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int sz1=word1.length();
        int sz2=word2.length();
        int i=0;
        int j=0;
        string ans="";
        while(i<sz1 || j<sz2){
            if(i<sz1){
                ans+=word1[i];
                i++;
            }
            if(j<sz2){
                ans+=word2[j];
                j++;
            }
        }
        return ans;
    }
};