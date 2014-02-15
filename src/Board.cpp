#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>

#include "Board.h"

void Board::swap(int x1, int y1, int x2, int y2) {
  int tmp = fields[x2][y2];
  fields[x2][y2] = fields[x1][y1];
  fields[x1][y1] = tmp;
}

void Board::moveMouse(int x, int y) {
  moveField(x / 100, y / 100);
}

void Board::moveField(int x, int y) {
  // Examine for vacant horizontal spot
  if (x > 0 && fields[x - 1][y] == 0) swap(x, y, x - 1, y);
  if (x < 2 && fields[x + 1][y] == 0) swap(x, y, x + 1, y);

  // Look for vacant vertical slot
  if (y > 0 && fields[x][y - 1] == 0) swap(x, y, x, y - 1);
  if (y < 2 && fields[x][y + 1] == 0) swap(x, y, x, y + 1);  
}

void Board::render(SDL_Surface* screen) {

  int color_background = SDL_MapRGB(screen->format, 200, 200, 200);
  SDL_Color color = {0x00, 0x00, 0x00, 0xff};

  // Draw text
  SDL_Rect rect;

  char* content;

  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      int square_x = 100 * x + 30;
      int square_y = 100 * y + 30;
      int value = fields[x][y];
      if (value > 0) {
	sprintf(content, "%d", value);
	rect = (SDL_Rect) { square_x - 20, square_y - 20, 70, 80 };
	SDL_FillRect(screen, &rect, color_background);
      } else {
	content[0] = '\0';
      }
      text = TTF_RenderText_Solid(font, content, color);
      rect = (SDL_Rect) { square_x, square_y, 50, 50};
      SDL_BlitSurface(text, NULL, screen, &rect);
    }
  }

  // Free memory
  SDL_FreeSurface(text);
  
}
