
template <typename TType>
DataBuffer& DataBuffer::operator<<(const TType& o){
    size_t size{};
	const uint8_t* ptr = nullptr;

	if constexpr (std::is_same_v<TType, std::string>){
		size = o.size();
		ptr = reinterpret_cast<const uint8_t*>(o.c_str());
	}else{
		size = sizeof(TType);
		ptr  = reinterpret_cast<const uint8_t*>(&o);
	}
	bytes_t arr(size);
	
	int i = 0;
	for (auto it = arr.begin(); it < arr.end(); it++, i++){
		*it = ptr[i];
	}
	this->stored.push(arr);
	return *this;
}

template <typename TType>
DataBuffer& DataBuffer::operator>>(TType& o){
	if (!this->stored.size())
		throw DataBuffer::NoDataIsAvailable();
	
	uint8_t* ptr = nullptr;

	ptr = reinterpret_cast<uint8_t*>(&o);
	const bytes_t first_vec = this->stored.front();
		int i = 0;
	if constexpr (std::is_same_v<TType, std::string>){
		o.assign
		(
			first_vec.begin(),\
			first_vec.end()
		);
	}else
		for (auto it = first_vec.begin(); it < first_vec.end(); it++, i++){
			ptr[i] = *it;
		}
	this->stored.pop();
	return *this;
}