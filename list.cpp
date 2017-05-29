#include <iostream>

using namespace std;

template <class T>
class Node{
public:
	Node();
	Node(T d);
	T m_data;
	Node<T>* next;
};

template <class T>
Node<T>::Node(){
	next = NULL;
}

template <class T>
Node<T>::Node(T x){
	m_data = x;
	next = NULL;
}

template <class T>
class List {
	public:

	typedef Node<T> node;
	List();	
	bool find(node**& p, T d);
	bool insert(T d);
	bool remove(T d);
	node* head;
	void print();
};

template <class T>
List<T>::List(){
	head= NULL;
}

template <class T>
bool List<T>::find(node**& p, T d){
	p = &head;

	for(;(*p) &&((*p)->m_data < d); p = &(*p)->next);

	return (*p) && (*p)->m_data == d;
}

template <class T>
bool List<T>::insert(T d){
	node** p;
	if(find(p, d))
		return 0;

	node* temp = new Node<T>(d);
	temp->next = *p;
	*p = temp;
	return 1;
}
template <class T>
void List<T>::print(){
	node* p = head;
	for(;p ; p = p->next)
		cout << p->m_data<< " ";
	cout << endl; 
}

template <class T>
bool List<T>::remove(T d){
	node** p;
	if(!find(p, d))
		return 0;
	
	node* temp = *p;
	*p = (*p)->next;
	delete temp;
return 1;
}

int main(){

	List<int> list;

	list.insert(10);
	list.insert(3);
	list.insert(11);
	list.insert(1);
	list.insert(2);
	list.insert(4);
	list.insert(9);
	list.remove(4);
	list.print();
	return 0;
}
