
#include "buffer.hpp"

template <typename TType>
DataBuffer<TType>::DataBuffer(){
    this->size = sizeof(TType);
    this->stored = new unsigned char[this->size];
}

template<typename TType>
DataBuffer<TType>::~DataBuffer(){
    delete[] this->stored;
}

template<typename TType>
unsigned char * DataBuffer<TType>::serialize(const TType& _o){
    std::memcpy(this->stored, &_o, this->size);
    return this->stored;
}

template <typename TType>
TType& DataBuffer<TType>::deserialize(TType& _o){
    std::memcpy(&_o, this->stored,this->size);
    return _o;
}


template<typename TType>
unsigned char * DataBuffer<TType>::operator<<(const TType& _o){
    return this->serialize(_o);
}

template<typename TType>
TType& DataBuffer<TType>::operator>>(TType& _o){
    return this->deserialize(_o);
}

template <typename TType>
std::ostream & operator<<(std::ostream& os, const DataBuffer<TType>& db){

    os << "[ ";
    for (size_t i = 0; i < db.size; ++i) {
        os << "0x" << std::hex << std::setw(2) << std::setfill('0') 
           << static_cast<int>(db.stored[i]) << " ";
    }
    os << "]";
    return os;
}
