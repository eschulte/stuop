#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _1 {
  char * _4;
  struct _1 * _6;
} ;
char* _10(char **_15, int _16);
int _7(char **_15, int _16, char *_12);
void _14(char **_15, int _16, char **_17, int _18);
int main() {
  struct _1 * _5 = NULL;
  int _16 = 0;
  while (1) {
    char _2[65];
    fgets(_2, sizeof(_2), stdin);
    if (feof(stdin)) break;
    {
      struct _1 * _3 =
        malloc(sizeof(*_3));
      _3 -> _4 = strdup(_2);
      _3 -> _6 = _5;
      _5 = _3;
      _16++;
    }
  }
  {
    char * _12;
    char * * _15;
    char * * _17;
    int _13 = 0;
    int _18 = 0;
    _15 = malloc(_16 * sizeof(*_15));
    _17 = malloc(_16 * sizeof(*_17));
    while (_5 != NULL) {
      _15[_13] = _5->_4;
      _13++;
      _5 = _5->_6;
    }
    _14(_15, _16, _17, _18);
    for (_13 = 0; _13 < _18; _13++) {
      printf("%s", _17[_13]);
    }
  }
  return 0;
}
int _7(char **_15, int _16, char *_12) {
  int _13;
  int _7 = 0;
  if (!_12) return -1;
  for (_13 = 1; _13 < _16; _13 += 2) {
    if (!_15[_13]) continue;
    if (!strcmp(_15[_13], _12) && _15[_13-1] != NULL)
      _7++;
  }
  return _7;
}
char* _10(char **_15, int _16) {
  int _9;
  int _13 = 0;
  char * _8 = NULL;
  for (_13 = 0; _13 < _16; _13++) {
    if (!_15[_13]) continue;
    if (!_7(_15, _16, _15[_13]) && !_8) {
      _8 = _15[_13];
      continue;
    }
    if (_8) {
      _9 = strcmp(_15[_13], _8);
      if (!_7(_15, _16, _15[_13]) && _9 < 0)
        _8 = _15[_13];
    }
  }
  return _8;
}
void _14(char **_15, int _16, char **_17, int _18) {
  int _9;
  int _13 = 0;
  int _11 = 0;
  char * _12;
  _12 = _10(_15, _16);
  for (_13 = 0; _13 < _16; _13++) {
    if (!_15[_13]) _11++;
  }
  if (_11 == _16) {
    for (_13 = 0; _13 < _18; _13++) {
      printf("%s", _17[_13]);
    }
    return;
  }
  if (!_12 && _11 < _16) {
    printf("cycle\n");
    _18 = 0;
    return;
  }
  _17[_18] = _12;
  _18++;
  for (_13 = 0; _13 < _16; _13++) {
    if (!_12 || !_15[_13]) continue;
    if (!strcmp(_15[_13], _12)) _15[_13] = NULL;
  }
  _14(_15, _16, _17, _18);
}
