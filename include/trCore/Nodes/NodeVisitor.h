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
#pragma once

#include <trCore/Export.h>

#include <trBase/Base.h>
#include <trBase/SmrtPtr.h>
#include <trUtil/RefStr.h>

namespace osg
{
    class NodeVisitor;
}

namespace trCore::Nodes
{
    /**
     * @class   NodeVisitor
     *          
     * @author Maxim Serebrennik
     *
     * @brief   A node visitor.
     */
    class TR_CORE_EXPORT NodeVisitor : public trBase::Base
    {
    public:

        enum TraversalMode
        {
            TRAVERSE_NONE = 0,
            TRAVERSE_PARENTS = 1,
            TRAVERSE_ALL_CHILDREN = 2,
            TRAVERSE_ACTIVE_CHILDREN = 3
        };

        enum VisitorType
        {
            NODE_VISITOR = 0,
            UPDATE_VISITOR = 1,
            EVENT_VISITOR = 2,
            COLLECT_OCCLUDER_VISITOR = 3,
            CULL_VISITOR = 4,
            INTERSECTION_VISITOR = 5
        };

        using BaseClass = trBase::Base;                 /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;         /// Holds the class type name for efficient comparisons

        /**
         * @fn  NodeVisitor::NodeVisitor(TraversalMode tm = TRAVERSE_NONE, const std::string name = CLASS_TYPE);
         *
         * @brief   Constructor.
         *
         * @param   tm      (Optional) The time.
         * @param   name    (Optional) The name.
         */
        NodeVisitor(TraversalMode tm = TRAVERSE_NONE, const std::string name = CLASS_TYPE);

        /**
         * @fn  NodeVisitor::NodeVisitor(VisitorType type, TraversalMode tm = TRAVERSE_NONE, const std::string name = CLASS_TYPE);
         *
         * @brief   Constructor.
         *
         * @param   type    The type.
         * @param   tm      (Optional) The time.
         * @param   name    (Optional) The name.
         */
        NodeVisitor(VisitorType type, TraversalMode tm = TRAVERSE_NONE, const std::string name = CLASS_TYPE);

        /**
         * @fn  virtual const std::string& NodeVisitor::GetType() const override;
         *
         * @brief   Returns the class type.
         *
         * @return  The type.
         */
        virtual const std::string& GetType() const override;

        /**
         * @fn  virtual void NodeVisitor::SetName(const std::string& name);
         *
         * @brief   Sets this instances name.
         *
         * @param   name    The name.
         */
        virtual void SetName(const std::string& name);

        /**
         * @fn  virtual osg::NodeVisitor* NodeVisitor::AsOSGVisitor();
         *
         * @brief   Returns a pointer to the internal OSG Node.
         *
         * @return  Null if it fails, else a pointer to an osg::Node.
         */
        virtual osg::NodeVisitor* AsOSGVisitor();

        /**
         * @fn  virtual const osg::NodeVisitor* NodeVisitor::AsOSGVisitor() const;
         *
         * @brief   Returns a constant pointer to the internal OSG Node.
         *
         * @return  Null if it fails, else a pointer to a const osg::Node.
         */
        virtual const osg::NodeVisitor* AsOSGVisitor() const;

    protected:

        trBase::SmrtPtr<osg::NodeVisitor> mNodeVisitor;

        /**
         * @fn  NodeVisitor::~NodeVisitor();
         *
         * @brief   Destructor.
         */
        ~NodeVisitor();
    };
}

