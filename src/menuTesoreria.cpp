#include "menuTesoreria.h"
#include <iostream>
#include<fstream>
#include "matricula.h"
#include "colegiatura.h"
#include "sueldos.h"
using namespace std;

void menuTesoreria::menuGeneral()
{
    system("cls");
    int choice;
	do
    {
	system("cls");
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t|    SISTEMA DE TESORERIA     |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Matricula"<<endl;
	cout<<"\t\t\t 2. Pago de Inscripcion"<<endl;
	cout<<"\t\t\t 3. Pago de colegiatura"<<endl;
	cout<<"\t\t\t 4. Pago de sueldos"<<endl;
	cout<<"\t\t\t 5. Salir del Sistema"<<endl;
		cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        {
            matricula matricula;
            matricula.menu();
        }
		break;
	case 2:
		//agregar pago de inscripcion
		break;
	case 3:
	    {
	        colegiatura colegiatura;
	        colegiatura.leerDatos();
	    }
		break;
    case 4:
	    {
	        sueldos sueldo;
	        sueldo.menuEmpleados();
	    }
		break;
	case 5:
		//search();
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
    }while(choice!= 5);
}

