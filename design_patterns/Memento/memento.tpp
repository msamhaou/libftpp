
template<typename TType>
Memento::Snapshot& Memento::Snapshot::operator<<(const TType& s){
	db << s;
	return *this;
}

template<typename TType>
Memento::Snapshot& Memento::Snapshot::operator>>(TType& s){
	db >> s;
	return *this;
}