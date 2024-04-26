#ifndef BUTTON_H
#define BUTTON_H

#include <stdio.h>  
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

void initButton(SDL_Renderer* renderer);

int handleButton(SDL_Event* event, SDL_Renderer* renderer);

void renderButton(SDL_Renderer* renderer);

#endif