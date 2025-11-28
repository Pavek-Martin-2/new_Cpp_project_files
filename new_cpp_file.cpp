#include <iostream>
#include <vector>
#include <fstream>
#include <sys/stat.h>

// vytvori soubory pro novy prazdny projekt, bez nutnosti neco slozite nastavovat v samotnem DEV C++

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

cout<<"utilita vytvori novy prazdny projekt pro Dev C++"<<endl;
cout<<"soubor "<<'"'<<"*.cpp"<<'"'<<" a k nemu odpovidajici soubor "<<'"'<<"*.dev"<<'"'<<endl;
cout<<"bez nutnosti neco slozite nastavovat v samotnem DEV C++"<<endl;
cout<<"nazev souboru nesmi obsahovat mezery a specialni znaky"<<endl;
cout<<"znak mezera nahrazujte znakem podtrzitko"<<endl;
cout<<endl<<"zadej nazev noveho Dev C++ projektu : ";
string nazev;
cin>>nazev; // input nazev

string cesta_cpp = cesta + nazev + ".cpp";
string cesta_dev= cesta + nazev + ".dev";
int aa, bb;

/*
kontrola jesli jiz soubor *.cpp existuje - aby se neprepsal novym prazdnym !
kontoluje jenom existenci *.cpp , *.dev nekontroluje, v *.dev neni o co prijit
a taky by meli existovat oba zaroven napr. "file_1.cpp" a k nemu i "file_1.dev"
*/
if (existuje_soubor(cesta_cpp)) {
cout<<"soubor "<<'"'<<cesta_cpp<<'"'<<" jiz existuje, zvolte jiny nazev"<<endl;
system("pause");
exit(0); 
}

// pole obsahu souboru souboru *.cpp
vector<string> pole_cpp = {
"#include <iostream>", 
"",
"using namespace std;",
"",
"int main(int argc, char** argv){",
"",
"cout<<\"Hello World\\n\";",
"",
"system(\"pause\");",
"return 0;",
"}",
"" // na konci souboru budou po zapise 2 prazdny radky *
};

size_t d_pole_cpp = pole_cpp.size(); // delka pole pole_cpp do promenne d_dole_cpp
//cout<<d_pole_cpp<<endl; // 10

// zapis do souboru *.cpp
ofstream out_file_cpp(cesta_cpp);
if (!out_file_cpp){
cout<<"chyba pri zapisu do souboru "<<'"'<<cesta_cpp<<'"'<<endl; // ReadOnly apod.
system("pause");
exit(1); // chybovej exit 1
}

// zapis pole_cpp do souboru out_file_cpp
for (aa = 0; aa < d_pole_cpp; aa++ ){
//cout<<pole_cpp[aa]<<endl;
out_file_cpp<<pole_cpp[aa]<<endl; // pole_cpp, o jeden klic min nez je potreba (dela "\n" vzdy) *
}

// uzavreni souboru *.cpp
out_file_cpp.close();


// pole obsahu souboru souboru *.dev
vector<string> pole_dev = {
"[Project]",
"FileName=new_cpp_file_5.dev", // zmenit [1]
"Name=new_cpp_file_5", // zmenit [2]
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
"IsCpp=1",
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
"FileVersion=",
"FileDescription=Developed using the Dev-C++ IDE",
"InternalName=",
"LegalCopyright=",
"LegalTrademarks=",
"OriginalFilename=",
"ProductName=",
"ProductVersion=",
"AutoIncBuildNr=0",
"SyncProduct=1",
"",
"[Unit1]",
"FileName=new_cpp_file_5.cpp", // zmenit [53]
"CompileCpp=1",
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
pole_dev[53] = "FileName=" + nazev + ".cpp";

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
cout<<"byl vytvoren soubor "<<'"'<<cesta_cpp<<'"';
cout<<" a soubor "<<'"'<<cesta_dev<<'"'<<endl<<endl;
cout<<"tento projekt otevrete dvojklikem na soubor "<<'"'<<cesta_dev<<'"'<<endl;
cout<<"klavesou F11 pak projekt prelozite a spustite"<<endl;

system("pause");
return 0;
}


