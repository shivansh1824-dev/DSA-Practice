/*class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(n+1,0);
        for(int x:nums){
            freq[x]++;
        }
        for(int i=0;i<n;i++){
            if(freq[i]>1){
                return i;
            }
        }
        return -1;
    }
};*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow != fast);
        slow=nums[0];
        while(slow != fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};