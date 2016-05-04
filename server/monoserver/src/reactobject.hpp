/*
 * =====================================================================================
 *
 *       Filename: reactobject.hpp
 *        Created: 04/21/2016 23:02:31
 *  Last Modified: 05/03/2016 14:32:16
 *
 *    Description: object only react to message, with an object pod
 *                 atoms of an react object:
 *                      1. before Activate(), we can call its internal method by ``this"
 *                      2. after Activate(), we can only use ReactObject::Send()
 *
 *                 In other word, after Activate(), react object can only communicate
 *                 with react object or receiver
 *
 *                 This prevent me implement MonoServer as react object. For MonoServer
 *                 it needs to manager SessionHub. However SessionHub is not an actor, so
 *                 if MonoServer is an react object, we have to launch SessionHub before
 *                 calling of MonoServer::Activate(), but, before activation of MonoServer
 *                 we don't have the address of Mo MonoServer to pass to SessionHub!
 *
 *                 In my design, SessionHub create Session's with SID and pass it to the
 *                 MonoServer, then MonoServer check info of this connection from DB and
 *                 create player object, bind Session pointer to the player and send the
 *                 player to proper RegionMonitor via ServerMap object.
 *
 *                 Another thing is for g_MonoServer->AddLog(...), if make MonoServer as
 *                 a react object, we can't use it anymore
 *
 *                 So let's make MonoServer as a receriver instead.
 *
 *        Version: 1.0
 *       Revision: none
 *       Compiler: gcc
 *
 *         Author: ANHONG
 *          Email: anhonghe@gmail.com
 *   Organization: USTC
 *
 * =====================================================================================
 */

#pragma once
#include <Theron/Theron.h>

#include "messagepack.hpp"
#include "serverobject.hpp"

class ActorPod;
class ReactObject: public ServerObject
{
    protected:
        ActorPod *m_ActorPod;

    public:
        ReactObject(uint8_t, uint32_t, uint32_t);
        ~ReactObject();

    public:
        virtual Theron::Address Activate();
        virtual void Operate(const MessagePack &, const Theron::Address &) = 0;

    public:
        // // send with response operation registering
        // bool Send(const MessagePack &, const Theron::Address &,
        //         const std::function<void(const MessagePack &, const Theron::Address &)> &);
        // bool Send(const MessagePack &rstMSG, const Theron::Address &rstAddress)
        // {
        //     std::function<void(const MessagePack &, const Theron::Address &)> fnNullOp;
        //     return Send(rstMSG, rstAddress, fnNullOp);
        // }
        // template<typename... U> bool Send(U&&... stArgs)
        // {
        //     return m_ActorPod->Send(std::forward<U>(stArgs)...);
        // }
};