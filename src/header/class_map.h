/*****************************************************************
 * Nom ................. : Class_map.h                           *
 * Role ................ : gestion de la map                     *
 * Auteur .............. : Monos                                 *
 * Version ............. : 04/05/2020                            *
 *****************************************************************/

#ifndef   CLASS_MAP_H
  #define CLASS_MAP_H
	
	// ============================
	// ** Les Defines des Scenes **
	// ============================

	// ================================
	// ** Déclaration des prototypes **
	// ================================
	void draw_map();
  void draw_sol(unsigned char x, unsigned char y);
  void draw_red_sol(unsigned char x, unsigned char y);
  void draw_trap(unsigned char x, unsigned char y);
  void draw_windows(unsigned char py);
  void draw_right_windows();
  void draw_full_red_sol(unsigned char px,unsigned char py);
  void draw_full_red_sol_off(unsigned char px,unsigned char py);
#endif
