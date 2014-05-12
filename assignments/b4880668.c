#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {
  false,
  true
} _19;
struct _54 {
  char * _57;
  struct _54 * _58;
};
struct _59 {
  char ** _60;
  int _62;
};
struct _31 {
  struct _42 ** _33;
  int _35;
};
struct _42 {
  char * _38;
  int _45;
  int _41;
  struct _42 * _39[100];
};
struct _66 {
  int _30;
  struct _42 * _21[1000];
};
void _13 (struct _42 * _47, char * _4);
void _8(struct _42 * _6, struct _42 * _5);
void _10(struct _42 * _47);
void _44(struct _42 * _47);
void _7 (struct _66 * _68);
void _14 (struct _66 * _68, struct _42 * _47);
void _15 (struct _66 * _68, struct _42 * _16, struct _42 * _17);
void _12 (struct _66 * _68, char ** _60, int _62);
struct _31 * _32 (struct _66 * _68);
int _20 (struct _66 * _68, struct _42 * _47);
void _37 (struct _66 * _68, struct _42 * _47);
_19 _67 (struct _66 * _68);
struct _42 ** _36 (struct _42 ** _33, int _48);
struct _42 ** _46 (struct _42 ** _33, struct _42 * _47, int _48);
int _50(const void *_25, const void *_26);
struct _59 * _29 (struct _66 * _68);
struct _59 * _53 ();
void _65 (struct _66 * _68, char ** _70, int _69);
int main(int _1, char const *_2[]) {
  struct _66 * _68 = malloc(sizeof(*_68));
  struct _59 * _52 = _53();
  char ** _60 = _52 -> _60;
  int _62 = _52 -> _62;
  _12(_68, _60, _62);
  struct _59 * _3 = _29(_68);
  char ** _70 = _3 -> _60;
  int _69 = _3 -> _62;
  _65(_68, _70, _69);
  free(_68);
  free(_52);
  free(_3);
  free(_60);
  free(_70);
  return 0;
}
void _13 (struct _42 * _47, char * _4) {
  _47 -> _38 = _4;
  _47 -> _45 = 0;
  _47 -> _41 = 0;
}
void _8(struct _42 * _6, struct _42 * _5) {
  _6 -> _39[_6 -> _41] = _5;
  _6 -> _41++;
}
void _10(struct _42 * _47) {
  _47 -> _45++;
}
void _44(struct _42 * _47) {
  _47 -> _45--;
}
void _7 (struct _66 * _68) {
  _68 -> _30 = 0;
}
void _14 (struct _66 * _68, struct _42 * _47) {
  if (_20(_68, _47) == -1) {
    _68 -> _21[_68 -> _30] = _47;
    _68 -> _30++;
  }
}
void _15 (struct _66 * _68, struct _42 * _16, struct _42 * _17) {
  int _11 = _20(_68, _16);
  int _9 = _20(_68, _17);
  _8(_68 -> _21[_9], _68 -> _21[_11]);
  _10(_68 -> _21[_11]);
}
void _12 (struct _66 * _68, char ** _60, int _62) {
  int _71 = 0;
  while (_71 < _62 - 1) {
    if (_71 % 2 == 0) {
      struct _42 * _16 = malloc(sizeof(*_16));
      struct _42 * _17 = malloc(sizeof(*_17));
      _13(_16, _60[_71+1]);
      _13(_17, _60[_71]);
      _14(_68, _16);
      _14(_68, _17);
      _15(_68, _16, _17);
    }
    _71++;
  }
}
struct _31 * _32 (struct _66 * _68) {
  struct _42 ** _49 = malloc(_68 -> _30 * sizeof(*_49));
  int _18 = 0;
  int _71 = 0;
  while (_71 < _68 -> _30) {
    if (_68 -> _21[_71] -> _45 == 0) {
      _49[_18] = _68 -> _21[_71];
      _18++;
    }
    _71++;
  }
  struct _31 * _34 = malloc(sizeof(*_34));
  _34 -> _33 = _49;
  _34 -> _35 = _18;
  return _34;
}
int _20 (struct _66 * _68, struct _42 * _47) {
  int _71 = 0;
  while (_71 < _68 -> _30) {
    if (strcmp(_68 -> _21[_71] -> _38, _47 -> _38) == 0) {
      return _71;
    }
    _71++;
  }
  return -1;
}
_19 _67 (struct _66 * _68) {
  if (_68 -> _30 == 0)
    return true;
  return false;
}
void _37 (struct _66 * _68, struct _42 * _47) {
  int index = _20(_68, _47);
  while (index < _68 -> _30 - 1) {
    _68 -> _21[index] = _68 -> _21[index+1];
    index++;
  }
  _68 -> _30--;
}
struct _42 ** _36 (struct _42 ** _33, int _48) {
  int _23 = _48;
  struct _42 ** _70 = malloc((_23 - 1) * sizeof(*_70));
  int _71 = 0;
  while (_71 < _23-1) {
    _70[_71] = _33[_71+1];
    _71++;
  }
  return _70;
}
struct _42 ** _46 (struct _42 ** _33, struct _42 * _47, int _48) {
  int _23 = _48;
  int _22 = 0;
  struct _42 ** _24 = malloc((_23 + 1) * sizeof(*_24));
  int _71 = 0;
  while (_71 < _23) {
    _24[_71] = _33[_71];
    _71++;
  }
  _24[_23] = _47;
  return _24;
}
int _50(const void *_25, const void *_26) {
  struct _42 * _27 = * (struct _42 **)_25;
  struct _42 * _28 = * (struct _42 **)_26;
  return strcmp(_27 -> _38, _28 -> _38);
}
struct _59 * _29 (struct _66 * _68) {
  char ** _70 = malloc(_68 -> _30 * sizeof(*_70));
  int _51 = 0;
  struct _31 * _34 = _32(_68);
  struct _42 ** _49 = _34 -> _33;
  int _48 = _34 -> _35;
  qsort(_49, _48, sizeof(_49[0]), _50);
  while (_48 != 0) {
    struct _42 * _40 = _49[0];
    _49 = _36(_49, _48);
    _37(_68, _40);
    _48--;
    _70[_51] = _40 -> _38;
    _51++;
    struct _42 ** _43 = _40 -> _39;
    int _71 = 0;
    while (_71 < _40 -> _41) {
      struct _42 * _47 = _43[_71];
      _44(_47);
      if (_47 -> _45 == 0) {
        _49 = _46(_49, _47, _48);
        _48++;
      }
      _71++;
    }
    qsort(_49, _48, sizeof(_49[0]), _50);
  }
  struct _59 * _52 = malloc(sizeof(*_52));
  _52 -> _60 = _70;
  _52 -> _62 = _51 + 1;
  return _52;
}
struct _59 * _53() {
  struct _54 * _60 = NULL;
  int _63 = 0;
  char ** _61;
  while (true) {
    char _55[80];
    fgets(_55, sizeof(_55), stdin);
    if (feof(stdin))
      break;
    struct _54 * _56 = malloc(sizeof(*_56));
    _56 -> _57 = strdup(_55);
    _56 -> _58 = _60;
    _60 = _56;
    _63++;
  }
  int _71 = 0;
  _61 = malloc(_63 * sizeof(*_61));
  while (_60 != NULL) {
    _61[_71] = _60 -> _57;
    _60 = _60->_58;
    _71++;
  }
  struct _59 * _64 = malloc(sizeof(*_64));
  _64 -> _60 = _61;
  _64 -> _62 = _63;
  return _64;
}
void _65 (struct _66 * _68, char ** _70, int _69) {
  if (_67(_68) == false)
    printf("cycle\n");
  else {
    int _71 = 0;
    while (_71 < _69-1) {
      printf("%s", _70[_71]);
      _71++;
    }
  }
}
