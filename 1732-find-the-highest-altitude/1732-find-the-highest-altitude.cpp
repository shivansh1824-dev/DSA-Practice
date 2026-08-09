class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n =gain.size();
        vector<int> ans(n+1,0);
        ans[0]=0;
        int maxAlt=0;
        for(int i=0;i<n;i++){
            ans[i+1]=ans[i]+gain[i];
            maxAlt=max(maxAlt,ans[i+1]);
        }
        return maxAlt;
    }
};