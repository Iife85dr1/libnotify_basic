#include "notify.hpp"

#include <libnotify/notify.h>

Notify::Notify(const char* appname) noexcept : m_appname(appname)
{
    notify_init(appname);
}

void Notify::SetTimeout(unsigned int timeout) { this->m_timeout = timeout; }

Notify::~Notify() { notify_uninit(); }

bool Notify::SendNotify(const char* text) const
{
    NotifyNotification* n = notify_notification_new(this->m_appname.c_str(), text, 0);
    notify_notification_set_timeout(n, this->m_timeout);
    bool ret =  notify_notification_show(n, nullptr);
    g_object_unref(G_OBJECT(n));
    return ret;
}
