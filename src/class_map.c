/*****************************************************************
 * Nom ................. : class_map.c                           *
 * Role ................ : gestion de la map                     *
 * Auteur .............. : Monos                                 *
 * Version ............. : 26/04/2019                            *
 *****************************************************************/
// ==================================
// ** Fichier include du programme **
// ==================================
#include "header/main.h"

// =====================
// ** Variable global **
// =====================
unsigned char ram_map_collision[11][11];

// =========================
// ** Affichage de la map **
// =========================
void draw_map()
{
  // -------------------------------------
  // * Declaration des variables locales *
  // -------------------------------------
  unsigned char x,y,i;
  i = 0;
  
  // ------------------
  // * netoyage ecran *
  // ------------------
  // VDP_clearTileMapRect	(	0,0,0,256/8,224/8);
  VDP_clearTileMapRect	(	1,0,0,256/8,224/8);

  // --------------------------------
  // * Boucle d'affichage de la map *
  // --------------------------------
  for (y=0;y<11;y++)
  {
    for (x=0;x<11;x++)
    {
      switch (map[i])
      {
        // ----------------
        // * Poser le sol *
        // ----------------
        case 1:
          draw_sol(x,y);
          ram_map_collision[x][y]=0;
         
          // -----------------------------------------
          // * Routine d'affichage du trap aleatoire *
          // -----------------------------------------
          if (random()<5000)
          {
            draw_trap(x,y);
            ram_map_collision[x][y]=1;
          }
        break;

        // ----------------
        // * Poser le mur *
        // ----------------
        case 2:
        //  draw_mur(x,y);
          ram_map_collision[x][y]=1;
        break;

        // -----------------
        // * Poser toiture *
        // -----------------
        case 3:
         // draw_toiture(x,y);
          ram_map_collision[x][y]=1;
        break;

        // -----------------
        // * Poser depart *
        // -----------------
        case 4:
          draw_sol(x,y);
          ram_map_collision[x][y]=0;
        break;

      } // Fin switch

      i++;
      


    } // Fin boucle X


  } // Fin boucle Y
  


} // Fin procedure draw_map()


// ---------------------------------------------
// * Afficher le sol rouge pour le déplacement *
// ---------------------------------------------
void draw_full_red_sol(unsigned char px,unsigned char py)
{

  // --------
  // * haut *
  // --------
  if (ram_map_collision[px][py-1]==0)
  {
    draw_red_sol(px,py-1);
    VDP_waitVSync();
  }
  // ---------------
  // * haut Droite *
  // ---------------
  if (ram_map_collision[px+1][py-1]==0)
  {
    draw_red_sol(px+1,py-1);
    VDP_waitVSync();
  }
  // ----------
  // * Droite *
  // ----------
  if (ram_map_collision[px+1][py]==0)
  {
    draw_red_sol(px+1,py);
    VDP_waitVSync();
  }
  // --------------
  // * bas Droite *
  // --------------
  if (ram_map_collision[px+1][py+1]==0)
  {
    draw_red_sol(px+1,py+1);
    VDP_waitVSync();
  }
  // -------
  // * bas *
  // -------
  if (ram_map_collision[px][py+1]==0)
  {
    draw_red_sol(px,py+1);
    VDP_waitVSync();
  }
  // --------------
  // * bas gauche *
  // --------------
  if (ram_map_collision[px-1][py+1]==0)
  {
    draw_red_sol(px-1,py+1);
    VDP_waitVSync();
  }
  // ----------
  // * gauche *
  // ----------
  if (ram_map_collision[px-1][py]==0)
  {
    draw_red_sol(px-1,py);
     VDP_waitVSync();
  }
  // ---------------
  // * haut gauche *
  // ---------------
  if (ram_map_collision[px-1][py-1]==0)
  {
    draw_red_sol(px-1,py-1);
    VDP_waitVSync();
  }
}


// -------------------
// * Retablir le sol *
// -------------------
void draw_full_red_sol_off(unsigned char px,unsigned char py)
{

  // ----------
  // * Droite *
  // ----------
  if (ram_map_collision[px+1][py]==0)
  {
    VDP_waitVSync();
    draw_sol(px+1,py);  
  }
  // ----------
  // * gauche *
  // ----------
  if (ram_map_collision[px-1][py]==0)
  {
    VDP_waitVSync();
    draw_sol(px-1,py);
  }

  // --------
  // * haut *
  // --------
  if (ram_map_collision[px][py-1]==0)
  {
    VDP_waitVSync();
    draw_sol(px,py-1);
   
  }

  // -------
  // * bas *
  // -------
  if (ram_map_collision[px][py+1]==0)
  {
    VDP_waitVSync();
    draw_sol(px,py+1);
  }

  // ---------------
  // * haut Droite *
  // ---------------
  if (ram_map_collision[px+1][py-1]==0)
  {
    VDP_waitVSync();
    draw_sol(px+1,py-1); 
  }

  // ---------------
  // * haut gauche *
  // ---------------
  if (ram_map_collision[px-1][py-1]==0)
  {
    VDP_waitVSync();
    draw_sol(px-1,py-1);
    
  }

  // --------------
  // * bas Droite *
  // --------------
  if (ram_map_collision[px+1][py+1]==0)
  {
    VDP_waitVSync();
    draw_sol(px+1,py+1);
   
  }
 // --------------
 // * bas gauche *
 // --------------
  if (ram_map_collision[px-1][py+1]==0)
  {
    VDP_waitVSync();
    draw_sol(px-1,py+1);
   
  }

}

// ==================
// ** poser un sol **
// ==================
void draw_sol(unsigned char x, unsigned char y)
{

  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(0,0,0,0,0x30 ),(x<<1)+TILES_DX,(y<<1)+TILES_DY);		
  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(0,0,0,0,0x25 ),(x<<1)+TILES_DX,(y<<1)+1+TILES_DY);
  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(0,0,0,0,0x2f ),(x<<1)+1+TILES_DX,(y<<1)+TILES_DY);		
  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(0,0,0,0,0x24 ),(x<<1)+1+TILES_DX,(y<<1)+1+TILES_DY);	

}

// ===================================
// ** Markeur de déplacement du sol **
// ===================================
void draw_red_sol(unsigned char x, unsigned char y)
{
  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(2,0,0,0,0x340 ),(x<<1)+TILES_DX,(y<<1)+TILES_DY);	
  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(2,0,0,0,0x350 ),(x<<1)+TILES_DX,(y<<1)+1+TILES_DY);	
  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(2,0,0,0,0x341 ),(x<<1)+1+TILES_DX,(y<<1)+TILES_DY);	
  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(2,0,0,0,0x351 ),(x<<1)+1+TILES_DX,(y<<1)+1+TILES_DY);	
}

// =======================
// ** Poser un le traps **
// =======================
void draw_trap(unsigned char x, unsigned char y)
{

  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(2,0,0,0,0x342 ),(x<<1)+TILES_DX,(y<<1)+TILES_DY);
  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(2,0,0,0,0x352 ),(x<<1)+TILES_DX,(y<<1)+1+TILES_DY);			
  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(2,0,0,0,0x343 ),(x<<1)+TILES_DX+1,(y<<1)+TILES_DY);	
  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(2,0,0,0,0x353 ),(x<<1)+1+TILES_DX,(y<<1)+1+TILES_DY);	
 
}


// ==========================
// * Draw windows game over *
// ==========================
void draw_windows(unsigned char py)
{
  unsigned char x;

  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(0,0,0,0,0 ),0+4,(py)+4);		
  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(0,0,0,0,0 ),21+4,(py)+4);	
  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(0,0,0,0,0 ),0+4,(2+py)+4);	
  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(0,0,0,0,0 ),21+4,(2+py)+4);	

  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(0,0,0,0,0 ),0+4,(1+py)+4);
  VDP_setTileMapXY	(0,TILE_ATTR_FULL	(0,0,0,0,0 ),21+4,(1+py)+4);		

  for (x=1;x<21;x++)
  { 
    VDP_setTileMapXY	(0,TILE_ATTR_FULL	(0,0,0,0,0 ),x+4,(py)+4);	
    VDP_setTileMapXY	(0,TILE_ATTR_FULL	(0,0,0,0,0), x+4,(1+py)+4);	 
    VDP_setTileMapXY	(0,TILE_ATTR_FULL	(0,0,0,0,0 ),x+4,(2+py)+4);	  
  }

}






