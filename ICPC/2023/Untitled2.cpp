#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

const ll N = 1e5 + 276;
ll n, a[N], tree[N * 4], t;

void build_tree (int id, int l, int r) {
	if (l == r){
		tree[id] = a[l];
		return ;
	}
	int g = (l + r)/2;
	build_tree(id * 2, l, g);
	build_tree(id * 2 + 1, g + 1, r);
	
	tree[id] = tree[id * 2] +  tree[id * 2 + 1];
}

ll get_value (int id, int l, int r, int u, int v) {
	if (u > r || v < l) return 0;
	if (l == r) {
		return tree[id];
	}
	int g = (l + r)/2;
	get_value(id * 2, l, g, u, v);
	get_value(id * 2 + 1, g + 1, r, u, v);
	return get_value(id * 2, l, g, u, v) + get_value(id * 2 + 1, g + 1, r, u, v);
}

void update_tree (int id, int l, int r, int pos, int value) {
	if (l == r && r == pos) {
		tree[id] += value;	
		return ;
	}
	if (pos < l || pos > r) return;
	
	int g = (l + r)/2;	
	if (g < pos) update_tree(id * 2, l, g, pos, value);
	else update_tree(id * 2 + 1, g + 1, r, pos, value);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
 
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}	
	build_tree(1, 1, n);

	while (t--) {
		ll q, u, v;
		cin >> q >> u >> v;
		if (q == 1) {
			update_tree(1, 1, n, u, v);
		} else {
			cout << get_value(1, 1, n, u, v) << endl;
		}
	}
	
}