#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _1 {
  char * _5;
  struct _1 * _9;
} ;
int _24(const void *_28, const void *_27);
int main() {
  struct _1 * _8 = NULL;
  int _12 = 0;
  while (1) {
    char _2[80];
    fgets(_2, sizeof(_2), stdin);
    if (feof(stdin)) break;
    {
      struct _1 * _3 =
        malloc(sizeof(*_3));
      _3 -> _5 = strdup(_2);
      _3 -> _9 = _8;
      _8 = _3;
      _12++;
    }
  }
  {
    char * * _16;
    char * * _15;
    int * * _19;
    int _23 = 0;
    int _20 = 0;
    int _18 = 0;
    int _6 = 0;
    int _4 = 0;
    _15 = malloc(_12 * sizeof(*_15));
    _16 = malloc(_12 * sizeof(*_16));
    _19 = malloc(_12 * sizeof(*_19));
    while (_8 != NULL) {
      int _7 = 0;
      _15[_23] = _8->_5;
      for(_6 = 0; _6 < _23; _6++){
        if(strcmp(_15[_6],_15[_23]) == 0){
          _7 = 1;
          break;
        }
      }
      if(_7 == 0){
        _16[_18] = _15[_23];
        _18++;
      }
      _19[_23] = malloc(_12*sizeof(int));
      _23++;
      _8 = _8->_9;
    }
    for(_23=0; _23<_12; _23+=2){
      int _13 = 0;
      int _10 = 0;
      for(_20=0; _20 < _18; _20++)
        if(strcmp(_15[_23],_16[_20])==0)
          _13=_20;
      for(_20=0; _20 < _18; _20++)
        if(strcmp(_15[_23+1],_16[_20])==0)
          _10=_20;
      _19[_13][_10] = 1;
    }
    int _11=0;
    int _17 = 0;
    for(_23=0;_23<_18;_23++){
      _11 = 0;
      for(_20=0;_20<_18;_20++){
        if(_19[_20][_23]==1){
          _11 = 1;
          break;
        }
      }
      if(_11==0){
        _15[_17]=_16[_23];
        _17+=1;
      }
    }
    char * * _22;
    int _21 = 0;
    _22 = malloc(_12 * sizeof(*_22));
    while(_17 > 0){
      qsort(_15, _17, sizeof(_15[0]), _24);
      _22[_21] = _15[_17-1];
      _21+=1;
      _17-=1;
      int _13 = -1;
      for(_20=0; _20 < _18; _20++){
        if(strcmp(_22[_21-1],_16[_20])==0)
          _13=_20;
      }
      for(_23=0;_23<_18;_23++){
        if(_19[_13][_23]==1){
          _19[_13][_23]=0;
          int _14 = 0;
          for(_20=0;_20<_18;_20++){
            if(_19[_20][_23]==1){
              _14 = 1;
              break;
            }
          }
          if(_14 == 0){
            _15[_17]=_16[_23];
            _17+=1;
          }
        }
      }
    }
    for(_23=0;_23<_18;_23++)
      for(_20=0;_20<_18;_20++)
        if(_19[_23][_20]==1){
          printf("cycle\n");
          exit(0);
        }
    for(_23=0;_23<_21;_23++)
      printf("%s",_22[_23]);
  }
  return 0;
}
int _24(const void *_25, const void *_26) {
  char * _28 = * (char * *)_25;
  char * _27 = * (char * *)_26;
  return strcmp(_27,_28);
}