#include "dep.h"

int main(int argc, char **argv)
{
    int continuer = 1, press = 0;
    SDL_Surface *ecran = NULL, *zozor = NULL, *sapin;
    SDL_Rect positionZozor, positinsapin;
    SDL_Event event;
    Objet perso;
    initialiser(&perso);

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_WM_SetCaption("deplacement perso", NULL);


    SDL_BlitSurface(perso.img, NULL, ecran, &perso.pos);

    SDL_EnableKeyRepeat(10, 10);
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_UP: // Flèche haut
                perso.pos.y -= 2;
                break;
            case SDLK_DOWN: // Flèche bas
                perso.pos.y += 2;
                break;
            case SDLK_RIGHT: // Flèche droite
                perso.pos.x += 2;
                break;
            case SDLK_LEFT: // Flèche gauche
                perso.pos.x -= 2;
                break;
            }
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
            {

                if (event.button.x <= ecran->w / 2)

                    perso.pos.x -= 20;
                else
                    perso.pos.x += 20;
            }
            break;

           
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(perso.img, NULL, ecran, &perso.pos);

        SDL_Flip(ecran);
    }

    SDL_FreeSurface(perso.img);
    SDL_Quit();
    return 0;
}
