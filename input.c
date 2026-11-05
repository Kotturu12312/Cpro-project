#include<stdio.h>
#include<ctype.h>
#include "input.h"
int readinput(char buf[]){
    //remove \n from the input;
    if(fgets(buf,16,stdin)==NULL)return 0;
    for (int i=0;buf[i]!='\0';i++){
        buf[i]=tolower(buf[i]);
        if (buf[i]=='\n')buf[i]='\0';
    }
    return 1;
}