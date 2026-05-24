class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // 將兩端加入並排序
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();

        int dp[m][m];
        for(int i=0;i<=m-2;++i) dp[i][i+1] = 0;
        
        for (int d=2; d<=m-1; ++d){
            for (int i=0; i+d<=m-1; ++i) {
                dp[i][i+d] = INT_MAX; // 求出 i 到 i+d 的最小 cost
                for (int j=i+1; j<i+d; ++j) {
                    int temp = dp[i][j] + dp[j][i+d];
                    if (temp < dp[i][i+d]) dp[i][i+d] = temp;
                }
                dp[i][i+d] += cuts[i+d] - cuts[i];
            }
        }
        return dp[0][m-1];
    }
};
