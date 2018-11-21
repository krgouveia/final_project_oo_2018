/**
 * \file node.hpp
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 11, 2018
 *
 **************************************************************************
 *
 * Module Name:  node.hpp
 *
 * \brief Define the template class of a node to be used for data structures.
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

#ifndef NODE_H
#define NODE_H

/** \class node
 *  \brief Template of a generic node.
 *  \details This class defines a node to be used in double linked data structures.
 */
 template<class T>
class Cnode
{
	private:
		Cnode* next;
		Cnode* previous;
		T data;
	public:
		Cnode();
		Cnode(T newData, Cnode* nextNode);
		~Cnode();
		void setNext(Cnode* nextNode);
		void setPrevious(Cnode* previousNode);
		void setData(T newData);
		Cnode* getNext();
		Cnode* getPrevious();
		T getData();
};

/**
 * Class constructor with no data.
 */
template<class T>
Cnode<T>::Cnode()
{
	previous = nullptr;
	next = nullptr;
}

/**
 * Class constructor inserting new data.
 */
template<class T>
Cnode<T>::Cnode(T newData, Cnode* nextNode)
{
	data = newData;
	next = nextNode;
}

/**
 * Class destructor
 */
template<class T>
Cnode<T>::~Cnode()
{
	next = nullptr;
	previous = nullptr;
	delete next;
	delete previous;
}

/**
 * Method to set next pointer.
 * \param Cnode* - pointer to the next node.
 * \return none
 */
template<class T>
void Cnode<T>::setNext(Cnode* nextNode)
{
	next = nextNode;
}

/**
 * Method to set previous pointer.
 * \param Cnode* - pointer to the previous node.
 * \return none
 */
template<class T>
void Cnode<T>::setPrevious(Cnode* previousNode)
{
	previous = previousNode;
}

/**
 * Method to set a generic type data.
 * \param newData - data to be stored.
 * \return none
 */
template<class T>
void Cnode<T>::setData(T newData)
{
	data = newData;
}

/**
 * Method to get the pointer to the next node.
 * \param none
 * \return Cnode* - pointer to the next node.
 */
template<class T>
Cnode<T>* Cnode<T>::getNext()
{
	return next;
}

/**
 * Method to get the pointer to the previous node.
 * \param none
 * \return Cnode* - pointer to the previous node.
 */
template<class T>
Cnode<T>* Cnode<T>::getPrevious()
{
	return previous;
}

/**
 * Method to get the data from the node.
 * \param none
 * \return T - generic data stored.
 */
template<class T>
T Cnode<T>::getData()
{
	return data;
}


#endif
