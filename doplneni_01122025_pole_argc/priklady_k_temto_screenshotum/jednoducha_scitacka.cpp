#include <iostream>
#include <sstream>

 /* 
 "string" argv[1][2] do "int"
 jednoducha scitacka dvou celich cisel
 jako ukazka prace z polem parametru a prevodu parametru mezi datovymi tipy
 */

using namespace std;
int argument_1, argument_2, suma;

int main(int argc, char *argv[]) {
//cout<<argc<<endl;
if (argc == 3){ // prave 2 zadane argumenty ( celem tedy 3, vcetne argv[0] )
cout<<"argv[0]="<<'"'<<argv[0]<<'"'<<endl; // prejmenovani souboru = zmena zde ( vypise vcetne uplne cesty )
// argv[1] -> int	
istringstream iss (argv[1]);
// argv[n] vzdy type string a pro aritmeticke operace se musi prevect na tip "int" apod.
if (iss >> argument_1){ // prevedeno string argv[1] na integer ? (ostreni chyby vstupu)
cout<<"argv[1]="<<'"'<<argument_1<<'"'<<endl;
}else{
// chyba prevedu argv[1]
cout<<"chyba argv[1]"<<endl;
system("pause");
exit(1);
}
// help 
}else{
cout<<"help:"<<endl;
cout<<argv[0]<<" 10 20"<<endl;
system("pause");
exit(0);
}

// argv[2] -> int
istringstream iss (argv[2]);
if (iss >> argument_2){ // prevedeno string argv[2] na integer ?
cout<<"argv[2]="<<'"'<<argument_2<<'"'<<endl;
}else{
// chyba prevodu argv[2]
cout<<"chyba argv[2]"<<endl;
system("pause");
exit(1);
}

/* 
soucet argumentu 1 a 2 (oba jiz type int)
jinak kazdy argument pride z vstupu vzdy jako type string a pro numericke operace
se musi prevect na tip "int" (cele cislo); "double" (desetine cislo) apod.
*/
suma = (argument_1 + argument_2); // int + int
// paklize se zada napr. 100.5, odrizne stoho desetinou cast ( musel by bejt datovej tip "double")
cout<<endl<<argument_1<<" + "<<argument_2<<" = "<<suma<<endl;

system("pause");
return 0;
}

