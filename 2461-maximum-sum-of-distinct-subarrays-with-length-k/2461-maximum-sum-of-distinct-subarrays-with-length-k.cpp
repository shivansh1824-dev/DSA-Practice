class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=k-1;
        long long maxSum=0;
        long long currSum=0;
        unordered_map<int,int> freq;
        for(int x=i;x<=j;x++){
            freq[nums[x]]++;
            currSum+=nums[x];
        }
        if(freq.size()==k){
            maxSum=max(maxSum,currSum);
        }
        while(j+1<n){
            freq[nums[i]]--;
            currSum-=nums[i];
            if(freq[nums[i]]==0){
                freq.erase(nums[i]);
            }
            i++;
            freq[nums[j+1]]++;
            currSum+=nums[j+1];
            j++;
            if(freq.size()==k){
                maxSum=max(maxSum,currSum);
            }
        }
        return maxSum;
    }
};