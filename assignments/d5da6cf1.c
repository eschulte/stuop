#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct _16 {
  char * _17;
  struct _16 * _22;
} ;
struct _16 * _18(struct _16 * _11);
bool _7(struct _16 * _25, struct _16 * _9);
bool _8(char ** _25, int _24, char * _9);
struct _16 * _10(struct _16 * _11);
struct _16 * _13(struct _16 * _25, char * _15);
struct _16 * _14(struct _16 * _25, struct _16 * _15);
bool _23(char ** _25, int _24);
int main() {
  struct _16 * _2 = NULL;
  int _24 = 0;
  while (1) {
    char _1[80];
    fgets(_1, sizeof(_1), stdin);
    if (feof(stdin)) {
      break;
    }
    {
      struct _16 * _20 = malloc(sizeof(*_20));
      _20 -> _17 = strdup(_1);
      _20 -> _22 = NULL;
      if (_2 == NULL) {
        _2 = _20;
      }
      else {
        _18(_2) -> _22 = _20;
      }
      _24++;
    }
  }
  {
    char ** _25 = malloc(_24 * sizeof(*_25));
    struct _16 * _21 = _2;
    int _26 = 0;
    while (_21 != NULL) {
      _25[_26] = _21 -> _17;
      _21 = _21 -> _22;
      _26++;
    }
    struct _16 * _5 = NULL;
    struct _16 * _4 = NULL;
    for (_26 = 0; _26 < _24; _26++) {
      if (!_7(_4, _13(_2, _25[_26]))) {
        if (!_8(_25, _24, _25[_26])) {
          struct _16 * _20 = malloc(sizeof(*_20));
          _20 -> _17 = _25[_26];
          _20 -> _22 = NULL;
          if (_4 == NULL) {
            _4 = _20;
          }
          else {
            _18(_4) -> _22 = _20;
          }
        }
      }
    }
    while (_4 != NULL) {
      struct _16 * _9 = _10(_4);
      _4 = _14(_4, _9);
      for (_26 = 0; _26 < _24; _26++) {
        if (strcmp(_25[_26], _9 -> _17) == 0) {
          _25[_26] = "";
        }
      }
      if (_5 == NULL) {
        _5 = _9;
      }
      else {
        _18(_5) -> _22 = _9;
      }
      for (_26 = 0; _26 < _24; _26++) {
        struct _16 * _3 = _13(_2, _25[_26]);
        if (_3 != NULL) {
          if (!_7(_4, _3)) {
            if (!_8(_25, _24, _25[_26])) {
              struct _16 * _20 = malloc(sizeof(*_20));
              _20 -> _17 = _25[_26];
              _20 -> _22 = NULL;
              if (_4 == NULL) {
                _4 = _20;
              }
              else {
                _18(_4) -> _22 = _20;
              }
            }
          }
        }
      }
    }
    if (_23(_25, _24)) {
      printf("cycle");
    }
    else {
      while(_5 != NULL) {
        printf("%s", _5 -> _17);
        _5 = _5 -> _22;
      }
    }
  }
  return 0;
}
struct _16 * _18(struct _16 * _11) {
  struct _16 * _6 = _11;
  while (_6 -> _22 != NULL) {
    _6 = _6 -> _22;
  }
  return _6;
}
bool _7(struct _16 * _25, struct _16 * _9) {
  struct _16 * _21 = _25;
  while (_21 != NULL) {
    if (strcmp(_21 -> _17, _9 -> _17) == 0) {
      return true;
    }
    _21 = _21 -> _22;
  }
  return false;
}
bool _8(char ** _25, int _24, char * _9) {
  int _26 = 0;
  while(_26 < _24) {
    if (strcmp(_25[_26], _9) == 0) {
      if(strcmp(_25[_26 + 1], "") != 0) {
        return true;
      }
    }
    _26 += 2;
  }
  return false;
}
struct _16 * _10(struct _16 * _11) {
  struct _16 * _21 = _11;
  char * _12 = _21 -> _17;
  while (_21 != NULL) {
    if (strncmp(_12, _21 -> _17, strlen(_12)) > 0) {
      _12 = _21 -> _17;
    }
    _21 = _21 -> _22;
  }
  return _13(_11, _12);
}
struct _16 * _13(struct _16 * _25, char * _15) {
  struct _16 * _21 = _25;
  while (_21 != NULL) {
    if (strcmp(_21 -> _17, _15) == 0) {
      struct _16 * _20 = malloc(sizeof(*_20));
      _20 -> _17 = _21 -> _17;
      _20 -> _22 = NULL;
      return _20;
    }
    _21 = _21 -> _22;
  }
  return NULL;
}
struct _16 * _14(struct _16 * _25, struct _16 * _15) {
  struct _16 * _21 = _25;
  struct _16 * _19 = NULL;
  while (_21 != NULL) {
    if (strcmp(_21 -> _17, _15 -> _17) == 0) {
      if(_19 == NULL) {
        _19 = _21 -> _22;
        return _19;
      }
      else {
        if (_21 -> _22 != NULL) {
          _18(_19) -> _22 = _21 -> _22;
        }
        return _19;
      }
    }
    else {
      if(_19 == NULL) {
        struct _16 * _20 = malloc(sizeof(*_20));
        _20 -> _17 = _21 -> _17;
        _20 -> _22 = NULL;
        _19 = _20;
      }
      else {
        struct _16 * _20 = malloc(sizeof(*_20));
        _20 -> _17 = _21 -> _17;
        _20 -> _22 = NULL;
        _18(_19) -> _22 = _20;
      }
    }
    _21 = _21 -> _22;
  }
  return _25;
}
bool _23(char ** _25, int _24) {
  int _26 = 0;
  for(_26 = 0; _26 < _24; _26++) {
    if(strcmp(_25[_26], "") != 0) {
      return true;
    }
  }
  return false;
}
