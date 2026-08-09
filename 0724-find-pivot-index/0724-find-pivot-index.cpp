class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        ans[0]=nums[0];
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            int leftSum=(i==0)?0:ans[i-1];
            int rightSum=(i==n-1)?0:ans[n-1]-ans[i];
            if(leftSum==rightSum){
                return i;
            }
        }
        return -1;
    }
};