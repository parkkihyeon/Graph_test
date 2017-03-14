#ifndef __STATE__NODE__  
#define __STATE__NODE__  

#include <iostream>
#include <vector>

#define WIDTH_SIZE 10
#define HEIGHT_SIZE 11

using namespace std ;


class State_node
{
public:
	int num_of_prev ;
	int num_of_next ;
	bool leaf_node ;
	vector<State_node*> *next ; 
	vector<State_node*> *prev ; 

	char arr[HEIGHT_SIZE][WIDTH_SIZE] ;

	State_node(char data[HEIGHT_SIZE][WIDTH_SIZE]) ;

	// state�� ���¸� ����Ѵ�.
	void Print_State();

	//node�� �ڽ��� ����.
	void Addlist_Child(State_node *add_state);
	void Connect_Parent(State_node *parent_state) ;

	// n��° �ڽ��� return
	State_node* NthCheck_Childnode(int n);

};

#endif