#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;


//Estructura del cliente

struct cliente
{
	char nombre[50],dpi[15];
   int cuenta;
   float saldo,limite;
   struct transaccion
   {
   	int notransaccion;
		float cantidad;
      string descripcion;
      char fecha[15];
      char tipo;
   }transaccion;
   struct transferencia
   {
   	int notransferencia;
      string cuentaDe,cuentaPara,descripcion;
      char fecha[15];
      float monto;
   }transferencia;
   struct prestamo
   {
   	int noprestamo;
      string descripcion;
      char fecha[15];
      float monto;
   }prestamo;
}lista[200];


//Funciones
void menu();
bool esNumerico(string linea);
void alta();
void informes();
void ingresos();
void gastos();
void transferencia();
void deuda();
void alerta(int pos);

void main()
{
	menu();
}

void menu(){
	int n;
	//El ciclo se repite hasta que el usuario decida salir pulsando 7
	while(n!=7){
   	printf("---------- MENU ----------\n");
		printf("1) Modulo de Cuentas\n");
      printf("2) Modulo de Ingresos\n");
      printf("3) Modulo de Gastos\n");
      printf("4) Modulo de Transferencias\n");
      printf("5) Modulo de Gestion de deudas\n");
      printf("6) Modulo de Informes\n");
      printf("7) Salir\n");
      scanf("%d",&n);
		switch (n)
      {
      	case 1:
         	system("cls");
         	printf("Ingresando al Modulo de Cuentas\n\n");
            cin.ignore(256,'\n');
            alta();
            break;
         case 2:
	         system("cls");
         	printf("Ingresando al Modulo de Ingresos\n\n");
            cin.ignore(256,'\n');
            ingresos();
            break;
         case 3:
         	system("cls");
         	printf("Ingresando al Modulo de Gastos\n\n");
            cin.ignore(256,'\n');
            gastos();
            break;
         case 4:
         	system("cls");
         	printf("Ingresando al Modulo de Transferencias\n\n");
            cin.ignore(256,'\n');
            transferencia();
            break;
         case 5:
         	system("cls");
         	printf("Ingresando al Modulo de Gestión de deudas\n\n");
            cin.ignore(256,'\n');
            deuda();
            break;
         case 6:
         	system("cls");
         	printf("Ingresando al Modulo de Informes\n\n");
            cin.ignore(256,'\n');
            informes();
            break;
         case 7:
         	system("cls");
         	printf("Hasta pronto...\n\n");
            system("pause");
            break;
         default:
         	system("cls");
         	printf("Opcion no valida\n\n\n");
            cin.ignore(256,'\n');
      }
   }
}

//Verifica que la cuenta sea un numero entero
bool esNumerico(string linea)
{
   bool b = true;
   int longitud = linea.size();
 
   if (longitud == 0) { 
      b = false;
   } else if (longitud == 1 && !isdigit(linea[0])) {
      b = false;
   } else {
      int i;
      if (linea[0] == '+' || linea[0] == '-')
         i = 1;
      else
         i = 0;
 
      while (i < longitud) {
         if (!isdigit(linea[i])) {
            b = false;
            break;
         }
         i++;
      }
   }
 
   return b;
}


//Modulo de Cuentas
void alta()
{
	float saldo,limite;
   char fecha[10],lineach[50];
   int cuenta;
   //string linea;
   bool repite=true;
   //El ciclo for recorre toda la lista buscando
   //posiciones vacias para agregar a un cliente nuevo
   for(int i=0;i<200;i++){
		if(strlen(lista[i].nombre)==0){
			//cilco se repetira hasta que el usuario de una cuenta con solo numeros
   		do {
      		cout << "Ingrese el numero de cuenta: \n ";
      		cin.getline(lineach, 50);
            string linea(lineach);
		      if (esNumerico(linea)) {
       		  repite = false;
              cuenta = atoi(linea.c_str());
              lista[i].cuenta=cuenta;
              cin.clear();
              cin.ignore(256,'\n');
      		}else {
         		cout << "La cuenta solo debe llevar numeros\n\n" << endl;
      		}
   		}while(repite);
      	printf("Ingrese el nombre del cliente: \n");
         cin.getline(lista[i].nombre,50);
         printf("Ingrese el DPI del cliente: \n");
         cin.getline(lista[i].dpi,15);
         printf("Ingrese el saldo inicial del cliente: \n");
         cin>>saldo;
         lista[i].saldo = saldo;
         printf("Ingrese el limite de la cuenta: \n");
         cin>>limite;
      	cin.ignore(256,'\n');
         printf("Ingrese fecha actual: \n");
         cin.getline(lista[i].transaccion.fecha,15);
         lista[i].limite = limite;
         lista[i].transaccion.notransaccion=1;
         lista[i].transaccion.tipo='n';
         lista[i].transferencia.notransferencia=0;
         lista[i].prestamo.noprestamo=0;
         lista[i].prestamo.descripcion="No";
         lista[i].prestamo.monto=0.0;
         system("pause");
		   system("cls");
         break;
      }
   }
}

//Busca la cuenta
int buscar(int cuent)
{
	for(int i=0;i<200;i++){
   	if(lista[i].cuenta==cuent){
      	return i;
         break;
      }
   }
   return -1;
}

//Sistema de alertas
void alerta(int pos)
{
	if(lista[pos].saldo<=lista[pos].limite){
   	printf("\n\nAlerta, El saldo de la cuenta de: %s\na llegado a su limite\n\n\n\n",lista[pos].nombre);
   }
}

//Modulo de ingresos
void ingresos()
{
	int cuenta;
   float monto;
	printf("Ingrese el numero de cuenta: \n");
   cin>>cuenta;
   //busca la cuenta
   int pos=buscar(cuenta);
   //si la cuenta existe
   if(pos!=-1){
		printf("Ingrese la cantidad a depositar: \n");
	   cin>>monto;
      cin.ignore(256,'\n');
      printf("Ingrese fecha actual: \n");
      cin.getline(lista[pos].transaccion.fecha,15);
      printf("Su saldo anterior era de: %f\n",lista[pos].saldo);
      lista[pos].saldo=lista[pos].saldo+monto;
      printf("Su nuevo saldo es de: %f\n",lista[pos].saldo);
      lista[pos].transaccion.notransaccion++;
      lista[pos].transaccion.tipo='I';
      lista[pos].transaccion.descripcion="Deposito";
   }
   //si la cuenta no existe
   else{
   	printf("La cuenta no existe\n");
   }
   system("pause");
   system("cls");
}

//Modulo Gastos
void gastos()
{
	int cuenta;
   float monto;
	printf("Ingrese el numero de cuenta: \n");
   cin>>cuenta;
   int pos=buscar(cuenta);
   alerta(pos);
   if(pos!=-1){
   	printf("Ingrese la cantidad a debitar: \n");
      cin>>monto;
   	if(lista[pos].saldo>monto){
	      printf("Su saldo anterior era de: %f\n",lista[pos].saldo);
   	   lista[pos].saldo=lista[pos].saldo-monto;
      	printf("Su nuevo saldo es de: %f\n",lista[pos].saldo);
	      lista[pos].transaccion.notransaccion++;
   	   lista[pos].transaccion.tipo='E';
      	lista[pos].transaccion.descripcion="Debito";
         cin.ignore(256,'\n');
         printf("Ingrese fecha actual: \n");
         cin.getline(lista[pos].transaccion.fecha,15);
         alerta(pos);
      }else{
      	printf("El saldo de la cuenta es insuficiente...\n");
      }
   }else{
   	printf("La cuenta no existe\n");
   }
   system("pause");
   system("cls");
}

//Modulo de Transferencias
void transferencia()
{
	int cuenta1,cuenta2;
   float monto;
	printf("Ingrese el numero de cuenta a debitar: \n");
   cin>>cuenta1;
   int pos1=buscar(cuenta1);
   printf("Ingrese el numero de la cuenta a acreditar: \n");
   cin>>cuenta2;
   int pos2=buscar(cuenta2);
   if(pos1!=-1 && pos2!=-1){
		printf("Ingrese el moto de la transferencia:\n");
      cin>>monto;
      if(lista[pos1].saldo>monto){
      	cin.ignore(256,'\n');
         printf("Ingrese fecha actual: \n");
	      cin.getline(lista[pos2].transferencia.fecha,15);
   	   cin.ignore();
      	printf("Saldo de la cuenta a debitar anterior: %f\n",lista[pos1].saldo);
         lista[pos1].saldo=lista[pos1].saldo-monto;
         printf("Saldo de la cuenta a debitar actual: %f\n",lista[pos1].saldo);
         lista[pos1].transaccion.notransaccion++;
         lista[pos1].transaccion.cantidad=monto;
         lista[pos1].transaccion.descripcion="Transferencia";
         lista[pos1].transaccion.tipo='E';
         printf("Saldo de la cuenta a acreditar anterior: %f\n",lista[pos2].saldo);
         lista[pos2].saldo=lista[pos2].saldo+monto;
         printf("Saldo de la cuenta a acreditar actual: %f\n",lista[pos2].saldo);
         lista[pos2].transferencia.notransferencia++;
         lista[pos2].transferencia.monto=monto;
         lista[pos2].transferencia.cuentaDe=lista[pos1].cuenta;
         lista[pos2].transaccion.notransaccion++;
         lista[pos2].transaccion.cantidad=monto;
         lista[pos2].transaccion.descripcion="Transferencia";
         lista[pos2].transaccion.tipo='I';
         alerta(pos1);
         alerta(pos2);
      }else{
      	printf("El saldo de la cuenta a debitar es insuficiente...\n");
      }
   }else{
   	printf("Una de las dos cuentas no existe...\n");
   }
   system("pause");
   system("cls");
}

//Modulo de Deuda
void deuda()
{
	int opt,pos;
   int cuenta;
   float monto;
   printf("Ingrese el numero de cuenta: \n");
   cin>>cuenta;
	pos = buscar(cuenta);
   if(pos!=-1){
   	printf("Que desea realizar: \n");
   	printf("1) Prestamo\n");
   	printf("2) Pago del Prestamo\n");
   	cin>>opt;
   	switch(opt){
   		case 1:
      		printf("Ingrese la cantidad del prestamo \n");
         	cin>>monto;
            cin.ignore(256,'\n');
   	      printf("Ingrese fecha actual: \n");
	         cin.getline(lista[pos].prestamo.fecha,15);
            lista[pos].prestamo.descripcion="Si";
            lista[pos].prestamo.noprestamo++;
            lista[pos].prestamo.monto=monto;
            lista[pos].transaccion.notransaccion++;
            lista[pos].transaccion.descripcion="Prestamo";
            lista[pos].transaccion.tipo='D';
            lista[pos].transaccion.cantidad=monto;
            printf("Prestamo realizado con exito...\n");
            system("pause");
		      system("cls");
         	break;
         case 2:
         	printf("La cantidad de su deuda es de: %f\n",lista[pos].prestamo.monto);
         	printf("Ingrese la cantidad a cancelar; \n");
            cin>>monto;
            if(monto>lista[pos].prestamo.monto && monto>lista[pos].saldo){
         		printf("No puede cancelar mas de lo que debe ó no tiene saldo suficiente\n");
               printf("Su saldo es de: %f\n",lista[pos].saldo);
               system("pause");
			      system("cls");
               break;
            }else{
            	lista[pos].prestamo.monto=lista[pos].prestamo.monto-monto;
               cin.ignore(256,'\n');
	         	printf("Ingrese fecha actual: \n");
		      	cin.getline(lista[pos].transaccion.fecha,15);
               lista[pos].saldo=lista[pos].saldo-monto;
               lista[pos].transaccion.notransaccion++;
      	      lista[pos].transaccion.descripcion="Pago de prestamo";
   	         lista[pos].transaccion.tipo='D';
	            lista[pos].transaccion.cantidad=monto;
	            printf("La nueva cantidad de su deuda es de: %f\n\n",lista[pos].prestamo.monto);
               alerta(pos);
               if(lista[pos].prestamo.monto==0){
               	lista[pos].prestamo.descripcion="No";
               }
               system("pause");
			      system("cls");
               break;
            }
         default:
         	printf("Opcion no valida...\n");
            system("pause");
            system("cls");
   	}
   }else{
   	printf("El cliente debe tener una cuenta para realizar un prestamo...\n");
      system("pause");
      system("cls");
   }
}

//Modulo de Informes
void informes()
{
	int cuent;
	printf("Ingrese el numero de cuenta: \n");
   cin>>cuent;
   int pos=buscar(cuent);
   if(pos!=-1){
      printf("Nombre del cuentahabiente: %s\n",lista[pos].nombre);
      printf("No. de DPI: %s\n",lista[pos].dpi);
      printf("Saldo de la cuenta: %f\n",lista[pos].saldo);
		printf("Limite de la cuenta: %f\n\n",lista[pos].limite);
      printf("No. de transcacciones: %d\n",lista[pos].transaccion.notransaccion);
      printf("Descripcion de la ultima transaccion: %s\n",lista[pos].transaccion.descripcion);
      printf("Tipo de la ultima transaccion: %c\n",lista[pos].transaccion.tipo);
      printf("Monto de la ultima transaccion: %f\n",lista[pos].transaccion.cantidad);
      printf("Fecha de la ultima transaccion: %s\n\n",lista[pos].transaccion.fecha);
      printf("No. de transferencias: %d\n",lista[pos].transferencia.notransferencia);
      printf("Fecha de la ultima transferencia: %s\n",lista[pos].transferencia.fecha);
      printf("Monto de la ultima transferencia: %f\n",lista[pos].transferencia.monto);
      printf("Transferencia recivida de la cuenta: %s\n\n",lista[pos].transferencia.cuentaDe);
      printf("Prestamo: %s\n",lista[pos].prestamo.descripcion);
      printf("Fecha del prestamo: %s\n",lista[pos].prestamo.fecha);
      printf("Monto del prestamo: %f\n",lista[pos].prestamo.monto);
   	system("pause");
	   system("cls");
   }else{
   	printf("La cuenta no existe\n");
      system("pause");
      system("cls");

   }

}