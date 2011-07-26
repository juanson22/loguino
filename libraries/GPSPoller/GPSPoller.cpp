/* Copyright 2011 David Irvine
 * 
 * This file is part of Loguino
 *
 * Loguino is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Loguino is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Loguino.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * $Rev$
 * $Author$
 * $Date$

*/

#include <config.h>
#include "WProgram.h"
#include "GPSPoller.h"

#ifdef ENABLE_GPS_POLLER
NMEA GPSPoller::n;

bool GPSPoller::begin(){
	GPS_SERIAL_DEV.begin(GPS_SERIAL_DEV_SPEED);
}

bool GPSPoller::poll(){
	while(GPS_SERIAL_DEV.available()){
		if (n.addChar(GPS_SERIAL_DEV.read())){
			if (n.validFix()){
				Message m;
	
				m.units="Degrees";
				m.nameSpace="GPS.Course";
				m.value=n.getCourse();
				Logger::log(m);
	
				m.units="Knots";
				m.nameSpace="GPS.Speed";
				m.value=n.getSpeed();
				Logger::log(m);
	
				m.units="Latitude";
				m.nameSpace="GPS.Latitude";
				m.value=n.getLatitude();
				Logger::log(m);
	
				m.units="Longitude";
				m.nameSpace="GPS.Longitude";
				m.value=n.getLongitude();
				Logger::log(m);

				m.units="Date";
				m.nameSpace="GPS.Date";
				m.value=n.getDate();
				Logger::log(m);
	
				m.units="Time";
				m.nameSpace="GPS.Time";
				m.value=n.getTime();
				Logger::log(m);
			}
		}
	}
}


#endif

