#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _17 {
  char * _20;
  struct _17 * _25;
};
int _15(const void * _1, const void *_2) {
  char * _3 = * (char * *)_1;
  char * _4 = * (char * *)_2;
  return strcmp(_3, _4);
}
int main() {
  struct _17 * _7 = NULL;
  int _10 = 0;
  while(1) {
    char _5[80];
    fgets(_5, sizeof(_5), stdin);
    if (feof(stdin))
      break;
    {
      struct _17 * _6 = malloc(sizeof(*_6));
      _6 -> _20 = strdup(_5);
      _6 -> _25 = _7;
      _7 = _6;
      _10 ++;
    }
  }
  char * * _12 = malloc(_10 * sizeof(*_12));
  int _28 = 0;
  for(_28 = 0; _28 < _10; _28++) {
    _12[_10 - _28 - 1] = _7 -> _20;
    _7 = _7 -> _25;
  }
  char * * _21 = NULL;
  int _26 = 0;
  for(_28 = 0; _28 < _10; _28++) {
    int _8 = 0;
    int _19 = 0;
    for(_19 = 0; _19 < _26; _19++) {
      if(strcmp(_12[_28], _21[_19]) == 0) {
        _8 = 1;
        break;
      }
    }
    if(_8 == 0) {
      char * * _9 = malloc((_26 + 1) * sizeof(*_21));
      for(_19 = 0; _19 < _26; _19++) {
        _9[_19] = _21[_19];
      }
      free(_21);
      _9[_26] = _12[_28];
      _21 = _9;
      _26 ++;
    }
  }
  struct _17 * * _18 = malloc(_26 * sizeof(*_18));
  int * _22 = malloc(_26 * sizeof(*_22));
  for(_28 = 0; _28 < _26; _28++) {
    _18[_28] = NULL;
    _22[_28] = 0;
  }
  for(_28 = 0; _28 < _10 / 2; _28++) {
    int _19 = 0;
    for(_19 = 0; _19 < _26; _19++) {
      if(strcmp(_12[2 * _28 + 1], _21[_19]) == 0) {
        struct _17 * _11 = malloc(sizeof(*_11));
        _11 -> _20 = _12[2 * _28];
        _11 -> _25 = _18[_19];
        _18[_19] = _11;
      }
      if(strcmp(_12[2 * _28], _21[_19]) == 0) {
        _22[_19] ++;
      }
    }
  }
  char * * _27 = malloc(_26 * sizeof(*_27));
  for(_28 = 0; _28 < _26; _28++) {
    char * * _16 = malloc(_26 * sizeof(*_27));
    int _14 = 0;
    int _19 = 0;
    for(_19 = 0; _19 < _26; _19++) {
      if(_22[_19] == 0) {
        int _13 = 0;
        int _23 = 0;
        for(_23 = 0; _23 < _28; _23++) {
          if(strcmp(_27[_23], _21[_19]) == 0) {
            _13 = 1;
          }
        }
        if(_13 == 0) {
          _16[_14] = _21[_19];
          _14++;
        }
      }
    }
    if(_14 == 0) {
      printf("cycle");
      exit(0);
    }
    qsort(_16, _14, sizeof(_16[0]), _15);
    _27[_28] = _16[0];
    for(_19 = 0; _19 < _26; _19++) {
      if(strcmp(_27[_28], _21[_19]) == 0) {
        struct _17 * _24 = _18[_19];
        while(_24 != NULL) {
          int _23 = 0;
          for(_23 = 0; _23 < _26; _23++) {
            if(strcmp(_24 -> _20, _21[_23]) == 0) {
              _22[_23] --;
            }
          }
          _24 = _24 -> _25;
        }
      }
    }
  }
  for(_28 = 0; _28 < _26; _28++) {
    printf("%s", _27[_28]);
  }
}
