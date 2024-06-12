#include "matricula.h"
#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
//#include<conio.h>
#include<iomanip>
#include <cstdlib> // Para la generación de números aleatorios
#include <ctime>   // Para establecer la semilla del generador de números aleatorios
#include "alumnos.h"
using namespace std;

// Definición de la estructura Sede que contiene los datos de una sede
struct Matricula {
    //string carnet;
    char carnet [20];
    char facultad [20];
    //char nombre[50];
    //char telefono[20];
};
void matricula::menu(){
int choice;

	do
    {
	system("cls");

	cout<<"\t\t\t---------------------------------------"<<endl;
	cout<<"\t\t\t|SISTEMA DE PAGO DE MATRICULA EN LINEA|"<<endl;
	cout<<"\t\t\t---------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Matricula"<<endl;
	cout<<"\t\t\t 2. Despliegue Matricula"<<endl;
    cout<<"\t\t\t 3. Modifica Matricula"<<endl;
    cout<<"\t\t\t 4. Borra Matricula"<<endl;
    cout<<"\t\t\t 5. Retornar menu anterior"<<endl;
    cout<<"\t\t\t-----------------------------------------"<<endl;
    cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
    cout<<"\t\t\t-----------------------------------------"<<endl;
    cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice; // Lee la opción del usuario

    switch(choice)
    {
    case 1:
        do
        {
            insertar();
            cout<<"\n\t\t\t Agrega otra Sede(Y,N): ";
            cin>>x; // Pregunta al usuario si quiere agregar otra Matricula
        } while(x=='y'||x=='Y'); // Repite el proceso si el usuario responde 'y' o 'Y'
		break;
	case 2:
	    {
	        //desplegar();
	    }
		break;
    case 3:
        {
            //modificar();
        }
        break;
    case 4:
        {
            //borrar();
        }
        break;
    case 5:
        {
            break;
        }
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
		cin.get();
	}
  }while(choice!= 5);
}
/*

// Función para generar un correo institucional
string matricula::generarCorreoInstitucional(string nombre, string apellido1, string apellido2) {
    // Extraer la inicial del primer nombre
    char inicialNombre = tolower(nombre[0]);

    // Convertir el primer apellido a minúscula
    for (char &c : apellido1) {
        c = tolower(c);
    }

    // Convertir el segundo apellido a minúscula
    for (char &c : apellido2) {
        c = tolower(c);
    }
    // Concatenar el primer apellido y la inicial del segundo apellido
    string correo = "";
    correo += inicialNombre;
    correo += apellido1;
    correo += apellido2[0];
    // Generar un número aleatorio de dos dígitos
    int numeroAleatorio = generarNumeroAleatorio();

    // Concatenar el dominio del correo institucional
    correo += to_string(numeroAleatorio) + "@miumg.edu.gt";

    return correo;
}*/
// Función para generar un número de boleta aleatorio
string matricula::generarNumeroBoleta() {
    srand(time(0)); // Establecer la semilla para números aleatorios
    string numeroBoleta = "No.";
    for (int i = 0; i < 6; ++i) {
        numeroBoleta += to_string(rand() % 10); // Añadir dígitos aleatorios
    }
    return numeroBoleta;
}
void matricula::insertar(){
    system("cls");
    Matricula matricula;
    ofstream file("Matricula.dat", ios::binary | ios::app);
    // Verifica si el archivo se abrió correctamente
    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl; // Muestra un mensaje de error si no se puede abrir el archivo
        return; // Retorna
    }
      string id, carnet, facultad, plan, jornada, nombre, apellido1, apellido2, fechaNacimiento, direccion, telefono, DPI, correo, fecha, numeroBoleta;
      //Información que aún no se ha agregado
      /*cout<<"\n-----------------------------------------------------------------------------------------------------------------";
      cout<<"\n-------------------------------------------------Creacion Matricula----------------------------------------------"<<endl;
      // Seleccionar Facultad
      cout << "Seleccione la Facultad (Ej. Ingenieria en sistemas, Ingenieria civil, etc.): ";
      cin.ignore(); // Limpiar el buffer de entrada
      //getline(cin, facultad);
      cin.getline(matricula.facultad, sizeof(matricula.facultad));
      cout << "Seleccione el plan(Diario, Fin de semana): ";
      getline(cin, plan);
      cout << "Seleccione la Jornada(Matutino, Vespertina): ";
      getline(cin, jornada);*/
      cout<<"\n-----------------------------------------------------------------------------------------------------------------";
      cout<<"\n-------------------------------------------Registro de Nuevos estudiante-----------------------------------------"<<endl;
      // Solicitar los datos del estudiante
      cout << "\n\t\t\t Ingrese el numero de carnet: ";
      cin.ignore();
      cin.getline(matricula.carnet, sizeof(matricula.carnet));
      ifstream archivo("Alumnos.dat", ios::binary);
      if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo" << endl;
        return;
        }
      else
        {
        Alumno alumno;
        while (archivo.read(reinterpret_cast<char*>(&alumno), sizeof(Alumno))) {
        }
        string id = alumno.id;
        string nombre = alumno.nombre;
        string carnet = matricula.carnet;
        cout<< id << endl;
        cout<< carnet <<endl;
        cout<< nombre <<endl;
        if (id != carnet)
        {
            cout << "Los datos del id no coinciden." << endl;
        return;
        }
        else
        {
            // Si los datos coinciden, continuar con el proceso de pago
            cout << "\t\t\t ID del estudiante: " << alumno.id << endl;
            cout << "\t\t\t Nombre del estudiante: " << alumno.nombre << endl;
            cout << "\t\t\t email del estudiante : " << alumno.DPI << endl;
            cout << "\t\t\t Estatus del estudiante: " << alumno.nacionalidad << endl;
            cout << "\t\t\t Direccion: " << alumno.direccion << endl;
            cout << "\t\t\t Telefono: " << alumno.telefono << endl;
            cout << "+---------------------------------------------------------------------------------+" << endl;
            file.write(reinterpret_cast<const char*>(&alumno), sizeof(alumno));
            file.close();
        }
    }
      cout << "\tFecha de ingreso de informacion(dd/mm/aaaa): ";
      getline(cin, fecha);
      cout << "\n\t\t--------- Monto de la matricula: Q10.00 ---------"<<"\n"<<endl;
      system("pause");
      pagarEnLinea();

      cout<<"\n\n-----------------------------------------------------------------------------------------------------------------"<<endl;
      cout << "\t\t\t¡Su pago de matricula ha sido procesado con exito!" << endl;
      //ofstream file("Matricula.dat", ios::binary | ios::app);
      //file<<"-------------------------------------------DATOS DEL ESTUDIANTE-------------------------------------------"<<"\n";
      file.write(reinterpret_cast<char*>(&facultad), sizeof(facultad));
      file.write(reinterpret_cast<char*>(&plan), sizeof(plan));
      file.write(reinterpret_cast<char*>(&jornada), sizeof(jornada));
      file.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
      file.write(reinterpret_cast<char*>(&apellido1), sizeof(apellido1));
      file.write(reinterpret_cast<char*>(&apellido2), sizeof(apellido2));
      file.write(reinterpret_cast<char*>(&fechaNacimiento), sizeof(fechaNacimiento));
      file.write(reinterpret_cast<char*>(&direccion), sizeof(direccion));
      file.write(reinterpret_cast<char*>(&telefono), sizeof(telefono));
      file.write(reinterpret_cast<char*>(&DPI), sizeof(DPI));
      file.write(reinterpret_cast<char*>(&correo), sizeof(correo));
      file.write(reinterpret_cast<char*>(&fecha), sizeof(fecha));
      //file.write(reinterpret_cast<char*>(&numeroCarnet), sizeof(numeroCarnet));
      //file.write(reinterpret_cast<char*>(&correoInstitucional), sizeof(correoInstitucional));
      file.close();
      system("pause");
      system("cls");
      //fstream file2;
      // Generar el número de boleta
      numeroBoleta = generarNumeroBoleta();
      // Mostrar el comprobante de pago
      cout<<"\n----------------------------------------------------------------------------------------------------------";
      cout<<"\n-------------------------------------------Comprobante de pago -------------------------------------------"<<endl;
      cout << "\t\t\tNumero de boleta: " << numeroBoleta << endl;
//      cout << "\t\t\tNumero de carnet: " << numeroCarnet << endl;
      cout << "\t\t\tNombre completo: " << nombre << " " << apellido1 << " " << apellido2 << endl;
      cout << "\t\t\tFecha de pago: " << fecha << endl;
      cout << "\t\t\tMonto de la matricula: Q10.00" <<"\n"<< endl;
      ofstream file2("Boleta_Pago.dat", ios::binary | ios::app);
      file2.write(reinterpret_cast<char*>(&numeroBoleta), sizeof(numeroBoleta));
//      file2.write(reinterpret_cast<char*>(&numeroCarnet), sizeof(numeroCarnet));
      file2.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
      file2.write(reinterpret_cast<char*>(&apellido1), sizeof(apellido1));
      file2.write(reinterpret_cast<char*>(&apellido2), sizeof(apellido2));
      file2.write(reinterpret_cast<char*>(&fecha), sizeof(fecha));
      file2.close();
      system("pause");
}
/*
void matricula::insertar(){
    system("cls");
    //fstream file;
      string facultad, plan, jornada, nombre, apellido1, apellido2, fechaNacimiento, direccion, telefono, DPI, correo, fecha, numeroBoleta;
      cout<<"\n-----------------------------------------------------------------------------------------------------------------";
      cout<<"\n-------------------------------------------------Creacion Matricula----------------------------------------------"<<endl;
      // Seleccionar Facultad
      cout << "Seleccione la Facultad (Ej. Ingenieria en sistemas, Ingenieria civil, etc.): ";
      cin.ignore(); // Limpiar el buffer de entrada
      getline(cin, facultad);
      cout << "Seleccione el plan(Diario, Fin de semana): ";
      getline(cin, plan);
      cout << "Seleccione la Jornada(Matutino, Vespertina): ";
      getline(cin, jornada);
      cout<<"\n-----------------------------------------------------------------------------------------------------------------";
      cout<<"\n-------------------------------------------Registro de Nuevos estudiante-----------------------------------------"<<endl;
      // Solicitar los datos del estudiante
      cout << "\n\tIngrese sus nombres: ";
      getline(cin, nombre);
      cout << "\tIngrese su primer apellido: ";
      getline(cin, apellido1);
      cout << "\tIngrese su segundo apellido: ";
      getline(cin, apellido2);
      cout << "\tIngrese su fecha de nacimiento(dd/mm/aaaa): ";
      getline(cin, fechaNacimiento);
      cout << "\tIngrese su Direccion de Residencia: ";
      getline(cin, direccion);
      cout << "\tIngrese su Telefono celular: ";
      getline(cin, telefono);
      cout << "\tIngrese su DPI(CUI): ";
      getline(cin, DPI);
      cout << "\tIngrese su Correo Electronico Personal: ";
      getline(cin, correo);
      cout << "\tFecha de ingreso de informacion(dd/mm/aaaa): ";
      getline(cin, fecha);
      cout << "\n\t\t--------- Monto de la matricula: Q10.00 ---------"<<"\n"<<endl;
      system("pause");
      pagarEnLinea();

      // Generar número de carnet y correo institucional
      string numeroCarnet = generarNumeroCarnet();
      string correoInstitucional = generarCorreoInstitucional(nombre, apellido1, apellido2);
      cout<<"\n\n-----------------------------------------------------------------------------------------------------------------"<<endl;
      cout << "\t\t\t¡Su pago de matricula ha sido procesado con exito!" << endl;
      cout << "\t\t\tNumero de carnet: " << numeroCarnet << endl;
      cout << "\t\t\tSu Correo institucional es: " << correoInstitucional << endl;
      //file.open("Matricula.txt", ios::app | ios::out);
      ofstream file("Matricula.dat", ios::binary | ios::app);
      //file<<"-------------------------------------------DATOS DEL ESTUDIANTE-------------------------------------------"<<"\n";
      file.write(reinterpret_cast<char*>(&facultad), sizeof(facultad));
      file.write(reinterpret_cast<char*>(&plan), sizeof(plan));
      file.write(reinterpret_cast<char*>(&jornada), sizeof(jornada));
      file.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
      file.write(reinterpret_cast<char*>(&apellido1), sizeof(apellido1));
      file.write(reinterpret_cast<char*>(&apellido2), sizeof(apellido2));
      file.write(reinterpret_cast<char*>(&fechaNacimiento), sizeof(fechaNacimiento));
      file.write(reinterpret_cast<char*>(&direccion), sizeof(direccion));
      file.write(reinterpret_cast<char*>(&telefono), sizeof(telefono));
      file.write(reinterpret_cast<char*>(&DPI), sizeof(DPI));
      file.write(reinterpret_cast<char*>(&correo), sizeof(correo));
      file.write(reinterpret_cast<char*>(&fecha), sizeof(fecha));
      file.write(reinterpret_cast<char*>(&numeroCarnet), sizeof(numeroCarnet));
      file.write(reinterpret_cast<char*>(&correoInstitucional), sizeof(correoInstitucional));
      file.close();
      system("pause");
      system("cls");
      //fstream file2;
      // Generar el número de boleta
      numeroBoleta = generarNumeroBoleta();
      // Mostrar el comprobante de pago
      cout<<"\n----------------------------------------------------------------------------------------------------------";
      cout<<"\n-------------------------------------------Comprobante de pago -------------------------------------------"<<endl;
      cout << "\t\t\tNumero de boleta: " << numeroBoleta << endl;
      cout << "\t\t\tNumero de carnet: " << numeroCarnet << endl;
      cout << "\t\t\tNombre completo: " << nombre << " " << apellido1 << " " << apellido2 << endl;
      cout << "\t\t\tFecha de pago: " << fecha << endl;
      cout << "\t\t\tMonto de la matricula: Q10.00" <<"\n"<< endl;
      ofstream file2("Boleta_Pago.dat", ios::binary | ios::app);
      //file2.open("Boleta_Pago.txt", ios::app | ios::out);
      file2.write(reinterpret_cast<char*>(&numeroBoleta), sizeof(numeroBoleta));
      file2.write(reinterpret_cast<char*>(&numeroCarnet), sizeof(numeroCarnet));
      file2.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
      file2.write(reinterpret_cast<char*>(&apellido1), sizeof(apellido1));
      file2.write(reinterpret_cast<char*>(&apellido2), sizeof(apellido2));
      file2.write(reinterpret_cast<char*>(&fecha), sizeof(fecha));
      file2.close();
      system("pause");
}*/

void matricula::pagarEnLinea() {
    system("cls");
    cout<<"\n----------------------------------------------------------------------------------------------------------";
    cout<<"\n-------------------------------------------DATOS DE LA TARJETA--------------------------------------------"<<endl;
    cout << "Ingrese los datos de su tarjeta de crédito para realizar el pago en línea:" << endl;
    string numTarjeta, fExpiracion, codSeguridad;
    cout << "Número de tarjeta: ";
    //cin.ignore();
    getline(cin, numTarjeta);
    cout << "Fecha de expiración (MM/AA): ";
    getline(cin, fExpiracion);
    cout << "Código de seguridad: ";
    getline(cin, codSeguridad);

    ifstream archivo("tarjeta.txt");
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo tarjeta.txt." << endl;
        return;
    }
    else
    {
        string numeroTarjeta, fechaExpiracion, codigoSeguridad;
        int saldo;
        // Leer el número de tarjeta
        getline(archivo, numeroTarjeta);
        // Leer la fecha de expiración
        getline(archivo, fechaExpiracion);
        // Leer el código de seguridad
        getline(archivo, codigoSeguridad);
        // Leer el saldo disponible
        string saldoStr;
        getline(archivo, saldoStr);
        saldo = stoi(saldoStr);
        if (numTarjeta != numeroTarjeta || fExpiracion != fechaExpiracion || codSeguridad != codigoSeguridad)
        {
            cout << "Los datos de la tarjeta no coinciden." << endl;
        return;
        }
        // Si los datos coinciden, continuar con el proceso de pago
        cout << "Los datos de la tarjeta coinciden." << endl;

        // Verificar el saldo en la tarjeta
        if (saldo >= 10) { // Si hay suficiente saldo para el pago
            cout << "\n¡Pago realizado en línea con éxito!" << endl;
            cout << "Monto pagado: Q10.00" << endl;
            cout << "Saldo disponible en la tarjeta: Q" << saldo - 10 << endl;
            archivo.close(); // Cerrar el archivo antes de abrirlo en modo de escritura
            // Actualizar el saldo en el archivo después del pago
            ofstream archivoSalida("tarjeta.txt"); // Abrir el archivo en modo de escritura
            if (!archivoSalida.is_open()) {
                cout << "Error: No se pudo abrir el archivo tarjeta.txt para escribir." << endl;
            return;
            }
            // Escribir los datos actualizados en el archivo
            archivoSalida << numeroTarjeta << endl;
            archivoSalida << fechaExpiracion << endl;
            archivoSalida << codigoSeguridad << endl;
            archivoSalida << saldo - 10 << endl; // Actualizar el saldo restando 10
            archivoSalida.close(); // Cerrar el archivo después de escribir
            }
            else { // Si no hay suficiente saldo para el pago
                cout << "\n¡No hay fondos suficientes en la tarjeta para realizar el pago!" << endl;
                cout << "Saldo disponible en la tarjeta: Q" << saldo << endl;
            }
                system("pause");
        }
}
