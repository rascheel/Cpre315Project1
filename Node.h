#ifndef NODE_H
#define NODE_H

#include<cstdlib>
#include <cstddef>
#include <cstdio>
#include<unordered_map>
using namespace std;

typedef struct prefix
{
	char * prefix;
	int bitLength;
};

class Node
{
public:
	Node * zero;//This is a binary tree so it's edges are either labeled zero or one
	Node * one;

	char symbol;
	double frequency;

	Node(Node * _zero, Node * _one);
	Node();
	Node(char _symbol, double _frequency);
	~Node();
	
	void createPrefixTable(unordered_map<char, prefix> * prefixTable, char * prevString, int depth);

	double getFrequency();

	class Comparator
	{
	public:
		bool operator()( Node& lhs,  Node& rhs) const;
	};	

};

#endif
