#ifndef UNIT_TEST_H_INCLUDED
#define UNIT_TEST_H_INCLUDED
#include "C:\GitHub\ScorchedEarth\unit.c"

TEST(initialize_test_unit){


    CHECK( player.points == 0);
    CHECK(player.hp == 100);
    CHECK(bot.points == 0);
    CHECK (bot.hp == 100);
}





#endif // UNIT_TEST_H_INCLUDED
