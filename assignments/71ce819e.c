#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct _19
{
  struct _17* _11;
  struct _19* _22;
};
struct _17
{
  char* _23;
  int _12;
  struct _19* _18;
  struct _17* _26;
};
struct _7
{
  char* _23;
  struct _7* _22;
};
int main()
{
  struct _17* _25 = NULL;
  while(1)
    {
      char _1[65];
      fgets(_1, sizeof(_1), stdin);
      if(feof(stdin))
        {
          break;
        }
      char _2[65];
      fgets(_2, sizeof(_2), stdin);
      struct _17* _3 = NULL;
      struct _17* _4 = NULL;
      struct _17* _6 = _25;
      while(_6)
        {
          if(!strcmp(_6->_23, _1))
            {
              _3 = _6;
            }
          if(!strcmp(_6->_23, _2))
            {
              _4 = _6;
            }
          _6 = _6->_26;
        }
      if(!_3)
        {
          _3 = malloc(sizeof(*_3));
          _3->_23 = strdup(_1);
          _3->_12 = 0;
          _3->_18 = NULL;
          _3->_26 = _25;
          _25 = _3;
        }
      if(!_4)
        {
          _4 = malloc(sizeof(*_4));
          _4->_23 = strdup(_2);
          _4->_12 = 0;
          _4->_18 = NULL;
          _4->_26 = _25;
          _25 = _4;
        }
      _3->_12++;
      struct _19* _5 = malloc(sizeof(*_5));
      _5->_11 = _3;
      _5->_22 = _4->_18;
      _4->_18 = _5;
    }
  int _13 = 0;
  int _14 = 0;
  struct _7* _16 = malloc(sizeof(*_16));
  struct _7* _15 = _16;
  while(!_13)
    {
      struct _17* _6 = _25;
      char* _8 = NULL;
      struct _17* _10 = NULL;
      _13 = 1;
      while(_6)
        {
          if(_6->_12 >= 0)
            {
              _13 = 0;
            }
          if(_6->_12 == 0)
            {
              if(!_10 || strcmp(_8, _6->_23) > 0)
                {
                  _10 = _6;
                  _8 = _6->_23;
                }
            }
          _6 = _6->_26;
        }
      if(_10)
        {
          _10->_12 = -1;
          struct _7* _9 = malloc(sizeof(*_9));
          _9->_22 = NULL;
          _9->_23 = strdup(_8);
          _15->_22 = _9;
          _15 = _9;
          struct _19* _18 = _10->_18;
          while(_18)
            {
              _18->_11->_12--;;
              _18 = _18->_22;
            }
        }
      else if(!_13)
        {
          _14 = 1;
          _13 = 1;
        }
    }
  if(_14)
    {
      printf("cycle\r\n");
    }
  else
    {
      _15 = _16->_22;
      while(_15)
        {
          printf("%s", _15->_23);
          _15 = _15->_22;
        }
    }
  _15 = _16->_22;
  while(_15)
    {
      free(_16->_23);
      free(_16);
      _16 = _15;
      _15 = _16->_22;
    }
  struct _17* _24 = _25->_26;
  while(_24)
    {
      struct _19* _21 = _24->_18;
      if(_21)
        {
          struct _19* _20 = _21->_22;
          while(_20)
            {
              free(_21);
              _21 = _20;
              _20 = _21->_22;
            }
        }
      free(_25->_23);
      free(_25);
      _25 = _24;
      _24 = _25->_26;
    }
  return 0;
}
