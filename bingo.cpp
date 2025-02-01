#include <iostream>
#include <cmath>

using namespace std;

const int NMAX = 50;
const int CMAX = 5;

struct jogador
{
    char nome [NMAX];
    int cartela [CMAX][CMAX] = {0};
    bool marcados [CMAX][CMAX] = {0};
};

void newCartela(int c[CMAX][CMAX]);
void showCartela(int c[CMAX][CMAX]);
void vectSort(int c[CMAX][CMAX]);

int main(){
    jogador jog[NMAX];
    int n;
    cout << "Insira a quantidade de jogadores: \n";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++){
        cout << "\nNome do jogador " << i+1 << ":  ";
        cin.getline(jog[i].nome, NMAX);
        newCartela(jog[i].cartela);
    }
    
    return 0;
}

void newCartela(int c[CMAX][CMAX]){
    int szAux;
    //define numeros da cartela 
    for(int i = 0; i < CMAX; i++){
        szAux = 0;
        while(szAux < 5){
            int num = (i*15)+(rand()%15)+1;
            if(num!=c[0][i] && num!=c[1][i] && num!=c[2][i] && num!=c[3][i] && num!=c[4][i]){
                c[szAux][i] = num;
                szAux++;}
        }
    }
    //organiza as cartelas em ordem
    vectSort(c);
    showCartela(c);
}

void vectSort(int c[CMAX][CMAX]){
    for(int lin = 0; lin < CMAX; lin++){
        for(int i = 0; i < CMAX-1; i++){
            for(int j = i+1; j < CMAX; j++){
                if(c[i][lin] > c[j][lin]){
                    int aux = c[i][lin];
                    c[i][lin] = c[j][lin];
                    c[j][lin] = aux;
                }
            }    
        }
    }
}

void showCartela(int c[CMAX][CMAX]){
    for(int i = 0; i < CMAX; i++){
        cout << "| ";
        for(int j = 0; j < CMAX; j++){
            c[i][j] >= 10?cout << c[i][j] << " ":cout << 0 <<c[i][j] << " ";
        }    
        cout << "|" << endl;
    }
}