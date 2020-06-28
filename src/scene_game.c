/*****************************************************************
 * Nom ................. : scene_game.c                          *
 * Role ................ : gestion des scenes du jeu             *
 * Auteur .............. : Monos                                 *
 * Version ............. : 26/04/2020                            *
 *****************************************************************/

// ==================================
// ** Fichier include du programme **
// ==================================
#include "header/main.h"
#define FREQ_FRAME 12

// ========================================
// ** Déclaration des variables globales **
// ========================================
extern unsigned char ram_map_collision[11][11];
unsigned char id_action;
unsigned char draw_text;
unsigned long i;
unsigned char cycle_frame=0;
unsigned char annimation_frame;

// ============================
// ** Procedure scene_game() **
// ============================
void scene_game()
{

  // =================================
  // ** Initiation de la scene_game **
  // =================================
 VDP_setEnable	(0	)	;

  // -------------------------
  // * Chargement des assets *
  // -------------------------
 
  VDP_setPalette(0, background_board.palette->data);
  VDP_drawImageEx(0, &background_board, TILE_ATTR_FULL(0, 0, 0, 0, 1),0, 0, 0, DMA);

  VDP_loadBMPTileData((const u32*) tilset_game.image, 0x340,128/8, 16/8,128/8); 
  VDP_loadBMPTileData((const u32*) sprite_game.image, 0x300,8, 2,8); 
 
  VDP_setPalette(2, tilset_game.palette->data);
  VDP_setPalette(1, sprite_game.palette->data);

  // -------------------------
  // * Initation des sprites *
  // -------------------------
  VDP_allocateSprites	(3);
 

  // -----------------------
  // * affichage de la map *
  // -----------------------
  draw_map();
  
  // -----------------------------
  // * Mise en place des sprites *
  // -----------------------------

  set_curseur(PLAYER_1,5,1);
  set_player(PLAYER_1,5,1);
  set_player(PLAYER_2,5,9);
 
  // -----------------------
  // * allumage de l'ecran *
  // -----------------------
for (i=0;i<3000;i++)
{


}
 VDP_setEnable	(1	)	;

  // -------------------------------
  // * Collision de la case sprite *
  // -------------------------------
  ram_map_collision[get_player_px(PLAYER_1)][get_player_py(PLAYER_1)] = 1;
  ram_map_collision[get_player_px(PLAYER_2)][get_player_py(PLAYER_2)] = 1;

  // ---------------------------------
  // * Initiation de l'action de jeu *
  // ---------------------------------

  switch (random()&0b0000000000000011)
  { 
    case 0 :
      id_action = 0;
    break;

     case 1 :
      id_action = 1;
    break;

   case 2 :
      id_action = 3;
      set_curseur(PLAYER_2,get_player_px(PLAYER_2),get_player_py(PLAYER_2));
   break;

   case 3 :
      id_action = 4;
      set_curseur(PLAYER_2,get_player_px(PLAYER_2),get_player_py(PLAYER_2));
    break;
  }

  // =================
  // * Update Player *
  // =================
  update_player();

  // ==================
  // * Pzlyer Musique *
  // ==================
  XGM_startPlay	(	(const u8 *) 	musique_pal	)	;

  // =============================
  // ** Boucle du la Scene Game **
  // =============================
  while(get_scene() == SCENE_GAME)
  {
    // **********************************
    // * Temps logique du jeu  (update) *
    // **********************************
   
    // -------------------------
    // * Mouvement du joueur 1 *
    // -------------------------
   
    if (id_action == 0)
    {

      if (draw_text==0)
      {
        draw_full_red_sol(get_player_px(PLAYER_1),get_player_py(PLAYER_1));

        VDP_drawTextBG	(	1,"PLAYER 1 ",30,1+2);
        VDP_drawTextBG	(	1,"         ",30,2+2);
        VDP_drawTextBG	(	1," MOVED   ",30,2+2);
       
        draw_text=1;
      }
     
      move_curseur(PLAYER_1);
      moved_player(PLAYER_1);
    }
     
    // ----------------------------------------------
    // * ouvrir une trap sur le sol par le joueur 1 *
    // ----------------------------------------------
    else if (id_action == 1)
    {
      if (draw_text==0)
      {
        VDP_drawTextBG	(	1,"PLAYER 1 ",30,1+2);
        VDP_drawTextBG	(	1,"         ",30,2+2);
        VDP_drawTextBG	(	1,"  FIRE   ",30,2+2);
    
        draw_text=1;
      }
      move_curseur(PLAYER_1);
      draw_trape_game(PLAYER_1);
    }
    
    // -----------------------
    // * Tester le game over *
    // -----------------------
    else if (id_action == 2)
    {
      testing_game_over();
      id_action = id_action+1;
    }

    // -------------------------
    // * Mouvement du joueur 2 *
    // -------------------------
   
    else if (id_action == 3)
    {
      if (draw_text==0)
      {
        draw_full_red_sol(get_player_px(PLAYER_2),get_player_py(PLAYER_2));
        VDP_drawTextBG	(	1,"PLAYER 2 ",30,1+2);
        VDP_drawTextBG	(	1,"         ",30,2+2);
        VDP_drawTextBG	(	1," MOVED   ",30,2+2);

        draw_text=1;
      }
      move_curseur(PLAYER_2);
      moved_player(PLAYER_2);
    }
    
    // ----------------------------------------------
    // * ouvrir une trap sur le sol par le joueur 2 *
    // ----------------------------------------------
    else if (id_action == 4)
    {
      if (draw_text==0)
      {
        VDP_drawTextBG	(	1,"PLAYER 2 ",30,1+2);
        VDP_drawTextBG	(	1,"         ",30,2+2);
        VDP_drawTextBG	(	1,"  FIRE   ",30,2+2);
   
        draw_text=1;
      }
      move_curseur(PLAYER_2);
      draw_trape_game(PLAYER_2);
    }
    // -----------------------
    // * Tester le game over *
    // -----------------------
    else if (id_action == 5)
    {
      testing_game_over();
      id_action = 0;
    }

    // ------------
    // * wait vbl *
    // ------------
    cycle_frame++;
    annimation_frame = FREQ_FRAME;
       // -----------------------
       // * Adapatation en NTSC *
      // -----------------------
  if (SYS_isPAL()==0) 
  {
    annimation_frame = ( annimation_frame * 60)/50;
  }

    VDP_waitVSync();  
   
    if (cycle_frame== annimation_frame)
    {
      VDP_loadBMPTileData((const u32*) tilset_game_1.image, 0x340,128/8, 16/8,128/8);
    }
    else if (cycle_frame== annimation_frame * 2)
    {
      VDP_loadBMPTileData((const u32*) tilset_game_2.image, 0x340,128/8, 16/8,128/8);
    }
    else if (cycle_frame== annimation_frame * 3)
    {
      VDP_loadBMPTileData((const u32*) tilset_game_1.image, 0x340,128/8, 16/8,128/8);
      
    }
    else if (cycle_frame== annimation_frame * 4)
    {
      VDP_loadBMPTileData((const u32*) tilset_game.image, 0x340,128/8, 16/8,128/8);
      cycle_frame = 0;
    }
    // ****************************
    // * Temps d'affichage (draw) *
    // ****************************

    if (get_scene()==SCENE_GAME)
    { 
      update_player();
      update_curseur();
      VDP_updateSprites(80,CPU);
   }
  }

}

// =====================================
// * Routine de déplacement du curseur *
// =====================================
void move_curseur(unsigned char id_player)
{
  static unsigned char pad_key_up;
  static unsigned char id_input;

 id_input = get_input(id_player);
  
  // ==========================
  // * Gestion du pad curseur *
  // ==========================

  // -----------------
  // * Touche droite *
  // -----------------

 if (id_input==6)  
  {

    if (pad_key_up == 0)
    {      
      set_curseur_px(get_curseur_px() + 1);
      pad_key_up = 1;
    }   
  }

  // -----------------
  // * Touche gauche *
  // -----------------
  else if ((id_input==4) )
  {
    if (pad_key_up == 0)
    {
      set_curseur_px(get_curseur_px() - 1);
      pad_key_up = 1;
    }
  }

  // ---------------
  // * Touche Haut *
  // ---------------
  else if ((id_input==8) ) 
  {

    if (pad_key_up == 0)
    {
      set_curseur_py(get_curseur_py() - 1);
      pad_key_up = 1;
     }
  }
 
  // --------------
  // * Touche Bas *
  // --------------
  else if ((id_input==2) )
  {
    if (pad_key_up == 0)
    {
      set_curseur_py(get_curseur_py() + 1);
      pad_key_up = 1;
    }  
  }

  // --------------------------------
  // * Mise à 0 le buffer de touche *
  // --------------------------------
  else
  {
    pad_key_up = 0;
  }

  // ================================
  // * protection de sortie du bord *
  // ================================
  if (get_curseur_px() == 0)
  {
    set_curseur_px(1);
  }

  if (get_curseur_px() == 10)
  {
    set_curseur_px(9);
  }

    if (get_curseur_py() == 0)
  {
    set_curseur_py(1);
  }

  if (get_curseur_py() == 10)
  {
    set_curseur_py(9);
  }

}

// =========================
// * Deplacement du joueur *
// =========================
void moved_player(unsigned char id_player)
{
  // -------------------------------------
  // * Declaration des variables locales *
  // -------------------------------------
  static unsigned char id_input;

  // -------------
  // - Get Input *
  // -------------
  id_input = get_input(id_player);


  // ----------------
  // * Effect Input *
  // ----------------
  if ((id_input==10) && ram_map_collision[get_curseur_px()][get_curseur_py()] == 0 )
  {
    if(
        // Case de droite
        ((get_curseur_px()== get_player_px(id_player) + 1) && (get_curseur_py() == get_player_py(id_player))) ||

        // Case de gauche
        ((get_curseur_px()== get_player_px(id_player)  - 1) && (get_curseur_py() == get_player_py(id_player))) ||

        // Case Haut
        ((get_curseur_px()== get_player_px(id_player) ) && (get_curseur_py() == get_player_py(id_player) - 1)) ||

        // Case Bas
        ((get_curseur_px()== get_player_px(id_player) ) && (get_curseur_py() == get_player_py(id_player) + 1)) ||

        // Haut/Droite
        ((get_curseur_px()==get_player_px(id_player) + 1) && (get_curseur_py() == get_player_py(id_player) - 1)) ||

        // Haut/Gauche
        ((get_curseur_px()== get_player_px(id_player) - 1) && (get_curseur_py() == get_player_py(id_player) - 1)) ||

        // Bas/Droite
        ((get_curseur_px()==get_player_px(id_player) + 1) && (get_curseur_py() == get_player_py(id_player) + 1)) ||

        // Bas/Gauche
        ((get_curseur_px()== get_player_px(id_player) - 1) && (get_curseur_py() == get_player_py(id_player) + 1)))
    {
        
        // ------------------------------
        // * Mise à 0 la case du joueur *
        // ------------------------------
        ram_map_collision[get_player_px(id_player)][get_player_py(id_player)] = 0;
        
        // --------------------------
        // * Virer les cases rouges *
        // --------------------------
        draw_full_red_sol_off(get_player_px(id_player),get_player_py(id_player));        

        // -------------------------------
        // * nouvelle position du joueur *
        // ------------------------------- 
        set_player(id_player,get_curseur_px(),get_curseur_py());
        
        // ------------------------------
        // * Mise à 1 la case du joueur *
        // ------------------------------
        ram_map_collision[get_player_px(id_player)][get_player_py(id_player)] = 1;
        
        // ------------------------------
        // * Passage à l'action suivant *
        // ------------------------------
        draw_text=0;
        id_action = id_action + 1; // poser un obstacle 
        VDP_waitVSync();
    }
  }

}

// ===========================
// * Ajouter le sol qui bloc *
// ===========================
void draw_trape_game(unsigned char id_player)
{
  // -------------------------------------
  // * Déclaration des variables locales *
  // -------------------------------------
  unsigned char next_player;
  static unsigned char id_input;

  id_input = get_input(id_player); 

  // ------------------------
  // * tester le bouton feu *
  // ------------------------
  if( id_input == 10)
  {

    if (ram_map_collision[get_curseur_px()][get_curseur_py()]==0)
    {
    //  snd_startplay(3);
      draw_trap(get_curseur_px(), get_curseur_py());
      ram_map_collision[get_curseur_px()][get_curseur_py()] = 1;
       VDP_waitVSync();
      // ----------------------------------
      // * preparation du nouveau curseur *
      // ----------------------------------
      
      if (id_player == 0)
      {
        next_player = 1;
      }
        else
      {
        next_player = 0;
      }
          
      set_curseur(next_player,get_player_px(next_player),get_player_py(next_player));
      
      // ------------------------------
      // * Passage à l'action suivant *
      // ------------------------------
      draw_text=0;
      id_action = id_action + 1; // tester le game overs
    }
   
  }

}

// =======================
// * Tester le Game over *
// =======================
void testing_game_over()
{
  // -------------------------------------
  // * Declaration des variables locales *
  // -------------------------------------
  unsigned char lost_player_1;
  unsigned char lost_player_2;

  // ----------------------
  // * tester les joueurs *
  // ----------------------
  lost_player_1 = test_lost_player(PLAYER_1);
  lost_player_2 = test_lost_player(PLAYER_2);

  // ------------------------------------
  // * tester les conditions de defaite *
  // ------------------------------------
 
  // ''''''''''''''''''''''
  // * Game Over player 1 *
  // ''''''''''''''''''''''
  if ((lost_player_1 == 1) && (lost_player_2 == 0))
  {
    draw_windows(21);
    VDP_drawTextBG	(	1,"Player 2 win",5+4,22+4);
    return_title_screen();
  }
  
  // ''''''''''''''''''''''
  // * Game Over Player 2 *
  // ''''''''''''''''''''''
  else if ((lost_player_1 == 0) && (lost_player_2 == 1))
  {
    draw_windows(21);
    VDP_drawTextBG	(	1,"Player 1 win",5+4,22+4);
    return_title_screen();
   
  }

  // ''''''''
  // * Draw *
  // ''''''''
  else if ((lost_player_1 == 1) && (lost_player_2 == 1))
  {
    draw_windows(21);
    VDP_drawTextBG	(	1,"Draw Game",5+4,22+4);
    return_title_screen();
  }

}

// ===================================================
// * Afficher le game over et retour à l'écran titre *
// ===================================================
void return_title_screen()
{
  unsigned char i = 0;  
  VDP_waitVSync();
  
  // -----------------------------------------
  // * Boucle d'attente de la touche start ! *
  // -----------------------------------------
  while(i==0)
  {
    if (get_input(0)==13)
    {
      i = 1;
    }
    
    VDP_waitVSync();
  }

  // -----------------
  // * Temporisation *
  // -----------------
  for (i=0;i<30;i++)
  {    
    VDP_waitVSync();
  }
 
  // ------------------------------------
  // * Traitement des sprites à l'écran *
  // ------------------------------------
  VDP_resetSprites ();
  VDP_clearSprites ();
  VDP_updateSprites(80,CPU);
  
  // ---------------------
  // * Fin de la musique *
  // ---------------------
  XGM_stopPlay(	)	;
  
  // --------------------
  // * Mode Ecran Titre *
  // --------------------
  set_scene(SCENE_TITLE_SCREEN); // Mode Scene game

}

// ===================================
// * Tester le Game Over d'un joueur *
// ===================================
unsigned char test_lost_player(unsigned char id_player)
{
 if ((

 // -----------------
 // * Position Haut *
 // ----------------- 
 ram_map_collision[get_player_px(id_player)][get_player_py(id_player)+1]  +

 // ----------------
 // * Position Bas *
 // ----------------
 ram_map_collision[get_player_px(id_player)][get_player_py(id_player)-1]  +
 
 // -------------------
 // * Position Gauche *
 // -------------------
 ram_map_collision[get_player_px(id_player)-1][get_player_py(id_player)]  +
 
 // -------------------
 // * Position Droite *
 // -------------------
 ram_map_collision[get_player_px(id_player)+1][get_player_py(id_player)]  +
  
 // --------------------------
 // * Position Haut / Gauche *
 // --------------------------
 ram_map_collision[get_player_px(id_player)-1][get_player_py(id_player)+1] +

 // --------------------------
 // * Position Haut / Droite *
 // --------------------------
 ram_map_collision[get_player_px(id_player)+1][get_player_py(id_player)+1] +

 // -------------------------
 // * Position Bas / Gauche *
 // -------------------------
 ram_map_collision[get_player_px(id_player)-1][get_player_py(id_player)-1] +
 
 // -------------------------
 // * Position Bas / Droite *
 // -------------------------
 ram_map_collision[get_player_px(id_player)+1][get_player_py(id_player)-1]

   == 8))
  {
    return 1;
  }

  else
  {
    return 0;
  }

}