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
#ifndef DUMMYPOLLER_H
#define DUMMYPOLLER_H

#include <Arduino.h>
#include <config.h>

#ifdef ENABLE_DUMMY_POLLER
#include <message.h>
#include <logger.h>


class DummyPoller{
	public:
		static void poll();
		static void begin();
	private:
		static int called;
};

#endif








#endif
