#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct _16 {
  char * _25;
  struct _16 * _27;
  struct _16 * _7;
} _16;
struct _29 {
  struct _16 * _18;
  struct _16 * _11;
};
void _30 (char * _32, struct _29 * _2)
{
  if(_2->_18 == NULL)
    {
      _2->_18 = (struct _16 *)malloc(sizeof(struct _16));
      _2->_11 = _2->_18;
      _2->_18->_25 = malloc(8*strlen(_32));
      strcpy(_2->_18->_25, _32);
    }
  else
    {
      _2->_11->_27 = (struct _16 *)malloc(sizeof(struct _16));
      _2->_11->_27->_7 = _2->_11;
      _2->_11 = _2->_11->_27;
      _2->_11->_25 = malloc(8*strlen(_32));
      strcpy(_2->_11->_25, _32);
    }
}
void _1 (struct _16 * _4)
{
  if (_4 != NULL)
    {
      printf("%s\n", _4->_25);
      _1(_4->_27);
    }
}
void _37 (struct _29 * _2)
{
  if (_2->_18 != NULL)
    _1(_2->_18);
}
void _31 (char * _32, struct _29 * _2)
{
  if (_2->_18 == NULL)
    _30(_32, _2);
  else if (strcmp(_32, _2->_18->_25) < 0)
    {
      _2->_18->_7 = (struct _16 *)malloc(sizeof(struct _16));
      _2->_18->_7->_27 = _2->_18;
      _2->_18 = _2->_18->_7;
      _2->_18->_25 = malloc(8*strlen(_32));
      strcpy(_2->_18->_25, _32);
    }
  else if (strcmp(_32, _2->_18->_25) != 0)
    {
      struct _16 * _26 = _2->_18->_27;
      while(1)
        {
          if (_26 == NULL)
            {
              _30(_32, _2);
              break;
            }
          else
            if (strcmp(_32, _26->_25)==0)
              break;
            else if (strcmp(_32, _26->_25) < 0)
              {
                _26->_7->_27 = (struct _16 *)malloc(sizeof(struct _16));
                _26->_7->_27->_7 = _26->_7;
                _26->_7 = _26->_7->_27;
                _26->_7->_27 = _26;
                _26->_7->_25 = malloc(8*strlen(_32));
                strcpy(_26->_7->_25, _32);
                break;
              }
            else
              _26 = _26->_27;
        }
    }
}
struct _6 {
  char * _8;
  int * _12;
  struct _6 * _27;
  struct _6 * _7;
} _6;
struct _28 {
  struct _6 * _18;
  struct _6 * _11;
};
int _3 (char * _9, struct _6 * _4)
{
  if (_4 != NULL)
    {
      if (strcmp(_4->_8, _9) != 0)
        return _3(_9, _4->_27);
      else if (strcmp(_4->_8, _9) == 0)
        return *(_4->_12);
    }
  else
    return 0;
}
int _24 (char * _9, struct _28 * _10)
{
  if (_10->_18 != NULL)
    return _3(_9, _10->_18);
  else
    return 0;
}
void _5(char * _9, int _13, struct _6 * _4)
{
  if ((_4 != NULL) && (strcmp(_4->_8, _9) != 0))
    _5(_9, _13, _4->_27);
  else if (_4 != NULL)
    *(_4->_12) = _13;
}
void _22(char * _9, int _13, struct _28 * _10)
{
  if (_24(_9, _10))
    _5(_9, _13, _10->_18);
  else
    {
      if(_10->_18 == NULL)
        {
          _10->_18 = (struct _6 *)malloc(sizeof(struct _6));
          _10->_11 = _10->_18;
          _10->_18->_8 = malloc(8*strlen(_9));
          _10->_18->_12 = malloc(sizeof(int));
          strcpy(_10->_18->_8, _9);
          *(_10->_18->_12) = _13;
        }
      else
        {
          _10->_11->_27 = (struct _6 *)malloc(sizeof(struct _6));
          _10->_11->_27->_7 = _10->_11;
          _10->_11 = _10->_11->_27;
          _10->_11->_8 = malloc(8*strlen(_9));
          strcpy(_10->_11->_8, _9);
          _10->_11->_12 = malloc(sizeof(int));
          *(_10->_11->_12) = _13;
        }
    }
}
void _19(char * _14, struct _29 * _21, struct _29 * _20)
{
  int _15 = 0;
  struct _16 * _26 = _21->_18;
  while(_26 != NULL)
    {
      if (!(_15%2))
        if ( strcmp(_26->_25,_14)==0 )
          _31(_26->_27->_25, _20);
      _26 = _26->_27;
      _15 = _15 + 1;
    }
}
void _33(struct _29 * _17, struct _29 * _21, struct _28 * _36, struct _29 * _23)
{
  struct _16 * _26 = _17->_18;
  while(_26 != NULL)
    {
      if (!_24(_26->_25, _36))
        {
          _22(_26->_25, 1, _36);
          struct _29 * _20 = (struct _29 *)malloc(sizeof(struct _29));
          _19(_26->_25, _21, _20);
          _33(_20, _21, _36, _23);
          _22(_26->_25, 2, _36);
          _30(_26->_25, _23);
        }
      else if (_24(_26->_25, _36) == 1)
        {
          printf("cycle\n");
          exit(0);
        }
      _26 = _26->_27;
    }
}
int main()
{
  char _32[100];
  struct _29 * _35 = (struct _29 *)malloc(sizeof(struct _29));
  struct _29 * _34 = (struct _29 *)malloc(sizeof(struct _29));
  struct _28 * _36 = (struct _28 *)malloc(sizeof(struct _28));
  struct _29 * _38 = (struct _29 *)malloc(sizeof(struct _29));
  while (fgets(_32, 99, stdin) != NULL)
    {
      if(_32[strlen(_32)-1]=='\n')
        _32[strlen(_32) - 1] = '\0';
      _30(_32, _35);
      _31(_32, _34);
    }
  _33(_34, _35, _36, _38);
  _37(_38);
}
