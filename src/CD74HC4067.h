#ifndef CD74HC4067_h
#define CD74HC4067_h

class CD74HC4067 {
public:
    CD74HC4067(int s0, int s1, int s2, int s3, int enable);
    void setChannel(int channel);
private:
    int _s0, _s1, _s2, _s3, _enable;
};

#endif
