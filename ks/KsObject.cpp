/*
   Copyright (C) 2015 Preet Desai (preet.desai@gmail.com)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include <ks/KsObject.hpp>
#include <ks/KsLog.hpp>

namespace ks
{
    std::mutex Object::s_id_mutex;

    // Start at one so that an Id of 0
    // can be considered invalid / unset
    Id Object::s_id_counter(1);

    Id Object::genId()
    {
        std::lock_guard<std::mutex> lock(s_id_mutex);
        Id id = s_id_counter;
        s_id_counter++;
        return id;
    }

    // ============================================================= //

    Object::Object(Key const &,shared_ptr<EventLoop> const &event_loop) :
        m_id(genId()),
        m_event_loop(event_loop)
    {

    }

    void Object::Init(Key const &, shared_ptr<Object> const &)
    {

    }

    Object::~Object()
    {

    }

    Id Object::GetId() const
    {
        return m_id;
    }

    shared_ptr<EventLoop> const & Object::GetEventLoop() const
    {
        return m_event_loop;
    }

} // ks
