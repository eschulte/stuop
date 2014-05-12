#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _3 62
#define _1 10
struct _2 {
  char* _37;
  char* _38;
};
struct _41 {
  char* _45;
  struct _41* _50;
  int _43;
};
struct _48 {
  struct _2 _45;
  struct _48* _50;
};
int _31(struct _41* _49, char* _34);
void _35(struct _41* _49);
void _12(struct _41* _49, int _30, struct _48* _20, int _47);
void _18(char** _23, int _30, int* _22, struct _41* _24, int _26, struct _48* _20);
int _32(char** _46, int _42, char* _34);
void _33(struct _41* _49, char* _34);
void _39(char** _46, int _42);
char** _40(struct _41* _49, int _42);
int _52(const void* _53, const void* _54);
int _47(struct _48* _49);
void _36(struct _48* _49);
int main() {
  int _30 = 0;
  int _11 = 0;
  struct _41* _49;
  struct _41* _9;
  struct _48* _20;
  struct _48* _6;
  char* _5;
  char _8[_3];
  while(fgets(_8, _3, stdin)) {
    if(_11 % 2 == 0) {
      _5 = strdup(_8);
    } else if(_11 == 1) {
      _20 = malloc(sizeof(*_20));
      _20->_45._37 = strdup(_8);
      _20->_45._38 = strdup(_5);
      _20->_50 = NULL;
      _6 = _20;
    } else {
      struct _48* _7 = malloc(sizeof(*_7));
      if(_8[strlen(_8) - 1] != '\n') {
        int _4 = strlen(_8);
        _8[_4] = '\n';
        _8[_4 + 1] = '\0';
      }
      _7->_45._37 = strdup(_8);
      _7->_45._38 = strdup(_5);
      _7->_50 = NULL;
      _6->_50 = _7;
      _6 = _7;
    }
    if(_11 == 0) {
      _49 = malloc(sizeof(*_49));
      _49->_45 = strdup(_8);
      _49->_50 = NULL;
      _9 = _49;
      _11++;
      _30++;
    } else if(!_31(_49, _8)) {
      struct _41* _10 = malloc(sizeof(*_10));
      _10->_45 = strdup(_8);
      _10->_50 = NULL;
      _9->_50 = _10;
      _9 = _10;
      _11++;
      _30++;
    } else {
      _11++;
    }
  }
  _12(_49, _30, _20, _11);
  return 0;
}
void _12(struct _41* _49, int _30, struct _48* _20, int _47) {
  char* _23[_30];
  int _22[_30];
  struct _41* _16 = malloc(sizeof(*_16));
  struct _41* _14 = _16;
  int _17 = 0;
  int _44 = 0;
  for(; _44 < _30; _44++) {
    _23[_44] = _49->_45;
    _22[_44] = 0;
    _49 = _49->_50;
    struct _48* _13 = _20;
    while(_13 != NULL) {
      if(strcmp(_13->_45._38, _23[_44]) == 0) {
        _22[_44]++;
      }
      _13 = _13->_50;
    }
    if(_22[_44] == 0) {
      if(_17 == 0) {
        _14->_45 = strdup(_23[_44]);
        _14->_50 = NULL;
        _14->_43 = 0;
      } else {
        struct _41* _15 = malloc(sizeof(*_15));
        _15->_45 = strdup(_23[_44]);
        _15->_50 = NULL;
        _14->_50 = _15;
        _14->_43 = 0;
        _14 = _15;
      }
      _17++;
    }
  }
  if(_17 == 0) {
    printf("cycle\n");
  } else {
    _18(_23, _30, _22, _16, _17, _20);
  }
}
void _18(char** _23, int _30, int* _22, struct _41* _24, int _26, struct _48* _20) {
  char* _29[_30];
  int _28 = 0;
  while(_26 > 0) {
    char** _19 = _40(_24, _26);
    qsort(_19, _26, sizeof(_19[0]), _52);
    char* _21 = strdup(_19[0]);
    _33(_24, _21);
    _26--;
    _29[_28++] = strdup(_21);
    struct _48* _27 = _20;
    while(_27 != NULL) {
      if(strcmp(_27->_45._37, _21) == 0) {
        int index = _32(_23, _30, _27->_45._38);
        if(_22[index] > 0) {
          _22[index]--;
          if(_22[index] == 0) {
            struct _41* _25 = malloc(sizeof(*_25));
            _25->_45 = _23[index];
            _25->_50 = _24;
            _24 = _25;
            _26++;
          }
        }
      }
      _27 = _27->_50;
    }
  }
  if(_28 == _30) {
    _39(_29, _30);
  } else {
    printf("cycle\n");
  }
}
int _31(struct _41* _49, char* _34) {
  while(_49 != NULL) {
    if(strcmp(_49->_45, _34) == 0) {
      return 1;
    } else {
      _49 = _49->_50;
    }
  }
  return 0;
}
int _32(char** _46, int _42, char* _34) {
  int _44 = 0;
  for(; _44 < _42; _44++) {
    if(strcmp(_46[_44], _34) == 0) {
      return _44;
    }
  }
  return -1;
}
void _33(struct _41* _49, char* _34) {
  while(_49 != NULL) {
    if(strcmp(_49->_45, _34) == 0) {
      _49->_43 = 1;
    }
    _49 = _49->_50;
  }
}
void _35(struct _41* _49) {
  while(_49 != NULL) {
    printf("%s", _49->_45);
    _49 = _49->_50;
  }
  printf("finished printing");
}
void _36(struct _48* _49) {
  while(_49 != NULL) {
    printf("Key: %s, Value: %s\n", _49->_45._37, _49->_45._38);
    _49 = _49->_50;
  }
}
void _39(char** _46, int _42) {
  int _44 = 0;
  for(; _44 < _42; _44++) {
    printf("%s", _46[_44]);
  }
}
char** _40(struct _41* _49, int _42) {
  char** _46 = malloc(_42 * sizeof(*_46));
  int _44 = 0;
  while(_49 != NULL) {
    if(_49->_43 == 0) {
      _46[_44++] = _49->_45;
    }
    _49 = _49->_50;
  }
  return _46;
}
int _47(struct _48* _49) {
  int _51 = 0;
  while(_49 != NULL) {
    _49 = _49->_50;
    _51++;
  }
  return _51;
}
int _52(const void* _53, const void* _54) {
  char* _55 = *(char**) _53;
  char* _56 = *(char**) _54;
  return strcmp(_55, _56);
}
