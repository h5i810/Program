#include "str_family.h"
#include <stddef.h>

void* memset(void*s, int c, size_t count);
void* memcpy(void* dest, const void* src, size_t count);
void* memmove(void* dest, const void*src, size_t count);

void* memset(void*src, int c, size_t count){
    char* tmp=(char*)src;
    while(count--)
        *tmp++=c;
    return src;
}


void* memcpy(void* dest, const void* src, size_t count){
    char* tmp=(char*)dest;
    const char* s=(const char*)src;

    while(count--)
        *tmp++=*s++;
    return dest;
}

void* memmove(void* dest, const void* src, size_t count){
    char *tmp;
    const char *s;
    if(dest<=src){
        tmp=dest;
        s=src;
        while(count--)
            *tmp+=*s++;
    }
    else{
        tmp=dest;
        tmp+=count;
        s=src;
        s+=count;
        while(count--)
            *--tmp=*--s;
    }

    return dest;
}

int memcmp(const void* cs, const void* ct, size_t count){
    const unsigned char* su1, *su2;
    int res=0;
    for(su1=cs, su2=ct; 0<count; ++su1,++su2, count--){
        if((res=*su1-*su2)!=0)
            break;
    }
    return res;
}

char *strstr(const char*s1, const char* s2){
    size_t len1, len2;

    len2=strlen(s2);
    if(!s2)
        return (char*)s1;
    len1=strlen(s2);
    
    while(len1>=len2){
        len1--;
        if(!memcmp(s1, s2,len2))
            return (char*)s1;
        s1++;
    }
    return NULL;
}



