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
Paciente* agregarPaciente(Paciente*&inicio,int valor, string name, string apell, int prior,string status){
	Paciente*nuevoPaciente=new Paciente(valor,name,apell,prior,status); //los pacientes inician sin medicinas
	nuevoPaciente->siguiente=NULL;
	if (inicio==NULL){
		inicio=nuevoPaciente;
	}else{
		Paciente*temp=inicio;
		while(temp->siguiente !=NULL){
			temp= temp->siguiente;
		}
		temp->siguiente=nuevoPaciente;
	}
	return nuevoPaciente;
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
void buscarPaciente(Paciente*&inicio, int idBuscado){
	Paciente*temp=inicio;
	while(temp != NULL){
		if(temp->id==idBuscado){
			cout<<"ID: "<< temp->id<<endl;
			cout<<"Nombre: "<<temp->nombre<<" "<<temp->apellidos<<endl;
			cout<<"Prioridad: "<<temp->prioridad<<endl;
			cout<<"Estado: "<<temp->estado<<endl;
		}
	
		temp=temp->siguiente;
	}cout<<"No se encuentra el paciente buscado";
}

//modificacion de la prioridad de un proceso
void ModificarPrioridad (Paciente*&inicio,int idBuscado){
	Paciente*temp=inicio;
	while(temp !=NULL && temp->id!=idBuscado){
		temp=temp->siguiente;
	}
	if (temp==NULL){
		cout<<"No se encontro un paciente con ese ID"<<endl;
		return;
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
};

//COLA
struct Cola{
	Paciente*primero;
	Paciente*fin;
	Cola(){
		primero=NULL;
		fin=NULL;
	}
};
//ENCOLAMIENTO DE PROCESOS SEGUN PRIORIDAD
void encolarPrioridad(Cola &cola, int id, string nombre, string apellido, int prioridad, string estado) {
   Paciente*nuevo=new Paciente(id, nombre, apellido, prioridad, estado);
    // Si la cola estÃ¡ vacÃ­a
    if (cola.primero == NULL){
        cola.primero = nuevo;
        cola.fin = nuevo;
        return;
    }

    // Si el nuevo paciente tiene mayor prioridad que el primero
    if (nuevo->prioridad > cola.primero->prioridad) {
        nuevo->siguiente = cola.primero;
        cola.primero = nuevo;
        return;
    }

    // Insertar en la posiciÃ³n correcta segÃºn prioridad
    Paciente* temp = cola.primero;
    while (temp->siguiente != NULL && temp->siguiente->prioridad >= nuevo->prioridad) {
        temp = temp->siguiente;
    }

    if(nuevo->siguiente==NULL)cola.fin=nuevo;
};

//DESENCOLAMIENTO Y EJECUCION DE PROCESOS
void desencolar(Cola &cola) {
    if (cola.primero == NULL) {
        cout << "La cola estÃ¡ vacÃ­a." << endl;
        return;
    }
    Paciente* temp = cola.primero;
    cout << "Atendiendo a: " << temp->nombre << " " << temp->apellidos<< endl;
    cola.primero = cola.primero->siguiente;
    if (cola.primero == NULL) { 
        // Si la cola queda vacÃ­a
        cola.fin = NULL;
    }
    delete temp; // liberamos memoria
};

//VISUALIZACION DE LA COLA ACTUAL
void mostrarCola(Cola cola) {
    if (cola.primero == NULL) {
        cout << "La cola estÃ¡ vacÃ­a." << endl;
        return;
    }
    Paciente* temp = cola.primero;
    cout << "\n--- Cola de espera ---" << endl;
    while (temp != NULL) {
        cout << "ID: " << temp->id 
             << " Nombre: " << temp->nombre << " " << temp->apellidos 
             << " Prioridad: " << temp->prioridad 
             << " Estado: " << temp->estado << endl;
        temp = temp->siguiente;
    }
};

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
void ingresarMedicina(string nombre, string dosis, string frecuencia){ //puntero al paciente que asignaremos medicina
	Medicina*nueva= new Medicina{nombre,dosis,frecuencia,tope}; //reservamos memoria y llenamos los campos, apilamos
	tope=nueva; //ahora el nuevo nodo es el tope actual
	cout<<"Se agrego "<<nombre<<" a la pila."<<endl;
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
};
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
};
void menuPacientes(Paciente*&inicio){
		int opcion;
		Cola colaPacientes;
		do{
			cout<<"\n=======GESTION DE PACIENTES========\n";
			cout<<"1.Agregar Paciente \n";
			cout<<"2.Buscar Paciente \n";
			cout<<"3.Eliminar paciente \n";
			cout<<"4.Modificar Prioridad \n";
			cout<<"5.Ejecucion de Lista \n";
			cout<<"6.Cola de espera \n";
			cout<<"7.Ingreso de medicina \n";
			cout<<"8.Eliminar Medicina \n";
			cout<<"9.Mostrar medicinas \n";
			cout<<"10.Salir \n";
			cin>>opcion;
			
			switch (opcion){
				case 1:{
					int valor,prior;
					string name,apell,status;
					cout<<"Ingrese ID: ";
					cin>>valor;
					
					cin.ignore();
					cout<<"Ingrese nombre: ";
					getline(cin,name);
					
					cout<<"Ingrese apellido: ";
					getline(cin,apell);
					
					cout<<"Ingrese Prioridad(1-5): ";
					cin>>prior;
					
					cin.ignore();
					cout<<"Ingrese estado: ";
					getline(cin,status);
					 
					Paciente* pacienteNuevo=agregarPaciente(inicio,valor,name,apell,prior,status);
					encolarPrioridad(colaPacientes,pacienteNuevo->id,pacienteNuevo->nombre,pacienteNuevo->apellidos,pacienteNuevo->prioridad,pacienteNuevo->estado);
					cout<<"Paciente ingresado correctamente\n";
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
					mostrarCola(colaPacientes);
					break;
				}
				case 6:{
					desencolar(colaPacientes);
					break;
				}
				case 7:{
					string nombre,dosis,frecuencia;
					cin.ignore();
					
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
				case 10:{
					cout<<"Hasta pronto.......";
					break;
				}
				default:
				cout<<"Opcion invalida\n";
				break;	
			}
			
		}while (opcion!=10);
	}
int main(int argc, char** argv) {
	Paciente*inicio=NULL;
	menuPacientes(inicio);
	return 0;
}







