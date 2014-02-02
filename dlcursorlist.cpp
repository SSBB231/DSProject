#include "dlcursorlist.h"


//Constructor. Recibe un entero que determina su capacidad.
DLCursorList::DLCursorList(int n)
{
	capacity = n;
	map = new Registry[capacity];
}

//Destructor.
DLCursorList::~DLCursorList()
{
	for(int i = 0; i < capacity; i++)
	{
		if(map[i].datum)
			delete map[i].datum;
	}

	delete[] map;
}

//Inserta un elemento a la lista.
bool DLCursorList::insert(Object* o, int i)
{
	//Valida la posición. Si no es válida, corta y retorna false.
	if(i < 0 || i > size)
		return false;
	
	//Valida que el objeto no sea nulo. Si lo es, corta y retorna false.
	if(o == NULL)
		return false;

	//Si está llena, retornar false y romper el flujo.
	if(size == capacity)
		return false;

	//Encuentra un nuevo espacio.
	int neo = findNextSlot();

	if(neo == -1)
	{
		return false;
	}
	else
	{
		//Ponemos el dato en el espacio designado.
		map[neo].datum = o;

		if(i == 0)
		{
			//Ahora hacemos que neo apunte a la cabeza.
			map[neo].next = head;

			//Hacemos que head también apunte a neo.
			map[head].prev = neo;

			//Convertimos el nuevo nodo en la cabeza.
			head = neo;
		}
		else
		{
			//Creamos un temporal para recorrer la lista.
			int tmp = head;

			//Recorre la lista. Se detiene en i-1.
			for(int j = 0; j < i-1; j++)
			{
				tmp = map[tmp].next;
			}

			//Hacemos que el nuevo apunte al anterior
			//del lugar al que lo insertaremos.
			map[neo].prev = tmp;

			//Hacemos que neo apunte al siguiente de tmp.
			map[neo].next = map[tmp].next;

			//Ahora hacemos al next del anterior neo.
			map[tmp].next = neo;

			//Esta parte enlaza al nuevo con el anterior que le toca.
			if(i < size)
			{
				map[map[neo].next].prev = neo;
			}
		}

		size++;
		return true;
	}
}		

//Consigue el índice del elemento especificado como parámetro.
int DLCursorList::indexOf(Object* object) const
{
	//-1 por si no encuentra el elemento.
	int i = -1;

	if(size > 0)
	{
		for(int j = 0; j < capacity; j++)
		{
			if((map[j].datum)->equals(object))
			{
				i = j;
				break;
			}
		}
	}
}

//Retorna el objeto localizado en la posición especificada.
Object* DLCursorList::get(unsigned i) const
{
	if(i < 0 || i >= size)
	{
		return NULL;
	}
	else
	{
		return map[i].datum;
	}
}

//Retorna el elemento especificado y lo borra de la lista.
Object* DLCursorList::remove(unsigned i)
{
	if(i < 0 || i >= size || size == 0)
	{
		return NULL;
	}
	else
	{
		Object* ret;	

		if(i == 0)
		{
			//Guardamos la cabeza como temporal.
			int tmp = head;

			//Guardamos el dato de tmp.
			ret = map[tmp].datum;

			//Desconectamos al dato del slot.
			map[tmp].datum = NULL;

			//Hacemos a head el siguiente de head.
			head = map[tmp].next;
	
			//Desconectamos al nuevo head del anterior.
			map[head].prev = -1;

			//Desconectamos al head anterior del nuevo.
			map[tmp].next = -1;
		}
		else
		{
			//Creamos la temporal para recorrer.
			int tmp = head;

			//Recorremos el arreglo y nos detenemos en el que borraremos.
			for(int j = 0; j < i; j++)
			{
				tmp = map[tmp].next;
			}

			//Guardamos el dato en la posición.
			ret = map[tmp].datum;

			//Nos deshacemos de la conexión con datum.
			map[tmp].datum = NULL;

			//Hacemos que el anterior se conecte al siguiente.
			map[map[tmp].prev].next = map[tmp].next;

			if(i != size-1)
			{
				//Hacemos que el siguiente se conecte al anterior.
				map[map[tmp].next].prev = map[tmp].prev;

				map[tmp].next = -1;
			}

			//Ahora borramos las conexiones.
			map[tmp].prev = -1;
		}
		
		size--;
		return ret;
	}
}

/*
* Retorna la posición (en la lista) del objeto 
* que está antes del especificado
* por el parámetro.
*/
int DLCursorList::prev(int i) const
{
	if(i < 0 || i >= size || size == 0)
	{
		return -1;
	}
	else
	{
		return map[i].prev;
	}
}

/*
* Retorna la posición (en la lista) del objeto 
* que está después del especificado
* por el parámetro.
*/
int DLCursorList::next(int i) const
{
	if(i < 0 || i >= size || size == 0)
	{
		return -1;
	}
	else
	{
		return map[i].next;
	}
}

//Borra todos los elementos de la lista.
void DLCursorList::clear()
{
	if(size != 0)
	{
		for(int i = 0; i < size; i++)
		{
			if(map[i].datum)
			{
				map[i].prev = -1;
				map[i].next = -1;
				delete map[i].datum;
			}
		}
		
		size = 0;
	}
}

//Retorna el primer elemento de la lista.
Object* DLCursorList::first() const
{
	if(size == 0)
	{
		return NULL;
	}
	else
	{
		return map[head].datum;
	}
}

//Retorna el último elemento de la lista.
Object* DLCursorList::last() const
{
	if(size == 0)
	{
		return NULL;
	}
	else
	{
		int tmp = head;

		for(int i = 0; i < size; i++)
		{
			tmp = map[tmp].next;
		}

		return map[tmp].datum;
	}
}
	
//Imprime cada elemento en la lista.
void DLCursorList::print() const
{
	int tmp = head;

	for(int i = 0; i < size; i++)
	{
		map[tmp].datum->print();
		tmp = map[tmp].next;
	}
}

//Determina si la lista está llena o no.
bool DLCursorList::isFull() const
{
	return (size == capacity);
}

//Encuentra el siguiente espacio dónde insertar.
int DLCursorList::findNextSlot() const
{
	//Variable que guardará la posición libre.
	//Inicializada en -1 por si no encuentra.
	int ret = -1;

	for(int i = 0; i < capacity; i++)
	{
		//Si encuentra espacio, lo guarda y rompe el ciclo.
		if(!map[i].datum)
		{
			ret = i;
			break;
		}
	}

	return ret;
}
