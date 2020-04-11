#ifndef VEC_H
#define VEC_H

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>

template <typename T>
class Vec
{
public:
    using iterator = T*;
    using const_iterator = const T*;
    using size_type = size_t;
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;

    Vec() { create();}
    ~Vec() { uncreate(); }
    explicit Vec(size_type n, const T& t=T()) { create(n, t); }
    Vec(const Vec& v) { create(v.begin(), v.end()); }
    Vec& operator=(const Vec&);

    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i];}
    
    void push_back(const T& t){
        if(avail==limit) grow();
        unchecked_append(t);
    }

    size_type size() const { return avail-data; }
    iterator begin() { return data; }
    const_iterator begin() const { return data;}

    iterator end() { return avail; }
    const_iterator end() const { return avail; }

private:
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);
    void uncreate();
    void grow();
    void unchecked_append(const T&);

private:
    iterator data;
    iterator avail;
    iterator limit;
    std::allocator<T> alloc;
};



template <typename T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
    if(this!=&rhs){
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <typename T>
void Vec<T>::create() {
    data = avail = limit = 0;
}

template <typename T>
void Vec<T>::create(size_type n, const T& val){
    data=alloc.allocate(n);
    avail=data;
    limit = data + n;
    std::uninitialized_fill(data, limit, val);
}

template<typename T>
void Vec<T>::create(const_iterator i, const_iterator j){
    data = alloc.allcate(j-i);
    limit=avail= std::uninitialized_copy(i, j, data);
}

template <typename T>
void Vec<T>::uncreate(){
    if(data){
        iterator it=avail;
        while(it!=data){
            alloc.destroy(--it);
        }
        alloc.deallocate(data, limit-data);
        data=limit=avail=0;
    }
}

template <typename T>
void Vec<T>::grow() {
    size_type new_size=std::max(2*(limit-data), ptrdiff_t(1));
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    uncreate();

    data=new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <typename T>
void Vec<T>::unchecked_append(const T& val){
    alloc.construct(avail++, val);
}

#endif
