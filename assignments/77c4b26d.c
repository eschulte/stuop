#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _23 {
  char * _24;
  struct _23 * _27;
};
struct _17 {
  char * _20;
  char * _19;
  struct _17 * _27;
};
void _13(struct _23 *, int _16);
void _15(struct _17 * _17, int _16);
int _25(const struct _23 * _26, const char * _28);
void _7(char *, struct _23 *, struct _23 *, struct _17 *, int*);
int main() {
  struct _23 * _14 = NULL;
  struct _23 * _2 = NULL;
  int _4 = 0;
  int _3 = 0;
  while (1) {
    char _1[64];
    fgets(_1, sizeof(_1), stdin);
    if (feof(stdin)) break;
    if ( !_25(_14, _1) )
      {
        struct _23 * _12 = malloc(sizeof(*_12));
        _12 -> _24 = strdup(_1);
        _12 -> _27 = _14;
        _14 = _12;
        _4++;
      }
    {
      struct _23 * _12 = malloc(sizeof(*_12));
      _12 -> _24 = strdup(_1);
      _12 -> _27 = _2;
      _2 = _12;
      _3++;
    }
  }
  struct _17 * _18 = NULL;
  {
    while (_2 != NULL) {
      struct _17 * _12 = malloc(sizeof(*_12));
      _12->_19 = _2->_24;
      _12->_20 = _2->_27->_24;
      _12->_27 = _18;
      _18 = _12;
      _2 = _2->_27->_27;
    }
  }
  _15(_18, _3 / 2);
  _13(_14, _4);
  int _9 = 0;
  struct _23 * _5 = malloc(sizeof(*_5));
  _5->_24 = "";
  _5->_27 = NULL;
  {
    struct _23 * _22 = _14;
    while (_22 != NULL) {
      char * _10 = _22->_24;
      if ( !_25(_5, _10) ) {
        _7(_10, NULL, _5, _18, &_9);
      }
      _22 = _22->_27;
    }
  }
  if (_9) printf("cycle\n");
  else {
    struct _23 * _22 = _5->_27;
    while (_22 != NULL) {
      printf("%s", _22->_24);
      _22=_22->_27;
    }
  }
  return 0;
}
void _7(char * _10, struct _23 * _6, struct _23 * _11, struct _17 * _18, int * _9) {
  if ( _25(_6, _10) ) *_9 = 1;
  if ( *_9 || _25(_11, _10) ) return;
  {
    struct _17 * _22 = _18;
    while (_22 != NULL) {
      if (strcmp(_22->_20, _10) == 0) {
        struct _23 * _8 = malloc(sizeof(*_8));
        _8->_24 = _10;
        _8->_27 = _6;
        _7(_22->_19, _8, _11, _18, _9);
        free(_8);
      }
      _22 = _22->_27;
    }
    if (*_9) return;
    struct _23 * _12 = malloc(sizeof(*_12));
    _12->_24 = _10;
    _12->_27 = NULL;
    while (_11->_27 != NULL) _11 = _11->_27;
    _11->_27 = _12;
  }
}
void _13(struct _23 * _14, int _16) {
  for (;_16!=0;_16--) {
    struct _23 * _22 = _14;
    while (_22->_27 != NULL) {
      if ( strcmp(_22->_24, _22->_27->_24) >= 0 ) {
        char * _21 = _22->_24;
        _22->_24 = _22->_27->_24;
        _22->_27->_24 = _21;
      }
      _22 = _22->_27;
    }
  }
}
void _15(struct _17 * _18, int _16) {
  for (;_16!=0;_16--) {
    struct _17 * _22 = _18;
    while (_22->_27 != NULL) {
      if ( strcmp(_22->_19, _22->_27->_19) >= 0 ) {
        char * _21 = _22->_19;
        _22->_19 = _22->_27->_19;
        _22->_27->_19 = _21;
        _21 = _22->_20;
        _22->_20 = _22->_27->_20;
        _22->_27->_20 = _21;
      }
      _22 = _22->_27;
    }
  }
}
int _25(const struct _23 * _26, const char * _28) {
  if ( _26 == NULL ) return 0;
  if ( strcmp(_26->_24, _28) == 0 ) return 1;
  return _25(_26->_27, _28);
}
