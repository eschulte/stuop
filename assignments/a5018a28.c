#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _1 1
#define _2 0
typedef struct _19 {
  char * _21;
  struct _19 * _32;
} _19;
typedef struct _18 {
  char * _16;
  struct _18 * _32;
  int _30;
  struct _19 *  _20;
} _18;
typedef struct _26 {
  char * _28;
  int _30;
  struct _26 * _32;
} _26;
void _14(_18 * _27, char * _29);
void _15(_18 * _27, char * _29, char * _22);
void _17(_18 * _27, char * _22);
void _25(_26 * _27, char * _29);
int _33(const void * _34, const void * _35);
int main(void) {
  _18 * _12 = malloc( sizeof(*_12) );
  _12->_16 = "No task; bookend";
  _12->_32 = NULL;
  _12->_20 = NULL;
  _12->_30 = 100;
  while (_1) {
    char _4[70];
    char _5[70];
    fgets(_4, sizeof(_4), stdin);
    if(feof(stdin)) {
      break;
    }
    fgets(_5, sizeof(_5), stdin);
    char *_3;
    if ((_3=strchr(_4, '\n')) != NULL)
      *_3 = '\0';
    _3 = NULL;
    if ((_3=strchr(_4, '\r')) != NULL)
      *_3 = '\0';
    _3 = NULL;
    if ((_3=strchr(_5, '\n')) != NULL)
      *_3 = '\0';
    _3 = NULL;
    if ((_3=strchr(_5, '\r')) != NULL)
      *_3 = '\0';
    _14(_12, _4);
    _15(_12, _4, _5);
    _14(_12, _5);
  }
  _26 * _9 = malloc( sizeof(*_9) );
  _9->_28 = "No contents; bookend";
  _9->_32 = NULL;
  _9->_30 = 0;
  _26 * _13 = malloc( sizeof(*_13) );
  _13->_28 = "No contents; bookend";
  _13->_32 = NULL;
  _13->_30 = 0;
  while (_1) {
    _18 * _7 = _12->_32;
    _18 * _6 = _12;
    while(_7 != NULL) {
      if(_7->_30 == 0) {
        _25(_9, _7->_16);
        _6->_32 = _7->_32;
        free(_7);
        _7 = _6->_32;
      }
      else {
        _6 = _7;
        _7 = _7->_32;
      }
    }
    if(_9->_30 == 0) {
      break;
    }
    char ** _11 = malloc(_9->_30 * sizeof(*_11));
    _26 * _31 = _9->_32;
    int _8 = 0;
    while(_31 != NULL) {
      _11[_8] = _31->_28;
      _31 = _31->_32;
      ++_8;
    }
    qsort(_11, _9->_30, sizeof(_11[0]), _33);
    _25(_13, _11[0]);
    _9->_30 -= 1;
    _17(_12, _11[0]);
    _26 * _10 = _9->_32;
    _26 * _23 = _9;
    while(_10 != NULL) {
      if(strcmp(_11[0], _10->_28) == 0) {
        _23->_32 = _10->_32;
        free(_10);
        break;
      }
      _23 = _10;
      _10 = _10->_32;
    }
    free(_11);
  }
  if(_12->_32 != NULL) {
    printf("cycle\n");
    return 0;
  }
  _13 = _13->_32;
  while(_13 != NULL) {
    printf("%s\n", _13->_28);
    _13 = _13->_32;
  }
  return 0;
}
void _14(_18 * _27, char * _29) {
  _18 * _31 = _27;
  while(_31->_32 != NULL) {
    if(strcmp(_31->_32->_16, _29) == 0) {
      return;
    }
    _31 = _31->_32;
  }
  _31->_32 = malloc( sizeof(*_31) );
  _31 = _31->_32;
  _31->_16 = strdup(_29);
  _31->_30 = 0;
  _31->_32 = NULL;
  _31->_20 = NULL;
}
void _15(_18 * _27, char * _29, char * _22) {
  _18 * _31 = _27->_32;
  while(_31 != NULL) {
    if(strcmp(_31->_16, _29) == 0) {
      _31->_30 += 1;
      _19 * _24 = _31->_20;
      if(_24 == NULL) {
        _31->_20 = malloc( sizeof(*(_31->_20)) );
        _24 = _31->_20;
      }
      else {
        while(_24->_32 != NULL) {
          if(strcmp(_24->_21, _22) == 0) {
            return;
          }
          _24 = _24->_32;
        }
        _24->_32 = malloc( sizeof(*_24) );
        _24 = _24->_32;
      }
      _24->_21 = strdup(_22);
      _24->_32 = NULL;
      break;
    }
    _31 = _31->_32;
  }
}
void _17(_18 * _27, char * _22) {
  _18 * _31 = _27->_32;
  while(_31 != NULL) {
    if(_31->_20 != NULL) {
      _19 * _24 = _31->_20;
      _19 * _23 = _31->_20;
      while(_24 != NULL) {
        if(strcmp(_24->_21, _22) == 0) {
          _31->_30 -= 1;
          _23->_32 = _24->_32;
          break;
        }
        else {
          _23 = _24;
          _24 = _24->_32;
        }
      }
    }
    _31 = _31->_32;
  }
}
void _25(_26 * _27, char * _29) {
  _27->_30 += 1;
  _26 * _31 = _27->_32;
  if(_31 == NULL) {
    _27->_32 = malloc( sizeof(*(_27->_32)) );
    _31 = _27->_32;
    _31->_28 = strdup(_29);
    _31->_30 = 0;
    _31->_32 = NULL;
  }
  else {
    while(_31->_32 != NULL) {
      _31 = _31->_32;
    }
    _31->_32 = malloc( sizeof(*(_31->_32)) );
    _31 = _31->_32;
    _31->_28 = strdup(_29);
    _31->_30 = 0;
    _31->_32 = NULL;
  }
}
int _33(const void * _34, const void * _35) {
  char * _36 = * (char * *)_34;
  char * _37 = * (char * *)_35;
  return strcmp(_36, _37);
}
