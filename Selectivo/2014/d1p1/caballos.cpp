/*

 Año: 2014
 Certamen: Selectivo
 Nivel: *
 Día: 1
 Problema: 1
 Tags: pd, ajedrez, tablero

*/

#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(a) int((a).size())

const int MAXN = 1010;
char T[MAXN][MAXN]; //Tablero: F x C
int DP[MAXN][MAXN][8]; //Memoria PD: F x C x 8

string W = "CABALLO"; //Palabra a buscar
int F,C,M;

//Direcciones de los movimientos del caballo
int di[] = {-1,-2,-2,-1,1,2,2,1};
int dj[] = {-2,-1,1,2,2,1,-1,-2};

/*
Implementación de la dinámica memoized.
Retorna la cantidad de formas de armar la palabra W[pos..]
partiendo de la casilla T[i][j]
*/
int dp(int i,int j,int pos) {

    if (W[pos] != T[i][j]) return 0;
    if (pos == si(W)-1) return 1;

    int &res = DP[i][j][pos];
    if (res != -1) return res; //Si ya está calculado, lo retorno

    res = 0;
    //Para cada uno de los 8 posibles movimientos del caballo
    forn(d,8) {
		//Genero la nueva posicion (ni,nj)
        int ni = i + di[d];
        int nj = j + dj[d];
        //Si (ni,nj) está dentro del tablero, llamo recursivamente
        if (ni >= 0 && nj >= 0 && ni < F && nj < C)
            res = (res + dp(ni,nj,pos+1)) % M;
    }

    return res;
}

//Inicializo DP
void init() {
    forn(i,F) forn(j,C) forn(k,8)
		DP[i][j][k] = -1;
}

int main () {
	freopen("caballos.in","r",stdin);
	freopen("caballos.out","w",stdout);

	//Optimización Entrada/Salida
	ios_base::sync_with_stdio(false);

	while(cin >> F >> C >> M) {
		init();

		forn(i,F)
			forn(j,C)
				cin >> T[i][j];

		int res = 0;

		forn(i,F)
			forn(j,C)
				res = (res + dp(i,j,0)) % M;

		cout << res << endl;
	}

    return 0;
}

/*

 Tiempo de ejecución: O(F * C * W.size())

*/
