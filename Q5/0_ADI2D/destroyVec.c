#include "main.h"

/* Destruction d'un vecteur
Entree : Vec* V
Sortie : vide
*/
void destroyVec(Vec* V){
   free(V->val);
   free(V);
   }
