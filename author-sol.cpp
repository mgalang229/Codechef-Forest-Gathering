#include <bits/stdc++.h>
 
using namespace std;

struct Tree {
	long long height;
	long long growth_rate;
};

bool Check(vector<Tree> a, long long w, long long l, long long months) {
	long long total_wood = 0;
	for (int i = 0; i < (int) a.size(); i++) {
		// check if the no. of months (passed argument) is greater than or equal to the
		// no. of months (calculated) needed in order to complete the condition (x >= l)
 		if (months >= ((l - a[i].height + a[i].growth_rate - 1) / a[i].growth_rate)) {
 			total_wood += a[i].height;
 			if (total_wood >= w) { // if the total wood is >= w, then there's no need to continue
 				return true;
 			}
 			total_wood += (months * a[i].growth_rate); // otherwise, increase the wood (by x months)
 			if (total_wood >= w) { // check again
 				return true;
 			}
 		}
 		if (total_wood >= w) {	
 			return true;
 		}
 	}
 	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, w, l;
	cin >> n >> w >> l;
	vector<Tree> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].height >> a[i].growth_rate;
	}
	long long ans = 0;
	long long low = 0;
	long long high = (long long) 1e18;
	while (low <= high) { // perform binary search for the months
		long long mid = low + (high - low) / 2;
		if (Check(a, w, l, mid)) { // if the calculated value is >= w, then change the upper bound
			ans = mid;
			high = mid - 1;	
		} else { // otherwise, change the lower bound
			low = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
