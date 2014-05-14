#ifndef SHOT_TEST_H
#define SHOT_TEST_H

#include "C:\GitHub\ScorchedEarth\shot.h"
#include "C:\GitHub\ScorchedEarth\shot_final_equation.c"
#include "C:\GitHub\ScorchedEarth\drawing_shots.h"
#include "C:\GitHub\ScorchedEarth\maps_create.c"
#include "C:\GitHub\ScorchedEarth\shot_formula.c"



//SHOT_FINAL_EQUATION

TEST(initializeMissileTest){
    missile_data* MISSILE = initializeMissile(10, 10);
    CHECK(NULL != MISSILE);
    CHECK(strcmp(MISSILE->name, "Super Light Missile")==0);
    CHECK_CLOSE(1.8, MISSILE->weight, 1e-6);
    CHECK(MISSILE->initial_velocity == 0);
    CHECK(MISSILE->shot_angle == 0);
    CHECK(MISSILE->x_turret_position == 10);
    CHECK(MISSILE->y_turret_position == 10);
}
//
TEST(cosAndSinDegrees){
    CHECK_CLOSE(0.7071, cosDegrees(45), 1e-4);
    CHECK_CLOSE(0.7071, sinDegrees(45), 1e-4);
    CHECK_CLOSE(0.7071, cosDegrees(-45), 1e-4);
    CHECK_CLOSE(-0.7071, sinDegrees(-45), 1e-4);
}

struct fixCreateMissileData{
    fixCreateMissileData(){
        MISSILE.weight = 1.8;
        MISSILE.initial_velocity = 30.;
        MISSILE.x_turret_position = 5;
        MISSILE.y_turret_position = 5;
        MISSILE.shot_angle = 45;
    }
    ~fixCreateMissileData(){ }
    missile_data MISSILE;
    // SOME EXPECTED RESULTS FOR FIXED VALUES
    // OF INITIAL VELOCITY AND WIND VELOCITY
    // 1. time = 1.0 (index =  50), init_v = 30, wind_v = 0
    // 2. time = 2.0 (index = 100), init_v = 36, wind_v = 1
    // 3. time = 3.0 (index = 150), init_v = 42, wind_v = 2
    int test_data[3][2] = {{25, 20},{54, 34},{91, 45}};
};

TEST_FIXTURE(fixCreateMissileData, test){
    int i;
    float data[2];
    for(i=0; i<3; i++){
        missile_data M = MISSILE;
        M.initial_velocity = 30.+6*i;
        xCoordinate(&M, i);
        yCoordinate(&M);
        data[0] = M.x_vector_coordinate[50*(i+1)];
        data[1] = M.y_vector_coordinate[50*(i+1)];
        CHECK_ARRAY_EQUAL(test_data[i], data, 2);
    }
}


//SHOT_FORMULA

TEST(playerShotTest)
{
    int mapLayout[100][80];
    create_mountain_map(mapLayout);
    missile_data* MISSILE = initializeMissile(10, 10);
    CHECK(NULL != MISSILE);
    playerShot(MISSILE, 30, 30, mapLayout);

}

#endif // SHOT_TEST_H
