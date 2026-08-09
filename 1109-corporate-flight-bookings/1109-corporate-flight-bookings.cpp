class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(int i=0;i<bookings.size();i++){
            for(int j=bookings[i][0]-1;j<=bookings[i][1]-1;j++){
                ans[j] += bookings[i][2];
            }
        }
        return ans;
    }
};