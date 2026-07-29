#ifndef BUFFER_HPP
#define BUFFER_HPP
#include <cstring>
#include <iostream>
#include <iomanip>
template<typename TType>
class DataBuffer{
public:
    DataBuffer();
    ~DataBuffer();
    unsigned char * operator<<(const TType & _o);
    TType& operator>>(TType & _o);
    unsigned char * stored;
    size_t size;
private :
    unsigned char * serialize(const TType & _o);
    TType& deserialize(TType & _o);
};

#endif