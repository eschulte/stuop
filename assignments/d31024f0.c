#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _24 {
  char * _25;
  struct _24 * _27;
};
struct _30 {
  struct _30 * _34;
  char * _26;
  struct _24 * _31;
};
void _10 (struct _24 * _33);
int _11(struct _24* _33, char * _12);
void _14(struct _24* _33, char * _16);
struct _30* _17(struct _30* _33, char * _13);
void _19(struct _24* _33, char * _13);
struct _24 * _15(struct _30* _33, char * _16);
void _22(struct _30* _33, struct _24* _23, int _18, char* _21);
struct _24 * _29(struct _30* _33);
int _35(const void *_36, const void *_37);
int _32(struct _30* _33);
int main() {
  struct _24 * _23 = NULL;
  int _2 = 0;
  while(1) {
    char _1[80];
    fgets(_1, sizeof(_1), stdin);
    if (feof(stdin)) break;
    {
      struct _24 * _8 = malloc(sizeof(*_8));
      _8 -> _25 = strdup(_1);
      _8 -> _27 = _23;
      _23 = _8;
      _2 ++;
    }
  }
  struct _30 * _9 = NULL;
  if(_2 > 0) {
    _9 = malloc(sizeof(*_9));
    _9->_34 = NULL;
    _9->_31 = NULL;
    _9->_26 = _23->_25;
    _22(_9, _23, 0, NULL);
  }
  struct _24 * _6 = _29(_9);
  int _5 = 0;
  char ** _4 = malloc(_2 * sizeof(*_4));
  while(_6 != NULL) {
    _4[_5] = _6->_25;
    _5++;
    _6 = _6->_27;
  }
  struct _24 * _28 = NULL;
  while(_5 > 0) {
    qsort(_4, _5, sizeof(_4[0]), _35);
    _5 --;
    char* _7 = _4[0];
    int _3;
    for(_3 = 0; _3 < _5 + 1; _3++) {
      _4[_3] = _4[_3 + 1];
    }
    _6 = _15(_9, _7);
    while(_6 != NULL) {
      _4[_5] = _6->_25;
      _5++;
      _6 = _6->_27;
    }
    struct _24 * _8 = malloc(sizeof(*_8));
    _8 -> _25 = strdup(_7);
    _8 -> _27 = _28;
    _28 = _8;
  }
  if(_32(_9)) {
    printf("cycle");
  } else {
    _10(_28);
  }
}
void _10 (struct _24 * _33) {
  if(_33 == NULL) {
    return;
  }
  if(_33->_27 != NULL) {
    _10(_33->_27);
  }
  printf ("%s", _33->_25);
}
int _11(struct _24* _33, char * _12) {
  if(_33 == NULL) {
    return 0;
  }
  if(strcmp(_33->_25, _12)) {
    return 1;
  }
  return _11(_33->_27, _12);
}
void _19(struct _24* _33, char * _13) {
  if(strcmp(_33->_25, _13) == 0) {
    return;
  }
  if(_33->_27 == NULL) {
    _33->_27 = malloc(sizeof(struct _24));
    _33->_27->_27 = NULL;
    _33->_27->_25 = strdup(_13);
  } else {
    _19(_33->_27, _13);
  }
}
struct _30* _17(struct _30* _33, char * _13) {
  if(strcmp(_33->_26, _13) == 0) {
    return _33;
  }
  if(_33->_34 == NULL) {
    _33->_34 = malloc(sizeof(struct _30));
    _33->_34->_34 = NULL;
    _33->_34->_31 = NULL;
    _33->_34->_26 = strdup(_13);
    return _33->_34;
  } else {
    return _17(_33->_34, _13);
  }
}
void _14(struct _24* _33, char * _16) {
  if(_33->_27 == NULL) {
    return;
  }
  if(strcmp(_33->_27->_25, _16) == 0) {
    _33->_27 = _33->_27->_27;
  } else {
    _14(_33->_27, _16);
  }
}
struct _24 * _15(struct _30* _33, char * _16) {
  if(_33 == NULL) {
    return NULL;
  }
  if(_33->_31 != NULL) {
    if(strcmp(_33->_31->_25, _16) == 0) {
      _33->_31 = _33->_31->_27;
    } else {
      _14(_33->_31, _16);
    }
    if(_33->_31 == NULL) {
      struct _24 * _28 = malloc(sizeof(struct _24));
      _28->_25 = _33->_26;
      _28->_27 = _15(_33->_34, _16);
      return _28;
    }
  }
  return _15(_33->_34, _16);
}
void _22(struct _30* _33, struct _24* _23, int _18, char* _21) {
  if(_23 == NULL) {
    return;
  }
  struct _30* _20 = _17(_33, _23->_25);
  if(_18) {
    if(_20->_31 == NULL) {
      _20->_31 = (struct _24*) malloc(sizeof(struct _24));
      _20->_31->_25 = strdup(_21);
      _20->_31->_27 = NULL;
    } else {
      _19(_20->_31, _21);
    }
    _22(_33, _23->_27, 0, _23->_25);
  } else {
    _22(_33, _23->_27, 1, _23->_25);
  }
}
struct _24 * _29(struct _30* _33) {
  if(_33 == NULL) {
    return NULL;
  }
  if(_33->_31 == NULL) {
    struct _24 * _28 = malloc(sizeof(struct _24));
    _28->_25 = _33->_26;
    _28->_27 = _29(_33->_34);
    return _28;
  }
  return _29(_33->_34);
}
int _32(struct _30* _33) {
  if(_33 == NULL) {
    return 0;
  }
  if(_33->_31 != NULL) {
    return 1;
  }
  return _32(_33->_34);
}
int _35(const void *_36, const void *_37) {
  char * _38 = * (char * *)_36;
  char * _39 = * (char * *)_37;
  return strcmp(_38,_39);
}
