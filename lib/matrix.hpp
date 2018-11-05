#ifndef ONLINEGAME_MATRIX_H
#define ONLINEGAME_MATRIX_H
namespace OnlineGame
{
	template<typename T>
	class Matrix {
	public:
		Matrix(int r, int c);
		~Matrix();
		const T& operator()(int row, int col) const;
		T& operator()(int row, int col);
		int row_count() const;
		int col_count() const;
	private:
		T *buf;		
		int rows, cols;
	};

	template<typename T>
	Matrix<T>::Matrix(int r, int c)
	:	rows{r},
		cols{c},
		buf{new T[rows * cols]{}}
	{
	}

	template<typename T>
	const T& Matrix<T>::operator()(int row, int col) const
	{
		return buf[rows * row + col];
	}

	template<typename T>
	T& Matrix<T>::operator()(int row, int col)
	{
		return buf[rows * row + col];
	}

	template<typename T>
	int Matrix<T>::row_count() const
	{
		return rows;
	}

	template<typename T>
	int Matrix<T>::col_count() const
	{
		return cols;
	}

	template<typename T>
	Matrix<T>::~Matrix()
	{
		delete buf;
	}
}
#endif /* ONLINEGAME_MATRIX_H */
