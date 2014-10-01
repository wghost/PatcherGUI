#ifndef VIEWLOG_H
#define VIEWLOG_H

//(*Headers(ViewLog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include <wx/arrstr.h>

class ViewLog: public wxDialog
{
	public:

		ViewLog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ViewLog();

		void SetParams(wxString GamePath, wxArrayString ModList);
		wxArrayString GetModNames(wxArrayString ModList);

		int GetSelection() { return SelectionIdx; }
		bool IsInstaller() { return bInstaller; }
		bool IsBatch() { return bBatch; }

		//(*Declarations(ViewLog)
		wxButton* Button4;
		wxStaticText* StaticText2;
		wxButton* Button1;
		wxPanel* Panel1;
		wxStaticText* StaticText1;
		wxButton* Button2;
		wxButton* Button5;
		wxButton* Button3;
		wxTextCtrl* TextCtrl1;
		wxListBox* ListBox1;
		//*)

	protected:

	    int SelectionIdx;
	    bool bInstaller;
	    bool bBatch;

		//(*Identifiers(ViewLog)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_LISTBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(ViewLog)
		void OnSelectItem(wxCommandEvent& event);
		void OnDoubleClickItem(wxCommandEvent& event);
		void OnLoadInstaller(wxCommandEvent& event);
		void OnLoadUninstaller(wxCommandEvent& event);
		void OnCloseLog(wxCommandEvent& event);
		void OnMakeBatchInstaller(wxCommandEvent& event);
		void OnMakeBatchUninstaller(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
