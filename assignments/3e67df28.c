#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _31* _9(struct _31* _17, char* _10);
void _11(struct _31** _17, int _19, int** _14);
struct _31* _22(struct _31* _32);
void _30(struct _31* _32);
struct _31 {
  char* _33;
  int index;
  int _34;
  struct _31 *_36;
};
int main() {
  int _19 = 0;
  struct _31* _1 = NULL;
  struct _31* _32 = NULL;
  while(1){
    char _3[80];
    fgets(_3, 80, stdin);
    if (feof(stdin))  {
      break;
    }
    struct _31 *_2 = malloc(sizeof(struct _31));
    _2->_34 = 0;
    _2->_36 = NULL;
    _19++;
    _2->_33 = strdup(_3);
    if (_1 != NULL) {
      _1->_36 = _2;
      _1 = _2;
    }
    else {
      _1 = _2;
      _32 = _2;
    }
  }
  int** _14 = (int**)malloc(_19 * sizeof(int*));
  int _18;
  for (_18 = 0; _18 < _19; _18++) {
    _14[_18] = (int*)malloc(_19 * sizeof(int));
  }
  struct _31 **_8 = (struct _31**)malloc(_19 * sizeof(struct _31));
  struct _31 *_5 = NULL;
  int _12;
  int _15 = 0;
  for (_12 = 0; _12 < _19; _12+=2) {
    struct _31* _3 = _32;
    _32 = _32->_36;
    struct _31* _4 = _32;
    _32 = _32 ->_36;
    struct _31* _7 = _9(_5, _3->_33);
    if (_7 == NULL) {
      _7 = _3;
      _7 -> index = _15;
      _8[_15] = _7;
      _15++;
      _7 -> _36 = _5;
      _5 = _7;
    }
    struct _31* _6 = _9(_5, _4->_33);
    if (_6 == NULL) {
      _6 = _4;
      _6 -> index = _15;
      _8[_15] = _6;
      _15++;
      _6 -> _36 = _5;
      _5 = _6;
    }
    _14[_6->index][_7->index] = 1;
    _7->_34 = _7->_34+1;
  }
  _11(_8, _15, _14);
  return 0;
}
struct _31* _9(struct _31* _17, char* _10) {
  struct _31* _13 = _17;
  while (_13 != NULL) {
    if (strcmp(_13 -> _33, _10) == 0) {
      return _13;
    }
    _13 = _13 -> _36;
  }
  return NULL;
}
void _11(struct _31** _17, int _19, int** _14) {
  struct _31 *_16 = NULL;
  int _26 = 0;
  char* _20[_19];
  int _12;
  for (_12 = 0; _12 < _19; _12++) {
    struct _31* _13 = _17[_12];
    if (_13->_34 == 0) {
      _13 -> _36 = _16;
      _16 = _13;
    }
  }
  while (_16 != NULL && _26 < _19){
    _16 = _22(_16);
    _20[_26] = _16->_33;
    _26++;
    int _15 = _16->index;
    _16 = _16 -> _36;
    int _18;
    for (_18 = 0; _18 < _19; _18++) {
      if (_14[_15][_18] != 0) {
	_17[_18] -> _34 = _17[_18]->_34-1;
	if (_17[_18] -> _34 == 0) {
	  _17[_18] -> _36 = _16;
	  _16 = _17[_18];
	}
      }
    }
  }
  if (_26 != _19) {
    printf("cycle\n");
  }
  else {
    int _21;
    for (_21= 0; _21 < _26; _21++) {
      printf("%s", _20[_21], _21);
    }
  }
}
struct _31* _22(struct _31* _32) {
  struct _31* _35 = _32;
  int _26 = 0;
  struct _31* _27 = NULL;
  struct _31* _29 = NULL;
  struct _31* _28 = NULL;
  while (_35 != NULL) {
    struct _31* _24 = _28;
    struct _31* _23 = _35;
    _29 = _23;
    while (_23 != NULL) {
      if (strcmp(_23->_33, _29->_33) < 0) {
	_29 = _23;
	_24 = _28;
      }
      _28 = _23;
      _23 = _23 -> _36;
    }
    if (_26 == 0) {
      if (_24 != NULL)
	_24->_36 = _35;
      struct _31 *_25 = _29->_36;
      _29->_36 = _35->_36;
      _35->_36 = _25;
      _32 = _29;
      _26++;
    }
    else {
      _24->_36 = _35;
      struct _31 *_25 = _29->_36;
      _29->_36 = _35->_36;
      _35->_36 = _25;
      _27->_36 = _29;
      _26++;
    }
    _27 = _29;
    _35 = _29 -> _36;
    _28 = _29;
  }
  _29->_36 = NULL;
  return _32;
}
void _30(struct _31* _32) {
  struct _31* _35 = _32;
  while (_35 != NULL) {
    printf("%s %d\n", _35->_33, _35->_34);
    _35 = _35->_36;
  }
}
