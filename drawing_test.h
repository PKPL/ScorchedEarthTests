#ifndef DRAWING_TEST_H
#define DRAWING_TEST_H

#include "C:\GitHub\ScorchedEarth\maps_create.c"
#include "C:\GitHub\ScorchedEarth\drawing_units.c"
#include "C:\GitHub\ScorchedEarth\unit.c"
#include "C:\GitHub\ScorchedEarth\drawing_maps.c"
#include "C:\GitHub\ScorchedEarth\drawing_shots.c"
#include "C:\GitHub\ScorchedEarth\shot_final_equation.c"
#include "C:\GitHub\ScorchedEarth\drawing_destruction.c"


TEST(drawing_destruction_test)
{
    int map_layout[100][80] = {{0}};

    create_mountain_map(map_layout);
    CHECK(NULL != map_layout);
    create_destruction(map_layout);
    CHECK(NULL != map_layout);
}

TEST(drawing_shots_test)
{
    missile_data* MISSILE = initializeMissile(10, 10);
    CHECK(NULL != MISSILE);
}

TEST(drawing_maps_test)
{
    int map_layout[100][80] = {{0}};

    create_mountain_map(map_layout);
    CHECK(NULL != map_layout);
}

TEST(drawing_units_test)
{
    int map_layout[100][80] = {{0}};

    create_mountain_map(map_layout);
    test_drawing_units(map_layout);
    int x, y;
    int counter_player = 0;
    int counter_enemy = 0;

    for (x = 0; x < 100; x++)
    {
        for (y = 0; y < 80; y++)
        {
            if (map_layout[x][y] == 2)
            {
                counter_player++;
            }
            else if (map_layout[x][y] == 3)
            {
                counter_enemy++;
            }
        }
    }

    CHECK (1 == counter_player);
    CHECK (1 == counter_enemy);

}

#endif // DRAWING_TEST_H
