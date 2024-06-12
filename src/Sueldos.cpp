#include "sueldos.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include "Bitacora.h"

using namespace std;

// Definición de la estructura para almacenar los datos de los empleados

void sueldos::crudsueldo() {
    int choice;
    string codigoPrograma = "6650"; // Código del programa
    Bitacora Auditoria; // Objeto para gestionar la bitácora de auditoría
    string user = "admin"; // Usuario actual del sistema

    do {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|    MENU DE SUELDOS          |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Base de datos de empleados" << endl;
        cout << "\t\t\t 2. Generación de nóminas" << endl;
        cout << "\t\t\t 3. Proceso de asignación de maestros" << endl;
        cout << "\t\t\t 4. Retorno" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tOpción a escoger:[1/2/3/4]" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opción: ";
        cin >> choice;

        switch(choice) {
            case 1:
                menuEmpleados(); // Llama a la función para el menú de empleados
                Auditoria.ingresoBitacora(user, codigoPrograma, "MEN"); // Registra en la bitácora la acción de mostrar el menú de empleados
                break;
            case 2:
                generacionNomina(); // Llama a la función para la generación de nómina
                break;
            case 3:
                procesoAsignacionMaestros();
                break;
            case 4:
                // Implementa la funcionalidad para "Retorno" aquí
                break;
            default:
                cout << "\n\t\t\t Opción inválida...Por favor prueba otra vez..";
                cin.get();
        }
    } while(choice != 4);
}

void sueldos::menuEmpleados() {
    int choice;
    do {
        system("cls");
        cout << "\t\t\t-----------------------------------" << endl;
        cout << "\t\t\t|    BASE DE DATOS DE EMPLEADOS   |" << endl;
        cout << "\t\t\t-----------------------------------" << endl;
        cout << "\t\t\t 1. Agregar empleado" << endl;
        cout << "\t\t\t 2. Eliminar empleado" << endl;
        cout << "\t\t\t 3. Ver información de los empleados" << endl;
        cout << "\t\t\t 4. Retroceder" << endl;
        cout << "\t\t\t-----------------------------------" << endl;
        cout << "\t\t\tOpción a escoger:[1/2/3/4]" << endl;
        cout << "\t\t\t-----------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opción: ";
        cin >> choice;

        switch(choice) {
            case 1:
                agregarEmpleado(); // Llama a la función para agregar un empleado
                break;
            case 2:
                eliminarEmpleado(); // Llama a la función para eliminar un empleado
                break;
            case 3:
                verEmpleados(); // Llama a la función para ver la información de los empleados
                break;
            case 4:
                // Salir del menú de empleados
                break;
            default:
                cout << "\n\t\t\t Opción inválida...Por favor prueba otra vez..";
                cin.get();
        }
    } while(choice != 4);
}

// Implementa las funciones agregarEmpleado(), eliminarEmpleado(), verEmpleados() aquí

void sueldos::agregarEmpleado() {
    Empleado empleado; // Declarar una variable para almacenar los datos del empleado

    cout << "\n\tIngrese el nombre del empleado: ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, empleado.nombre); // Leer el nombre del empleado

    cout << "\tIngrese el puesto del empleado: ";
    getline(cin, empleado.puesto); // Leer el puesto del empleado

    cout << "\tIngrese el salario del empleado: ";
    cin >> empleado.salario; // Leer el salario del empleado

    // Guardar la información en un archivo binario
    ofstream file("empleados.dat", ios::binary | ios::app);
    size_t nombreSize = empleado.nombre.size();
    size_t puestoSize = empleado.puesto.size();
    file.write(reinterpret_cast<const char*>(&nombreSize), sizeof(nombreSize));
    file.write(empleado.nombre.c_str(), nombreSize);
    file.write(reinterpret_cast<const char*>(&puestoSize), sizeof(puestoSize));
    file.write(empleado.puesto.c_str(), puestoSize);
    file.write(reinterpret_cast<const char*>(&empleado.salario), sizeof(empleado.salario));
    file.close();

    cout << "\n\t¡El empleado ha sido agregado con éxito!\n";
    system("pause");
}

void sueldos::eliminarEmpleado() {
    string nombre; // Variable para almacenar el nombre del empleado a eliminar
    string puesto; // Variable para almacenar el puesto del empleado a eliminar

    cout << "\n\tIngrese el nombre del empleado que desea eliminar: ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, nombre); // Leer el nombre del empleado

    cout << "\tIngrese el puesto del empleado que desea eliminar: ";
    getline(cin, puesto); // Leer el puesto del empleado

    ifstream archivo("empleados.dat", ios::binary); // Abrir el archivo para lectura en modo binario
    ofstream archivoTmp("empleados_tmp.dat", ios::binary); // Abrir un archivo temporal para escritura en modo binario

    size_t nombreSize, puestoSize;
    Empleado empleado; // Declarar una variable para almacenar el empleado actual
    bool eliminado = false; // Bandera para indicar si se eliminó el empleado

    while (archivo.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize))) {
        empleado.nombre.resize(nombreSize);
        archivo.read(&empleado.nombre[0], nombreSize);
        archivo.read(reinterpret_cast<char*>(&puestoSize), sizeof(puestoSize));
        empleado.puesto.resize(puestoSize);
        archivo.read(&empleado.puesto[0], puestoSize);
        archivo.read(reinterpret_cast<char*>(&empleado.salario), sizeof(empleado.salario));

        if (empleado.nombre == nombre && empleado.puesto == puesto) { // Si el nombre y el puesto del empleado coinciden con los ingresados
            eliminado = true; // Actualizar la bandera indicando que se eliminó el empleado
        } else {
            archivoTmp.write(reinterpret_cast<const char*>(&nombreSize), sizeof(nombreSize));
            archivoTmp.write(empleado.nombre.c_str(), nombreSize);
            archivoTmp.write(reinterpret_cast<const char*>(&puestoSize), sizeof(puestoSize));
            archivoTmp.write(empleado.puesto.c_str(), puestoSize);
            archivoTmp.write(reinterpret_cast<const char*>(&empleado.salario), sizeof(empleado.salario));
        }
    }

    archivo.close(); // Cerrar el archivo original
    archivoTmp.close(); // Cerrar el archivo temporal

    remove("empleados.dat"); // Eliminar el archivo original
    rename("empleados_tmp.dat", "empleados.dat"); // Renombrar el archivo temporal como el archivo original

    if (eliminado) { // Si el empleado fue eliminado
        cout << "\n\t¡El empleado ha sido eliminado con éxito!\n";
    } else {
        cout << "\n\tEste empleado no existe en la base de datos.\n";
    }

    system("pause");
}

void sueldos::verEmpleados() {
    ifstream archivo("empleados.dat", ios::binary); // Abrir el archivo para lectura en modo binario
    if (!archivo) { // Si no se pudo abrir el archivo
        cout << "No hay empleados registrados." << endl; // Mensaje de error
        return; // Salir de la función
    }

    Empleado empleado; // Declarar una variable para almacenar el empleado actual

    cout << "\n-----------------Información de los empleados---------------------" << endl;
    cout << "Nombre" <<setw(22)<< "Puesto" <<setw(12)<< "Salario\n\n";

    size_t nombreSize, puestoSize;
    while (archivo.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize))) {
        empleado.nombre.resize(nombreSize);
        archivo.read(&empleado.nombre[0], nombreSize);
        archivo.read(reinterpret_cast<char*>(&puestoSize), sizeof(puestoSize));
        empleado.puesto.resize(puestoSize);
        archivo.read(&empleado.puesto[0], puestoSize);
        archivo.read(reinterpret_cast<char*>(&empleado.salario), sizeof(empleado.salario));

        // Mostrar los detalles del empleado
        cout << empleado.nombre << setw(22) << empleado.puesto << setw(12) << empleado.salario << endl;
    }

    archivo.close(); // Cerrar el archivo

    cout << "Presione Enter para continuar..."; // Mensaje para el usuario
    cin.ignore(); // Ignorar cualquier entrada adicional
    cin.get(); // Esperar a que el usuario presione Enter para continuar
}

void sueldos::procesoAsignacionMaestros() {
    string nombre, especializacion, lugarImpartirClases;
    cout << "\n\tIngrese su nombre: ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, nombre);
    cout << "\tIngrese su especialización (Ingeniería o Licenciatura): ";
    getline(cin, especializacion);
    cout << "\tIngrese donde quiere impartir clases (Ingeniería o Licenciatura): ";
    getline(cin, lugarImpartirClases);

    // Guardar la información en un archivo binario
    ofstream file("AsignacionMaestros.dat", ios::binary | ios::app);
    size_t nombreSize = nombre.size();
    size_t especializacionSize = especializacion.size();
    size_t lugarImpartirClasesSize = lugarImpartirClases.size();
    file.write(reinterpret_cast<const char*>(&nombreSize), sizeof(nombreSize));
    file.write(nombre.c_str(), nombreSize);
    file.write(reinterpret_cast<const char*>(&especializacionSize), sizeof(especializacionSize));
    file.write(especializacion.c_str(), especializacionSize);
    file.write(reinterpret_cast<const char*>(&lugarImpartirClasesSize), sizeof(lugarImpartirClasesSize));
    file.write(lugarImpartirClases.c_str(), lugarImpartirClasesSize);
    file.close();

    cout << "\n\t¡La información ha sido guardada con éxito!\n";
    system("pause");
}

void sueldos::generacionNomina() {
    string nombre, mesPago;
    double salario;

    cout << "\n\tIngrese el nombre del empleado: ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, nombre);

    cout << "\tIngrese el sueldo del empleado: ";
    cin >> salario;

    cout << "\tIngrese el mes de pago del empleado: ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, mesPago);

    // Calcular las deducciones
    double deduccionIGGS = salario * 0.055;
    double deduccionISR = salario * 0.0483;
    double deduccionIRTRA = salario * 0.01;
    double totalDeducciones = deduccionIGGS + deduccionISR + deduccionIRTRA;

    // Calcular las bonificaciones
    double bonificacionIncentivo = 250.0;
    double bonificacionExtra = 0.0;

    if (mesPago == "julio") {
        bonificacionExtra = salario; // Bono 14
    } else if (mesPago == "diciembre") {
        bonificacionExtra = salario; // Aguinaldo
    }

    // Calcular el salario neto
    double salarioNeto = salario - totalDeducciones + bonificacionIncentivo + bonificacionExtra;

    // Mostrar los resultados en una tabla
    cout << fixed << setprecision(2); // Establecer la precisión a dos decimales
    cout << "\n-------------------Detalle de Nómina-------------------\n";
    cout << "Empleado: " << nombre << endl;
    cout << "Sueldo Bruto: Q" << salario << endl;
    cout << "--------------------------------------------------------\n";
    cout << "Deducciones:\n";
    cout << "IGSS (5.5%): Q" << deduccionIGGS << endl;
    cout << "ISR (4.83%): Q" << deduccionISR << endl;
    cout << "IRTRA (1%): Q" << deduccionIRTRA << endl;
    cout << "Total Deducciones: Q" << totalDeducciones << endl;
    cout << "--------------------------------------------------------\n";
    cout << "Bonificaciones:\n";
    cout << "Bonificación Incentivo: Q" << bonificacionIncentivo << endl;
    if (bonificacionExtra > 0) {
        cout << "Bonificación Extra: Q" << bonificacionExtra << " (" << (mesPago == "julio" ? "Bono 14" : "Aguinaldo") << ")" << endl;
    }
    cout << "--------------------------------------------------------\n";
    cout << "Sueldo Neto: Q" << salarioNeto << endl;
    cout << "--------------------------------------------------------\n";

    cout << "\n\t¡La nómina ha sido generada con éxito!\n";
    system("pause");
}
