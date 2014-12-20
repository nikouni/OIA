#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen ("chocolates.in", "r", stdin);
	//freopen ("chocolates.out", "w", stdout);
	
	int n;
	cin >> n;
	
	int men = 1<<20;
	int may = 0;
	
	int x;
	for(int i = 0; i < n ; i++) {
		cin >> x;
		may = max(may,x);
		men = min(men,x);
	}
	
	cout << ((may - men >2)?'S':'N') << endl;
	
	return 0;
}
