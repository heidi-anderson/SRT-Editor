/** ***************************************************************************
 * @file
 *
 * @brief has all of Donald Weigel's srtList functions.
 *****************************************************************************/

#include "thpe02.h"

/************************************************************************
 *  @author Donald
 *
 *  @par Description
    Based on the number of frames in the list, finds if a frame is in the list
 *
 *  @param[in] frameNumber - which ordered frame to find
 *
 *  @par Example
 *  @verbatim
    srtList list;
    frame frameOne, frameTwo, frameThree;
    list.find( 2 ); // would equal true

    @endverbatim
 ************************************************************************/
bool srtList::find( int frameNumber )
{
    node* walker = headptr;
    int counter = 1;
    
    while( walker != nullptr )
    {
        if( counter == frameNumber )
            return true;

        walker = walker->next;
        counter++;
    }

    return false;
}