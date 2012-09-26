#include "Node.h"


Node::Node()
{
}

Node::Node(char _symbol, double frequency)
{
	symbol = _symbol;
	frequency = _frequency;
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
