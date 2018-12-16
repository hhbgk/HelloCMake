//
// Created by huanghaibo on 2018/12/16.
//

#ifndef HELLOCMAKE_PLAYER_JNI_H
#define HELLOCMAKE_PLAYER_JNI_H
typedef struct _player{
    int state;
    pthread_t tid;
}player_t;
#endif //HELLOCMAKE_PLAYER_JNI_H
