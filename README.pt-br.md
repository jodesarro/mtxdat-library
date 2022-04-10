# Biblioteca para arquivos no formato Matrix Market

<p align="right"><a href="README.md">Read in English</a></p>

Um conjunto de funções em C++ para lidar com dados numéricos de arquivos no formato [Matrix Market (MTX)](https://math.nist.gov/MatrixMarket/formats.html).

Os arquivos MTX têm uma estrutura inteligente onde é possível armazenar dados bidimensionais em apenas uma coluna.

É muito útil para importar e exportar matrizes, tabelas, conjuntos de dados numéricos e etc.

Esses arquivos geralmente são usados para importar e exportar dados em softwares como [Cell Ranger](https://support.10xgenomics.com/single-cell-gene-expression/software/pipelines/latest/what-is-cell-ranger), [Anjal](http://murasu.com/murasu-anjal/), [Wolfram Mathematica](https://reference.wolfram.com/language/ref/format/MTX.html), dentre outros.

## Funções disponíveis

- Obter dimensões (número de linhas e colunas) de um arquivo MTX
```
void mtxdat_getsize( std::string mtxdat_path, int &imax, int &jmax )
```

- Importar dados numéricos de um arquivo MTX e armazenar os valores em um array de uma dimensão
```
template<typename T>
void mtxdat_import( std::string mtxdat_path, T * data_array, int imax, int jmax )

template<typename T>
void mtxdat_import( std::string mtxdat_path, std::complex<T> * data_array, int imax, int jmax )
```

- Exportar dados numéricos de um array de uma dimensão para um arquivo MTX
```
template<typename T>
void mtxdat_export( std::string mtxdat_path, T * data_array, int imax, int jmax )

template<typename T>
void mtxdat_export( std::string mtxdat_path, std::complex<T> * data_array, int imax, int jmax )
```

## Como usar

A bibliotea está em estilo *header-only* (apenas cabeçalho), ou seja, não é necessário compilá-la separadamente, você só precisa incluir o arquivo <a href="mtxdat-library.hpp">*mtxdat-library.hpp*</a> no seu projeto.

## Licença

Este projeto está protegido sob a licença <a href="LICENSE">MIT License</a> e tem [@jodesarro](https://github.com/jodesarro) como seu principal autor.
