#pragma once

struct Node;

typedef Node* TList;

void init(TList& head); //инициалиция
bool isEmpty(TList head); //проверка на пустоту 
void addToHead(TList& head, int elem); //добавление в начало
void addAfterNode(TList pNode, int elem); //добавление в середину 
void deleteFromHead(TList& head); //удаление с начала списка 
void deleteAfterNode(TList pNode); //удаление после заданного элемента 
void clear(TList& head); //очистка списка 
void printList(TList head); //печать списка
void print(TList head); //рекурсивная печать списка 
void createFromHead(TList& head); //формирование списка в прямом порядке 
void createFromTail(TList& head); //формирование списка в обратном порядке 

bool fromFileToList(TList& head);
void L1L2(TList& L, TList& L1, TList& L2);