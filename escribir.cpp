#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	string ruc, producto;
	int unidads;
	double precio;
	char aux;
	ofstream archivo;
	
	archivo.open("compras.txt");
	
	cout << "RUC del cliente ( X mayus para terminar) : ";
	cin >> ruc;
	
	while (ruc != "X"){
		cin.get(aux);
		cout << "Producto: "; getline(cin, producto);
		cout << "Unidades: "; cin >> unidads;
		cout << "Precio: " ; cin >> precio;
		
		archivo << ruc << " " << unidads << " " << precio;
		archivo << precio << " " << producto <<endl;
		cout << " RUC del cliente (X mayus para terminar): ";
		cin >> ruc;
	}
	archivo << "X";
	archivo.close();
	
	return 0;
}
