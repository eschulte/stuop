#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _17 {
  char * _18;
  int _20;
  int _14;
  struct _17 * _13;
  struct _17 * _22;
} ;
void _16(struct _17 * _18, char* _1);
int _23(const void *_26, const void *_27);
int main() {
  struct _17 * _15 = NULL;
  int _8 = 0;
  while (1) {
    char _2[80];
    fgets(_2, sizeof(_2), stdin);
    if (feof(stdin)) break;
    {
      struct _17 * _3 =
        malloc(sizeof(*_3));
      _3 -> _18 = strdup(_2);
      _3 -> _20 = 0;
      _3 -> _14 = 1 - _8%2;
      _3 -> _22 = _15;
      if(_3 -> _22 != NULL)
	_3 -> _22 -> _13 = _3;
      _15 = _3;
      _8++;
    }
  }
  struct _17 * _18 = _15;
  struct _17 * _4 = _15;
  while(_15 != NULL){
    while(_4 != NULL){
      if(strcmp(_15 -> _18, _4-> _18) == 0){
	_15->_20 += _4->_14;
      }
      _4 = _4->_22;
    }
    _4 = _18;
    _15 = _15 -> _22;
  }
  _15 = _18;
  {
    char * * _5;
    int _7 = 0;
    _5 = malloc(_8 * sizeof(*_5));
    while (_15 != NULL) {
      _5[_7] = _15->_18;
      _7++;
      _15 = _15->_22;
    }
    _15 = _18;
    qsort(_5, _8, sizeof(_5[0]), _23);
    struct _17 * _10 = NULL;
    while(1){
      struct _17 * _12 = _18;
      int _7;
      int _9 = 1;
      for(_7 = 0; _7 < _8; _7++){
	char* _6 = _5[_7];
	_12 = _18;
	while(_12 != NULL && strcmp(_12->_18, _6) != 0){
	  _12 = _12->_22;
	  if(_12 == NULL)
	    break;
	  if(_12->_20 >= 0)
	    _9 = 0;
	}
	if(_12 != NULL && _12->_20 == 0){
	  _7 = 2*_8 + 1;
	  break;
	}
      }
      if(_7 == _8 && _9 == 0){
	printf("cycle");
	return 0;
      }
      if(_9 == 1 || _12 == NULL){
	while(_10->_22 != NULL){
	  _10 = _10 -> _22;
	}
	while(_10 != NULL){
	  printf("%s", _10->_18);
	  _10 = _10 -> _13;
	}
	return 0;
      }
      struct _17 * _11 = malloc(sizeof(*_11));
      _11 -> _18 = _12 -> _18;
      _11 -> _22 = _10;
      if(_11 -> _22 != NULL)
	_11 -> _22 -> _13 = _11;
      _10 = _11;
      _16(_15, _12->_18);
      while(_15 != NULL){
	if(_15->_13 != NULL && strcmp(_12->_18, _15->_13->_18) == 0 && _15 -> _14 == 1){
	  _16(_18, _15->_18);
	}
	_15 = _15 -> _22;
      }
      _15 = _18;
      if(_18 != NULL)
	_15 = _18;
    }
  }
  return 0;
}
void _16(struct _17 * _18, char* _19){
  struct _17 * _21 = _18;
  while(_21 != NULL){
    if(strcmp(_21->_18, _19) == 0)
      _21->_20--;
    _21 = _21->_22;
  }
}
int _23(const void *_24, const void *_25) {
  char * _26 = * (char * *)_24;
  char * _27 = * (char * *)_25;
  return strcmp(_26,_27);
}
