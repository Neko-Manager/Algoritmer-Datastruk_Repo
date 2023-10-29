#pragma once
#include <iostream>
#include<vector>


using namespace std;

class Tree_Library
{


public:
    ///------------Creating the node-----------------
	
	/// Node struct = creating a structure called node. The structure wil contain all the 
	///-neccesary variables for a node. It can contain many different datatypes.
	struct Node
	{
		int information;
		Node* Parent;
		vector<Node*> ChildNode;
	};

	vector<Node*> Tree; 

	const int root = -1;
	
	///------------Constructing class object-----------------

	///Constructin the class object and pushing the new node into the tree vector.
	///This will store my nodes.
	Tree_Library()
	{
	    ///Storing the root node.
		Tree.push_back(CreateNode(root,nullptr));
	}; 


	///------------Calling the struct and creating a method with type "struct"-----------------
	
	///Calling the struct which contains all the base information for "a node". 
	///Then creating a method to make new nodes independent from other nodes.
	Node* CreateNode(const int information, Node* inputParent)
	{
		Node* NewNode = new Node();
		NewNode->information = information;
		NewNode->Parent = inputParent; 
		return NewNode; 
	};

	///------------Creating functions"-----------------
	void AddToTree()
	{
		Tree.push_back(CreateNode(root, nullptr));
	}

	void CreateRandomTree(Node* root, int maxDepth, int currentDepth)
	{
		if (currentDepth >= maxDepth) return;

		int randomInformation = rand() % 5; 

		///Iteratinf as long as i is less than randomnumber.
		for (int i = 0; i < randomInformation; i++)
		{
			///If yes the create a childnode with this random value and set root.
			///The push it into the root as a childnode.
			Node* childNode = CreateNode(randomInformation, root); 
			root->ChildNode.push_back(childNode);  

			///Using recursion and increasing the cuurent depth by one for each iteration.
			CreateRandomTree(childNode, maxDepth, currentDepth + 1); 
		}
		return;

	}
	
	///Will visit all the nodes of a graph. 
	void BreadthFirstSearch(Node* root) 
	{
		///While the current node is not a nullpointer the function will run.
		while (root != nullptr)
		{
			///Creating a temporarely vector to enable the function to run over each row.
			vector<Node*> CurrentNode;
			CurrentNode.push_back(root);

            ///Runs if the tempnode has a value > 0 or "isNotempty"
			while (!CurrentNode.empty())
			{
				///Defining the size of the tempNode as an auto generated value.
				auto s = CurrentNode.size();

				///Runs if the size is greater than 0.
				while (s > 0)
				{
					///Creating a variable which will be used to restore the tempnode while it is deleted.
					///Since element 0 for tempnode always is the first index value, it will create new childnodes based on these.
					Node* tempNode = CurrentNode[0];  

					///Deleting the first element in the tepmnode, or the "only accessible node".
					CurrentNode.erase(CurrentNode.begin()); 
					 
					///Printing the retsored information.
					cout << tempNode->information << endl;  

					///Creating a for loop which alowes me to iterate over each
					for (auto k = tempNode->ChildNode.begin(); k != tempNode->ChildNode.end(); k++)  
					{
						CurrentNode.push_back(*k);
					}

					///The Node size decreases each iteration to progress to next level.
					s--; 
				}
			}
		 return;
		}
	};

	///DFS Preorder (Root-->Left-->Right)
	void DepthFirstSearchPreorder(Node* root) 
	{	
		///Printing the current node.
		cout << root->information << endl;

		///i = first index of the current nodes` children.
		auto i = root->ChildNode.begin(); 

		///While the current node is not a nullpointer the function will run.
        while (root != nullptr)
		{
			///If the next node is not the last node for the current level, the function use recursion and goes one level deeper. 
			if (i != root->ChildNode.end())  
			{
				///Recursion for the current node. Progresses to next level if criteria is met.
				DepthFirstSearchPreorder(*i);

				///moving the i with the level increase.
				i++;

				///Example;
				///         -1
	            ///        /  \
	            ///       1    2   
	            ///     /   \
	            ///    3     4
                ///  / | \
	            /// 5  6  7 
                /// 
                /// root = 1, i = [3,4] since i is the vector array of (Node* root)`s childnodes
				/// DepthFirsrtSearchPreorder(*i) = DepthFirsrtSearchPreorder(i = [3])
				/// i++ is then [5]
			}

			///If current node`s childnode is does not have any new child node, the i++ will fail an return the function to the last node.
			///BY doing this the index size is [i-1] and by refering to the example above, the function fails when 5 is the current root, since it does not have any children.
			/// When the function return with 3 as its root, the children will only be i = [6,7].
			else return; 
		}
	};

	///DFS Postorder (Left-->Right-->Root)
	void DepthFirstSearchPostorder(Node* root)
	{
		///i = first index of the current nodes` children.
		auto i = root->ChildNode.begin();  

		///While the current node is not a nullpointer the function will run.
		while(root != nullptr)
		{
			///If the next node is not the last node for the current level, the function use recursion and goes one level deeper. 
			if (i != root->ChildNode.end())  
			{
				///Recursion for the current node. Progresses to next level if criteria is met.
				DepthFirstSearchPostorder(*i);  

				///moving the i with the level increase.
				i++;
			}

			///If current node`s childnode is does not have any new child node, the i++ will fail an return the function to the last node.
			else
			{
				///Printing the Node value if the Node is not a nullpointer and the node fails to keep the recursion going.
				///This will print the postorder variant.
			   cout << root->information << endl; 
			   return;
			}
		}
	};

	///Insertion function
	void InsertNode(Node* root, int data)
	{
		if (root != nullptr)
		{ 
			///Iterating over all children.
			for (Node* child : root->ChildNode)
			{
				InsertNode(child, data);

				///If a child has a child which is not empty and the data is one greater than the current child, then it inserts.
				if (child->ChildNode.empty() == true && data == child->information + 1)
				{
					cout << data << " " << "in childnode:" << "" << child->information << " " << "+ 1" << endl;
					child->ChildNode.push_back(CreateNode(data, root));
				}
				else if (child->ChildNode.empty() == true && data == child->information - 1) 
				{
					cout << data << " " << "in childnode:" << "" << child->information << " " << "- 1" << endl;  
					child->ChildNode.push_back(CreateNode(data,root));  
				}
			}
			return;
		}
	}

	void DeleteNode(Node* root, int deletFromNode)
	{
		if (root->ChildNode.empty() == false)
		{
			for (Node* child : root->ChildNode)
			{
				DeleteNode(child, deletFromNode); 

				if (child->information > deletFromNode)  
				{
					root->ChildNode.erase(root->ChildNode.begin());
				}
				else return;  
			}
		 cout << "Deleted nodes from root:" << deletFromNode << endl;
		}
	}

	///Get functions
	int GetSizeForCurrentNode(Node* root)
	{
		///Nullpointer control
		if (root == nullptr) 
		{
			return 0;
		};

		///Prints out the size of the root node
		auto size = root->ChildNode.size(); 
		cout << size << endl;  
		return size;    
	};

	void GetParent(Node* root)
	{
		if (root == NULL) return;
		cout << root->Parent->information << " = " << "Parent of node = " << root->information << endl;
		return;
	}

	void GetParents(Node* root,int findParentsOf)
	{
		if (root == NULL) return;

		for (Node* child : root->ChildNode)
		{
			GetParents(child, findParentsOf);  
			 
			if (root->information < findParentsOf)    
			{
				cout << root->information << " = " << "Parent of node = " << child->information << endl;    
			}
		}
	     return;
	}

	void GetChild(Node* root, int findChildOf)
	{
		for (Node* child : root->ChildNode) 
		{
			GetChild(child, findChildOf);   
			if (root->information == findChildOf)
			{
				cout << child->information << " = " << "Child of node = " << root->information << endl;
				return;
			}

			///If the child infromation is the node we are looking for but has no children then the function executes.
			if (child->information == findChildOf && child->ChildNode.empty() == true)  
			{
				cout << child->information << ": Has no children" << endl;
				return;
			}
		}
	}

	void GetChildren(Node* root, int findChildrenOf)
	{
		///Iterating over chjildren
		for (Node* child : root->ChildNode) 
		{
			GetChildren(child, findChildrenOf); 

			///Checking if root node has the same information as the int findChildrenOf.
			if (root->information == findChildrenOf)  
			{
				///If yes, then iterate over all the children and print them.
				for (Node* findChildren : root->ChildNode) 
				{
				   GetChildren(findChildren, findChildrenOf); 

				   if (findChildren->information > findChildrenOf)   
				   {
   				      cout << findChildren->information << " = " << "Children of node = " << root->information << endl;
				   }
				}
				return;
			}
			///If the child infromation is the node we are looking for but has no children then the function executes.
			if (child->information == findChildrenOf && child->ChildNode.empty() == true)  
			{
				cout << child->information << ": Has no children" << endl; 
				return;
			}
		}
	}

	bool GetRoot(Node* root, int findRootOf)
	{
		for (Node* child : root->ChildNode)
		{
			GetRoot(child, findRootOf); 

			///Prints the root if the parent of child aka root is not empty.
			if (child->information == findRootOf && child->Parent->ChildNode.empty() == false) 
			{
				cout << child->information << " " << "Is a root" << endl; 
				return true;
			}
			else false;
		}
	}

	int GetSize(Node* root)
	{
		///Nullpointer control
		if (root == nullptr) 
		{
			return 0;
		};

	    ///Declaring size as one to include the first node. 
	    int amountOfNodes = 1; 
		
	    ///For loop which iterates over all childnodes for root node
	    for (Node* child : root->ChildNode) 
	    {
     	    ///amountOfNodes increases if the root node has a childnode, if yes then +1.
	        amountOfNodes += GetSize(child); 
	    }
	     return amountOfNodes; 
	};

	int GetDepth(Node* root) 
	{
		///Nullpointer control
		if (root == nullptr) 
		{ 
			return 0;
		};

		///Deepest or Max level
		int level = 0; 
	   
		///For loop wich iterates over list of children for current root node.
		///Starts with first element in first index.
		for (Node* child : root->ChildNode) 
		{
			///Declaring the currentDepth as an integer
			int currentDepth = GetDepth(child);

			///Compares level to the to the childnodes depth and chooses the gerater one.
			///Example; 
			///root = 3
			///When the loop runs over the last childnode int currentDepth = GetDepth(root->childnode[2])
			///-the function checks the max value before termination. level = max(0,1) and return level = 1 + 1 = 2.
			/// The root then returns to root = 1 and iterates over int currentDepth = GetDepth(root->childnode[1]) which is 4 and does the same process until the maxdepth is reached.
			/// If the depth is deeper it will simply check if the previous childs` depth is smaler than the current one.
			/// Take the same root = 3, but it compares the prevous childs` depth to the new one.
			/// level = max(level = 1,GetDepth(root->ChildNode[1] = 2)).
			/// level = 2 since 2 > 1 and then return 2 + 1 = 3.
			
			level = max(level, currentDepth);   
		}
			return level + 1 ; 
	};

	bool GetisEmpty(Node* root) 
	{
		///Control if Tree size is 0.
		if (Tree.size() == NULL)
		{
			return true;
		}

		///Nullpointer control
		if (root == NULL) 
		{
			return true;
		};

		///Iterating over each childnode.
		for (Node* child : root->ChildNode)  
		{
			///Prints if the nodes childnode  is either empty or not.
			///Then recursively checks next child of current root node.
			if (child->ChildNode.empty() == true) 
			{
				cout << "Childnode of this is empty" << endl;  
				cout << child->information << endl;  
			}
			GetisEmpty(child); 
		}  
		return true;
	};

	bool GetisLeaf(Node* root) 
	{
		///Nullpointer control
		if (root == nullptr) 
		{
			return true;
		};

		///Iterating over each childnode.
		for (Node* child : root->ChildNode) 
		{
			///Prints if the nodes childnode  is either empty or not.
			///Then recursively checks next child of current root node.
			if (child->ChildNode.empty() == true) 
			{
				cout << "This is a leaf node" << endl; 
				cout << child->information << endl; 
			}
			else
			{
				cout << "This is not a leaf node" << endl; 
				cout << child->information << endl; 
			}
			GetisLeaf(child); 
		}
		///Returns the information stored in the node checked to indicate where in the tree the suer is.
		return true; 
	};
};

