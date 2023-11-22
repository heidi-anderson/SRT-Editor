/** ***************************************************************************
 * @file
 *****************************************************************************/
#include "thpe02.h"
#include "../catch_amalgamated.hpp"


TEST_CASE( "Remove - removing items that are not in list")
{
    srtList test;
    frame frame1;
    frame frame2;
    frame frame3;
    frame frame4;

    test.insert( frame1 );
    test.insert( frame2 );
    test.insert( frame3 );
    test.insert( frame4 );

    REQUIRE( test.remove( 5 ) == false );
}


TEST_CASE( "Remove - removing item that is there" )
{
    srtList test;
    frame frame1;
    frame frame2;
    frame frame3;
    frame frame4;

    test.insert( frame1 );
    test.insert( frame2 );
    test.insert( frame3 );
    test.insert( frame4 );

    REQUIRE( test.remove( 3 ) == true );
}


TEST_CASE( "Remove - removing multiple items in a row" )
{
    srtList test;
    frame frame1;
    frame frame2;
    frame frame3;
    frame frame4;

    test.insert( frame1 );
    test.insert( frame2 );
    test.insert( frame3 );
    test.insert( frame4 );

    REQUIRE( test.remove( 3 ) == true );
    REQUIRE( test.remove( 3 ) == true );
    REQUIRE( test.remove( 3 ) == false);
}


TEST_CASE( "Find - find an item that is not in the list" )
{
    srtList test;
    frame frame1;
    frame frame2;
    frame frame3;
    frame frame4;

    test.insert( frame1 );
    test.insert( frame2 );
    test.insert( frame3 );
    test.insert( frame4 );

    REQUIRE( test.find( 5 ) == false );
}


TEST_CASE( "Find - item is in list" )
{
    srtList test;
    frame frame1;
    frame frame2;
    frame frame3;
    frame frame4;

    test.insert( frame1 );
    test.insert( frame2 );
    test.insert( frame3 );
    test.insert( frame4 );

    REQUIRE( test.find( 2 ) == true );
}