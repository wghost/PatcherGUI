#ifndef SHOWDEBUGLOGDIALOG_H
#define SHOWDEBUGLOGDIALOG_H

//(*Headers(ShowDebugLogDialog)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
//*)

class ShowDebugLogDialog: public wxDialog
{
	public:

		ShowDebugLogDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ShowDebugLogDialog();

		//(*Declarations(ShowDebugLogDialog)
		wxPanel* Panel1;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(ShowDebugLogDialog)
		static const long ID_TEXTCTRL1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(ShowDebugLogDialog)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
