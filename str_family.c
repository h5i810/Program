#include "str_family.h"

#include <stdio.h>

int main(){
    char str1[]="12444";
    char str2[100]={0};
    //strcpy
    //char* ret=strcpy(str2, str1);
    
    //strncpy
    char* ret=strncpy(str2, str1, 3);
    printf("strncpy: ret=%s\nstr2=%s\n", ret, str2);
    ret=strcat(str2, str1);
    printf("strcat: ret=%s\nstr2=%s\n", ret, str2);
    size_t num=strlen(str2);
    printf("strlen(str2)=%ld\n",num );

    printf("strcmp(st1, str2)=%d\n", strcmp(str1, str2));
}
