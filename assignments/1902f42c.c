#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _18 {
  char * _26;
  int _24;
  struct _18 * _28;
  struct _18 * _21;
} ;
int _1(const void *_2, const void *_3) {
  char * _5 = * (char * *)_2;
  char * _4 = * (char * *)_3;
  return strcmp(_4,_5);
}
struct _18 * _22(struct _18 * _21, const void *_26) {
  if (_21 == NULL) return NULL;
  if (strcmp(_21->_26, _26) == 0) return _21;
  return _22(_21->_28, _26);
}
int main() {
  struct _18 * _7 = NULL;
  int _8 = 0;
  while (1) {
    char _6[80];
    fgets(_6, sizeof(_6), stdin);
    if (feof(stdin)) break;
    {
      struct _18 * _11 = malloc(sizeof(*_11));
      _11 -> _26 = strdup(_6);
      _11 -> _28 = _7;
      _7 = _11;
      _8++;
    }
  }
  char * * _9;
  int _13 = _8 - 1;
  _9 = malloc(_8 * sizeof(*_9));
  while (_7 != NULL) {
    _9[_13] = _7->_26;
    _13--;
    _7 = _7->_28;
  }
  struct _18 * _15 = NULL;
  struct _18 * _27 = NULL;
  struct _18 * _23 = NULL;
  struct _18 * _19 = NULL;
  int _12 = 0;
  for (_13 = 0; _13 < _8; _13 += 2) {
    struct _18 * _10;
    _10 = _22(_23, _9[_13]);
    if (_10 == NULL) {
      struct _18 * _11 = malloc(sizeof(*_11));
      _11->_26 = _9[_13];
      _11->_24 = 1;
      _11->_28 = _23;
      _23 = _11;
      _12++;
    } else {
      _10->_24++;
    }
    _10 = _22(_23, _9[_13+1]);
    if (_10 == NULL) {
      struct _18 * _11 = malloc(sizeof(*_11));
      _11->_26 = _9[_13+1];
      _11->_24 = 0;
      _11->_28 = _23;
      _23 = _11;
      _12++;
    }
    _10 = _22(_19, _9[_13]);
    if (_10 == NULL) {
      struct _18 * _11 = malloc(sizeof(*_11));
      _11->_26 = _9[_13];
      _11->_21 = NULL;
      _11->_28 = _19;
      _19 = _11;
    }
    _10 = _22(_19, _9[_13+1]);
    if (_10 == NULL) {
      struct _18 * _11 = malloc(sizeof(*_11));
      _11->_26 = _9[_13+1];
      _11->_21 = malloc(sizeof(*_11));
      _11->_21->_26 = _9[_13];
      _11->_21->_28 = NULL;
      _11->_28 = _19;
      _19 = _11;
    } else {
      struct _18 * _11 = malloc(sizeof(*_11));
      _11->_26 = _9[_13];
      _11->_28 = _10->_21;
      _10->_21 = _11;
    }
  }
  for (_13 = 0; _13 < _12; _13++) {
    char* _20 = NULL;
    struct _18 * _17 = NULL;
    struct _18 * _14 = _23;
    while (_14 != NULL) {
      if (_14->_24 == 0) {
        if (_20 == NULL || strcmp(_14->_26, _20) < 0) {
          _20 = _14->_26;
          _17 = _14;
        }
      }
      _14 = _14->_28;
    }
    if (_20 == NULL) {
      printf("cycle\n");
      _27 = NULL;
      break;
    }
    struct _18 * _16 = malloc(sizeof(*_16));
    _16->_26 = _20;
    if (_27 == NULL) {
      _27 = (_15 = _16);
    } else {
      _15->_28 = _16;
      _15 = _16;
    }
    _17->_24 = -1;
    struct _18 * _25 = _22(_19, _20)->_21;
    while (_25 != NULL) {
      (_22(_23, _25->_26)->_24)--;
      _25 = _25->_28;
    }
  }
  while (_27 != NULL) {
    printf("%s", _27->_26);
    _27 = _27->_28;
  }
  return 0;
}
