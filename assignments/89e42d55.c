#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _6 {
  char * _9;
  struct _6 * _11;
} ;
int _12(const void *_2, const void *_3) {
  char * _4 = * (char **)_2;
  char * _5 = * (char **)_3;
  return strcmp(_4,_5);
}
int _1(const void *_2, const void *_3) {
  char * _4 = * (char **)_2;
  char * _5 = * (char **)_3;
  if (strcmp(_4,"") == 0) {
    return strcmp(_5,_4);
  }
  if (strcmp(_5,"") == 0) {
    return strcmp(_5,_4);
  }
  return strcmp(_4,_5);
}
int main() {
  struct _6 * _10 = NULL;
  int _19 = 0;
  while (1) {
    char _7[60];
    fgets(_7, sizeof(_7), stdin);
    if (feof(stdin)) break;
    struct _6 * _8 =
      malloc(sizeof(*_8));
    _8 -> _9 = strdup(_7);
    _8 -> _11 = _10;
    _10 = _8;
    _19++;
  }
  char **_21;
  char **_15 = malloc(_19 * sizeof(*_15));
  int _30 = 0;
  _21 = malloc(_19 * sizeof(*_21));
  while (_10 != NULL) {
    _21[_30] = _10->_9;
    _15[_30] = _10->_9;
    _30++;
    _10 = _10->_11;
  }
  qsort(_15, _19, sizeof(_15[0]), _12);
  int _28 = 1;
  for (_30 = 0; _30 < _19-1; ++_30) {
    if (strcmp(_15[_30], _15[_30+1]) == 0) {
      continue;
    }
    else {
      _28 = _28 + 1;
    }
  }
  char **_24 = malloc(_28 * sizeof(*_24));
  int _13;
  int _14 = 0;
  int _16 = 0;
  for (_30 = 0; _30 < _19; ++_30) {
    _14 = 0;
    for (_13 = 0; _13 < _28; ++_13) {
      if (_24[_13] != NULL) {
        if (strcmp(_15[_30], _24[_13]) == 0) {
          _14 = 1;
          break;
        }
      }
    }
    if (_14 == 0) {
      _24[_16] = _15[_30];
      ++_16;
    }
  }
  int _25[_28];
  for (_30 = 0; _30 < _28; ++_30) {
    _25[_30] = 0;
  }
  int _22;
  for (_30 = 0; _30 < _28; ++_30) {
    char *_17 = _24[_30];
    for (_22 = 0; _22 < _19; ++_22) {
      if (_22%2 == 1) {
        if (strcmp(_17, _21[_22]) == 0) {
          _25[_30]++;
        }
      }
    }
  }
  char **_29 = malloc(_28 * sizeof(*_29));
  int _18 = 0;
  int _26 = 0;
  int _27 = 0;
  _30 = 0;
  while (_30 < _28) {
    if (_25[_30] == 0) {
      char *_20 = _24[_30];
      _25[_30]--;
      _29[_18] = _20;
      ++_18;
      for (_22 = 0; _22 < _19; ++_22) {
        if ((_22%2 == 0) && strcmp(_20, _21[_22]) == 0) {
          char *_23 = _21[_22+1];
          for (_26 = 0; _26 < _28; ++_26) {
            if (strcmp(_23, _24[_26]) == 0) {
              _25[_26]--;
              if (_25[_26] == 0) {
                _27 = 1;
              }
            }
          }
        }
      }
    }
    if (_27 == 1) {
      _27 = 0;
      _30 = 0;
    }
    else {
      ++_30;
    }
  }
  if (_29[_28-1] == NULL) {
    printf("cycle\n");
    exit(0);
  }
  for (_30=0; _30 < _28; _30++) {
    printf("%s", _29[_30]);
  }
  return 0;
}
