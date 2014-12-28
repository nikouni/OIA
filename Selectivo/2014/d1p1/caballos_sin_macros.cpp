/*
 
 Año: 2014
 Certamen: Selectivo
 Problema: 1
 Tags: pd, ajedrez, tablero
 
*/

#include <bits/stdc++.h>

using namespace std;

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
    if (pos == W.size()-1) return 1;

    int &res = DP[i][j][pos];
    if (res != -1) return res; //Si ya está calculado, lo retorno

    res = 0;
    //Para cada uno de los 8 posibles movimientos del caballo
    for(int d = 0; d < 8 ; d++) {
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
    for(int i = 0; i < F; i++)
		for(int j = 0; j < C; j++)
			for(int k = 0; k < 8; k++)
                DP[i][j][k] = -1;
}

int main () {
	freopen("caballos.in","r",stdin);
	freopen("caballos.out","w",stdout);

	//Optimización Entrada/Salida
	ios_base::sync_with_stdio(false);

	while(cin >> F >> C >> M) {
		init();

		for(int i = 0; i < F; i++)
			for(int j = 0; j < C; j++)
				cin >> T[i][j];

		int res = 0;

		for(int i = 0; i < F; i++)
			for(int j = 0; j < C; j++)
				res = (res + dp(i,j,0)) % M;

		cout << res << endl;		
	}
    
    return 0;
}

/*
 
 Tiempo de ejecución: O(F * C * W.size())
 
*/
