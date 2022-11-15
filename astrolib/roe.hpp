#pragma once
#include <cmath>
#include "states.hpp"

namespace roe{
  template<class T>
  class RiemannProblem{
    state<T> left;
    state<T> right;
    RiemannProblem(state<T>&&left_,state<T>&&right_){
      left=left_;
      right=right_;
    }
    flux<T> solve(){
      T hat_u=(left.root_rho*left.u + right.root_rho*right.u)/(left.root_rho+right.root_rho);
      T hat_H=((left.E+left.p)/left.root_rho + (right.E+right.p)/right.root_rho)/(left.root_rho+right.root_rho);
      T hat_c=sqrt((left.gamma-1)*hat_H-0.5*hat_u*hat_u);
    }
  }; 
}
