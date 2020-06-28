/*****************************************************************
 * Titre du jeu ........ : Prisonnier                            *
 * Nom ................. : main.c                                *
 * Role ................ : lanceur du programme                  *
 * Auteur .............. : Monos                                 *
 * Version ............. : 0.0.0                                 *
 * Cible ............... : Megadrive SGDK                        *
 *****************************************************************/

// ==================================
// ** Fichier include du programme **
// ==================================
#include "header/main.h"

// ===================
// * int main()      *
// ===================
int main()
{
  signed int i;
  u16 random_cycle = 0; // Compteur de cycle pour le seed
  // --------------------------------------
  // * Initation de la scene du programme *
  // --------------------------------------
  set_scene(SCENE_INIT);
  
  // -----------------------
	// * Boucle du programme *
	// -----------------------
	while(1)
	{ 
	  
    // --------------
    // * Scene_Init *
    // --------------
    if (get_scene() == SCENE_INIT)
    {

      // ---------------------------
      // * Initation de la machine *
      // --------------------------- 
      VDP_clearTileMapRect	(	0,0,0,320/8,224/8);
      VDP_clearTileMapRect	(	1,0,0,320/8,224/8);
      VDP_setScreenWidth256(); // 256 px (16 tiles à l'écran)
      VDP_setScreenHeight224 (); // 224px (14 tiles à l'écran)
      VDP_setPlaneSize	(64,32,FALSE); // Tailles virtuel de 32x16 tiles)    
      set_scene(SCENE_SPLASH); 
    } 
    

    else if (get_scene() == SCENE_SPLASH)
    {
      VDP_setPalette(0, logo_offgame.palette->data);
      SND_startPlay_PCM	(	offgame,sizeof(offgame),SOUND_RATE_11025,SOUND_PAN_CENTER,0);
      VDP_waitVSync();
      VDP_drawImageEx(0, &logo_offgame, TILE_ATTR_FULL(0, 0, 0, 0, 1),32, 12, 0, CPU);
      

      for (i=0;i<25;i++)
      {
        VDP_setHorizontalScroll	(	0,-(i*8));	
        VDP_waitVSync();
      }

      for (i=0;i<80;i++)
      {
        VDP_waitVSync();
      }

      set_scene(SCENE_TITLE_SCREEN); 
    }

    // -----------------------
    // * Scene title screene *
    // -----------------------
    else if (get_scene() == SCENE_TITLE_SCREEN)
    {
    
      VDP_setHorizontalScroll	(	0,0);
      VDP_clearTileMapRect	(	0,0,0,320/8,224/8);
      VDP_clearTileMapRect	(	1,0,0,320/8,224/8);

      VDP_setTextPalette	(	1	);	

      // -----------------
      // * Test menu wip *
      // ----------------- 
      VDP_setScreenWidth320();
      VDP_setBackgroundColor (0);
      XGM_startPlay	(	(const u8 *) 	musique_title_screen	)	;

      VDP_setPalette(0, titlescreen.palette->data);
      VDP_drawImageEx(0, &titlescreen, TILE_ATTR_FULL(0, 0, 0, 0, 1),0+4, 0, 0, CPU);
    
/*
      VDP_drawTextBG	(	1,"PRESS START",12,12);
      VDP_drawTextBG	(	1,"OPTIONS",12,13);
      VDP_drawTextBG	(	1,"CREDITS",12,14);

      VDP_drawTextBG	(	1,"OFFGAME 2020",1,26);
*/
      while(get_scene() == SCENE_TITLE_SCREEN)
      {
        random_cycle++;

        if (get_input(0)==13)
        {
            // ------------------------------
            // * Seed du genateur aléatoire *
            // ------------------------------
            setRandomSeed (random_cycle);
            set_scene(SCENE_GAME); 
        }

        VDP_waitVSync();
      }
    }
     
    // --------------
    // * Scene_game *
    // --------------
    else if (get_scene() == SCENE_GAME)
    {
      scene_game();
    	VDP_waitVSync();
    }

    // ----------------
    // * scene credit *
    // ----------------
    else if (get_scene() == SCENE_CREDIT)
    {
  //    credit();
    	VDP_waitVSync();
    }

	 	
		VDP_waitVSync();
	}
	
	return (0);
}
