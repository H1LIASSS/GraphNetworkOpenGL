#pragma once

#include <vector>
#include "Vector.h"

class Graph
{
public:
	Graph() { defineGraph(); }
	Graph(int _nodes, int _connections) { nodes = _nodes, weight = _connections; defineGraph(); }
	GLuint& getVAO() { return va; };
	int noc() { return connections.size(); };
private:
	int nodes = 6, weight = 6;

	std::vector<std::vector<int>> graphMap;
	std::vector<GLint> connections;
	std::vector<Vector> vertexes;

	GLuint vb;
	GLuint eb;
	GLuint va;

	void defineGraph();
	void fillvbo();
	void fillebo();
	void fillvao();
};

