#include "Main.h"
#include <iostream>
#include<vector>
#include "Graph_Library.h"
#include "Tree_Library.h"

using namespace std;

int main()
{
	///----------------Trees------------------------
	Tree_Library root;
	cout << "Manually typed in" << endl;
	cout << "" << endl;

	///Level zero
	///   -1

	///First level
	///    -1
	///   /  \
	///  1    2 
	root.Tree.front()->ChildNode.push_back(root.CreateNode(1, root.Tree.front())); 
	root.Tree.front()->ChildNode.push_back(root.CreateNode(2, root.Tree.front())); 
	 
    ///Second level
	///       -1
	///      /  \
	///     1    2 
    ///   /   \
	///  3     4
	root.Tree.front()->ChildNode[0]->ChildNode.push_back(root.CreateNode(3, root.Tree.front()->ChildNode[0])); 
	root.Tree.front()->ChildNode[0]->ChildNode.push_back(root.CreateNode(4, root.Tree.front()->ChildNode[0])); 

	///Third level
	///          -1
	///         /  \
	///        1    2 
	///      /   \ 
	///    3       4
    ///  / | \    / \
	/// 5  6  7  8   9
	root.Tree.front()->ChildNode[0]->ChildNode[0]->ChildNode.push_back(root.CreateNode(5, root.Tree.front()->ChildNode[0]->ChildNode[0]));
	root.Tree.front()->ChildNode[0]->ChildNode[0]->ChildNode.push_back(root.CreateNode(6, root.Tree.front()->ChildNode[0]->ChildNode[0]));
	root.Tree.front()->ChildNode[0]->ChildNode[0]->ChildNode.push_back(root.CreateNode(7, root.Tree.front()->ChildNode[0]->ChildNode[0]));

	root.Tree.front()->ChildNode[0]->ChildNode[1]->ChildNode.push_back(root.CreateNode(8, root.Tree.front()->ChildNode[0]->ChildNode[1])); 
	root.Tree.front()->ChildNode[0]->ChildNode[1]->ChildNode.push_back(root.CreateNode(9, root.Tree.front()->ChildNode[0]->ChildNode[1]));  

	///Fourth level
    ///          -1
    ///         /  \
	///        1    2 
	///      /   \ 
	///    3       4
	///  / | \    / \
	/// 5  6  7  8   9 
    ///               \
	///               10
	root.Tree.front()->ChildNode[0]->ChildNode[1]->ChildNode[1]->ChildNode.push_back(root.CreateNode(10, root.Tree.front()->ChildNode[0]->ChildNode[1]->ChildNode[1])); 

	cout << "InsertNode" << endl; 
	root.InsertNode(root.Tree.front(), 11); 
	root.InsertNode(root.Tree.front(), 12);
	cout << " " << endl; 
	 
	cout << "DeleteNode" << endl;    
	root.DeleteNode(root.Tree.front(),3);  
	cout << " " << endl; 

	cout << "DepthFirstSearchPreorder" << endl; 
	root.DepthFirstSearchPreorder(root.Tree.front());
	cout << " " << endl;

	cout << "DepthFirstSearchPostorder" << endl;
	root.DepthFirstSearchPostorder(root.Tree.front()); 
	cout << " " << endl; 

	cout << "BreadthFirstSearch" << endl;
	root.BreadthFirstSearch(root.Tree.front());
	cout << " " << endl; 

	cout << "GetSizeForCurrentNode" << endl;
	root.GetSizeForCurrentNode(root.Tree.front());
	cout << " " << endl; 

	cout << "GetSize" << endl;
	cout << root.GetSize(root.Tree.front()) <<endl;  
	cout << " " << endl;

	cout << "GetParent" << endl; 
	root.GetParent(root.Tree.front()->ChildNode[1]); 
	cout << " " << endl;

	cout << "GetParents" << endl; 
	root.GetParents(root.Tree.front(),2); 
	cout << " " << endl; 

	cout << "GetChild" << endl; 
	root.GetChild(root.Tree.front(),4); 
	cout << " " << endl; 

	cout << "GetChildren" << endl; 
	root.GetChildren(root.Tree.front(),4);  
	cout << " " << endl; 

	cout << "GetRoot" << endl; 
	root.GetRoot(root.Tree.front(),8);  
	cout << " " << endl; 

	cout << "GetDepth" << endl;
	cout << root.GetDepth(root.Tree.front()) << endl;
	cout << " " << endl;  

	cout << "GetisEmpty" << endl;  
	root.GetisEmpty(root.Tree.front()); 
	cout << " " << endl;    

	cout << "GetisLeaf" << endl; 
	cout << root.root << endl; 
	root.GetisLeaf(root.Tree.front()); 
	cout << " " << endl; 

	cout << "AddToTree" << endl;
	root.AddToTree(); 
	cout << " " << endl; 

	cout << "CreateRandomTree" << endl; 
	cout << root.root << endl; 
	root.CreateRandomTree(root.Tree[1], 5, 0); 
	cout << " " << endl; 

	cout << "BreadthFirstSearch" << endl;
	root.BreadthFirstSearch(root.Tree[1]); 
	cout << " " << endl;  
	
	cout << " " << endl;
	cout << "----------------Graphs-------------------" << endl;
	cout << " " << endl;

	Graph_Library g(4);    

	cout << "Create graph" << endl; 
	g.printMatrix();  
	cout << " " << endl;  
	 
	cout << "Add Edge Between" << endl;
	g.addEdge(0, 1); 
	cout << " " << endl;
	g.addEdge(0, 5);  
	cout << " " << endl;
	g.addEdge(3, 2);  
	cout << " " << endl;
	g.addEdge(2, 3);  
	cout << " " << endl;
	g.addEdge(3, 4);  
	cout << " " << endl;

	cout << "Graph after vertices added" << endl;
	g.addVertex(2);  
	cout << " " << endl; 

	cout << "Create graph" << endl;
	cout << "1 = Has edge | 0 = Does not have edge" << endl;
	g.printMatrix();  
	cout << " " << endl;  

	cout << "Delete edge" << endl; 
	g.deleteEdge(2, 3);  
	cout << " " << endl; 

	cout << "Graph after vertices are deleted" << endl;
	g.deletVertex(1);
	cout << " " << endl; 

	cout << "Create graph after deletion" << endl;
	cout << "1 = Has edge | 0 = Does not have edge" << endl; 
	g.printMatrix(); 
	cout << " " << endl; 

	cout << "Are the vertices directly connected?" << endl;
	g.singleAreConnected(3, 2);    
	g.singleAreConnected(0, 3);       
	cout << " " << endl; 

	cout << "What vertices are directly connected?" << endl; 
	g.allAreConnected(0);  
	cout << " " << endl; 

	cout << "Breadth First Search" << endl;
	g.breadthFirstSearch(3);  
	cout << " " << endl; 

	cout << "GetSize" << endl;
	g.getSize(1);
	cout << " " << endl;  

	cout << "getIsEmpty" << endl; 
	g.getIsEmpty(3);  
	cout << " " << endl; 

	cout << "getinformation" << endl;
	g.getInformation(0,1);
	cout << " " << endl;


	cout << "GetDepth" << endl; 
	g.getDepth(0);
	cout << " " << endl; 

	cout << " " << endl;
	cout << "----------------Graphs Random-------------------" << endl;
	cout << " " << endl;

	Graph_Library gr(rand() % 10 + 5);  

	cout << "Add Edge Between" << endl; 

	gr.addRandomEdge();  
	cout << " " << endl; 
	gr.addRandomEdge();
	cout << " " << endl;
	gr.addRandomEdge();
	cout << " " << endl;
	gr.addRandomEdge();
	cout << " " << endl;

	cout << "Create random graph" << endl; 
	cout << "1 = Has edge | 0 = Does not have edge" << endl; 
	gr.printMatrix(); 
	cout << " " << endl;  

	cout << "What vertices are directly connected?" << endl; 
	gr.allAreConnected(0); 
	cout << " " << endl; 

	cout << "Breadth First Search" << endl; 
	gr.breadthFirstSearch(0); 
	cout << " " << endl; 

	cout << "GetSize" << endl; 
	gr.getSize(1);  
	cout << " " << endl; 

	cout << "getIsEmpty" << endl; 
	gr.getIsEmpty(3);  
	cout << " " << endl; 

	cout << "getinformation" << endl; 
	gr.getInformation(0, 1);  
	cout << " " << endl; 

	cout << "GetDepth" << endl; 
	gr.getDepth(0);  
	cout << " " << endl; 
}

