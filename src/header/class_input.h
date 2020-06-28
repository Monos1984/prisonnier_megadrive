/*****************************************************************
 * Nom ................. : scene_player .h                       *
 * Role ................ : gestion du joueur                      *
 * Auteur .............. : Monos                                 *
 * Version ............. : 19/11/19                              *
 *****************************************************************/

#ifndef   CLASS_INPUT_H
  #define CLASS_INPUT_H
	

	// ================================
	// ** Déclaration des prototypes **
	// ================================
unsigned char get_right(unsigned char id_pad);
unsigned char get_left(unsigned char id_pad);
unsigned char get_up(unsigned char id_pad);
unsigned char get_down(unsigned char id_pad);
unsigned char get_fire(unsigned char id_pad);
unsigned char get_fire_left(unsigned char id_pad);


unsigned char get_input(unsigned char id_pad);

 
   
#endif
