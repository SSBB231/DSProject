#ifndef DLCURSORLIST_H
#define DLCURSORLIST_H

#include "tdalist.h"

class DLCursorList : public TDAList
{
	//Define una estructura parecida al nodo de una lista enlazada.
	struct Registry
	{
		int prev, next;
		Object* datum;
	};

	//Mapa que simula la lista enlazada.
	Registry* map;

	//Apunta al primer nodo.
	int head;

	//Determina la capacidad de la lista.
	int capacity;
	

	//Encuentra un nuevo espacio dónde insertar.
	int findNextSlot() const;

public:
	//Constructor. Recibe un entero que determina su capacidad.
	DLCursorList(int=5);

	//Destructor.
	~DLCursorList();

	//Inserta un elemento a la lista.
	virtual bool insert(Object*, int);

	//Consigue el índice del elemento especificado como parámetro.
    	virtual int indexOf(Object*) const;

	//Retorna el objeto localizado en la posición especificada.
  	virtual Object* get(unsigned) const;

	//Retorna el elemento especificado y lo borra de la lista.
	virtual Object* remove(unsigned);

	/*
	* Retorna la posición (en la lista) del objeto 
	* que está antes del especificado
	* por el parámetro.
	*/
	virtual int prev(int) const;

	/*
	* Retorna la posición (en la lista) del objeto 
	* que está después del especificado
	* por el parámetro.
	*/
	virtual int next(int) const;

	//Borra todos los elementos de la lista.
	virtual void clear();

	//Retorna el primer elemento de la lista.
	virtual Object* first() const;

	//Retorna el último elemento de la lista.
	virtual Object* last() const;
	
	//Retorna la representación en cadena de la lista.
	virtual void print() const;

	//Determina si la lista está llena o no.
	virtual bool isFull() const;
};

#endif
	
