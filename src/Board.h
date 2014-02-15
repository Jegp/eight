#ifndef BOARD_H
#define BOARD_H

#include <SDL/SDL.h>

struct Board { 

  int fields[3][3];

  SDL_Surface* text;
  TTF_Font* font;

Board() : font(TTF_OpenFont("sans-serif", 40)){
    for (int x = 0; x < 3; x++)
      for (int y = 0; y < 3; y++)
	fields[x][y] = x + y * 3;
  }

  void moveMouse(int x, int y);
  
  void moveField(int x, int y);

  void render(SDL_Surface* screen);

  void swap(int x1, int y1, int x2, int y2);

};

#endif
