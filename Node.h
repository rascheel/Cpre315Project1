#ifndef NODE_H
#define NODE_H

#include <cstddef>
#include <cstdio>

class Node
{
public:
	Node * zero = NULL;//This is a binary tree so it's edges are either labeled zero or one
	Node * one = NULL;

	char symbol;
	double frequency;

	Node();
	Node(char _symbol, double _frequency);
	~Node();

	double getFrequency();

	class Comparator
	{
	public:
		bool operator()( Node& lhs,  Node& rhs) const;
	};	

};

#endif
