#pragma once
#include "Matrix.h"

class Vector :
	public Matrix
{
public:
	Vector() :row(0), column(1), data(nullptr) {}

	Vector(double* data, int m_row) :row(m_row), column(1)
	{
		this->data = new double[row];
		for (int i = 0; i < row; i++)
		{
			this->data[i] = data[i];
		}
	}

	~Vector()
	{
		delete[] data;
	}

	int get_size()
	{
		return get_row();
	}

	/**
	* @brief		Override the operator =
	*/
	Vector& operator=(Vector& para)
	{
		for (int i = 0; i < this->row; i++)
		{
			this->data[i] = para[i];
		}
	}

	/**
	* @brief		Override the operator []
	*/
	double operator[](int index)
	{
		return this->get_data()[index];
	}

	/**
	* @brief		Transpose the vector
	*
	* @return		Vector
	*/
	Vector trans()
	{
		Matrix temp = this->trans();
		return matrix_as_vector(temp);
	}

private:
	int row;
	int column;
	double* data;
	int get_row()
	{
		return this->row;
	}
	int get_column()
	{
		return this->column;
	}
	double* get_data()
	{
		return this->data;
	}
};

Vector matrix_as_vector(Matrix& para)
{
	int row = para.get_size()[0];
	double* data = new double[row];
	for (int i = 0; i < row; i++)
	{
		data[i] = para[i][0];
	}
	return Vector(data, row);
}