#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "tinyfiledialogs.h"
#include "button.h"

#define WIN_WIDTH    800
#define WIN_HEIGHT   600

/*
void handleButtonClick() {
    char const* filters[] = {"*.png", "*.jpg", "*.bmp"};
    char const* fileFilters[2] = {filters, NULL};
    char const* filePath = tinyfd_openFileDialog("Select an image", NULL, 1, fileFilters, NULL, 0);

    if (filePath) {
        SDL_Surface* surface = IMG_Load(filePath);
        if (surface) {
            // Create texture from surface
            texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_FreeSurface(surface);
        }
    }
}
*/

int main(int argc, char **argv)
{
	// Initializes sdl & sdl image w/ error check
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		fprintf(stderr, "sdl failed whoops %s\n", SDL_GetError());
		return 1;
	}
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) < 0)
	{
		fprintf(stderr, "sdl image failed whoops\n");
		return 1;
	}
	
	SDL_Window *win;
	const char *win_name = "Image To Stripe Converter";
	if ((win = SDL_CreateWindow(win_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN)) == NULL)
	{
		SDL_Quit();
		fprintf(stderr, "window is fail uhh %s\n", SDL_GetError());
		return 1;
	}
	
	SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	
	initButton(renderer);
	
	SDL_Event e;
	bool quit = false;
	while (!quit)
	{ 
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type) 
			{
				case SDL_QUIT:
					quit = true;
					break;
			}
			
			if (handleButton(&e, renderer)) 
			{
			// Button clicked, handle the event
			}

		}
		
		// Initialize renderer color white for the background
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
		
		renderButton(renderer);

        // Update screen
        SDL_RenderPresent(renderer);
	}
	
	SDL_DestroyWindow(win);
	SDL_Quit();
	IMG_Quit();
	exit(0);
	
	return 0;
}
