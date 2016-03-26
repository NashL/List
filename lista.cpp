#include <iostream>

using namespace std;

template <class T>
class Nodo{
public:
	Nodo();
	Nodo(T d);
	T m_data;
	Nodo<T>* next;
};

template <class T>
Nodo<T>::Nodo(){
	next = NULL;
}

template <class T>
Nodo<T>::Nodo(T x){
	m_data = x;
	next = NULL;
}

template <class T>
class Lista {
	public:

	typedef Nodo<T> node;
	Lista();	
	bool find(node**& p, T d);
	bool insertar(T d);
	bool borrar(T d);
	node* cab;
	void imprimir();
};

template <class T>
Lista<T>::Lista(){
	cab= NULL;
}

template <class T>
bool Lista<T>::find(node**& p, T d){
	p = &cab;

	for(;(*p) &&((*p)->m_data < d); p = &(*p)->next);

	return (*p) && (*p)->m_data == d;
}

template <class T>
bool Lista<T>::insertar(T d){
	node** p;
	if(find(p, d))
		return 0;

	node* temp = new Nodo<T>(d);
	temp->next = *p;
	*p = temp;
	return 1;
}
template <class T>
void Lista<T>::imprimir(){
	node* p = cab;
	for(;p ; p = p->next)
		cout << p->m_data<< " ";
	cout << endl; 
}

template <class T>
bool Lista<T>::borrar(T d){
	node** p;
	if(!find(p, d))
		return 0;
	
	node* temp = *p;
	*p = (*p)->next;
	delete temp;
return 1;
}

int main(){

	Lista<int> li;

	li.insertar(10);
	li.insertar(3);
	li.insertar(4);
	li.insertar(9);
	li.imprimir();
	li.borrar(4);
	li.imprimir();
	return 0;
}
