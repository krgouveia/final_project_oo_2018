/**
 * \file teste_queue.cpp
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 12, 2018
 *
 **************************************************************************
 *
 * Module Name:  teste_queue.cpp
 *
 * \brief Main program to test the queue and node classes.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   12-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#include "queue.hpp"
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
	Cqueue<string> q;

	if (q.checkEmpty())
	{
		cout << "Queue is empty" << endl;
	}

	// Enqueue elements
	q.pushBack("Message 1");
	cout << "Size of queue = " << q.getSize() << endl;
	q.pushBack("Message 2");
	cout << "Size of queue = " << q.getSize() << endl;
	q.pushBack("Message 3");
	cout << "Size of queue = " << q.getSize() << endl;

	// Dequeue elements
	cout << q.popFront() << endl;
	cout << "Size of queue = " << q.getSize() << endl;
	cout << q.popFront() << endl;
	cout << "Size of queue = " << q.getSize() << endl;
	cout << q.popFront() << endl;
	cout << "Size of queue = " << q.getSize() << endl;

	system("PAUSE");
}
