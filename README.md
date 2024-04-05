# School 21. Matrix

Development of the matrix.h library.

### Matrix Functions Overview

| Function             | Description                               | Status |
|----------------------|-------------------------------------------|--------|
| s21_create_matrix    | Creates a matrix of given size.          |   ☑️   |
| s21_remove_matrix    | Removes a matrix, freeing memory.         |   ☑️   |
| s21_eq_matrix        | Checks equality of two matrices.          |   ☑️   |
| s21_sum_matrix       | Adds two matrices.                        |   ☑️   |
| s21_sub_matrix       | Subtracts one matrix from another.        |   ☑️   |
| s21_mult_number      | Multiplies each matrix element by a number. |   ☑️   |
| s21_mult_matrix      | Multiplies one matrix by another.         |   ☑️   |
| s21_transpose        | Transposes a matrix.                      |   ☑️   |
| s21_calc_complements | Calculates complements of matrix elements. |   ☑️   |
| s21_determinant      | Calculates matrix determinant.            |   ☑️   |
| s21_inverse_matrix   | Calculates matrix inverse.                |   ☑️   |

## Run Locally
Before starting the project, you will need to install the Check library and the lcov and gcov utilities. Next, follow these steps:

1. Clone the project

```bash
  git clone git@github.com:kmiakaeva/S21-matrix.git
```

2. Go to the project directory

```bash
  cd S21-matrix
```

3. Go to the src folder

```bash
  cd src
```

4. Run make to build matrix.a

```bash
  make
```

5. Run test

```bash
  make test
```

6. Run to generate gcov report

```bash
  make gcov_report
```

### Additional commands

1. Run to clear assembly files

```bash
  make clean
```

2. Run test with valgrind

```bash
  make valgrind
```
