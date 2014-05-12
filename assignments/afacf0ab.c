#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
struct _27 {
  char* _30;
  struct _27* _8;
  struct _27* _32;
  struct _27* _16;
  int _24;
  int _25;
};
static struct _27* _36 = NULL;
static struct _27* _17 = NULL;
static int _26 = 0;
struct _27* _20() {
  struct _27* _13 = malloc(sizeof(struct _27));
  _13->_30 = NULL;
  _13->_8 = NULL;
  _13->_32 = NULL;
  _13->_16 = NULL;
  _13->_24 = 0;
  _13->_25 = 0;
  return _13;
}
void _11(struct _27* _13, char* _18) {
  struct _27* _31 = _13->_8;
  int _1 = (_31 == NULL) ? 0 : 1;
  while (_31) {
    if (!_31->_32) break;
    _31 = _31->_32;
    _1++;
  }
  assert(_1 == _13->_24);
  if (_31) {
    struct _27* _32 = _20();
    _31->_32 = _32;
    _32->_16 = _31;
    _32->_30 = strdup(_18);
  } else {
    _13->_8 = _20();
    _13->_8->_30 = strdup(_18);
  }
  _13->_24++;
}
struct _27* _12(struct _27* _13, char* _18) {
  struct _27* _2 = _13->_8;
  while (_2) {
    if (strcmp(_18, _2->_30) == 0) return _2;
    _2 = _2->_32;
  }
  return NULL;
}
void _28(struct _27* _13, char* _18) {
  struct _27* _3 = _12(_13, _18);
  if (_3) {
    if (_3->_16) {
      (_3->_16)->_32 = _3->_32;
    } else {
      _13->_8 = _3->_32;
    }
    if (_3->_32) {
      (_3->_32)->_16 = _3->_16;
    }
    free(_3);
    _13->_24--;
    assert(_13->_24 >= 0);
  }
}
struct _27* _14(struct _27* _36, char* _4) {
  struct _27* _31 = _36;
  while (_31) {
    if (strcmp(_4, _31->_30) == 0) return _31;
    _31 = _31->_32;
  }
  return NULL;
}
void _35(struct _27 *_31, int _5) {
  if (_31 == NULL) return;
  printf("%s", _31->_30);
  struct _27* _18 = _31->_8;
  while (_18) {
    printf("%s ", _18->_30);
    _18 = _18->_32;
  }
  if (_5) _35(_31->_32, _5);
}
struct _27* _19(struct _27* _31) {
  while (_31 && (_31->_25 || _31->_24 > 0)) {
    _31 = _31->_32;
  }
  if (_31 == NULL) return NULL;
  struct _27* _7 = _31;
  struct _27* _22 = _31;
  char* _6 = _31->_30;
  while (_31) {
    if ((strcmp(_6, _31->_30) > 0) && (_31->_25 == 0) && (_31->_24 == 0)) {
      _6 = _31->_30;
      _7 = _31;
    }
    _31 = _31->_32;
  }
  return _7;
}
int _33(struct _27* _31) {
  while (_31) {
    if (_31->_25 == 0) return 1;
    _31 = _31->_32;
  }
  return 0;
}
void _37(struct _27* _31) {
  if (!_31) return;
  struct _27* _22 = _31->_8;
  struct _27* _9;
  while (_22) {
    _9 = _22->_32;
    free(_22);
    _22 = _9;
  }
  while (_31) {
    _9 = _31->_32;
    free(_31);
    _31 = _9;
  }
}
int main() {
  char _10[80];
  char _15[80];
  while (fgets(_10, sizeof(_10), stdin) && fgets(_15, sizeof(_15), stdin)) {
    struct _27* _13;
    if (!_36) {
      _13 = _20();
      _26++;
      _13->_30 = strdup(_10);
      _36 = _13;
      _17 = _13;
    } else {
      _13 = _14(_36, _10);
      if (!_13) {
        _13 = _20();
        _26++;
        _13->_30 = strdup(_10);
        _13->_16 = _17;
        _17->_32 = _13;
        _17 = _13;
      }
    }
    _11(_13, _15);
    assert(_12(_13, _15) != NULL);
    struct _27* _18 = _14(_36, _15);
    if (!_18) {
      _18 = _20();
      _26++;
      _18->_30 = strdup(_15);
      _18->_16 = _17;
      _17->_32 = _18;
      _17 = _18;
    }
  }
  struct _27* _29;
  struct _27* _38 = NULL;
  struct _27* _21 = NULL;
  while (_29 = _19(_36)) {
    struct _27* _22 = _20();
    _22->_30 = strdup(_29->_30);
    if (_38) {
      _21->_32 = _22;
      _21 = _22;
    } else {
      _38 = _22;
      _21 = _22;
    }
    assert(_29->_25 == 0 && _29->_24 == 0);
    _29->_25 = 1;
    _26--;
    struct _27* _31 = _36;
    while (_31) {
      _28(_31, _29->_30);
      _31 = _31->_32;
    }
  }
  int _34 = _33(_36);
  if (_34) { printf("cycle\n"); }
  else { _35(_38, 1); }
  _37(_36);
  _37(_38);
  return 0;
}
