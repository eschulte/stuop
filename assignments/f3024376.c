#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
int _1(const void *_2, const void *_3);
int main() {
  int _9 = 0;
  char * _10[100];
  while (1) {
    char _4[80];
    fgets(_4, sizeof(_4), stdin);
    if (feof(stdin)) break;
    _10[_9] = strdup(_4);
    _9++;
  }
  int _11 = _9;
  char * _14[100];
  int _13 = 0;
  int _15;
  while(_11 != 0){
    char * _12 = "";
    int _8 = INT_MAX;
    for(_15=0; _15<_9; _15++){
      int _5;
      char * _6 = _10[_15];
      if (strcmp(_6, "") == 0) continue;
      int _7 = 0;
      for(_5=0; _5<_9; _5++){
        if(strcmp(_6, _10[_5]) == 0 && _5 % 2 == 0 && strcmp(_10[_5+1], "") != 0) _7++;
      }
      if(_7 < _8 || (_7 == _8 && strcmp(_6, _12) < 0)){
        _12 = _6;
        _8 = _7;
      }
    }
    if(_8 != 0){
      printf ("cycle");
      return 0;
    }
    for(_15=0; _15<_9; _15++){
      if(strcmp(_12, _10[_15]) == 0) {
        _10[_15] = "";
        _11--;
      }
    }
    _14[_13] = _12;
    _13++;
  }
  for (_15=0; _15<_13; _15++) {
    printf("%s",_14[_15]);
  }
  return 0;
}
