#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _1 {
  char * _4;
  struct _1 * _6;
} ;
int _20(char **_26, char *_23, int _21, int _22);
void _24(char** _26, int _25);
int main() {
  struct _1 * _5 = NULL;
  int _7 = 0;
  while (1) {
    char _2[80];
    fgets(_2, sizeof(_2), stdin);
    if (feof(stdin)) break;
    {
      struct _1 * _3 = malloc(sizeof(*_3));
      _3 -> _4 = strdup(_2);
      _3 -> _6 = _5;
      _5 = _3;
      _7++;
    }
  }
  char **_8;
  _8 = malloc(_7 * sizeof(*_8));
  int _27 = _7 - 1;
  while(_5!=NULL) {
    _8[_27] = _5->_4;
    _5 = _5->_6;
    _27--;
  }
  int _15 = 0;
  for(_27=0; _27<_7; _27++) {
    if(_20(_8, _8[_27], 0, _27-1)==-1) _15++;
  }
  char **_13 = malloc(_15*sizeof(*_13));
  _15 = 0;
  for(_27=0; _27<_7; _27++) {
    if(_20(_13, _8[_27], 0, _15-1)==-1)
      _13[_15++] = _8[_27];
  }
  int **_16 = malloc(_15*sizeof(*_16));
  for(_27=0; _27<_15; _27++) {
    _16[_27] = malloc(_15*sizeof(*_16[_27]));
  }
  int _11;
  for(_27=0; _27<_15; _27++) {
    for(_11=0; _11<_15; _11++) {
      _16[_27][_11] = 0;
    }
  }
  for(_27=0; _27<_7; _27=_27+2) {
    int _9 = _20(_13, _8[_27+1], 0, _15-1);
    int _10 = _20(_13, _8[_27], 0, _15-1);
    _16[_9][_10] = 1;
  }
  char **_18 = malloc(_15*sizeof(*_18));
  int _19 = 0;
  while(_19 < _15) {
    char *_14 = NULL;
    int _17;
    for(_27=0; _27<_15; _27++) {
      int _12 = 1;
      for(_11=0; _11<_15; _11++) {
        if(_16[_11][_27]==1) {
          _12 = 0;
          break;
        }
      }
      if(_12 && _20(_18, _13[_27], 0, _19-1)==-1) {
        if(_14==NULL || strcmp(_14, _13[_27]) > 0) {
          _14 = _13[_27];
          _17 = _27;
        }
      }
    }
    if(_14==NULL) {
      printf("cycle\n");
      exit(0);
    }
    _18[_19++] = _14;
    for(_27=0; _27<_15; _27++) {
      _16[_17][_27] = 0;
    }
  }
  _24(_18, _19);
  return 0;
}
int _20(char **_26, char *_23, int _21, int _22) {
  int _27;
  for(_27=_21; _27<_22+1; _27++) {
    if(strcmp(_23, _26[_27])==0) return _27;
  }
  return -1;
}
void _24(char **_26, int _25) {
  int _27;
  for(_27=0; _27<_25; _27++) {
    printf("%s", _26[_27]);
  }
}
