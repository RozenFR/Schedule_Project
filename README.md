# Ad
Installer JETBRAINS :
- CLion
- Intellij IDEA
- WebStorm
- PHPStorm
- PyCharm
- Android Studio

Logiciel professionnel pour assurer un bon développement.

# Scheduling Project
Ce projet a été créer par 2 étudiant de l'université UFR de Metz en France

# Créateur
Rozen & Gyumi

# Informations
Le programme tourne avec la version JAVA SE 16 et JAVAFX 16.

Modification du fichier utilities.c et utilities.h :
- Remplacement de min par intmin
- Remplacement de max par intmax

Modification du fichier schedule.h et schedule.c :
- Remplacement de makespan par Makespan

## Windows

Si le programme tourne sous window, vous devrez supprimer le fichier .so situé dans le fichier java/lib.

Pour lancer le programme :
```shell
# Pour lancer l'application faire :
javac --module-path="PATH TO JAVAFX LIB" --add-modules javafx.controls,javafx.fxml application/App.java
java -Djava.library.path=./lib --module-path="PATH TO JAVAFX LIB" --add-modules javafx.controls,javafx.fxml application/App.java
```

## Linux

Si le programme tourne sous linux, vous devrez supprimer le fichier .dll situé dans le fichier java/lib.

