#pragma once
#include <iostream>
#include<vector>

using namespace std;

class Graph_Library
{
private:
	int numVertices;

	vector<vector<int>> adjMatrix;

public:
	
	///----------Most important functions-----------
	
	///Initializing the numVertices member and create the 2D vector.
	///This will represent the matrix.
	Graph_Library(int amountOfVertices) 
	{
		///Creating the structs which stores the input integer in "this" object.
		this->numVertices = amountOfVertices;    

		///Creating the 2D matrix with foor loop.
		///The vector pushes ads or "pushes" the vector row to create a 2D array with the same amount of size.
		/// push numVertices in row x | push numVertices in row y
		for (int i = 0; i < amountOfVertices; i++)   
		{
			vector<int> row(numVertices, 0); 
			adjMatrix.push_back(row); 
		}
	}
	
	///Adding an vertex
	void addVertex(int insertAmountOfNewVertex)
	{
		///Updating the numvertices value.
		this->numVertices = numVertices + insertAmountOfNewVertex;  

		///If value is a positive number.
		if (insertAmountOfNewVertex > -1) 
		{
			///Adding rows while the size is smaller tha the amount of numvertices.
			while (adjMatrix.size() < numVertices) 
			{
				///Creating a vector to be pushed in column or vectro y.
				vector<int> row(numVertices, 0);
				adjMatrix.push_back(row);
			}

			///Iterating if the column vector size is smaller than the column size;
			for (int i{}; i < adjMatrix.size(); i++)
			{
				///If criteria is met then push back zeros for row if size is smaller.
				while (adjMatrix[i].size() < numVertices) 
				{
					adjMatrix[i].push_back(0);
				}
			}
		}
		return printMatrix();
	}

	///Adding an edge between two vertices. This is done by changing the entry to 1.
	void addEdge(int ID, int dest)
	{
		if (ID < numVertices && dest < numVertices)  
		{
			cout << "Add edge bewteen " << ID << " and " << dest << endl;
			adjMatrix[ID][dest] = 1;
			return;
		}
		
		if(ID == numVertices && dest == numVertices)
		{
			cout << "Already has edge " << ID << " and " << dest << endl;  
			return;
		}

		if(ID > numVertices || dest > numVertices)
		{
			cout << "Both or one vector out of bounds " << ID << " and " << dest << endl; 
			return;
		}
		
	}

	///Adding an edge between two vertices. This is done by changing the entry to 1.
	void addRandomEdge()
	{
		int randomNumber = rand() % numVertices;
		int randomNumber2 = rand() % numVertices; 

		cout << "Add edge bewteen " << randomNumber << " and " << randomNumber2 << endl;  
		adjMatrix[randomNumber][randomNumber2] = 1; 
	}

	///Deleteing the edge between to vertices.
	void deleteEdge(int ID, int dest)
	{
		///Simply changing the edge from a 1 to a 0. These values aru used as a "yes" or "no" for bool functions that checks if two nodes are connected.
		cout << "Edge bewteen " << ID << " and " << dest << " is deleted" << endl;
		adjMatrix[ID][dest] = 0; 
	}

	///Deleting a vertex
	void deletVertex(int amountOfVertexToDelete)
	{
		///Updating numvVertices.
		this->numVertices = numVertices - amountOfVertexToDelete; 

		///CReating a variable which is the original amount.
		int oldAmount = numVertices + amountOfVertexToDelete;

		///Checks if the new vertex amount is not a negative number and 
		if (numVertices > -1)  
		{  
			///Iterating while column size is greater than the new amount of vertices.
			while (adjMatrix.size() > numVertices) 
			{
				///Erasing all elements in the column if the size is bigger than the new amount.
				adjMatrix.erase(adjMatrix.begin()); 
			}

			///Iterating over all colums less than new amount of vertices
			for (int i{}; i < numVertices; i++)
			{ 
				///Iterating while the row size is bigger tan new amount of vertices
				while (adjMatrix[i].size() > numVertices)
				{
					///Deleting all elments in row that filfill this criteria.
					adjMatrix[i].erase(adjMatrix[i].begin());
				}
			}
			return printMatrix(); 
		}
		else
		{
			cout << "The vertix does not exist or is a negative number" << endl;
		}
	}

	///If the corresponding entry is 1 then the vertices are directly connected.
	bool singleAreConnected(int ID, int dest)
	{
		///Checks if an edge exist bewteen two "nodes". If yes then return a message confirming its existance, else notify that its not there.
		if (adjMatrix[ID][dest] == 1)  
		{
			cout << ID << " Is connected to " << dest << endl; 
			return true; 
		}
		else
		{
			cout << ID << " Is not connected to " << dest << endl;
			return false;
		}
	}

	///If the corresponding entry is 1 then the vertices are directly connected.
	bool allAreConnected(int fromNode, bool isConnected = false)  
	{
		if (fromNode > -1)
		{
			///Iterating over whole 2d matrix and check s if an edge exist. If yes the returns a confimation, else a message notifying that an edge is not found.
			for (int i = fromNode; i < numVertices; i++) 
			{
				for (int j = 0; j < numVertices; j++) 
				{
					if (adjMatrix[i][j] == 1) 
					{
						cout << i << " Is connected to " << j << " "; 
						isConnected = true; 
					}
					else
					{
						cout << i << " Is not connected to " << j << " "; 
						isConnected = false; 
					}
					cout << endl; 
				}
				cout << endl; 
			}
			return true;
		}
		
	}

	///Prints the matrix consisting of edges 0 and 1. 0 = is not connected, 1 is connected.
	void printMatrix()
	{
		///Prints the matrix and disaplays whhich nodes that are connected and not.
		for (int i = 0; i < adjMatrix.size(); i++)
		{
			for (int j = 0; j < adjMatrix[i].size(); j++) 
			{
				cout << adjMatrix[i][j] << " "; 
			}
			cout << endl;
		}
	}

	///----------Other functions-----------

	///The function checks all vertices of the specified y->array and selectd a start node. If the x-array has any edges, then the function print those vertices.
	void breadthFirstSearch(int fromNode) 
	{
		///Creating a vector which stores bools with the size of adj-matix.
		vector<bool> visited(adjMatrix.size(), false);

		///Creating a queue vector to store queue value to store adejcent vertices..
		vector<int> que; 

		///Push back the input integer as the first element in que.
		que.push_back(fromNode); 

		///Set the element in element "fromNode" to true to include it in the print.
		visited[fromNode] = true;

		///Creating an integer which will be index the for loop iterates over.
		int vis;

		///Creating a while loop which iterates if the vector is not empty.
		while(!que.empty())
		{
			///Sets vis to be equal to the element in index zero of que which is "fromNode".
			vis = que[0]; 

			///Printing current vertex.
			cout << vis << " ";

			///Deleting the previous node or "first index" in que vector. This is beacause vis always is equal to que[0]. The element must be swapped.
			///If the element isnt deleted before update it will print the sequence to infinity.
			que.erase(que.begin()); 

			///The function iterates until the maximum vector size is reached.
			for (int i = 0; i < numVertices; i++) 
			{
				///If element vis and i == 1 and not visited, then the que ads i and pushes it back.
				if (adjMatrix[fromNode][i] == 1 && (!visited[i])) 
				{
					///Pushing the adjacent vertex to the que vector.
					que.push_back(i); 

					///Set the element as visited.
					visited[i] = true; 
				}
			}
			cout << endl;
		}
	};

	bool getIsEmpty(int ID)
	{
		for (int i = 0; i < ID; i++) 
		{
			cout << "Element in row:" << i << " ";

			for (int j = 0; j < numVertices; j++)   
			{
				if (adjMatrix[i][j] == 0) 
				{
					cout << "index:" << j << " ";
				}
			}
			cout << " = is empty" << endl; 
		}
		return true;
	}

	void getInformation(int ID, int dest) 
	{
		cout << adjMatrix[ID][dest] << endl; 
		return;
	};

	void getSize(int ID) 
	{
		if (adjMatrix.empty() == false)
		{
		  cout << adjMatrix.size() << endl;
		  return;
		}
			
	};

	int getDepth(int ID) 
	{
		int level = 0;  

		for (ID; ID < adjMatrix.size(); ID++)     
		{
		  level += 1;    
		}
		cout << level << endl;
		return level; 
	};

};

