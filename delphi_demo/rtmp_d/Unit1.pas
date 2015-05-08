unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls,test, ComCtrls;
type
  TForm1 = class(TForm)
    pnl_video: TPanel;
    btn_start: TButton;
    btn_stop: TButton;
    cbb_audiooutput: TComboBox;
    edt_address: TEdit;
    edt_app: TEdit;
    edt_stream: TEdit;
    lv_msg: TListView;
    procedure btn_startClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure btn_stopClick(Sender: TObject);
  private
    { Private declarations }
  Handle:THandle;
  pRtmp:Pointer;
  CreateRtmpPlayer:TCreateRtmpPlayer;
  CallInJson:TCallInJson;
  pRes:PChar;
  CallBackFun:TcallBackFun;
  SetVdDisplayWnd:TSetVdDisplayWnd;
  public
    { Public declarations }
  end;
//解析jeson的函数的声明
function ParseJson():Boolean;

var
  Form1: TForm1;

implementation
uses
  uLkJSON;
{$R *.dfm}

//解析jeson函数的实现
function ParseJson():Boolean;
begin
  Result:=True;
end;  

function CallBack(const pszJson:PChar):Boolean; cdecl;
var
  s:string;
begin
  //ShowMessage(pszJson);

  Result:=True;
end;  

procedure TForm1.btn_startClick(Sender: TObject);
var
  js:TlkJSONobject;
  tmpParam:TlkJSONobject;
  tmp2:TlkJSONbase;
  ws:TlkJSONstring;
  s:string;
  i:Integer;
  num:TlkJSONnumber;

  //Handle:THandle;
  //pRtmp:Pointer;
  pRes:PChar;
  CallBackFun:TcallBackFun;
//  CreateRtmpPlayer:TCreateRtmpPlayer;
//  CallInJson:TCallInJson;

  m_strScheduleSvr,m_strPublishSiteInfo,
  m_strPublishStageInfo,m_strUserID,m_strKey,strApp:String;

begin
//  Handle := LoadLibrary('RtmpPlayManager_c.dll');
//  ShowMessage(SysErrorMessage(GetLastError));
//  if Handle <>0 then
//   begin
//     @CreateRtmpPlayer := GetProcAddress(Handle,'CreateRtmpPlayManager_c');
//     ShowMessage(SysErrorMessage(GetLastError));
//
//     @CallInJson := GetProcAddress(Handle,'CallInJson');
//     ShowMessage(SysErrorMessage(GetLastError));
//     if(@CreateRtmpPlayer <> nil) then
//     begin
//           pRtmp := CreateRtmpPlayer(CallBack);
//           GetMem(pRes,1024);
//           js := TlkJSONobject.Create;
//           tmp := TlkJSONobject.Create();
//           js.Add('cmd','startplay');
//           js.Add('params',tmp);
//           s := TlkJSON.GenerateText(js);
//           CallInJson(pRtmp,PChar(s),@pRes);
//
//           tmp.Free;
//           //js.Free;
//           FreeMem(pRes);
//     end else ShowMessage('GetProcAddress error');
//     FreeLibrary(Handle); //从进程的地址空间中解除“.dll”文件的映射
//   end;
m_strScheduleSvr := edt_address.Text;
m_strPublishSiteInfo := edt_app.Text;
m_strPublishStageInfo := edt_stream.Text;
m_strKey :='yun';
strApp := m_strPublishSiteInfo + '?' + m_strKey;
m_strUserID := '10000';
pnl_video.Width := 320;
pnl_video.Height := 240;

//设置启动流媒体启动参数
           GetMem(pRes,1024);
           ZeroMemory(pRes,1024);
           js := TlkJSONobject.Create();
           tmpParam := TlkJSONobject.Create();

           // SetStreamInfo
           tmpParam.Add('pURL',m_strScheduleSvr);
           tmpParam.Add('pAppID',strApp);
           tmpParam.Add('pStreamID',m_strPublishStageInfo);

           ZeroMemory(pRes,1024);
           js := TlkJSONobject.Create();
           js.Add('cmd','SetStreamInfo');
           js.Add('params',tmpParam);
           s := TlkJSON.GenerateText(js);
           CallInJson(pRtmp,PChar(s),@pRes);
           
           // SetAudioPlayDev
           ZeroMemory(pRes,1024);
           js := TlkJSONobject.Create();
           tmpParam := TlkJSONobject.Create();
           tmpParam.Add('uDevID',cbb_audiooutput.ItemIndex);
           js.Add('cmd','SetAudioPlayDev');
           js.Add('params',tmpParam);

           s := TlkJSON.GenerateText(js);
           CallInJson(pRtmp,PChar(s),@pRes);
           s := TlkJSON.GenerateText(tmpParam);

           // SetVdDisplayWnd

           SetVdDisplayWnd(pRtmp,pnl_video.Handle);

           //  SetAdPara
           ZeroMemory(pRes,1024);
           js := TlkJSONobject.Create();
           tmpParam := TlkJSONobject.Create();
           tmpParam.Add('uOutVolum',80);
           tmpParam.Add('bMute',False);
           js.Add('cmd','SetAdPara');
           js.Add('params',tmpParam);

           s := TlkJSON.GenerateText(js);
           CallInJson(pRtmp,PChar(s),@pRes);

           //  SetClientUserID
           ZeroMemory(pRes,1024);
           js := TlkJSONobject.Create();
           tmpParam := TlkJSONobject.Create();
           tmpParam.Add('pszUserID',m_strUserID);
           js.Add('cmd','SetClientUserID');
           js.Add('params',tmpParam);

           s := TlkJSON.GenerateText(js);
           CallInJson(pRtmp,PChar(s),@pRes);

           //  StartPlay
           ZeroMemory(pRes,1024);
           js := TlkJSONobject.Create();
           tmpParam := TlkJSONobject.Create();
           js.Add('cmd','StartPlay');
           js.Add('params',tmpParam);

           s := TlkJSON.GenerateText(js);
           CallInJson(pRtmp,PChar(s),@pRes);

           js.Free();
           FreeMem(pRes);
end;

procedure TForm1.FormCreate(Sender: TObject);
var
  js:TlkJSONobject;
  tmp:TlkJSONobject;
  tmp2:TlkJSONbase;
  ws:TlkJSONstring;
  s:string;
  i:Integer;
  start:Integer;
  num:TlkJSONnumber;
  tmp3:TlkJSONlist;
begin
  //i := pnl_video.Handle;
  Handle := LoadLibrary('RtmpPlayManager_c.dll');
  ShowMessage(SysErrorMessage(GetLastError));
  if Handle <>0 then
   begin
     @CreateRtmpPlayer := GetProcAddress(Handle,'CreateRtmpPlayManager_c');
     ShowMessage(SysErrorMessage(GetLastError));

     @CallInJson := GetProcAddress(Handle,'CallInJson');
     @SetVdDisplayWnd := GetProcAddress(Handle,'SetVdDisplayWnd');
     ShowMessage(SysErrorMessage(GetLastError));
     if(@CreateRtmpPlayer <> nil) then
     begin
           pRtmp := CreateRtmpPlayer(CallBack);
           GetMem(pRes,1024);
           ZeroMemory(pRes,1024);
           js := TlkJSONobject.Create;
           tmp := TlkJSONobject.Create();
           js.Add('cmd','GetAudioPlayDevList');
           js.Add('params',tmp);
           s := TlkJSON.GenerateText(js);
           CallInJson(pRtmp,PChar(s),@pRes);
           s := UTF8Encode(pRes);
           js := TlkJSON.ParseText(s) as TlkJSONobject;
           s := TlkJSON.GenerateText(js);
           tmp := js.Field['data'] as TlkJSONobject;
           s := TlkJSON.GenerateText(tmp);
           tmp3 :=  tmp.Field['player'] as TlkJSONlist;
           s := TlkJSON.GenerateText(tmp3);
           i := tmp3.Count;
           //start := 0;
           for  start:=0 to i-1 do
           begin
             s := tmp3.getString(start);
             cbb_audiooutput.AddItem(tmp3.getString(start),nil);
           end;
           cbb_audiooutput.ItemIndex:=0;
           s := TlkJSON.GenerateText(tmp);
           tmp.Free;
           //js.Free;
           FreeMem(pRes);
     end else ShowMessage('GetProcAddress error');
     //FreeLibrary(Handle); //从进程的地址空间中解除“.dll”文件的映射
   end;
end;


procedure TForm1.FormDestroy(Sender: TObject);
begin
  if Handle <>0 then
  begin
        FreeLibrary(Handle); //从进程的地址空间中解除“.dll”文件的映射
  end;
    //edt_address.Text;
end;

procedure TForm1.btn_stopClick(Sender: TObject);
var
  js:TlkJSONobject;
  tmpParam:TlkJSONobject;
  tmp2:TlkJSONbase;
  ws:TlkJSONstring;
  s:string;
  i:Integer;
  pRes:PChar;
begin
   //StopPlay
   GetMem(pRes,1024);
   ZeroMemory(pRes,1024);
   js := TlkJSONobject.Create();
   tmpParam := TlkJSONobject.Create();
   js.Add('cmd','StopPlay');
   js.Add('params',tmpParam);
   s := TlkJSON.GenerateText(js);
   CallInJson(pRtmp,PChar(s),@pRes);
   s := UTF8Encode(pRes);
   js := TlkJSON.ParseText(s) as TlkJSONobject;
   s := TlkJSON.GenerateText(js);
   js.Free;
   FreeMem(pRes);
end;

end.



