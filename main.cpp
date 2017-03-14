#include"Graph.h"

using namespace std ;

char Init_jannggi[HEIGHT_SIZE][WIDTH_SIZE] = {{'O','O','O','O','O','O','O','O','O','O'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'}};

char Init_jannggi2[HEIGHT_SIZE][WIDTH_SIZE] = {{'O','O','O','O','O','O','O','O','O','O'},
{'O','2','2','2','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'}};

char Init_jannggi3[HEIGHT_SIZE][WIDTH_SIZE] = {{'O','O','O','O','O','O','O','O','O','O'},
{'O','3','3','3','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'},
{'O','X','X','X','X','X','X','X','X','X'}};

void abc(char data[HEIGHT_SIZE][WIDTH_SIZE] )
{
	for(int i=1 ; i <=10 ; i++)
	{
		for(int j=1 ; j<=9 ; j++){
			data[i][j] = 'A' + i - 1 ;
		}
	}
}

int main()
{
	char data[HEIGHT_SIZE][WIDTH_SIZE] ;
	abc(data) ;

	Adjcency_grpah *g = new Adjcency_grpah(Init_jannggi) ;

	vector<State_node*> state ;
	state.push_back(new State_node(data)) ;
	state.push_back(new State_node(Init_jannggi2)) ;

	g->Insert(state) ;

	state.clear() ;
	state.push_back(new State_node(Init_jannggi3)) ;
	state.push_back(new State_node(data)) ;

	g->Insert(state) ;

	state.clear() ;
	state.push_back(new State_node(data)) ;
	state.push_back(new State_node(Init_jannggi3)) ;

	g->Insert(state) ;

	g->getRoot()->Print_State() ;
	g->getRoot()->NthCheck_Childnode(1)->Print_State() ;
//	g->getRoot()->NthCheck_Childnode(0)->NthCheck_Childnode(0)->Print_State();
	
	return 0 ;
}
