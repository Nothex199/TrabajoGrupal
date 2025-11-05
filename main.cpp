#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Paciente{
	int id;
	string nombre;
	string apellidos;
	int prioridad;
	string estado;
	Paciente*siguiente;
	
	Paciente();
	Paciente(int valor,string name, string apell, int prior,string status){
		id=valor;
		nombre=name;
		apellidos=apell;
		prioridad=prior;
		estado=status;
		siguiente=NULL;
	}
};
//insertar nuevos procesos
void agregarAlFinal(Paciente*&inicio,int valor, string name, string apell, int prior,string status){
	Paciente*nuevoPaciente=new Paciente(valor,name,apell,prior,status);
	if (inicio==NULL){
		inicio==nuevoPaciente;
	}else{
		Paciente*temp=inicio;
		while(temp->siguiente !=NULL){
			temp= temp->siguiente;
		}
		temp->siguiente=nuevoPaciente;
	}
}

//eliminar procesos


//busqueda de procesos por ID o nombre
//modificacion de la prioridad de un proceso

//COLA
//ENCOLAMIENTO DE PROCESOS SEGUN PRIORIDAD
//DESENCOLAMIENTO Y EJECUCION DE PROCESOS
//VISUALIZACION DE LA COLA ACTUAL

//LISTA
//ASIGNACION DE MEMORIA A PROCESOS PUSH
//LIBERACION DE MEMORIA
//ESTADO ACTUAL DE LA MEMORIA

int main(int argc, char** argv) {
	cout<<"-----Comenzamos el proyecto-----"<<endl;
	return 0;
}

