#pragma once


class Observer {
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};

class Observable {
public:
    virtual ~Observable() = default;
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObserver() const = 0;
};
