#include <bits/stdc++.h>

namespace kdtree {
	const int maxD = 2, SIZE = 1000010, inf = 0x3f3f3f3f;
	int D = 0, root = 1, tot, ans;
	struct point {
		int coo[maxD];
		point() {}
		point(int x, int y) { coo[0] = x; coo[1] = y; }
	};
	struct node {
		int coo[maxD], range[maxD][2], ch[2];
		bool operator < (const node &o) const { return coo[D] < o.coo[D]; }
		node() {}
//		node(const node &o) {
//			for(int i=0;i<maxD;++i) coo[i] = o.coo[i], range[i][0] = o.range[i][0], range[i][1] = o.range[i][1], ch[0] = o.ch[0], ch[1] = o.ch[1];
//		}
	} t[SIZE];
	int build(int,int,int);
	void ist(int,point&,int);
	void qry(int,point&,int);
	inline void init(int l, int r) {
		for(int i=0;i<maxD;++i) t[0].range[i][0] = inf, t[0].range[i][1] = -inf;
		root = build(l, r, 0); tot = r; ans = inf;
	}
	inline int query(point &pt) {
		ans = inf; qry(root, pt, 0);
		return ans;
	}
	inline void insert(point& pt) {
		ist(root, pt, 0);
	}
	inline void update(int p) {
		for(int i=0;i<maxD;++i)
		t[p].range[i][0] = std::min(t[p].range[i][0],std::min(t[t[p].ch[0]].range[i][0],t[t[p].ch[1]].range[i][0])),
		t[p].range[i][1] = std::max(t[p].range[i][1],std::max(t[t[p].ch[0]].range[i][1],t[t[p].ch[1]].range[i][1]));
	}
	inline void newnode(int p, point& pt) {
		for(int i=0;i<maxD;++i) t[p].coo[i] = t[p].range[i][0] = t[p].range[i][1] = pt.coo[i];
		t[p].ch[0] = t[p].ch[1] = 0;
	} 
	int build(int lp, int rp, int tag) {
		int mid = lp + rp >> 1; D = tag;
		std::nth_element(t + lp, t + mid, t + rp + 1);
		for(int i=0;i<maxD;++i) t[mid].range[i][0] = t[mid].range[i][1] = t[mid].coo[i];
		if(lp != mid) t[mid].ch[0] = build(lp,mid-1,(tag+1)%maxD);
		if(mid != rp) t[mid].ch[1] = build(mid+1,rp,(tag+1)%maxD);
		update(mid);
		return mid;
	}
	void ist(int p, point &pt, int tag) {
		D = tag;
		if(pt.coo[D] < t[p].coo[D]) {
			if(t[p].ch[0]) ist(t[p].ch[0], pt, (tag+1)%maxD);
			else newnode(t[p].ch[0]=++tot, pt);
		} else {
			if(t[p].ch[1]) ist(t[p].ch[1], pt, (tag+1)%maxD);
			else newnode(t[p].ch[1]=++tot, pt);
		}
		update(p);
	}
	int get_dis(int coo1[], int coo2[]) {
		int ret = 0;
		for(int i=0;i<maxD;++i) ret += abs(coo1[i]-coo2[i]);
		return ret;
	}
	int get_eva(int coo[], int range[][2]) {
		int ret = 0;
		for(int i=0;i<maxD;++i) ret += std::max(range[i][0]-coo[i],0) + std::max(coo[i]-range[i][1],0);
		return ret;
	}
	void qry(int p, point &pt, int tag) {
		D = tag;
		ans = std::min(ans, get_dis(pt.coo,t[p].coo));
		int d[2];
		if(t[p].ch[0]) d[0] = get_eva(pt.coo, t[t[p].ch[0]].range); else d[0] = inf;
		if(t[p].ch[1]) d[1] = get_eva(pt.coo, t[t[p].ch[1]].range); else d[1] = inf;
		int mi = d[0]>=d[1];
		if(d[mi] < ans) qry(t[p].ch[mi], pt, (tag+1)%maxD);
		if(d[1-mi] < ans) qry(t[p].ch[1-mi], pt, (tag+1)%maxD);
	}
};

int main() {
	int n, m, x, y, t;
	std::cin >> n >> m;
	for(int i = 1; i <= n; ++i) std::cin >> kdtree::t[i].coo[0] >> kdtree::t[i].coo[1];
	kdtree::init(1, n);
	for(int i = 1; i <= m; ++i) {
		std::cin >> t >> x >> y;
		kdtree::point p(x, y);
		if(t == 1) {
			kdtree::insert(p);
		} else {
			std::cout << kdtree::query(p) << std::endl;
		}
	}
	return 0;	
}
