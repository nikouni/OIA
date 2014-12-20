#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen ("torneo.in", "r", stdin);
	freopen ("torneo.out", "w", stdout);
	
	int n;
	cin >> n;
	
	int G,E,P;
	int best = 0,max_point = 0;
	
	for(int i = 0 ; i < n ; i++) {
		
		cin >> G >> E >> P;
		
		int p = 3 * G + E;
		
		if (p > max_point) {
			max_point = p;
			best = i;
		}
	}
	
	cout << best + 1 << endl;
	
	return 0;
}
