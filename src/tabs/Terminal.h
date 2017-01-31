/*
 * Terminal.h
 *
 *  Created on: Aug 28, 2012
 *      Author: mgooch
 */

#ifndef TERMINAL_H_
#define TERMINAL_H_
#define UNICODE
#define _UNICODE
#include "types.h"
#include "ParentApp.h"
#include <wx/timer.h>
#include <wx/timer.h>
	struct Terminal {
	public:
		Terminal(ParentApp* p,long ID);
		virtual ~Terminal();
		wxTextCtrl* terminal,*prompt;
		wxProcess* running;
		wxTimer* timer;
		long runningID;
		int Launch();
		void DataEntered();
		void UpdateTerminal();
	};

#endif /* TERMINAL_H_ */
