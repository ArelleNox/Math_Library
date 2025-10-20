#pragma once
namespace ml
{
	template <typename T>
	Matrix4x4<T>::Matrix4x4() {} // constructeur par défaut

	template <typename T>
	Matrix4x4<T>::Matrix4x4(const std::array<T, 16>& m) : m(m) {} // constructeur avec initialisation des éléments

	template <typename T>
	T& Matrix4x4<T>::operator()(int row, int col) { return m[row * 4 + col]; }

	template <typename T>
	T  Matrix4x4<T>::operator()(int row, int col) const { return m[row * 4 + col]; }


	////// STATIC PROPRETIES


    template <typename T>
    Matrix4x4<T> Matrix4x4<T>::Identity() { // Renvoie la matrice identite
       return Matrix4x4<T>(std::array<T, 16>{ 1, 0, 0, 0,
                                                  0, 1, 0, 0,
                                                  0, 0, 1, 0,
                                                  0, 0, 0, 1 });
    }

    template <typename T>
	Matrix4x4<T> Matrix4x4<T>::Zero() { // Renvoie la matrice nulle
       return Matrix4x4<T>(std::array<T, 16>{ 0, 0, 0, 0,
                                                  0, 0, 0, 0,
                                                  0, 0, 0, 0,
                                                  0, 0, 0, 0 });
    }

	/////PROPRETIES


	template <typename T>
	T Matrix4x4<T>::Cofactor(int row, int col) const { // Calcule le cofacteur de la matrice
		std::array<T, 9> minor;
		int index = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i != row && j != col) {
					minor[index++] = (*this)(i, j);
				}
			}
		}
		T det = minor[0] * (minor[4] * minor[8] - minor[5] * minor[7]) -
			minor[1] * (minor[3] * minor[8] - minor[5] * minor[6]) +
			minor[2] * (minor[3] * minor[7] - minor[4] * minor[6]);
		if ((row + col) % 2 == 1) det = -det;
		return det;
	}

	template <typename T>
	T Matrix4x4<T>::Determinant() const { // Calcule le determinant de la matrice
		T det = 0;
		for (int j = 0; j < 4; j++) {
			det += (*this)[0][j] * Cofactor(0, j);
		}
		return det;
	}

	template <typename T>
	Matrix4x4<T> Matrix4x4<T>::Inverse() const { // Calcule l'inverse de la matrice
		T det = Determinant();
		if (det == 0) return Matrix4x4<T>::Zero();
		Matrix4x4<T> adj = ml::Matrix4x4<T>::Identity();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				adj[j][i] = Cofactor(i, j);
			}
		}
		Matrix4x4<T> inv = ml::Matrix4x4<T>::Identity(); 
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				inv[i][j] = adj[i][j] / det;
			}
		}
		return inv;
	}

	template <typename T>
	Vector3<T> Matrix4x4<T>::lossyScale() { // Calcule l'echelle de la matrice
		float sx = std::sqrt((*this)[0][0] * (*this)[0][0] + (*this)[1][0] * (*this)[1][0] + (*this)[2][0] * (*this)[2][0]);
		float sy = std::sqrt((*this)[0][1] * (*this)[0][1] + (*this)[1][1] * (*this)[1][1] + (*this)[2][1] * (*this)[2][1]);
		float sz = std::sqrt((*this)[0][2] * (*this)[0][2] + (*this)[1][2] * (*this)[1][2] + (*this)[2][2] * (*this)[2][2]);
		return Vector3<T>(sx, sy, sz);
	}

	template <typename T>
	Quaternion<T> Matrix4x4<T>::rotation() { // Calcule la rotation de la matrice
		T trace = (*this)[0][0] + (*this)[1][1] + (*this)[2][2];
		T qw, qx, qy, qz;
		if (trace > 0) {
			T s = std::sqrt(trace + 1.0f) * 2; // S=4*qw
			qw = 0.25f * s;
			qx = ((*this)[2][1] - (*this)[1][2]) / s;
			qy = ((*this)[0][2] - (*this)[2][0]) / s;
			qz = ((*this)[1][0] - (*this)[0][1]) / s;
		}
		else if (((*this)[0][0] > (*this)[1][1]) & ((*this)[0][0] > (*this)[2][2])) {
			T s = std::sqrt(1.0f + (*this)[0][0] - (*this)[1][1] - (*this)[2][2]) * 2; // S=4*qx
			qw = ((*this)[2][1] - (*this)[1][2]) / s;
			qx = 0.25f * s;
			qy = ((*this)[0][1] + (*this)[1][0]) / s;
			qz = ((*this)[0][2] + (*this)[2][0]) / s;
		}
		else if ((*this)[1][1] > (*this)[2][2]) {
			T s = std::sqrt(1.0f + (*this)[1][1] - (*this)[0][0] - (*this)[2][2]) * 2; // S=4*qy
			qw = ((*this)[0][2] - (*this)[2][0]) / s;
			qx = ((*this)[0][1] + (*this)[1][0]) / s;
			qy = 0.25f * s;
			qz = ((*this)[1][2] + (*this)[2][1]) / s;
		}
		else {
			T s = std::sqrt(1.0f + (*this)[2][2] - (*this)[0][0] - (*this)[1][1]) * 2; // S=4*qz
		}
		return Quaternion<T>(qx, qy, qz, qw);
	}

	template <typename T>
	bool Matrix4x4<T>::isIdentity() const { // Verifie si la matrice est l'identite
		return (*this)[0][0] == 1 && (*this)[0][1] == 0 && (*this)[0][2] == 0 && (*this)[0][3] == 0 &&
			(*this)[1][0] == 0 && (*this)[1][1] == 1 && (*this)[1][2] == 0 && (*this)[1][3] == 0 &&
			(*this)[2][0] == 0 && (*this)[2][1] == 0 && (*this)[2][2] == 1 && (*this)[2][3] == 0 &&
			(*this)[3][0] == 0 && (*this)[3][1] == 0 && (*this)[3][2] == 0 && (*this)[3][3] == 1;
	}

	template <typename T>
	T Matrix4x4<T>::This(int i, int j) const {  // Accede aux elements de la matrice
		return (*this)[i][j];
	}

	template <typename T>
	Matrix4x4<T> Matrix4x4<T>::Transpose() const { // Transpose la matrice : colonne = ligne
		Matrix4x4<T> result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result[i][j] = (*this)[j][i];
			}
		}
		return result;
	}

	//////PUBLIC METHODS

	template <typename T>
	Vector3<T> Matrix4x4<T>::GetColumn(int index) const { // Renvoie une colonne de la matrice
		return Vector3<T>((*this)[0][index], (*this)[1][index], (*this)[2][index]);
	}

	template <typename T>
	Vector3<T> Matrix4x4<T>::GetRow(int index) const { // Renvoie une ligne de la matrice
		return Vector3<T>((*this)[index][0], (*this)[index][1], (*this)[index][2]);
	}

	template <typename T>
	void Matrix4x4<T>::SetColumn(int index, const Vector3<T>& column) { // Modifie une colonne de la matrice
		(*this)[0][index] = column.x;
		(*this)[1][index] = column.y;
		(*this)[2][index] = column.z;
	}

	template <typename T>
	void Matrix4x4<T>::SetRow(int index, const Vector3<T>& row) { // Modifie une ligne de la matrice
		(*this)[index][0] = row.x;
		(*this)[index][1] = row.y;
		(*this)[index][2] = row.z;
	}

	template <typename T>
	Vector3<T> Matrix4x4<T>::GetPosition() const { // Renvoie la position de la matrice
		return Vector3<T>((*this)[0][3], (*this)[1][3], (*this)[2][3]);
	}

	template <typename T>
	Vector3<T> Matrix4x4<T>::MultiplyPoint(const Vector3<T>& point) const { // Multiplie un point par la matrice
		T x = (*this)[0][0] * point.x + (*this)[0][1] * point.y + (*this)[0][2] * point.z + (*this)[0][3];
		T y = (*this)[1][0] * point.x + (*this)[1][1] * point.y + (*this)[1][2] * point.z + (*this)[1][3];
		T z = (*this)[2][0] * point.x + (*this)[2][1] * point.y + (*this)[2][2] * point.z + (*this)[2][3];
		T w = (*this)[3][0] * point.x + (*this)[3][1] * point.y + (*this)[3][2] * point.z + (*this)[3][3];
		if (w != 0 && w != 1) {
			x /= w;
			y /= w;
			z /= w;
		}
		return Vector3<T>(x, y, z);
	}

	template <typename T>
	Vector3<T> Matrix4x4<T>::MultiplyPoint3x4(const Vector3<T>& point) const { // Multiplie un point par la matrice 3x4
		T x = (*this)[0][0] * point.x + (*this)[0][1] * point.y + (*this)[0][2] * point.z + (*this)[0][3];
		T y = (*this)[1][0] * point.x + (*this)[1][1] * point.y + (*this)[1][2] * point.z + (*this)[1][3];
		T z = (*this)[2][0] * point.x + (*this)[2][1] * point.y + (*this)[2][2] * point.z + (*this)[2][3];
		return Vector3<T>(x, y, z);
	}

	template <typename T> 
	Vector3<T> Matrix4x4<T>::MultiplyVector(const Vector3<T>& vec) const { // Multiplie un vecteur par la matrice
		T x = (*this)[0][0] * vec.x + (*this)[0][1] * vec.y + (*this)[0][2] * vec.z;
		T y = (*this)[1][0] * vec.x + (*this)[1][1] * vec.y + (*this)[1][2] * vec.z;
		T z = (*this)[2][0] * vec.x + (*this)[2][1] * vec.y + (*this)[2][2] * vec.z;
		return Vector3<T>(x, y, z);
	}

	template <typename T>
	void Matrix4x4<T>::SetTRS(const Vector3<T>& position, const Quaternion<T>& rotation, const Vector3<T>& scale) { // Modifie la matrice avec une position, une rotation et une echelle
		Matrix4x4<T> t = Translate(position);
		Matrix4x4<T> r = Rotate(rotation);
		Matrix4x4<T> s = Scale(scale);
		*this = t * r * s;
	}

	template <typename T>
	bool Matrix4x4<T>::ValidTRS() const { // Verifie si la matrice est une matrice TRS
		return (*this)[3][0] == 0 && (*this)[3][1] == 0 && (*this)[3][2] == 0 && (*this)[3][3] == 1;
	}

	template <typename T>
	std::string Matrix4x4<T>::ToString() const { // Convertit la matrice en chaine de caracteres
		std::string result = "";
		for (int i = 0; i < 4; i++) {
			result += "| ";
			for (int j = 0; j < 4; j++) {
				result += std::to_string((*this)[i][j]) + " ";
			}
			result += "|\n";
		}
		return result;
	}

	////// STATIC METHODS


	template <typename T>
	Matrix4x4<T> Matrix4x4<T>::Frustum(T left, T right, T bottom, T top, T near, T far) { // Renvoie une matrice de frustum : met du 3D en 2D
		ml::Matrix4x4<float> m;
		T rl = right - left;
		T tb = top - bottom;
		T fn = far - near;

		m[0][0] = (2 * near) / rl;
		m[0][1] = 0;
		m[0][2] = (right + left) / rl;
		m[0][3] = 0;

		m[1][0] = 0;
		m[1][1] = (2 * near) / tb;
		m[1][2] = (top + bottom) / tb;
		m[1][3] = 0;

		m[2][0] = 0;
		m[2][1] = 0;
		m[2][2] = -(far + near) / fn;
		m[2][3] = -(2 * far * near) / fn;

		m[3][0] = 0;
		m[3][1] = 0;
		m[3][2] = -1;
		m[3][3] = 0;

		return m;
	}

	template <typename T>
	Matrix4x4<T> Matrix4x4<T>::Inverse3DAffine(const Matrix4x4<T>& m) { // Calcule l'inverse d'une matrice affine 3D
		ml::Matrix4x4<T> inv;
		inv[0][0] = m[0][0]; inv[0][1] = m[1][0]; inv[0][2] = m[2][0]; inv[0][3] = 0;
		inv[1][0] = m[0][1]; inv[1][1] = m[1][1]; inv[1][2] = m[2][1]; inv[1][3] = 0;
		inv[2][0] = m[0][2]; inv[2][1] = m[1][2]; inv[2][2] = m[2][2]; inv[2][3] = 0;
		inv[3][0] = -(m[3][0] * inv[0][0] + m[3][1] * inv[1][0] + m[3][2] * inv[2][0]);
		inv[3][1] = -(m[3][0] * inv[0][1] + m[3][1] * inv[1][1] + m[3][2] * inv[2][1]);
		inv[3][2] = -(m[3][0] * inv[0][2] + m[3][1] * inv[1][2] + m[3][2] * inv[2][2]);
		inv[3][3] = 1;
		return inv;
	}

	template <typename T>
	Matrix4x4<T> Matrix4x4<T>::LookAt(const Vector3<T>& eye, const Vector3<T>& center, const Vector3<T>& up) { // Renvoie une matrice de vue
		Vector3<T> f = (center - eye).Normalized();
		Vector3<T> upNonConst = up;
		Vector3<T> s = Vector3<T>::Cross(f, upNonConst).Normalized();
		Vector3<T> u = Vector3<T>::Cross(s, f);
		Matrix4x4<T> m = Identity();
		Vector3<T> eyeNonConst = eye;
		m[0][0] = s.x; m[0][1] = s.y; m[0][2] = s.z; m[0][3] = -Vector3<T>::Dot(s, eyeNonConst);
		m[1][0] = u.x; m[1][1] = u.y; m[1][2] = u.z; m[1][3] = -Vector3<T>::Dot(u, eyeNonConst);
		m[2][0] = -f.x; m[2][1] = -f.y; m[2][2] = -f.z; m[2][3] = Vector3<T>::Dot(f, eyeNonConst);
		return m;
	}

	template <typename T>
	Matrix4x4<T> Matrix4x4<T>::Ortho(T left, T right, T bottom, T top, T near, T far) { // renvoie une matrice orthographique
		ml::Matrix4x4<float> m;
		m[0][0] = 2 / (right - left);
		m[0][1] = 0;
		m[0][2] = 0;
		m[0][3] = -(right + left) / (right - left);
		m[1][0] = 0;
		m[1][1] = 2 / (top - bottom);
		m[1][2] = 0;
		m[1][3] = -(top + bottom) / (top - bottom);
		m[2][0] = 0;
		m[2][1] = 0;
		m[2][2] = -2 / (far - near);
		m[2][3] = -(far + near) / (far - near);
		m[3][0] = 0;
		m[3][1] = 0;
		m[3][2] = 0;
		m[3][3] = 1;
		return m;
	}

	template <typename T>
	Matrix4x4<T> Matrix4x4<T>::Perspective(T fovY, T aspect, T near, T far) { // Renvoie une matrice de perspective
		T f = 1 / std::tan(fovY / 2);
		ml::Matrix4x4<T> m;
		m[0][0] = f / aspect;
		m[0][1] = 0;
		m[0][2] = 0;
		m[0][3] = 0;
		m[1][0] = 0;
		m[1][1] = f;
		m[1][2] = 0;
		m[1][3] = 0;
		m[2][0] = 0;
		m[2][1] = 0;
		m[2][2] = (far + near) / (near - far);
		m[2][3] = (2 * far * near) / (near - far);
		m[3][0] = 0;
		m[3][1] = 0;
		m[3][2] = -1;
		m[3][3] = 0;
		return m;
	}

	//Rotation matrix from quaternion
	template <typename T>
	Matrix4x4<T> Matrix4x4<T>::Rotate(const Quaternion<T>& q) { // Renvoie une matrice de rotation à partir d'un quaternion
		ml::Matrix4x4<float> m;
		T x = q.x, y = q.y, z = q.z, w = q.w;
		T xx = x * x, yy = y * y, zz = z * z;
		T xy = x * y, xz = x * z, yz = y * z;
		T wx = w * x, wy = w * y, wz = w * z;

		m[0][0] = 1 - 2 * (yy + zz);
		m[0][1] = 2 * (xy - wz);
		m[0][2] = 2 * (xz + wy);
		m[0][3] = 0;

		m[1][0] = 2 * (xy + wz);
		m[1][1] = 1 - 2 * (xx + zz);
		m[1][2] = 2 * (yz - wx);
		m[1][3] = 0;

		m[2][0] = 2 * (xz - wy);
		m[2][1] = 2 * (yz + wx);
		m[2][2] = 1 - 2 * (xx + yy);
		m[2][3] = 0;

		m[3][0] = m[3][1] = m[3][2] = 0;
		m[3][3] = 1;
		return m;
	}

	template <typename T>
	Matrix4x4<T> Matrix4x4<T>::Scale(const Vector3<T>& scale) { // Renvoie une matrice de mise à l'échelle
		Matrix4x4<T> m = Identity();
		m[0][0] = scale.x;
		m[1][1] = scale.y;
		m[2][2] = scale.z;
		return m;
	}

	template <typename T>
	Matrix4x4<T> Matrix4x4<T>::Translate(const Vector3<T>& translation) { // Renvoie une matrice de translation
		Matrix4x4<T> m = Identity();
		m[0][3] = translation.x;
		m[1][3] = translation.y;
		m[2][3] = translation.z;
		return m;
	}

	template <typename T>
	Matrix4x4<T> Matrix4x4<T>::TRS(const Vector3<T>& position, const Quaternion<T>& rotation, const Vector3<T>& scale) {  // Renvoie une matrice TRS : combinéion de translation, rotation et mise à l'échelle
		Matrix4x4<T> t = Translate(position);
		Matrix4x4<T> r = Rotate(rotation);
		Matrix4x4<T> s = Scale(scale);
		return t * r * s;
	}

	//// //// OPERATORS           OVERLOAD des operateurs existants pour les appliquer aux matrices
	
	// Row access
	template <typename T>
	std::array<T, 4>& Matrix4x4<T>::operator[](int row) {
		return *reinterpret_cast<std::array<T, 4>*>(&m[row * 4]);
	}

	template <typename T>
	const std::array<T, 4>& Matrix4x4<T>::operator[](int row) const {
		return *reinterpret_cast<const std::array<T, 4>*>(&m[row * 4]);
	}

	template <typename T>
	Matrix4x4<T> Matrix4x4<T>::operator*(const Matrix4x4<T>& rhs) const {
		ml::Matrix4x4<float> result = ml::Matrix4x4<float>::Identity();
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				result[i][j] = static_cast<T>(0);
				for (int k = 0; k < 4; ++k) {
					result[i][j] += (*this)[i][k] * rhs[k][j];
				}
			}
		}
		return result;
	}

	template <typename T>
	bool Matrix4x4<T>::operator==(const Matrix4x4<T>& rhs) const {
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				if ((*this)[i][j] != rhs[i][j])
					return false;
		return true;
	}

	template <typename T>
	bool Matrix4x4<T>::operator!=(const Matrix4x4<T>& rhs) const {
		return !(*this == rhs);
	}
}