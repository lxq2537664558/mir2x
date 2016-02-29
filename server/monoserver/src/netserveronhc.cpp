/*
 * =====================================================================================
 *
 *       Filename: netserveronhc.cpp
 *        Created: 02/24/2016 01:52:37
 *  Last Modified: 02/28/2016 16:59:39
 *
 *    Description: 
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

#include "monoserver.hpp"

MonoServer::ReadHC()
{
    std::function<void(uint8_t)> fnProcessHC = [this, fnProcessHC](uint8_t nSMID){
        switch(nSMHC){
            case CM_PING:           OnPing()  ; break;
            case CM_LOGIN:          OnLogin() ; break;
            case CM_PING:           OnPing()  ; break;
            case CM_PING:           OnPing()  ; break;
            case CM_PING:           OnPing()  ; break;
            default: break;
        }
        m_NetIO.ReadHC(fnProcessHC);
    };
    m_NetIO.ReadHC(fnProcessHC);
}

void MonoServer::OnPing()
{
    auto fnResponsePing = [this, &nTick](){
        m_NetIO.Send(SM_PING, nTick);
    };
    m_NetIO.Read(nTick, fnResponsePing);
}

void MonoServer::OnPing()
{
    auto fnResponsePing = [this, &nTick](){
        m_NetIO.Send(SM_PING, nTick);
    };
    m_NetIO.Read(nTick, fnResponsePing);

    Read(4, fnOnRead)
}


