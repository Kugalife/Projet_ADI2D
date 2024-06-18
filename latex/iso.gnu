# Nom du fichier de donnees
u = "out"
uRef = "ref"

# Parametres du trace
set contour base
set view map
unset surface

# Rapport d'aspect egal
set size ratio -1

# Nombre d'isovaleurs souhaitees
set cntrparam levels 11  

# Etiquettes et titre
set xlabel "X"
set ylabel "Y"
set title "isovaleurs de u et uRef"

# Placer les legendes en dehors de la figure, a droite
set key outside right

# Trace des isovaleurs
splot u using 1:2:3 with lines
replot uRef using 1:2:3 with lines

# Affichage du graphique
pause mouse keypress "Appuyez sur une touche pour quitter"

