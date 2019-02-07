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
#include <trCore/Nodes/NodeVisitor.h>

#include <osg/NodeVisitor>

namespace trCore::Nodes
{
    /**
     * @fn  osg::NodeVisitor::VisitorType ToVisitorType(VisitorType type);
     *
     * @brief   Converts a TR visitor type to an osg visitor type.
     *
     * @param   type    The visitor type.
     *
     * @return  Type as an osg::NodeVisitor::VisitorType.
     */
    osg::NodeVisitor::VisitorType ToVisitorType(NodeVisitor::VisitorType type)
    {

        enum VisitorType
        {
            NODE_VISITOR = 0,
            UPDATE_VISITOR = 1,
            EVENT_VISITOR = 2,
            COLLECT_OCCLUDER_VISITOR = 3,
            CULL_VISITOR = 4,
            INTERSECTION_VISITOR = 5
        };

        switch (type)
        {
        case VisitorType::NODE_VISITOR:
            return osg::NodeVisitor::VisitorType::NODE_VISITOR;
            break;
        case VisitorType::UPDATE_VISITOR:
            return osg::NodeVisitor::VisitorType::UPDATE_VISITOR;
            break;
        case VisitorType::EVENT_VISITOR:
            return osg::NodeVisitor::VisitorType::EVENT_VISITOR;
            break;
        case VisitorType::COLLECT_OCCLUDER_VISITOR:
            return osg::NodeVisitor::VisitorType::COLLECT_OCCLUDER_VISITOR;
            break;
        case VisitorType::CULL_VISITOR:
            return osg::NodeVisitor::VisitorType::CULL_VISITOR;
            break;
        case VisitorType::INTERSECTION_VISITOR:
            return osg::NodeVisitor::VisitorType::INTERSECTION_VISITOR;
            break;
        default:
            return osg::NodeVisitor::VisitorType::NODE_VISITOR;
            break;
        }
        return osg::NodeVisitor::VisitorType();
    }

    const trUtil::RefStr NodeVisitor::CLASS_TYPE = trUtil::RefStr("trCore::Nodes::NodeVisitor");

    //////////////////////////////////////////////////////////////////////////
    NodeVisitor::NodeVisitor(TraversalMode tm, const std::string name)
        : NodeVisitor(NODE_VISITOR, tm, name)
    {
    }

    //////////////////////////////////////////////////////////////////////////
    NodeVisitor::NodeVisitor(VisitorType type, TraversalMode tm, const std::string name)
    {
        mNodeVisitor = new osg::NodeVisitor(ToVisitorType(type), tm);
        mNodeVisitor->setName(name);
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& NodeVisitor::GetType() const
    {
        return CLASS_TYPE;
    }

    //////////////////////////////////////////////////////////////////////////
    void NodeVisitor::SetName(const std::string& name)
    {
        BaseClass::SetName(name);
        mNodeVisitor->setName(name);
    }

    //////////////////////////////////////////////////////////////////////////
    osg::NodeVisitor* NodeVisitor::AsOSGVisitor()
    {
        return mNodeVisitor.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    const osg::NodeVisitor* NodeVisitor::AsOSGVisitor() const
    {
        return mNodeVisitor.Get();
    }

    //////////////////////////////////////////////////////////////////////////
    void NodeVisitor::Reset()
    {
        mNodeVisitor->reset();
    }

    //////////////////////////////////////////////////////////////////////////
    NodeVisitor::~NodeVisitor()
    {
    }
}
