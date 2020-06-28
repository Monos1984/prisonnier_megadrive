/*****************************************************************
 * Nom ................. : class_player.c                        *
 * Role ................ : gestion du joeur                      *
 * Auteur .............. : Monos                                 *
 * Version ............. : 26/04/2020                            *
 * Cible ............... : Megadrive SGDK                        *
 *****************************************************************/

// ==================================
// ** Fichier include du programme **
// ==================================
#include "header/main.h"

// ========================================
// ** Déclaration des variables globales **
// ========================================
 player_t player[2];
 curseur_t curseur;

// ================
// ** Set player **
// ================
void set_player(unsigned char id_player,unsigned char position_x,unsigned char position_y)
{
 player[id_player].px = position_x;
 player[id_player].py = position_y;
}

// ==================
// ** Set couleurs **
// ==================
void set_coul(unsigned char id_player,unsigned char id_coul)
{
  player[id_player].id_coul = id_coul;
}

// =========================================
// ** Récupérer la position x d'un joueur **
// =========================================
unsigned char get_player_px(unsigned char id_player)
{
  return player[id_player].px;
}

// =========================================
// ** Récupérer la position y d'un joueur **
// =========================================
unsigned char get_player_py(unsigned char id_player)
{
  return player[id_player].py;
}

// ===================
// ** update_player **
// ===================
void update_player()
{
  
  // ------------------
  // * Variable local *
  // ------------------
  static unsigned char count_id;
  unsigned char f_flip_j0;  
  unsigned char f_flip_j1; 
  
  // ----------------------------
  // * Compteur de cycle update *
  // ----------------------------
  count_id++;

  // --------------------------------------------
  // * routine d'update de la symetrie vertical *
  // --------------------------------------------
  if (count_id > 30)
  {
    count_id = 0;
  }
  
  if (count_id>15)
  {
    f_flip_j0=1;
    f_flip_j1=0;
  }
  else
  {
    f_flip_j0=0;
    f_flip_j1=1;
  }

  // -----------------------------------
  // * Affichage des sprites du joueur *
  // -----------------------------------
  VDP_setSprite	(	1,((player[0].px)<<4)+(TILES_DX*8),(((player[0].py)<<4))+(TILES_DY*8),SPRITE_SIZE	(2,2),TILE_ATTR_FULL	(1,1,0,f_flip_j0,0x308)); // Joueur 0
  VDP_setSprite	(	2,((player[1].px)<<4)+(TILES_DX*8),(((player[1].py)<<4)+(TILES_DY*8)),SPRITE_SIZE	(2,2),TILE_ATTR_FULL	(1,1,0,f_flip_j1,0x30C));  // Joueur 1
}


// ==================
// ** Set curseur **
// ==================
void set_curseur(unsigned char id_player,unsigned char position_x,unsigned char position_y)
{
  curseur.id_player = id_player;
  curseur.px = position_x;
  curseur.py = position_y;
  curseur.id_coul = player[id_player].id_coul;
}


// ====================================
// ** Recupérer la couleur du joueur **
// ====================================
unsigned char get_player_id_color(unsigned char id_player)
{
  return player[id_player].id_coul;
}

// ====================
// ** Set curseur_px **
// ====================
void set_curseur_px(unsigned char position_x)
{
  curseur.px = position_x;
}

// ====================
// ** Get curseur px **
// ====================
unsigned char get_curseur_px()
{
  return curseur.px;
}
// ====================
// ** Set curseur_py **
// ====================
void set_curseur_py(unsigned char position_y)
{
  curseur.py = position_y;
}

// ====================
// ** Get curseur py **
// ====================
unsigned char get_curseur_py()
{
  return curseur.py;
}

// ================================================
// ** couleur du curseur (obsolet sur megadrive) **
// ================================================
void set_coul_curseur(unsigned char id_coul)
{
 curseur.id_coul = id_coul;

}


// ====================
// ** update curseur **
// ====================
void update_curseur()
{
 
  if ( curseur.id_player==0)
  {
    VDP_setSprite	(	0,((curseur.px)<<4)+(TILES_DX*8),(((curseur.py)<<4)+(TILES_DY*8)),SPRITE_SIZE	(2,2),TILE_ATTR_FULL	(1,1,0,0,0x300));
  }
  else
  {
    VDP_setSprite	(	0,((curseur.px)<<4)+(TILES_DX*8),(((curseur.py)<<4)+(TILES_DY*8)),SPRITE_SIZE	(2,2),TILE_ATTR_FULL	(1,1,0,0,0x304));
  }

}