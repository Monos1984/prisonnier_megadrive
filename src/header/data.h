/*****************************************************************
 * Nom ................. : scene_manager.h                       *
 * Role ................ : gestion des scenes du jeu             *
 * Auteur .............. : Monos et michel louvet                *
 * Version ............. : 24/03/2019                            *
 *****************************************************************/

#ifndef DATA_H
  #define DATA_H
	
	// ============================
	// ** Les Defines des Scenes **
	// ============================

	// ================================
	// ** Déclaration des prototypes **
	// ================================
	
  // =====================
  // ** Variable extern **
  // =====================
  extern const unsigned char rle_data_tile[];
  extern const unsigned char rle_color_tilset[];
  extern const unsigned char map[];
  extern const unsigned char rle_game_sprite[];

#define SZTILtitle_screen 572
#define SZCOLtitle_screen 162
#define SZMAPtitle_screen 242

extern const unsigned char TILtitle_screen[];
extern const unsigned char COLtitle_screen[];
extern const unsigned char MAPtitle_screen[];

  extern const unsigned char dummysound[];
  extern const unsigned char menu_selection[];
  extern const unsigned char snd_space_break[];
  extern const unsigned char snd_victory[];
  extern const unsigned char snd_move_invalid[];
  extern const unsigned char snd_return[];

  extern const unsigned char musique_ch0[];
  extern const unsigned char musique_ch2[];
  extern const unsigned char musique_ch3[];

#endif
