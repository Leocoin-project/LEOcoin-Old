Name LEOcoin

RequestExecutionLevel highest
SetCompressor /SOLID lzma

# General Symbol Definitions
!define REGKEY "SOFTWARE\$(^Name)"
!define VERSION 1.1.0
!define COMPANY "LEO Ltd"
!define URL "http://www.leocoin.org"
!define PROJECTURL "http://www.leocoin.org"
!define ProductName "LEOcoin Wallet"

# MUI Symbol Definitions
!define MUI_ICON "..\share\pixmaps\LEOcoin.ico"
!define MUI_WELCOMEFINISHPAGE_BITMAP "..\share\pixmaps\nsis-wizard.bmp"
!define MUI_HEADERIMAGE
!define MUI_HEADERIMAGE_RIGHT
!define MUI_HEADERIMAGE_BITMAP "..\share\pixmaps\nsis-header.bmp"
!define MUI_FINISHPAGE_NOAUTOCLOSE
!define MUI_STARTMENUPAGE_REGISTRY_ROOT HKLM
!define MUI_STARTMENUPAGE_REGISTRY_KEY ${REGKEY}
!define MUI_STARTMENUPAGE_REGISTRY_VALUENAME StartMenuGroup
!define MUI_STARTMENUPAGE_DEFAULTFOLDER LEOcoin
!define MUI_FINISHPAGE_RUN $INSTDIR\LEOcoin-qt.exe
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"
!define MUI_UNWELCOMEFINISHPAGE_BITMAP "..\share\pixmaps\nsis-wizard.bmp"
!define MUI_UNFINISHPAGE_NOAUTOCLOSE


# Included files
!include Sections.nsh
!include MUI2.nsh

# Variables
Var StartMenuGroup

# Installer pages
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_STARTMENU Application $StartMenuGroup
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

# Installer languages
!insertmacro MUI_LANGUAGE English

# Installer attributes
OutFile LEOcoin-1.1.0-win32-setup.exe
InstallDir $PROGRAMFILES\LEO\LEOcoin
CRCCheck on
XPStyle on
BrandingText " "
ShowInstDetails show
VIProductVersion 1.1.0.0
VIAddVersionKey ProductName "LEOcoin Wallet"
VIAddVersionKey ProductVersion "${VERSION}"
VIAddVersionKey CompanyName "${COMPANY}"
VIAddVersionKey CompanyWebsite "${URL}"
VIAddVersionKey FileVersion "${VERSION}"
VIAddVersionKey FileDescription ""
VIAddVersionKey LegalCopyright ""
InstallDirRegKey HKCU "${REGKEY}" Path
ShowUninstDetails show

# Installer sections
Section -Main SEC0000
    SetOutPath $INSTDIR
    SetOverwrite on
    File ..\release\LEOcoin-qt.exe
    File /oname=license.txt ..\COPYING
#    File /oname=readme.txt ..\doc\README_windows.txt
#    SetOutPath $INSTDIR\daemon
#    File ..\src\LEOcoind.exe
    SetOutPath $INSTDIR\src
    File /r /x *.exe /x *.o ..\src\*.*
    SetOutPath $INSTDIR
    WriteRegStr HKCU "${REGKEY}\Components" Main 1
  
    # Remove old wxwidgets-based-lwocoin executable and locales:
    #Delete /REBOOTOK $INSTDIR\LEOcoin-qt.exe
    #RMDir /r /REBOOTOK $INSTDIR\locale
SectionEnd

Section -post SEC0001
    WriteRegStr HKCU "${REGKEY}" Path $INSTDIR
    SetOutPath $INSTDIR
    WriteUninstaller $INSTDIR\uninstall.exe
    !insertmacro MUI_STARTMENU_WRITE_BEGIN Application
	CreateDirectory $SMPROGRAMS\$StartMenuGroup
    CreateShortcut "$SMPROGRAMS\$StartMenuGroup\${ProductName}.lnk" $INSTDIR\LEOcoin-qt.exe
	CreateShortcut "$SMPROGRAMS\$StartMenuGroup\Uninstall ${ProductName}.lnk" $INSTDIR\uninstall.exe
	
	;remove old shortcuts
	Delete "$DESKTOP\LEOcoin.lnk"
	Delete "$SMPROGRAMS\$StartMenuGroup\Uninstall LEOcoin.lnk"
	
	;remove old wallet
	

	;create desktop shortcut
    CreateShortCut "$DESKTOP\${ProductName}.lnk" "$INSTDIR\LEOcoin-qt.exe" ""

    !insertmacro MUI_STARTMENU_WRITE_END
    WriteRegStr HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayName "$(^Name)"
    WriteRegStr HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayVersion "${VERSION}"
    WriteRegStr HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" Publisher "${COMPANY}"
    WriteRegStr HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" URLInfoAbout "${PROJECTURL}"
    WriteRegStr HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" DisplayIcon $INSTDIR\uninstall.exe
    WriteRegStr HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" UninstallString $INSTDIR\uninstall.exe
    WriteRegDWORD HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" NoModify 1
    WriteRegDWORD HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)" NoRepair 1

    # bitcoin: URI handling disabled for 0.6.0
        WriteRegStr HKCR "LEOcoin" "URL Protocol" ""
        WriteRegStr HKCR "LEOcoin" "" "URL:LEOcoin"
        WriteRegStr HKCR "LEOcoin\DefaultIcon" "" $INSTDIR\LEOcoin-qt.exe
        WriteRegStr HKCR "LEOcoin\shell\open\command" "" '"$INSTDIR\LEOcoin-qt.exe" "$$1"'
SectionEnd

# Macro for selecting uninstaller sections
!macro SELECT_UNSECTION SECTION_NAME UNSECTION_ID
    Push $R0
    ReadRegStr $R0 HKCU "${REGKEY}\Components" "${SECTION_NAME}"
    StrCmp $R0 1 0 next${UNSECTION_ID}
    !insertmacro SelectSection "${UNSECTION_ID}"
    GoTo done${UNSECTION_ID}
next${UNSECTION_ID}:
    !insertmacro UnselectSection "${UNSECTION_ID}"
done${UNSECTION_ID}:
    Pop $R0
!macroend

# Uninstaller sections
Section /o -un.Main UNSEC0000
    Delete /REBOOTOK $INSTDIR\LEOcoin-qt.exe
    Delete /REBOOTOK $INSTDIR\license.txt
    Delete /REBOOTOK $INSTDIR\readme.txt
	Delete /REBOOTOK "$DESKTOP\${ProductName}.lnk"
    RMDir /r /REBOOTOK $INSTDIR\daemon
    RMDir /r /REBOOTOK $INSTDIR\src
    DeleteRegValue HKCU "${REGKEY}\Components" Main
SectionEnd

Section -un.post UNSEC0001
    DeleteRegKey HKCU "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\$(^Name)"
    Delete /REBOOTOK "$SMPROGRAMS\$StartMenuGroup\Uninstall LEOcoin.lnk"
    #Delete /REBOOTOK "$SMPROGRAMS\$StartMenuGroup\LEOcoin.lnk"
    #Delete /REBOOTOK "$SMSTARTUP\LEOcoin.lnk"
    Delete /REBOOTOK $INSTDIR\uninstall.exe
    Delete /REBOOTOK $INSTDIR\debug.log
    Delete /REBOOTOK $INSTDIR\db.log
    DeleteRegValue HKCU "${REGKEY}" StartMenuGroup
    DeleteRegValue HKCU "${REGKEY}" Path
    DeleteRegKey /IfEmpty HKCU "${REGKEY}\Components"
    DeleteRegKey /IfEmpty HKCU "${REGKEY}"
    DeleteRegKey HKCR "LEOcoin"
    RmDir /REBOOTOK $SMPROGRAMS\$StartMenuGroup
    RmDir /REBOOTOK $INSTDIR
    Push $R0
    StrCpy $R0 $StartMenuGroup 1
    StrCmp $R0 ">" no_smgroup
no_smgroup:
    Pop $R0
SectionEnd

# Installer functions
Function .onInit
    InitPluginsDir
FunctionEnd

# Uninstaller functions
Function un.onInit
    ReadRegStr $INSTDIR HKCU "${REGKEY}" Path
    !insertmacro MUI_STARTMENU_GETFOLDER Application $StartMenuGroup
    !insertmacro SELECT_UNSECTION Main ${UNSEC0000}
FunctionEnd
