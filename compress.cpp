#include<iostream>
#include<cstdio>
#include"Node.h"
#include<unordered_map>
#include<queue>
using namespace std;

int main()
{
	//cout << "hello" << endl;
	FILE * fileToRead;
	char * fileName = "sample1.txt";

	fileToRead = fopen(fileName, "r");
	if(fileToRead == NULL)
	{
		printf("error reading file\n");
		return 0;
	}
	int c;
	unordered_map<char, int> frequencyMap;
	int fileLength = 0;
	do {
		c = fgetc(fileToRead);
		fileLength++;
		//printf("%c", c);
		int count = frequencyMap.count(c);
		if(count == 0)
		{
			frequencyMap.insert(pair<char, int>((char)c, 1));
		}
		else
		{
			frequencyMap.at((char)c) += 1;
		}
		
	}while(c != EOF);
	unordered_map<char, int>::iterator iterator = frequencyMap.begin();
	priority_queue<Node, vector<Node>, Node::Comparator> queue;
	while(iterator != frequencyMap.end())
	{
		//printf("%c: %i\n", iterator->first, iterator->second);
		Node tmpNode = Node(iterator->first, (double)(((double)iterator->second)/(double)fileLength));
		queue.push(tmpNode);
		iterator++;
	}

	double what = 0;
	printf("-----------------------------ORDERED---------------------------------\n");
	while(!queue.empty())
	{
		Node tmpNode = queue.top();
		printf("%c: %f\%\n", tmpNode.symbol, 100*tmpNode.getFrequency());
		what += tmpNode.getFrequency();
		queue.pop();
	}
	printf("total percent = %f\%\n", 100*what);
	

		


	return 0;
}

Node Huffman(priority_queue<Node, vector<Node>, Node::Comparator> queue)
{
	if(queue.size() == 2)
	{
		
	}
	else
	{
		Node y = queue.top();
		queue.pop();
		Node z = queue.top();
		queue.pop();

		Node yz = Node();
		yz.zero = &y;
		yz.one = &z;

		queue.push(yz);

		Node Tprime = Huffman(queue);
		
		Node T = 
}
