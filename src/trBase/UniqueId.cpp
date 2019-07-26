/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2019 Acid Rain Studios LLC
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 3.0 of the License, or (at your option)
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
* @author Maxim Serebrennik
*/

#include <trBase/UniqueId.h>

#include <trUtil/PlatformMacros.h>
#include <trUtil/Logging/Log.h>

#include <bID/uuid/random_generator.hpp>
#include <bID/uuid/string_generator.hpp>
#include <bID/uuid/nil_generator.hpp>
#include <bID/uuid/uuid.hpp>
#include <bID/uuid/uuid_io.hpp>

#include <iostream>

namespace trBase
{
    /**
     * @class   implId
     *
     * @brief   An implementation class for GUID.
     */
    class implId
    {
    public:

        /**
         * @fn  implId::implId(bool createNewId)
         *
         * @brief   Constructor.
         *
         * @param   createNewId if true, generates a new id.  If not, it sets the id to empty.
         */
        implId::implId(bool createNewId)
        {
            if (createNewId)
            {
                //Create a random GUID
                mGUID = bID::uuids::random_generator()();

            }
            else
            {
                //Create a NULL GUID
                mGUID = bID::uuids::nil_uuid();
            }
        }

        /**
         * @fn  implId::implId(const implId& toCopy)
         *
         * @brief   Makes a copy of the passed in Unique ID GUID.
         *
         * @param   toCopy  to copy.
         */
        implId::implId(const implId& toCopy)
        {
            mGUID = toCopy.mGUID;
        }

        /**
         * @fn  implId::implId(const std::string& toCopy)
         *
         * @brief   Constructor.
         *
         * @param   toCopy  to copy.
         */
        implId::implId(const std::string& toCopy)
        {
            mGUID = bID::uuids::string_generator()(toCopy);
        }

        /**
         * @fn  const std::string implId::ToString() const
         *
         * @brief   Convert this object into a string representation.
         *
         * @return  A const std::string that represents this object.
         */
        const std::string implId::ToString() const
        {
            return bID::uuids::to_string(mGUID);
        }

        /**
         * @fn  void implId::FromString(std::string& idString)
         *
         * @brief   Initializes this object from the given string.
         *
         * @param [in,out]  idString    The identifier string.
         */
        void implId::FromString(std::string& idString)
        {
            mGUID = bID::uuids::string_generator()(idString);
        }

        /**
         * @fn  bool implId::IsNull() const
         *
         * @brief   Returns true if the GUID is equal to 00000000-0000-0000-0000-000000000000.
         *
         * @return  True if null, false if not.
         */
        bool implId::IsNull() const
        {
            return mGUID.is_nil();
        }

        /**
         * @fn  implId& implId::operator=(const implId& id)
         *
         * @brief   Assignment operator.
         *
         * @param   id  The identifier.
         *
         * @return  A shallow copy of this object.
         */
        implId& implId::operator=(const implId& id)
        {
            if (this == &id)
            {
                return *this;
            }

            mGUID = id.mGUID;
            return *this;
        }

        /**
         * @fn  implId& implId::operator=(const implId* id)
         *
         * @brief   Assignment operator.
         *
         * @param   id  The identifier.
         *
         * @return  A shallow copy of this object.
         */
        implId& implId::operator=(const implId* id)
        {
            if (this == id)
            {
                return *this;
            }

            mGUID = id->mGUID;
            return *this;
        }

        /**
         * @fn  implId& implId::operator=(const std::string& id)
         *
         * @brief   Assignment operator.
         *
         * @param   id  The identifier.
         *
         * @return  A shallow copy of this object.
         */
        implId& implId::operator=(const std::string& id)
        {
            mGUID = bID::uuids::string_generator()(id);
            return *this;
        }

        /**
         * @fn  bool implId::operator==(const implId & id) const
         *
         * @brief   Equality operator.
         *
         * @param   id  The identifier.
         *
         * @return  True if the parameters are considered equivalent.
         */
        bool implId::operator==(const implId & id) const
        {
            return mGUID == id.mGUID;
        }

        /**
         * @fn  bool implId::operator!=(const implId & id) const
         *
         * @brief   Inequality operator.
         *
         * @param   id  The identifier.
         *
         * @return  True if the parameters are not considered equivalent.
         */
        bool implId::operator!=(const implId & id) const
        {
            return mGUID != id.mGUID;
        }

        /**
         * @fn  bool implId::operator<(const implId & id) const
         *
         * @brief   Less-than comparison operator.
         *
         * @param   id  The identifier.
         *
         * @return  True if the first parameter is less than the second.
         */
        bool implId::operator<(const implId & id) const
        {
            return mGUID < id.mGUID;
        }

        /**
         * @fn  bool implId::operator>(const implId & id) const
         *
         * @brief   Greater-than comparison operator.
         *
         * @param   id  The identifier.
         *
         * @return  True if the first parameter is greater than to the second.
         */
        bool implId::operator>(const implId & id) const
        {
            return mGUID > id.mGUID;
        }

    private:
        bID::uuids::uuid mGUID;
    };

    ////////////////////////////////////////////////
    const trUtil::RefStr UniqueId::CLASS_TYPE = trUtil::RefStr("trBase::UniqueId");

    ////////////////////////////////////////////////
    UniqueId::UniqueId(bool createNewId)
    {
        if (createNewId)
        {
            //Create a random GUID
            mGUID = bID::uuids::random_generator()();

        }
        else
        {
            //Create a NULL GUID
            mGUID = bID::uuids::nil_uuid();
        }
    }

    ////////////////////////////////////////////////
    UniqueId::UniqueId(const UniqueId& toCopy)
    {
        mGUID = toCopy.mGUID;
    }

    ////////////////////////////////////////////////
    UniqueId::UniqueId(const std::string& toCopy)
    {
        mGUID = bID::uuids::string_generator()(toCopy);
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& UniqueId::GetType() const
    {
        return CLASS_TYPE;
    }

    ////////////////////////////////////////////////
    const std::string UniqueId::ToString() const
    {
        return bID::uuids::to_string(mGUID);
    }

    ////////////////////////////////////////////////
    void UniqueId::FromString(std::string& idString)
    {
        mGUID = bID::uuids::string_generator()(idString);
    }

    ////////////////////////////////////////////////
    bool UniqueId::IsNull() const
    {
        return mGUID.is_nil();
    }

    ////////////////////////////////////////////////
    UniqueId& UniqueId::operator=(const UniqueId& id)
    {
        if (this == &id)
        {
            return *this;
        }

        mGUID = id.mGUID;
        return *this;
    }

    ////////////////////////////////////////////////
    UniqueId& UniqueId::operator=(const UniqueId* id)
    {
        if (this == id)
        {
            return *this;
        }

        mGUID = id->mGUID;
        return *this;
    }

    ////////////////////////////////////////////////
    UniqueId& UniqueId::operator=(const std::string& id)
    {
        mGUID = bID::uuids::string_generator()(id);
        return *this;
    }

    ////////////////////////////////////////////////
    bool UniqueId::operator==(const UniqueId & id) const
    {
        return mGUID == id.mGUID;
    }

    ////////////////////////////////////////////////
    bool UniqueId::operator!=(const UniqueId & id) const
    {
        return mGUID != id.mGUID;        
    }

    ////////////////////////////////////////////////
    bool UniqueId::operator<(const UniqueId & id) const
    {
        return mGUID < id.mGUID;
    }

    ////////////////////////////////////////////////
    bool UniqueId::operator>(const UniqueId & id) const
    {
        return mGUID > id.mGUID;
    }

    ////////////////////////////////////////////////
    std::ostream& operator << (std::ostream& o, const UniqueId& id)
    {
        o << id.ToString();
        return o;
    }

    ////////////////////////////////////////////////
    std::istream& operator >> (std::istream& i, UniqueId& id)
    {
        std::string value;
        i >> value;
        id = value;
        return i;
    }    
}