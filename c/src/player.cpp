#include "player.hpp"

Player::Player()
{
    ;
}

void Player::play(int key_num)
{
    switch (13 - key_num) {
        case 0: system("play ../mp3_14/40-C.mp3 & > /dev/null"); break;
        case 1: system("play ../mp3_14/42-D.mp3 & > /dev/null"); break;
        case 2: system("play ../mp3_14/44-E.mp3 & > /dev/null"); break;
        case 3: system("play ../mp3_14/45-F.mp3 & > /dev/null"); break;
        case 4: system("play ../mp3_14/47-G.mp3 & > /dev/null"); break;
        case 5: system("play ../mp3_14/49-A.mp3 & > /dev/null"); break;
        case 6: system("play ../mp3_14/51-B.mp3 & > /dev/null"); break;
        case 7: system("play ../mp3_14/52-C.mp3 & > /dev/null"); break;
        case 8: system("play ../mp3_14/54-D.mp3 & > /dev/null"); break;
        case 9: system("play ../mp3_14/56-E.mp3 & > /dev/null"); break;
        case 10: system("play ../mp3_14/57-F.mp3 & > /dev/nul"); break;
        case 11: system("play ../mp3_14/59-G.mp3 & > /dev/nul"); break;
        case 12: system("play ../mp3_14/61-A.mp3 & > /dev/nul"); break;
        case 13: system("play ../mp3_14/63-B.mp3 & > /dev/nul"); break;
    }
}
