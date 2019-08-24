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