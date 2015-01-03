#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef set<int> se;
typedef pair<int,int> pii;
typedef long long int tint;

#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define rall(c) (c).rbegin(), (c).rend()
#define all(c) (c).begin(), (c).end()
#define D(a) << #a << "=" << a << " "


#define si(a) int((a).size())
#define pb push_back
#define mp make_pair

const int MAXN = 1000 + 10;

//Arreglo de damas y caballeros
string D[MAXN],C[MAXN];
//Cach� para programaci�n din�mica
int DP[MAXN][MAXN];
//Arreglo para reconstruir el camino
pii next[MAXN][MAXN];


int main () {
	freopen("portero.in","r",stdin);
	//freopen("portero.out","w",stdout);

	ios_base::sync_with_stdio(false);

    int n,m,p;

    while( cin >> n) {
        set<pair<string,string> > P; //Parejas

        forn(i,n)
            cin >> D[i];
        cin >> m;
        forn(i,m)
            cin >> C[i];
        cin >> p;
        forn(i,p) {
            string s;
            cin >> s;
            int guion = s.find('-');
            string mujer = s.substr(0,guion);
            string hombre = s.substr(guion+1,1000);
            P.insert(mp(mujer,hombre));
        }

        //Din�mica bottom-up
        dforsn(i,0,n+1)
            dforsn(j,0,m+1) {
                if (i == n || j == m) {
                    DP[i][j] = 0;
                    continue;
                }
                if (P.count(mp(D[i],C[j]))) {
                    DP[i][j] = 1 + DP[i+1][j+1];
                    //En next guardo la direcci�n en que me mov�
                    //para luego reconstruir el camino
                    next[i][j] = mp(1,1);
                }
                else {
                    DP[i][j] = max(DP[i+1][j],DP[i][j+1]);
                    if (DP[i+1][j] > DP[i][j+1])
                        next[i][j] = mp(1,0);
                    else
                        next[i][j] = mp(0,1);
                }
            }

        cout << DP[0][0] << endl;

        if (DP[0][0] == 0) continue;

        int i = 0,j=0;

        while(1) {
            pii nex = next[i][j];
            if (nex == mp(1,1)) {
                cout << D[i] << " " << C[j] << endl;
                break;
            }
            i += nex.first;
            j += nex.second;
        }

    }


  return 0;

}


