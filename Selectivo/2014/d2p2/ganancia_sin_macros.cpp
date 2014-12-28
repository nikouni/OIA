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

/*
Definimos una función para comparar si un auto debe arreglarse antes que otro.
Se puede ver que conviene arreglar el auto A antes que el auto B si
la demora de A por la tarifa de B es menor a la demora de B por la tarifa de A.
*/
bool men(pair<int,int> A, pair<int,int> B) {
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
	    vector<pair<int,int> > v;
        for(int i = 0; i < A; i++) {
            cin >> D >> T >> P;
            //El precio lo sumo al principio, ya que es independiente del orden de los autos
            res += P;
            v.push_back(make_pair(D,T));
        }

        //Ordeno los autos según el comparador definido
        sort(v.begin(),v.end(),men);

        //Calculo la ganancia total
        int time = 0;
        for(int i = 0; i < A; i++) {
            res -= v[i].second * time;
            time += v[i].first;
        }

        cout << res << endl;
	}

  return 0;

}


