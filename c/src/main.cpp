#include "detect.hpp"
#include "player.hpp"

int main(int argc, char** argv)
{
    Detector detector;
    Player player;
    while(1) {
        int* res_ptr = detector.detect();
        for (int i = 0; i < 14; i++) {
            player.play(res_ptr[i]);
        }
        usleep(20000);
    }
}
