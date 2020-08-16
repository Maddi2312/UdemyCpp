#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <limits>

template<typename T>
class Matrix
{
public:
	Matrix<T>(const unsigned int &rows, const unsigned int &cols, const T &value);
	Matrix<T>(const unsigned int &rows, const unsigned int &cols);
	~Matrix<T>();

	void print_matrix() const;
	Matrix<T>& operator=(const Matrix<T> &matrixB);
	Matrix<T> transpose();

	Matrix operator+(const Matrix &matrixB);
	Matrix& operator+=(const Matrix &matrixB);

	Matrix operator-(const Matrix &matrixB);
	Matrix& operator-=(const Matrix &matrixB);

	Matrix operator*(const Matrix &matrixB);
	Matrix& operator*=(const Matrix &matrixB);

	Matrix operator*(const T &scalar);
	Matrix& operator*=(const T &scalar);

	Matrix operator/(const T &scalar);
	Matrix& operator/=(const T &scalar);

	unsigned int num_rows();
	unsigned int num_cols();

private:
	unsigned int m_rows;
	unsigned int m_cols;
	const double m_epsilon;
	const T m_value;
	std::vector<std::vector<T>> m_data;
};

template<typename T>
Matrix<T>::Matrix(const unsigned int &rows, const unsigned int &cols, const T &value):
	m_rows(rows), m_cols(cols), m_value(0.0), m_data(m_rows, vector<T>(m_cols, 0)),
	m_epsilon(1e-6)
{
	std::cout << "Created Matrix: " << &this->m_data << std::endl;
}

template<typename T>
Matrix<T>::Matrix(const unsigned int &rows, const unsigned int &cols):
	m_rows(rows), m_cols(cols), m_data(m_rows, vector<T>(m_cols, 0)),
	m_epsilon(std::numeric_limits<double>::min())
{
	std::cout << "Created Matrix: " << &this->m_data << std::endl;
}

template<typename T>
Matrix<T>::~Matrix()
{
	std::cout << "Deleted Matrix: " << &this->m_data << std::endl;
}

template<typename T>
void Matrix<T>::print_matrix() const
{
	for (int i = 0; i != m_rows; ++i)
	{
		for (int j = 0; j != m_cols; ++j)
		{
			std::cout << m_data[i][j] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &matrixB)
{

}

template<typename T>
Matrix<T> Matrix<T>::transpose()
{

}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &matrixB)
{

}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix &matrixB)
{

}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &matrixB)
{

}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix &matrixB)
{

}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &matrixB)
{

}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix &matrixB)
{

}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T &scalar)
{
	Matrix<T> result(m_rows, m_cols);

	for (int i = 0; i != m_rows; ++i)
	{
		std::transform(
			this->m_data[i].begin(),
			this->m_data[i].end(),
			result.m_data[i].begin(),
			[scalar](T val) {return val * scalar; });
	}

	return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator*=(const T &scalar)
{
	for (int i = 0; i != m_rows; ++i)
	{
		std::transform(
			this->m_data[i].begin(),
			this->m_data[i].end(),
			this->m_data[i].begin(),
			[scalar](T val) {return val * scalar; });
	}

	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T &scalar)
{
	Matrix<T> result(m_rows, m_cols);

	for (int i = 0; i != m_rows; ++i)
	{
		std::transform(
			this->m_data[i].begin(),
			this->m_data[i].end(),
			result.m_data[i].begin(),
			[scalar, this](T val) {return val / (scalar + this->m_epsilon); });
	}

	return result;
}

template<typename T>
Matrix<T>& Matrix<T>::operator/=(const T &scalar)
{
	for (int i = 0; i != m_rows; ++i)
	{
		std::transform(
			this->m_data[i].begin(),
			this->m_data[i].end(),
			this->m_data[i].begin(),
			[scalar, this](T val) {return val / (scalar + this->m_epsilon); });
	}

	return *this;
}

template<typename T>
unsigned int Matrix<T>::num_rows()
{

}

template<typename T>
unsigned int Matrix<T>::num_cols()
{

}