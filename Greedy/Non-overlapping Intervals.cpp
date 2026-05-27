class Solution {
public:
    static bool cmp(vector<int>& v1, vector<int>& v2){
        return v1[1]<v2[1]; // <= 會 RE
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int k=0;
        int res=1;
        for(int i=1;i<n;++i){
            if(intervals[i][0]>=intervals[k][1]){ //活動不衝突
                k=i; ++res;
            }
        }
        return n-res;
    }
};
