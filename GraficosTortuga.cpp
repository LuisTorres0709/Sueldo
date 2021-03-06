#include <iostream>
using namespace std;
void plumaabajo(bool &pluma); //Se usan con TRUE y FALSE (minuscula)
void plumaarriba(bool &pluma);
void giraderecha(int &direccion);
void giraizquierda(int &direccion);
void avanzar(char mat[][20], int renglones, int &posicionx,int &posiciony, int avance, int direccion, bool pluma);
void mostrar(char mat[][20],int renglones);
void centinela(int posicionx, int posiciony, bool pluma, int direccion);
int menu();


int main()
{
	int comando, direccion=2, avance, posicionx=0, posiciony=0;
	bool pluma=false; //Inicializamos la pluma hacia arriba
	char piso[20][20];
	for (int renglon = 0; renglon < 20; renglon++) {
		for (int columna = 0; columna < 20; columna++) {
			piso[renglon][columna] =' ';
		}
	}// Limpiamos el piso
	cout << "La tortuga inicia en el renglón 1 y columna 1 con la pluma hacia arriba mirando a la derecha...";
	do {
		comando = menu();
		switch (comando) {
		case 1:
			plumaarriba(pluma);
			break;
		case 2:
			plumaabajo(pluma);
			piso[posiciony][posicionx] = '*';
			break;
		case 3:
			giraderecha(direccion);
			break;
		case 4:
			giraizquierda(direccion);
			break;
		case 5:
			cout << "Cuantos pasos quieres avanzar?";
			cin >> avance;
			avanzar(piso,20,posicionx,posiciony, avance,direccion,pluma);
			avance = 0;
			if (pluma == true) {
				piso[posiciony][posicionx] = '*';
			}
			break;
		case 6:
			mostrar(piso, 20);
			break;
		case 7:
			centinela(posicionx, posiciony,pluma, direccion);
			break;
		default:
			break;
		}
	} while (comando != 0);
    return 0;
}
int menu() {
	int opcion;
	cout << "1.- Dirigir pluma hacia arriba\n" <<
		"2.- Dirigir pluma hacia abajo\n" <<
		"3.- Girar a la derecha\n" <<
		"4.- Girar a la izquierda\n" <<
		"5.- Avanzar\n" <<
		"6.- Mostrar el piso\n" <<
		"7.- Funcion centinela (te pone al tanto del estado de la tortuga)\n" <<
		"Presiona 0 para salir...\n";
	cin >> opcion;
	return opcion;
}
void plumaabajo(bool &pluma) {
	pluma = true;
}
void plumaarriba(bool &pluma) {
	pluma = false;
}
void giraderecha(int &direccion) {
	direccion++;
	if (direccion > 4) {
		direccion = 1;
	}
}
void giraizquierda(int &direccion) {
	direccion--;
	if (direccion < 1) {
		direccion = 4;// si esta mirando hacia arriba, mirará hacia la izquierda
	}
}
void avanzar(char mat[][20],int renglones,int &posicionx, int &posiciony, int avance, int direccion, bool pluma) {
	int paso = 0;
	if (pluma == true) {
		if (direccion == 2) { //Se avanza a la derecha
			while (paso != avance && posicionx < 19) {
				mat[posiciony][posicionx] = '*';
				posicionx++;
				paso++;
			}
		}
		else if (direccion == 3) { //Se avanza hacia abajo
			while (paso != avance && posiciony < 19) {
				mat[posiciony][posicionx] = '*';
				posiciony++;
				paso++;
			}
		}
		else if (direccion == 4) { //Se avanza hacia la izquierda
			while (paso != avance && posicionx >= 1) {
				mat[posiciony][posicionx] = '*';
				posicionx--;
				paso++;
			}
		}
		else { //Se avanza hacia arriba
			while (paso != avance && posicionx >= 1) {
				mat[posiciony][posicionx] = '*';
				posiciony--;
				paso++;
			}
		}
	}
	else {
		if (direccion == 2) { //Se avanza a la derecha
			while (paso != avance && posicionx < 19) {
				posicionx++;
				paso++;
			}
		}
		else if (direccion == 3) { //Se avanza hacia abajo
			while (paso != avance && posiciony < 19) {
				posiciony++;
				paso++;
			}
		}
		else if (direccion == 4) { //Se avanza hacia la izquierda
			while (paso != avance && posicionx >= 1) {
				posicionx--;
				paso++;
			}
		}
		else { //Se avanza hacia arriba
			while (paso != avance && posicionx >= 1) {
				posiciony--;
				paso++;
			}
		}
	}
}
void mostrar(char mat[][20], int renglones) {
	for (int renglon = 0; renglon < renglones; renglon++) {
		for (int columna = 0; columna < 20; columna++) {
			cout << mat[renglon][columna] << "| ";
		}
		cout << endl;
	}
}
void centinela(int posicionx, int posiciony, bool pluma, int direccion){
	cout << "La tortuga está en el renglon " << posiciony << " y columna " << posicionx << endl;
	switch (direccion) {
	case 1:
		cout << "Está mirando hacia arriba"<<endl;
		break;
	case 2:
		cout << "Está mirando hacia la derecha" << endl;
		break;
	case 3:
		cout << "Está mirando hacia abajo" << endl;
		break;
	case 4:
		cout << "Está mirando hacia la izquierda" << endl;;
		break;
	default:
		break;
	}
	if (pluma == true) {
		cout << "La pluma está hacia abajo, está pintando" << endl;
	}
	else {
		cout << "La pluma está hacia arriba,no está pintando" << endl;
	}
}
