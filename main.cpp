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
void agregarPaciente(Paciente*&inicio,int valor, string name, string apell, int prior,string status){
	Paciente*nuevoPaciente=new Paciente(valor,name,apell,prior,status); //los pacientes inician sin medicinas
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
void eliminarPaciente(Paciente*&inicio, int idBuscado){
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
			return;
		}
		anterior=temp;
		temp=temp->siguiente;
	}
	cout<<"No se encontro un Paciente con ese id"<<endl;
};

//busqueda de procesos por ID o nombre
void buscarPaciente(Paciente*&inicio,int idBuscado){
	Paciente* temp=inicio;
	while(temp != NULL){
		if(temp->id==idBuscado){
			cout<<"ID: "<< temp->id<<endl;
			cout<<"Nombre: "<<temp->nombre<<temp->apellidos<<endl;
			cout<<"Prioridad: "<<temp->prioridad<<endl;
			cout<<"Estado: "<<temp->estado<<endl;
		}
		temp=temp->siguiente;
	}
	cout<<"No se encuentra el paciente buscado"
};

//modificacion de la prioridad de un proceso
void ModificarPrioridad (Paciente*&inicio,int idBuscado){
	Paciente* temp=inicio;
	while(temp !=NULL && temp->id!=idBuscado){
		temp=temp->siguiente;
	}
	if (temp==NULL){
		cout<<"No se encontro un paciente con ese ID"<<endl;
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
//Definimos la estructura 
struct Medicina{
	string nombre;
	string dosis;
	string frecuencia;
	Medicina*siguiente; //puntero que actua como TOPE
};
//ASIGNACION DE MEMORIA A PROCESOS PUSH
Medicina* tope=NULL; //la pila empieza vacia
void asignarMedicina(string nombre, string dosis, string frecuencia){ //puntero al paciente que asignaremos medicina
	Medicina*nueva= new Medicina{nombre,dosis,frecuencia,tope}; //reservamos memoria y llenamos los campos, apilamos
	tope=nueva; //ahora el nuevo nodo es el tope actual
	cout<<"Se agrego "<<nombre<<"a la pila."<<endl;
}
//LIBERACION DE MEMORIA --como es pila se eleima el primer nodo qu registro
void eliminarMedicina(){
	if(tope==NULL){ //VERIFICAMOS SI LA PILA ESTA VACIA
		cout<<"La pila esta vacia. No hay elementos que eliminar"<<endl;
		return;
	}
	Medicina*temp=tope; //el elemento a eliminar
	cout<<"Se elimino "<<temp->nombre<<" de la pila."<<endl;
	tope=tope->siguiente; //el tope se mueve al siguiente nodo
	delete temp;
}
//ESTADO ACTUAL DE LA MEMORIA
void MostrarMedicinas(){
	if(tope==NULL){
		cout<<"La pila esta vacia."<<endl;
		return;
	}
	Medicina*temp=tope;
	cout<<"Estado actual de la pila: ";
	while(temp != NULL){
		cout<<"-"<<temp->nombre<<"("<<temp->dosis<<" ,"<<temp->frecuencia<<" )"<<endl;
		temp=temp->siguiente;
	}
}
void menuPacientes(Paciente*&inicio){
		int opcion;
		do{
			system("clear");
			cout<<"=======GESTION DE PACIENTES========"<<endl;
			cout<<"1.Agregar Paciente \n";
			cout<<"2.Buscar Paciente \n";
			cout<<"3.Eliminar paciente \n";
			cout<<"4.Modificar prioridad \n";
			cout<<"3.Lista Segun prioridad \n";
			cout<<"6.Ejecucion de Lista \n";
			cout<<"7.Cola de espera \n";
			cout<<"8.Ingreso de medicina \n";
			cout<<"9.Eliminar Medicina \n";
			cout<<"10.Mostrar medicinas \n";
			cout<<"11.Salir \n";
			cin>>opcion;
			
			switch (opcion){
				case 1:{
					int id,prioridad;
					string nombre,apellido,estado;
					cout<<"Ingrese ID: ";
					cin>>id;
					
					cin.ignore();
					cout<<"Ingrese nombre: ";
					getline(cin,nombre);
					
					cout<<"Ingrese apellido: ";
					getline(cin,apellido);
					
					cout<<"Ingrese Prioridad(1-5): ";
					cin>>prioridad;
					
					cin.ignore();
					cout<<"Ingrese estado: ";
					getline(cin,estado);
					 
					agregarPaciente(inicio,id,nombre,apellido,prioridad,estado);
					cout<<"Paciente ingresado correctamente";
					break;
				}		
				case 2:{
					int id;
					cout<<"Ingrese ID del paciente a Buscar: ";
					cin>>id;
					buscarPaciente(inicio,id);
					break;
				}
				case 3:{
					int id;
					cout<<"Ingresa ID del paciente a eliminar: ";
					cin>>id;
					eliminarPaciente(inicio,id);
					break;
				}
				case 4:{
					int id;
					cout<<"Ingresa ID del paciente a modificar: ";
					cin>>id;
					ModificarPrioridad(inicio,id);
					break;
				}
				case 5:{
					break;
				}
				case 6:{
					break;
				}
				case 7:{
					break;
				}
				case 8:{
					string nombre,dosis,frecuencia;
					cout<<"Ingrese Nombre de la Medicina: ";
					getline(cin,nombre);
					
					cout<<"Ingrese la dosis: ";
					getline(cin,dosis);
					
					cout<<"Ingrese la frecuencia: ";
					getline(cin,frecuencia);
					
					ingresarMedicina(nombre,dosis,frecuencia);
					break;
				}
				case 8:{
					eliminarMedicina();
					break;
				}
				case 9:{
					MostrarMedicinas();
					break;
				}
				case 11:{
					cout<<"Hasta pronto.......";
					break;
				}
				default:
				cout<<"Opcion invalida\n";
				break;	
			}
			
		}while (opcion!=11);
	}
int main(int argc, char** argv) {
	cout<<"-----Comenzamos el proyecto-----"<<endl;
	void MenuPacientes(Pacientes*&inicio){
		int opcion;
		do{
			
		}
	}
	return 0;
}






