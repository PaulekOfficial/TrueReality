/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2018 Acid Rain Studios LLC
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
* Author: Maxim Serebrennik
*/

#pragma once

#include <trManager/Export.h>

namespace trManager
{
    /**
     * @struct  TimingStructure
     *
     * @brief   A timing structure for all sim loop variables. 
     */
    struct TR_MANAGER_EXPORT TimingStructure
    {
        int frameNumber = 0;       //Holds the Frame number

        double deltaSimTime = 0.;  //Scaled Time between frames in seconds. 
        double deltaRealTime = 0.; //Non-scaled Time between frames.
        double simTime = 0.;       //Scaled time of the current simulation run.
        double realTime = 0.;      //Non-scaled time of the current simulation run.
        double timeScale = 1.;     //Time scaler
    };
}


