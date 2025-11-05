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
	
	Paciente(){};
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
		inicio=nuevoPaciente;
	}else{
		Paciente*temp=inicio;
		while(temp->siguiente !=NULL){
			temp= temp->siguiente;
		}
		temp->siguiente=nuevoPaciente;
	}
};

//eliminar procesos
void EliminarPaciente(Paciente*&inicio, int idBuscado){
	Paciente*temp=inicio;
	Paciente*anterior=NULL;
	//Iniciamos un bucle que recorre la lista
	while (temp != NULL){ 
		if(temp->id==idBuscado){
			if(anterior==NULL){ //en caso se elimine el primer nodo, a fin de que la list no quede rota, actualizamos el nuevo nodo de inicio
				inicio=temp->siguiente; 
			}else{
				anterior->siguiente=temp->siguiente;
			}
			delete temp;
			cout<<"Paciente con ID "<<idBuscado<<" eliminado"<<endl;
			return
		}
		anterior=temp;
		temp=temp->siguiente;
	}
	cout<<"No se encontro un Paciente con ese id"<<endl;
};

//busqueda de procesos por ID o nombre
void BuscarPorID(Paciente*&inicio,int idBuscado){
	Paciente* temp=inicio;
	while(temp != NULL){
		if(temp->id==idBuscado){
			cout<<"ID: "<< temp->id<<endl;
			cout<<"Nombre: "<<temp->nombre<<temp->apellidos<<endl;
			cout<<"Prioridad: "<<temp->prioridad<<endl;
			cout<<"Estado: "<<temp->estado<<endl;
		}
		actual=actual->siguiente;
	};
	cout<<"No se encuentra el paciente buscado"
}

//modificacion de la prioridad de un proceso
void ModificarPrioridad (Paciente*&inicio,int idBuscado){
	Paciente* temp=inicio;
	while(temp !=NULL && temp->id!=idBuscado){
		temp=temp->siguiente;
	}
	if (temp==NULL){
		cout<<"No se encontro un paciente con ese ID"<<ENDL;
	}
	cout<<"Paciente Encontrado";
	cout<<"ID: "<< temp->id<<endl;
	cout<<"Nombre: "<<temp->nombre<<temp->apellidos<<endl;
	cout<<"Prioridad: "<<temp->prioridad<<endl;
	cout<<"Estado: "<<temp->estado<<endl;
	int nuevaPrioridad;
	cout<<"Ingrese la nueva prioridad: ";
	cin>>nuevaPrioridad;
	
	temp->prioridad=nuevaPrioridad;
	cout<<"Prioridad actualizada correctamente";
}

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


