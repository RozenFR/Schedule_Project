# Définit la version minimum de cmake
cmake_minimum_required(VERSION 3.6)
# Définit le nom du projet
project(Schedule_Project C)
# Définit le type de build (important pour la génération du projet sln)
set(CMAKE_BUILD_TYPE Debug)

# Ajout de jni.h
find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
# Ajout du dossier /include dans les includes
include_directories(include ${PROJECT_BINARY_DIR})
# Ajout des fichiers sources du dossier /src
file(GLOB SOURCES "src/*.c")

# Exec
add_executable(schedule_launch ${SOURCES} )

# définition des macros de sorties du fichier include
include(GenerateExportHeader)
# Créer le fichier .lib
add_library(schedulelibrary SHARED ${SOURCES})
# Génération du projet SLN
GENERATE_EXPORT_HEADER (schedulelibrary
        BASE_NAME schedulelibrary
        EXPORT_MACRO_NAME schedulelibrary_EXPORT
        EXPORT_FILE_NAME schedulelibrary_Export.h
        STATIC_DEFINE schedulelibrary_BUILT_AS_STATIC
        )