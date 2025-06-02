#pragma once

#include <fstream>
#include <string>
#include <complex>
#include <vector>

void mtxdat_getsize( std::string mtxdat_path, int &imax, int &jmax )
{
    std::fstream mtxdat_file(mtxdat_path);
    mtxdat_file >> imax >> jmax;
    while ( !mtxdat_file.good() )
    {
        mtxdat_file.clear();
        mtxdat_file.ignore(INT_MAX, '\n');
        mtxdat_file >> imax >> jmax;
    }
    mtxdat_file.close();
}

template<typename T>
void mtxdat_import( std::string mtxdat_path, T * data_array, int imax, int jmax )
{
    std::fstream mtxdat_file(mtxdat_path);
    mtxdat_file >> imax >> jmax;
    while ( !mtxdat_file.good() )
    {
        mtxdat_file.clear();
        mtxdat_file.ignore(INT_MAX, '\n');
        mtxdat_file >> imax >> jmax;
    }
    int dim = imax*jmax;
    for ( int i=0; i<dim; i++ )
    {
        mtxdat_file >> data_array[i];
    }
    mtxdat_file.close();
}

template<typename T>
void mtxdat_import( std::string mtxdat_path, std::vector<std::vector<T>> &data_vector, int imax, int jmax )
{
    std::fstream mtxdat_file(mtxdat_path);
    mtxdat_file >> imax >> jmax;
    while ( !mtxdat_file.good() )
    {
        mtxdat_file.clear();
        mtxdat_file.ignore(INT_MAX, '\n');
        mtxdat_file >> imax >> jmax;
    }
    for ( int j=0; j<jmax; j++ )
    {
        for ( int i=0; i<imax; i++ )
        {
            mtxdat_file >> data_vector.at(i).at(j);
        }
    }
    mtxdat_file.close();
}

template<typename T>
void mtxdat_import( std::string mtxdat_path, std::complex<T> * data_array, int imax, int jmax )
{
    std::fstream mtxdat_file(mtxdat_path);
    mtxdat_file >> imax >> jmax;
    while ( !mtxdat_file.good() )
    {
        mtxdat_file.clear();
        mtxdat_file.ignore(INT_MAX, '\n');
        mtxdat_file >> imax >> jmax;
    }
    int dim = imax*jmax;
    double realpart, imagpart;
    for ( int i=0; i<dim; i++ )
    {
        mtxdat_file >> realpart >> imagpart;
        data_array[i] = std::complex<T> (realpart, imagpart);
    }
    mtxdat_file.close();
}

template<typename T>
void mtxdat_import( std::string mtxdat_path, std::vector<std::vector<std::complex<T>>> &data_vector, int imax, int jmax )
{
    std::fstream mtxdat_file(mtxdat_path);
    mtxdat_file >> imax >> jmax;
    while ( !mtxdat_file.good() )
    {
        mtxdat_file.clear();
        mtxdat_file.ignore(INT_MAX, '\n');
        mtxdat_file >> imax >> jmax;
    }
    double realpart, imagpart;
    for (int j=0; j<jmax; j++)
    {
        for ( int i=0; i<imax; i++ )
        {
            mtxdat_file >> realpart >> imagpart;
            data_vector.at(i).at(j) = std::complex<T> (realpart, imagpart);
        }
    }
    mtxdat_file.close();
}

template<typename T>
void mtxdat_export( std::string mtxdat_path, T * data_array, int imax, int jmax, int out_precision = 0, bool out_scientific = false )
{    
    std::fstream mtxdat_file;
    mtxdat_file.open( mtxdat_path, std::fstream::out );
    mtxdat_file << "%%MatrixMarket matrix array real general\n";
    mtxdat_file << "%" << "Created with C/C++ using the MTXdat library: https://github.com/jodesarro/mtxdat-library\n";
    mtxdat_file << imax << " " << jmax << std::endl;
    int dim = imax * jmax;
    for ( int i=0; i<dim; i++ )
    {
        std::stringstream number;
        number << std::showpos;
        if ( out_precision != 0 )
        {
            number.precision(out_precision);
        }
        if ( out_scientific )
        {
            number << std::scientific;
        }
        number << "   " << data_array[i] << std::endl;
        mtxdat_file << number.str();
    }
    mtxdat_file.close();
}

template<typename T>
void mtxdat_export( std::string mtxdat_path, std::vector<std::vector<T>> &data_vector, int imax, int jmax, int out_precision = 0, bool out_scientific = false )
{    
    std::fstream mtxdat_file;
    mtxdat_file.open( mtxdat_path, std::fstream::out );
    mtxdat_file << "%%MatrixMarket matrix array real general\n";
    mtxdat_file << "%" << "Created with C/C++ using the MTXdat library: https://github.com/jodesarro/mtxdat-library\n";
    mtxdat_file << imax << " " << jmax << std::endl;
    for ( int j=0; j<jmax; j++ )
    {
        for ( int i=0; i<imax; i++ )
        {
            std::stringstream number;
            number << std::showpos;
            if ( out_precision != 0 )
            {
                number.precision(out_precision);
            }
            if ( out_scientific )
            {
                number << std::scientific;
            }
            number << "   " << data_vector.at(i).at(j) << std::endl;
            mtxdat_file << number.str();
        }
    }
    mtxdat_file.close();
}

template<typename T>
void mtxdat_export( std::string mtxdat_path, std::complex<T> * data_array, int imax, int jmax, int out_precision = 0, bool out_scientific = false )
{    
    std::fstream mtxdat_file;
    mtxdat_file.open( mtxdat_path, std::fstream::out );
    mtxdat_file << "%%MatrixMarket matrix array complex general\n";
    mtxdat_file << "%" << "Created with C++ using the MTXdat library: https://github.com/jodesarro/mtxdat-library\n";
    mtxdat_file << imax << " " << jmax << std::endl;
    int dim = imax * jmax;
    for ( int i=0; i<dim; i++ )
    {
        std::stringstream number;
        number << std::showpos;
        if ( out_precision != 0 )
        {
            number.precision(out_precision);
        }
        if ( out_scientific )
        {
            number << std::scientific;
        }
        number << "   " << real(data_array[i]) << "   " << imag(data_array[i]) << std::endl;
        mtxdat_file << number.str();
    }
    mtxdat_file.close();
}

template<typename T>
void mtxdat_export( std::string mtxdat_path, std::vector<std::vector<std::complex<T>>> &data_vector, int imax, int jmax, int out_precision = 0, bool out_scientific = false )
{    
    std::fstream mtxdat_file;
    mtxdat_file.open( mtxdat_path, std::fstream::out );
    mtxdat_file << "%%MatrixMarket matrix array complex general\n";
    mtxdat_file << "%" << "Created with C++ using the MTXdat library: https://github.com/jodesarro/mtxdat-library\n";
    mtxdat_file << imax << " " << jmax << std::endl;
    for ( int j=0; j<jmax; j++ )
    {
        for ( int i=0; i<imax; i++ )
        {
            std::stringstream number;
            number << std::showpos;
            if ( out_precision != 0 )
            {
                number.precision(out_precision);
            }
            if ( out_scientific )
            {
                number << std::scientific;
            }
            number << "   " << real(data_vector.at(i).at(j)) << "   " << imag(data_vector.at(i).at(j)) << std::endl;
            mtxdat_file << number.str();
        }
    }
    mtxdat_file.close();
}