#ifndef ONLINEGAME_MATRIX_H
#define ONLINEGAME_MATRIX_H
#include <iterator>
#include <algorithm>
#include "coord.h"

namespace OnlineGame
{
	template<typename T>
	class Matrix;

	template<typename T>
	class matrix_iterator;

	template<typename T>
	struct Element
	{
		Element() = default;
		bool operator==(const Element<T> &a) const;
		bool operator!=(const Element<T> &a) const;
		Element& operator=(const T& val);
		T *subject{};
		Coord coord{};
	};

	template<typename T>
	Element<T> make_element(Matrix<T> *m, int pos)
	{
		return Element<T>{m->buf + pos,
			Coord{pos / m->col_count(), pos % m->col_count()}};
	}

	template<typename T>
	bool Element<T>::operator==(const Element<T> &a) const
	{
		return subject == a.subject && coord.row == a.coord.row &&
			coord.col == a.coord.col;
	}

	template<typename T>
	bool Element<T>::operator!=(const Element<T> &a) const
	{
		return !(*this == a);
	}

	template<typename T>
	Element<T>& Element<T>::operator=(const T &val)
	{
		*subject = val;
		return *this;
	}

	template<typename T>
	class Matrix {
	public:
		using iterator = matrix_iterator<T>;
		iterator begin();
		iterator end();
		Matrix() = default;
		Matrix(int r, int c);
		Matrix(const Matrix &m);
		Matrix(Matrix &&m);
		~Matrix();
		Matrix& operator=(const Matrix &m);
		Matrix& operator=(Matrix &&m) noexcept;
		const T& operator()(int row, int col) const;
		T& operator()(int row, int col);
		const T& operator[](int pos) const;
		T& operator[](int pos);
		void set(int row, int col, const T &t);
		const T& get(int row, int col) const;
		void resize(int rows, int cols);
		int row_count() const noexcept;
		int col_count() const noexcept;
		friend class matrix_iterator<T>;
		friend Element<T> make_element<T>(Matrix<T> *m, int pos);
	private:
		T *buf{};
		int rows{}, cols{};
	};

	template<typename T>
	class matrix_iterator:
		public std::iterator<std::forward_iterator_tag, T,
			ptrdiff_t, const T*, const T&>
	{
		public:
			matrix_iterator(Matrix<T> *m, int p);
			const Element<T>& operator*() const;
			Element<T>& operator*();
			matrix_iterator& operator++();
			matrix_iterator operator++(int);
			matrix_iterator& operator=(const T& val);
			bool operator==(const matrix_iterator<T> &other) const;
			bool operator!=(const matrix_iterator<T> &other) const;
		private:
			Matrix<T> *m;
			Element<T> elem;
			int pos{};
	};

	template<typename T>
	matrix_iterator<T>::matrix_iterator(Matrix<T> *mm, int p)
	:	m{mm},
		elem{make_element<T>(mm, p)},
		pos{p}
	{
	}

	template<typename T>
	const Element<T>& matrix_iterator<T>::operator*() const
	{
		return elem;
	}

	template<typename T>
	Element<T>& matrix_iterator<T>::operator*()
	{
		return elem;
	}

	template<typename T>
	matrix_iterator<T>& matrix_iterator<T>::operator++()
	{
		++pos;
		elem = make_element(m, pos);
		return *this;
	}

	template<typename T>
	matrix_iterator<T> matrix_iterator<T>::operator++(int)
	{
		matrix_iterator<T> temp = *this;
		++pos;
		elem = make_element(m, pos);
		return temp;
	}

	template<typename T>
	matrix_iterator<T>& matrix_iterator<T>::operator=(const T& val)
	{
		elem.subject[pos] = val;
		return *this;
	}

	template<typename T>
	bool matrix_iterator<T>::operator==(const matrix_iterator<T> &a) const
	{
		return m == a.m && elem == a.elem && pos == a.pos;
	}

	template<typename T>
	bool matrix_iterator<T>::operator!=(const matrix_iterator<T> &other) const
	{
		return !(*this == other);
	}

	template<typename T>
	typename Matrix<T>::iterator Matrix<T>::begin()
	{
		return matrix_iterator<T>(this, 0);
	}

	template<typename T>
	typename Matrix<T>::iterator Matrix<T>::end()
	{
		return matrix_iterator<T>(this, rows * cols);
	}

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
	const T& Matrix<T>::operator[](int pos) const
	{
		return buf[pos];
	}

	template<typename T>
	T& Matrix<T>::operator[](int pos)
	{
		return buf[pos];
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
