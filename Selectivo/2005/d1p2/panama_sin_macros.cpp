/*

 Año: 2005
 Certamen: Selectivo
 Nivel: *
 Día: 1
 Problema: 2
 Tags: bfs

*/

#include <bits/stdc++.h>

using namespace std;

//Estructura para una celda del mapa
struct celda {
    int x,y,cost;

    celda(int _x = 0, int _y = 0, int _cost = 0) {
        x = _x;
        y = _y;
        cost = _cost;
    }

};

const int MAXN = 1000 + 10;

//Mapa
char T[MAXN][MAXN];
//Visitados
bool done[MAXN][MAXN];
int n,m;
//Direcciones de los movimientos posibles
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

//Se realiza un bfs con dos colas, una para las A y otra para las L
//Las A se procesan de forma prioritaria, ya que tienen costo 0
//La función retorna el camino mínimo o -1 en caso de que no exista camino
int bfs() {
    queue<celda> A,L;
    //Inicialmente agrego la celda superior derecha
    A.push(celda(0,0,0));
    done[0][0] = true;

    while(!A.empty() || !L.empty()) {
        celda u;
        //Si la cola de A's no está vacía, extraigo la próxima celda
        if (!A.empty()) {
            u = A.front();
            A.pop();
        }
        //Si no, la próxima celda es una L
        else {
            u = L.front();
            L.pop();
        }

        //Si llegué a la última fila, devuelvo el costo
        if (u.x == n-1) return u.cost;

        //Para cada una de las 4 direcciones
        for(int d = 0 ; d < 4 ; d++) {
            //Calculo la celda vecina
            int nx = dx[d] + u.x;
            int ny = dy[d] + u.y;

            //Si la celda está dentro del mapa
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                //Si ya está visitada, la salteo
                if (done[nx][ny]) continue;
                done[nx][ny] = true;

                //Agrego la nueva celda a la cola correspondiente
                if (T[nx][ny] == 'A')
                    A.push(celda(nx,ny,u.cost));
                else if (T[nx][ny] == 'L')
                    L.push(celda(nx,ny,u.cost+1));

            }
        }
    }

    return -1;
}

void init() {
    for(int i = 0 ; i < n ; i++)
        for(int j = 0; j < m ; j++)
            done[i][j] = false;
}

int main () {
	freopen("panama.in","r",stdin);
	freopen("panama.out","w",stdout);

	ios_base::sync_with_stdio(false);

	while(cin >> n >> m) {

	    init();

        for(int i = 0 ; i < n ; i++)
            for(int j = 0; j < m ; j++)
                cin >> T[i][j];

        int res = bfs();

        if (res == -1) {
            cout << "NO" << endl;
            cout << 0 << endl;
        }
        else {
            cout << "SI" << endl;
            cout << res << endl;
        }
	}

  return 0;
}


