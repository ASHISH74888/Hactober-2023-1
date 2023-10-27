class Solution {
public:

    int dp[1005][105][2];
    int helper(vector<int> arr, int i, int k, bool flag){
        if(i==arr.size()) return 0;

        if(dp[i][k][flag]!=-1) return dp[i][k][flag];

        int ans = INT_MIN;
        ans = helper(arr,i+1,k,flag);   // leave thar stock

        if(flag){
            ans = max(ans, helper(arr,i+1,k-1,false)+arr[i]);  // sell
        }else{
            if(k>0) ans = max(ans,helper(arr,i+1,k,true)-arr[i]);  // buy
        }
        return  dp[i][k][flag] = ans;
    }
    int maxProfit(int k, vector<int>& arr) {

        memset(dp,-1,sizeof dp);
        return helper(arr,0,k,false);
    }
};
