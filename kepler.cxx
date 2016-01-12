#include<iostream>
#include<cmath>

using namespace std;

int main(){
  
  double H, q[2], p[2], t = 0;
  const double e = 0.6, dt = 0.0005, tEnd = 20*M_PI;
  
  q[0] = 1-e;
  q[1] = 0;
  p[0] = 0;
  p[1] = sqrt((1+e)/(1-e));
  
  H = 0.5*(p[0]*p[0]+p[1]*p[1])-1/sqrt(q[0]*q[0]+q[1]*q[1]);
  
  cout << t << "\t" << H << "\t" << q[0] << "\t" << q[1] << endl;
  
  while (t<=tEnd){
    
    t += dt;
    
    double old = q[0]*q[0]+q[1]*q[1];
    
    for (int i=0; i<2; i++){
      
      p[i] -= dt*q[i]/pow(old,1.5);
      q[i] += dt*p[i];
      
    }
    
    H = 0.5*(p[0]*p[0]+p[1]*p[1])-1/sqrt(q[0]*q[0]+q[1]*q[1]);
    
    cout << t << "\t" << H << "\t" << q[0] << "\t" << q[1] << endl;
    
  }
  
  return 0;
  
}