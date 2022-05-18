#include <iostream>
#include <fstream>
#include<windows.h>
#include <string>
using namespace std;

string validacionDT(string x) {
	int V = 1;
	for (int z = 0; z < x.length(); z++) {
		if (!isalpha(x.at(z)) && !isspace(x.at(z))) {
			V = 1;
			z = 100;
		}
		else {
			V = 0;
		}
	}

	while (V == 1) {
		cout << "Por favor introduzca una descripcion valida." << endl;
		cin >> x;

		for (int z = 0; z < x.length(); z++) {
			if (!isalpha(x.at(z)) && !isspace(x.at(z))) {
				V = 1;
				z = 100;
			}
			else {
				V = 0;
			}
		}
	}
	return x;
};

string validacionNT(string x) {
	int V = 1;
	for (int z = 0; z < x.length(); z++) {
		if (!isalpha(x.at(z)) && !isspace(x.at(z))) {
			V = 1;
			z = 100;
		}
		else {
			V = 0;
		}
	}

	while (V == 1) {
		cout << "Por favor introduzca un nombre valido." << endl;
		cin >> x;

		for (int z = 0; z < x.length(); z++) {
			if (!isalpha(x.at(z)) && !isspace(x.at(z))) {
				V = 1;
				z = 100;
			}
			else {
				V = 0;
			}
		}
	}
	return x;
};

int validacionM(int x) {
	while (x <= 0 || x > 60) {
		cout << "Introduzca un minuto valid0." << endl;
		cin >> x;
	}
	return x;
};

int validacionH(int x) {
	while (x <= 0 || x > 24) {
		cout << "Introduzca una hora valida." << endl;
		cin >> x;
	}
	return x;
};

string validacionN(string x) {
	int z;
	bool espa;
	while (x.empty()) {
		cout << "Error, Por favor un nombre valido. " << endl;
		cin.ignore();
		getline(cin, x);

	}
	for (z = 0; z < x.length(); z++) {
		if (!isalpha(x.at(z)) && !isspace(x.at(z))) {
			espa = true;
			z = 100;
		}
		else {
			espa = false;
		}
	}
	while (espa == true) {
		cout << "Error, Por favor introduzca informacion sin simbolos: " << endl;
		cin.ignore();
		getline(cin, x);
		while (x.empty()) {
			cout << "Error, Por favor introduzca informacion: " << endl;
			cin.ignore();
			getline(cin, x);
		}
		for (z = 0; z < x.length(); z++) {
			if (!isalpha(x.at(z)) && !isspace(x.at(z))) {
				espa = true;
				z = 100;
			}
			else {
				espa = false;
			}
		}
	}
	return x;
};

struct {
	int hora, minutos, ctratamiento;
	string nombrep, nombretrata, descripcion;
	float preciouni, preciofinal;

}Datos[15];

int b; //Opcion borrar
int i;
int mo;//switch modificar
int m;
string nombre, nt, dt;
int horas, minutos;
int d1;//Variable switch menu
int cit = 0; //Numero cita vigente
int main()
{

	while (true) {
		cout << "\tMENU DE OPCIONES" << endl;
		cout << "1. Agregar cita\n2. Lista de citas\n3. Modificar cita\n4. Elminar cita\n5. Salir " << endl;
		cin >> d1;
		switch (d1) {
		case 1: cout << "Numero de cita: " << cit + 1 << endl;
			cout << "Introduzca el nombre del paciente: " << endl;
			cin.ignore();
			getline(cin, nombre);
			nombre = validacionN(nombre);
			Datos[cit].nombrep = nombre;
			cout << "Ingrese la hora (formato 24 horas): " << endl;
			cin >> horas;
			horas = validacionH(horas);
			Datos[cit].hora = horas;
			cout << "Ingrese los minutos : " << endl;
			cin >> minutos;
			minutos = validacionM(minutos);
			Datos[cit].minutos = minutos;
			cout << "Ingrese el nombre del tratamiento: " << endl;
			cin.ignore();
			getline(cin, nt);
			nt = validacionNT(nt);
			Datos[cit].nombretrata = nt;
			cout << "Ingrese su descripcion: " << endl;
			cin.ignore();
			getline(cin, dt);
			dt = validacionDT(dt);
			Datos[cit].descripcion = dt;
			cout << "Ingrese el precio del tratamiento: " << endl;
			cin >> Datos[cit].preciouni;
			cout << "Ingrese la cantidad del tratamiento: " << endl;
			cin >> Datos[cit].ctratamiento;
			Datos[cit].preciofinal = (Datos[cit].preciouni * Datos[cit].ctratamiento) + ((Datos[cit].preciouni * Datos[cit].ctratamiento) * 16);
			cit = cit + 1;
			system("pause");
			system("cls");
			break;
		case 2:
			if (cit == 0) {
				cout << "No hay citas vigentes." << endl;
				break;
			}
			for (i = 0; i < cit; i++) {
				cout << "Numero de cita: " << i + 1 << endl;
				cout << "Nombre del paciente: " << Datos[i].nombrep << endl;
				cout << "Hora: " << Datos[i].hora << " : " << Datos[i].minutos << endl;
				cout << "Nombre del tratamiento :" << Datos[i].nombretrata << endl;
				cout << "Descripcion del tratamiento :" << Datos[i].descripcion << endl;
				cout << "Precio unitario del tratamiento : " << Datos[i].preciouni << endl;
				cout << "Cantidad del tratamiento : " << Datos[i].ctratamiento << endl;
				cout << "Precio final del tratamiento : " << Datos[i].preciofinal << "$ pesos." << endl << endl;


			}
			system("pause");
			system("cls");
			break;
		case 3:
			if (cit == 0) {
				cout << "No hay citas vigentes." << endl;
				break;
			}
			cout << "Ingrese el numero de cita a modificar";
			cin >> m;
			m = m - 1;
			cout << "Que desea modificar?" << endl;
			cout << "Numero de cita: " << i + 1 << endl;
			cout << "1. Nombre del paciente: " << Datos[m].nombrep << endl;
			cout << "2. Hora: " << Datos[m].hora << " : " << Datos[m].minutos << endl;
			cout << "3. Nombre del tratamiento :" << Datos[m].nombretrata << endl;
			cout << "4. Descripcion del tratamiento :" << Datos[m].descripcion << endl;
			cout << "5. Precio unitario del tratamiento : " << Datos[m].preciouni << endl;
			cout << "6. Cantidad del tratamiento : " << Datos[m].ctratamiento << endl;
			cout << "Precio final del tratamiento : " << Datos[m].preciofinal << "$ pesos." << endl;
			cin >> mo;
			switch (mo) {
			case 1: cout << "Introduzca el nombre del paciente: " << endl;
				cin >> nombre;
				Datos[m].nombrep = validacionN(nombre);
				break;
			case 2:
				cout << "Ingrese la hora (formato 24 horas): " << endl;
				cin >> horas;
				Datos[m].hora = validacionH(horas);
				cout << "Ingrese los minutos : " << endl;
				cin >> minutos;
				Datos[m].minutos = validacionM(minutos);
				break;
			case 3:cout << "Ingrese el nombre del tratamiento: " << endl;
				cin >> nt;
				Datos[m].nombretrata = validacionNT(nt);
				break;
			case 4: cout << "Ingrese su descripcion: " << endl;
				cin >> dt;
				Datos[m].descripcion = validacionDT(dt);
				break;
			case 5:cout << "Ingrese el precio del tratamiento: " << endl;
				cin >> Datos[m].preciouni;
				Datos[m].preciofinal = (Datos[m].preciouni * Datos[m].ctratamiento) + ((Datos[m].preciouni * Datos[m].ctratamiento) * 16);
				break;
			case 6: cout << "Ingrese la cantidad del tratamiento: " << endl;
				cin >> Datos[m].ctratamiento;
				Datos[m].preciofinal = (Datos[m].preciouni * Datos[m].ctratamiento) + ((Datos[m].preciouni * Datos[m].ctratamiento) * 16);
				break;
			}
			cout << "Cita modificada." << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "Ingrese la cita a borrar." << endl;
			cin >> b;
			b = b - 1;
			for (i = b - 1; i < cit; i++) {
				Datos[i].nombrep = Datos[i + 1].nombrep;
				Datos[i].nombretrata = Datos[i + 1].nombretrata;
				Datos[i].ctratamiento = Datos[i + 1].ctratamiento;
				Datos[i].descripcion = Datos[i + 1].descripcion;
				Datos[i].hora = Datos[i + 1].hora;
				Datos[i].minutos = Datos[i + 1].minutos;
				Datos[i].preciofinal = Datos[i + 1].preciofinal;
				Datos[i].preciouni = Datos[i + 1].preciouni;


			}
			cit = cit - 1;
			cout << "Cita borrada exitosamente." << endl;
			system("pause");
			system("cls");
			break;
		case 5: cout << "guardando la informacion.";
			if (cit == 0) {
				exit(0);
				break;
			}
			for (i = 0; i < cit; i++) {
				ofstream c("citasv.txt", ios::app);
				if (!c) {
					cout << "ERROR ARCHIVO NO ENCONTRADO.";
				}
				c << "Numero de cita: " << i + 1 << endl;
				c << "Nombre del paciente: " << Datos[i].nombrep << endl;
				c << "Hora: " << Datos[i].hora << " : " << Datos[i].minutos << endl;
				c << "Nombre del tratamiento :" << Datos[i].nombretrata << endl;
				c << "Descripcion del tratamiento :" << Datos[i].descripcion << endl;
				c << "Precio unitario del tratamiento : " << Datos[i].preciouni << endl;
				c << "Cantidad del tratamiento : " << Datos[i].ctratamiento << endl;
				c << "Precio final del tratamiento : " << Datos[i].preciofinal << "$ pesos." << endl;
				c << "-----------------------------------------------------" << endl;

			}
			exit(0);
		default: cout << "Error, ingrese una opcion valida." << endl;
		}
	}
}
