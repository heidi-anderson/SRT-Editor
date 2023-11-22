#include "thpe02.h"

void usageState()
{
    cout << "Usage: thpe02.exe instructionFile srtFile" << endl;
    cout << "       instructionfile - a list of modifications to be done to the srt list" << endl;
    cout << "       srtFile - valid srt captions to be loaded if the file exists" << endl;
}
/** ***************************************************************************
 * @author Heidi Anderson
 *
 * @par Description:
 * Does error checking for command line arguments
 *
 * @param[in,out] argc - number of arguments
 * @param[in,out] argv - character array of arguments
 * @param[in,out] file - input instructional file
 *
 *
 * @par Example:
   @verbatim
   commandLine(argc, argv, instructionFile)
    
if(argc < 2 || argc > 3)
    output:
        Usage: thep02.exe instructionFile srtFile
               instructionFile - a list of modifications to be done to the srt list
               srtFile - valid srt captions to be loaded if the file exists
else
    file opens, checks validity and returns. 
    @endverbatim
 *
 *****************************************************************************/
int commandLine(int& argc, char**& argv, ifstream& file)
{
    if (argc < 2 || argc > 3)   // check number of arguments
    {
        usageState();
        exit(0);
    }

    file.open(argv[1]);     // open instruction file
    if (!file.is_open())
    {
        cout << "Unable to open file: " << argv[1] << endl;
    }

    return 0;
}