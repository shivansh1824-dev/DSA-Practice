class Solution {
public:
    string removeOccurrences(string s, string part){
        int k=part.length();
        string ans;
        for(char ch:s){
            ans.push_back(ch);
            if(ans.length()>=k && ans.substr(ans.length()-k)==part){
                ans.erase(ans.length()-k);
            }
        }
        return ans;
    }
};