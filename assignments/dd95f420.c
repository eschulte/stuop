#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct _19 {
  char *_26;
  struct _19 *_31;
};
struct _28 {
  char *_26;
  struct _28 *_31;
  struct _19 *_20;
  struct _28 *_16;
  int _24;
  int _22;
};
struct _28 *_29;
struct _28 *_1;
int _18 = 0;
bool _33 = true;
bool _2(struct _28 *_3, const char *_4) {
  struct _28 * _15 = _29;
  bool _5 = false;
  while (_15 != NULL) {
    if (strcmp(_15->_26, _4))
      {
        _5 = true;
        break;
      }
    _15 = _15->_31;
  }
  return _5;
}
void _27() {
  int _6 = 0;
  while(1) {
    char _8[80];
    char _11[80];
    fgets(_8, sizeof(_8), stdin);
    fgets(_11, sizeof(_11), stdin);
    if (feof(stdin)) break;
    struct _28 *_30 = _29;
    int _7 = 0;
    int _10 = 0;
    while(_30) {
      if (strcmp(_30->_26, strdup(_8)) == 0)
        {
          _7 = 1;
          struct _19 *_9 = malloc(sizeof(struct _19));
          if (_9 == NULL)
            {
              printf("Error making dependency graph node");
            }
          _9->_26 = strdup(_11);
          _9->_31 = _30->_20;
          _30->_22 = _30->_22+1;
          _30->_20 = _9;
        }
      if (strcmp(_30->_26, strdup(_11)) == 0)
        {
          _10 = 1;
        }
      _30 = _30->_31;
    }
    if (!_7)
      {
        struct _28 *_12 = malloc(sizeof(struct _28));
        if (_12 == NULL)
          {
            printf("Error making action graph node");
          }
        _12->_26 = strdup(_8);
        _12->_31 = _29;
        _12->_22 = 1;
        _29 = _12;
        struct _19 *_9 = malloc(sizeof(struct _19));
        if (_9 == NULL)
          {
            printf("Error making dependency edge node");
          }
        _9->_26 = strdup(_11);
        _29->_20 = _9;
      }
    if (!_10)
      {
        struct _28 *_12 = malloc(sizeof(struct _28));
        if (_12 == NULL)
          {
            printf("Error making dependency graph node");
          }
        _12->_26 = strdup(_11);
        _12->_31 = _29;
        _12->_22 = 0;
        _29 = _12;
      }
  }
}
struct _28 * _17() {
  struct _28 *_15 = _29;
  struct _28 *_14 = NULL;
  while (_15 != NULL) {
    if (_15->_22 == 0)
      {
        struct _28 *_13 = _15;
        _15->_16 = _14;
        _14 = _15;
      }
    _15 = _15->_31;
  }
  struct _28 *_21 = _14;
  if (_14 != NULL)
    {
      _15 = _14;
      while(_15 != NULL) {
        if (strcmp(_15->_26, _21->_26) < 0)
          {
            _21 = _15;
          }
        _15 = _15->_16;
      }
    }
  return _21;
}
void _32(int _35) {
  int _25;
  for (_25 = 0; _25 < _35; _25++)
    {
      struct _28 *_21 = _17();
      if (_21 == NULL)
        {
          printf("cycle\n");
          _33 = false;
          return;
        }
      _21->_22 = -1;
      _21->_24 = _18;
      _18++;
      struct _28 *_30 = _29;
      while(_30 != NULL) {
        struct _19 *_23 = _30->_20;
        while(_23 != NULL) {
          if (strcmp(_23->_26, _21->_26) == 0)
            {
              _30->_22--;
              break;
            }
          _23 = _23->_31;
        }
        _30 = _30->_31;
      }
    }
}
void _34(int _35) {
  int _25;
  for (_25 = 0; _25 < _35; _25++)
    {
      struct _28 *_30 = _29;
      while(_30) {
        if (_30->_24 == _25)
          {
            printf("%s", _30->_26);
          }
        _30 = _30->_31;
      }
    }
}
int main() {
  _27();
  int _35 = 0;
  struct _28 *_30 = _29;
  while(_30 != NULL) {
    _35++;
    _30 = _30->_31;
  }
  _32(_35);
  if (_33 == true)
    {
      _34(_35);
    }
}
