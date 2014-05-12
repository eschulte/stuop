#define _21 10
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct _33 {
  unsigned int index;
  struct _33 *_35;
} _33;
void _22(char*** _29, size_t* _28, size_t* _23)
{
  size_t _1 = 0;
  while (true) {
    char *_2 = NULL;
    if (getline(&_2, &_1, stdin) == -1)
      break;
    if (*_28 >= *_23) {
      *_23 *= 2;
      *_29 = (char**) realloc(*_29, (*_23)*sizeof(*_29));
      if (!(*_29)) {
        printf("Realloc failure");
        exit(EXIT_FAILURE);
      }
    }
    (*_29)[(*_28)++] = _2;
  }
}
_33* _9(unsigned int index) {
  _33* _3 = (_33*) malloc(sizeof(_33));
  _3->index = index;
  _3->_35 = NULL;
  return _3;
}
void _11(_33** _37, char* _4, char* _6,
         char** _30, size_t _31)
{
  unsigned int _5;
  for (_5 = 0; _5 < _31; _5++)
    if (!strcmp(_30[_5], _4))
      break;
  unsigned int _8;
  for (_8 = 0; _8 < _31; _8++) {
    if (!_37[_8]) {
      _37[_8] = _9(_5);
      break;
    }
    if (_37[_8]->index == _5)
      break;
  }
  unsigned int _10;
  for (_10 = 0; _10 < _31; _10++)
    if (!strcmp(_30[_10], _6))
      break;
  unsigned int _7;
  for (_7 = 0; _7 < _31; _7++) {
    if (!_37[_7]) {
      _37[_7] = _9(_10);
      break;
    }
    if (_37[_7]->index == _10)
      break;
  }
  _33* _34 = _37[_8];
  while (_34) {
    if (_34->index == _10)
      break;
    if (!_34->_35) {
      _34->_35 = _9(_10);
      break;
    }
    _34 = _34->_35;
  }
}
void _25(_33** _37, char** _30, size_t _31,
         char** _29, size_t _28)
{
  unsigned int _32;
  for (_32 = 0; _32 < _28-1; _32+=2) {
    _11(_37, _29[_32+1], _29[_32],
        _30, _31);
  }
}
void _14(int* _19, _33** _37, size_t _31)
{
  unsigned int _32;
  for (_32 = 0; _32 < _31; _32++) {
    _33* _34 = _37[_32]->_35;
    while (_34) {
      _19[_34->index]++;
      _34 = _34->_35;
    }
  }
}
int _15(const void *_13, const void *_12)
{
  return strcmp(*(char**) _12, *(char**) _13);
}
void _26(char** _38, size_t* _27,
         _33** _37, size_t _31,
         char** _30)
{
  int* _19 = calloc(_31, sizeof(int));
  _14(_19, _37, _31);
  char* _17[_31];
  size_t _18 = 0;
  unsigned int _32;
  for (_32 = 0; _32 < _31; _32++)
    if (_19[_32] == 0)
      _17[_18++] = _30[_32];
  while (_18 > 0) {
    qsort(_17, _18, sizeof(char*), _15);
    char* _16 = _17[--_18];
    _38[(*_27)++] = _16;
    for (_32 = 0; _32 < _31; _32++) {
      unsigned int index = _37[_32]->index;
      if (!strcmp(_30[index], _16))
        break;
    }
    _33* _34 = _37[_32]->_35;
    while(_34) {
      if (--_19[_34->index] == 0)
        _17[_18++] = _30[_34->index];
      _34 = _34->_35;
    }
  }
  free(_19);
}
void _24(char** _30, size_t* _31,
         char** _29, size_t _28)
{
  unsigned int _32;
  for (_32 = 0; _32 < _28; _32++) {
    unsigned int _20;
    for (_20 = 0; _20 < *_31; _20++) {
      if (!strcmp(_29[_32], _30[_20]))
        break;
    }
    if (_20 == *_31)
      _30[(*_31)++] = _29[_32];
  }
}
int main()
{
  size_t _23 = _21;
  char** _29 = (char**) malloc(_23*sizeof(char*));
  size_t _28 = 0;
  _22(&_29, &_28, &_23);
  char** _30 = (char**) malloc(_23*sizeof(char*));
  size_t _31 = 0;
  _24(_30, &_31, _29, _28);
  _33** _37 = (_33**) calloc(_31, sizeof(_33*));
  _25(_37, _30, _31, _29, _28);
  char** _38;
  size_t _27 = 0;
  _38 = (char**) malloc(_31*sizeof(char*));
  _26(_38, &_27,
      _37, _31, _30);
  unsigned int _32;
  if (_27 != _31)
    printf("cycle\n");
  else
    for (_32 = 0; _32 < _31; _32++)
      printf("%s", _38[_32]);
  for (_32 = 0; _32 < _28; _32++)
    free(_29[_32]);
  free(_29);
  free(_30);
  for (_32 = 0; _32 < _31; _32++) {
    _33* _34 = _37[_32];
    while (_34) {
      _33* _36 = _34;
      _34 = _34->_35;
      free(_36);
    }
  }
  free(_37);
  free(_38);
  return 0;
}
