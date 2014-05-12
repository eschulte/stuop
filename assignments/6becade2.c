#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _1 {
  char * _5;
  struct _1 * _7;
};
struct _25 {
  char * _17;
  char * _28;
};
int _15(const char * * _23, int * _22);
int _30(const void *_36, const void *_33);
int _34(const char *_36, char * * _37, size_t _35);
int _24( const char * _36,
         struct _25 * _27,
         int _26);
int _16 (   const char * _36,
            struct _25 ** _27,
            int * _26,
            const char * * _23,
            int * _22);
int main(){
  struct _1 * _6 = NULL;
  int _4 = 0;
  while (1) {
    char _2[80];
    fgets(_2, sizeof(_2), stdin);
    if (feof(stdin)) break;
    {
      struct _1 * _3 = malloc(sizeof(*_3));
      _3 -> _5 = strdup(_2);
      _3 -> _7 = _6;
      _6 = _3;
      _4++;
    }
  }
  char * * _37;
  char * * _12;
  const char * * _14;
  const char * * _23;
  struct _25 * _27;
  int _38 = 0;
  int _9 = 0;
  int _11 = 0;
  int _26 = _4/2;
  int _22 = 0;
  _37 = malloc(_4 * sizeof(*_37));
  _12 = malloc(_4 * sizeof(*_12));
  _27 = malloc(_26 * sizeof(*_27));
  while (_6 != NULL){
    _37[_38] = _6 -> _5;
    _38++;
    _6 = _6 -> _7;
  }
  for (_9 = 0; _9 < _38; _9++){
    int _8 = _34(_37[_9], _12, _11);
    if (_8 == 1) {
      _12[_11] = _37[_9];
      _11++;
    }
  }
  _23 = malloc(_11 * sizeof(*_23));
  _14 = malloc(_11 * sizeof(*_14));
  for (_38 = 0; _38 < _26; _38++){
    struct _25 * _10 = malloc(sizeof(*_10));
    _10 -> _28   = _37[(_38*2)+1];
    _10 -> _17  = _37[(_38*2)];
    _27[_38] = *_10;
  }
  for (_38 = 0; _38 < _11; _38++){
    if (_24(_12[_38], _27, _26) == 1){
      _23[_22] = _12[_38];
      _22++;
      qsort(_23, _22, sizeof(_23[0]), _30);
    }
  }
  int _13 = 0;
  while (_22 > 0){
    const char * _18 = _23[0];
    _15(_23, &_22);
    _14[_13] = _18;
    _13++;
    _16(_18, &_27, &_26, _23, &_22);
  }
  if (_26 > 0){
    printf("cycle\n");
  }
  else{
    for (_38 = 0; _38 < _13; _38++){
      printf("%s", _14[_38]);
    }
  }
  return 0;
}
int _15(const char * * _23, int * _22){
  int _38 = 0;
  for (_38 = 0; _38 < (*_22)-1; _38++){
    _23[_38] = _23[_38+1];
  }
  _23[(*_22)-1] = NULL;
  *_22 = *_22-1;
}
int _16 (   const char * _36,
            struct _25 ** _27,
            int * _26,
            const char * * _23,
            int * _22){
  int _38 = 0;
  int _19 = 0;
  int _20 = 0;
  struct _25 * _18;
  char * * _21;
  _18 = malloc(*_26 * sizeof(*_18));
  _21 = malloc(*_26 * sizeof(*_21));
  for (_38 = 0; _38 < *_26; _38++){
    if (strcmp(_36, (*_27)[_38]._17) != 0){
      _18[_19] = (*_27)[_38];
      _19++;
    }
    else{
      _21[_20] = (*_27)[_38]._28;
      _20++;
    }
  }
  *_27 = _18;
  *_26 = _19;
  for (_38 = 0; _38 < _20; _38++){
    if (_24(_21[_38], *_27, *_26) == 1){
      _23[*_22] = _21[_38];
      (*_22)++;
      qsort(_23, *_22, sizeof(_23[0]), _30);
    }
  }
  return 1;
}
int _24( const char * _36,
         struct _25 * _27,
         int _26 ){
  int _29 = 1;
  int _38 = 0;
  for (_38 = 0; _38 < _26; _38++){
    if (strcmp(_36, _27[_38]._28) == 0){
      _29 = 0;
    }
  }
  if (_29 == 1){ return 1; }
  else { return 0; }
}
int _30(const void *_31, const void *_32){
  char * _36 = * (char * *)_31;
  char * _33 = * (char * *)_32;
  return strcmp(_36,_33);
}
int _34(const char *_36, char * * _37, size_t _35){
  int _38 = 0;
  if (_35 == 0){
    return 1;
  }
  else{
    for (_38 = 0; _38 < _35; _38++){
      if (strcmp(_36, _37[_38]) == 0){
        return 0;
      }
    }
    return 1;
  }
}
