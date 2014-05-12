#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _34 {
  char * _35;
  struct _34 * _36;
};
void _1(int * * _49, int _2) {
  int _58;
  int _30;
  for(_58 = 0; _58 < _2; _58++) {
    for(_30 = 0; _30 < _2; _30++) {
      printf("%d ", _49[_58][_30]);
    }
    printf("\n");
  }
}
void _3(char * _4) {
  int _58;
  for(_58 = 0; _58 < 80; _58++) {
    if(_4[_58] == '\n') {
      _4[_58] == '\0';
      return;
    }
  }
}
void _5(int * _12, int _21) {
  int _58;
  for(_58 = 0; _58 < _21; _58++) {
    printf("%d ", _12[_58]);
  }
  printf("\n");
}
int _22(char * _6, char * _7) {
  int _58 = 0;
  for(_58 = 0; _58 < 80; _58++) {
    char _8 = _6[_58];
    char _9 = _7[_58];
    if(_8 == _9) {
      if(_8 == '\0') {
        return 0;
      }
      continue;
    }
    if(_8 < _9) {
      return -1;
    } else {
      return 1;
    }
  }
  return 0;
}
int _10(int * _12, int * _21) {
  int _25 = _12[0];
  int _58;
  for(_58 = 1; _58 < _21[0]; _58++) {
    _12[_58 - 1] = _12[_58];
  }
  _12[_58] = -1;
  _21[0]--;
  return _25;
}
int _46(int * _12, int _21) {
  _21--;
  int _25 = _12[_21];
  _12[_21] = -1;
  return _25;
}
void _45(int * _12, int _21, int _11) {
  int _58;
  for(_58 = _21; _58 > 0; _58--) {
    _12[_58] = _12[_58 - 1];
  }
  _12[0] = _11;
}
void _50(int * _12, int _21, int _11) {
  _12[_21] = _11;
}
int _48(int * * _12, int _21, int _13) {
  int _25;
  _25 = 0;
  int _58;
  for(_58 = 0; _58 < _21; _58++) {
    _25 += _12[_13][_58];
  }
  return _25;
}
int _14(const void *_23, const void *_17);
int _39(const void *_23, const void *_17);
int _26(struct _34 *_24, char *_23);
int _14(const void *_15, const void *_16) {
  char * _23 = * (char * *)_15;
  char * _17 = * (char * *)_16;
  return strcmp(_17,_23);
}
int _39(const void *_15, const void *_16) {
  char * _23 = * (char * *)_15;
  char * _17 = * (char * *)_16;
  return strcmp(_23, _17);
}
int _53(const void * _23, const void * _17) {
  int _18 = *(const int*) _23;
  int _19 = *(const int*) _17;
  return (_18 < _19) - (_18 > _19);
}
void _20(struct _34 * _24) {
  struct _34 * _29 = _24;
  while(1) {
    printf("%s", _29 -> _35);
    if(_29 -> _36 == NULL) {
      break;
    }
    _29 = _29 -> _36;
  }
  printf("Done printing\n");
  return;
}
int _26(struct _34 *_24, char *_23) {
  if(_24 == NULL) {
    return -1;
  }
  int _25 = 0;
  struct _34 * _29 = _24;
  while(1) {
    if(_22(_23, _29 -> _35) == 0) {
      return _25;
    }
    if(_29 -> _36 == NULL) {
      break;
    }
    _29 = _29 -> _36;
    _25++;
  }
  return -1;
}
int _43(char * * _24, int _21, char * _23) {
  int _25 = 0;
  for(_25 = 0; _25 < _21; _25++) {
    if(_22(_23, _24[_25]) == 0) {
      return _25;
    }
  }
  return -1;
}
int main() {
  struct _34 * _33 = NULL;
  struct _34 * _37 = NULL;
  int _40 = 0;
  int _55 = 0;
  while (1) {
    char _28[80];
    fgets(_28, sizeof(_28), stdin);
    if (feof(stdin)) break;
    {
      struct _34 * _27 =
        malloc(sizeof(*_27));
      _27 -> _35 = strdup(_28);
      _27 -> _36 = _33;
      _33 = _27;
      _40++;
      if(_26(_37, _27 -> _35) == -1) {
        struct _34 * _29 = malloc(sizeof(*_29));
        _29 -> _35 = strdup(_28);
        _29 -> _36 = _37;
        _37 = _29;
        _55 ++;
      }
    }
  }
  {
    char * * _41;
    int * * _49;
    _49 = malloc(_55 * sizeof(* _49));
    int _30;
    for(_30 = 0; _30 < _55; _30++) {
      _49[_30] = malloc(sizeof(* _49[_30]) * _55);
    }
    char * * _56;
    _56 = malloc(_55 * sizeof(*_56));
    int _31;
    int _32;
    for(_31 = 0; _31 < _55; _31++) {
      for(_32 = 0; _32 < _55; _32++) {
        _49[_31][_32] = 0;
      }
    }
    int _58 = 0;
    _41 = malloc(_40 * sizeof(*_41));
    while (_33 != NULL) {
      _41[_58] = _33->_35;
      _58++;
      _33 = _33->_36;
    }
    _58 = 0;
    struct _34 * _38 = _37;
    while(_37 != NULL) {
      _56[_58] = _37 -> _35;
      _58++;
      _37 = _37 -> _36;
    }
    _37 = _38;
    qsort(_56, _55, sizeof(_56[0]), _39);
    _58 = 0;
    for(_58 = 0; _58 < _40; _58 += 2) {
      char * _44 = _41[_58];
      char * _42 = _41[_58 + 1];
      _49[_43(_56, _55, _42)][_43(_56, _55, _44)] = 1;
    }
    int * _51 = malloc(_55 * sizeof(*_51));
    int _52 = 0;
    int * _57 = malloc(_55 * sizeof(*_57));
    int _54 = 0;
    for(_58 = 0; _58 < _55; _58++) {
      if(_48(_49, _55, _58) == 0) {
        _45(_51, _52, _58);
        _52++;
      }
    }
    while(_52 > 0) {
      int _47 = _46(_51, _52);
      _52--;
      _50(_57, _54, _47);
      _54++;
      for(_58 = 0; _58 < _55; _58++) {
        if(_49[_58][_47] == 1) {
          _49[_58][_47] = 0;
          if(_48(_49, _55, _58) == 0) {
            _50(_51, _52, _58);
            _52++;
            qsort(_51, _52 + 1, sizeof(int), _53);
          }
        }
      }
    }
    if(_54  == _55) {
      for(_58 = 0; _58 < _55; _58++) {
        printf("%s", _56[_57[_58]]);
      }
    } else {
      printf("cycle\n");
    }
  }
  return 0;
}
