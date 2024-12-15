#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ii pair<ll ,ll>
const ll N = 2e6 + 276;
const ll M = 1e3 + 276;
ll n, a, b, t;
pair <ll , ll> node[N];

int solve() {
	cin >> n >> a >> b;
	string path; ll x = 0, y = 0, k = 0;
	cin >> path;
	path = '*' + path;
	for (int i = 1; i <= n; i++) {
		if (path[i] == 'N') y++;
		else if (path[i] == 'E') x++;
		else if (path[i] == 'S') y--;
		else if (path[i] == 'W') x--;
		node[++k] = make_pair(x, y);
		if (x == a && y == b) return cout << "YES" << endl, 0;
	}
	
	for (int i = 1; i <= n; i++) {
		if (a % node[i].first == 0 && b % node[i].second) {
			if (a / node[i].first == b/ node[i].second) return cout << "YES" << endl, 0;
		}
	}
	
	return cout << "NO" << endl , 0;
}
int main(){
	ios_base ::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << -2/1;
}