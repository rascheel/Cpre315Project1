#include "Node.h"
using namespace std;

Node::Node(Node * _zero, Node * _one)
{
	zero = _zero;
	one = _one;
}

Node::Node()
{
	zero = NULL;
	one = NULL;
}

Node::Node(char _symbol, double _frequency)
{
	symbol = _symbol;
	frequency = _frequency;
	zero = NULL;
	one = NULL;
}

Node::~Node()
{
}

double Node::getFrequency()
{
	if(zero == NULL && one == NULL)//If it is a leaf then we return it's frequency
	{
		return frequency;
	}
	else if(zero == NULL)
	{
		printf("ERROR: Zero is null, but one isn't.\n");
	}
	else if(one == NULL)
	{
		printf("ERROR: One is null, but zero isn't.\n");
	}
	else
	{
		return zero->getFrequency() + one->getFrequency();
	}
}

bool Node::Comparator::operator()(Node& lhs, Node& rhs) const
{
	return lhs.getFrequency() > rhs.getFrequency();
}

void Node::createPrefixTable(unordered_map<char, prefix> * prefixTable, char * prevString, int depth)
{
	//printf("before if/elses %x %x\n", zero, one);
	//fflush(stdout);
	if(zero == NULL && one == NULL)
	{
		//printf("in if\n");
		//fflush(stdout);
		prefix pfixToInsert;
		pfixToInsert.prefix = prevString;
		pfixToInsert.bitLength = depth;
		prefixTable->insert(pair<char, prefix>(symbol, pfixToInsert));
	}
	else if(zero == NULL)
	{
		printf("zero is null, and one isnt.\n");
		fflush(stdout);
	}
	else if(one == NULL)
	{
		printf("one is null, and zero isn't.\n");
		fflush(stdout);
	}
	else
	{
		char * zeroString = (char*)malloc(sizeof(char)*(depth+1));
		//printf("depth %i\n", depth);
		//fflush(stdout);
		for(int i = 0; i < depth; i++)
		{
			zeroString[i] = prevString[i];
		}
		//printf("after loop zero\n", depth);
		//fflush(stdout);
		zeroString[depth] = '1';
		//printf("after assigning new zero, %x %x\n", zero, one);
		//fflush(stdout);
		zero->createPrefixTable(prefixTable, zeroString, depth+1);

		//printf("depth %i\n", depth);
		//fflush(stdout);

		char * oneString = (char*)malloc(sizeof(char)*(depth+1));
		for(int i = 0; i < depth; i++)
		{
			oneString[i] = prevString[i];
		}
		//printf("after loop one\n", depth);
		//fflush(stdout);
		oneString[depth] = '0';
		//printf("after assigning new one\n");
		//fflush(stdout);
		one->createPrefixTable(prefixTable, oneString, depth+1);
		free((void*)prevString);
	}
}






