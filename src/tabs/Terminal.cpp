/*
 * Terminal.cpp
 *
 *  Created on: Aug 28, 2012
 *      Author: mgooch
 */

#include "Terminal.h"


Terminal::Terminal(ParentApp* p,long ID) {
	// TODO Auto-generated constructor stub
	timer= new wxTimer(p->gui,ID);
	runningID=0;
	running=new wxProcess(p->gui,ID);
	running->Redirect();
	if(!ID)
	{
		this->terminal=p->gui->server_terminal_term;
		this->prompt=p->gui->server_terminal_prompt;
	} else {
		this->terminal=p->gui->client_terminal_term;
		this->prompt=p->gui->client_terminal_prompt;
	}
}

Terminal::~Terminal() {
	// TODO Auto-generated destructor stub
	delete running;
	delete timer;
}

//Terminal Functions

void Terminal::DataEntered()
{
    if(runningID)
    {
    	wxOutputStream* process_in=this->running->GetOutputStream();
        wxChar c;
        wxString entry=this->prompt->GetLineText(0);
        this->prompt->Clear();
        entry+=wxT("\n");
        terminal->AppendText(wxT(">"));
        terminal->AppendText(entry);
        for(size_t i=0;i<entry.Len(); ++i)
        {
            c=entry[i];
            process_in->PutC(c);
        }
    }
}

void Terminal::UpdateTerminal()
{
    if(runningID)
    {
        wxChar c;
        wxString s;
        wxInputStream *process_err,*process_out;
        process_out=this->running->GetInputStream();
        process_err=this->running->GetErrorStream();
        while(this->running->IsErrorAvailable())
        {
            c=process_err->GetC();
            s+=c;
        }
        this->terminal->AppendText(s);
        s.Clear();
        while(this->running->IsInputAvailable())
        {
            c=process_out->GetC();
            s+=c;
        }
        this->terminal->AppendText(s);
    }
}
