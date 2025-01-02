#include <canvas.h>
#include <ncurses.h>

const char CHAR_BY_LIGHTNESS[] = " .,--==*$@";


bool key_pressed(void) {
  return getch() != ERR;
}


void init_cnv(int *width, int *height) {
  initscr();
  noecho();  // n'affiche pas les entrées de l'utilisateur
  cbreak();
  keypad(stdscr, TRUE); // Activer la lecture des touches spéciales
  nodelay(stdscr, TRUE);// Activer le mode non bloquant pour getch
  *width = getmaxx(stdscr);  // récupère la taille de l'écran
  *height = getmaxy(stdscr);
}

void update_cnv(pixel_t pixel_buffer, int width, int height) {
  int i = 0;
  for(int y=0; y<height; y++) {
    for(int x=0; x<width; x++) {
      mvaddch(y, x, CHAR_BY_LIGHTNESS[pixel_buffer[i]]);
      i++;
    }
  }

  refresh();
}

void end_cnv(void) {
  endwin();
}
