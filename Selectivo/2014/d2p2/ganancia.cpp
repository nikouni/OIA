/*

 Año: 2014
 Certamen: Selectivo
 Nivel: *
 Día: 1
 Problema: 1
 Tags: greedy, sorting

*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair

/*
Definimos una función para comparar si un auto debe arreglarse antes que otro.
Se puede ver que conviene arreglar el auto A antes que el auto B si
la demora de A por la tarifa de B es menor a la demora de B por la tarifa de A.
*/
bool men(pii A,pii B) {
    return A.first * B.second < B.first * A.second;
}

int main () {
	freopen("ganancia.in","r",stdin);
	freopen("ganancia.out","w",stdout);

	ios_base::sync_with_stdio(false);

	int A;

	while (cin >> A) {
	    int res = 0;
	    int D,T,P;
	    vector<pii> v;
        forn(i,A) {
            cin >> D >> T >> P;
            //El precio lo sumo al principio, ya que es independiente del orden de los autos
            res += P;
            v.pb(mp(D,T));
        }

        //Ordeno los autos según el comparador definido
        sort(all(v),men);

        //Calculo la ganancia total
        int time = 0;
        forn(i,A) {
            res -= v[i].second * time;
            time += v[i].first;
        }

        cout << res << endl;
	}

  return 0;

}


