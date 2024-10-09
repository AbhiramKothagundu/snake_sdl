#include "snake.h"

#if 0
//FULLSCREEN
#define WINDOW_X 0
#define WINDOW_Y 0
#define WINDOW_WIDTH 2560
#define WINDOW_HEIGHT 1600

#else
//STREAM
#define WINDOW_X 10
#define WINDOW_Y -20
#define WINDOW_WIDTH 1770
#define WINDOW_HEIGHT 1405
#endif

#define GRID_SIZE 20
#define GRID_DIM 1000

enum {
  SNAKE_UP, SNAKE_DOWN , SNAKE_LEFT , SNAKE_RIGHT
};

struct snake {
  int x;
  int y;
  int dir;
  struct snake *next;
    
};
typedef struct snake Snake;

Snake *head;
Snake *tail;

void init_snake(){
  Snake *new = malloc(sizeof(Snake));
  new->x = rand() % (GRID_SIZE /2) + (GRID_SIZE /4);
  new->y = rand() % (GRID_SIZE /2) + (GRID_SIZE /4);
  new->dir = SNAKE_UP;
  new->next = NULL;

  head = new;
  tail = new;

  return;

}

void increase_snake(){
  Snake *new = malloc(

}

void render_grid(SDL_Renderer *renderer , int x , int y){


  SDL_SetRenderDrawColor(renderer ,0x00 , 0x00 , 0x00 , 255);
  int cell_size = GRID_DIM / GRID_SIZE;
  
  SDL_Rect cell;
  cell.w = cell_size;
  cell.h = cell_size;

  for(int i=0 ; i < GRID_SIZE ; i++) {
    for(int j=0 ; j < GRID_SIZE ; j++){
      cell.x = x + (i * cell_size);
      cell.y = y + (j * cell_size);
      SDL_RenderDrawRect(renderer,&cell);
      
    }
  }
  
  
  return;

}



int main()
{
  SDL_Window *window;
  SDL_Renderer *renderer;

  if(SDL_INIT_VIDEO < 0) {
    fprintf(stderr, "ERROR : SDL_INIT_VIDEO");
  }

  window = SDL_CreateWindow(
			      "Snake",
			      WINDOW_X,
			      WINDOW_Y,
			      WINDOW_WIDTH,
			      WINDOW_HEIGHT,
			      SDL_WINDOW_BORDERLESS
			      );
  
  if(!window) {
    fprintf(stderr , "ERROR : !window" );
  }

  renderer = SDL_CreateRenderer(window , -1, SDL_RENDERER_ACCELERATED);

  if(!renderer) {
    fprintf(stderr , "ERRROR : !renderer");
  }

  int grid_x = (WINDOW_WIDTH / 2) - (GRID_DIM / 2);
  int grid_y = (WINDOW_HEIGHT / 2) - (GRID_DIM / 2);
  

  bool quit = false;
  SDL_Event event;

  while(!quit) {
    while(SDL_PollEvent(&event)) {
      switch(event.type) {
      case SDL_QUIT :
	quit = true;
	break;
      case SDL_KEYUP :
	break;
      case SDL_KEYDOWN:
	switch(event.key.keysym.sym) {
	case SDLK_ESCAPE:
	  quit = true;
	  break;
	}
	break;	
      }      
    }

    SDL_RenderClear(renderer);
    //RENNDER LOOP START

    render_grid(renderer,grid_x,grid_y);

    //RENDER LOOP END
    SDL_SetRenderDrawColor(renderer , 0xff, 0xff,0xff, 255);
    SDL_RenderPresent(renderer);

  }

  

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  

  return 0;

}
