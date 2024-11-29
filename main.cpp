#include <iostream>
#include <fstream>
#include "registro.h"


using namespace std;

int main(){
	tregistro registro;
	fstream archivo;
	archivo.open("bd.dat", ios::in | ios::out | ios::binary );
	archivo.seekg(0, ios::end);
	int pos = archivo.tellg();
	int numReg = pos / SIZE;
	cout << " Lac cantidad de registros es: "<< numReg <<endl;
	int num;
	cout << " Registro numero?: ";
	cin >> num;
	if((num>0) && (num<=numReg)){
		archivo.seekg((num-1) * SIZE, ios::beg);
		archivo.read((char *) &registro, SIZE);
		mostrar(registro);
		cout << endl << " Cambiar nombre [S/N]? ";
		cin.sync();
		if((c=='s') || (c=='S')){
			cout << " Nombre: ";
			cin.sync();
			cin.getline(registro.item, 80);
		}
		cout<<endl;
		cout << " Cambiar el precio[S/N]? ";
		cin.sync();
		cin>>c;
		if((c=='s') || (c=='S')){
			cout << " Precio: ";
			cin>>registro.valor;
		}
		archivo.seekg((num-1) * SIZE, ios::beg);
		archivo.write((char *) &registro, SIZE);
		cout<<endl;
		cout<<" Registro actualizado: "<<endl;
		archivo.seekg((num-1) * SIZE, ios::beg);
		archivo.write((char *) &registro, SIZE);
		mostrar(registro);
	}
	archivo.close();
	return 0;
}
