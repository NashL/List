#include <iostream>

using namespace std;

template <class T>
struct Nodo{
	Nodo<T>* next;
	T dato;
	Nodo(T);
};

template <class T>
Nodo<T>::Nodo(T d){
	dato = d;
	next = NULL;
}

template <class T>
class Lista{
	public:
	typedef Nodo<T> node;
	Lista();
	bool buscar(node**& p, T d);
	bool insertar(T d);
	bool borrar(T d);
	node* cab;
	void imprimir();
};

template <class T>
Lista<T>::Lista(){
	cab = NULL;
}

template <class T>
bool Lista<T>::buscar(node**& p, T d){
	
	for(p = &cab; (*p) && (*p)->dato < d; p = &(*p)->next){}
//	return !!(*p);	
return (*p) && (*p)->dato == d;
}
template <class T>
bool Lista<T>::insertar(T d){
	
	node** p;
	if(buscar(p, d))
		return 0;
	node* temp = new node(d);
	temp->next = *p;
	*p = temp;
	return 1;
}
template <class T>
bool Lista<T>::borrar(T d){

	node** p;
	if(!buscar(p,d))	
		return 0;

	node* temp = *p;
	*p = (*p)->next;
	delete temp;
	return 1;

}
	
template <class T>
void Lista<T>::imprimir(){
	node* q = cab;
	for(;q; q = q->next)
		cout << q->dato << " ";
	cout << endl;
return ;
}


int main(){

	Lista<int> li;
	li.insertar(3);
	li.insertar(33);
	li.insertar(44);
	li.insertar(8);
	li.insertar(11);
	li.insertar(22);
	li.borrar(3);
	li.imprimir();
}
















	
