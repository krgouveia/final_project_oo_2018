/**
 * \file queue.hpp
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 11, 2018
 *
 **************************************************************************
 *
 * Module Name:  queue.hpp
 *
 * \brief Define the template class of a queue.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   11-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include "node.hpp"

/** \class Cqueue
*	\brief Queue implementation with generic node.
*	\details This template class implements the methods to initialize and access queues with generic nodes.
*/
template<class T>
class Cqueue
{
	private:
		Cnode<T>* first;
		Cnode<T>* last;
		int size;
	public:
		Cqueue();
		~Cqueue();
		bool checkEmpty();
		int getSize();
		void pushBack(T);
		T popFront();
};


/**
 * \brief Class constructor
 */ 
template<class T>
Cqueue<T>::Cqueue()
{
	first = nullptr;
	last = nullptr;
	size = 0;
}

/**
 * \brief Class destructor
 */
template<class T>
Cqueue<T>::~Cqueue() {
	while (first != nullptr) popFront();
}

/**
 * \brief Method to check if the queue is empty
 * \param none
 * \return bool - TRUE if the queue is empty, FALSE if it isn't.
 */
template<class T>
bool Cqueue<T>::checkEmpty()
{
	return size == 0 ? true : false;
}

/**
 * \brief Method to obtain the number of nodes that a queue contains.
 * \param none
 * \return int - number of nodes.
 */
template<class T>
int Cqueue<T>::getSize()
{
	return size;
}

/**
 * \brief Method to create a node to insert new data at the end of teh queue.
 * \param newData - Generic data type to be inserted at the queue.
 * \return none
 */
template<class T>
void Cqueue<T>::pushBack(T newData)
{
	Cnode<T>* temp = new Cnode<T>();
	temp->setData(newData);
	temp->setNext(nullptr);

	if (checkEmpty())
	{
		first = last = temp;
	}
	else
	{
		last->setNext(temp);
		last = temp;
	}
	size++;
}

/**
 * \brief Method to get the data from the queue and delete the node used to store it.
 * \param none
 * \return T - generic data type information.
 */
template<class T>
T Cqueue<T>::popFront()
{
	T element = first->getData();
	Cnode<T>* temp = first;
	first = first->getNext();
	size--;
	delete temp;
	return element;
}
#endif
