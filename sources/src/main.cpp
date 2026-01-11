#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <vector>

#include "Shader.h"
#include "Graph.h"

using namespace std;


void projectInit()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

void windowInit(GLFWwindow* window, int width, int height)
{
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
}


int main()
{   
    projectInit();
    int w = 640, h = 640;

    GLFWwindow* window = glfwCreateWindow(w, h, "GraphNetwork 1S", NULL, NULL);
    windowInit(window, w, h);
    Shader shader;
	Graph graph(1000,1);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader.getShaderProgram());

        glBindVertexArray(graph.getVAO());
        glDrawElements(GL_LINES, graph.noc(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
	
    glfwTerminate();
    return 0;
}
////////////////////////////////
///
///
///
///сфера вставить вершины на поверхности сферы  
///  
///  
/// 
////////////////////////////////


//void fGraph()
//{
//	int degree = 0;
//	const int graphSize = 6, m = 6;
//	int Adjacent[graphSize][graphSize];
//	vector<double> probabilities;
//	probabilities.push_back(0);
//
//
//	for (int i = 0; i < graphSize; i++)
//	{
//		for (int j = 0; j < graphSize; j++)
//		{
//			Adjacent[i][j] = 0;
//		}
//		Adjacent[i][i] = m;
//		probabilities.push_back(0);
//	}
//	Adjacent[0][0] = 2 * m;
//	degree += 2 * m;
//
//
//	for (int i = 1; i < graphSize; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			for (int x = 0; x < i; x++)
//			{
//				double s = 0;
//				for (int y = 0; y < i; y++)
//				{
//					s += Adjacent[x][y];
//				}
//				probabilities[x + 1] = (probabilities[x] + (s / degree) * 100);
//			} //get probability zones 
//			double p = rand() % 100;
//			for (int x = 0; x < probabilities.size() - 1; x++)
//			{
//				if (probabilities[x] <= p && probabilities[x + 1] >= p)
//				{
//					Adjacent[x][i] += 1;
//					break;
//				}
//			}
//		}
//		degree += 2 * m;
//
//		for (int x = 0; x < graphSize; x++)
//		{
//			for (int y = 0; y < graphSize; y++)
//			{
//				cout << Adjacent[x][y] << " ,";
//			}
//			cout << endl;
//		}
//		cout << endl;
//
//	}
//}


//TODO  
//
//vertex shader import
//fragment shader import
//
//
//
//
//
//
//
//
//
/////////////////////////