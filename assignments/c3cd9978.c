#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _16 64
struct _28{
  char _6 [_16];
  int _29;
  struct _26 * _27;
  int _20;
};
struct _26{
  struct _28 * _28;
  struct _26 * _34;
};
struct _28 * _2(char * _6){
  struct _28 * _3 = malloc(sizeof(struct _28));
  if(!_3) return _3;
  _3->_20 = 0;
  _3->_29 = 0;
  _3->_27 = NULL;
  strcpy(_3->_6, _6);
}
void _25(struct _26 ** _35, struct _28 * _28){
  struct _26 * _1 = malloc(sizeof(struct _26));
  if(!_1) return;
  _1->_28=_28;
  _1->_34 = *_35;
  *_35 = _1;
}
struct _28 * _18(struct _26 ** _35, char * _6){
  if(!_35) return NULL;
  struct _26 * _32 = *_35;
  struct _28 * _3 = NULL;
  while(_32){
    if(!strcmp(_6, _32->_28->_6)){
      _3 = _32->_28;
      break;
    }
    _32 = _32->_34;
  }
  if(!_3) {
    _3 = _2(_6);
    _25(_35, _3);
  }
  return _3;
}
void _36(struct _26 * _32){
  if(!_32){
    return;
  }
  _36(_32->_34);
  printf("%s", _32->_28->_6);
}
void _5(struct _26 * _32){
  if(!_32){
    printf("\n");
    return;
  }
  while(_32){
    printf("\t\t%p\n", _32->_28);
    _32 = _32->_34;
  }
}
void _4(struct _26 * _32){
  if(!_32){
    printf("null list\n");
    return;
  }
  while(_32){
    printf("%p\n\t%s\t%d\n\t%d\n",
	   _32->_28,
	   _32->_28->_6,
	   _32->_28->_29,
	   _32->_28->_20);
    if(_32->_28->_20){
      printf("\tdependents:\n");
      _5(_32->_28->_27);
      printf("\n");
    }
    _32 = _32->_34;
  }
}
int _11(struct _26 * _35){
  struct _26 *_7 = _35;
  struct _26 *_10 = _35->_34;
  if(!_10) return -1;
  struct _26 *_9 = _10->_34;
  if(!_9) return -1;
  struct _26 *_8 = _9->_34;
  if(strcmp(_10->_28->_6, _9->_28->_6)<0) return 0;
  _7->_34 = _9;
  _10->_34 = _8;
  _9->_34 = _10;
  return 1;
}
int _14(struct _26 * _35){
  int _12 = 0;
  while(1){
    int _13 = _11(_35);
    if(_13 < 0) return _12;
    else _12+=_13;
    _35 = _35->_34;
  }
}
void _24(struct _26 ** _35){
  struct _26 * _15 = malloc(sizeof(struct _26));
  _15->_28 = NULL;
  _15->_34 = *_35;
  while(_14(_15) > 0) {}
  *_35 = _15->_34;
}
int main(){
  struct _26 * _35 = NULL;
  char _17 [_16];
  char _19 [_16];
  int _23 = 0;
  while(1){
    if(!fgets(_17, _16, stdin) || !fgets(_19, _16, stdin))
      break;
    struct _28 * _22= _18(&_35, _17);
    struct _28 * _21= _18(&_35, _19);
    _22->_29++;
    _21->_20++;
    _25(&(_21->_27), _22);
    _23++;
  }
  _24(&_35);
  struct _26 * _33 = malloc(sizeof(struct _26));
  _33->_28 = NULL;
  _33->_34 = _35;
  struct _26 * _37 = NULL;
  int _31 = 1;
  while(_31){
    _31 = 0;
    struct _26 * _32 = _33;
    while(_32->_34){
      struct _26 * _34 = _32->_34;
      if(!(_34->_28->_29)){
	_32->_34 = _34->_34;
	_25(&_37, _34->_28);
	struct _26 * _30 = _34->_28->_27;
	while(_30){
	  _30->_28->_29--;
	  _30 = _30->_34;
	}
	_31 = 1;
	break;
      }
      _32 = _34;
    }
  }
  _35 = _33->_34;
  if(_35)
    printf("cycle\n");
  else{
    _36(_37);
  }
  return 0;
}
