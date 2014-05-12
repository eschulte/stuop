#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int _30(const void *_31,const void *_32);
struct _12 {
  char *_17;
  struct _12 * _22;
};
struct _6 {
  char *_18;
  int _20;
  struct _12 * _14;
  int _15;
  int _13;
};
int main() {
  struct _12 * _2 = NULL;
  int _3 = 0;
  while (1) {
    char _1[80];
    fgets(_1, sizeof(_1), stdin);
    if (feof(stdin))
      break;
    {
      struct _12 *_9 = malloc(sizeof(*_9));
      _9->_17 = strdup(_1);
      _9->_22 = _2;
      _2 = _9;
      _3++;
    }
  }
  {
    char ** _29;
    int _25 = _3 - 1;
    int _23 = 0;
    _29 = malloc(_3 * sizeof(*_29));
    while (_2 != NULL) {
      _29[_25] = _2->_17;
      _25--;
      _2 = _2->_22;
    }
    {
      struct _6 ** _28;
      int _24 = 0;
      int _16 = 0;
      _28 = malloc(_3 * sizeof(*_28));
      char * _4 = NULL;
      char * _7 = NULL;
      for (_16 = 0; _16 < _3; _16 += 2) {
        _4 = _29[_16];
        _7 = _29[_16 + 1];
        struct _6 * _33 = NULL;
        struct _6 * _34 = NULL;
        for (_25 = 0; _25 < _24; _25++) {
          if (strcmp(_28[_25]->_18, _4) == 0) {
            _33 = _28[_25];
            _28[_25]->_20++;
            break;
          }
        }
        if (_33 == NULL) {
          struct _6 * _5 = malloc(sizeof(*_5));
          _5->_20 = 1;
          _5->_18 = _4;
          _5->_15 = 0;
          _5->_13 = 0;
          _28[_24] = _5;
          _33 = _5;
          _24++;
        }
        for (_25 = 0; _25 < _24; _25++) {
          if (strcmp(_28[_25]->_18, _7) == 0) {
            _34 = _28[_25];
            break;
          }
        }
        if (_34 == NULL) {
          struct _6 * _8 = malloc(sizeof(*_8));
          _8->_20 = 0;
          _8->_18 = _7;
          _8->_15 = 0;
          _8->_13 = 0;
          _28[_24] = _8;
          _34 = _8;
          _24++;
        }
        struct _12 *_9 = malloc(sizeof(*_9));
        _9->_17 = _33->_18;
        _9->_22 = _34->_14;
        _34->_14 = _9;
        _34->_15++;
      }
      {
        char ** _27;
        char ** _26;
        _26 = malloc(_24 * sizeof(*_26));
        _27 = malloc(_24 * sizeof(*_27));
        int _11 = 0;
        int _10 = 0;
        while (_10 < _24) {
          for (_25 = 0; _25 < _24; _25++) {
            if (_28[_25]->_13 == 0 && _28[_25]->_20 == 0) {
              _27[_11] = _28[_25]->_18;
              _11++;
            }
          }
          if (_11 == 0) {
            _23 = 1;
            break;
          }
          else {
            qsort(_27,_11,sizeof(_27[0]),_30);
            int _19 = 0;
            _26[_10] = _27[0];
            _10++;
            _11 = 0;
            for (_25 = 0; _25 < _24; _25++) {
              struct _12 * _21;
              if (strcmp(_27[0], _28[_25]->_18) == 0) {
                _28[_25]->_13 = 1;
                _21 = _28[_25]->_14;
                for (_16 = 0; _16 < _28[_25]->_15; _16++) {
                  for (_19 = 0; _19 < _24; _19++) {
                    if (strcmp(_21->_17,
                               _28[_19]->_18) == 0) {
                      _28[_19]->_20--;
                      break;
                    }
                  }
                  _21 = _21->_22;
                }
                break;
              }
            }
          }
        }
        if (_23 == 1) {
          printf("cycle");
        } else {
          for (_25 = 0; _25 < _24; _25++) {
            printf("%s", _26[_25]);
          }
        }
        free(_26);
        free(_27);
      }
      free(_28);
      free(_29);
    }
  }
  return 0;
}
int _30(const void *_31,const void *_32) {
  char * _33 = *(char **)_31;
  char * _34 = *(char**)_32;
  return strcmp(_33,_34);
}
