#include "Graph.h"

#include <iostream>
using namespace std;

void Graph::fillvbo()
{
	for (int i = 0; i < nodes; i++)
	{
		float th = rand() % 360;
		float f = rand() % 360;

		float r = float(rand() % 100) / 100.f;
		float g = float(rand() % 100) / 100.f;
		float b = float(rand() % 100) / 100.f;

		vertexes.push_back(Vector(cos(f)*cos(th), sin(f), cos(f) * sin(f)));
		vertexes.push_back(Vector(r,g,b));
	}

	glGenBuffers(1, &vb);
	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glBufferData(GL_ARRAY_BUFFER, vertexes.size() * sizeof(Vector), vertexes.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Graph::fillebo()
{
	for (int i = 1; i < graphMap.size(); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (graphMap[j][i] > 0)
			{
				connections.push_back(i*2);
				connections.push_back(j*2);
			}
		}
	}
	std::cout << std::endl;

	//for (int i = 0; i < connections.size(); i++)
	//{
	//	cout << connections[i] << ", ";
	//}


	glGenBuffers(1, &eb);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, connections.size() * sizeof(GLint), connections.data(), GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Graph::fillvao()
{
	glGenVertexArrays(1, &va);
	glBindVertexArray(va);

	glBindBuffer(GL_ARRAY_BUFFER, vb);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eb);

	// ??????? ? ????????????
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// ??????? ? ??????
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void Graph::defineGraph()
{
	int degree = 2 * weight;

	std::vector<double> probabilities;
	probabilities.push_back(0);

	for (int i = 0; i < nodes; i++)
	{
		std::vector<int> a;
		for (int j = 0; j < nodes; j++)
		{
			a.push_back(0);
		}
		graphMap.push_back(a);
		graphMap[i][i] = weight;

		probabilities.push_back(0);
	}



	graphMap[0][0] = 2 * weight;						////
	/*Filling default values*/							//// forgot my own math
	for (int i = 1; i < nodes; i++)
	{
		for (int j = 0; j < weight; j++)
		{
			for (int x = 0; x < i; x++)
			{
				double s = 0;
				for (int y = 0; y < i; y++)
				{
					s += graphMap[x][y];
				}
				probabilities[x + 1] = (probabilities[x] + (s / degree) * 100);
			} //get probability zones 
			double p = rand() % 100;
			for (int x = 0; x < probabilities.size() - 1; x++)
			{
				if (probabilities[x] <= p && probabilities[x + 1] >= p)
				{
					graphMap[x][i] += 1;
					break;
				}
			}
		}
		degree += 2 * weight;
	}				////			////			
														
	/*for (int i = 0; i < graphMap.size(); i++)
	{
		for (int j = 0; j < graphMap.size(); j++)
		{
			std::cout << graphMap[i][j] << ",";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;*/

	fillvbo();
	fillebo();
	fillvao();

	cout << endl;

	for (int i = 0; i < nodes; i++)
	{
		int s = 0;
		for (int j = i+1; j < nodes; j++)
		{
			s += graphMap[i][j];
		}
		cout << s << ", ";
		//how would work 
	}
	cout << endl;
	cout << endl;

	cout << graphMap[0].size();
}