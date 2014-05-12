#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _35 {
  char * _36;
  struct _35 * _40;
} ;
struct _27 {
  char * _32;
  int _16;
} ;
struct _29 {
  char * _32;
  struct _35 * _12;
};
int _41(const void *_42, const void *_43);
int _26(const char * _33, struct _27 * _31, int _30);
int _28(const char * _33, struct _29 * _31, int _30);
void _37(char * _38, struct _35 * _39);
int _23(char * _24, char * * _25, int _30);
void _17(struct _35 * _18, char * * _19, int * _20, struct _27 * _21, int _22);
int main()
{
  struct _35 * _3 = NULL;
  int _8 = 0;
  while (1) {
    char _1[80];
    fgets(_1, sizeof(_1), stdin);
    if (feof(stdin)) break;
    {
      struct _35 * _2 =
        malloc(sizeof(*_2));
      _2 -> _36 = strdup(_1);
      _2 -> _40 = _3;
      _3 = _2;
      _8++;
    }
  }
  {
    char * * _25;
    char * * _9;
    char * * _14;
    int _34 = 0;
    _25 = malloc(_8 * sizeof(*_25));
    _9 = malloc(_8 * sizeof(*_9));
    while (_3 != NULL) {
      _25[_34] = _3->_36;
      _34++;
      _3 = _3->_40;
    }
    for (_34 = 0; _34 < _8; _34++) {
      _9[_34] = _25[_34];
    }
    qsort(_25, _8, sizeof(_25[0]), _41);
    int _22 = 0;
    char * _5 = "";
    char * _4 = "";
    for (_34 = _8-1; _34 > -1; _34--) {
      _5 = _25[_34];
      if (strcmp(_5, _4) != 0) {
        _22++;
      }
      _4 = _5;
    }
    _14 = malloc(_22 * sizeof(*_14));
    char * * _6 = malloc(_22 * sizeof(*_6));
    _4 = "";
    int _16 = 0;
    for (_34 = _8-1; _34 > -1; _34--) {
      _5 = _25[_34];
      if (strcmp(_5, _4) != 0) {
        _6[_16] = _5;
        _16++;
      }
      _4 = _5;
    }
    for (_34 = _8-1; _34 > -1; _34--) {
    }
    struct _27 * _21 = malloc(_22 * sizeof(*_21));
    struct _29 * _10 = malloc(_22 * sizeof(*_10));
    for (_34 = 0; _34 < _22; _34++) {
      _21[_34]._32 = _6[_34];
      _21[_34]._16 = 0;
      _10[_34]._32 = _6[_34];
      _10[_34]._12 = malloc(sizeof(_10[_34]._12));
    }
    int _7 = 0;
    int _11 = 0;
    for (_34 = _8-1; _34 > -1; _34--) {
      if (_7%2 == 0) {
        _11 = _26(_9[_34], _21, _22);
        _21[_11]._16 = _21[_11]._16 + 1;
      }else {
        _11 = _28(_9[_34], _10, _22);
        _37(_9[_34+1], _10[_11]._12);
      }
      _7++;
    }
    int * _20 = malloc(*_20);
    char * * _19 = malloc(_22 * sizeof(*_19));
    for (_34 = _8-1; _34 > -1; _34--) {
      _11 = _26(_9[_34], _21, _22);
      if (_21[_11]._16 == 0 && !_23(_9[_34], _19, *_20)) {
        _19[(*_20)] = _9[_34];
        (*_20)++;
      }
    }
    qsort(_19, *_20, sizeof(_19[0]), _41);
    int _13 = 0;
    while ((*_20) > 0) {
      _14[_13] = _19[0];
      _13++;
      if (_13 == _22) {
        break;
      }
      _11 = _28(_19[0], _10, _22);
      if (_11 == -1) {
        break;
      } else {
      }
      if (_10[_11]._12->_36 != NULL)
        _17(_10[_11]._12, _19, _20, _21, _22);
      for (_34 = 0; _34 < _22; _34++) {
        if (_34 == _22 - 1) {
          _19[_34] = NULL;
        }else {
          _19[_34] = _19[_34+1];
        }
      }
      (*_20)--;
      qsort(_19, *_20, sizeof(_19[0]), _41);
    }
    if (_13 != _22) {
      printf("cycle");
    } else {
      for (_34 = 0; _34 < _22; _34++) {
        printf("%s",_14[_34]);
      }
    }
  }
  return 0;
}
void _17(struct _35 * _18, char * * _19, int * _20, struct _27 * _21, int _22) {
  int _15;
  if (_18 != NULL) {
    _15 = _26(_18->_36, _21, _22);
    (_21[_15]._16)--;
    if (_21[_15]._16 == 0) {
      _19[*_20] = _18->_36;
      (*_20)++;
    }
    if (_18->_40 != NULL) {
      _17(_18->_40, _19, _20, _21, _22);
    }else {
      return;
    }
  }
}
int _23(char * _24, char * * _25, int _30) {
  int _34;
  for (_34 = 0; _34 < _30; _34++) {
    if (strcmp(_24, _25[_34]) == 0) {
      return 1;
    }
  }
  return 0;
}
int _26(const char * _33, struct _27 * _31, int _30) {
  int _34;
  for (_34 = 0; _34 < _30; _34++) {
    if (strcmp(_31[_34]._32, _33) == 0) {
      return _34;
    }
  }
  return -1;
}
int _28(const char * _33, struct _29 * _31, int _30) {
  int _34;
  for (_34 = 0; _34 < _30; _34++) {
    if (strcmp(_31[_34]._32, _33) == 0) {
      return _34;
    }
  }
  return -1;
}
void _37(char * _38, struct _35 * _39) {
  if (_39->_36 == NULL) {
    _39->_36 = _38;
  } else if (_39->_40 == NULL) {
    _39->_40 = malloc(sizeof(_39));
    _39->_40->_36 = _38;
  } else {
    _37(_38, _39->_40);
  }
}
int _41(const void *_42, const void *_43) {
  char * _44 = * (char * *)_42;
  char * _45 = * (char * *)_43;
  return strcmp(_44,_45);
}
