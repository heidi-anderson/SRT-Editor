////Ashleigh's testcases will be hosted here
//#include "thpe02.h"
//#include "../catch_amalgamated.hpp"
//
//
//using namespace Catch;
//
//
//TEST_CASE( "readIn - reading in a simple file with one caption" )
//{
//    srtList list;
//    string name = "Hi.txt";
//    ifstream in;
//    frame aFrame;
//
//    in.open( name );
//
//    list.readIn( in, aFrame );
//
//    CHECK( aFrame.startTime == "00:01:00,001" );
//    CHECK( aFrame.endTime == "00:02:00,002" );
//    CHECK( aFrame.caption == "Hi!" );
//}
//
//
//TEST_CASE( "readIN - reading in a simple file with two captions" )
//{
//    srtList list;
//    string name = "WazzUp.txt";
//    ifstream in;
//    frame aFrame;
//
//    in.open( name );
//
//    list.readIn( in, aFrame );
//
//    REQUIRE( aFrame.startTime == "00:05:45,120" );
//    REQUIRE( aFrame.endTime == "00:06:11,030" );
//    REQUIRE( aFrame.caption == "Wazz up!I'm Dave!" );
//}
//
//
//TEST_CASE( "readIn - reading in a simple file with three captions" )
//{
//    srtList list;
//    string name = "Animals.txt";
//    ifstream in;
//    frame aFrame;
//
//    in.open( name );
//
//    list.readIn( in, aFrame );
//
//    REQUIRE( aFrame.startTime == "00:40:00,001" );
//    REQUIRE( aFrame.endTime == "00:02:00,002" );
//    REQUIRE( aFrame.caption == "I like cats!-I like dogs!Ew, I hate animals." );
//}
//
//
//TEST_CASE( "insert - inserting a simple caption and times" )
//{
//    srtList list;
//    frame frameOne, frameTwo, frameThree;
//    bool result;
//
//    SECTION( "front" )
//    {
//        frameOne.startTime = "00:01:00,010";
//        frameOne.endTime = "00:02:00,004";
//        frameOne.caption = "WEEEEEEEEEEEEE";
//
//        result = list.insert( frameOne );
//
//        REQUIRE( result == true );
//    }
//    SECTION( "end" )
//    {
//        frameThree.startTime = "00:03:31,230";
//        frameThree.endTime = "00:04:00,042";
//        frameThree.caption = "Me too!";
//
//        result = list.insert( frameThree );
//
//        REQUIRE( result == true );
//    }
//    SECTION( "middle" )
//    {
//        frameThree.startTime = "00:02:21,390";
//        frameThree.endTime = "00:03:00,042";
//        frameThree.caption = "I like rollercoasters!";
//        result = list.insert( frameTwo );
//
//        REQUIRE( result == true );
//    }
//
//
//}
//
//
//TEST_CASE( "insert - inserting 5 frames" )
//{
//    srtList list;
//    frame frameOne, frameTwo, frameThree, frameFour, frameFive;
//    bool result;
//
//    SECTION( "front" )
//    {
//        frameOne.startTime = "00:01:00,010";
//        frameOne.endTime = "00:02:00,004";
//        frameOne.caption = "Hello!";
//
//        result = list.insert( frameOne );
//
//        REQUIRE( result == true );
//    }
//    SECTION( "end" )
//    {
//        frameFive.startTime = "00:10:31,230";
//        frameFive.endTime = "00:04:00,042";
//        frameFive.caption = "Me too!";
//
//        result = list.insert( frameFive );
//
//        REQUIRE( result == true );
//    }
//    SECTION( "middle - 2" )
//    {
//        frameTwo.startTime = "00:02:21,390";
//        frameTwo.endTime = "00:03:50,000";
//        frameTwo.caption = "-Hi!";
//        result = list.insert( frameTwo );
//
//        REQUIRE( result == true );
//    }
//    SECTION( "middle - 3" )
//    {
//        frameThree.startTime = "00:04:21,390";
//        frameThree.endTime = "00:06:00,100";
//        frameThree.caption = "How are you?";
//
//        result = list.insert( frameThree );
//
//        REQUIRE( result == true );
//    }
//    SECTION( "middle - 4" )
//    {
//        frameFour.startTime = "00:07:11,11";
//        frameFour.endTime = "00:09:33,042";
//        frameFour.caption = "Good! And you?";
//        result = list.insert( frameFour );
//
//        REQUIRE( result == true );
//    }
//}
//
//
//TEST_CASE( "validateTime - testing 00:00:00,000" )
//{
//    srtList list;
//    string time = "00:00:00,000";
//    bool result;
//
//    result = list.validateTime( time );
//
//    REQUIRE( result == true );
//}
//
//
//TEST_CASE( "validateTime - testing invalid time" )
//{
//    srtList list;
//    string time = "00:0a:00,00b";
//    bool result;
//
//    result = list.validateTime( time );
//
//    REQUIRE( result == false );
//}