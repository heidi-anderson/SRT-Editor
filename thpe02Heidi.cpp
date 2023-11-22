/** ***************************************************************************
 * @file
 *
 * @brief Heidi's functions
 *****************************************************************************/

#include "thpe02.h"

/** ***************************************************************************
 * @author Heidi Anderson
 *
 * @par Description:
 * Opens an ifstream for file input
 *
 * @param[in,out] file - reference to ifstream
 * @param[in] fileName - name of file to be opened
 *
 * @returns true for success, false otherwise
 *
 * @par Example:
   @verbatim
   openInput(InputFile.ppm, fin);
   @endverbatim
 *
 *****************************************************************************/
bool openInput( ifstream& file, string fileName )
{
    file.open( fileName) ;
    if( !file.is_open( ) )
    {
        cout << "Unable to open the file: " << fileName << endl;
        return false;
    }

    return true;
}



/** ***************************************************************************
 * @author Heidi Anderson
 *
 * @par Description:
 * Opens an ofstream for file output
 *
 * @param[in,out] file - reference to ofstream
 * @param[in] fileName - name of file to be opened
 *
 * @returns true for success, false otherwise
 *
 * @par Example:
   @verbatim
   openOutput(outputFile.ppm, fout);
   @endverbatim
 *
 *****************************************************************************/
bool openOutput( ofstream& file, string fileName )
{
    file.open( fileName );
    if( !file.is_open( ) )
    {
        cout << "Unable to open the file: " << fileName << endl;
        return false;
    }

    return true;
}