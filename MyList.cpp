#include "MyList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

typedef Node* TList;

void init(TList& head)
{
	head = NULL;
}

bool isEmpty(TList head)
{
	return head == NULL;
}

void addToHead(TList& head, int elem)
{
	TList p = new Node;
	p->data = elem;
	p->next = head;
	head = p;
}

void addAfterNode(TList pNode, int elem)
{
	TList p = new Node;
	p->data = elem;
	p->next = pNode->next;
	pNode->next = p;
}

void deleteFromHead(TList& head)
{
	TList p = head;
	head = head->next;
	p->next = 0;
	delete p;
}

void deleteAfterNode(TList pNode)
{
	if (pNode != 0)
	{
		TList p = pNode->next;
		pNode->next = p->next;
		p->next = 0;
		delete p;
	}
}

void clear(TList& head)
{
	while (!isEmpty(head))
		deleteFromHead(head);
	delete head;
}

void printList(TList head)
{
	TList p = head;
	while (p != NULL)
	{
		cout << p->data << endl;
		p = p->next;
	}
}

void print(TList head)
{
	if (head == 0)
		cout << endl;
	else
	{
		cout << head->data;
		print(head->next);
	}
}

void createFromHead(TList& head)
{
	init(head);
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int elem;
		cout << endl << "Введите элемент: ";
		cin >> elem;
		addToHead(head, elem);
	}
}

void createFromTail(TList& head)
{
	init(head);
	TList tail = head;
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int elem;
		cout << endl << "Введите элемент: ";
		cin >> elem;
		if (isEmpty(head))
		{
			addToHead(head, elem);
			tail = head;
		}
		else
		{
			addAfterNode(tail, elem);
			tail = tail->next;
		}
	}
}

bool fromFileToList(TList& head) {
	ifstream inf("List.txt");
	if (!inf.is_open()) {
		cout << "Не удалось считать файл";
		return 0;
	}
	init(head);
	TList tail = head;
	int temp;
	while (inf >> temp) {
		if (isEmpty(head))
		{
			addToHead(head, temp);
			tail = head;
		}
		else
		{
			addAfterNode(tail, temp);
			tail = tail->next;
		}
	}
}


void L1L2(TList& L,TList& L1,TList& L2) {  //Принимаем на вход список с данными и 2 пустых(в которые будем добавлять элты в зависимости от знака
	TList pNode = L; int temp; TList tail1 = L1; TList tail2 = L2; //Создаем вспомагательный указатель(pNode), переменную в которой будем времмено хранить значение и указатели на хвост списков L1, L2
	init(L1); init(L2);
	while (pNode != NULL) { //Проходимся по списку
		temp = pNode->data; //Значение элемента записываем в переменную
		if (temp > 0) { //В зависимости от знака добавляем этот элемент в нужный список, по тому же принципу что и в createFromTail
			if (isEmpty(L1))
			{
				addToHead(L1, temp);
				tail1 = L1;
			}
			else
			{
				addAfterNode(tail1, temp);
				tail1 = tail1->next;
			}
		}
		else if (temp < 0) {
			if (isEmpty(L2))
			{
				addToHead(L2, temp);
				tail2 = L2;
			}
			else
			{
				addAfterNode(tail2, temp);
				tail2 = tail2->next;
			}
		}
		pNode = pNode->next; //Переходим на следующий элемент
	}
}