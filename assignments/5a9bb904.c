#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct _1 {
  char * _4;
  struct _1 * _6;
};
int _41(const void *_44, const void *_45);
int main() {
  struct _1 * _5 = NULL;
  int _27 = 0;
  while (1) {
    char _2[80];
    fgets(_2, sizeof(_2), stdin);
    if (feof(stdin)) break;
    {
      struct _1 * _3 =
        malloc(sizeof(*_3));
      _3 -> _4 = strdup(_2);
      _3 -> _6 = _5;
      _5 = _3;
      _27++;
    }
  }
  char * * _11;
  int _12 = _27-1;
  _11 = malloc(_27 * sizeof(*_11));
  while (_5 != NULL) {
    _11[_12] = _5->_4;
    _12--;
    _5 = _5->_6;
  }
  char * _25[_27][_27];
  int _7, _8;
  for (_7 = 0; _7 < _27; _7++) {
    for(_8 = 0; _8 < _27; _8 ++) _25[_7][_8] = "fuck";
  }
  char * _33[_27][2];
  int _9,_10;
  for (_9 = 0; _9 < _27; _9++) {
    for (_10 = 0; _10 < 2; _10++) _33[_9][_10] = "fuck";
  }
  int _16;
  _16 = 0;
  int _35;
  _35 = 0;
  for (_12=0; _12<_27; _12 = _12+2) {
    char * _20;
    _20 = _11[_12];
    char * _23;
    _23 = _11[_12+1];
    int _15;
    bool _17;
    _17 = false;
    bool _13;
    _13 = false;
    int index;
    index = -1;
    for (_15 = 0; _15 < _27; _15++) {
      if (strcmp(_25[_15][0], _23) == 0) {
        _13 = true;
        index = _15;
      }
    }
    if (_13) {
      bool _14;
      _14 = false;
      for (_15=1; _15<_27; _15++) {
        if (strcmp(_25[index][_15], _20) == 0) {
          _14 = true;
          _17 = true;
          break;
        }
      }
      if (_14 == false) {
        for (_15 = 1; _15< _27; _15++) {
          if (strcmp(_25[index][_15], "fuck") == 0) {
            _25[index][_15] = _20;
            break;
          }
        }
      }
    }
    else {
      _25[_16][0] = _23;
      _25[_16][1] = _20;
      _16++;
    }
    if (_17 == false) {
      bool _18;
      _18 = false;
      int _21;
      for (_21=0; _21 < _27; _21++) {
        if (strcmp(_33[_21][0], _20) == 0) {
          _18 = true;
          break;
        }
      }
      if (_18 == true) {
        char _19[100];
        strcpy(_19, _33[_21][1]);
        int _30;
        _30 = 0;
        _30 = atoi(_19);
        _30++;
        char _32[15];
        sprintf(_32, "%d", _30);
        _33[_21][1] = _32;
      }
      else {
        _33[_35][0] = _20;
        _33[_35][1] = "1";
        _35++;
      }
      bool _22;
      _22 = false;
      for (_21=0; _21 < _27; _21++) {
        if (strcmp(_33[_21][0], _23) == 0) {
          _22 = true;
        }
      }
      if (_22 == false) {
        _33[_35][0] = _23;
        _33[_35][1] = "0";
        _35++;
      }
    }
  }
  char**_39;
  _39 = malloc(_27 * sizeof(*_39));
  int _38;
  _38 = 0;
  bool _37;
  _37 = false;
  while (_35 != 0) {
    char * * _36;
    int index;
    _36 = malloc(_35 * sizeof(*_36));
    for (index=0; index<_27; index++) {
      _36[index] = "zzzzz";
    }
    int _24;
    _24 = 0;
    for (index=0; index<_27; index++) {
      if (strcmp(_33[index][1], "0") == 0) {
        _36[_24] = _33[index][0];
        _24++;
      }
    }
    qsort(_36, _24, sizeof(_36[0]), _41);
    int _26;
    _26 = 0;
    for (index=0; index < _27; index++ ) {
      if (strcmp(_25[index][0],_36[0]) == 0) {
        _26 = index;
        break;
      }
    }
    int _34;
    _34 = 0;
    for (index=0; index < _27; index++ ) {
      if (strcmp(_33[index][0],_36[0]) == 0) {
        _34= index;
        break;
      }
    }
    int _31;
    for (index=1; index < _27; index++ ) {
      if (strcmp(_25[_26][index], "fuck") == 0) {
        break;
      }
      else {
        char _28[256];
        strcpy(_28, _25[_26][index]);
        for (_31=0; _31<_27; _31++) {
          if (strcmp(_28, _33[_31][0]) == 0) {
            char _29[100];
            strcpy(_29, _33[_31][1]);
            int _30;
            _30 = atoi(_29);
            _30--;
            char _32[10];
            sprintf(_32, "%d", _30);
            _33[_31][1] = _32;
            break;
          }
        }
      }
    }
    _39[_38] = _36[0];
    _38++;
    _33[_34][0] = "removed";
    _33[_34][1] = "1000";
    _35--;
    if (strcmp(_36[0],"zzzzz") == 0) {
      printf("cycle\n");
      _37 = true;
      break;
    }
  }
  if (_37 != true) {
    int _40;
    _40 = 0;
    for (_40=0; _40<_38; _40++) {
      printf("%s", _39[_40]);
    }
  }
  return 0;
}
int _41(const void *_42, const void *_43) {
  char * _44 = * (char * *)_42;
  char * _45 = * (char * *)_43;
  return strcmp(_44,_45);
}
