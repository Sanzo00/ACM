// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <algorithm>
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
struct Tree{
	int tot, rt[maxn], lson[maxn*40], rson[maxn*40], cnt[maxn*40];
	int build (int l, int r) {
		int o = ++tot;
		int mid = (l + r) >> 1;
		cnt[o] = 0;
		if (l != r) {
			lson[o] = build(l, mid);
			rson[o] = build(mid+1, r);
		}
		return o;
	}
	int update(int prev, int l, int r, int v) {
		int o = ++tot;
		int mid = (l + r) >> 1;
		lson[o] = lson[prev];
		rson[o] = rson[prev];
		cnt[o] = cnt[prev] + 1;
		if (l != r) {
			if (v <= mid) lson[o] = update(lson[o], l, mid, v);
			else rson[o] = update(rson[o], mid+1, r, v);
		}
		return o;
	}
	int query(int u, int v, int l, int r, int k) {
		if (l == r) return l;
		int mid = (l + r) >> 1;
		int num = cnt[lson[v]] - cnt[lson[u]];
		if (num >= k) return query(lson[u], lson[v], l, mid, k);
		else return query(rson[u], rson[v], mid+1, r, k-num);
	}
}T;
int arr[maxn], sz, a[maxn];
int get(int x) {
	return lower_bound(arr+1, arr+1+sz, x) - arr;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), arr[i] = a[i];
	sort(arr+1, arr+1+n);
	sz = unique(arr+1, arr+1+n) - arr - 1;
	T.tot = 0;
	T.rt[0] = T.build(1, sz);
	for (int i = 1; i <= n; ++i) {
		T.rt[i] = T.update(T.rt[i-1], 1, sz, get(a[i]));
	}
	for (int i = 0; i < m; ++i) {
		int l, r, k;
		scanf("%d %d %d", &l, &r, &k);
		printf("%d\n", arr[T.query(T.rt[l-1], T.rt[r], 1, sz, k)]);
	}
	return 0;
}