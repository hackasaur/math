#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

double f(double x){ //defining f(x)
  return (x * pow(M_E,x) - 3);
}

//regula-falsi method:
void regula(double a, double b, double toler){ //a,b are the initial guesses for the method given by user. Toler is the range of f(c) till which you want to itterate. The Smaller value gives better approximation of the root.
  double c = a; 
  int i=1;
  while(f(c) > toler || f(c) < -toler){ //loop will run while f(c) is not in the range of ±toler. 
    cout<< i << ") " << "a=" << a << ", b=" << b << ", f(a)=" << f(a) << ", f(b)=" << f(b);  //prints a,b,f(a),f(b) for each iteration(i).
    c = ( (a*f(b)) - (b*f(a)) )/( f(b) - f(a) );  //calculates value of c using equation of false-position method.
    if( (f(c) * f(b)) < 0 ){
      a = c;  
    }
    else b = c; //since signs of f(a) nd f(b) must be opposite so that the root lies between [a,b] range.
      cout<<", c="<<c<<", f(c)="<<f(c)<<endl; //prints f(c) for each itteration.
      ++i;
  }
  cout<< "\nthe root of the equation is: " << c << endl; //prints the value of c which is within ±tolerance
}  

void table_coordinates(double P, double Q, double H){ //prints coordinates after each interval of h from p to q.
  double p = P;
  double q = Q;
  double h= H;
  while(p <= q){
    cout<<"x = "<<p<<" y = "<<f(p)<<endl;
    p += h;
  }
}

int main(){
  double a,b,toler = 0.001;
  cout<<"the value of initial guess a:";cin>>a;
  cout<<"the value of initial guess b:";cin>>b;
  regula(a,b,toler);cout<<"\n";
  
  table_coordinates(a,b,0.1);
  
  system("pause");
  return 0;
}
