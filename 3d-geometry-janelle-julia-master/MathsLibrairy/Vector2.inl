#pragma once

/// CONSTRUCTOR

template <typename T>
ml::Vector2<T>::Vector2() {} // constructeur par defaut


template <typename T>
ml::Vector2<T>::Vector2(T x, T y) : x(x), y(y) {} // initialise les composantes x et y du vecteur


/// STATIC_PORPRETIES

template <typename T>
ml::Vector2<T> ml::Vector2<T>::Down() { return ml::Vector2(0.0f, -1.0f); } // retourne le vecteur unitaire vers le bas

template <typename T>
ml::Vector2<T> ml::Vector2<T>::Up() { return ml::Vector2(0.0f, 1.0f); } // retourne le vecteur unitaire vers le haut

template <typename T>
ml::Vector2<T> ml::Vector2<T>::Left() { return ml::Vector2(-1.0f, 0.0f); } // retourne le vecteur unitaire vers la gauche

template <typename T>
ml::Vector2<T> ml::Vector2<T>::Right() { return ml::Vector2(1.0f, 0.0f); } // retourne le vecteur unitaire vers la droite

template <typename T>
ml::Vector2<T> ml::Vector2<T>::One() { return ml::Vector2(1.0f, 1.0f); }    // retourne le vecteur (1,1)

template <typename T>
ml::Vector2<T> ml::Vector2<T>::Zero() { return ml::Vector2(0.0f, 0.0f); } // retourne le vecteur (0,0)

template <typename T>
ml::Vector2<T> ml::Vector2<T>::PositiveInfinity() { return Vector2(x = std::numeric_limits<T>::infinity(), y = std::numeric_limits<T>::infinity()); };    // retourne le vecteur avec des composantes infinies positives

template <typename T>
ml::Vector2<T> ml::Vector2<T>::NegativeInfinity() { return Vector2(x = -1 * (std::numeric_limits<T>::infinity()), -1 * (y = std::numeric_limits<T>::infinity())); }; // retourne le vecteur avec des composantes infinies négatives


///PROPERTIES

template <typename T>
T ml::Vector2<T>::Magnitude() { return std::sqrt(x * x + y * y); } // retourne la longueur du vecteur

template <typename T>
ml::Vector2<T> ml::Vector2<T>::Normalized() { // retourne une copie normalisée du vecteur

    T mag = Magnitude();
    if (mag != 0.0f)
        return ml::Vector2(x / mag, y / mag);
    else
        return ml::Vector2(0.0f, 0.0f);
}

template <typename T>
T ml::Vector2<T>::SqrtMagnitude() { // retourne la magnitude au carré : bien pour les comparaisons
	T mag = Magnitude();
    return pow((mag),2);
}

template <typename T>
T ml::Vector2<T>::This(int i) { // retourne la composante x ou y en fonction de l'indice i (0 pour x, 1 pour y)
    if (i == 0) return x;
    else if (i == 1) return y;
}

template <typename T>
T ml::Vector2<T>::X() const { return x; } // retourne la composante x du vecteur

template <typename T>
T ml::Vector2<T>::Y() const { return y; } // retourne la composante y du vecteur


///PUBLIC METHODS

template <typename T>
bool ml::Vector2<T>::Equal(Vector2<T> other) { // compare deux vecteurs
    if (x == other.x && y == other.y) return true;
    else return false;
}

template <typename T>
void ml::Vector2<T>::Normalize() { // normalise le vecteur 
    T mag = Magnitude();
    x = x / mag;
    y = y / mag;
}

template <typename T>
void ml::Vector2<T>::Set(T newX, T newY) { x = newX, y = newY; } // permet de modifier les valeurs du vecteur

template <typename T>
std::string ml::Vector2<T>::ToString() { // retourne une representation textuelle du vecteur
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}


///STATIC METHOD

template <typename T>
T ml::Vector2<T>::Angle(Vector2<T> a, Vector2<T> b) { // retourne l'angle entre deux vecteurs
    float dotProd = a.x * b.x + a.y * b.y;
    float lenA = std::sqrt(a.x * a.x + a.y * a.y);
    float lenB = std::sqrt(b.x * b.x + b.y * b.y);
    return std::acos(dotProd / (lenA * lenB)); // retourne en radians

}

template <typename T>
ml::Vector2<T> ml::Vector2<T>::ClampMagnitude(Vector2<T>& a, T maxLength) { // contraint la longueur d'un vecteur a une valeur maxLength
    T mag = a.Magnitude();
    if (mag > maxLength)
        return a.Normalized() * maxLength;
    return a;
}

template <typename T>
T ml::Vector2<T>::Distance(Vector2<T>& a, Vector2<T>& b) { // distance entre deux vecteurs
    return Vector2<T>(a - b).Magnitude();
}

template <typename T>
T ml::Vector2<T>::Dot(Vector2<T>& a, Vector2<T>& b) { // produit scalaire entre deux vecteurs
    return (a.x * b.x + a.y * b.y);
}

template <typename T>
ml::Vector2<T> ml::Vector2<T>::Lerp(Vector2<T> a, Vector2<T> b, T t) { // interpolation linéaire entre deux vecteurs en fixant t entre 0 et 1 : fait bouger un vecteur a vers un vecteur b en fonction de t
    if (t < 0.0f) t = 0.0f;
    if (t > 1.0f) t = 1.0f;
    return a + (b - a) * t;
}

template <typename T>
ml::Vector2<T> ml::Vector2<T>::LerpUnclamped(Vector2<T> a, Vector2<T> b, T t) { // même chose que lerp mais sans clamp t entre 0 et 1
    return a + (b - a) * t;
}

template <typename T>
ml::Vector2<T> ml::Vector2<T>::Min(Vector2<T>& a, Vector2<T>& b) { // retourne le plus petite valeur
    return Vector2<T>(std::fmin(a.x, b.x), std::fmin(a.y, b.y));
}

template <typename T>
ml::Vector2<T> ml::Vector2<T>::Max(Vector2<T>& a, Vector2<T>& b) { // retourne le plus grande valeur
    return Vector2<T>(std::fmax(a.x, b.x), std::fmax(a.y, b.y));
}

template <typename T>
ml::Vector2<T> ml::Vector2<T>::MoveTowards(Vector2<T> current, Vector2<T> target, T maxDistanceDelta) { // Déplace un vecteur current vers un vecteur target d'une distance maxDistanceDelta
    Vector2<T> toVector = target - current;
    T dist = toVector.Magnitude();
    if (dist <= maxDistanceDelta || dist == 0.0f) {
        return target;
    }
    return current + toVector / dist * maxDistanceDelta;
}

template <typename T>
ml::Vector2<T> ml::Vector2<T>::Perpendicular(Vector2<T> inDirection) { // retourne un vecteur perpendiculaire au vecteur donné
    return Vector2<T>(-inDirection.y, inDirection.x);
}

template <typename T>
ml::Vector2<T> ml::Vector2<T>::Scale(Vector2<T>& a, Vector2<T>& b) { // Redimmensionne un vecteur en fonction d'un autre vecteur
    return Vector2<T>(a.x * b.x, a.y * b.y);
}

template <typename T>
T ml::Vector2<T>::SignedAngle(Vector2<T> from, Vector2<T> to) { // retourne l'angle entre deux vecteurs en tenant compte du sens (positif ou negatif)
    T angle = Angle(from, to);
    T cross = from.x * to.y - from.y * to.x;
    return (cross < 0) ? -angle : angle;
}

template <typename T>
ml::Vector3<T> ml::Vector2<T>::ToVector3() const { // permet de passer un vecteur 2 en vecteur 3
	T zValue = 0;
    return ml::Vector3<T>(this->x, this->y, zValue);
}

template <typename T>
ml::Vector2<T> ml::Vector2<T>::ToVector2(Vector3<T>& vec) {  // permet de passer un vecteur 3 en vecteur 2
    return Vector2<T>(vec.x, vec.y);
}


///OPERATOR        OVERLOAD des operateurs existant pour pouvoirs les appliquer a nos vecteurs

template <typename T>
ml::Vector2<T> ml::Vector2<T>::operator-(const Vector2<T>& other) const {
    return Vector2<T>(this->x - other.x, this->y - other.y);
}

template <typename T>
ml::Vector2<T> ml::Vector2<T>::operator+(const Vector2<T>& other) const {
    return Vector2<T>(this->x + other.x, this->y + other.y);
}

template <typename T>
ml::Vector2<T> ml::Vector2<T>::operator*(const Vector2<T>& other) const {
    return Vector2<T>(this->x * other.x, this->y * other.y);
}

template <typename T>
ml::Vector2<T> ml::Vector2<T>::operator*(T scalar) const {
    return Vector2<T>(this->x * scalar, this->y * scalar);
}

template <typename T>
ml::Vector2<T> ml::Vector2<T>::operator/(const Vector2<T>& other) const {

    T newX = (other.x != 0.0f) ? (this->x / other.x) : 0.0f;
    T newY = (other.y != 0.0f) ? (this->y / other.y) : 0.0f;
    return Vector2<T>(newX, newY);
}

template <typename T>
ml::Vector2<T> ml::Vector2<T>::operator/(T scalar) const {
    if (scalar != 0.0f)
        return Vector2<T>(this->x / scalar, this->y / scalar);
    else
        return Vector2<T>(0.0f, 0.0f);
}

template <typename T>
bool ml::Vector2<T>::operator==(const Vector2<T>& other) const {
    return this->x == other.x && this->y == other.y;
}

template <typename T>
bool ml::Vector2<T>::operator!=(const Vector2<T>& other) const {
    return !(*this == other);
}