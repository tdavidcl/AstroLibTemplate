#pragma once
#include "states.hpp"
#include "roe.hpp"
#include "flux_limiters.hpp"

template<class T>
class interface{
	interface(state<T>&&left, state<T>&&right){
	}
}
