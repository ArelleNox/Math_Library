# **Librairie Mathématique / Demo Pong**



# Librairie Matheamtique


## 1. Informations Générales
- Projet : Ce projet consiste à recréer une librairie mathématique inspirée de Unity en C++. Elle a été conçue pour être utilisée dans des projets graphiques ou de jeux vidéo, notamment pour le développement d’un jeu de Pong avec SFML 3.0. Le développement s’est étalé sur deux semaines.
- Janelle : Vec2, Quaternion, Mat4x4, Pong.
- Julia : Vec3, Mat4x4, UnitTest, Pong


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
 
```cpp
class Vector2{
private:
	T x;
	T y;

public:
	/// CONSTRUCTOR
	Vector2();
	Vector2(T x, T y);

	/// STATIC_PORPRETIES
	Vector2 Down();
	Vector2 Up();
	Vector2 Left();
	Vector2 Right();
	Vector2 One();
	Vector2 Zero();
	Vector2 PositiveInfinity();
	Vector2 NegativeInfinity();

	///PROPERTIES
	T Magnitude(); // UT
	Vector2 Normalized(); // UT
	T SqrtMagnitude(); // UT
	T This(int i); // UT
	T X() const; // UT
	T Y() const; // UT

	///PUBLIC METHODS
	bool Equal(Vector2 other); // UT
	void Normalize(); // UT
	void Set(T newX, T newY); // UT
	std::string ToString(); // UT

	/// STATIC METHODS
	static T Angle(Vector2 a, Vector2 b); // UT
	static Vector2 ClampMagnitude(Vector2& a, T MaxLenght); // UT
	static T Distance(Vector2& a, Vector2& b); // UT
	static T Dot(Vector2& a, Vector2& b); // UT
	static Vector2 Lerp(Vector2 a, Vector2 b, T t); // UT
	static Vector2 LerpUnclamped(Vector2 a, Vector2 b, T t); // UT
	static Vector2 Min(Vector2& a, Vector2& b); // UT
	static Vector2 Max(Vector2& a, Vector2& b); // UT
	static Vector2 MoveTowards(Vector2 current, Vector2 target, T maxDistanceDelta); // UT
	static Vector2 Perpendicular(Vector2 inDirection); // UT
	static Vector2 Scale(Vector2& a, Vector2& b);// UT
	static T SignedAngle(Vector2 from, Vector2 to); // UT
	
	// CONVERSIONS

	Vector3<T> ToVector3() const;
	static Vector2<T> ToVector2(Vector3<T>& vec);

	///OPERATOR

	Vector2 operator-(const Vector2& other) const;
	Vector2 operator+(const Vector2& other) const;
	Vector2 operator*(const Vector2& other) const;
	Vector2 operator*(T scalar) const;
	Vector2 operator/(const Vector2& other) const;
	Vector2 operator/(T scalar) const;

	bool operator==(const Vector2& other) const;
	bool operator!=(const Vector2& other) const;

	template<typename TypeToCastTo>
	explicit operator TypeToCastTo()
	{
		return TypeToCastTo{ x, y };
	}
};

typedef Vector2<float> Vector2f;

```


### 3.2. Vector3<T>
- Vecteur 3D générique.
- Utilisé pour les calculs spatiaux et les directions en 3D.
- Méthodes similaires à Vector2<T> avec ajout de Z().
  
```cpp
template <typename T>

class Vector3 {
public:

	T x;
	T y;
	T z;

public:
	Vector3();

	Vector3(T x, T y, T z);

	///// STATIC_PORPRETIES

	static Vector3 Down();
	static Vector3 Up();
	static Vector3 Right();
	static Vector3 Left();
	static Vector3 Back();
	static Vector3 Foward();
	static Vector3 One();
	static Vector3 Zero();
	static Vector3 negativeInfinity();
	static Vector3 positiveInfinity();

	/////PORPRETIES

	Vector3 Normalized(); // UT
	T Magnitude(); // UT
	T SqrMagnitude(); // UT
	T This(int i); // UT
	T X(); // UT
	T Y(); // UT
	T Z(); // UT

	///// PUBLIC METHODS

	bool Equals(Vector3& other); // UT
	void Set(T newX, T newY, T newZ); // UT
	std::string ToString(); // UT
	void Normalize(); // UT

	/////// STATIC METHODS

	static T Angle(Vector3 a, Vector3 b); // UT
	static Vector3 ClampMagnitude(Vector3& a, T MaxLenght); // UT
	static Vector3 Cross(Vector3& a, Vector3& b); // UT
	static T Distance(Vector3& a, Vector3& b); // UT
	static T Dot(Vector3& a, Vector3& b); // UT
	static Vector3 Lerp(Vector3 a, Vector3 b, T t); // UT
	static Vector3 LerpUnclamped(Vector3 a, Vector3 b, T t); // UT
	static Vector3 Min(Vector3& a, Vector3& b); // UT
	static Vector3 Max(Vector3& a, Vector3& b); // UT
	static Vector3 MoveTowards(Vector3 current, Vector3 target, T maxDistanceDelta); // UT
	static void OrthoNormalize(Vector3& normal, Vector3& tangent); // UT
	static Vector3 Project(Vector3 vector, Vector3 onNormal); // UT
	static Vector3 ProjectOnPlane(Vector3 vector, Vector3 planeNormal); // UT
	static Vector3 Reflect(Vector3 inDirection, Vector3 inNormal);	// UT
	static Vector3 RotateTowards(Vector3 current, Vector3 target, T maxRadiansDelta, T maxMagnitudeDelta); // UT
	static Vector3 Scale(Vector3& a, Vector3& b); // UT
	static T SignedAngle(Vector3 from, Vector3 to, Vector3 axis); // UT
	static Vector3 Slerp(Vector3 a, Vector3 b, T t); // UT
	static Vector3 SlerpUnclamped(Vector3 a, Vector3 b, T t); // UT


	/////////OPERATOR

	Vector3 operator-(const Vector3& other) const;
	Vector3 operator+(const Vector3& other) const;
	Vector3 operator*(const Vector3& other) const;
	Vector3 operator*(T scalar) const;
	Vector3 operator/(const Vector3& other) const;
	Vector3 operator/(T scalar) const;
	bool operator==(const Vector3& other) const;
	bool operator!=(const Vector3& other) const;

	template<typename TypeToCastTo>
	explicit operator TypeToCastTo()
	{
		return TypeToCastTo{x, y, z};
	}
};
```

### 3.3. Matrix4x4<T>
- Matrice 4x4 pour les transformations (translation, rotation, mise à l’échelle).
- Utilisée pour les calculs de transformation dans les scènes 3D.
- Méthodes : Multiply(), Transpose(), Identity().

 ```cpp
template <typename T>
class Matrix4x4{
private:
	std::array<T, 16> m;
	
public:
	Matrix4x4();
	Matrix4x4(const std::array<T, 16>& m);

	T& operator()(int row, int col);
	T  operator()(int row, int col) const;

	////// STATIC PROPRETIES

	static Matrix4x4 Identity(); // UT
	static Matrix4x4 Zero(); // UT


	/////PROPRETIES

	T Cofactor(int row, int col) const;
	T Determinant() const;
	Matrix4x4 Inverse() const; // UT
	Vector3<T> lossyScale();
	Quaternion<T> rotation();
	bool isIdentity() const; // UT
	T This(int i, int j) const;
	Matrix4x4 Transpose() const; // UT

	//////PUBLIC METHODS

	Vector3<T> GetColumn(int index) const;
	Vector3<T> GetRow(int index) const;
	void SetColumn(int index, const Vector3<T>& column);
	void SetRow(int index, const Vector3<T>& row);
	Vector3<T> GetPosition() const;
	Vector3<T> MultiplyPoint(const Vector3<T>& point) const;
	Vector3<T> MultiplyPoint3x4(const Vector3<T>& point) const;
	Vector3<T> MultiplyVector(const Vector3<T>& vec) const;
	void SetTRS(const Vector3<T>& position, const Quaternion<T>& rotation, const Vector3<T>& scale);
	bool ValidTRS() const;
	std::string ToString() const;

	////// STATIC METHODS
	static Matrix4x4<T> Frustum(T left, T right, T bottom, T top, T near, T far);
	static Matrix4x4<T> Inverse3DAffine(const Matrix4x4<T>& m);
	static Matrix4x4<T> LookAt(const Vector3<T>& eye, const Vector3<T>& center, const Vector3<T>& up);
	static Matrix4x4<T> Ortho(T left, T right, T bottom, T top, T near, T far); // UT
	static Matrix4x4<T> Perspective(T fovY, T aspect, T near, T far);
	static Matrix4x4<T> Rotate(const Quaternion<T>& q);
	static Matrix4x4<T> Scale(const Vector3<T>& scale); // UT
	static Matrix4x4<T> Translate(const Vector3<T>& translation); // UT
	static Matrix4x4<T> TRS(const Vector3<T>& position, const Quaternion<T>& rotation, const Vector3<T>& scale);

	///// OPERATOR
	std::array<T, 4>& operator[](int row);
	const std::array<T, 4>& operator[](int row) const;
	Matrix4x4 operator*(const Matrix4x4& rhs) const;
	bool operator==(const Matrix4x4& rhs) const;
	bool operator!=(const Matrix4x4& rhs) const;
    
  ```

### 3.4. Quaternion<T>
- Représentation des rotations en 3D.
- Permet d’éviter les problèmes de gimbal lock.
- Méthodes : Normalize(), ToMatrix(), FromAxisAngle().

```cpp
template<typename T = float>
class Quaternion
{
public:
    T x, y, z, w;

    constexpr Quaternion();
    constexpr Quaternion(T x, T y, T z, T w);

    static Quaternion Identity();
    static T Dot(const Quaternion& a, const Quaternion& b);
    static T Angle(const Quaternion& a, const Quaternion& b);
    static Quaternion Lerp(const Quaternion& a, const Quaternion& b, T t);
    static Quaternion Slerp(const Quaternion& a, const Quaternion& b, T t);
    const static Quaternion FromAxisAngle( Vector3<T>& axis, T angle);
    static Quaternion AngleAxis(T angle, const Vector3<T>& axis);
    static Quaternion FromEuler(const Vector3<T>& eulerRad);

    void ToAxisAngle(Vector3<T>& outAxis, T& outAngle) const;
    Vector3<T> ToEuler() const;

    T Length() const;
    Quaternion Normalized() const;
    void Normalize();
    Quaternion Conjugate() const;
    Quaternion Inverse() const;

    Quaternion operator*(const Quaternion& rhs) const;
    Vector3<T> operator*(const Vector3<T>& v) const;
    bool operator==(const Quaternion& q) const;

    template<typename TypeToCastTo>
    explicit operator TypeToCastTo()
    {
        return TypeToCastTo{x, y, z, w};
    }

public:
    static constexpr T kEpsilon = static_cast<T>(1e-6);
    static constexpr T PI = static_cast<T>(3.14159265358979323846);
};

using Quat = Quaternion<float>;

```

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

