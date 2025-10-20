# **Librairie Mathématique / Demo Pong**



# Librairie Matheamtique


## 1. Informations Générales
- Projet : Ce projet consiste à recréer une librairie mathématique inspirée de Unity en C++. Elle a été conçue pour être utilisée dans des projets graphiques ou de jeux vidéo, notamment pour le développement d’un jeu de Pong avec SFML 3.0. Le développement s’est étalé sur deux semaines.



## 2. Objectifs du Projet
- Reproduire les types mathématiques essentiels utilisés dans les moteurs de jeu modernes (Unity, Unreal).
- Créer une base réutilisable pour des projets 2D et 3D en C++.
- Faciliter les calculs vectoriels et matriciels dans des environnements graphiques comme SFML.


## 3. Types Implémentés

### 3.1. Vector2<T>
- Vecteur 2D générique.

- Comporte les méthodes :
    - X() / Y() pour accéder aux coordonnées.
    - Opérateurs +, -, *, / pour les opérations vectorielles.
    - Méthodes utilitaires : Magnitude(), Normalize(), Dot().

### 3.2. Vector3<T>
- Vecteur 3D générique.
- Utilisé pour les calculs spatiaux et les directions en 3D.
- Méthodes similaires à Vector2<T> avec ajout de Z().

### 3.3. Matrix4x4<T>
- Matrice 4x4 pour les transformations (translation, rotation, mise à l’échelle).
- Utilisée pour les calculs de transformation dans les scènes 3D.
- Méthodes : Multiply(), Transpose(), Identity().

### 3.4. Quaternion<T>
- Représentation des rotations en 3D.
- Permet d’éviter les problèmes de gimbal lock.
- Méthodes : Normalize(), ToMatrix(), FromAxisAngle().


## 4. Tests Unitaires
- Chaque type a été testé avec des cas simples :
- Vérification des opérations arithmétiques.
- Comparaison des résultats attendus.
- Tests de robustesse sur les types génériques.


## 5. Fichiers Principaux
- Vector2.h / Vector2.cpp : Définition du vecteur 2D.
- Vector3.h / Vector3.cpp : Définition du vecteur 3D.
- Matrix4x4.h / Matrix4x4.cpp : Définition de la matrice 4x4.
- Quaternion.h / Quaternion.cpp : Définition du quaternion.
- UnitTest : Dossier contenant les tests unitaires pour chaque type.


## 6. Utilisation dans des Projets
- Pong SFML 3.0 : Utilisation de Vector2f pour gérer les positions et les déplacements des raquettes.
- Extensible : Peut être intégré dans des moteurs maison ou des projets OpenGL/DirectX.


## 7. Outils et Technologies
- Langage : C++17
- Environnement : Visual Studio / VS Code


## 8. Évolutions Possibles
- Ajout de Transform combinant position, rotation et échelle.
- Intégration avec des moteurs physiques.
- Ajout de Vector4<T> et Matrix3x3<T>.


# Pong

## **1. Informations Générales**

**Résumé** :  Ce projet consiste à recréer une librairie mathématique inspirée de Unity en C++, puis à l’utiliser pour développer un jeu de Pong avec SFML 3.0. Le développement s’est étalé sur deux semaines.


## **2. Concept de Base**

- **Gameplay principal** : Deux joueurs contrôlent chacun une raquette pour renvoyer une balle. Le but est d’empêcher la balle de passer derrière sa raquette tout en essayant de marquer contre l’adversaire.  
- **Objectifs** :
  - Court terme : Réagir rapidement pour renvoyer la balle.
  - Long terme : Gagner en marquant le plus de points. 
- **Déroulement** : Le jeu se joue en boucle jusqu’à ce que l’utilisateur quitte la partie. 
- **Style de progression** : Jeu d’arcade classique, basé sur la précision et les réflexes.


## **3. Méchaniques de Jeu**

### **3.1. Contrôle du joueur**
- **Déplacement** :
    - Joueur 1 : W pour monter, S pour descendre.
    - Joueur 2 : Flèche Haut pour monter, Flèche Bas pour descendre.  
- **Vitesse** : Chaque raquette se déplace à une vitesse constante définie dans le constructeur.

### **3.2. Système de Scoring**
- **Score** : Chaque fois qu’un joueur rate la balle, l’adversaire gagne un point.

## **4. Architecture du Code**

### **4.1. Fichiers principaux**

- **Player.h / Player.cpp** : Classe représentant les raquette.
- ** Ball.h / Ball.cpp** : Classe représentant la balle.
- **Game.h / Game.cpp** : Boucle principale du jeu.
- **Score.h / Score.cp** : Classe représentant le score.
- **main.cpp** : Point d’entrée du programme.

### **4.2. Fonctions clés**

- Player::update(float deltaTime, bool moveUp, bool moveDown) : Met à jour la position de la raquette.
- Player::draw(sf::RenderWindow& window) : Dessine la raquette à l’écran.
- Game::run() : Contient toute la logique du jeu (événements, mise à jour, rendu).


## **5. Style Visuel**
- Style minimaliste en blanc sur fond noir.
- Raquettes : rectangles blancs.
- Balle : cercle blanc.
  

## **6. Systèmes et Outils**

### **6.1. Moteur de Jeu**
- **SFML 3.0.2** : Utilisé pour la fenêtre, les entrées clavier, et le rendu graphique

### **6.2. Librairie Mathématiques**
- Créée entièrement en C++ avec des templates et des opérateurs personnalisés. 


## **8. Évolutions Possibles**

- Menu de démarrage et écran de fin.
- Effets sonores et musiques.
- Mode solo contre une IA.


# Math Library / Pong Demo

# Math Library

## 1. General Information
- Team Project Summary: This project involved recreating a math library inspired by Unity in C++. It was designed to be used in graphical or game development projects, including a Pong game built with SFML 3.0. Development spanned two weeks.

## 2. Project Goals
- Recreate essential math types used in modern game engines (Unity, Unreal).
- Build a reusable foundation for 2D and 3D projects in C++.
- Simplify vector and matrix calculations in graphical environments like SFML.

## 3. Implemented Types

### 3.1. Vector2<T>
- Generic 2D vector.
- Includes:
    - X() / Y() accessors.
    - Operators: +, -, *, / for vector math.
    - Utility methods: Magnitude(), Normalize(), Dot().

### 3.2. Vector3<T>
- Generic 3D vector.
- Used for spatial calculations and 3D directions.
- Similar methods to Vector2<T>, with added Z().

### 3.3. Matrix4x4<T>
- 4x4 matrix for transformations (translation, rotation, scaling).
- Used for 3D scene transformations.
- Methods: Multiply(), Transpose(), Identity().

### 3.4. Quaternion<T>
- Represents 3D rotations.
- Prevents gimbal lock.
- Methods: Normalize(), ToMatrix(), FromAxisAngle().

## 4. Unit Testing
- Each type was tested with simple cases:
- Arithmetic operations.
- Expected result comparisons.
- Robustness checks for generic types.

## 5. Key Files
- Vector2.h / Vector2.cpp: 2D vector definition.
- Vector3.h / Vector3.cpp: 3D vector definition.
- Matrix4x4.h / Matrix4x4.cpp: 4x4 matrix definition.
- Quaternion.h / Quaternion.cpp: Quaternion definition.
- UnitTest/: Folder containing unit tests for each type.

## 6. Project Integration
- Pong SFML 3.0: Vector2f used for paddle positions and movement.
- Extensibility: Can be integrated into custom engines or OpenGL/DirectX projects.

## 7. Tools & Technologies
- Language: C++17
- Environment: Visual Studio / VS Code

## 8. Future Improvements
- Add a Transform class combining position, rotation, and scale.
- Integrate with physics engines.
- Add Vector4<T> and Matrix3x3<T>.

# Pong Game

## 1. General Information
- Summary: This project uses the custom math library to build a Pong game with SFML 3.0. Development lasted two weeks.

## 2. Core Concept
- Main Gameplay: Two players control paddles to bounce a ball back and forth. The goal is to prevent the ball from passing your paddle and score against your opponent.

- Objectives:
    - Short-term: React quickly to return the ball.
    - Long-term: Win by scoring the most points.
    - Flow: The game runs in a loop until the user exits.
- Progression Style: Classic arcade gameplay focused on precision and reflexes.

## 3. Game Mechanics

### 3.1. Player Controls
- Movement:
    - Player 1: W to move up, S to move down.
    - Player 2: Up Arrow to move up, Down Arrow to move down.
- Speed: Each paddle moves at a constant speed defined in its constructor.

### 3.2. Scoring System
- Score: Each time a player misses the ball, the opponent scores a point.

## 4. Code Architecture

### 4.1. Main Files
- Player.h / Player.cpp: Paddle class.
- Ball.h / Ball.cpp: Ball class.
- Game.h / Game.cpp: Main game loop.
- Score.h / Score.cpp: Score tracking class.
- main.cpp: Program entry point.

### 4.2. Key Functions
- Player::update(float deltaTime, bool moveUp, bool moveDown): Updates paddle position.
- Player::draw(sf::RenderWindow& window): Renders the paddle.
- Game::run(): Contains the full game loop (events, updates, rendering).

## 5. Visual Style
- Minimalist white-on-black design.
- Paddles: white rectangles.
- Ball: white circle.

## 6. Systems & Tools

### 6.1. Game Engine
- SFML 3.0.2: Used for window creation, keyboard input, and rendering.

### 6.2. Math Library
- Fully custom-built in C++ using templates and operator overloading.

## 7. Future Improvements
- Start menu and end screen.
- Sound effects and music.
- Solo mode with AI opponent.
