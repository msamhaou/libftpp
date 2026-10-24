
template <typename TType>
Pool<TType>::~Pool(){
	for (auto elem : this->_pool)
		delete elem;
}

template <typename TType>
void Pool<TType>::free_remain(size_t n){
	for(size_t i{n-1}; i > 0; --i){
		delete this->_pool[i];
	}
}

template <typename TType>
void Pool<TType>::grow(size_t size, size_t n){
	for (size_t i{size}; i < n; i++){
		this->_pool[i] = new TType;
	}
}


template <typename TType>
void Pool<TType>::resize(const size_t& numberOfObjectStored){
	if (numberOfObjectStored < pool_size){
		free_remain(pool_size - numberOfObjectStored);
		this->_pool.resize(numberOfObjectStored);
		
	}
	else if (numberOfObjectStored > pool_size){
		this->_pool.resize(numberOfObjectStored);

		grow(pool_size, numberOfObjectStored);
	}
	this->is_aquired.resize(numberOfObjectStored);
	this->pool_size = numberOfObjectStored;
}

template <typename TType>
template <typename ... TArgs>
typename Pool<TType>::Object Pool<TType>::acquire(TArgs&& ... p_args){
	int i = 0;

	for (auto is : is_aquired){
		if (!is)
		{
			this->is_aquired[i] = true;
			TType*p = new (this->_pool[i]) TType(std::forward<TArgs>(p_args)...);
			return Object(p, this);
		}
		++i;
	}
    throw std::runtime_error("NO All pools Are aquired!");
}


template <typename TType>
TType * Pool<TType>::Object::operator->(){
    return this->obj;
}


template <typename TType>
void	Pool<TType>::Object::release(){
	auto pool = this->_pool->_pool;
	int i{};
	for (auto element : pool){
		if (element == this->obj)
		{
			this->_pool->is_aquired[i] = false;
			return;
		}
		++i;
	}
	throw std::runtime_error("this element does not exist");
}