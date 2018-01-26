/*
* The Construct Open Source Game and Simulation Engine
* Copyright (C) 2017
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 2.1 of the License, or (at your option)
* any later version.
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
* details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* Author: Maxim Serebrennik
*/

#pragma once

#include "Export.h"

#include <tcManager/MessageBase.h>
#include <tcManager/TimingStructure.h>
#include <tcBase/UniqueId.h>
#include <tcUtil/RefStr.h>

#include <string>

namespace tcManager
{
    /**
     * @class   MessageEntityRegistered
     *
     * @brief   A message that is sent out when a new entity is registered with the System Manager.
     */
    class  TC_MANAGER_EXPORT MessageEntityRegistered : public tcManager::MessageBase
    {
    public:
        typedef tcManager::MessageBase BaseClass;           /// Adds an easy and swappable access to the base class

        const static tcUtil::RefStr MESSAGE_TYPE;           /// Holds the class/message type name for efficient comparisons

        /**
         * @fn  MessageEntityRegistered::MessageEntityRegistered(const tcBase::UniqueId* fromActorID, const tcBase::UniqueId* aboutActorID, const std::string* entityType, const std::string* entityName);
         *
         * @brief   Constructor.
         *
         * @param   fromActorID     Identifier of the entity that is sending this message (usually System
         *                          Manager)
         * @param   aboutActorID    Identifier for the Entity that just registered.
         * @param   entityType      Type of the registered entity.
         * @param   entityName      Name of the registered entity.
         */
        MessageEntityRegistered(const tcBase::UniqueId* fromActorID, const tcBase::UniqueId* aboutActorID, const std::string* entityType, const std::string* entityName);

        /**
         * @fn  virtual const std::string& MessageEntityRegistered::GetMessageType() const override;
         *
         * @brief   Returns the Message type.
         *
         * @return  The message type.
         */
        virtual const std::string& GetMessageType() const override;

        /**
         * @fn  virtual const std::string& MessageEntityRegistered::GetEntityType() const;
         *
         * @brief   Gets entity type.
         *
         * @return  The entity type.
         */
        virtual const std::string& GetEntityType() const;

        /**
         * @fn  virtual const std::string& MessageEntityRegistered::GetEntityName() const;
         *
         * @brief   Gets entity type.
         *
         * @return  The entity type.
         */
        virtual const std::string& GetEntityName() const;

    protected:

        /**
         * @fn  MessageEntityRegistered::~MessageEntityRegistered();
         *
         * @brief   Destructor.
         */
        ~MessageEntityRegistered();

    private:

        const std::string* mEntityTypePtr;
        const std::string* mEntityNamePtr;
    };
}