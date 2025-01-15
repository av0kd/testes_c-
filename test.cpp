#include <iostream>

using namespace std;
const int CMAX = 30;


struct Corrida{
    int dia;
    int mes;
    int ano;
    int horas;
    int minutos;
    int segundos;
    int paceMin;
    int paceSeg;
    float distancia;
};
void sortMenu(Corrida c[CMAX],  int n, int sortFilter);
void sortRunByPace(Corrida c[CMAX], int n);
void sortRunByDuration(Corrida c[CMAX], int n);
void sortRunByDate(Corrida c[CMAX], int n);



int main()
{
    Corrida c[CMAX];
    int n, sortFilter;
    cin >> n ;

    for (int i = 0; i < n; i++){
        int tempoTotal, pace;
        cin >> c[i].dia;
        cin >> c[i].mes;
        cin >> c[i].ano;
        cin >> c[i].horas;
        cin >> c[i].minutos;
        cin >> c[i].segundos;
        cin >> c[i].distancia;
        tempoTotal = (c[i].horas*60*60)+(c[i].minutos*60)+c[i].segundos;
        pace = tempoTotal/c[i].distancia;
        c[i].paceMin = pace/60;
        c[i].paceSeg = pace%60;
    }
    cin >> sortFilter;
    sortMenu(c,n,sortFilter);
    for (int r = 0; r < n; r++){
        cout << "\nTreino do dia " << c[r].dia << "/" <<c[r].mes << "/" << c[r].ano<< endl;
        cout << "Duracao: " << c[r].horas << ":" <<c[r].minutos << ":" << c[r].segundos<< endl; 
        cout << "Pace: " << c[r].paceMin << "'" <<c[r].paceSeg << '"' << endl;
        cout << "Distancia: " << c[r].distancia << " Km\n--------------------";
    }
    return 0;
}

void sortMenu(Corrida c[CMAX],  int n, int sortFilter){
    switch (sortFilter){
        case 0:
            cout << "Ordenados por data:";
            sortRunByDate(c,n);
            break;
        case 1:
            cout << "Ordenados por duracao:";
            sortRunByDuration(c,n);
            break;
        case 2:
            cout << "Ordenados por pace:";
            sortRunByPace(c,n);
            break;
        default:
            cout << "Filtro invalido!\n"; // espero q n chegue aqui
    }
}

void sortRunByDate(Corrida c[CMAX], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            Corrida aux = c[i];
            if((c[i].ano > c[j].ano) || (c[i].ano >= c[j].ano && c[i].mes > c[j].mes) || (c[i].ano >= c[j].ano && c[i].mes >= c[j].mes && c[i].dia > c[j].dia)){
                c[i] = c[j];
                c[j] = aux;
            }
        }
    }
}

void sortRunByDuration(Corrida c[CMAX], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int durationCI = (c[i].horas*60*60)+(c[i].minutos*60)+c[i].segundos;
            int durationCJ = (c[j].horas*60*60)+(c[j].minutos*60)+c[j].segundos;
            if(durationCI < durationCJ){
                Corrida aux = c[i];
                c[i] = c[j];
                c[j] = aux;
            }
        }    
    }
}

void sortRunByPace(Corrida c[CMAX], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            int paceCI = (c[i].paceMin*60) + c[i].paceSeg;
            int paceCJ = (c[j].paceMin*60) + c[j].paceSeg;
            Corrida aux = c[i];
            if(paceCI > paceCJ){
                c[i] = c[j];
                c[j] = aux;
            }
        }    
    }
}
