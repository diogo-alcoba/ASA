#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdio>
using namespace std;


int main(){
    int total_pessoas,ligacoes,pessoa,amigo;
    char virg;
    cin >> total_pessoas >> virg >> ligacoes;
    //cout << total_pessoas <<  " " << ligacoes;
    vector<int> amigos1(total_pessoas+1,0);
    vector<int> amigos2(total_pessoas+1,0);
    vector<int> hist1(total_pessoas,0);
    vector<int> hist2(total_pessoas,0);
    
   /*  amigos1.push_back(1);
    cout << amigos1[total_pessoas] << " " << amigos1[total_pessoas + 1];
    cout << amigos1.size(); */
    
    hist1[0] = total_pessoas;
    hist2[0] = total_pessoas;

    for (int i = 0; i < ligacoes; i++){
        cin >> pessoa >> amigo;
        hist1[amigos1[pessoa]++]--;
        hist1[amigos1[pessoa]]++;
        hist2[amigos2[amigo]++]--;
        hist2[amigos2[amigo]]++;
    }

    cout << "Histograma 1" << endl;
    for (int i = 0; i < total_pessoas; i++){
        cout << hist1[i] << endl;
    }
    cout << "Histograma 2" << endl;
    for (int i = 0; i < total_pessoas; i++){
        cout << hist2[i] << endl;
    }

    return 0;
}