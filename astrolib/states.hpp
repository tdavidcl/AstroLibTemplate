#pragma once
#include<cmath>
template <class T>
struct state{
  T root_rho=(T)0;
  T u=(T)0;
  T p=(T)0;
  T E=(T)0;
  T gamma=(T)0; 
};

template <class T>
struct flux{
  T rho;
  T mom;
  T pE;
};

template <class T>
inline state<T> operator-(state<T>a, state<T>b){
  state<T>c;
  c.root_rho=sqrt(a.root_rho*a.root_rho-b.root_rho*b.root_rho);
  c.u=a.u-b.u;
  c.p=a.p-b.p;
  c.E=a.E-b.E;
  c.gamma=0.5*(b.gamma+a.gamma);
  return c;
}
template <class T>
inline state<T> operator+(state<T>a, state<T>b){
  state<T>c;
  c.root_rho=sqrt(a.root_rho*a.root_rho+b.root_rho*b.root_rho);
  c.u=a.u+b.u;
  c.p=a.p+b.p;
  c.E=a.E+b.E;
  c.gamma=0.5*(b.gamma+a.gamma);
  return c;
}
template<class T>
inline state<T> operator*(state<T>a, T b){
  state<T>c;
  c.root_rho=sqrt(b)*a.root_rho;
  c.u=a.u*b;
  c.p=a.p*b;
  c.E=a.E*b;
  c.gamma=a.gamma;
}
template<class T>
inline state<T> mean(state<T>a,state<T>b){
  return 0.5*(a+b);
}