#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::exception;

// Перечислення пріорітетів арифметичних операцій
enum Priority { PLUS_MINUS, MULT_DIV, MAX_PR };
class Tree_expression
{
	// Опис елемента дерева
	struct Node
	{
		char data;	// дані (символ операції або цифри)
		Node* left, *right;	// вказівники на нащадків
	};

	// Функція визначення пріорітету операції
	Priority GetPriority(char op)
	{
		switch (op)
		{
		case '-': case '+': return PLUS_MINUS;
		case '/': case '*': return MULT_DIV;
			// нам важливо визначити операцію з найменшим пріорітетом,
			// тому, якщо це не арифметична операція, повертаємо максимальний пріорітет
		default: return MAX_PR;
		}
	}

	// Рекурсивна функція створення дерева виразу
	// ex	 - арифметичний вираз
	// first - індекс початку виразу
	// last	 - індекс кінця виразу
	Node* CreateTree(string ex, int first, int last)
	{
		Node* tree = new Node;	// ствоерння нової вершини

		if (first == last)	// якщо це кінцева вершина: значення (операнд)
		{
			// записуємо дані та повертаємо вершину
			tree->data = ex[first];
			tree->left = nullptr;
			tree->right = nullptr;
			return tree;
		}

		// знаходимо операцію з найменшим пріорітетом
		int counter = 0;	// лічильний відкритих дужок
		int k = 0;			// індекс знайденої операції
		int minPr = MAX_PR;	// пріорітет знайденої операції

		for (int i = first; i <= last; ++i)	// цикл пошуку
		{
			if (ex[i] == '(') ++counter;		// відкрита дужка - збільшуємо лічильник
			else if (ex[i] == ')') --counter;	// закрита дужка - зменшуємо лічильник

			// якщо елемент не в дужках, враховуємо його
			if (counter == 0)
			{
				if (GetPriority(ex[i]) <= minPr)	// шукаємо останню операцію 
				{									// з найменшим пріорітетом
					minPr = GetPriority(ex[i]);
					k = i;
				}
			}
		}

		if (minPr == MAX_PR)	// якщо операцію не знайдено, 
		{						// це означає, що весь вираз взято в дужки						
			delete tree;								// звільняємо виділену пам'ять
			return CreateTree(ex, first + 1, last - 1);	// викликаємо ще раз функцію, відкинувши дужки
		}

		tree->data = ex[k];							// внутрішня вершина: операція
		tree->left = CreateTree(ex, first, k - 1);	// будуємо ліве піддерево на основі лівого підвиразу
		tree->right = CreateTree(ex, k + 1, last);	// будуємо праве піддерево на основі правого підвиразу

		return tree;	// повертаємо вершину
	}

	// Обхід дерева: ЛПК
	void PrintLPK(Node* tree)
	{
		if (tree == nullptr) return;

		PrintLPK(tree->left);
		PrintLPK(tree->right);
		cout << tree->data << ' ';
	}
	// Обхід дерева: ЛКП
	void PrintLKP(Node* tree)
	{
		if (tree == nullptr) return;

		PrintLKP(tree->left);
		cout << tree->data << ' ';
		PrintLKP(tree->right);
	}

	// Рекурсивна функція обчислення виразу по дереву
	int CalcTree(Node* tree)
	{
		if (tree->left == nullptr)		// якщо немає нащадків - це значення
			return tree->data - '0';	// повертаємо цифру

		int left = CalcTree(tree->left);	// визначаємо значення лівого нащадка
		int right = CalcTree(tree->right);	// визначаємо значення правого нащадка

		switch (tree->data) // виконуємо операцію з визначеними операндами
		{
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		case '/': return left / right;
			// якщо невірна операція - генеруємо виключну ситуацію
		default: throw exception("Invalid operation");
		}
	}
	bool Validating_expression(string ex)
	{
		for (int i = 0; i < ex.length() - 1; i++)
		{
			if (ex[i] != '+' && ex[i] != '-' && ex[i] != '*' && ex[i] != '/' && isdigit(ex[i]) == false && ex[i] != '(' && ex[i] != ')')
			{
				return false;
			}
		}
		return true;
	}
	public:
		Node* Create_tree(string ex)
		{
			if (Validating_expression(ex) == false)
				throw exception("expression not validating\n");
			return CreateTree(ex, 0, ex.length() - 1);
		}
		int Calculate_ex(Node * p)
		{
			return CalcTree(p); // обчислюємо вираз по дереву
		}
		int Calculate_ex(string ex)
		{
			if (Validating_expression(ex) == false)
				throw exception("expression not validating\n");
			return CalcTree(CreateTree(ex, 0, ex.length() - 1)); // обчислюємо вираз по дереву
		}
};
int main()
{
	Tree_expression obj;
	string ex = "((0-1)+(6-3))*4/2";					// арифметичний вираз
	//Node* tree = CreateTree(ex, 0, ex.length() - 1);	// будуємо дерево виразу

	//cout << "LPK: ";	// прохід дерева: ЛПК
	//PrintLPK(tree);		// дозволяє визначити вираз
	//cout << endl;		// за допомогою стека

	//cout << "LKP: ";	// прохід дерева: ЛКП
	//PrintLKP(tree);		// дозволяє подивитися початковий вигляд виразу 
	//cout << endl;		// проте повністю відновити його не вийде - втрачаються дужки

	try
	{
		cout << "Result: " << obj.Calculate_ex(ex) << endl;
		cout << "Result: " << obj.Calculate_ex(obj.Create_tree(ex)) << endl;
	}
	catch (exception ex) // в разі помилки, обробляємо виключення
	{
		cout << ex.what() << endl;
	}

	system("pause");
	return 0;
}