#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct _20 {
  char * _10;
  char * _11;
  struct _20 * _31;
};
struct _19 {
  char * _29;
  int _21;
  struct _19 * _31;
};
struct _23 {
  char * _29;
  struct _23 * _31;
};
int _33(const void *_6, const void *_5);
struct _23* _22(char * _17, struct _20 * _25);
struct _23* _24(char * _17, struct _20 * _25);
bool _26(char * _17, char * * _16, int _15);
char * * _18(struct _19 * _39, struct _20 * _25, int _38);
void _37(char * * _39, int _38);
int _12(char * _17, struct _20 * _25);
struct _19* _8(struct _20 * _25, int _9);
int _7(struct _19 * _39);
int main() {
  struct _20 * _25 = NULL;
  int _9 = 0;
  while (1) {
    char _2[80];
    fgets(_2, sizeof(_2), stdin);
    if (feof(stdin)) break;
    {
      struct _20 * _14 =
        malloc(sizeof(*_14));
      char * _1;
      if (_9 % 2 == 0) {
        _1 = strdup(_2);
      }
      else {
        _14 -> _10 = _1;
        _14 -> _11 = strdup(_2);
        _14 -> _31 = _25;
        _25 = _14;
      }
      _9++;
    }
  }
  struct _19 * _39 = _8(_25, _9);
  int _38 = _7(_39);
  char * * _36 = _18(_39, _25, _38);
  _37(_36, _38);
  return 0;
}
int _33(const void *_3, const void *_4) {
  char * _6 = * (char * *)_3;
  char * _5 = * (char * *)_4;
  return strcmp(_5,_6);
}
struct _23* _22(char * _17, struct _20 * _25) {
  struct _23 * _16 = NULL;
  while (1) {
    if (_25 == NULL) break;
    struct _23 * _14 = malloc(sizeof(*_14));
    if (strcmp(_25->_11, _17) == 0) {
      _14->_29 = _25->_10;
      _14->_31 = _16;
      _16 = _14;
    }
    _25 = _25->_31;
  }
  return _16;
}
struct _23* _24(char * _17, struct _20 * _25) {
  struct _23 * _16 = NULL;
  while (1) {
    if (_25 == NULL) break;
    struct _23 * _14 = malloc(sizeof(*_14));
    if (strcmp(_25->_10, _17) == 0) {
      _14->_29 = _25->_11;
      _14->_31 = _16;
      _16 = _14;
    }
    _25 = _25->_31;
  }
  return _16;
}
int _12(char * _17, struct _20 * _25) {
  int _21 = 0;
  while (1) {
    if (_25 == NULL) break;
    if (strcmp(_25->_10, _17) == 0) _21++;
    _25 = _25->_31;
  }
  return _21;
}
int _7(struct _19 * _39) {
  int _38 = 0;
  while (1) {
    if (_39 == NULL) break;
    _38++;
    _39 = _39->_31;
  }
  return _38;
}
struct _19* _8(struct _20 * _25, int _9) {
  struct _20 * _13 = _25;
  char * * _16 = malloc(_9 * sizeof(*_16));
  int _38 = 0;
  while (1) {
    if (_25 == NULL) break;
    if (!_26(_25->_10, _16, _38)) {
      _16[_38] = _25->_10;
      _38++;
    }
    if (!_26(_25->_11, _16, _38)) {
      _16[_38] = _25->_11;
      _38++;
    }
    _25 = _25->_31;
  }
  struct _19 * _39 = NULL;
  int _40 = 0;
  while (1) {
    if (_40 == _38) break;
    struct _19 * _14 = malloc(sizeof(*_14));
    _14->_29 = _16[_40];
    _14->_21 = _12(_16[_40], _13);
    _14->_31 = _39;
    _39 = _14;
    _40++;
  }
  free(_16);
  return _39;
}
bool _26(char * _17, char * * _16, int _15) {
  int _40 = 0;
  while (1) {
    if (_40 == _15) break;
    if (strcmp(_16[_40], _17) == 0) {
      return true;
    }
    _40++;
  }
  return false;
}
char * * _18(struct _19 * _39, struct _20 * _25, int _38) {
  char * * _35 = malloc(_38 * sizeof(*_35));
  int _32 = 0;
  while (1) {
    if (_39 == NULL) break;
    if (_39->_21 == 0) {
      _35[_32] = _39->_29;
      _32++;
    }
    _39 = _39->_31;
  }
  if (_32 == 0) {
    printf("cycle\n");
    exit(1);
  }
  qsort(_35, _32, sizeof(_35[0]), _33);
  char * * _36 = malloc(_38 * sizeof(*_35));
  int _34 = 0;
  while (1) {
    if (_32 == 0) break;
    _32--;
    _36[_34] = _35[_32];
    struct _23 * _30 = _22(_36[_34], _25);
    _34++;
    while (1) {
      if (_30 == NULL) break;
      bool _28 = true;
      struct _23 * _27 = _24(_30->_29, _25);
      while (1) {
        if (_27 == NULL) break;
        if (!_26(_27->_29, _36, _34)) {
          _28 = false;
        }
        _27 = _27->_31;
      }
      if (_28) {
        _35[_32] = _30->_29;
        _32++;
      }
      _30 = _30->_31;
    }
    qsort(_35, _32, sizeof(_35[0]), _33);
  }
  if (_34 != _38) {
    printf("cycle\n");
    exit(1);
  }
  free(_35);
  return _36;
}
void _37(char * * _39, int _38) {
  int _40 = 0;
  while (1) {
    if (_40 == _38) break;
    printf("%s", _39[_40]);
    _40++;
  }
}
