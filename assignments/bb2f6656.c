#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {
  false,
  true
} _12;
struct _13 {
  char * _21;
  char * _15;
};
struct _2 {
  char * _21;
  int    _6;
};
struct _16 {
  struct _13 * _17;
  struct _16 * _18;
};
struct _11 {
  struct _2 * _17;
  struct _11 * _18;
};
int _32 = 0;
struct _11* _22(char* _9, struct _11* _10, int _3) {
  _12 _1 = false;
  struct _11 *_5 = _10;
  while(_10 != NULL) {
    if(!strcmp(_10->_17->_21,_9)) {
      _10->_17->_6 += _3;
      _1 = true;
      break;
    }
    _10 = _10 -> _18;
  }
  if(!_1) {
    _32++;
    struct _2 * _20 = malloc(sizeof(*_20));
    _20->_21 = _9;
    _20->_6 = _3;
    struct _11 * _4 = malloc(sizeof(*_4));
    _4->_17 = _20;
    _4->_18 = _5;
    _5 = _4;
  }
  return _5;
}
char * _29(struct _11* _10) {
  struct _11 *_5 = _10;
  _12 _8 = false;
  char * _7 = NULL;
  while(_10 != NULL) {
    if(_10->_17->_6 == 0) {
      if(_7 == NULL)
        _7 = _10->_17->_21;
      else
        _7 = strcmp(_7, _10->_17->_21) < 0 ? _7 : _10->_17->_21;
    }
    if(_10->_17->_6 != -1) _8 = true;
    _10 = _10 -> _18;
  }
  if(_7 != NULL)
    return _7;
  if(_8)
    return "cycle";
  return "";
}
struct _11* _26(char *_9, struct _11* _10, struct _16 *_27) {
  _10 = _22(_9, _10, -1);
  while(_27 != NULL) {
    if(!strcmp(_27->_17->_15, _9)) {
      _10 = _22(_27->_17->_21, _10, -1);
    }
    _27 = _27->_18;
  }
  return _10;
}
int main() {
  struct _16 * _27 = NULL;
  struct _11 * _30 = NULL;
  int _24 = 0;
  _12 _25 = false;
  struct _13 * _20 = malloc(sizeof(*_20));
  while (1) {
    char _14[80];
    fgets(_14, sizeof(_14), stdin);
    if (feof(stdin)) break;
    {
      char * _23 = strdup(_14);
      if (_25) {
        _20 -> _15 = _23;
        struct _16 * _19 =
          malloc(sizeof(*_19));
        _19 -> _17 = _20;
        _19 -> _18 = _27;
        _27 = _19;
        _20 = malloc(sizeof(*_20));
        _30 = _22(_23, _30, 0);
      } else {
        _20 -> _21 = _23;
        _30 = _22(_23, _30, 1);
      }
      _24++;
      _25 = !_25;
    }
  }
  {
    char ** _33 = malloc(sizeof(char *) * _32);
    char * _28 = _29(_30);
    int _31 = 0;
    while(strcmp(_28, "")) {
      if(!strcmp(_28, "cycle")) {
        printf("cycle\n");
        return 0;
      }
      _33[_31] = _28;
      _30 = _26(_28, _30, _27);
      _28 = _29(_30);
      _31++;
    }
    int _34 = 0;
    for(; _34 < _32; _34++)
      printf("%s", _33[_34]);
  }
  return 0;
}
