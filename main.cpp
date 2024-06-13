#include<iostream>
#include<string>
using namespace std;


class Node{
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    Node (string i, Node* l, Node* r){
    info = i ;
    leftchild = l ;
    rightchild = r;
    };
};
class BinaryTree{
    public:
    Node* ROOT;
    BinaryTree() {
		ROOT = nullptr; //initializing ROOT to null
	}
    void insert(string element){//insert a node in the binary search tree
        Node* newNode = new Node(element, nullptr, nullptr);//Allocate memory for the new node
        newNode->info = element;//assign value to data field of the new node
		newNode->leftchild = nullptr;//make the left child of the new node point to null
		newNode->rightchild = nullptr;//make the right child of the new node point to null

        Node* parent = nullptr;
		Node* currentNode = nullptr;
		search(element, parent, currentNode);

        if (parent == nullptr) {
			ROOT = newNode; // mark the new node as  root
			return; // exit
		}

		if (element < parent->info) {
			parent->leftchild = newNode;
		}
		else if (element > parent->info) {
			parent->rightchild = newNode;
		}
    }
};
void search(string element, Node*& parent, Node*& currentNode) {
		currentNode = ROOT;
		parent = nullptr;
		while ((currentNode != nullptr) && (currentNode->info != element)) {
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
	}
};
void inorder(Node* ptr) {
    if (ROOT == nullptr)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
};
void preorder(Node* ptr){
    if (ROOT == nullptr) {
			cout << "Tree Is Empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
};
void postorder(Node* ptr){
    
}
int main(){

}