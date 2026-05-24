// 木棍需被切割的地方由小到大排列好
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); // IO 優化
    int L, N, cost[52][52], cut[52];
    for (int i=0; i<=50; ++i) cost[i][i+1] = 0; // 初始化：因為在 i 和 i+1 之間無法切一刀，所以為0
    
    while (cin>>L && L) { 
        cin >> N;
        cut[0] = 0; cut[N+1] = L;
        for (int i=1; i<=N; ++i) cin >> cut[i];
        
        for (int d=2; d<=N+1; ++d){
            for (int i=0; i<=N-d+1; ++i) {
                cost[i][i+d] = INT_MAX; // 求出 i 到 i+d 的最小 cost
                for (int j=i+1; j<i+d; ++j) {
                    int temp = cost[i][j] + cost[j][i+d];
                    if (temp < cost[i][i+d]) cost[i][i+d] = temp;
                }
                cost[i][i+d] += cut[i+d] - cut[i];
            }
        }
        cout << "The minimum cutting is " << cost[0][N+1] << ".\n";
    }
    return 0;
}
