#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, L; cin >> n >> L;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i){
		int x, time; cin >> x >> time;
		v.push_back({time, x});
	}
	long long ans = 0;
	// 優先依照切的時間點排序
	sort(v.begin(), v.end());
	
	set<int> st;
	st.insert(0); st.insert(L);
	for (int i = 0; i < n; i++){
	    // lower_bound 會找到 set 中第一個大於等於 v[i].second 的元素，這就是新切點的右邊界 (right)
		auto it = st.lower_bound(v[i].second);
		// prev(it) 則是該元素的上一個元素，即為新切點的左邊界 (left)
		int left = *prev(it), right = *it;
		ans += right - left;
		st.insert(v[i].second);
	}
	cout << ans;
}
