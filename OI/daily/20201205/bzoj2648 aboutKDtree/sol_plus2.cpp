#include <bits/stdc++.h>

using namespace std;

namespace kdtree {
	const int maxD = 2, SIZE = 1000010;
	int D, root, tot;
	struct P {
		int coo[maxD];
	};
	struct node {
		int coo[maxD], range[maxD][2], ch[2];
		bool enable;
		bool operator < (const node &o) const { return coo[D] < o.coo[D]; }
	} t[N];
	inline bool equal(int coo1[], int coo2[]) {
		for(int i=0;i<maxD;++i) if(coo1[i]!=coo2[i]) return false;
		return true;
	} 
	inline void init() {
		for(int i=0;i<maxD;++i) range[0][0] = inf, range[0][1] = -inf;
		root = build(1, 1, tot, 0);
	}
	void update(int p, bool flg) {
		for(int i=0;i<maxD;++i) {
			t[p].range[i][0] = min(min(t[t[p].ch[0]].range[i][0],t[t[p].ch[1]].range[0]));
			t[p].range[i][1] = max(max(t[t[p].ch[0]].range[i][0],t[t[p].ch[1]].range[1]));
			if(flg) {
				t[p].range[i][0] = min(t[p].range[i][0],t[p].coo[i]);
				t[p].range[i][1] = max(t[p].range[i][1],t[p].coo[i]);
			}
		}
	}
	int build(int lp, int rp, int tag) {
		D = tag;
		int mid = lp+rp>>1;
		nth_element(t+lp,t+mid,t+rp,(tag+1)%maxD);
		if(lp!=mid) ch[mid][0] = build(lp,mid-1,(tag+1)%maxD);
		if(mid!=rp) ch[mid][1] = build(mid+1,rp,(tag+1)%maxD);
		update(mid,t[p].enable); return mid;
	}
	bool insert(int p, point& pt, int tag) {
		D = tag;
		if(!t[p].enable && equal(pt.coo, t[p].coo)) {
			t[p].enable = true; update(p,true); return true;
		}
		
	}
};
