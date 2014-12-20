#include <bits/stdc++.h>
using namespace std;

bool figu[100100];

int main(){
	freopen ("figuritas.in", "r", stdin);
	freopen ("figuritas.out", "w", stdout);
	
	int F;
	cin >> F;
	int x;
	
	for(int i = 0 ; i < F-1 ; i++) {
		cin >> x;
		figu[x] = true;
	}
	
	for(int i = 1 ; i <= F ; i++)
		if (!figu[i]) cout << i << endl;
	
	return 0;
}
