#ifndef DRAWING_TEST_H
#define DRAWING_TEST_H

#include "C:\GitHub\ScorchedEarth\unit.c"
#include "C:\GitHub\ScorchedEarth\drawing_units.c"


TEST (check_one_player_one_enemy) {

    int map_layout_test [100][80] = {{0}};

    test_drawing_units(map_layout_test);

    int counter_PLAYER= 0;
    int counter_ENEMY = 0;
    for (int x = 0; x < 100; x++)
    {
        for (int y = 0; y < 80; y++)
        {
            if (map_layout_test[x][y] == 2)
            {
                counter_PLAYER ++;
            }
            else if (map_layout_test[x][y] == 3)
            {
                counter_ENEMY ++;
            }
        }
    }
    CHECK ( 1 == counter_PLAYER );
    CHECK ( 1 == counter_ENEMY );
}

#endif // DRAWING_TEST_H
