#ifndef NOTIFY_HPP
#define NOTIFY_HPP
#include <string>

class Notify
{
public:
    explicit Notify(const char* appname) noexcept;
    ~Notify();
    bool SendNotify(const char* text) const;
    void SetTimeout(unsigned int timeout);

private:
    unsigned int m_timeout = 5000;
    std::string m_appname;
};

#endif // NOTIFY_HPP
