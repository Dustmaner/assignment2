#include "searchTree.h"



searchTree::searchTree()
{
	root = NULL;
	nodeCount = 0;
}

searchTree::~searchTree()
{
	deleteTree(root);
}


void searchTree::insert(string insertWord)
{
	bool isTaller = false;

	Node* newNode = new Node();

	insertWord = caseConvert(insertWord);

	newNode->balanceFactor = 0;
	newNode->word = insertWord;
	newNode->leftNode = NULL;
	newNode->rightNode = NULL;


	insertNode(root, newNode, isTaller);
}

void searchTree::insertNode(Node* &root, Node* newNode, bool &isTaller) //inserts a node into the tree
{
	if(root == NULL)
	{
		root = newNode;
		isTaller = true;

		nodeCount++;
//		cout << "New word added: " << root->word << endl;
	}
	else if (root->word == newNode->word)
	{
//		cerr << "Sorry, \"" << newNode->word << "\" has already been added" << endl;
	}
	else if (root->word > newNode->word) //new item goes into left subtree
	{
		insertNode(root->leftNode, newNode, isTaller);

		if(isTaller)
			switch (root->balanceFactor)
			{
			case -1:
				balanceFromLeft(root);
				isTaller = false;
				break;

			case 0:
				root->balanceFactor = -1;
				isTaller = true;
				break;

			case 1:
				root->balanceFactor = 0;
				isTaller = false;
			}//end switch
	}//end if
    else
	{
		insertNode(root->rightNode, newNode, isTaller);

		if (isTaller)
			switch (root->balanceFactor)
			{
			case -1:
				root->balanceFactor = 0;
				isTaller = false;
				break;

			case 0:
				root->balanceFactor = 1;
				isTaller = true;
				break;

			case 1:
				balanceFromRight(root);
				isTaller = false;
			}
	}
}

string searchTree::caseConvert(string word)
{
	string temp = word;
	transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
	return temp;
}

Node* searchTree::getRoot() //returns the root node of the binary tree
{
	return root;
}

void searchTree::rotateLeft(Node* &root)
{
	Node *point; 	//pointer to the root of right subtree

	if(root == NULL)
	{
		cerr << "No root node" << endl;
	}
	else if (root->rightNode == NULL)
	{
		cerr << "Error in the tree: "
		<< "No right subtree to rotate." << endl;
	}
	else
	{
		point = root->rightNode;
		root->rightNode = point->leftNode; //left node of point becomes
											// the right node of root
		point->leftNode = root;
		root = point;		//make pointer the new root node
	}
}

void searchTree::rotateRight(Node* &root)
{
	Node *point;

	if(root == NULL)
	{
		cerr << "Error in the tree" << endl;
	}
	else if (root->leftNode == NULL)
	{
		cerr << "Error in the tree: " << "No left subtree to rotate." << endl;
	}
	else
	{
		point = root->leftNode;
		root->leftNode = point->rightNode;	//right ndoe of point becomes
												//the left node of root
		point->rightNode = root;
		root = point;		//make point the new root node
	}
}

void searchTree::balanceFromLeft(Node* &root)
{
	Node *p;
	Node *w;

	p = root->leftNode; //p points to left subtree of root

	switch (p->balanceFactor)
	{
	case -1:
		root->balanceFactor = 0;
		p->balanceFactor = 0;
		rotateRight(root);
		break;

	case 0:
		cerr << "Error: Cannot balance from the left." << endl;
		break;

	case 1:
		w = p->rightNode;
		switch (w->balanceFactor) 	//adjust balanceFactor
		{
			case -1:
				root->balanceFactor = 1;
				p->balanceFactor = 0;
				break;
			case 0:
				root->balanceFactor = 0;
				p->balanceFactor = 0;
				break;
			case 1:
				root->balanceFactor = 0;
				p->balanceFactor = -1;
				break;
		}//end switch

		w->balanceFactor = 0;
		rotateLeft(p);
		root->leftNode = p;
		rotateRight(root);
	}//end switch
}

void searchTree::balanceFromRight(Node* &root)
{
	Node *p;
	Node *w;

	p = root->rightNode; //p points to left subtree of root

	switch (p->balanceFactor)
	{
	case -1:
		w = p->leftNode;
		switch (w->balanceFactor) 	//adjust balanceFactor
		{
		case -1:
			root->balanceFactor = 0;
			p->balanceFactor = 1;
			break;
		case 0:
			root->balanceFactor = 0;
			p->balanceFactor = 0;
			break;
		case 1:
			root->balanceFactor = -1;
			p->balanceFactor = 0;
		}

		w->balanceFactor = 0;
		rotateRight(p);
		root->rightNode = p;
		rotateLeft(root);
		break;

	case 0:
		cerr << "Error: Cannot balance from the left." << endl;
		break;

	case 1:
		root->balanceFactor = 0;
		p->balanceFactor = 0;
		rotateLeft(root);
	}//end switch
}

int searchTree::maxDepth(Node* checkNode)
{
	if(checkNode == NULL)
    {
			return 0;
    }
    else
    {
        return 1 + max(maxDepth(checkNode->leftNode), maxDepth(checkNode->rightNode));
    }
}

void searchTree::printTree(Node* searchTree) //Prints words in alphabetical order
{
	if(searchTree != NULL)
    {
        printTree(searchTree->leftNode);
        cout << searchTree->word << endl;
        printTree(searchTree->rightNode);
    }
}
void searchTree::deleteTree(Node *delNode)
{
    if(delNode)
    {
        deleteTree(delNode->leftNode);
        deleteTree(delNode->rightNode);
        delete delNode;
    }
}

void searchTree::report()
{
	cout << "\n\n*******Report******* " << endl;
	cout << "There are " << nodeCount << " words in the dictionary" << endl;
	cout << "The maximum depth of the tree is "<< maxDepth(this->getRoot())<< " nodes." << endl;
}

void searchTree::findWord(string word)
{
    Node* currNode = this->getRoot();

    do
    {
      if(currNode->word == word)
        {
            cout << "The word " << word << " was found in the dictionary";
        }
        else
        {
            currNode = currNode->leftNode;
        }
    }
    while
    (currNode != NULL);
}
//
//void searchTree::inOrder(string& buffer)
//{
//    Node* node = this->getRoot();
//
//    inOrder(buffer, node->leftNode);
//    buffer += node->word + '\n';
//    inOrder(buffer, node->rightNode);
//}
//
//void searchTree::inOrder(string& buffer, Node* node)
//{
//    if (node == NULL)
//        return;
//
//    inOrder(buffer, node->leftNode);
//    buffer += node->word + '\n';
//    inOrder(buffer, node->rightNode);
//}
