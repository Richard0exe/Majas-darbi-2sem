/// Uzdevums_H.cpp
/*********************************************************
H9. Doti divi faili bināri f1 un f2, kuru komponentes ir patvaļīgas simbolu virknes(komponentes sakārtotas alfabētiski).
Uzrakstīt programmu, kas apvieno failus f1 un f2 failā f3 tā, lai arī f3 komponentes būtu sakārtotas
(failā f3 nedrīkst parādīties divas komponentes ar vienādu vērtību).
Programmu veidot tā, lai pilns faila saturs netiktu ielādēts operatīvajā atmiņā.
Uzrakstīt arī palīgprogrammas, kas ļauj izveidot failus f1 un f2 un izdrukā failu saturu.
********************************************************/
/// Autors: Ričards Bubišs, rb22033
/// Veidota: 05.05.2023
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

const int MAX_GARUMS = 10;

struct Komponente {
    char teksts[MAX_GARUMS];     ///fiksēts komponentes garums 9 simboli


};
/**********************************
void createFile(const char* fileName)
void createFile(fileName)-
izveido bināro failu, kurā lietotājs ievava komponentes.
**********************************/
void createFile(const char* fileName)
{
    ofstream out(fileName, ios::binary);
    Komponente k;
    while(true){
        cout<<"Ievadiet faila " <<fileName<<" komponenti: "<<endl;
        cin.getline(k.teksts, MAX_GARUMS);      ///saglabās kā k.teksts masīvā ar garumu MAX_GARUMS
        if(strcmp(k.teksts, "exit") == 0){
            break;
        }
        out.write((char*)&k, sizeof(k));
        memset(k.teksts, '\0',MAX_GARUMS);   ///uzstāda elementu nulles vērtību
    }
    out.close();
}
/**************************************
void printFile(const char* fileName)
void printFile(fileName)-
izvada faila saturu uz lietotāja ekrāna.
***********************************/
void printFile(const char* fileName)
{
    ifstream in(fileName, ios::binary);
    Komponente k;
    while(in.read((char*)&k,sizeof(k))){
        cout<<k.teksts<<" ";
    }
    cout<<endl;
    in.close();
}
/*******************************************************************************
void mergeFiles(const char* file1, const char* file2, const char* file3)
void mergeFiles(file1,file2,file3)-
apvieno 2 failus kādā 1 failā, kurš saturēs pirmā un otrā faila komponentes.
*******************************************************************************/
void mergeFiles(const char* file1, const char* file2, const char* file3) {
    ifstream in1(file1, ios::binary);
    ifstream in2(file2, ios::binary);
    ofstream out(file3, ios::binary);

    Komponente k;

    map<Komponente, bool> uniqueComponents;

    while (in1.read((char*)&k, sizeof(k))) {
        uniqueComponents.insert(make_pair(k, true));   ///pāris komponente, vērtība true, ja komponente jau ir map tā netiks atkārtota
    }

    while (in2.read((char*)&k, sizeof(k))) {
        uniqueComponents.insert(make_pair(k, true));
    }

    for (const auto& comp : uniqueComponents) {             ///iterē starp map elementiem un ieraksa tos binārajā failā
        out.write((char*)&comp.first, sizeof(comp.first));
    }

    in1.close();
    in2.close();
    out.close();
}


int main()
{
    int ok;
    do{
    const char* f1= "f1.bin";
    const char* f2 = "f2.bin";
    const char* f3 = "f3.bin";

    createFile(f1);
    createFile(f2);

    cout<<"f1 saturs: "<<endl;
    printFile(f1);

    cout<<"f2 saturs: "<<endl;
    printFile(f2);

    mergeFiles(f1,f2,f3);

    cout<<"Faila f3 saturs: "<<endl;
    printFile(f3);

    cout<<"Vēlaties turpināt(1) vai beigt(0)?"<<endl;
    cin>>ok;
    cin.ignore();
    }while(ok!=0);

    return 0;

}

/************************************* Testa plāns **********************************************************
    Ievads                                                    paredzamais rezultāts
_____________________________________________________________________________________________________________
    f1.bin                      f2.bin                           f3.bin

    apple                       banana                           apple
    banana                      cherry                           banana
    orange                      kiwi                             cherry
                                                                 kiwi
                                                                 orange
______________________________________________________________________________________
                                                                 cat
    doggy                       cat                              doggy
    elephant                    elephant                         elephant
    fish                        horse                            fish
    giraffe                     koala                            giraffe
                                                                 horse
                                                                 koala
*************************************************************************************************************/


