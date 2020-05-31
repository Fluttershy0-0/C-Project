#pragma once

#include "../headers/SMatrix.h"

SMatrix generate_SMatrix(UTYPE n, UTYPE m)
{
	SMatrix newmatrix;
	newmatrix.rows = m;
	newmatrix.columns = n;
	newmatrix.mas = (DTYPE **)malloc(sizeof(DTYPE *) * m);
	for (UTYPE _m = 0; _m < m; ++_m)
	{
		newmatrix.mas[_m] = (DTYPE *)malloc(sizeof(DTYPE) * n);
	}
	return newmatrix;
}

ITYPE input_SMatrix(SMatrix *x)
{
	for (UTYPE _n = 0; _n < x->rows; ++_n)
	{
		for (UTYPE _m = 0; _m < x->columns; ++_m)
		{
			scanf("%lf", &(x->mas[_n][_m]));
		}
	}
	return x->columns * x->rows;
}

ITYPE output_SMatrix(SMatrix x, ITYPE type, ITYPE width, ITYPE precision)
{
	if (type == 0)
	{
		for (UTYPE _n = 0; _n < x.rows; ++_n)
		{
			for (UTYPE _m = 0; _m < x.columns; ++_m)
			{
				printf("%*.*lf ", width, precision, x.mas[_n][_m]);
			}
			printf("\n");
		}
	}
	else
	{
		for (UTYPE _n = 0; _n < x.rows; ++_n)
		{
			for (UTYPE _m = 0; _m < x.columns; ++_m)
			{
				printf("%*.*e ", width, precision, x.mas[_n][_m]);
			}
			printf("\n");
		}
	}
	return x.rows * x.columns;
}

ITYPE inputBinaryFile_SMatrix(char *file, SMatrix *x)
{
	FILE *read_ptr;
	if ((read_ptr = fopen(file, "rb")) == NULL)
	{
		fprintf(stderr, "Read error!\n");
		return 0;
	}
	for (UTYPE _i = 0; _i < x->rows; _i++)
	{
		fread(x->mas[_i], sizeof(DTYPE), x->columns, read_ptr);
	}
	fclose(read_ptr);
	return x->rows * x->columns;
}

ITYPE outputBinaryFile_SMatrix(char *file, SMatrix x)
{
	FILE *write_ptr;
	if ((write_ptr = fopen(file, "wb")) == NULL)
	{
		fprintf(stderr, "Write error!\n");
		return 0;
	}
	for (UTYPE _i = 0; _i < x.rows; _i++)
	{
		fwrite(x.mas[_i], sizeof(DTYPE), x.columns, write_ptr);
	}
	fclose(write_ptr);
	return x.rows * x.columns;
}

ITYPE inputTextFile_SMatrix(char *file, SMatrix *x)
{
	FILE *read_ptr;
	if ((read_ptr = fopen(file, "r")) == NULL)
	{
		fprintf(stderr, "Read error!\n");
		return 0;
	}
	for (UTYPE _i = 0; _i < x->rows; _i++)
	{
		for (UTYPE _j = 0; _j < x->columns; _j++)
		{
			fscanf(read_ptr, "%lf", &(x->mas[_i][_j]));
		}
	}
	fclose(read_ptr);
	return x->rows * x->columns;
}

ITYPE outputTextFile_SMatrix(char *file, SMatrix x, ITYPE type, ITYPE width, ITYPE precision)
{
	FILE *write_ptr;
	if ((write_ptr = fopen(file, "w")) == NULL)
	{
		fprintf(stderr, "Write error!\n");
		return 0;
	}
	if (type == 0)
	{
		for (UTYPE _i = 0; _i < x.rows; ++_i)
			for (UTYPE _j = 0; _j < x.columns; _j++)
				fprintf(write_ptr, "%*.*lf ", width, precision, x.mas[_i][_j]);
	}
	else
	{
		for (UTYPE _i = 0; _i < x.rows; ++_i)
			for (UTYPE _j = 0; _j < x.columns; _j++)
				fprintf(write_ptr, "%*.*e ", width, precision, x.mas[_i][_j]);
	}
	fprintf(write_ptr, "\n");
	printf("Done!");
	fclose(write_ptr);
	return x.rows * x.columns;
}

SMatrix add_SMatrix(SMatrix x, SMatrix y)
{
	if (x.rows != y.rows || x.columns != y.columns)
		return generate_SMatrix(0, 0);

	for (UTYPE i = 0; i < x.rows; i++)
		for (UTYPE j = 0; j < x.columns; j++)
			x.mas[i][j] += y.mas[i][j];

	return x;
}

SMatrix sub_SMatrix(SMatrix x, SMatrix y)
{
	if (x.rows != y.rows || x.columns != y.columns)
		return generate_SMatrix(0, 0);

	for (UTYPE i = 0; i < x.rows; i++)
		for (UTYPE j = 0; j < x.columns; j++)
			x.mas[i][j] -= y.mas[i][j];

	return x;
}

SMatrix mult_SMatrix(SMatrix x, SMatrix y)
{
	if (x.rows != y.rows || x.columns != y.columns)
		return generate_SMatrix(0, 0);

	for (UTYPE i = 0; i < x.rows; i++)
		for (UTYPE j = 0; j < x.columns; j++)
			x.mas[i][j] *= y.mas[i][j];

	return x;
}

SMatrix multConst_SMatrix(SMatrix x, DTYPE y)
{
	for (UTYPE i = 0; i < x.rows; i++)
	{
		for (UTYPE j = 0; j < x.columns; j++)
		{
			x.mas[i][j] *= y;
		}
	}

	return x;
}

SMatrix divide_SMatrix(SMatrix x, SMatrix y)
{
	if (x.rows != y.rows || x.columns != y.columns)
		return generate_SMatrix(0, 0);

	for (UTYPE i = 0; i < x.rows; i++)
	{
		for (UTYPE j = 0; j < x.columns; j++)
		{
			if (y.mas[i][j] == 0)
				return generate_SMatrix(0, 0);

			x.mas[i][j] /= y.mas[i][j];
		}
	}

	return x;
}

SMatrix divideConst_SMatrix(SMatrix x, DTYPE y)
{
	if (y == 0)
		return generate_SMatrix(0, 0);

	for (UTYPE i = 0; i < x.rows; i++)
	{
		for (UTYPE j = 0; j < x.columns; j++)
		{
			x.mas[i][j] /= y;
		}
	}

	return x;
}

SMatrix mod_SMatrix(SMatrix x, SMatrix y)
{
	if (x.rows != y.rows || x.columns != y.columns)
		return generate_SMatrix(0, 0);

	for (UTYPE i = 0; i < x.rows; i++)
	{
		for (UTYPE j = 0; j < x.columns; j++)
		{
			if (y.mas[i][j] == 0)
				return generate_SMatrix(0, 0);

			while (x.mas[i][j] - y.mas[i][j] >= 0)
			{
				x.mas[i][j] -= y.mas[i][j];
			}
		}
	}

	return x;
}

SMatrix modConst_SMatrix(SMatrix x, DTYPE y)
{
	if (y == 0)
		return generate_SMatrix(0, 0);

	for (UTYPE i = 0; i < x.rows; i++)
	{
		for (UTYPE j = 0; j < x.columns; j++)
		{
			while (x.mas[i][j] - y >= 0)
			{
				x.mas[i][j] -= y;
			}
		}
	}

	return x;
}

ITYPE unadd_SMatrix(SMatrix *x, const SMatrix y)
{
	if (x->rows != y.rows || x->columns != y.columns)
		return 0;

	for (UTYPE i = 0; i < x->rows; i++)
	{
		for (UTYPE j = 0; j < x->columns; j++)
		{
			x->mas[i][j] += y.mas[i][j];
		}
	}

	return 1;
}

ITYPE unsub_SMatrix(SMatrix *x, const SMatrix y)
{
	if (x->rows != y.rows || x->columns != y.columns)
		return 0;

	for (UTYPE i = 0; i < x->rows; i++)
	{
		for (UTYPE j = 0; j < x->columns; j++)
		{
			x->mas[i][j] -= y.mas[i][j];
		}
	}

	return 1;
}

ITYPE unmult_SMatrix(SMatrix *x, const SMatrix y)
{
	if (x->rows != y.rows || x->columns != y.columns)
		return 0;

	for (UTYPE i = 0; i < x->rows; i++)
	{
		for (UTYPE j = 0; j < x->columns; j++)
		{
			x->mas[i][j] *= y.mas[i][j];
		}
	}

	return 1;
}

ITYPE undivide_SMatrix(SMatrix *x, const SMatrix y)
{
	if (x->rows != y.rows || x->columns != y.columns)
		return 0;

	for (UTYPE i = 0; i < x->rows; i++)
	{
		for (UTYPE j = 0; j < x->columns; j++)
		{
			if (y.mas[i][j] == 0)
				return 0;

			x->mas[i][j] /= y.mas[i][j];
		}
	}

	return 1;
}

ITYPE unmod_SMatrix(SMatrix *x, const SMatrix y)
{
	if (x->rows != y.rows || x->columns != y.columns)
		return 0;

	for (UTYPE i = 0; i < x->rows; i++)
	{
		for (UTYPE j = 0; j < x->columns; j++)
		{
			if (y.mas[i][j] == 0)
				return 0;

			while (x->mas[i][j] - y.mas[i][j] >= 0)
				x->mas[i][j] -= y.mas[i][j];
		}
	}

	return 1;
}

DTYPE _det_SMatrix(DTYPE **mas, UTYPE n)
{
	DTYPE rezDet;
	ITYPE subJ, s;
	DTYPE **subT;
	if (n == 1)
		return mas[0][0];
	if (n == 2)
		return mas[0][0] * mas[1][1] - mas[0][1] * mas[1][0];
	subT = (DTYPE **)malloc((n - 1) * sizeof(DTYPE));
	rezDet = 0;
	s = 1;
	for (UTYPE _i = 0; _i < n; ++_i)
	{
		subJ = 0;
		for (UTYPE _j = 0; _j < n; ++_j)
			if (_i != _j)
				subT[subJ++] = mas[_j] + 1;
		rezDet = rezDet + s * mas[_i][0] * _det_SMatrix(subT, n - 1);
		s = -s;
	}
	free(subT);
	return rezDet;
}

DTYPE det_SMatrix(SMatrix x)
{
	if (x.columns == x.rows && x.columns > 0)
	{
		return _det_SMatrix(x.mas, x.rows);
	}
	else
	{
		return 0;
	}
}

SMatrix get_adjoint_SMatrix(SMatrix x)
{
	if (x.rows != x.columns)
		return generate_SMatrix(0, 0);

	UTYPE n = x.rows;
	SMatrix answer = generate_SMatrix(n, n);

	return answer;
}

SMatrix inverse_SMatrix(SMatrix x)
{
	if (x.rows != x.columns)
		return generate_SMatrix(0, 0);

	UTYPE n = x.rows;
	SMatrix answer = generate_SMatrix(n, n);

	DTYPE det = det_SMatrix(x);

	if (det == 0)
	{
		return generate_SMatrix(0, 0);
	}

	SMatrix adj = get_adjoint_SMatrix(x);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			answer.mas[i][j] = adj.mas[i][j] / det;

	return answer;
}

SVector solve_SMatrix(SMatrix x, SVector y)
{
	if (x.columns != y.size)
		return generate_SVector(0);
	SVector rez = generate_SVector(x.rows);
	for (UTYPE _r = 0; _r < x.rows; ++_r)
	{
		DTYPE temp = 0;
		for (UTYPE _c = 0; _c < x.columns; ++_c)
		{
			temp += x.mas[_r][_c] * y.mas[_c];
		}
		rez.mas[_r] = temp;
	}
	return rez;
}

ITYPE swap_row_SMatrix(SMatrix *x, UTYPE i, UTYPE j)
{
	if (i < 0 || j < 0 || i >= x->rows || j >= x->rows)
		return 0;
	DTYPE *trow;
	trow = x->mas[i];
	x->mas[i] = x->mas[j];
	x->mas[j] = trow;
	return 1;
}

ITYPE swap_column_SMatrix(SMatrix *x, UTYPE i, UTYPE j)
{
	if (i < 0 || j < 0 || i >= x->columns || j >= x->columns)
		return 0;
	DTYPE temp;
	for (UTYPE _n = 0; _n < x->columns; ++_n)
	{
		temp = x->mas[_n][i];
		x->mas[_n][i] = x->mas[_n][j];
		x->mas[_n][j] = temp;
	}
	return 1;
}