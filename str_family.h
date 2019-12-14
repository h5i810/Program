#pragma once
#include <stddef.h>

char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, size_t count);
char* strcat(char* dest, const char* src);
int strcmp(const char* cs, const char *ct);
size_t strlen(const char* s);

char* strcpy(char* dest, const char* src){
    char* tmp=dest;

    while((*tmp++=*src++)!='\0');
    return dest;
}

char* strncpy(char* dest, const char* src, size_t count){
    char* tmp=dest;
    while(count){
        if((*tmp=*src)!=0)
            src++;
        tmp++;
        count--;
    }

    return dest;
}


char* strcat(char* dest, const char* src){
    char *tmp=dest;

    while(*tmp) tmp++;
    while((*tmp++=*src++)!='\0');

    return dest;
}


int strcmp(const char* cs, const char* ct){
    unsigned char c1, c2;
    while(1){
        c1=*cs++;
        c2=*ct++;
        if(c1!=c2)
            return c1<c2? -1:1;
        if(!c1)
            break;
    }

    return 0;
}

size_t strlen(const char* src){
    const char *tmp=src;
    while(*tmp!='\0') tmp++;
    return tmp-src;
}
