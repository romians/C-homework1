#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} Node;

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

void printPreorder(Node* node) {
	if (node == NULL)
		return;

	printf("%d ", node->data);
	printPreorder(node->left);
	printPreorder(node->right);
}

void printInorder(Node* node) {
	if (node == NULL)
		return;

	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}

void printPostorder(Node* node) {
	if (node == NULL)
		return;

	printPostorder(node->left);
	printPostorder(node->right);
	printf("%d ", node->data);
}

#define MAX_SIZE 12 // �迭 ũ��� ��ü ��� ������ �ϳ� ũ�� �����մϴ�.
int Tree[MAX_SIZE];

// ���� ��ȸ �Լ��Դϴ�.
void preOrder(int index) {
	if (index >= MAX_SIZE || Tree[index] == -1) return; // �ε����� ������ ����ų�, ��� ���� -1�� ��� �����մϴ�.
	printf("%d ", Tree[index]);
	preOrder(index * 2); // ���� �ڽ� ��� �湮
	preOrder(index * 2 + 1); // ������ �ڽ� ��� �湮
}

// ���� ��ȸ �Լ��Դϴ�.
void inOrder(int index) {
	if (index >= MAX_SIZE || Tree[index] == -1) return;
	inOrder(index * 2);
	printf("%d ", Tree[index]);
	inOrder(index * 2 + 1);
}

// ���� ��ȸ �Լ��Դϴ�.
void postOrder(int index) {
	if (index >= MAX_SIZE || Tree[index] == -1) return;
	postOrder(index * 2);
	postOrder(index * 2 + 1);
	printf("%d ", Tree[index]);
}


int main() {
	Node* root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(7);

	root->left->left = newNode(3);
	root->left->right = newNode(6);

	root->right->left = newNode(9);

	root->left->left->left = newNode(4);
	root->left->left->right = newNode(5);

	root->right->left->left = newNode(8);

	root->right->left->right = newNode(-1); // Empty node

	root->right->right = newNode(-1); // Empty node

	printf("<Linked Tree>");
		printf("1. ���� ��ȸ");
			printPreorder(root);
	printf("2. ���� ��ȸ");
		printInorder(root);
	printf("3. ���� ��ȸ");
		printPostorder(root);


	// �迭 �ʱ�ȭ
	for (int i = 0; i < MAX_SIZE; i++) {
		Tree[i] = -1;
	}

	// Ʈ���� �� �Ҵ�
	int arr[11] = { 0, 1, 2, 7, 3, 6, -1 ,9 ,4 ,5 ,8 };
	for (int i = 1; i <= 10;i++) {
		Tree[i] = arr[i];
	}

	printf("< Array Tree >");
		printf("1. ���� ��ȸ");
			preOrder(1);
	printf(" 2. ���� ��ȸ ");
		inOrder(1);
	printf(" 3. ���� ��ȸ ");
		postOrder(1);

	return 0;
}
