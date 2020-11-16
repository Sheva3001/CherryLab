#pragma once

struct Node;

typedef Node* TList;

void init(TList& head); //�����������
bool isEmpty(TList head); //�������� �� ������� 
void addToHead(TList& head, int elem); //���������� � ������
void addAfterNode(TList pNode, int elem); //���������� � �������� 
void deleteFromHead(TList& head); //�������� � ������ ������ 
void deleteAfterNode(TList pNode); //�������� ����� ��������� �������� 
void clear(TList& head); //������� ������ 
void printList(TList head); //������ ������
void print(TList head); //����������� ������ ������ 
void createFromHead(TList& head); //������������ ������ � ������ ������� 
void createFromTail(TList& head); //������������ ������ � �������� ������� 

bool fromFileToList(TList& head);
void L1L2(TList& L, TList& L1, TList& L2);