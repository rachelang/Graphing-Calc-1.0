#include <stdio.h>
#include <math.h>

double f0(double x);
double f1(double x);
double f2(double x);
double f3(double x);
void graphing(double(*f)(double x), double xL, double xR, double yD, double yU);
double dne(void);
#define DNE 1.4920694713590719

//Please open window to full-screen to see intended graph.
int main(void){
  graphing(f0, -10, 10, -1, 1);
  graphing(f1, -8, 8, -1.5, 1.5);
  graphing(f2, -10, 10, -100, 100);
  graphing(f3, -4, 10, -2, 5);
}

//Sample graphs:
double f0(double x){ if(x!=0.0) return 1/x; else return dne();}
double f1(double x){ return cos(x);}
double f2(double x){ return pow(x,3)+5*pow(x,2)-4*x-20;}
double f3(double x){ if(x>=0.0) return sqrt(x); else return dne();}

void graphing(double(*f)(double x), double xL, double xR, double yD, double yU){
  char graph[100][40];

  double xInc = (xR-xL)/100;  //value between each x-marker.
  double yInc = (yU-yD)/40; //value between each y-marker.
  double min = 0;

  double diff = (0-yD)-(double)(int)((0-yD)/yInc);
  int whole = (int)((0-yD)/yInc);
  int xAxis = diff<yInc/2? whole: whole+1;
  diff = (0-xL)-(double)(int)((0-xL)/xInc);
  whole = (int)((0-xL)/xInc);
  int yAxis = diff<xInc/2? whole: whole+1;

  for(int i=0; i<100; i++){
    for(int j=0; j<40; j++){
      graph[i][j]=' ';
      graph[i][xAxis]='_';
      graph[yAxis][j]='|';
    }
  }

  for(int i=0; i<100; i++){
    double yVal = f(xL + xInc*i);
    if(yVal<=yU && yVal>=yD && yVal!=DNE){
      diff = yVal-(double)(int)(yVal/yInc);
      whole = (int)(yVal/yInc);
      int yPos = diff<yInc/2? whole: whole+1;
      graph[i][yPos+xAxis] = '.';
    }
  }

  for(int i=39; i>=0; i--){
    for(int j=0; j<100; j++) printf("%c",graph[j][i]);
    printf("\n");
  }
}

//DNE points
double dne(void){ return 1.4920694713590719;}

