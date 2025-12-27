#include <iostream>
#include <vector>
#include <fstream>
#include <sys/stat.h>

// vytvori soubory pro novy prazdny projekt, bez nutnosti neco slozite nastavovat v samotnem DEV C

using namespace std;

// funkce kontola existence souboru
bool existuje_soubor(const string& nazev_souboru) {
struct stat buffer;
return (stat(nazev_souboru.c_str(), &buffer) == 0);
}

int main(){
// deklarace
//string cesta = "R:\\"; // tady menit
string cesta = "C:\\work\\";
//string cesta = "C:\\work\\folder\\";

cout<<"utilita vytvori novy prazdny projekt pro Dev C#"<<endl;
cout<<"soubor "<<'"'<<"*.c"<<'"'<<" a k nemu odpovidajici soubor "<<'"'<<"*.dev"<<'"'<<endl;
cout<<"bez nutnosti neco slozite nastavovat v samotnem DEV C#"<<endl;
cout<<"nazev souboru nesmi obsahovat mezery a specialni znaky"<<endl;
cout<<"znak mezera nahrazujte znakem podtrzitko"<<endl;
cout<<endl<<"zadej nazev noveho Dev C# projektu : ";
string nazev;
cin>>nazev; // input nazev

string cesta_c = cesta + nazev + ".c";
string cesta_dev= cesta + nazev + ".dev";
int aa, bb;

/*
kontrola jesli jiz soubor *.c existuje - aby se neprepsal novym prazdnym !
kontoluje jenom existenci *.c , *.dev nekontroluje, v *.dev neni o co prijit
a taky by meli existovat oba zaroven napr. "file_1.c" a k nemu i "file_1.dev"
*/
if (existuje_soubor(cesta_c)) {
cout<<"soubor "<<'"'<<cesta_c<<'"'<<" jiz existuje, zvolte jiny nazev"<<endl;
system("pause");
exit(0); 
}

// pole obsahu souboru souboru *.c
vector<string> pole_c = {
"#include <stdio.h>", // puvodni pro C++ bylo "#include <iostream>", 
"#include <stdlib.h>", // pridano ve verzi "C"
"",
"int main(int argc, char *argv[]) {", // puvodni pro Cpp bylo (int argc, char** argv)
"",
"printf(\"Hello World\\n\");",
"",
"",
"//system(\"pause\");",
"return 0;",
"}",
"" // na konci souboru budou po zapise 2 prazdny radky *
};

size_t d_pole_c = pole_c.size(); // delka pole pole_c do promenne d_dole_c
//cout<<d_pole_c<<endl; // 10

// zapis do souboru *.c
ofstream out_file_c(cesta_c);
if (!out_file_c){
cout<<"chyba pri zapisu do souboru "<<'"'<<cesta_c<<'"'<<endl; // ReadOnly apod.
system("pause");
exit(1); // chybovej exit 1
}

// zapis pole_c do souboru out_file_c
for (aa = 0; aa < d_pole_c; aa++ ){
//cout<<pole_c[aa]<<endl;
out_file_c<<pole_c[aa]<<endl; // pole_c, o jeden klic min nez je potreba (dela "\n" vzdy) *
}

// uzavreni souboru *.c
out_file_c.close();


/* 
seznam rozdilu mezi "C" a "Cpp" verzi souboru *.dev ( prvni "C"; druhy "Cpp" )

radek 16 - IsCpp=0                     ;    IsCpp=1
radek 42 - FileVersion=1.0.0.0         ;    FileVersion=
radek 49 - ProductVersion=1.0.0.0      ;    ProductVersion=
radek 54 - FileName=bubble_sort_1.cpp  ;    FileName=bubble_sort_1.c
radek 55 - CompileCpp=0                ;    CompileCpp=1
*/

// pole obsahu souboru souboru *.dev
vector<string> pole_dev = {
"[Project]",
"FileName=new_c_file_5.dev", // zmenit [1]
"Name=new_c_file_5", // zmenit [2]
"Type=1",
"Ver=2",
"ObjFiles=",
"Includes=",
"Libs=",
"PrivateResource=",
"ResourceIncludes=",
"MakeIncludes=",
"Compiler=",
"CppCompiler=",
"Linker=",
"IsCpp=0", // zmena oproti "Cpp" =0
"Icon=",
"ExeOutput=",
"ObjectOutput=",
"LogOutput=",
"LogOutputEnabled=0",
"OverrideOutput=0",
"OverrideOutputName=",
"HostApplication=",
"UseCustomMakefile=0",
"CustomMakefile=",
"CommandLine=",
"Folders=",
"IncludeVersionInfo=0",
"SupportXPThemes=0",
"CompilerSet=0",
"CompilerSettings=0000000000000000000000000",
"UnitCount=1",
"",
"[VersionInfo]",
"Major=1",
"Minor=0",
"Release=0",
"Build=0",
"LanguageID=1033",
"CharsetID=1252",
"CompanyName=",
"FileVersion=1.0.0.0", // zmena oproti "Cpp" FileVersion=
"FileDescription=Developed using the Dev-C++ IDE",
"InternalName=",
"LegalCopyright=",
"LegalTrademarks=",
"OriginalFilename=",
"ProductName=",
"ProductVersion=1.0.0.0", // zmena oproti "Cpp" ProductVersion=
"AutoIncBuildNr=0",
"SyncProduct=1",
"",
"[Unit1]",
"FileName=new_c_file_5.c", // zmana oproti "Cpp" *.cpp
"CompileCpp=0", // zmana oproti "Cpp" =1
"Folder=",
"Compile=1",
"Link=1",
"Priority=1000",
"OverrideBuildCmd=0",
"BuildCmd=",
"" // na konci souboru pak budou 2 prazdni radky **
};

// zmeny radku pole_dev
pole_dev[1] = "FileName=" + nazev + ".dev";
pole_dev[2] = "Name=" + nazev;
pole_dev[53] = "FileName=" + nazev + ".c";

size_t d_pole_dev = pole_dev.size(); // delka pole pole_dev do promenne d_dole_dev
//cout<<d_pole_dev<<endl; // 62

// zapis do souboru *.dev
ofstream out_file_dev(cesta_dev);
if (!out_file_dev){
cout<<"chyba pri zapisu do souboru "<<'"'<<cesta_dev<<'"'<<endl; // ReadOnly apod.
system("pause");
exit(1); // chybovej exit 1
}


// zapis pole_dev do souboru out_file_dev
for (bb = 0; bb < d_pole_dev; bb++ ){
//cout<<pole_dev[bb]<<endl;
out_file_dev<<pole_dev[bb]<<endl; // pole_dev, o jeden klic min nez je potreba (dela "\n" vzdy) **
}

// uzavreni souboru *.dev
out_file_dev.close();

// koncove hlaseni
cout<<"byl vytvoren soubor "<<'"'<<cesta_c<<'"';
cout<<" a soubor "<<'"'<<cesta_dev<<'"'<<endl<<endl;
cout<<"tento projekt otevrete dvojklikem na soubor "<<'"'<<cesta_dev<<'"'<<endl;
cout<<"klavesou F11 pak projekt prelozite a spustite"<<endl;

system("pause");
return 0;
}


