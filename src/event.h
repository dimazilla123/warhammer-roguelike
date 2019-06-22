#ifndef EVENT_H
#define EVENT_H

class Event {
public:
    virtual ~Event() {};
    unsigned long long getTime() const { return t; };
    void setTime(unsigned long long t_) { t = t_; };
protected:
    unsigned long long t;
};

#endif
