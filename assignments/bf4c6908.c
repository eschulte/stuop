#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _24 80
struct _2;
typedef struct _1 {
  char _23[_24];
  struct _2* _15;
  int _16;
} _11;
typedef struct _2 {
  struct _2* _28;
  _11* _22;
} _26;
_11* _12(char* _29, _26* _30);
_26* _18(_26* _19, _26* _20);
_26* _21(_26* _29, _26* _30);
_26* _25(_26* _29, _26* _30);
int main() {
  _26* _19 = NULL;
  int _3 = 1;
  while (1) {
    char _7[_24];
    char _5[_24];
    if ((fgets(_7, sizeof(_7), stdin) == NULL) ||
        (fgets(_5, sizeof(_5), stdin) == NULL)) {
      break;
    }
    char _4 = '\0';
    strncpy(strchr(_7, '\n'), &_4, 1);
    strncpy(strchr(_5, '\n'), &_4, 1);
    _11* _22 = _12(_7, _19);
    _11* _8 = _12(_5, _19);
    if (_8 == NULL) {
      _8 = (_11*) malloc(sizeof(_11));
      strncpy(_8->_23, _5, _24);
      _8->_15 = NULL;
      _8->_16 = 0;
      _26* _6 = (_26 *) malloc(sizeof(_26));
      _6->_22 = _8;
      _19 = _21(_19, _6);
    }
    if (_22 == NULL) {
      _22 = (_11*) malloc(sizeof(_11));
      strncpy(_22->_23, _7, _24);
      _22->_15 = NULL;
      _22->_16 = 0;
      _26* _9 = (_26 *) malloc(sizeof(_26));
      _9->_22 = _22;
      _19 = _21(_19, _9);
    }
    _26* _9 = (_26*) malloc(sizeof(_26));
    _9->_22 = _22;
    _9->_28 = NULL;
    _8->_15 = _25(_8->_15, _9);
    _22->_16 += 1;
  }
  _26* _10 = _18(_19, NULL);
  while(_10 != NULL) {
    printf("%s\n", _10->_22->_23);
    _10 = _10->_28;
  }
  return 0;
}
_11* _12(char* _29, _26* _30) {
  if (_30 == NULL) {
    return NULL;
  }
  if (!strncmp(_29, _30->_22->_23, _24)) {
    return _30->_22;
  }
  return _12(_29, _30->_28);
}
_26* _18(_26* _19, _26* _20) {
  if (_19 == NULL) {
    return _20;
  }
  _26* _27 = _19;
  if (_27->_22->_16 == 0) {
    _19 = _27->_28;
  } else {
    while (1) {
      if (_27->_28 == NULL) {
        char _13[6] = "cycle";
        strncpy(_19->_22->_23, _13, 6);
        _19->_28 = NULL;
        return _19;
      }
      if (_27->_28->_22->_16 == 0) {
        _26* _14 = _27;
        _27 = _27->_28;
        _14->_28 = _27->_28;
        break;
      }
      _27 = _27->_28;
    }
  }
  _20 = _25(_20, _27);
  _26* _17 = _27->_22->_15;
  while(_17 != NULL) {
    _17->_22->_16 -= 1;
    _17 = _17->_28;
  }
  return _18(_19, _20);
}
_26* _21(_26* _30, _26* _29) {
  if (_30 == NULL ||
      strncmp(_29->_22->_23, _30->_22->_23, _24) < 0) {
    _29->_28 = _30;
    return _29;
  }
  _26* _27 = _30;
  while (_27->_28 != NULL &&
         strncmp(_29->_22->_23, _27->_28->_22->_23, _24) > 0) {
    _27 = _27->_28;
  }
  _29->_28 = _27->_28;
  _27->_28 = _29;
  return _30;
}
_26* _25(_26* _30, _26* _29) {
  _29->_28 = NULL;
  if (_30 == NULL) {
    return _29;
  }
  _26* _27 = _30;
  while (_27->_28 != NULL) {
    _27 = _27->_28;
  }
  _27->_28 = _29;
  return _30;
}
