/*

 Año: 2014
 Certamen: Selectivo
 Nivel: *
 Día: 1
 Problema: 1
 Tags: bruteforce

*/

/*
Me pareció importante mencionar esta solución porque, aunque no va a estar
cerca de sacar 100 puntos, es trivial pensarla y usando next_permutation se
puede programar MUY rápido y fácil. Solución ideal para cuando nos quedan 20
minutos de prueba, :-)
Lo que hacemos es simplemente probar todos los órdenes posibles y quedarnos
con el mejor.
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50 + 5;

int D[MAXN];
int T[MAXN];

int main () {
	freopen("ganancia.in","r",stdin);
	freopen("ganancia.out","w",stdout);

	ios_base::sync_with_stdio(false);

	int A,P;

	while (cin >> A) {
	    int res = 0;

        for(int i = 0; i < A; i++) {
            cin >> D[i] >> T[i] >> P;
            res += P;
        }

        //Creo un vector {0,1,2,...,A-1} que va a representar un orden de autos
        vector<int> perms;
        for(int i = 0; i < A; i++) {
            perms.push_back(i);
        }

        int best = INT_MAX;
        //Itero por los n! ordenes posibles y calculo el valor para cada uno
        do {
            int time = 0;
            int cost = 0;
            for(int i = 0; i < A; i++) {
                cost += T[perms[i]] * time;
                time += D[perms[i]];
            }
            best = min(best,cost);
        } while ( next_permutation(perms.begin(),perms.end()) );

        res -= best;

        cout << res << endl;
	}

  return 0;

}


