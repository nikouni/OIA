#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;

//Arreglo de damas y caballeros
string D[MAXN],C[MAXN];
//Caché para programación dinámica
int DP[MAXN][MAXN];
//Arreglo para reconstruir el camino
pair<int,int> next[MAXN][MAXN];

int main () {
	freopen("portero.in","r",stdin);
	freopen("portero.out","w",stdout);

	ios_base::sync_with_stdio(false);

    int n,m,p;

    while( cin >> n) {
        set<pair<string,string> > P; //Parejas

        for(int i = 0; i < n ; i++)
            cin >> D[i];

        cin >> m;
        for(int i = 0; i < m ; i++)
            cin >> C[i];

        cin >> p;
        for(int i = 0; i < p ; i++) {
            string s;
            cin >> s;
            int guion = s.find('-');
            string mujer = s.substr(0,guion);
            string hombre = s.substr(guion+1,1000);
            P.insert(make_pair(mujer,hombre));
        }

        //Dinámica bottom-up
        for(int i = n ; i >=0 ; i--)
            for(int j = m ; j >= 0 ; j--) {
                if (i == n || j == m) {
                    DP[i][j] = 0;
                    continue;
                }
                //Si D[i] y C[j] son pareja
                if (P.count(make_pair(D[i],C[j]))) {
                    DP[i][j] = 1 + DP[i+1][j+1];
                    //En next guardo la dirección en que me moví
                    //para luego reconstruir el camino
                    next[i][j] = make_pair(1,1);
                }
                else {
                    DP[i][j] = max(DP[i+1][j],DP[i][j+1]);
                    if (DP[i+1][j] > DP[i][j+1])
                        next[i][j] = make_pair(1,0);
                    else
                        next[i][j] = make_pair(0,1);
                }
            }

        cout << DP[0][0] << endl;

        if (DP[0][0] == 0) continue;

        int i = 0 , j = 0;
        while(1) {
            pair<int,int> nex = next[i][j];
            if (nex == make_pair(1,1)) {
                cout << D[i] << " " << C[j] << endl;
                break;
            }
            i += nex.first;
            j += nex.second;
        }

    }

  return 0;

}


