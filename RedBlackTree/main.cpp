#include <iostream>

struct node;
struct Tree;
void insert(Tree&, int);
void insert(Tree&, int, node*);
node* createNode(int key = 0, node* p = nullptr);


struct node {
	int key = NULL;
	node* left = nullptr;
	node* right = nullptr;
	node* p = nullptr;
	char color = 'r';
}*NIL = createNode();



node* createNode(int key, node* p)
{
	node* n = new node;
	if (p == nullptr) p = NIL;
	n->key = key;
	n->left = NIL;
	n->right = NIL;
	n->p = p;
	n->color = 'n';
	return n;
}


bool isNil(node* a)
{
	if (a->color == 'n') return true;
	else return false;
}

struct Tree {
	node* root = NIL;
	int h;
	int n;
};


void insert(
	Tree& T,
	int key
)
{
	if (isNil(T.root))
	{
		T.root = createNode(key);
		T.root->color = 'b';
		return;
	}
	node* x = T.root;
	insert(T, key, x);
}


void insert(
	Tree& T,
	int key,
	node* x
)
{
	if (x->key > key && isNil(x->left))
	{
		//insert to the left of x
		x->left = createNode(key, x);
		x->left->color = 'r';
		++T.n;
	}
	else if (x->key <= key && isNil(x->right))
	{
		//insert to the right of x
		x->right = createNode(key, x);
		x->right->color = 'r';
		++T.n;
	}
	else
	{
		if (x->key > key) x = x->left;
		else x = x->right;
		insert(T, key, x);
	}

}


int main()
{
	Tree TheTree;





	std::cout << '\n';
	return 0;
}