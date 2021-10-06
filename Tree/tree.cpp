#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Written JAlthea (2021/07)
*/

//"Binary Tree"
template <typename T>
struct node {
	T value;
	node *left;
	node *right;
	node *parent;
};

template <typename T>
class binary_tree {
public:
	binary_tree();
	~binary_tree();
	void clear();
	void erase_subtree(node<T> *node);
	int erase_leaf(node<T> *node);
	bool is_leaf(node<T> *node);
	bool insert_root(T value);
	bool insert(node<T> *parent, T value);
	bool insert_left(node<T> *parent, T value);
	bool insert_right(node<T> *parent, T value);
	bool search(T value);	//O(n)
	bool search_node(node<T> *node);	//O(1)
	void print_inorder();
	void print_preorder();
	void print_postorder();
	void print_levelorder();

private:
	node<T> *root;
	unordered_map<node<T>, pair<node<T>, node<T>>> tree_connecting_info;	//for O(1) search
	node<T> *get_node(T value);
	bool search_tree(node<T> *node, T value);
	void inorder(node<T> *node);
	void preorder(node<T> *node);
	void postorder(node<T> *node);
	void levelorder(node<T> *root);
};

template <typename T>
binary_tree<T>::binary_tree() {
	this.root = NULL;
}

template <typename T>
binary_tree<T>::~binary_tree() {
	clear();
}

template <typename T>
void binary_tree<T>::clear() {
	erase_subtree(this->root);
	this->root = NULL;
}

template <typename T>
void binary_tree<T>::erase_subtree(node<T> *node) {
	if (node == NULL) return;
	erase_subtree(node->left);
	erase_subtree(node->right);
	if (node->parent->left == node) node->parent->left = NULL;
	else if (node->parent->right == node) node->parent->right = NULL;
	delete node;
}

template <typename T>
int binary_tree<T>::erase_leaf(node<T> *node) {
	if (node == NULL) return -1;

	if (is_leaf(node)) {
		if (node->parent != NULL) {
			if (node->parent->left == node) node->parent->left = NULL;
			else if (node->parent->right == node) node->parent->right = NULL;
		}

		delete node;
		return 1;
	}

	return 0;
}

template <typename T>
bool binary_tree<T>::is_leaf(node<T> *node) {
	if (node == NULL) return false;
	if (node->left == NULL && node->right == NULL) return true;
	return false;
}

template <typename T>
bool binary_tree<T>::insert_root(T value) {
	if (root != NULL) return false;
	root = get_node(value);
	return true;
}

template <typename T>
bool binary_tree<T>::insert(node<T> *parent, T value) {
	if (!search_node(parent)) return false;
	if (parent->left && parent->right) return false;

	node<T> *new_node = get_node(value);
	pair<node<T>, node<T>> p = tree_connecting_info[*parent];
	if (parent->left == NULL) {
		parent->left = new_node;
		p.first = *new_node;
	}
	else if (parent->right == NULL) {
		parent->right = new_node;
		p.second = *new_node;
	}

	new_node->parent = parent;
	return true;
}

template <typename T>
bool binary_tree<T>::insert_left(node<T> *parent, T value) {
	if (!search_node(parent)) return false;
	if (parent->left) return false;

	node<T> *new_node = get_node(value);
	pair<node<T>, node<T>> p = tree_connecting_info[*parent];
	parent->left = new_node;
	p.first = *new_node;

	new_node->parent = parent;
	return true;
}

template <typename T>
bool binary_tree<T>::insert_right(node<T> *parent, T value) {
	if (!search_node(parent)) return false;
	if (parent->right) return false;

	node<T> *new_node = get_node(value);
	pair<node<T>, node<T>> p = tree_connecting_info[*parent];
	parent->right = new_node;
	p.second = *new_node;

	new_node->parent = parent;
	return true;
}

template <typename T>
bool binary_tree<T>::search(T value) {
	return search_tree(this->root, value) ? true : false;
}

template <typename T>
bool binary_tree<T>::search_node(node<T> *node) {
	return tree_connecting_info.find(node) == tree_connecting_info.end() ? false : true;
}

template <typename T>
void binary_tree<T>::print_inorder() {
	inorder(this.root);
	cout << '\n';
}

template <typename T>
void binary_tree<T>::print_preorder() {
	preorder(this.root);
	cout << '\n';
}

template <typename T>
void binary_tree<T>::print_postorder() {
	postorder(this.root);
	cout << '\n';
}

template <typename T>
void binary_tree<T>::print_levelorder() {
	levelorder(this.root);
	cout << '\n';
}

template <typename T>
node<T> *binary_tree<T>::get_node(T value) {
	node<T> *new_node = new node<T>;
	new_node->value = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

template <typename T>
bool binary_tree<T>::search_tree(node<T> *node, T value) {
	if (node == NULL) return false;
	if (node->value == value) return true;
	bool b_left = search_tree(node->left, value);
	bool b_right = search_tree(node->right, value);
	return b_left || b_right ? true : false;
}

template <typename T>
void binary_tree<T>::inorder(node<T> *node) {
	if (node == NULL) return;
	inorder(node->left);
	cout << node->value << ' ';
	inorder(node->right);
}

template <typename T>
void binary_tree<T>::preorder(node<T> *node) {
	if (node == NULL) return;
	cout << node->value << ' ';
	preorder(node->left);
	preorder(node->right);
}

template <typename T>
void binary_tree<T>::postorder(node<T> *node) {
	if (node == NULL) return;
	postorder(node->left);
	postorder(node->right);
	cout << node->value << ' ';
}

template <typename T>
void binary_tree<T>::levelorder(node<T> *root) {
	queue<node<T>*> q;
	q.push(root);
	while (!q.empty()) {
		node<T> *now = q.front(); q.pop();
		cout << now->value << ' ';
		if (now->left) q.push(now->left);
		if (now->right) q.push(now->right);
	}
}
