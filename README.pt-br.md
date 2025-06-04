# Biblioteca MTXdat: um conjunto de funções em C++ para lidar com dados numéricos de arquivos no formato Matrix Market

<p align="right"><a href="README.md">Read in English</a></p>

Os arquivos [Matrix Market (MTX)](https://math.nist.gov/MatrixMarket/formats.html) têm uma estrutura inteligente que torna possível armazenar dados bidimensionais em apenas uma coluna. É muito útil para importar e exportar matrizes, tabelas, conjuntos de dados numéricos e etc. Tais arquivos são geralmente utilizados para importar e exportar dados em softwares como [Cell Ranger](https://support.10xgenomics.com/single-cell-gene-expression/software/pipelines/latest/what-is-cell-ranger), [Anjal](http://murasu.com/murasu-anjal/), [Wolfram Mathematica](https://reference.wolfram.com/language/ref/format/MTX.html), dentre outros.

## Funções disponíveis

### Leitura e importação de dados

- Obter dimensões (número de linhas e colunas) de um arquivo MTX
```
void mtxdat_getsize( std::string mtxdat_path, int &imax, int &jmax )
```

- Importar dados numéricos de um arquivo MTX e armazenar os valores em um *array* de uma dimensão
```
template<typename T>
void mtxdat_import( std::string mtxdat_path, T * data_array, int imax, int jmax )
```

- Importar dados numéricos complexos de um arquivo MTX e armazenar os valores em um *complex array* de uma dimensão
```
template<typename T>
void mtxdat_import( std::string mtxdat_path, std::complex<T> * data_array, int imax, int jmax )
```

- Importar dados numéricos de um arquivo MTX e armazenar os valores em um *vector* de duas dimensões
```
template<typename T>
void mtxdat_import( std::string mtxdat_path, std::vector<std::vector<T>> &data_vector, int imax, int jmax )
```

- Importar dados numéricos complexos de um arquivo MTX e armazenar os valores em um *complex vector* de duas dimensões
```
template<typename T>
void mtxdat_import( std::string mtxdat_path, std::vector<std::vector<std::complex<T>>> &data_vector, int imax, int jmax )
```

### Exportação de dados

- Exportar dados numéricos de um *array* de uma dimensão para um arquivo MTX
```
template<typename T>
void mtxdat_export( std::string mtxdat_path, T * data_array, int imax, int jmax, int out_precision = 0, bool out_scientific = false )
```

- Exportar dados numéricos complexos de um *complex array* de uma dimensão para um arquivo MTX
```
template<typename T>
void mtxdat_export( std::string mtxdat_path, std::complex<T> * data_array, int imax, int jmax, int out_precision = 0, bool out_scientific = false )
```

- Exportar dados numéricos de um *vector* de uma dimensão para um arquivo MTX
```
template<typename T>
void mtxdat_export( std::string mtxdat_path, std::vector<std::vector<T>> &data_vector, int imax, int jmax, int out_precision = 0, bool out_scientific = false )
```

- Exportar dados numéricos complexos de um *complex vector* de duas dimensões para um arquivo MTX
```
template<typename T>
void mtxdat_export( std::string mtxdat_path, std::vector<std::vector<std::complex<T>>> &data_vector, int imax, int jmax, int out_precision = 0, bool out_scientific = false )
```

## Como usar

A bibliotea está em estilo *header-only* (apenas cabeçalho), ou seja, não é necessário compilá-la separadamente, você só precisa incluir o arquivo <a href="mtxdat-library.hpp">*mtxdat-library.hpp*</a> no seu projeto.

## Autoria

Os códigos e rotinas foram desenvolvidos e são atualizados por <a href="https://www.researchgate.net/profile/Jhonas-de-Sarro">Jhonas O. de Sarro</a> ([@jodesarro]( https://github.com/jodesarro )).

## Licença

Este projeto está protegido sob a licença <a href="LICENSE">MIT License</a>.
