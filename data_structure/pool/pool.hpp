#ifndef POOL_HPP
#define POOL_HPP

#include <vector>
#include <cstddef>
#include <utility>
#include <stdexcept>

template <typename TType>
class Pool {
private :
	size_t					pool_size;
    std::vector<TType *>	_pool;
	std::vector<bool>		is_aquired;

	void	free_remain(size_t n);
	void	grow(size_t size, size_t n);
public:
    class Object {
		
        TType * obj;
        Pool<TType> * _pool;
        void release();
		public:
        friend class Pool<TType>;
		Object(TType * p, Pool<TType> * pool) :obj(p), _pool(pool){
		}
        TType * operator->();
        ~Object(){
			this->obj->~TType();
            this->release();
		}
    };

	~Pool();
    void resize(const size_t& numberOfObjectStored);
    template <typename ... TArgs>
    Pool<TType>::Object acquire(TArgs&& ... p_args);
};

#include "pool.tpp"

#endif