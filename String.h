#pragma once
#include <iostream>
#include <string.h>

class String
{
private:
    char* _data;

public:
    String()
    : _data(new char[1])
    {
        *_data='\0';
    }

    String(const String& rhs)
    : _data(new char[strlen(rhs._data)+1])
    {
        strcpy(_data, rhs._data);
    }

    String(const char* str)
    : _data(new char[strlen(str)+1])
    {
        strcpy(_data, str);   
    }

    ~String(){ delete [] _data; }

    String& operator=(const String &rhs){
        if(&rhs!=this){
            delete [] _data;
            _data=NULL;
            _data=new char[rhs.size()+1];
            strcpy(_data, rhs._data);
        }
        return *this;
    }

    size_t size() const{
        return strlen(_data); 
    }

    char* c_str() const{
        return _data;
    }
};
