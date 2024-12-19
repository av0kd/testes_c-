#include <iostream>
#include <cstring>

using namespace std;

int getStringLength(char str[]);
void getStringCopy(char strToCopy[], char strToBeCopied[]);
void getStringConcatenated(char str1[], char str2[]);
int getStringCompared(char str1[], char str2[]);



int main (){
    char str1 [55] = "0";
    char str2 [55] = "0";
    cin.getline(str1, 55);
    cin.getline(str2, 55);
    cout << "String 1: "<< str1 << "\nString 2: "<< str2 << endl;
    cout << "String 1 compared to String 2: "<< getStringCompared(str1,str2) <<endl;
    return 0;
}

int getStringLength(char str[]){
    int cont = 0;
    while (str[cont] != '\0' ){
        cont++;}
    return cont;}

void getStringCopy(char strToCopy[], char strBeingCopied[]){
    for (int i = 0; i < getStringLength(strBeingCopied); i++){
        strToCopy[i] = strBeingCopied[i];}}

void getStringConcatenated(char str1[], char str2[]){
    int st1Size = getStringLength(str1);
    int totalSize = st1Size+getStringLength(str2);
    for (int i = st1Size; i < totalSize; i++){
        str1[i] = str2[i-st1Size];}
}

int getStringCompared(char str1[], char str2[]){
    int diff = 0, i = 0;
    while(diff == 0){
        diff = str1[i] - str2[i];
        if(str1[i]=='\0' || str2[i]=='\0'){
            break;}
        i++;
    }
    return diff;
}