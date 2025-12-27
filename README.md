# Custom Game Engine

Un moteur de jeu Open Source à but éducatif, conçu en C++ avec **SDL3** et **OpenGL**. Ce projet vise à fournir une base solide pour le développement de jeux 2D et 3D avec une séparation stricte entre l'éditeur et le runtime.

## 🚀 Concept

Ce projet est né de la volonté d'apprendre et de comprendre les mécanismes internes d'un moteur de jeu. Il n'est pas seulement un outil de création, mais aussi un terrain d'expérimentation pour les concepts d'architecture logicielle appliquée au jeu vidéo.

L'objectif principal est de proposer un environnement de développement complet avec :
- Un **Editor** pour concevoir les scènes et gérer les ressources.
- Un **Runtime** léger et performant pour l'exécution finale du jeu.
- Un **Core Engine** partagé qui gère la logique de base.

## 🛠 Technologies

Le moteur s'appuie sur des bibliothèques robustes et modernes :
- **SDL3** : Pour la gestion des fenêtres, des entrées utilisateur et du cycle de vie de l'application.
- **OpenGL** : API de rendu graphique pour la 2D et la 3D.
- **ImGui** : Utilisé pour l'interface de l'éditeur (Editor) afin d'offrir des outils de débogage et de manipulation en temps réel.
- **GLM (OpenGL Mathematics)** : Pour tous les calculs mathématiques liés à l'espace 2D et 3D.
- **CMake** : Pour une gestion simple et multiplateforme de la compilation.

## 🏗 Architecture du Projet

Le projet est divisé en trois cibles principales :
1. **Engine (Shared Library)** : Le cœur du système (Core). Il contient le `SceneTree`, les `RenderingServers` (2D/3D), le système d'événements et la gestion des `GameObject` et `Components`.
2. **Editor (Executable)** : L'application graphique permettant de manipuler le moteur, d'éditer les scènes et de prévisualiser les changements.
3. **Runtime (Executable)** : L'exécutable minimaliste chargé de charger une scène et de la faire tourner sans la surcharge de l'éditeur.

## 📂 Structure des dossiers
- `core/` : Code source du moteur (Engine).
- `editor/` : Code source de l'éditeur.
- `runtime/` : Code source du lanceur de jeu.
- `thirdparty/` : Bibliothèques tierces (SDL, ImGui, GLM).

## ⚙️ Compilation

### Prérequis
- Un compilateur supportant le **C++20**.
- **CMake** version 3.20 ou supérieure.

### Étapes
1. Cloner le dépôt et ses sous-modules (si applicable) :
   ```powershell
   git clone https://github.com/[votre-utilisateur]/Custom-Game-Engine.git
   cd Custom-Game-Engine
   ```
2. Générer les fichiers de build avec CMake :
   ```powershell
   cmake -B bin
   ```
3. Compiler le projet :
   ```powershell
   cmake --build bin
   ```

## 📜 Licence

Ce projet est un logiciel Open Source.

---
*Projet à but éducatif développé avec passion.*
