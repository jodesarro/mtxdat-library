#pragma once

#include <fstream>
#include <string>
#include <complex>

void mtxdat_getsize( std::string mtxdat_path, int &imax, int &jmax )
{
    std::fstream mtxdat_file( mtxdat_path );
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
    std::fstream mtxdat_file( mtxdat_path );

    mtxdat_file >> imax >> jmax;
    while ( !mtxdat_file.good() )
    {
        mtxdat_file.clear();
        mtxdat_file.ignore(INT_MAX, '\n');
        mtxdat_file >> imax >> jmax;
    }

    int dim = imax * jmax;
    
    for ( int i=0; i<dim; i++ )
    {
        mtxdat_file >> data_array[i];
    }

    mtxdat_file.close();
}

template<typename T>
void mtxdat_import( std::string mtxdat_path, std::complex<T> * data_array, int imax, int jmax )
{
    std::fstream mtxdat_file( mtxdat_path );

    mtxdat_file >> imax >> jmax;
    while ( !mtxdat_file.good() )
    {
        mtxdat_file.clear();
        mtxdat_file.ignore(INT_MAX, '\n');
        mtxdat_file >> imax >> jmax;
    }

    int dim = imax * jmax;

    double realpart, imagpart;
    for ( int i=0; i<dim; i++ )
    {
        mtxdat_file >> realpart >> imagpart;
        data_array[i] = std::complex<T> (realpart, imagpart);
    }

    mtxdat_file.close();
}

template<typename T>
void mtxdat_export( std::string mtxdat_path, T * data_array, int imax, int jmax, int out_precision = 0, bool out_scientific = false )
{    
    std::fstream mtxdat_file;
    mtxdat_file.open( mtxdat_path, std::fstream::out );

    mtxdat_file << "%%MatrixMarket matrix array real general\n%\n";
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
void mtxdat_export( std::string mtxdat_path, std::complex<T> * data_array, int imax, int jmax, int out_precision = 0, bool out_scientific = false )
{    
    std::fstream mtxdat_file;
    mtxdat_file.open( mtxdat_path, std::fstream::out );

    mtxdat_file << "%%MatrixMarket matrix array complex general\n%\n";
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
