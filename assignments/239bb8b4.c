#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _1 {
  char * _5;
  struct _1 * _7;
} ;
int _25(const void *_26, const void *_27);
int main() {
  struct _1 * _6 = NULL;
  int _4 = 0;
  while (1) {
    char _2[80];
    fgets(_2, sizeof(_2), stdin);
    if (feof(stdin)) break;
    {
      struct _1 * _3 =
        malloc(sizeof(*_3));
      _3 -> _5 = strdup(_2);
      _3 -> _7 = _6;
      _6 = _3;
      _4++;
    }
  }
  char * * _24;
  char * * _23;
  char * * _22;
  char * * _21;
  _23 = malloc(_4 * sizeof(*_23));
  _24 = malloc(_4 * sizeof(*_24));
  _22 = malloc(_4*sizeof(*_22));
  _21 = malloc(_4* sizeof(*_21));
  int _18 = 0;
  int _16 = 0;
  while (_6 != NULL) {
    if (_16) {
      _21[_18] = _6->_5;
      _16 = 0;
      _18++;
    }
    else {
      _22[_18] = _6->_5;
      _16 = 1;
    }
    _6 = _6->_7;
  }
  _16 = 1;
  int _15 = 0;
  int _20;
  int _9;
  int _12;
  int _11;
  char* _8;
  char* _14;
  for (_9=0; _9<_18; _9++) {
    _8 = _22[_9];
    for (_20=0; _20<_18; _20++) {
      if (strcmp(_21[_20], _8)==0) {
        _16 = 0;
      }
    }
    for (_20=0; _20<_9; _20++) {
      if (strcmp(_22[_20], _8) == 0) {
        _16 = 0;
      }
    }
    if (_16) {
      _23[_15] = _8;
      _15++;
    }
    _16 = 1;
  }
  int _19 = 0;
  int _10;
  int _13;
  int _17 = 0;
  if (_15 == 0) {
    _16 = 0;
    _17 = 1;
  }
  else {
    _16 = 1;
  }
  while (_16) {
    qsort(_23, _15, sizeof(_23[0]), _25);
    _24[_19] = _23[0];
    for (_20=0; _20<_18; _20++) {
      if (strcmp(_22[_20], _23[0]) == 0) {
        _17++;
        _14 = _21[_20];
        _11 = 0;
        _10 = 0;
        for (_9=0;_9<_18;_9++) {
          if (strcmp(_21[_9], _21[_20]) == 0) {
            _11++;
            for (_12=0;_12<(_19+1);_12++) {
              if (strcmp(_22[_9], _24[_12]) == 0) {
                _10++;
              }
            }
          }
        }
        if ((_11 == _10) && (_11 != 0)) {
          _13 = 1;
          for (_12=0;_12<(_19+1);_12++) {
            if (strcmp(_14, _24[_12]) == 0) {
              _13 = 0;
            }
          }
          if (_13) {
            _23[_15] = _14;
            _15++;
          }
        }
      }
    }
    for (_20=1; _20<_15; _20++) {
      _23[_20-1] = _23[_20];
    }
    _15--;
    _19++;
    if (_15 == 0) {
      _16 = 0;
    }
  }
  if (_17 < _18) {
    printf("cycle");
  }
  else {
    for (_20=0; _20<_19; _20++) {
      printf("%s",_24[_20]);
    }
  }
  free(_21);
  free(_22);
  free(_23);
  free(_24);
  return 0;
}
int _25(const void *_26, const void *_27) {
  char * _28 = * (char * *)_26;
  char * _29 = * (char * *)_27;
  return strcmp(_28,_29);
}
