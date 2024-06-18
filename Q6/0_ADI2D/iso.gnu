# Nom du fichier de données
u = "out"
uRef = "ref"

# Paramètres du tracé
set contour base
set view map
unset surface

# Rapport d'aspect égal
set size ratio -1

# Nombre d'isovaleurs souhaitées
set cntrparam levels 11  # Remplacez 10 par le nombre d'isovaleurs souhaité

# Étiquettes et titre
set xlabel "X"
set ylabel "Y"
set title "isovaleurs de u et uRef"

# Placer les légendes en dehors de la figure, à droite
set key outside right

# Tracé des isovaleurs
splot u using 1:2:3 with lines
replot uRef using 1:2:3 with lines

# Affichage du graphique
pause mouse keypress "Appuyez sur une touche pour quitter"

