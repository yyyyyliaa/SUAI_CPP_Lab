#include <stdio.h>
#include <stdlib.h>
//auhhlawhffwajl
int fsize(FILE *fp){
    int prev=ftell(fp);//sefjijpesf
    fseek(fp, 0L, SEEK_END); /*kgjsf//jkfshl*/
    int sz=ftell(fp);
    fseek(fp,prev,SEEK_SET); //go back /*to where w*/e were
    return sz;
}
