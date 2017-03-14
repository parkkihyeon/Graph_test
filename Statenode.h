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
	vector<State_node*> *next ; // 공간복잡도를 위해 list 사용.

	char arr[HEIGHT_SIZE][WIDTH_SIZE] ;

	State_node(char data[HEIGHT_SIZE][WIDTH_SIZE]) ;

	// state의 상태를 출력한다.
	void Print_State();

	//node의 자식을 생성.
	void Create_Child(State_node *add_state);

	// n번째 자식을 return
	State_node* NthCheck_Childnode(int n);

};

#endif