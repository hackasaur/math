#include<iostream>
#include<conio.h>
#include<cmath>
using namespace std;

inline double f(double x){
  return (pow(x,3)+1);//equation's R.H.S. you can enter your own equation.
}

class calculus{
double a,b; //a and b will define the interval (a,b) in which the integral has to calculated.
  public:
    set_ab(double A, double B){
      a = A;
      b = B;    
    }
    double rect_integral(int n){ //this func integrates f(x) as a series of n rectangles.
      double sum = 0;
      double h = (b-a)/n;
      for(int i = 0;i < n;i++){
        cout<<"["<<i<<"]"<<f(a + (i * h)) * h<<"\n";  //prints length of each n rectangles. 
        sum += f(a + (i * h)) * h;
      }
      return(sum * h);
    }
    double trap_integral(int n){  //this func integrates f(x) as a series of n trapeziums.
      double sum = 0;
      double h = (b - a) / n;
      for(int i = 0;i < n;i++){
        cout<<"["<<i<<"]"<<(f(a + (i * h)) + f(a + ((i + 1) * h)))/2<<"\n"; //area/h of each n trapeziums.
        sum += (f(a + (i * h))+ f(a + ((i + 1) * h)))/2;    
      }
        return(sum * h);
    }
   double differentiate(double r, double h){  //this func diffrentiates f(x) at r with dx as h.
    return((f(r + h) - f(r)) / h);
   }
};
int main(){
  double lowLimit, upLimit;
  cout<<"enter the lower limit:";cin>>lowLimit;
  cout<<"enter the upper limit:";cin>>upLimit;
  calculus cal;
  cal.set_ab(lowLimit, upLimit);
  cout<<"the rectangle integral is:"<<cal.rect_integral(100)<<"\n\n"; //this prints integral of f(x) calculating sum of area of n rectangles.
  cout<<"the trapezoidal integral is:"<<cal.rect_integral(100)<<"\n\n"; //this prints integral of f(x) calculating sum of area of n trapeziums.
  cout<<"the differential is:"<<cal.differentiate(-5,0.001)<<"\n\n";
  
  system("pause");
  return 0;
}
