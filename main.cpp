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
	//state.push_back(new State_node(data)) ;
	//state.push_back(new State_node(Init_jannggi2)) ;

	//g->Insert(state) ;

	
	return 0 ;
}
