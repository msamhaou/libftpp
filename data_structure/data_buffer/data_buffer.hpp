#ifndef DATA_BUFFER_HPP
#define DATA_BUFFER_HPP
#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <exception>
#include <stdexcept>

using bytes_t = std::vector<uint8_t>;

class DataBuffer{
private:
    std::queue<bytes_t> stored;
public:
    DataBuffer() = default;
    ~DataBuffer() = default;
	DataBuffer(const DataBuffer&) = default;
	DataBuffer(DataBuffer&&) = delete;
    template<typename TType>
    DataBuffer& operator<<(const TType & _o);
    template<typename TType>
    DataBuffer& operator>>(TType & _o);


	class NoDataIsAvailable : public std::runtime_error{
    public:
        NoDataIsAvailable(): std::runtime_error("No Object to deserialize"){}
	};
};

#include "data_buffer.tpp"
#endif