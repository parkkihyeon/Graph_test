#include "Statenode.h"

State_node::State_node(char data[HEIGHT_SIZE][WIDTH_SIZE]) {
	for(int i=1 ; i< HEIGHT_SIZE; i++)
		for(int j=1 ; j< WIDTH_SIZE ; j++)
			arr[i][j] = data[i][j] ;
	leaf_node = false ;
	next = new vector<State_node*>() ;
	num_of_prev = 0 ;
	num_of_next = 0 ;
} ;

// state�� ���¸� ����Ѵ�.
void State_node::Print_State(){
	for(int i=1 ; i< HEIGHT_SIZE; i++){
		for(int j=1 ; j< WIDTH_SIZE ; j++)
			cout << arr[i][j] << " " ;
		cout << endl ;
	}
};

//node�� �ڽ��� ����.
void State_node::Create_Child(State_node *add_state){
	this->next->push_back(add_state) ;
	int num_of_next = this->next->size() ;
};

// n��° �ڽ��� return
State_node* State_node::NthCheck_Childnode(int n){
	return next->at(n) ;
};