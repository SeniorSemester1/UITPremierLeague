#ifndef PLAYERWRITER_H
#define PLAYERWRITER_H


class PlayerWriter
{
public:
    virtual void addPlayer();
    virtual void removePlayer();
    virtual void defragment();
};

#endif // PLAYERWRITER_H
