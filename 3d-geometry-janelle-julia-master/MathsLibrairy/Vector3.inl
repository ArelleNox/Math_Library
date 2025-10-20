#pragma once


template <typename T>
ml::Vector3<T>::Vector3(T x, T y, T z) : x(x), y(y), z(z) { x = 0.0f; y = 0.0f; z = 0.0f; } // Constructeur avec paramètres

template <typename T>
ml::Vector3<T>::Vector3() {} // Constructeur par défaut


//// STATIC_PROPRETIES

template <typename T>
ml::Vector3<T> ml::Vector3<T>::Down() { return Vector3(0.0f, -1.0f, 0.0f); } // Renvoies le vecteur unitaire pointant vers le bas
template <typename T>
ml::Vector3<T> ml::Vector3<T>::Up() { return Vector3(0.0f, 1.0f, 0.0f); } // Renvoies le vecteur unitaire pointant vers le haut
template <typename T>
ml::Vector3<T> ml::Vector3<T>::Right() { return Vector3(1.0f, 0.0f, 0.0f); } // Renvoies le vecteur unitaire pointant vers la droite
template <typename T>
ml::Vector3<T> ml::Vector3<T>::Left() { return Vector3(-1.0f, 0.0f, 0.0f); } // Renvoies le vecteur unitaire pointant vers la gauche
template <typename T>
ml::Vector3<T> ml::Vector3<T>::Back() { return Vector3(0.0f, 0.0f, -1.0f); } // Renvoies le vecteur unitaire pointant vers l'arrière
template <typename T>
ml::Vector3<T> ml::Vector3<T>::Foward() { return Vector3(0.0f, 0.0f, 1.0f); } // Renvoies le vecteur unitaire pointant vers l'avant
template <typename T>
ml::Vector3<T> ml::Vector3<T>::One() { return Vector3(1.0f, 1.0f, 1.0f); } // Renvoies le vecteur (1,1,1)
template <typename T>
ml::Vector3<T> ml::Vector3<T>::Zero() { return Vector3(0.0f, 0.0f, 0.0f); } // Renvoies le vecteur (0,0,0)
template <typename T>
ml::Vector3<T> ml::Vector3<T>::positiveInfinity() { return Vector3(std::numeric_limits<T>::infinity(), std::numeric_limits<T>::infinity(), std::numeric_limits<T>::infinity()); } // Renvoies le vecteur (infini, infini, infini)
template <typename T>
ml::Vector3<T> ml::Vector3<T>::negativeInfinity() { return Vector3(-1 * (std::numeric_limits<T>::infinity()), -1 * (std::numeric_limits<T>::infinity()), -1 * (std::numeric_limits<T>::infinity())); } // Renvoies le vecteur (-infini, -infini, -infini)


///// PROPRETIES

template <typename T>
ml::Vector3<T> ml::Vector3<T>::Normalized() { // Renvoies une copie normalisée du vecteur
	T mag = Magnitude();
	if (mag != 0.0f)
		return ml::Vector3(x / mag, y / mag, z / mag);
	else
		return ml::Vector3(0.0f, 0.0f, 0.0f);
}

template <typename T>
T ml::Vector3<T>::Magnitude() { return std::sqrt(x * x + y * y + z * z); } // Renvoies la taille du vecteur

template <typename T>
T ml::Vector3<T>::SqrMagnitude() { T mag = (*this).Magnitude();  return std::pow((mag), 2); } // Renvoies la taille au carré du vecteur 

template <typename T>
T ml::Vector3<T>::This(int i) { // Renvoies la composante i du vecteur
	if (i == 0) return x;
	else if (i == 1) return y;
	else if (i == 2) return z;
}

template <typename T>
T ml::Vector3<T>::X() { return x; } // Renvoies la composante X du vecteur

template <typename T>
T ml::Vector3<T>::Y() { return y; } // Renvoies la composante Y du vecteur

template <typename T>
T ml::Vector3<T>::Z() { return z; } // Renvoies la composante Z du vecteur


///////////////// PUBLIC METHODS

template <typename T>
bool ml::Vector3<T>::Equals(Vector3<T>& other) { // Compare ce vecteur à un autre pour voir si ils sont égaux
	if (x == other.x && y == other.y && z == other.z) return true;
	else return false;
}

template <typename T>
void ml::Vector3<T>::Set(T newX, T newY, T newZ) { x = newX, y = newY, z = newZ; } // Défini les composantes du vecteur

template <typename T>
std::string ml::Vector3<T>::ToString() { // Renvoies une représentation textuelle du vecteur
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}


//////////////// STATIC METHODS

template <typename T>
T ml::Vector3<T>::Angle(Vector3<T> a, Vector3<T> b) { // Renvoies l'angle en radians entre deux vecteurs (positif)
	T dotProduct = Dot(a, b);
	T MagA = a.Magnitude();
	T MagB = b.Magnitude();

	T cosTheta = dotProduct / (MagA * MagB);
	return acos(cosTheta);
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::ClampMagnitude(Vector3<T>& a, T maxLength) { // Renvoie un vecteur avec une magnitude limitée à maxLength choisi
	T mag = a.Magnitude();
	if (mag > maxLength)
		return a.Normalized() * maxLength;
	return a;
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::Cross(Vector3<T>& a, Vector3<T>& b) { // Renvoie un produit de vecteur
	return Vector3((a.y * b.z) - (a.z * b.y), (a.z * b.x) - (a.x * b.z), (a.x * b.y) - (a.y * b.x));
}

template <typename T>
T ml::Vector3<T>::Distance(Vector3<T>& a, Vector3<T>& b) { // Renvoie la distance entre deux vecteurs
	return Vector3<T>(a - b).Magnitude();
}

template <typename T>
T ml::Vector3<T>::Dot(Vector3<T>& a, Vector3<T>& b) { // Renvoie le produit scalaire de deux vecteurs
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::Lerp(Vector3<T> a, Vector3<T> b, T t) { //  permet d'aller d'un vecteur a un autre progressivement de manière controlé
	if (t < 0.0f) t = 0.0f;
	if (t > 1.0f) t = 1.0f;
	return a + (b - a) * t;
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::LerpUnclamped(Vector3<T> a, Vector3<T> b, T t) { //  permet d'aller d'un vecteur a un autre progressivement de manière non controlé
	return a + (b - a) * t;
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::Min(Vector3<T>& a, Vector3<T>& b) { // Renvoie la plus petite valeur 
	return Vector3(std::fmin(a.x, b.x), std::fmin(a.y, b.y), fmin(a.z, b.z));
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::Max(Vector3<T>& a, Vector3<T>& b) { // Renvoie la plus grande valeur 
	return Vector3(std::fmax(a.x, b.x), std::fmax(a.y, b.y), fmax(a.z, b.z));
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::MoveTowards(Vector3<T> current, Vector3<T> target, T maxDistanceDelta) { // Renvoie un vecteur se rapprochant du vecteur target depuis le vecteur current
	Vector3 direction = target - current;
	T distance = direction.Magnitude();
	if (distance <= maxDistanceDelta || distance == 0.0f) {
		return target;
	}
	return current + direction / distance * maxDistanceDelta;
}

template <typename T>
void ml::Vector3<T>::Normalize() { // normalise un vecteur

	T mag = (*this).Magnitude();
	x = x / mag;
	y = y / mag;
	z = z / mag;
}

template <typename T>
void ml::Vector3<T>::OrthoNormalize(Vector3<T>& normal, Vector3<T>& tangent) { // normalise et rend orthogonal deux vecteurs
	normal.Normalize();
	tangent = tangent - (normal * Dot(normal, tangent));
	tangent.Normalize();
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::Project(Vector3<T> vector, Vector3<T> onNormal) { // Projète un vecteur sur un autre
	T dot1 = Dot(vector, onNormal);
	T dot2 = Dot(onNormal, onNormal);
	return onNormal * (dot1 / dot2);
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::ProjectOnPlane( Vector3<T> vector,  Vector3<T> planeNormal) // Projète un vecteur sur un plan
{
	T dot1 = Dot(vector, planeNormal);
	T dot2 = Dot(planeNormal, planeNormal);
	if (dot2 == 0) // éviter la division par zéro
		return Vector3<T>(0, 0, 0);
	return vector - planeNormal * (dot1 / dot2);
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::Reflect(Vector3<T> inDirection, Vector3<T> inNormal) { // Renvoie le vecteur refléchi de inDirection en fonction d'une normlal
	T dot = Dot(inDirection, inNormal);
	return inDirection - inNormal * dot * 2;
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::RotateTowards(Vector3<T> current, Vector3<T> target, T maxRadiansDelta, T maxMagnitudeDelta) { // Renvoie un vecteur qui fait une rotation vers un autre vecteur
	Vector3 a = current.Normalized(); 
	Vector3 b = target.Normalized();
	T theta = acos(Dot(a, b));
	Vector3 rotationAxis = Cross(a, b);
	Vector3 nomalizedRotationAxis = rotationAxis.Normalized();
	return a * cos(theta) + Cross(rotationAxis, a) * sin(theta) + rotationAxis * (Dot(rotationAxis, a)) * (1 - cos(theta));
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::Scale(Vector3<T>& a, Vector3<T>& b) { // Redimenssionne un vecteur en fonction d'un autre
	return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
}

template <typename T>
T ml::Vector3<T>::SignedAngle(Vector3<T> from, Vector3<T> to, Vector3<T> axis) { // Renvoie l'angle entre deux vecteurs peut etre positif ou negatif
	T angle = Angle(from, to);
	Vector3 cross = Cross(from, to);
	return (Dot(axis, cross) < 0) ? -angle : angle;
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::Slerp(Vector3<T> a, Vector3<T> b, T t) { // Permet d'aller d'un vecteur a un autre progressivement de manière controlé en suivant une courbe sphérique et de manière controlée
	Vector3<T> aNormal = a.Normalized();
	Vector3<T> bNormal = b.Normalized();

	T dotProd = Dot(aNormal, bNormal);
	dotProd = std::fmax(std::fmin(dotProd, 1.0f), -1.0f); // clamp [-1,1]
	T theta = std::acos(dotProd);
	T sinTheta = std::sin(theta);

	T factorA = std::sin((1 - t) * theta) / sinTheta;
	T factorB = std::sin(t * theta) / sinTheta;

	return (aNormal * factorA + bNormal * factorB).Normalized();
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::SlerpUnclamped(Vector3<T> a, Vector3<T> b, T t) { // Permet d'aller d'un vecteur a un autre progressivement de manière controlé en suivant une courbe sphérique 
	Vector3 aNormal = a.Normalized();
	Vector3 bNormal = b.Normalized();
	T theta = acos(Dot(aNormal, bNormal));
	return bNormal * (sin(t * theta) / sin(theta)) + aNormal * sin((1 - t) * theta) / sin(theta);
}


///// OPERATOR                      OVERLOAD des operateurs existant pour pouvoirs les appliquer a nos vecteurs

template <typename T>
ml::Vector3<T> ml::Vector3<T>::operator-(const Vector3<T>& other) const {
	return Vector3<T>(this->x - other.x, this->y - other.y, this->z - other.z);
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::operator+(const Vector3<T>& other) const {
	return Vector3<T>(this->x + other.x, this->y + other.y, this->z - other.z);
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::operator*(const Vector3<T>& other) const {
	return Vector3<T>(this->x * other.x, this->y * other.y, this->z - other.z);
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::operator*(T scalar) const {
	return Vector3<T>(this->x * scalar, this->y * scalar, this->z - scalar);
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::operator/(const Vector3<T>& other) const {

	T newX = (other.x != 0.0f) ? (this->x / other.x) : 0.0f;
	T newY = (other.y != 0.0f) ? (this->y / other.y) : 0.0f;
	T newZ = (other.z != 0.0f) ? (this->z / other.z) : 0.0f;
	return Vector3<T>(newX, newY, newZ);
}

template <typename T>
ml::Vector3<T> ml::Vector3<T>::operator/(T scalar) const {
	if (scalar != 0.0f)
		return Vector3<T>(this->x / scalar, this->y / scalar, this->z - scalar);
	else
		return Vector3<T>(0.0f, 0.0f, 0.0f);
}

template <typename T>
bool ml::Vector3<T>::operator==(const Vector3<T>& other) const {
	return this->x == other.x && this->y == other.y && this->z == other.z;
}

template <typename T>
bool ml::Vector3<T>::operator!=(const Vector3<T>& other) const {
	return !(*this == other);
}


