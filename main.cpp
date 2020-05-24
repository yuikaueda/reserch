#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N     100
//#define Pon   0.8
//#define Poff  0.5

//#define Koff   0.5
//#define Kon    0.5

#define f      2.0
#define Ks     0.1
#define Kc     100
  

double Uniform(){
  return ((double)rand()+1.0)/((double)RAND_MAX+2.0);
}

void checkNumberSpring(bool isBind[])
{
  int   countOn = 0;
  

  for(int idSpring = 0; idSpring < N; idSpring++){
    // count number of "on" spring
    if(isBind[idSpring]) countOn++; 
    
  } 
  printf("number of springs: %5d %5d\n", countOn, N - countOn);
}


void springOnOff(bool isBind[])
{

int   countOn = 0;
  

  for(int idSpring = 0; idSpring < N; idSpring++){
    // count number of "on" spring
    if(isBind[idSpring]) countOn++; 
    
  } 


double Kon = 0.2*(N - countOn);
double Koff = Ks*exp(f) + Kc*exp(-f);

  for(int idSpring = 0; idSpring < N; idSpring++){
    if(isBind[idSpring]){ // spring is on
      double value = Uniform(); 
      //if(value < Poff) isBind[idSpring] = false;
	if(value < Koff / (Koff + Kon) ) isBind[idSpring] = false;

    }
    else{ // spring is off
      double value = Uniform(); 
      //if(value < Pon) isBind[idSpring] = true;
	if(value < Kon / (Koff + Kon)) isBind[idSpring] = true;
    }
  } 
}

int main()
{
  bool  isBind[N];

  for(int idSpring = 0; idSpring < N; idSpring++)
    isBind[idSpring] = true;

  srand(1);
  for(int iter = 0; iter < 10; iter++){
    checkNumberSpring(isBind);
    springOnOff(isBind);
  }

  return 0;
}
