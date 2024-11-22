#include <iostream>
#include <string>

#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	const int IGV = 18;
	string ruc, producto;
	int unidads;
	double precio, neto, total, igv;
	char aux;
	ifstream archivo;
	int contador = 0;
	
	archivo.open("compras.txt");
	
	if(archivo.is_open()){
		archivo >> ruc;
		while(ruc != "X"){
			archivo >> unidads >> precio;
			archivo.get(aux);
			getline(archivo, producto);
			contador++;
			neto = unidads * precio;
			igv = neto * (IGV/100);
			total = neto + igv;
			cout << "\t Compra " << contador << ": " <<endl;
			cout << "\t  " << producto << ": " << unidads << " x " << fixed << setprecision(2) << precio << " = ";
			cout << neto << " - I.G.V. :" << igv <<"% - Total: " << total <<endl;
			archivo >> ruc;
		}
		archivo.close();
	}else{
		cout << " ERROR 12421 : " << endl;
		cout << " No se logro abrir el archivo" <<endl;
	}
	return 0;
}
