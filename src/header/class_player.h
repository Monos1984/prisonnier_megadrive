/*****************************************************************
 * Nom ................. : scene_player .h                       *
 * Role ................ : gestion du joueur                      *
 * Auteur .............. : Monos                                 *
 * Version ............. : 19/11/19                              *
 *****************************************************************/

#ifndef   CLASS_PLAYER_H
  #define CLASS_PLAYER_H
	
	// ============================
	// ** Les Defines des Scenes **
	// ============================
  #define PLAYER_1 0
  #define PLAYER_2 1
	// ================================
	// ** Déclaration des prototypes **
	// ================================
  void set_player(unsigned char id_player,unsigned char position_x,unsigned char position_y);
  void set_coul(unsigned char id_player,unsigned char id_coul);
  unsigned char get_player_px(unsigned char id_player);
  unsigned char get_player_py(unsigned char id_player);
  void update_player();

  void set_curseur(unsigned char id_player,unsigned char position_x,unsigned char position_y);
  void set_curseur_px(unsigned char position_x);
  unsigned char get_curseur_px();
   void set_curseur_py(unsigned char position_y);
  unsigned char get_curseur_py();
  void update_curseur();
unsigned char get_player_id_color(unsigned char id_player);
void set_coul_curseur(unsigned char id_coul);
  // ================================
  // ** Déclaration des structures **
  // ================================
  
  // -----------------------
  // * Structure  player_t *
  // -----------------------
 
  typedef struct 
  {   
    unsigned char px;
    unsigned char py;
    unsigned char ia;
    unsigned char id_coul;

  } player_t;


  // -----------------------
  // * structure curseur_t *
  // -----------------------
  typedef struct 
  {
    unsigned char px;
    unsigned char py;
    unsigned char id_coul;
    unsigned char id_player;

  } curseur_t;
   
#endif
