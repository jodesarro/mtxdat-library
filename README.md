# MTXdat library: A set of C++ functions to handle numeric data in the Matrix Market file format

<p align="right"><a href="README.pt-br.md">Leia em português (br)</a></p>

The [Matrix Market (MTX)](https://math.nist.gov/MatrixMarket/formats.html) file format has a clever structure where one can store two-dimensional data in only one column. It is a very useful format for importing and exporting matrices, tables, numeric datasets and so on. Files in such format are generally used for importing and exporting data in softwares such as [Cell Ranger](https://support.10xgenomics.com/single-cell-gene-expression/software/pipelines/latest/what-is-cell-ranger), [Anjal](http://murasu.com/murasu-anjal/), [Wolfram Mathematica](https://reference.wolfram.com/language/ref/format/MTX.html), among others.

## Available functions

### Reading and importing data

- Get dimensions (the number of rows and columns) of a MTX file
```
void mtxdat_getsize( std::string mtxdat_path, int &imax, int &jmax )
```

- Import numeric data from a MTX file and store the values in an one-dimensional array
```
template<typename T>
void mtxdat_import( std::string mtxdat_path, T * data_array, int imax, int jmax )
```

- Import complex numeric data from a MTX file and store the values in an one-dimensional complex array
```
template<typename T>
void mtxdat_import( std::string mtxdat_path, std::complex<T> * data_array, int imax, int jmax )
```

- Import numeric data from a MTX file and store the values in a two-dimensional vector
```
template<typename T>
void mtxdat_import( std::string mtxdat_path, std::vector<std::vector<T>> &data_vector, int imax, int jmax )
```

- Import complex numeric data from a MTX file and store the values in a two-dimensional complex vector
```
template<typename T>
void mtxdat_import( std::string mtxdat_path, std::vector<std::vector<std::complex<T>>> &data_vector, int imax, int jmax )
```

### Exporting data

- Export numeric data of an one-dimensional array to a MTX file
```
template<typename T>
void mtxdat_export( std::string mtxdat_path, T * data_array, int imax, int jmax, int out_precision = 0, bool out_scientific = false )
```

- Export complex numeric data of an one-dimensional complex array to a MTX file
```
template<typename T>
void mtxdat_export( std::string mtxdat_path, std::complex<T> * data_array, int imax, int jmax, int out_precision = 0, bool out_scientific = false )
```

- Export numeric data of a two-dimensional vector to a MTX file
```
template<typename T>
void mtxdat_export( std::string mtxdat_path, std::vector<std::vector<T>> &data_vector, int imax, int jmax, int out_precision = 0, bool out_scientific = false )
```

- Export complex numeric data of a two-dimensional complex vector to a MTX file
```
template<typename T>
void mtxdat_export( std::string mtxdat_path, std::vector<std::vector<std::complex<T>>> &data_vector, int imax, int jmax, int out_precision = 0, bool out_scientific = false )
```

## How to use

The library is in a header-only library style, i.e., there is nothing to build, you only have to include the <a href="mtxdat-library.hpp">*mtxdat-library.hpp*</a> file into your project.

## Authorship

The codes and routines were developed and are updated by <a href="https://www.researchgate.net/profile/Jhonas-de-Sarro">Jhonas O. de Sarro</a> ([@jodesarro]( https://github.com/jodesarro )).

## Licensing

This project is protected under <a href="LICENSE">MIT License</a>.
