#include "board.h"

board *board_init(SDL_Renderer *renderer, const char *filename) {
	board *b = malloc(sizeof(board));
	if(!b) {
		log_err("Failed to allocate board\n");
		return NULL;
	}

	b->renderer = renderer;
	b->tex = IMG_LoadTexture(b->renderer, filename);

	if(b->tex == NULL) {
		log_err("Failed to load board texture\n");
		return NULL;
	}

	return b;
}

void board_draw(board *b) {
	SDL_Rect src_rect;
	SDL_Rect dest_rect;
	SDL_QueryTexture(b->tex, NULL, NULL, &src_rect.w, &src_rect.h);
	dest_rect.w = src_rect.w;
	dest_rect.h = src_rect.h;
	dest_rect.x = (1280/2)-(src_rect.w/2);
	dest_rect.y = (720/2)-(src_rect.h/2);
	SDL_RenderCopy(b->renderer, b->tex,NULL,&dest_rect);
}
