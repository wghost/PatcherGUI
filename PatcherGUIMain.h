/***************************************************************
 * Name:      PatcherGUIMain.h
 * Purpose:   Defines Application Frame
 * Author:    Wasteland Ghost (wghost81@gmail.com)
 * Created:   2013-12-09
 * Copyright: Wasteland Ghost ()
 * License:
 **************************************************************/

#ifndef PATCHERGUIMAIN_H
#define PATCHERGUIMAIN_H

//(*Headers(PatcherGUIFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
//*)
#include <wx/arrstr.h>

class PatcherGUIFrame: public wxFrame
{
    public:

        PatcherGUIFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~PatcherGUIFrame();

    private:

        bool bSelectPath;
        bool bSelectFile;
        wxArrayString PatchUPKoutput;
        wxArrayString PatchUPKerrors;
        wxArrayString DecompressOutput;
        wxArrayString DecompressErrors;
        wxString BackupPathString;
        wxString PatchUPKprogram;
        wxString DecompressProgram;
        wxArrayString FilesToBackup;
        wxArrayString FilesToRemove;
        wxArrayString FilesToDecompress;
        wxString curBackupPathString;
        wxArrayString InstList, UninstList;
        wxString InstLogName;
        wxString ProgLog;

        bool RestoreFromBackup();
        bool MakeBackups();
        bool RemoveSizeFiles();
        bool DecompressUPK();
        bool LoadCFG();
        bool SaveCFG();

        bool NeedDecompression(wxString filename);

        void OpenModFile(wxString FilePath);
        void SaveModFileAs();
        void LoadLogs();
        void SaveLogs();
        unsigned FindUninstallFileIdx(wxString UninstallFile);
        unsigned FindInstallFileIdx(wxString InstallFile);
        wxString GetLatestUninstallFile(wxString InstallFile);
        bool InstallMod(wxString& filename, wxString& str);

        //(*Handlers(PatcherGUIFrame)
        void OnSaveModFile(wxCommandEvent& event);
        void OnSaveModFileAs(wxCommandEvent& event);
        void OnInstallMod(wxCommandEvent& event);
        void OnSelectDirectory(wxCommandEvent& event);
        void OnSelectModFile(wxCommandEvent& event);
        void OnChangeSettings(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnShowLog(wxCommandEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnDisableHashCheck(wxCommandEvent& event);
        void OnEnableINI(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnShowReadme(wxCommandEvent& event);
        void OnOpenConfigFolder(wxCommandEvent& event);
        void OnShowDebugLog(wxCommandEvent& event);
        void DisableSpecificPackageHashCheck(wxCommandEvent& event);
        void OnDisablePhoneHome(wxCommandEvent& event);
        void OnPatchExecutable(wxCommandEvent& event);
        //*)

        //(*Identifiers(PatcherGUIFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON8;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON9;
        static const long ID_RICHTEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON7;
        static const long ID_BUTTON2;
        static const long ID_BUTTON4;
        static const long ID_PANEL1;
        static const long ID_MENUITEM9;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM6;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM13;
        static const long ID_MENUITEM10;
        static const long ID_MENUITEM11;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM14;
        static const long ID_MENUITEM12;
        static const long ID_MENUITEM7;
        static const long ID_MENUITEM8;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(PatcherGUIFrame)
        wxMenuItem* MenuItem2;
        wxMenuItem* MenuItem1;
        wxPanel* Panel1;
        wxMenu* Menu5;
        wxMenuItem* Menu1;
        wxStatusBar* StatusBar1;
        wxButton* Button4;
        wxButton* Button1;
        wxMenu* Menu6;
        wxButton* Button2;
        wxButton* Button8;
        wxMenuItem* MenuItem3;
        wxRichTextCtrl* RichTextCtrl1;
        wxMenuItem* Menu3;
        wxMenuItem* MenuItem9;
        wxMenu* Menu7;
        wxMenu* Menu4;
        wxMenuItem* MenuItem11;
        wxButton* Button9;
        wxMenuItem* MenuItem5;
        wxTextCtrl* TextCtrl1;
        wxMenuBar* MenuBar1;
        wxMenuItem* MenuItem10;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem6;
        wxMenuItem* Menu2;
        wxButton* Button7;
        wxTextCtrl* TextCtrl2;
        wxMenuItem* MenuItem8;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PATCHERGUIMAIN_H
