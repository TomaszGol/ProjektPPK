#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>

//#include "funkcje.h"

enum Color { NoColor = 0, Red = 1, Blue = -1 };

void readFile(std::map<int, std::vector<int> >& Graph) {
	std::fstream file;
	int id, id2;
	file.open("Graf.txt");
	if (!file)
	{
		std::cout << "Can't open file" << std::endl;
	}
	while (!file.eof())
	{
		file >> id >> id2;
		if (Graph.find(id) == Graph.end())
		{
			Graph[id].push_back(id2);

		}
		else {
			Graph[id].push_back(id2);
		}
	}
}
void showMap(std::map<int, std::vector<int> >& Graph)
{
	std::map<int, std::vector<int> >::iterator itr;
	for (itr = Graph.begin(); itr != Graph.end(); itr++)
	{
		std::cout << itr->first << "=> { ";
		for (auto it2 = itr->second.begin(); it2 != itr->second.end(); it2++)
			std::cout <<*it2 << ", ";
		std::cout << "}" << std::endl;
	}
}
bool isBipartite(std::map<int, std::vector<int> >& graph) {
		
	if (graph.empty())
		return false;

	int n = graph.size();
	std::map<int, Color> colors;


	std::map<int, std::vector<int> >::iterator itr;
	for (itr = graph.begin(); itr != graph.end(); itr++)
	{
		colors.insert(std::make_pair((*itr).first, Color::NoColor));
	}

	std::queue<int> q;
	auto first = (*graph.begin()).first;
	q.push(first);
	colors[first] = Color::Red;

	while (!q.empty())
	{
		int v = q.front(); // wierzcholek badany
		q.pop();

		auto vertices = graph[v];
		for (int i = 0; i < vertices.size(); i++)
		{
			int u = vertices[i]; // pojedynczy sasiad

			if (colors[u] == colors[v])
				return false;
			if (colors[u] == Color::NoColor)
			{
				colors[u] = (Color)(-colors[v]); // pomauluj na przeciwny w stosunku do rodzica
				q.push(u);
			}
		}
	}

	return true;
}


int main()
{
	std::map<int, std::vector<int> > Graph;
	readFile(Graph);
	showMap(Graph);
	bool a;
	a = isBipartite(Graph);
	std::cout << a;

}

