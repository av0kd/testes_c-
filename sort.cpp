#include <iostream>

using namespace std;

const int SZMAX = 30;

int vectCompare(char vec1[SZMAX], char vec2[SZMAX]);
void alphabeticSortCharMatriceMenu(char vec[SZMAX][SZMAX]);
void alphabeticSortCharMatriceToLowest(char vec[SZMAX][SZMAX], int n);
void alphabeticSortCharMatriceToHighest(char vec[SZMAX][SZMAX], int n);
void matriceFilling(char vec[SZMAX][SZMAX], int n);
void vectReplace(char vec1[SZMAX], char vec2[SZMAX]); 

int main (){
    
    int n;
    char str [SZMAX][SZMAX] = {};
    cout << "Indique a quantidade de linhas da matriz:  ";
    cin >> n;
    matriceFilling(str, n);
    cout << "Matriz definida!\n";
    alphabeticSortCharMatriceToLowest(str,n);
    cout << "Matriz organizada!\n";
    for(int i = 0; i < n; i++){
        cout << "Texto da string "<< i+1 << ":  "<< str[i] << endl;
    }
    
    
    return 0;
    }

void matriceFilling(char vec[SZMAX][SZMAX], int n){
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout << "Texto para a string "<< i+1 << ":  ";
        cin.getline(vec[i], SZMAX);
    }
}

int vectCompare(char vec1[SZMAX], char vec2[SZMAX]){
    int dif = 0, i = 0;
    while (dif == 0){
        dif = vec1[i]-vec2[i];
        if (vec1[i] == '\0'|| vec2[i] == '\0'){
            break;}
        i++;
    }
    return dif;
}

void charVectSortMenu(char vec[SZMAX][SZMAX]){

}

void alphabeticSortCharMatriceToLowest(char vec[SZMAX][SZMAX], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(vectCompare(vec[i],vec[j]) < 0){
                char aux[SZMAX] = {};
                vectReplace(aux,vec[i]);
                vectReplace(vec[i],vec[j]);
                vectReplace(vec[j],aux);
            }
        }    
    }
}

void alphabeticSortCharMatriceToHighest(char vec[SZMAX][SZMAX], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(vectCompare(vec[i],vec[j]) > 0){
                char aux[SZMAX] = {};
                vectReplace(aux,vec[i]);
                vectReplace(vec[i],vec[j]);
                vectReplace(vec[j],aux);
            }
        }    
    }
}

void vectReplace(char vec1[SZMAX], char vec2[SZMAX]){
    int i = 0;
    while (vec2[i]!='\0')
    {
        vec1[i]=vec2[i];
        i++;
    }
    vec1[i]='\0';
}