#include<iostream>
#include<vector>

#define POINTER_SIZE 300
#define WIDTH_SIZE 10
#define HEIGHT_SIZE 11
#define MAX 100000

using namespace std ;

char Init_jannggi[HEIGHT_SIZE][WIDTH_SIZE] = {('3','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X')};

char Init_jannggi2[HEIGHT_SIZE][WIDTH_SIZE] = {('1','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X'),
	('X','X','X','X','X','X','X','X','X','X')};

class State_node
{
public:
	int num_of_prev ;
	int num_of_next ;
	bool leaf_node ;
	State_node *prev[POINTER_SIZE] ;
	State_node *next[POINTER_SIZE] ;
	char arr[HEIGHT_SIZE][WIDTH_SIZE] ;

	State_node(char data[HEIGHT_SIZE][WIDTH_SIZE]) {
		for(int i=1 ; i< HEIGHT_SIZE; i++)
			for(int j=1 ; j< WIDTH_SIZE ; j++)
				arr[i][j] = data[i][j] ;
		num_of_prev = 0 ;
		num_of_next = 0 ;
		leaf_node = false ;
	} 

	// state�� ���¸� ����Ѵ�.
	void Print_State(){
		for(int i=1 ; i<= 10; i++){
			for(int j=1 ; j<=9 ; j++)
				cout << arr[i][j] << " " ;
			cout << endl ;
		}
	}

	//node�� �ڽ��� ����.
	void Create_Child(State_node *add_state){
		this->next[num_of_next++] = add_state ;
	}

	// n��° �ڽ��� return
	State_node* NthCheck_Childnode(int n){
		return this->next[n] ;
	}

	void Plus_Siblingnode(){
		num_of_next++ ;
	}

	void Plus_Parentnode(){
		num_of_prev++ ;
	}

};

class Adjcency_grpah
{
private :
	State_node *root ;
	vector<State_node*> *node_list ;

public:
	Adjcency_grpah(){
		root = new State_node(Init_jannggi) ;
		node_list = new vector<State_node*>() ;
		node_list->push_back(root) ;
	}

	void Insert(State_node* state[], int len_history){
		int index = 0 ;
		State_node *now_state = root ;

		while(state[index]){
			State_node* add_state = state[index] ;
			int childnode = Is_Have_childnode(now_state,add_state) ;

			// �ڱ� �ڽİ� ������ ������ �״�� �̵�.
			if(childnode)
				now_state = now_state->NthCheck_Childnode(childnode) ;
			// �ڱ� �ڽİ� ������ ������ � ��忡 �����ϸ� �� ��带 next�� �����Ѵ�.
			else {
				now_state->Create_Child(add_state) ;
				now_state = add_state ;
				if(!Is_In_The_List_State(add_state)){
					node_list->push_back(add_state) ;
				}
			}
			index++ ;
		}
	}

	State_node* getRoot(){
		return root ;
	}

	// ���� ��ġ�� ��忡���� �ڽĳ��� �߰��� state�� ������ �ִ���.
	int Is_Have_childnode(State_node* sub_root, State_node* state){	
		for(int i=0; i<sub_root->num_of_next ; i++)
			if(!Diff_State(sub_root->NthCheck_Childnode(i), state))
				return i ;
		return NULL ;
	}


	// ���� ��� state�� �׷����� �����ϰ� �ִ���
	State_node* Is_In_The_List_State(State_node *state){
		for(int i=0; i<node_list->size() ; i++)
			if(!Diff_State(node_list->at(i), state))
				return node_list->at(i) ;
		return NULL ; 
	}

	// �� state�� ������ �ٸ��� Ȯ���ϴ� �Լ�.
	bool Diff_State(State_node *stateA, State_node *stateB){
		for(int i=1 ; i< HEIGHT_SIZE; i++)
			for(int j=1 ; j< WIDTH_SIZE ; j++){
				if ( stateA->arr[i][j] != stateB->arr[i][j] )
					return true ;
			}
			return false ;
	}
};

Adjcency_grpah *g = new Adjcency_grpah() ;

int main()
{
	char data[HEIGHT_SIZE][WIDTH_SIZE] ;
	for(int i=1 ; i <=10 ; i++)
	{
		for(int j=1 ; j<=9 ; j++){
			data[i][j] = 'A' + i - 1 ;
		}
	}

	State_node *t = new State_node(data) ;
	State_node *t2 = new State_node(Init_jannggi2) ;
	g->getRoot()->Print_State() ;

	return 0 ;
}
