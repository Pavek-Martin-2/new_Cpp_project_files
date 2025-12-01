#include <iostream>

// zpracovani argumentu

using namespace std;

int main(int argc, char **argv) {
	
	//cout<<argv[0]<<endl; // argumet [0] je vzdy nazev spusteneho souboru
	
	if (argc == 1 ){ // prvni argument je tedy vlastne az argv[1]
		cout<<"priklad:"<<endl;
		//cout<<argv_3.exe <<" argument1 argument2"<<endl;
		cout<<argv[0]<<" argument1 argument2"<<endl;
		// v pripade mezer se da cely argument do uvozovek jako string
		exit(0);
	}
	
   for ( int aa = 1; aa <= argc; aa++){
   cout<<argv[aa]<<endl;
}
   system("pause");
   return 0;

}


