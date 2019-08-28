#ifndef ISTACK_H
#define ISTACK_H

template< class T >
class IStack
{
public:
	virtual ~IStack() {};
	// destructor

	virtual void clear(void) = 0;
	// clear all data in stack

	virtual int size(void) = 0 ;
	// get number of data in stack

	virtual bool isEmpty(void) = 0;
	// query if stack empty

	virtual bool isFull(void) = 0;
	// query if stack full

	virtual void push(T& x) = 0;
	// push data in stack

	virtual T* pop(void) = 0;
	// pop top data in stack

	virtual T* peek(void) = 0;
	// peek top data in stack

	virtual void show(void) = 0;
	// show data in stack
};

#endif
