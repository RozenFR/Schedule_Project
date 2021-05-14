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
Le programme a été tourné avec la version JAVA SE 16 et JAVAFX 16.
Fonctionne aussi avec Java SE 11 et JAVAFX 11.

Modification du fichier utilities.c et utilities.h :
- Remplacement de min par intmin
- Remplacement de max par intmax

Modification du fichier schedule.h et schedule.c :
- Remplacement de makespan par Makespan

Makefile et CMake
- Le makefile présent dans le projet est uniquement présent pour faire tourner la partie C
```shell
make clean run
```
- le CMake présent dans le projet permet de créer un exécutable et les librairy C pour le java
```shell
cd out
cmake ..
cmake --build .
```

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

