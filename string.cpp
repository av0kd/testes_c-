#include <iostream>
#include <cstring>

const int SMAX = 51;

using namespace std;

int getStringLength(char str[]);
void getStringCopy(char strToCopy[], char strToBeCopied[]);
void getStringConcatenated(char str1[], char str2[]);
int getStringCompared(char str1[], char str2[]);
void rmStringFlaws(char str[]);
bool isStringPolindrome(char str[]);

int main (){
    char str [SMAX] = "a";
    char str2 [SMAX] = "c";
    cout << getStringCompared(str,str2) << endl << strcmp(str,str2);
    
    return 0;
}

int getStringLength(char str[]){
    int cont = 0;
    while (str[cont] != '\0' ){
        cont++;}
    return cont;}

void getStringCopy(char strCopying[], char strBeingCopied[]){
    for (int i = 0; i <= getStringLength(strBeingCopied); i++){
        strCopying[i] = strBeingCopied[i];}}

void getStringConcatenated(char str1[], char str2[]){
    int st1Size, totalSize, i;
    st1Size = getStringLength(str1);
    totalSize = st1Size+getStringLength(str2);
    for (i = st1Size; i <= totalSize; i++){
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

void rmStringFlaws(char str[]){
    char noSpaceVect [SMAX] = "";
    int iSt = 0, iSpcSt = 0;
    while(str[iSpcSt] != '\0' ){
        if((str[iSpcSt] >= 'a' && str[iSpcSt] <= 'z')||(str[iSpcSt] >= 'A' && str[iSpcSt] <= 'Z')||(str[iSpcSt] >= '0' && str[iSpcSt] <= '9')){
            if((str[iSpcSt] >= 'a' && str[iSpcSt] <= 'z')||(str[iSpcSt] >= '0' && str[iSpcSt] <= '9')){
                noSpaceVect[iSt] = str[iSpcSt];}
            else{   
                noSpaceVect[iSt] = str[iSpcSt]+32;}
            iSt++;}
        iSpcSt++;
    }
    noSpaceVect[iSt] = '\0';
    getStringCopy(str, noSpaceVect);
    
}

bool isStringPolindrome(char str[]){
    char bckupVec [SMAX] = "";
    getStringCopy(bckupVec , str);
    rmStringFlaws(bckupVec);
    int sz = getStringLength(bckupVec)-1;
    
    for(int i = 0; i <= (sz/2); i++){
        if (bckupVec[i] != bckupVec[sz-i]){
            return 0;
        }
    }
    return 1;
}