
#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <unordered_map>
#include <functional>

template <typename TEvent>
class Observer{
	std::unordered_map<TEvent, std::vector<std::function<void()>> > _map;
	
	public:
	void notify(const TEvent& event);
	void subscribe(const TEvent& event, const std::function<void()>& lambda);

};

template<typename TEvent>
void Observer<TEvent>::subscribe(const TEvent& event, const std::function<void()>& lambda){
	_map[event].push_back(lambda);
}

template<typename TEvent>
void Observer<TEvent>::notify(const TEvent & event){
	if (_map.find(event) == _map.end())
		return ;
	for (auto f : _map[event]){
		f();
	}
}
#endif