#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _10 {
  char* _13;
  struct _10 *_19;
};
struct _16 {
  char* _26;
  char* _28;
  struct _16 *_19;
};
int _25(const void *_1, const void *_2) {
  char * _4 = * (char * *)_1;
  char * _3 = * (char * *)_2;
  return strcmp(_3,_4);
}
int main() {
  struct _16 * _18 = NULL;
  int _38 = 0;
  struct _10 * _15 = NULL;
  int _24 = 0;
  char _5[80];
  while (1) {
    struct _16 * _11 = malloc(sizeof(* _11));
    fgets(_5, sizeof(_5), stdin);
    if (feof(stdin)) break;
    _11->_26 = strdup(_5);
    fgets(_5, sizeof(_5), stdin);
    _11->_28 = strdup(_5);
    _11->_19 = _18;
    _18 = _11;
    _38++;
    int _7 = 0;
    struct _10 * _6 = _15;
    while (_6 != NULL) {
      if (strcmp((_6->_13), (_11->_26)) == 0) {
        _7 = 1;
        break;
      }
      _6 = _6->_19;
    }
    if (_7 == 0) {
      struct _10 * _12 = malloc(sizeof(*_12));
      _12->_13 = _11->_26;
      _12->_19 = _15;
      _15 = _12;
      _24++;
    }
    int _9 = 0;
    struct _10 * _8 = _15;
    while (_8 != NULL) {
      if (strcmp((_8->_13), (_11->_28)) == 0) {
        _9 = 1;
        break;
      }
      _8 = _8->_19;
    }
    if (_9 == 0) {
      struct _10 * _12 = malloc(sizeof(*_12));
      _12->_13 = _11->_28;
      _12->_19 = _15;
      _15 = _12;
      _24++;
    }
  }
  char * * _22;
  int _14 = 0;
  _22 = malloc(_24 * sizeof(*_22));
  while (_15 != NULL) {
    _22[_14] = _15->_13;
    _14++;
    _15 = _15->_19;
  }
  struct _16 * * _36;
  int _17 = 0;
  _36 = malloc(_38 * sizeof(*_36));
  while (_18 != NULL) {
    _36[_17] = _18;
    _17++;
    _18 = _18->_19;
  }
  char * * _30;
  int _32 = 0;
  _30 = malloc(_24 * sizeof(*_30));
  int _23, _20;
  for (_23 = 0; _23 < _24; _23++) {
    int _21 = 0;
    for (_20 = 0; _20 < _38; _20++) {
      if (strcmp(_22[_23], (_36[_20])->_26) == 0) {
        _21 = 1;
        break;
      }
    }
    if (_21 == 0) {
      _30[_32] = _22[_23];
      _32++;
    }
  }
  char * * _40;
  int _39 = 0;
  _40 = malloc(_24 * sizeof(*_40));
  while (_32 > 0) {
    qsort(_30, _32, sizeof(_30[0]), _25);
    _40[_39] = _30[_32 - 1];
    _39++;
    _32--;
    int * _34;
    int _33 = 0;
    _34 = malloc(_38 * sizeof(int));
    int _31;
    for (_31 = 0; _31 < _38; _31++) {
      if (strcmp((_36[_31])->_28, _40[_39 - 1]) != 0) {
        continue;
      }
      _34[_33] = _31;
      _33++;
      int _29 = 0;
      int _27;
      for (_27 = 0; _27 < _38; _27++) {
        if (strcmp(_36[_27]->_26, _36[_31]->_26) == 0 && strcmp(_36[_27]->_28, _36[_31]->_28) != 0) {
          _29 = 1;
          break;
        }
      }
      if (_29 == 0) {
        _30[_32] = _36[_31]->_26;
        _32++;
      }
    }
    int _35;
    for (_35 = _33 - 1; _35 >= 0; _35--) {
      int _37;
      for (_37 = _34[_35] + 1; _37 <= _38 - 1; _37++) {
        _36[_37 - 1] = _36[_37];
      }
      _38--;
    }
  }
  if (_38 == 0) {
    int _41;
    for (_41 = 0; _41 < _39; _41++) {
      printf(_40[_41]);
    }
  }
  else {
    printf("cycle\n");
  }
  return 0;
}
