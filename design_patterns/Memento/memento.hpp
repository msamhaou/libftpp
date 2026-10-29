#ifndef MEMENTO_HPP
#define	MEMENTO_HPP

#include "../../data_structure/data_structures.hpp"

class Memento;
class Memento {

public:
class Snapshot{
	public:
	friend class Memento;
		template<typename TType>
		Snapshot& operator<<(const TType&);
		template<typename TType>
		Snapshot& operator>>(TType&);
	private:
		DataBuffer db;
	};

	Memento() = default;
	Snapshot save();
	void load(const Memento::Snapshot& state);
private:
	virtual void _saveToSnapshot(Memento::Snapshot& snapshot) const = 0;
	virtual void _loadFromSnapshot(Memento::Snapshot& snapshot) = 0;
};

#include "memento.tpp"


#endif