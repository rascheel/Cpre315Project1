#include<iostream>
#include<cstdio>
#include"Node.h"
#include<unordered_map>
#include<queue>
using namespace std;


Node Huffman(priority_queue<Node, vector<Node>, Node::Comparator> queue);
void writeBit(bool bit, FILE * fileToWrite, bool flush=0);

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

//	double what = 0;
	//printf("-----------------------------ORDERED---------------------------------\n");
	//while(!queue.empty())
	//{
	//	Node tmpNode = queue.top();
//		printf("%c: %f\%\n", tmpNode.symbol, 100*tmpNode.getFrequency());
//		what += tmpNode.getFrequency();
//		queue.pop();
//	}
//	printf("total percent = %f\%\n", 100*what);
	
	Node prefixTree = Huffman(queue);

	unordered_map<char, char*> prefixTable;

	prefixTree.createPrefixTable(&prefixTable, NULL, 0);

	FILE * fileToWrite = fopen("output.enc", "w+");

	writeBit(0,fileToWrite);
	writeBit(1,fileToWrite);
	writeBit(0,fileToWrite);
	writeBit(0,fileToWrite);
	writeBit(1,fileToWrite);
	writeBit(0,fileToWrite);
	writeBit(0,fileToWrite);
	writeBit(1,fileToWrite);
	writeBit(1,fileToWrite, 1);

	fclose(fileToWrite);
	return 0;
}

Node Huffman(priority_queue<Node, vector<Node>, Node::Comparator> queue)
{
	if(queue.size() == 2)
	{
		Node y = queue.top();
		queue.pop();
		Node z = queue.top();
		queue.pop();
		return Node(&y, &z);
	}
	else
	{
		Node y = queue.top();
		queue.pop();
		Node z = queue.top();
		queue.pop();
		Node yz = Node(&y, &z);

		queue.push(yz);

		Node Tprime = Huffman(queue);
		
		return Tprime;
	} 
}

void writeBit(bool bit, FILE * fileToWrite, bool flush)
{
	static char byte = 0;
	static int bits = 0;
	if(bit)
	{
		byte = byte | (1 << bits);
		bits++;
	}
	else
	{
		byte = byte | (0 << bits);
		bits++;
	}

	if(bits == 8 || flush)
	{
		fputc((char)byte, fileToWrite);
		byte = 0;
		bits = 0;
	}

}
