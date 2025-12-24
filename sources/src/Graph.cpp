#include "Graph.h"

#include <iostream>
using namespace std;

void Graph::defineGraph()
{
	int degree = 2*weight;

	std::vector<double> probabilities;
	probabilities.push_back(0);

	for (int i = 0; i < nodes; i++)
	{
		std::vector<int> a;
		for (int j = 0; j < nodes; j++)
		{
			a.push_back(0);
		}
		Adjacent.push_back(a);
		Adjacent[i][i] = weight;

		probabilities.push_back(0);

		vertexes.push_back(Vector((float(rand() % 200) - 100.f) / 100.f, (float(rand() % 200) - 100.f) / 100.f, 0.f));
	} 
	Adjacent[0][0] = 2 * weight;
	/*Filling default values*/

	for (int i = 1; i < nodes; i++)
	{
		for (int j = 0; j < weight; j++)
		{
			for (int x = 0; x < i; x++)
			{
				double s = 0;
				for (int y = 0; y < i; y++)
				{
					s += Adjacent[x][y];
				}
				probabilities[x + 1] = (probabilities[x] + (s / degree) * 100);
			} //get probability zones 
			double p = rand() % 100;
			for (int x = 0; x < probabilities.size() - 1; x++)
			{
				if (probabilities[x] <= p && probabilities[x + 1] >= p)
				{
					Adjacent[x][i] += 1;
					break;
				}
			}
		}
		degree += 2 * weight;
	}

	//for (int i = 0; i < Adjacent.size(); i++)
	//{
	//	for (int j = 0; j < Adjacent.size(); j++)
	//	{
	//		std::cout << Adjacent[i][j]<<",";
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;

	//glGenVertexArrays(1, &vao);
	//glBindVertexArray(vao);

	//GLuint vb;
	//glGenBuffers(1, &vb);
	//glBindBuffer(GL_ARRAY_BUFFER, vb);
	//glBufferData(GL_ARRAY_BUFFER, vertexes.size() * sizeof(Vector), vertexes.data(), GL_DYNAMIC_DRAW);
	//glBindBuffer(GL_ARRAY_BUFFER, 0);


	 
	//Element buffer for now holds connections of each graph to who.
	std::vector<GLint> a;
	a.push_back(-1);
	connections.push_back(a);

	for (int i = 1; i < Adjacent[0].size(); i++)
	{
		std::vector<GLint> a;
		for (int j = 0; j < i; j++)
		{
			if (Adjacent[j][i] > 0)
				a.push_back(j);
		}
		connections.push_back(a);
	}

	std::cout << std::endl;

	for (int i = 0; i < connections.size(); i++)
	{
		for (int j = 0; j < connections[i].size(); j++)
		{
			cout << connections[i][j] << ',';
		}
		cout << endl;
	}
	
	GLuint eb;
	glGenBuffers(1, &eb);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, connections.size() * sizeof(GLint), connections.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}