//#include <iostream>
//#include <fstream>
//#include <map>
//#include <vector>
//
////#include "funkcje.h"
//
//void readFile(std::map<int, std::vector<int> > &Graph) {
//	std::fstream file;
//	int id, id2;
//	file.open("Graf.txt");
//	if (!file)
//	{
//		std::cout << "Can't open file" << std::endl;
//	}
//	while (!file.eof())
//	{
//		//std::vector<int>Neighbours;
//		file >> id >> id2;
//		std::map<int, std::vector<int> >::iterator itr;
//		if (Graph.find(id) == Graph.end())
//		{
//		}
//		//Neighbours.push_back(id2);
//		Graph.insert(std::pair<int, std::vector<int>>(id, id2) );
//	}
//}