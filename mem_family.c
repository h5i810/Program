#include "mem_family.h"
#include <stdio.h>

int main(){
    char str[]="1234567";
    char str1[100]={0};
    puts(str);
    //memset(str, 0, sizeof(str));
    //puts(str);
    //memcpy(str1, str, sizeof(str));
    memmove(str1, str, sizeof(str));
    puts(str1);
}
