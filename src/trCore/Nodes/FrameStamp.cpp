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

#include <trCore/Nodes/FrameStamp.h>

#include <trBase/Base.h>

#include <osg/FrameStamp>

namespace trCore::Nodes
{
    const trUtil::RefStr FrameStamp::CLASS_TYPE = trUtil::RefStr("trCore::Nodes::FrameStamp");

    //////////////////////////////////////////////////////////////////////////
    FrameStamp::FrameStamp(const std::string name)
    {
        mFrameStamp = new osg::FrameStamp();
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& FrameStamp::GetType() const
    {
        return CLASS_TYPE;
    }

    //////////////////////////////////////////////////////////////////////////
    void FrameStamp::SetName(const std::string& name)
    {
        BaseClass::SetName(name);
    }

    //////////////////////////////////////////////////////////////////////////
    osg::FrameStamp* FrameStamp::AsOSGClass()
    {
        return mFrameStamp.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    const osg::FrameStamp* FrameStamp::AsOSGClass() const
    {
        return mFrameStamp.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    FrameStamp& FrameStamp::operator=(const FrameStamp & fs)
    {
        mFrameStamp = fs.mFrameStamp;
        SetName(fs.GetName());
        return *this;
    }

    //////////////////////////////////////////////////////////////////////////
    FrameStamp::~FrameStamp()
    {
    }
}

