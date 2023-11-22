#include "thpe02.h"

/** ***************************************************************************
 * @author Heidi Anderson
 *
 * @par Description:
 * outputs usage statement to terminal
 *
 * @par Example:
   @verbatim
   usageState( );
   // outputs usage statement
 *
 *****************************************************************************/
void usageState( )
{
    cout << "Usage: thpe02.exe instructionFile srtFile" << endl;
    cout << "       instructionFile - a list of modifications to be done to the srt list" << endl;
    cout << "       srtFile - valid srt captions to be loaded if the file exists" << endl;
}
