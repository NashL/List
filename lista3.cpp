#include <iostream>

using namespace std;

template <class T>
struct Nodo{
	Nodo(T d);
	T data;
	Nodo<T>*next;
};

template <class T>
Nodo<T>::Nodo(T d){
	data = d;
	next = NULL;
}

template <class T>
class Lista{

	public:
	typedef Nodo<T> nodo;
	Lista();
	bool buscar(nodo** &p, T d);
	bool insertar(T d);
	bool borrar(T d);
	void imprimir();
	nodo* head;
};

template <class T>
Lista<T>::Lista(){
	head= NULL;
}

template <class T>
bool Lista<T>::buscar(nodo**& p, T d){
	
	for(p = &head; (*p) && (*p)->data < d; p = &(*p)->next){}
	return (*p) && (*p)->data == d;
		
}

template <class T>
bool Lista<T>::insertar(T d){
	nodo** p;
	if(buscar(p,d))
		return 0;

	nodo* temp = new nodo(d);
	temp->next = *p;
	*p = temp;
	return 1;
}

template <class T>
bool Lista<T>::borrar(T d){
	nodo** p;
	if(!buscar(p,d))
		return 0;
	
	nodo* temp = *p;
	*p = (*p)->next;
	delete temp;
return 1;
}
template <class T>
void Lista<T>:: imprimir(){
	nodo* q = head;

	for(;q;q = q->next)
		cout << q->data << " ";

	cout << endl;
}
int main(){

	Lista<int> list;
	list.insertar(3);
	list.insertar(4);
	list.insertar(1);
	list.insertar(44);
	list.insertar(2);
	list.borrar(4);
	list.imprimir();
	return 0;
}



























