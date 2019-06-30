#pragma once
#include <iostream>
#include<vector>
#include<string>
using namespace std;

//#define Item int
//typedef int Item;
class Tree
{
private:
	struct Node
	{
		vector<string>Receipts;
		string Car_number;
		Node *left;
		Node *right;

		Node(string Car_number,string data, Node* left = nullptr, Node* right = nullptr)
			: left(left), right(right)
		{
			this->Car_number = Car_number;
			this->Receipts.push_back(data);
		}
	};

	Node * root;

	void Add(string Car_number, Node*& node, string data = " ")
	{
		if(node!=nullptr)
			Find(Car_number).Receipts.push_back(data);
		Add__(Car_number, node, data);
	}

	void Add__(string Car_number, Node*& node, string data = " ")
	{
		if (node == nullptr)
			node = new Node(Car_number, data);

		else if (data > node->Receipts.back())
			Add(Car_number, node->right, data);
		else
			Add(Car_number, node->left, data);
	}
	void Print(const Node* node) const
	{
		if (node != nullptr)
		{
			PrintLKP(node->left);
			cout << "Car number : " << node->Car_number << endl;
			Print_(node);
			PrintLKP(node->right);
		}
	}
	void PrintLKP(const Node* node) const
	{
		if (node != nullptr)
		{
			PrintLKP(node->left);
			Print_(node);
			PrintLKP(node->right);
		}
	}
	void PrintKLP(const Node* node) const
	{
		if (node != nullptr)
		{
			Print_(node);
			PrintKLP(node->left);
			PrintKLP(node->right);
		}
	}
	void PrintPKL(const Node* node) const
	{
		if (node != nullptr)
		{
			PrintPKL(node->right);
			Print_(node);
			PrintPKL(node->left);
		}
	}
	void PrintKPL(const Node* node) const
	{
		if (node != nullptr)
		{
			Print_(node);
			PrintKPL(node->right);
			PrintKPL(node->left);
		}
	}
	void Print_(const Node* node) const
	{
		for (int i = 0; i < node->Receipts.size(); i++)
		{
			cout << "Receipts : " << node->Receipts[i] << endl;////////////////////////////////////////////////////////////////////////////<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		}
	}
	Node Find(string Car_number_, const Node* node) const
	{
		if (node == nullptr)
			return *node;
		if (node->Car_number == Car_number_)
			return *node;
		else if (Car_number_ > node->Car_number)
			return Find(Car_number_, node->right);
		else
			return Find(Car_number_, node->left);
	}
public:
	Tree()
	{
		root = nullptr;
	}

	void Add(string Car_number,string data)
	{
		Add(Car_number, root, data);
	}
	void PrintLKP() const
	{
		PrintLKP(root);
	}
	void PrintKLP() const
	{
		PrintKLP(root);
	}
	void PrintPKL() const
	{
		PrintPKL(root);
	}
	void PrintKPL() const
	{
		PrintKPL(root);
	}

	void PrintSort(bool desc = false)
	{
		// умова ? вираз1 (true) : вираз2 (false); 
		desc ? PrintPKL() : PrintLKP();
	}

	void Print_by_diapason(const Node* node,const string begin, const string end) const
	{
		if (node != nullptr)
		{
			PrintLKP(node->left);
			if (node->Car_number > begin&&node->Car_number < end)
			{
			cout << "Car number : " << node->Car_number << endl;////////////////////////////////////////////////////////////////////////////<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			Print_(node);
			}
			PrintLKP(node->right);
		}
	}

	Node Find(string number)
	{
		return Find(number, root);
	}
	void Print_by_number(const string number)
	{
		Node* node;
		*node=Find(number);
		cout << "Car number : " << node->Car_number << endl;////////////////////////////////////////////////////////////////////////////<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		Print_(node);
		PrintLKP(node->right);
	}
	//bool FindLine(int data) const
	//{
	//	for (Node * n = root; n != nullptr; /*вираз*/)
	//	{
	//		if (n->data == data) return true;////////////////////////////////////////////////////////////////////////////<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	//		else if (data > n->data)////////////////////////////////////////////////////////////////////////////<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	//			n = n->right;
	//		else
	//			n = n->left;
	//	}
	//	return false;
	//}
};