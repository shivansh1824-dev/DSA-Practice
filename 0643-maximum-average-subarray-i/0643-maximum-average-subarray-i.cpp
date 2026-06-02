class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long windowSum = 0;

        int left = 0;
        int right = 0;

        while (right < k) {
            windowSum += nums[right];
            right++;
        }

        long long bestSum = windowSum;

        while (right < nums.size()) {
            windowSum += nums[right];
            windowSum -= nums[left];

            bestSum = max(bestSum, windowSum);

            left++;
            right++;
        }

        return static_cast<double>(bestSum) / k;
    }
};