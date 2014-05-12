#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _39 {
  char * _41;
  struct _39 * _44;
  struct _39 * _22;
} ;
struct _12{
  int _41;
  struct _12 *_44;
};
void _29(struct _39 *_40);
int _38(const char * _42, const struct _39 * _40);
int _33(const void *_37, const void *_36);
int _24(char * * _26, int _25, char * _27);
int main() {
  struct _39 * _5 = NULL;
  struct _39 * _4 = NULL;
  struct _39 * _18 = NULL;
  struct _39 * _23 = NULL;
  int _2 = 0;
  int _19 = 0;
  while (1) {
    char _1[80];
    fgets(_1, sizeof(_1), stdin);
    if (feof(stdin)) break;
    {
      struct _39 * _10 =
        malloc(sizeof(*_10));
      _10 -> _41 = strdup(_1);
      if( _38(_10 -> _41, _4) == 0
          && _38(_10->_41, _5)==0){
        _19++;
      }
      if( _2 % 2 == 0 ){
	if (_5 != NULL){
	  _5 -> _22 = _10;
	}
	_10 -> _44 = _5;
      	_5 = _10;
      }
      else{
	_10 -> _44 = _4;
	if(_4 != NULL){
	  _4 -> _22 = _10;
	}
	_4 = _10;
      }
      _2++;
    }
  }
  {
    struct _39 * _3 = _4;
    while(_3){
      if(_38(_3->_41, _5) == 0 &&
         _38(_3->_41, _18) == 0){
        struct _39 * _10 =
          malloc(sizeof(*_10));
        _10 -> _41 = _3->_41;
        _10 -> _44 = _18;
        if(_18!= NULL){
          _18 -> _22 = _10;
        }
        _18 = _10;
      }
      _3 = _3->_44;
    }
    _29(_18);
  }
  int * _20  = (int*) malloc (sizeof(*_20) * _19);
  char * * _14 = malloc(sizeof(*_14) * _19);
  struct _12 * * _13 = malloc(sizeof(*_13) * _19);
  int _28 = 0;
  struct _39 * _8 = _4;
  struct _39 * _9 = _5;
  while(_8){
    int index = _24(_14, _28, _8->_41);
    if(index == -1){
      _14[_28] = _8->_41;
      _28++;
    }
    index = _24(_14, _28, _9->_41);
    if(index == -1){
      _14[_28] = _9->_41;
      _28++;
    }
    _8 = _8-> _44;
    _9 = _9-> _44;
  }
  _8 = _4;
  _9 = _5;
  while(_8){
    int index = _24(_14, _28, _9->_41);
    _20[index] += 1;
    int _7 = _24(_14, _19, _8->_41);
    int _6 = _24(_14, _19, _9->_41);
    struct _12 * _10 = malloc(sizeof(*_10));
    _10 -> _41 = _6;
    _10 -> _44 = _13[_7];
    _13[_7] = _10;
    _8 = _8-> _44;
    _9 = _9-> _44;
  }
  while(_18 != NULL){
    char * _11 = _18 -> _41;
    _18 = _18->_44;
    struct _39 * _10 =
      malloc(sizeof(*_10));
    _10 -> _41 = _11;
    _10 -> _22 = _23;
    if( _23 != NULL){
      _23->_44 = _10;
      _23 = _23-> _44;
    }
    else{
      _23 = _10;
    }
    int index = _24(_14, _19, _11);
    struct _12 * _17 = _13[index];
    while(_17 != NULL){
      int _15 = _17->_41;
      _20[_15] -= 1;
      if (_20[_15] == 0){
        struct _39 * _16 = malloc(sizeof(*_16));
        _16 -> _41 = _14[_15];
        _16 -> _44 = _18;
        if (_18 != NULL){ _18-> _22 = _16; }
        _18 = _16;
      }
      _17 = _17->_44;
    }
    _29(_18);
  }
  int _21 = 1;
  for(_28 = 0; _28 < _19; _28++){
    if (_20[_28] > 0){
      _21 = -1;
      printf("cycle\n");
      break;
    }
  }
  if(_21 == 1){
    while (_23->_22 != NULL){
      _23 = _23 -> _22;
    }
    while(_23 != NULL){
      printf("%s", _23->_41);
      _23 = _23->_44;
    }
  }
  return 0;
}
int _24(char ** _26, int _25, char * _27){
  int _28;
  for(_28 = 0; _28 < _25; _28++){
    if(strcmp(_26[_28], _27) == 0){
      return _28;
    }
  }
  return -1;
}
void _29(struct _39 *_40){
  struct _39 * _32 = _40;
  while(_32 != NULL){
    struct _39 * _31 = _32-> _44;
    while(_31 != NULL){
      if(strcmp(_32->_41, _31->_41) > 0){
        char *_30 = _31->_41;
        _31-> _41 = _32 -> _41;
        _32-> _41 = _30;
      }
      _31 = _31->_44;
    }
    _32 = _32->_44;
  }
}
int _33(const void *_34, const void *_35) {
  char * _37 = * (char * *)_34;
  char * _36 = * (char * *)_35;
  return strcmp(_36,_37);
}
int _38(const char * _42, const struct _39 * _40){
  struct _39 * _43 = _40;
  while(_43){
    if(strcmp(_43->_41, _42) == 0){
      return 1;
    }
    _43 = _43->_44;
  }
  return 0;
}
