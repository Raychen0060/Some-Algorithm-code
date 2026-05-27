class Solution {
public:
    int latestNonConflict(const vector<vector<int>>& v, int idx){
        int low=0, high=idx-1; // 往回找
        while(low<=high){
            int mid=(high+low)>>1;
            // 如果 mid 號活動的結束時間 <= 目前活動的開始時間，代表不衝突
            if(v[mid][0] <= v[idx][1]){
                // 檢查下一個活動是否也不衝突？我們想找的是「最晚」結束的活動
                if (v[mid + 1][0] <= v[idx][1]) low=mid+1; // 繼續往右找
                else return mid + 1; // 找到了！回傳 1-based index
            } else high = mid - 1; // 衝突了，代表 mid 太晚結束，往左找
        }
        return 0; // 找不到在活動 idx 開始之前，就已經結束的最晚活動
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        // 將三個屬性綁定在一起，格式定為 {endTime, startTime, profit}
        // 使用 vector<vector<int>> 或 vector<array<int, 3>> 皆可
        vector<vector<int>> acts(n, vector<int>(3));
        for(int i = 0; i < n; ++i) acts[i] = {endTime[i], startTime[i], profit[i]};
        sort(acts.begin(),acts.end());
        
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;++i){
            int p=latestNonConflict(acts, i-1);
            dp[i]=max(dp[i-1],(dp[p]+acts[i-1][2]));
        }
        return dp[n];
    }
};
