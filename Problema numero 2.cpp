//codigo del problema del salto del caballo

//const = constante
// N = dimension del tablero
// [N][N] = las dimenciones del tablero (8*8)
// d = la matriz que va a almecenar de los movimientos que va a tener (lo que esta en llaves, los cuales son moviemientos en l, que el caballo puede realizar en el tablero de la matriz)
// void = escribir tablero
// int i,j; = interadores, y (j) porque exactamente los creo, 
// i = controla las filas y j = las columnas
// (i=0;i<N;i++) = el i, que comience en 0, hasta que i sea menor que N, i++ para que incremente
// cout<<tablero[i][j]<<"|" = para mostrar el tablero, "|" = para separar
// cout<<endl; = para separar las filas y el 2 para separar un tablero del otro
// el 2 void es para los saltos y tendra 4 parametros (#1 numeros de movimientos que copiamos en la matriz (int i), #2 las coordenadas iniciales del tablero (int x, int y), #3 una variable bool, para pasar de referencia la cual sera el (&exito), esta variable ayudara a saber si es que ya recorrimos el tablero o si aun no)
// int nx, ny; = para almacenar las coordenadas que el caballo va a tomar cuando se mueva
// while((k<8) && !exito) = mientras no se alla terminado el #de movimientos que podemos hacer y ademas sino hemos obtenido exito
// lo que esta adentro del do = para las nuevas coordenadas que va a tener el caballo cuando se mueva
// if = para darse cuenta si es que las nuevas coordenadas que uno acabara de obtener, estan en rango de el tablero
// && (tablero[nx][ny]==0)) = para evitar que visitemos las casillas 2 veces
// if(i < N*N) = si i es menor a la cantidad de casillas que tiene el tablero, indica que podemos seguir llenando las casillas del tablero y cuando no se cumpla indica que el tablero esta lleno
// if ( !exito ) = si exito es falso, al tablero regresalo a 0
// else { exito = true; } = sino es verdadero
// int fila=1; int col; = para controlar (filas y columnas)
// if (exito) = si todo sale bien, para que me diga lo que esta en (cout<<""<<emdl;) y si no (else) no encontrado
// 

#include <iostream>
using namespace std;

const int N = 3;
int tablero[N][N];

//desplazamientos relativos del caballo
int d[20][2] = {{1,-1},{-1,-1},{1,0},{-2,2},{2,0},{1,-1},{1,-1},{1,0},{1,-1},{1,-1},{-1,0}};
void escribirTablero()
{
	int i,j;
	
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			cout<<tablero[i][j]<<"|";
        }
		cout<<endl;
	}
	cout<<endl;
}

void saltoCaballo(int i, int x, int y, bool &exito)
{
	int nx, ny;
	int k=0; //interador para controlar los desplazamientos del caballo
	exito = false;
	
	do
	{
		k++;
		nx = x + d[k-1][0];
		ny = y + d[k-1][1];
		
		//verificando si las coordenadas son correctas
		if ((nx>=0) && (nx<N) && (ny>=0) && (ny<N) && (tablero[nx][ny]==0))
		{
		    //Guardamos el movimiento
		    tablero[nx][ny] = i;
		    escribirTablero(); //mostrando como el caballo se mueve
		    
		    if(i < N*N){
		    	saltoCaballo(i+1,nx,ny,exito);
		    	
		    	if ( !exito )
				{
		    		tablero[nx][ny] = 0;
				}
			}
			else 
			{
				exito = true;
			}
		}
    }while((k<8) && !exito);
}
	

int main (){
	bool exito;
	int fila=1;
	int col=2;
	
	tablero[fila][col] = 1;
	saltoCaballo(2,fila,col,exito);
	
	if (exito){
		cout<<"Camino Encontrado"<<endl;
		escribirTablero();
	}
	else{
		cout<<"Camino No Encontrado"<<endl;
	}
	
	return 0;
}


























