#pragma once

#include <vector>
#include "Vector.h"

class Graph
{
public:
	Graph() { defineGraph(); }
	Graph(int _nodes, int _connections) { nodes = _nodes, weight = _connections; defineGraph(); }

	
private:
	int nodes = 6, weight = 6;

	std::vector<std::vector<int>> Adjacent;
	std::vector<std::vector<GLint>> connections;
	std::vector<Vector> vertexes;


	void defineGraph();
};

