/* A conio implementation for Mingw/Dev-C++.
 * version 1.2
 *
 * Written by:
 * Hongli Lai <hongli@telekabel.nl>
 * tkorrovi <tkorrovi@altavista.net> on 2002/02/26. 
 * Andrew Westcott <ajwestco@users.sourceforge.net>
 * Adrian Sandor <aditsu@yahoo.com> 2004/11/07
 *
 * Offered for use in the public domain without any warranty.
 */

/*
 * mingw conio.h information:
 *
 * Low level console I/O functions. Pretty please try to use the ANSI
 * standard ones if you are writing new code.
 *
 * This file is part of the Mingw32 package.
 *
 * Contributors:
 *  Created by Colin Peters <colin@bird.fu.is.saga-u.ac.jp>
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  This source code is offered for use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * $Revision: 1.4 $
 *
 */
/*  Some of the code below was part of Mingw's conio.h  */

#ifndef _CONIO_H_
#define _CONIO_H_

/* All the headers include this file. */
#include <_mingw.h>

#ifndef RC_INVOKED

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
} COLORS;

#define BLINK 0
#define _NOCURSOR 0
#define _SOLIDCURSOR 100
#define _NORMALCURSOR 25

/* console info */

typedef struct
{
	unsigned char winleft, wintop, winright, winbottom,
	 attribute, normattr, currmode, screenheight, screenwidth, curx, cury;
} text_info;

typedef struct
{
	int left, top, right, bottom, width, height, totalwidth, totalheight,
	 maxwidth, maxheight, attr, cx, cy;
} con_info;

/* conio functions defined in msvcrt */

char* _cgets (char*);
int _cprintf (const char*, ...);
int _cputs (const char*);
int _cscanf (char*, ...);
int _getch ();
int _getche ();
int _kbhit ();
int _putch (int);
int _ungetch (int);

#define cgets	_cgets
#define cprintf	_cprintf
#define cputs	_cputs
#define cscanf	_cscanf

int	getch ();
int	getche ();
int	kbhit ();
int	putch (int);
int	ungetch (int);

/* other conio functions */

void clrscr();
void clreol();
void gotoxy(int x, int y);
int wherex();
int wherey();
void textattr(int attr);
void textbackground(int color);
void textcolor(int color);

void insline();
void delline();

/* 1.2: workaround for a gcc issue with the gettext identifier */
int _gettext(int left, int top, int right, int bottom, void*buf);
#define gettext _gettext
int puttext(int left, int top, int right, int bottom, void*buf);
int movetext(int left, int top, int right, int bottom, int newleft, int newtop);

void gettextinfo(text_info *r);
void _setcursortype(int type);

/* delay functions; they were originally in dos.h */

void delay(unsigned msec);
void sleep(unsigned sec);

/* new useful functions; all of them use 0-based coordinates */

void con_wherexy(int*x, int*y);
void con_gotoxy(int x, int y);

void con_getinfo(con_info*inf);
void con_setwindow(int left, int top, int right, int bottom);
void con_resize(int width, int height);
void con_setbuffer(int width, int height);
void con_crop();
void con_settitle(const char*str);

void con_fillchar(char c, int n, int x, int y);
void con_fillattr(int fg, int bg, int n, int x, int y);
void con_fill(char c, int fg, int bg, int n, int x, int y);
void con_fillcr(char c, int n, int x, int y);

int con_get(int left, int top, int right, int bottom, void*buf);
int con_put(int left, int top, int right, int bottom, void*buf);
int con_getchars(int left, int top, int right, int bottom, char *str);
int con_putchars(int left, int top, int right, int bottom, char *str);
int con_getattrs(int left, int top, int right, int bottom, int*buf);
int con_putattrs(int left, int top, int right, int bottom, int*buf);

void con_scroll(int left, int top, int right, int bottom, int newleft, int newtop);
void con_scrollup(int left, int top, int right, int bottom);
void con_scrolldown(int left, int top, int right, int bottom);
void con_scrollleft(int left, int top, int right, int bottom);
void con_scrollright(int left, int top, int right, int bottom);

/* todo: implement djgpp libc conio functions?
http://www.delorie.com/djgpp/doc/libc/libc_4.html */

#ifdef __cplusplus
}
#endif

#endif	/* Not RC_INVOKED */

#endif	/* Not _CONIO_H_ */

