
[Setup]
AppName=6�l�̗����l�ƐǊ�̏���2
AppVerName=6�l�̗����l�ƐǊ�̏���2_1.1
VersionInfoVersion=1.1.0.0
AppCopyright=�Ō�̔ӎ`
AppPublisher=�Ō�̔ӎ`
AppPublisherURL=http://the-last-dinner.club
AppVersion=1.1
UsePreviousAppDir=no
DefaultDirName={pf}\6chefs2_1.1
DefaultGroupName=6�l�̗����l�ƐǊ�̏���2
UninstallDisplayIcon={app}\6chefs2_1.1.exe
Compression=lzma
SolidCompression=yes

;�E�B�U�[�h�y�[�W�ɕ\�������O���t�B�b�N�i*.bmp: 164 x 314�j
WizardImageFile=C:\Users\LastDinner\Desktop\6chefs2_1.1\installer.bmp
;�E�B�U�[�h�y�[�W�ɕ\�������O���t�B�b�N���g�傳��Ȃ�
WizardImageStretch=no
;���̌��ԐF
WizardImageBackColor=$ffffff

[Files]
;src��.exe, game.rc, *.dll������Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\src\*"; DestDir: "{app}"
;Resouces
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\BGM\*"; DestDir: "{app}\BGM"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\character\*"; DestDir: "{app}\character"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\csv\*"; DestDir: "{app}\csv"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\character\plist\*"; DestDir: "{app}\character\plist"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\event\*"; DestDir: "{app}\event"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\img\disp\*"; DestDir: "{app}\img\disp"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\img\character\*"; DestDir: "{app}\img\character"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\img\*"; DestDir: "{app}\img"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\map\*"; DestDir: "{app}\map"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\save\*"; DestDir: "{app}\save"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\se\*"; DestDir: "{app}\se"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\config\*"; DestDir: "{app}\config"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\effect\*"; DestDir: "{app}\effect"Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\fonts\*"; DestDir: "{app}\fonts"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\shaders\*"; DestDir: "{app}\shaders"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\voice\*"; DestDir: "{app}\voice"
Source: "C:\Users\LastDinner\Desktop\6chefs2_1.1\Resources\video\*"; DestDir: "{app}\video"
;Source: "C:\Users\Ishiwata Lab\Desktop\6chefs1.1\shaders\*"; DestDir: "{app}\shaders";Source: "C:\Users\Ishiwata Lab\Desktop\6chefs1.1\ReadMeWin.txt"; DestDir: "{app}"; Flags: isreadme

[Dirs]
Name: {app}\save;Permissions: everyone-modify

[Tasks]
Name: desktopicon; Description: "�f�X�N�g�b�v�ɃV���[�g�J�b�g���쐬����"

[Icons]
Name: "{group}\6�l�̗����l�ƐǊ�̏���2"; Filename: "{app}\6chefs2_1.1.exe"
Name: "{commondesktop}\6�l�̗����l�ƐǊ�̏���2"; Filename: "{app}\6chefs2_1.1.exe"; WorkingDir: "{app}"; Tasks: desktopicon

[Languages]
Name:"jp";MessagesFile:"C:\Program Files (x86)\Inno Setup 5\Languages\Japanese.isl";

[Run]
Filename: "{app}\6chefs2_1.1.exe"; Description: "�C���X�g�[���I�����ɃQ�[�����N������"; Flags: postinstall
