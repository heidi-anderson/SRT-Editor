#include "srtList.h"

/************************************************************************
 *  @author Donald Weigel, Ashleigh Kirkpatrick and Heidi Anderson
 *
 *  @par Description
    Based on the number of frames, removes a frame from the list
 *
 *  @param[in] frameNumber - which ordered frame to remove from list
 *
 *  @par Example
 *  @verbatim
    srtList list;
    frame frameOne, frameTwo, frameThree;
    list.remove( 3 ); // would be true

    @endverbatim
 ************************************************************************/
bool srtList::remove( int frameNumber )
{
    node* prev;         // ptr for previous node
    node* curr;         // ptr for current node
    int activeNode = 1; // int to keep track of position

    if( frameNumber < 1 || headptr == nullptr ) // check frame num & emptiness
    {
        return false;
    }

    if( frameNumber == 1 ) // remove from front
    {
        headptr = headptr->next;
        return true;
    }

    prev = headptr;   // initialize ptrs
    curr = headptr;

    while( curr != nullptr &&       // remove from middle / end
        activeNode < frameNumber )
    {
        prev = curr;    // traverse
        curr = curr->next;
        activeNode++;
    }

    if( curr == nullptr )   // out of bounds
    {
        return false;
    }

    prev->next = curr->next;    // traverse

    return true;
}