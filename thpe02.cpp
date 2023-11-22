/** **************************************************************************
 * @file 
 ****************************************************************************/
/** **************************************************************************
 * @mainpage THPE01 - The SRT Editor
 * 
 * @section course_section Course Information 
 *
 * @author Heidi Anderson, Ashleigh Kirkpatrick, Donald Weigel
 * 
 * @par Professor: 
 *         Roger Schrader
 * 
 * @par Course:
 *         CSC215 - M02 - Programming Techniques
 * 
 * @par Location: 
 *         McLaury - M205
 * 
 * @date Due November 7, 2023
 *
 * @section program_section Program Information 
 * 
 * @details 
 * This program creates subtitles for a film or movie.
 *
 * By utilizying singly linked lists and classes we will make a program 
 * that can create and modify subtitles that you can use for films and tv shoes
 *
 * This program works by being fed an instructional file and optionally given
 * an srt file. It reads the instructional file and based on the instructions it
 * is given it will remove, print, or add frames with subtitles to the already
 * existing/new srt file.
 *
 * @section compile_section Compiling and Usage 
 *
 * @par Compiling Instructions: 
 *      none - a straight compile and link with no external libraries.
 * 
 * @par Usage: 
   @verbatim  
   c:\> thpe02.exe instructionalfile.txt srtfile.srt

	Usage: thpe02.exe instructionFile srtFile
           instructionfile - a list of modifications to be done to the srt list
           srtFile - valid srt captions to be loaded if the file exists

   @endverbatim 
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 * 
 * @todo none
 * 
 * @par Modifications and Development Timeline: 
 * This is a link to gitlab's commit as an example. To view <a target="_blank" 
 * href="https://gitlab.cse.sdsmt.edu/csc215/fall2023/team12/-/commits/main?ref_type=heads">click here.</a>
 * 
 *****************************************************************************/

#include "thpe02.h"

 /** ***************************************************************************
  * @author Heidi Anderson, Ashleigh Kirkpatrick
  *
  * @par Description
  * This is the main implementation of the program.  It will retrieve an
  * instructional file, and can retrieve an SRT file if given. If any errors
  * are encountered with the arguments an error message is printed and the
  * program exits. 
  * 
  * If two arguments were retrieved, it opens the instructional file. If three
  * arguments were given it will open the instructional file and open the SRT
  * file. 
  * 
  * After processing the srtFile and Instructional file all files are closed. 
  *
  * @param[in] argc - the number of arguments from the command prompt.
  * @param[in] argv - a 2d array of characters containing the arguments
  *
  * @returns 0 to exit
  *
  * *****************************************************************************/
int main( int argc, char** argv )
{
    ifstream finstructions; // inputed instructional file
    ifstream finSRT;        // inputed srt file
    ofstream fout;          // output file
    srtList list;           // srt list variable
    frame aFrame;           // frame struct variable

    if( argc != 2 && argc != 3 )    // check number of arguments
    {
        usageState( );  // print usage statement
        return 0;       // return
    }

    if ( !openInput( finstructions, argv[1] ) ) // open instructional file
        return 0;   // return if not open

    if( argc == 2 )  // no srt list given
    {
        readInstructions( finstructions, fout, list );  // read instructional file
    }
    if( argc == 3 )  // srt list given
    {
        if ( !openInput( finSRT, argv[2] ) )    // open srt file
            return 0;   // return if not open

        list.readSrtFile( finSRT, aFrame );            // read the srt file
        readInstructions( finstructions, fout, list ); // read indstructional file
    }


    finSRT.close( );        // close files
    finstructions.close( );
    fout.close( );

    return 0;   // return
}
