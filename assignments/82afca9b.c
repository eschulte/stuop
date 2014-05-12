#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _5 {
  char * _8;
  struct _5 * _10;
} ;
int _7(struct _5 * _3, char * _1) {
  if(_3 == NULL) {
    return 0;
  }
  else if(!strcmp(_3 -> _8, _1)) {
    return 1;
  }
  else {
    return _7(_3 -> _10, _1);
  }
}
char * * _15(struct _5 * _3, int _2) {
  char * * _4;
  int _28 = 0;
  _4 = malloc(_2 * sizeof(*_4));
  while (_3 != NULL) {
    _4[_28] = _3->_8;
    _28++;
    _3 = _3->_10;
  }
  return _4;
}
int _29(const void *_32, const void *_33);
int main() {
  struct _5 * _13 = NULL;
  struct _5 * _14 = NULL;
  struct _5 * _16 = NULL;
  int _17 = 0;
  int _12 = 0;
  while (1) {
    char _6[80];
    fgets(_6, sizeof(_6), stdin);
    if (feof(stdin)) break;
    {
      struct _5 * _11 = malloc(sizeof(*_11));
      char * _9 = strdup(_6);
      if(!_7(_13, _9)) {
        _11 -> _8 = _9;
        _11 -> _10 = _13;
        _13 = _11;
        _17++;
        _11 = malloc(sizeof(*_11));
      }
      if(_12 % 2 == 0) {
        _11 -> _8 = _9;
        _11 -> _10 = _16;
        _16 = _11;
      }
      else {
        _11 -> _8 = _9;
        _11 -> _10 = _14;
        _14 = _11;
      }
      _12++;
    }
  }
  int _25 = _12 / 2;
  char * * _23 = _15(_13, _17);
  char * * _20 = _15(_14, _25);
  char * * _21 = _15(_16, _25);
  qsort(_23, _17, sizeof(_23[0]), _29);
  char * * _27 = malloc(_17 * sizeof(*_27));
  int index = -1;
  int _26 = 0;
  int _24 = 0;
  while(_26 < _17) {
    char * _22 = NULL;
    int _28 = 0;
    for(_28 = 0; _28 < _17; _28++) {
      if(_23[_28] == NULL) {
        continue;
      }
      int _19 = 1;
      int _18 = 0;
      for(_18 = 0; _18 < _25; _18++) {
        if(_21[_18] == NULL) {
          continue;
        }
        else if(!strcmp(_23[_28], _21[_18])) {
          _19 = 0;
          break;
        }
      }
      if(_19) {
        _22 = _23[_28];
        index = _28;
        break;
      }
    }
    if(_22 == NULL) {
      break;
    }
    for(_28=0; _28 < _25; _28++) {
      if(_20[_28] == NULL) {
        continue;
      }
      else if(!strcmp(_22, _20[_28])) {
        _20[_28] = NULL;
        _21[_28] = NULL;
        _24++;
      }
    }
    _27[_26] = _22;
    _23[index] = NULL;
    _26++;
  }
  if(_24 == _25) {
    int _28 = 0;
    for (_28=0; _28 < _26; _28++) {
      printf("%s", _27[_28]);
    }
  }
  else {
    printf("%s", "cycle");
  }
  return 0;
}
int _29(const void *_30, const void *_31) {
  char * _32 = * (char * *)_30;
  char * _33 = * (char * *)_31;
  return strcmp(_32, _33);
}
