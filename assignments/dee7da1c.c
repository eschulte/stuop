#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#define _17 62
#define _1 1024
typedef int _24;
#define _2 1
#define _3 0
typedef struct _38 {
  char _46[61];
  char _39[61];
} _38;
typedef struct _50 {
  void* _53;
  struct _50* _56;
} _50;
typedef struct _58 {
  _50* _52;
} _58;
_58* _34() {
  _58* _4 = (_58*)malloc(sizeof(_58));
  _4->_52 = NULL;
  return _4;
}
_50* _6(void* _53) {
  _50* _8 = (_50*)malloc(sizeof(_50));
  _8->_53 = _53;
  _8->_56 = NULL;
  return _8;
}
_24 _27(char* _53, _58* _51) {
  _50* _55 = _51->_52;
  char* _54;
  while (_55 != NULL) {
    _54 = (char*)_55->_53;
    if (strcmp(_54, _53) == 0) {
      return _2;
    }
    _55 = _55->_56;
  }
  return _3;
}
void _37(_58* _5) {
  if (_5->_52 == NULL) {
    return;
  }
  _5->_52 = _5->_52->_56;
}
void _20(_58* _58, void* _53) {
  _50* _8 = (_50*)malloc(sizeof(_50));
  _8->_56 = _58->_52;
  _58->_52 = _8;
  _8->_53 = _53;
}
void _36(_58* _58, void* _53) {
  _50* _8 = _6(_53);
  if (_58->_52 == NULL) {
    _58->_52 = _8;
    return;
  }
  _50* _55 = _58->_52;
  while(_55->_56 != NULL) {
    _55 = _55->_56;
  }
  _55->_56 = _8;
}
void _43(_58* _58, char* _53) {
  _50* _8 = _6((void*)_53);
  if (_58->_52 == NULL) {
    _58->_52 = _8;
    return;
  }
  _50** _13 = &(_58->_52);
  _50* _55 = _58->_52;
  while (_55 != NULL) {
    int _7 = strcmp(_53, (char*)(_55->_53));
    if (_7 == 0) {
      return;
    } else if (_7 < 0) {
      *_13 = _8;
      _8->_56 = _55;
      return;
    } else {
      _13 = &(_55->_56);
      _55 = _55->_56;
    }
  }
  *_13 = _8;
}
_24 _11(_38* _9, _38* _10) {
  if (strcmp(_9->_46, _10->_46) == 0) {
    if (strcmp(_9->_39, _10->_39) == 0) {
      return _2;
    }
  }
  return _3;
}
void _41(_58* _31, _38* _12) {
  if (_31->_52 == NULL) {
    return;
  }
  _50** _13 = &(_31->_52);
  _50* _55 = _31->_52;
  while (_55 != NULL) {
    _38* _23 = (_38*)_55->_53;
    if (_11(_12, _23)) {
      *_13 = _55->_56;
      free(_55);
      return;
    }
    _13 = &(_55->_56);
    _55 = _55->_56;
  }
}
void _18(char* _14) {
  int _15 = strcspn(_14, "\n\r");
  _14[_15] = '\0';
}
_58* _57() {
  char _16[_17];
  char _19[_17];
  _58* _31 = _34();
  _38* _23;
  while (1) {
    _23 = (_38*)malloc(sizeof(_38));
    if (fgets((char*)&_16, _17, stdin) != NULL) {
      _18(_16);
      strcpy(_23->_46, _16);
    } else {
      break;
    }
    if (fgets((char*)&_19, _17, stdin)) {
      _18(_19);
      strcpy(_23->_39, _19);
    } else {
      break;
    }
    _20(_31, _23);
  }
  return _31;
}
void _61() {
  printf("cycle\n");
}
void _21(_58* _60) {
  _50* _55 = _60->_52;
  _38* _23;
  while (_55 != NULL) {
    _23 = (_38*)_55->_53;
    printf("Dependent: %s | Dependency: %s\n", _23->_46,
           _23->_39);
    _55 = _55->_56;
  }
}
_58* _30 (_58* _60) {
  _58* _22 = _34();
  _50* _55 = _60->_52;
  _38* _23;
  while (_55 != NULL) {
    _23 = (_38*)_55->_53;
    _43(_22, _23->_39);
    _55 = _55->_56;
  }
  return _22;
}
_58* _25 (_58* _60) {
  _58* _29 = _34();
  _50* _55 = _60->_52;
  _38* _23;
  while (_55 != NULL) {
    _23 = (_38*)_55->_53;
    _43(_29, _23->_46);
    _55 = _55->_56;
  }
  return _29;
}
_24 _42(char* _28, _58* _26) {
  _58* _29 = _25(_26);
  return !_27(_28, _29);
  free(_29);
}
_58* _35(_58* _31) {
  _58* _44 = _34();
  _58* _33 = _30(_31);
  _50* _55 = _33->_52;
  while (_55 != NULL) {
    char* _32 = (char*)_55->_53;
    if (_42(_32, _31)) {
      _43(_44, _32);
    }
    _55 = _55->_56;
  }
  free(_33);
  return _44;
}
_58* _59(_58* _60) {
  _58* _48 = _60;
  _58* _49 = _34();
  _58* _44 = _35(_60);
  while (_44->_52 != NULL) {
    char* _40 = (char*)_44->_52->_53;
    _36(_49, _40);
    _37(_44);
    _50* _47 = _48->_52;
    while (_47 != NULL) {
      _38* _45 = (_38*)_47->_53;
      if (strcmp(_45->_39, _40) == 0) {
        _41(_48, _45);
        if (_42(_45->_46, _48)) {
          _43(_44, _45->_46);
        }
      }
      _47 = _47->_56;
    }
  }
  if (_48->_52 != NULL) {
    return NULL;
  } else {
    return _49;
  }
}
void _62(_58* _51) {
  _50* _55 = _51->_52;
  char* _54;
  while (_55 != NULL) {
    _54 = (char*)_55->_53;
    printf("%s\n", _54);
    _55 = _55->_56;
  }
}
int main() {
  _58* _60 = _57();
  _58* _63 = _59(_60);
  if (_63 == NULL) {
    _61();
  } else {
    _62(_63);
  }
  return 0;
}
