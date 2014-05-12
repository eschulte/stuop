#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _31 {
  char * _33;
  struct _31 * _35;
  struct _31 * _14;
} ;
int _24(struct _31 * _32, const char * _25);
int _21(struct _31 * _32);
int _27(const void *_28, const void *_29);
void _30(struct _31 * _32);
int main() {
  struct _31 * _4 = NULL;
  int _9 = 0;
  char * * _7 = NULL;
  int _8 = 0;
  int _1 = 80;
  while(1) {
    char _2[80];
    fgets(_2, sizeof (_2), stdin);
    if (feof(stdin)) break;
    {
      struct _31 * _3 =
	malloc(sizeof(*_3));
      _3 -> _33 = strdup(_2);
      _3 -> _35 = _4;
      _4 = _3;
      _9++;
    }
  }
  {
    _7 = malloc(_9 * sizeof(*_7));
    while (_4 != NULL) {
      _7[_8] = _4->_33;
      _8++;
      _4 = _4 -> _35;
    }
  }
  char *  _5[_9];
  for (_8 = 0; _8<_9; _8++) {
    _5[_8] = strdup(_7[_8]);
  }
  qsort(_5, _9, sizeof(_5[0]), _27);
  struct _31 * _13  = malloc(sizeof(_13));
  _13 -> _33 = "";
  _13 -> _14 = NULL;
  _13 -> _35 = NULL;
  struct _31 * _18 = _13;
  struct _31 * _10 = _18;
  int _15 = 0;
  for (_8=0;_8<_9;_8++) {
    if (_24(_13, _5[_8]) == 0) {
      _18 -> _33 = strdup(_5[_8]);
      _18 = _18 -> _35;
      _18= malloc(sizeof(struct _31));
      _18 -> _33 = "";
      _18 -> _35 = NULL;
      _18 -> _14 = NULL;
      _10 -> _35 = _18;
      _18 -> _14 = _10;
      _10 = _18;
      _15++;
    }
  }
  struct _31 * _20 = malloc(sizeof(_13));
  _20 -> _33 = "";
  struct _31 * _11 = _20;
  _10 = _11;
  char* _12 = "";
  int _16 = 1;
  int _17 = 0;
  int _6 = _21(_13)+1;
  int _19 = 0;
  while (_21(_20) != _15) {
    if (_21(_13) >= _6) {
      _19 = 1;
      printf("cycle");
      break;
    }
    _6 = _21(_13);
    _18 = _13;
    _17 = 0;
    while (_17<_6) {
      _12 = _18->_33;
      _16 = 1;
      for (_8=1;_8<_9;_8+=2) {
	if (strcmp(_12,_7[_8])==0) {
	  if (_24(_20,_7[_8-1])==0) {
	    _16 = 0;
	    _8 = _9;
	  }
	}
      }
      if (_16 == 1) {
	_11->_33 = strdup(_12);
	_11 = _11->_35;
	_11 = malloc(sizeof(struct _31));
	_11->_33 = "";
	_11->_35 = NULL;
	_10->_35 = _11;
	_11->_14 = _10;
	_10 = _11;
	while(strcmp(_18->_33, _12)!=0) {
	  _18 = _18->_35;
	}
	if (_18->_14 == NULL) {
	  _13 = _18->_35;
	  _13->_14 = NULL;
	  free(_18);
	}
	else if (_18->_35 == NULL){
	  _18->_14->_35 = NULL;
	  free(_18);
	}
	else {
	  _18->_14->_35 = _18->_35;
	  _18->_35->_14 = _18->_14;
	  free(_18);
	}
	_17 = _15+100;
      }
      else if (_16 == 0){
	_17++;
	_18 = _18->_35;
      }
      else {
	printf("There has been an error\n");
	break;
      }
    }
  }
  if (_19 == 0) {
    _30(_20);
  }
  return 0;
}
int _21(struct _31 * _32) {
  struct _31 * _22 = _32;
  int _23 = 0;
  while (_22 != NULL) {
    _23++;
    _22 = _22-> _35;
  }
  return _23-1;
}
int _24(struct _31 * _32, const char * _25) {
  struct _31 * _26 = _32;
  while (_26 != NULL) {
    if (strcmp(_26 -> _33, _25) == 0) return 1;
    _26 = _26 -> _35;
  }
  return 0;
}
int _27(const void *_28, const void *_29) {
  return strcmp(*((char**) _28), *((char**) _29));
}
void _30(struct _31 * _32) {
  struct _31 * _34 = _32;
  while (_34 != NULL) {
    printf("%s",_34->_33);
    _34 = _34->_35;
  }
}
