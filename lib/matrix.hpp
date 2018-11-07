#ifndef ONLINEGAME_MATRIX_H
#define ONLINEGAME_MATRIX_H
#include <algorithm>
namespace OnlineGame
{
	template<typename T>
	class Matrix {
	public:
		Matrix() = default;
		Matrix(int r, int c);
		Matrix(const Matrix &m);
		Matrix(Matrix &&m);
		~Matrix();
		Matrix& operator=(const Matrix &m);
		Matrix& operator=(Matrix &&m) noexcept;
		const T& operator()(int row, int col) const;
		T& operator()(int row, int col);
		void set(int row, int col, const T &t);
		const T& get(int row, int col) const;
		void resize(int rows, int cols);
		int row_count() const noexcept;
		int col_count() const noexcept;
	private:
		T *buf{};
		int rows{}, cols{};
	};

	template<typename T>
	Matrix<T>::Matrix(int r, int c)
	:	rows{r},
		cols{c},
		buf{new T[r * c]}
	{
	}

	template<typename T>
	Matrix<T>::Matrix(const Matrix &m)
	:	rows{m.rows},
		cols{m.cols},
		buf{new T[m.rows * m.cols]}
	{
		std::copy(m.buf, m.buf + m.rows*m.cols, buf);
	}

	template<typename T>
	Matrix<T>::Matrix(Matrix &&m)
	:	rows{m.rows},
		cols{m.cols},
		buf{m.buf}
	{
		m.rows = 0;
		m.cols = 0;
		m.buf = nullptr;
	}

	template<typename T>
	Matrix<T>::~Matrix()
	{
		delete buf;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator=(const Matrix &m)
	{
		T *temp = new T[m.rows * m.cols];
		std::copy(m.buf, m.buf + m.rows*m.cols, temp);
		delete buf;
		rows = m.rows;
		cols = m.cols;
		buf = temp;

		return *this;
	}

	template<typename T>
	Matrix<T>& Matrix<T>::operator=(Matrix &&m) noexcept
	{
		delete buf;
		rows = m.rows;
		cols = m.cols;
		buf = m.buf;
		m.rows = 0;
		m.cols = 0;
		m.buf = nullptr;

		return *this;
	}

	template<typename T>
	const T& Matrix<T>::operator()(int row, int col) const
	{
		return buf[row * cols + col];
	}

	template<typename T>
	T& Matrix<T>::operator()(int row, int col)
	{
		return buf[row * cols + col];
	}

	template<typename T>
	void Matrix<T>::resize(int r, int c)
	{
		T *temp = new T[r * c];
		delete buf;
		buf = temp;
		rows = r;
		cols = c;
	}

	template<typename T>
	int Matrix<T>::row_count() const noexcept
	{
		return rows;
	}

	template<typename T>
	int Matrix<T>::col_count() const noexcept
	{
		return cols;
	}
}
#endif /* ONLINEGAME_MATRIX_H */
