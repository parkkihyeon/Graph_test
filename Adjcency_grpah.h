#ifndef __ADJCENCY__GRAPH__  
#define __ADJCENCY__GRAPH__  

#include "Statenode.h"
#include <iostream>
#include <vector>

#define WIDTH_SIZE 10
#define HEIGHT_SIZE 11

using namespace std ;

class Adjcency_grpah
{
private :
	State_node *root ;
	vector<State_node*> *node_list ;

public:
	Adjcency_grpah(char Init_jannggi[HEIGHT_SIZE][WIDTH_SIZE]);

	void Insert(vector<State_node*> state);

	State_node* getRoot();
	// ���� ��ġ�� ��忡���� �ڽĳ��� �߰��� state�� ������ �ִ���.
	int Is_Have_childnode(State_node* sub_root, State_node* state);

	// ���� ��� state�� �׷����� �����ϰ� �ִ���
	State_node* Is_In_The_List_State(State_node *state);

	// �� state�� ������ �ٸ��� Ȯ���ϴ� �Լ�.
	bool Diff_State(State_node *stateA, State_node *stateB);
};

#endif