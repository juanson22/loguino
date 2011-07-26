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
 * $Rev$:   
 * $Author$: 
 * $Date$:  

*/


#include <config.h>
#include "WProgram.h"
#include "Poller.h"

void Poller::begin(){
	#ifdef ENABLE_MS_POLLER
		MSPoller::begin();
	#endif
	#ifdef ENABLE_LIS331_POLLER
		LIS331Poller::begin();
	#endif
	#ifdef ENABLE_DUMMY_POLLER
		DummyPoller::begin();
	#endif
	#ifdef ENABLE_GPS_POLLER
		GPSPoller::begin();
	#endif
}

void Poller::poll()
{
	#ifdef ENABLE_MS_POLLER
		MSPoller::poll();
	#endif
	#ifdef ENABLE_LIS331_POLLER
		LIS331Poller::poll();
	#endif
	#ifdef ENABLE_DUMMY_POLLER
		DummyPoller::poll();
	#endif
	#ifdef ENABLE_GPS_POLLER
		GPSPoller::poll();
	#endif
}
