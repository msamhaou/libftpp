
#include "memento.hpp"

Memento::Snapshot Memento::save(){
	Memento::Snapshot snapshot;
	this->_saveToSnapshot(snapshot);
	return snapshot;
}

void Memento::load(const Memento::Snapshot& snapshot){
	// Memento::Snapshot loaded;
	Snapshot s(snapshot);
	this->_loadFromSnapshot(s);
} 