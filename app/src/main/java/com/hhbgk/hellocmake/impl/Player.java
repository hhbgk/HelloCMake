package com.hhbgk.hellocmake.impl;

public class Player {
    private native boolean nativeInit();
    private native boolean nativeCreate(int port, String ip);
    private native boolean nativeClose();

    public Player() {
        nativeInit();
    }

    public boolean create(int port, String ip) {
        return nativeCreate(port, ip);
    }
}
