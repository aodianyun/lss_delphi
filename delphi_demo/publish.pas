unit publish;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls,test;
type
  TForm1 = class(TForm)
    pnl_video: TPanel;
    edt_pubAddress: TEdit;
    edt_app: TEdit;
    edt_stream: TEdit;
    btn_start: TButton;
    btn_stop: TButton;
    cbb_cam: TComboBox;
    cbb_mic: TComboBox;
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure btn_startClick(Sender: TObject);
  private
    { Private declarations }
    Handle:THandle;
    pRtmp:Pointer;
    CreateRtmpPublish:TCreateRtmpPublish;
    CallInJson:TCallInJson;
    pRes:PChar;
    CallBackFun:TcallBackFun;
    SetPublishVideoPara:TSetPublishVideoPara;
    Release:TRealease;
    DoTest:TDoTest;
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation
   uses
     uLkJSON;
{$R *.dfm}

function CallBack(const pszJson:PChar):Boolean; cdecl;
var
  s:string;
begin
  Result:=True;
end;



procedure TForm1.FormCreate(Sender: TObject);
var
  js:TlkJSONobject;
  tmpParam:TlkJSONobject;
  tmp2:TlkJSONbase;
  ws:TlkJSONstring;
  s:string;
  i:Integer;
  start:Integer;
  num:TlkJSONnumber;
  tmp3:TlkJSONlist;

begin
  pnl_video.Width := 320;
  pnl_video.Height := 240;
  Handle := LoadLibrary('RtmpPublishManager_c.dll');
  //ShowMessage(SysErrorMessage(GetLastError));
  if Handle <>0 then
  begin
    @CreateRtmpPublish := GetProcAddress(Handle,'CreateRtmpPublishManager_c');
    //ShowMessage(SysErrorMessage(GetLastError));

    @CallInJson := GetProcAddress(Handle,'CallInJson');
    //ShowMessage(SysErrorMessage(GetLastError));

    @SetPublishVideoPara := GetProcAddress(Handle,'SetPublishVideoPara');
    //ShowMessage(SysErrorMessage(GetLastError));
    // test
    //@DoTest := GetProcAddress(Handle,'DoTest');

    @Release := GetProcAddress(Handle,'Release');
    //ShowMessage(SysErrorMessage(GetLastError));
    if (@CreateRtmpPublish <>nil) then
    begin
      pRtmp := CreateRtmpPublish(CallBackFun);
      GetMem(pRes,1024);
      ZeroMemory(pRes,1024);

      //  GetCamList
      js := TlkJSONobject.Create();
      tmpParam := TlkJSONobject.Create();
      js.Add('cmd','GetCamList');
      js.Add('params',tmpParam);
      s := TlkJSON.GenerateText(js);
      CallInJson(pRtmp,PChar(s),@pRes);
      s := UTF8Encode(pRes);
      js := TlkJSON.ParseText(s) as TlkJSONobject;
      tmpParam := js.Field['data'] as TlkJSONobject;
      s := TlkJSON.GenerateText(tmpParam);
      tmp3 := tmpParam.Field['cameras'] as TlkJSONlist;
      i := tmp3.Count;

      for start:=0 to i-1 do
      begin
        cbb_cam.AddItem(tmp3.getString(start),nil);
      end;
      cbb_cam.ItemIndex := 0;

      // GetMicList
      js := TlkJSONobject.Create();
      tmpParam := TlkJSONobject.Create();
      js.Add('cmd','GetMicList');
      js.Add('params',tmpParam);
      s := TlkJSON.GenerateText(js);
      CallInJson(pRtmp,PChar(s),@pRes);
      s := UTF8Encode(pRes);
      js := TlkJSON.ParseText(s) as TlkJSONobject;
      tmpParam := js.Field['data'] as TlkJSONobject;
      s := TlkJSON.GenerateText(tmpParam);
      tmp3 := tmpParam.Field['mics'] as TlkJSONlist;
      i := tmp3.Count;

      for start:=0 to i-1 do
      begin
        cbb_mic.AddItem(tmp3.getString(start),nil);
      end;
      cbb_mic.ItemIndex := 0;

      //DoTest(pRtmp,pnl_video.Handle);

      js.Free;
      FreeMem(pRes);
    end;
  end else   ShowMessage(SysErrorMessage(GetLastError));
end;

procedure TForm1.FormDestroy(Sender: TObject);
begin
  if Handle <>0 then
  begin
    FreeLibrary(Handle);
  end;
end;

procedure TForm1.btn_startClick(Sender: TObject);

var
	 m_strScheduleSvr,
	 m_strPublishRoomInfo,
	 m_strPublishStageInfo,
	 m_strUserID,
	 m_strKey:String;

	 // video paragment
	 m_iVdFps,
	 m_iVdBitRate,
	 m_iVdWidth,
	 m_iVdHeight,
	 m_iVdQuality,
	 m_iVdInterval,
	 m_iBFrame,
	 m_iQuality:Integer;

	 //audio para
	 m_iAdSampleRate,
	 m_iAdBitRate,
	 m_iAdChannels,
	 m_iAdBitPerSample,
	 m_iAdVolum:Integer;
	 m_bAdMute,
	 m_bShowSpectrum:Boolean;

	 m_bOtherPlayerMute:Boolean;
	 m_iOtherPlayerVolum:Integer;
   strApp:String;
   js:TlkJSONobject;
  tmpParam:TlkJSONobject;
  //:TlkJSONbase;
  //ws:TlkJSONstring;
  s:string;
  i:Integer;
  //start:Integer;
  //num:TlkJSONnumber;
  //tmp3:TlkJSONlist;
begin
	 m_strScheduleSvr := 'rtmp://rtmp.aodianyun.com:1935';
	 m_strPublishRoomInfo := 'app';
	 m_strPublishStageInfo := 'stream';
	 m_strUserID := '10000';
	 m_strKey := 'yun';

	 //@ video paragment
	 m_iVdFps := 10;
	 m_iVdBitRate := 160*1000;
	 m_iVdWidth := 320;
	 m_iVdHeight := 240;
	 m_iVdQuality := 80;
	 m_iVdInterval := 30;
	 m_iBFrame := 0;
	 m_iQuality := 0;

	 //@ audio para
	 m_iAdSampleRate := 44100;
	 m_iAdBitRate := 32*1000;
	 m_iAdChannels := 2;
	 m_iAdBitPerSample := 16;
	 m_iAdVolum := 80;
	 m_bAdMute := false;
	 m_bShowSpectrum := true;

	 m_bOtherPlayerMute := false;
	 m_iOtherPlayerVolum := 80;
   strApp :=  m_strPublishRoomInfo+'?'+m_strKey;
   GetMem(pRes,1024);


    //  SetCam
    ZeroMemory(pRes,1024);
    js := TlkJSONobject.Create();
    tmpParam := TlkJSONobject.Create();
    tmpParam.Add('uCamID',cbb_cam.ItemIndex);
    js.Add('cmd','SetCam');
    js.Add('params',tmpParam);
    s := TlkJSON.GenerateText(js);
    CallInJson(pRtmp,PChar(s),@pRes);
//    s := UTF8Encode(pRes);
//    js := TlkJSON.ParseText(s) as TlkJSONobject;

    // SetMic
    ZeroMemory(pRes,1024);
    js := TlkJSONobject.Create();
    tmpParam := TlkJSONobject.Create();
    tmpParam.Add('uMicID',cbb_mic.ItemIndex);
    js.Add('cmd','SetMic');
    js.Add('params',tmpParam);
    s := TlkJSON.GenerateText(js);
    CallInJson(pRtmp,PChar(s),@pRes);


    // SetPublishAudioPara
    ZeroMemory(pRes,1024);
    js := TlkJSONobject.Create();
    tmpParam := TlkJSONobject.Create();
    tmpParam.Add('iSampleRate',m_iAdSampleRate);
    tmpParam.Add('iChannels',m_iAdChannels);
    tmpParam.Add('iBitPerSample',m_iAdBitPerSample);
    tmpParam.Add('iBitRate',m_iAdBitRate);
    tmpParam.Add('iVolum', m_iAdVolum);
    tmpParam.Add('bMute', m_bAdMute);
    js.Add('cmd','SetPublishAudioPara');
    js.Add('params',tmpParam);
    s := TlkJSON.GenerateText(js);
    CallInJson(pRtmp,PChar(s),@pRes);

    // SetPublishVideoPara
    SetPublishVideoPara(pRtmp,m_iVdWidth, m_iVdHeight, m_iVdFps, m_iVdBitRate, pnl_video.Handle, m_iVdInterval);
    
    js.Free;
    FreeMem(pRes);
end;

end.
