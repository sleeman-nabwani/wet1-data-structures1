#ifndef AVL_TREE_
#define AVL_TREE_

#include <iostream>

using namespace std;
template <class T>
class AVLTree
{
public:

    class Node
    {
    public:
        T* data;
        int height;
        Node* Left;
        Node* Right;

        explicit Node(const T& data) : data(new T(data)) ,height(1), Left(nullptr), Right(nullptr) {

        }
        Node(const Node& n)
        {
            data = new T(*(n.data));
            height = n.height;
            if (n.Left) {
                Left = new Node(*(n.Left));
            }
            else {
                Left = nullptr;
            }
            if (n.Right) {
                Right = new Node(*(n.Right));
            }
            else
                Right = nullptr;
        }
        Node& operator=(const Node& node)
        {
            if (this == &node) {
                return *this;
            }
            data = new T(*(node.data));
            if (node.Left) {
                Left = new Node(*(node.Left));
            }
            else {
                Left = nullptr;
            }
            if (node.Right) {
                Right = new Node(*(node.Right));
            }
            else {
                Right = nullptr;
            }
            return *this;
        }
        ~Node()
        {
            delete data;
        }
    };
    Node* root;
    int NodeCount;
    Node* getMax(){
        while(root && root->Right)
            root = root->Right;
        return root;
    }
    void insert(T x)
    {
        root = insertUtil(root, x);
    }
    void remove(T x)
    {
        root = removeUtil(root, x);
    }
    Node* search(T x)
    {
        return searchUtil(root, x);
    }
    void inorder(T* arr)
    {
        int i = 0;
        inorderUtil(root,arr,i);
    }
    AVLTree() :root(nullptr),NodeCount(0) {}
    AVLTree(const AVLTree& Tree)
    {
        root = CopyTree(Tree.root);
        NodeCount = Tree.NodeCount;
    }
    AVLTree<T>& operator=(const AVLTree<T>& tree)
    {
        if (this == &tree) {
            return *this;
        }
        DeleteTree(root);
        root = CopyTree(tree.root);
        NodeCount=tree.NodeCount;
        return *this;
    }
    ~AVLTree()
    {
        DeleteTree(this->root);
    }
    void printTree(Node* nodeRoot, int space = 0)
    {
        // Base case
        if (nodeRoot == nullptr)
            return;

        // Increase distance between levels
        space += 10;

        // Process right child first
        printTree(nodeRoot->Right, space);

        // Print current node after space
        // count
        cout << endl;
        for (int i = 10; i < space; i++)
            cout << " ";
        cout << *(nodeRoot->data) << "\n";

        // Process left child
        printTree(nodeRoot->Left, space);
    }
private:
    Node* CopyTree(Node* nodeRoot)
    {
        if (nodeRoot)
        {
            Node* newRoot = new Node(*nodeRoot->data);
            if(nodeRoot->Left)
                newRoot->Left = new Node(*nodeRoot->Left);
            if(nodeRoot->Right)
                newRoot->Right = new Node(*nodeRoot->Right);
            return newRoot;
        }
        else
            return nullptr;
    }
    void DeleteTree(Node* nodeRoot)
    {
        if (nodeRoot == nullptr)
            return;
        else
        {
            DeleteTree(nodeRoot->Left);
            DeleteTree(nodeRoot->Right);
            delete nodeRoot;
        }
    }

    int height(Node* head) {
        if (head == nullptr)
            return 0;
        return head->height;
    }
    Node* RightRotation(Node* head) {
        Node* newhead = head->Left;
        head->Left = newhead->Right;
        newhead->Right = head;
        head->height = 1 + max(height(head->Left), height(head->Right));
        newhead->height = 1 + max(height(newhead->Left), height(newhead->Right));
        return newhead;
    }

    Node* LeftRotation(Node* head) {
        Node* newhead = head->Right;
        head->Right = newhead->Left;
        newhead->Left = head;
        head->height = 1 + max(height(head->Left), height(head->Right));
        newhead->height = 1 + max(height(newhead->Left), height(newhead->Right));
        return newhead;
    }

    void inorderUtil(Node* head,T* arr,int& i) {
        if (head == nullptr)
            return;
        inorderUtil(head->Left,arr,i);
        arr[i] = *head->data;
        i++;
        inorderUtil(head->Right,arr,i);
    }
    Node* insertUtil(Node* head, T x) {
        if (head == nullptr)
        {
            NodeCount +=1;
            Node* temp = new Node(x);
            return temp;
        }
        if (x < *head->data)
            head->Left = insertUtil(head->Left, x);
        else if (x > *head->data)
            head->Right = insertUtil(head->Right, x);
        head->height = 1 + max(height(head->Left), height(head->Right));
        int bal = height(head->Left) - height(head->Right);
        if (bal > 1) {
            if (x < *head->Left->data) {
                return RightRotation(head);
            }
            else {
                head->Left = LeftRotation(head->Left);
                return RightRotation(head);
            }
        }
        else if (bal < -1) {
            if (x > *head->Right->data) {
                return LeftRotation(head);
            }
            else {
                head->Right = RightRotation(head->Right);
                return LeftRotation(head);
            }
        }
        return head;
    }
    Node* removeUtil(Node* head, T x) {
        if (head == nullptr)
            return nullptr;
        if (x < *head->data)
        {
            head->Left = removeUtil(head->Left, x);
        }
        else if (x > *head->data)
        {
            head->Right = removeUtil(head->Right, x);
        }
        else
        {
            Node* r = head->Right;
            if (head->Right == nullptr) {
                Node* l = head->Left;
                delete(head);
                head = l;
            }
            else if (head->Left == nullptr) {
                delete(head);
                head = r;
            }
            else {
                while (r->Left != nullptr)
                    r = r->Left;
                *head->data = *r->data;
                head->Right = removeUtil(head->Right, *r->data);
            }
        }
        if (head == nullptr)
            return head;
        head->height = 1 + (height(head->Left), height(head->Right));
        int bal = height(head->Left) - height(head->Right);
        if (bal > 1) {
            if (height(head->Left) >= height(head->Right)) {
                return RightRotation(head);
            }
            else {
                head->Left = LeftRotation(head->Left);
                return RightRotation(head);
            }
        }
        else if (bal < -1) {
            if (height(head->Right) >= height(head->Left)) {
                return LeftRotation(head);
            }
            else {
                head->Right = RightRotation(head->Right);
                return LeftRotation(head);
            }
        }
        return head;
    }
    Node* searchUtil(Node* head, T x) {
        if (head == nullptr)
            return nullptr;
        T k = *head->data;
        if (k >x)
            return searchUtil(head->Left, x);
        else if(k < x)
            return searchUtil(head->Right, x);
        else
            return head;
    }
};

//template<class T>
//inline Node<T>::Node(const Node<T>& n)
//{
//	data = new T(*(n.data));
//	if (n.Left) {
//		Left = new Node<T>(*(n.Left));
//	}
//	else {
//		Left = nullptr;
//	}
//	if (n.Right) {
//		Right = new Node<T>(*(n.Right));
//	}
//	else
//		Right = nullptr;
//}

//template<class T>
//inline Node<T>& Node<T>::operator=(const Node<T>&Node)
//{
//	if (this == &Node) {
//		return *this;
//	}
//	data = new T(*(Node.data));
//	if (Node.Left) {
//		Left = new Node<T>(*(Node.Left));
//	}
//	else {
//		Left = nullptr;
//	}
//	if (Node.Right) {
//		Right = new Node<T>(*(Node.Right));
//	}
//	else {
//		Right = nullptr;
//	}
//	return *this;
//}
//
//template<class T>
//inline Node<T>::~Node()
//{
//	delete data;
//}





#endif
