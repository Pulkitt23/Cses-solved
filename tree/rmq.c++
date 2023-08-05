class Segtree{
public:
	vector<int> seg;
	int sz = 0;
	Segtree(vector<int> a){
		int n = a.size();
		seg.assign(2*n, INT_MAX);
		sz = n;
		for(int i =0 ; i < n; i++){
			seg[n + i] = a[i];
		}
		for(int i = n - 1; i >= 1; i--){
			seg[i] = min(seg[2*i], seg[2*i + 1]);
		}
	}

	void update(int ind, int val){
		ind = sz + ind;
		while(ind >= 1){
			seg[ind] = val;
			ind /= 2;
		}
	}

	int query(int l, int r){
		l += sz;
		r += sz;
		int ans = INT_MAX;
		while(l < r){
			if(l%2){
				ans = min(ans, seg[l]);
				l++;
			}
			if(r%2){
				r--;
				ans = min(ans, seg[r]);
			}
			l /= 2;
			r /= 2;
		}
		return ans;
	}
};
