#include "lr.h"

int main(void) 
{
  int n;
  printf("Введите номер лабы: ");
  scanf("%d",&n);
  if(n==1)
    return lr1();
  else if(n==2)
    return lr2();
  else if(n==3)
    return lr3();
  else if(n==4)
    return lr4();
  else if(n==5)
    return lr5();
  else if(n==6)
    return lr6();
  else if(n==7)
    return lr7();
  else  
    printf("такой лабы нет");
}
