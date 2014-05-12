#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct _27 {
  char * _33;
  struct _27 * _35;
};
struct _16 {
  char * _33;
  int _17;
  struct _16 * _35;
};
struct _9 {
  char * _33;
  struct _27 * _4;
  struct _9  * _35;
};
bool _22(struct _16 * _8) {
  while (_8 != NULL) {
    if (strcmp("", _8->_33) != 0) {
      return true;
    }
    _8 = _8->_35;
  }
  return false;
}
bool _15(char * _6, struct _16 * _8) {
  while (_8 != NULL) {
    if (strcmp(_6, _8->_33) == 0) {
      return true;
    }
    _8 = _8->_35;
  }
  return false;
}
bool _24(char * _6, struct _9 * _8) {
  while (_8 != NULL) {
    if (strcmp(_6, _8->_33) == 0) {
      return true;
    }
    _8 = _8->_35;
  }
  return false;
}
void _30(char * _6, struct _16 * _8) {
  while (_8 != NULL) {
    if (strcmp(_6, _8->_33) == 0) {
      _8->_33 = "";
      return;
    }
    _8 = _8->_35;
  }
  return;
}
void _25(char * _6, struct _9 * _2, struct _16 * _1) {
  while (_2 != NULL) {
    if (strcmp(_6, _2->_33) == 0) {
      struct _27 * _4 = _2->_4;
      while (_4 != NULL) {
        struct _16 * _21 = _1;
        while (_21 != NULL) {
          if (strcmp(_4->_33, _21->_33) == 0) {
            _21->_17--;
          }
          _21 = _21->_35;
        }
        _4 = _4->_35;
      }
    }
    _2 = _2->_35;
  }
}
void _14(char * _6, struct _16 ** _8) {
  if (*_8 == NULL) {
    (*_8) = malloc(sizeof(**_8));
    (*_8)->_33 = _6;
    (*_8)->_17 = 1;
    (*_8)->_35 = NULL;
    return;
  }
  struct _16 * _21 = *_8;
  struct _16 * _5 = NULL;
  while (_21 != NULL) {
    if (strcmp(_21->_33, _6) == 0) {
      _21->_17++;
      return;
    }
    _5 = _21;
    _21 = _21->_35;
  }
  _21 = malloc(sizeof(*_21));
  _21->_33 = _6;
  _21->_17 = 1;
  _21->_35 = NULL;
  _5->_35 = _21;
  return;
}
void _18(char * _6, char * _3, struct _9 ** _8) {
  if (*_8 == NULL) {
    (*_8) = malloc(sizeof(**_8));
    (*_8)->_33 = _6;
    (*_8)->_4 = malloc(sizeof((*_8)->_4));
    (*_8)->_4->_33 = _3;
    (*_8)->_4->_35   = NULL;
    (*_8)->_35 = NULL;
    return;
  }
  struct _9 * _21 = *_8;
  struct _9 * _5 = NULL;
  while (_21 != NULL) {
    if (strcmp(_21->_33, _6) == 0) {
      struct _27 * _29 = malloc(sizeof(*_29));
      _29->_33 = _3;
      _29->_35 = _21->_4;
      _21->_4 = _29;
      return;
    }
    _5 = _21;
    _21 = _21->_35;
  }
  _21 = malloc(sizeof(*_21));
  _21->_33 = _6;
  struct _27 * _29 = malloc(sizeof(*_29));
  _29->_33 = _3;
  _29->_35 = NULL;
  _21->_4 = _29;
  _21->_35 = NULL;
  _5->_35 = _21;
  return;
}
int _7(char * _6, struct _16 * _8) {
  struct _16 * _21 = _8;
  while (_21 != NULL) {
    if (strcmp(_6, _21->_33) == 0) {
      return _21->_17;
    }
    _21 = _21->_35;
  }
  return -1;
}
char * _23(struct _16 * _8) {
  char * _31 = NULL;
  struct _16 * _21 = _8;
  while (_21 != NULL) {
    if (_31 == NULL) {
      if (strcmp(_21->_33, "") != 0)
        _31 = _21->_33;
    }
    else if(strcmp(_21->_33, "") != 0 && (_7(_21->_33, _8) < _7(_31, _8) || (_7(_21->_33, _8) == _7(_31, _8) && strcmp(_21->_33, _31) < 0))) {
      _31 = _21->_33;
    }
    _21 = _21->_35;
  }
  if (_7(_31, _8) == 0) {
    return _31;
  }
  return NULL;
}
int main() {
  struct _27 * _13       = NULL;
  struct _27 * _11       = NULL;
  struct _16   * _32    = NULL;
  struct _9  * _26 = NULL;
  int _12 = 0;
  while (1) {
    char _10[80];
    fgets(_10, sizeof(_10), stdin);
    if (feof(stdin)) break;
    struct _27 * _21 = malloc(sizeof(*_21));
    _21->_33 = strtok(strdup(_10), "\n");
    if (_11 != NULL) {
      _11->_35 = _21;
    }
    else {
      _13 = _21;
    }
    _11 = _21;
    _12++;
  }
  {
    struct _27 * _21 = _13;
    while (_21 != NULL) {
      char * _20 = _21->_33;
      char * _19 = _21->_35->_33;
      _14(_20, &_32);
      if (!_15(_19, _32)) {
        struct _16 * _29 = malloc(sizeof(*_29));
        _29->_33 = _19;
        _29->_17    = 0;
        _29->_35   = _32;
        _32 = _29;
      }
      _18(_19, _20, &_26);
      _21 = _21->_35->_35;
    }
  }
  struct _27 * _34 = NULL;
  struct _27 * _28 = NULL;
  while (_22(_32)) {
    char * _31 = _23(_32);
    if (_31 == NULL) {
      _34 = malloc(sizeof(*_34));
      _34->_33 = "cycle";
      _34->_35 = NULL;
      break;
    }
    if (_24(_31, _26)) {
      _25(_31, _26, _32);
    }
    struct _27 * _29 = malloc(sizeof(*_29));
    _29->_33 = _31;
    _29->_35 = NULL;
    if (_28 != NULL) {
      _28->_35 = _29;
    }
    else {
      _34 = _29;
    }
    _28 = _29;
    _30(_31, _32);
  }
  while (_34 != NULL) {
    printf("%s\n", _34->_33);
    _34 = _34->_35;
  }
  return 0;
}
