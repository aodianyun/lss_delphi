unit publish;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs,typdef, StdCtrls, ExtCtrls,jpeg;

type
  TForm1 = class(TForm)
    pnl_video: TPanel;
    btn_start: TButton;
    btn_stop: TButton;
    cbb_cam: TComboBox;
    cbb_mic: TComboBox;
    edt_pubAddress: TEdit;
    edt_app: TEdit;
    edt_stream: TEdit;
    procedure FormCreate(Sender: TObject);
    procedure btn_startClick(Sender: TObject);
    procedure btn_stopClick(Sender: TObject);
    procedure showLogo();
  private
    { Private declarations }
    Handle:THandle;
    pRtmp:Pointer;
    CreateRtmpPublish:TCreateRtmpPublish;
    DoTest:TDoTest;
    CallInJson:TCallInJson;
    SetPublishVideoPara:TSetPublishVideoPara;
    Release:TRealease;
    pRes:PChar;
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
begin
  //ShowMessage(pszJson);
  Result:=True;
end;

procedure TForm1.showLogo();
var
  myjpg:Tjpegimage;
  mycanvas:TControlCanvas;
begin
  myjpg:=Tjpegimage.Create ;
  mycanvas:=TControlCanvas.Create ;
  myjpg.LoadFromFile('logo.jpg') ;
  mycanvas.Control :=pnl_video;
  mycanvas.StretchDraw(pnl_video.ClientRect ,myjpg);
  myjpg.Free ;
  mycanvas.Free;
  pnl_video.Repaint ;
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
  showLogo();
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

    @Release := GetProcAddress(Handle,'Release');
    //ShowMessage(SysErrorMessage(GetLastError));

    @DoTest := GetProcAddress(Handle,'DoTest');
    //ShowMessage(SysErrorMessage(GetLastError));
    if (@CreateRtmpPublish <>nil) then
    begin
      pRtmp := CreateRtmpPublish(CallBack);
      if(pRtmp=nil) then
      begin
         ShowMessage(SysErrorMessage(GetLastError));
      end;  
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

      js.Free;
      FreeMem(pRes);
    end;
    end else ShowMessage(SysErrorMessage(GetLastError));
end;

procedure TForm1.btn_startClick(Sender: TObject);
var
	 m_strScheduleSvr,
	 m_strPublishRoomInfo,
	 m_strPublishStageInfo,
	 m_strUserID,
	 m_strKey:String;
   strApp:string;
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
	 m_strScheduleSvr := edt_pubAddress.Text;
	 m_strPublishRoomInfo := edt_app.Text;
	 m_strPublishStageInfo := edt_stream.Text;
	 m_strUserID := '10000';
	 m_strKey := 'yun';
   strApp :=  m_strPublishRoomInfo+'?'+m_strKey;

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

    //DoTest(pRtmp,pnl_video.Handle);

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
    SetPublishVideoPara(pRtmp,m_iVdWidth, m_iVdHeight, m_iVdFps, m_iVdBitRate,pnl_video.Handle, m_iVdInterval);

    // SetPublishStreamPara
    ZeroMemory(pRes,1024);
    js := TlkJSONobject.Create();
    tmpParam := TlkJSONobject.Create();
    tmpParam.Add('pServer',m_strScheduleSvr);
    tmpParam.Add('pApp',strApp);
    tmpParam.Add('pStream',m_strPublishStageInfo);
    js.Add('cmd','SetPublishStreamPara');
    js.Add('params',tmpParam);
    s := TlkJSON.GenerateText(js);
    CallInJson(pRtmp,PChar(s),@pRes);

    // SetPublishOtherPlayerVolum
    ZeroMemory(pRes,1024);
    js := TlkJSONobject.Create();
    tmpParam := TlkJSONobject.Create();
    tmpParam.Add('uVolum',m_iOtherPlayerVolum);
    tmpParam.Add('bMute',m_bOtherPlayerMute);
    js.Add('cmd','SetPublishOtherPlayerVolum');
    js.Add('params',tmpParam);
    s := TlkJSON.GenerateText(js);
    CallInJson(pRtmp,PChar(s),@pRes);

    // SetClientUserID
    ZeroMemory(pRes,1024);
    js := TlkJSONobject.Create();
    tmpParam := TlkJSONobject.Create();
    tmpParam.Add('pszUserID',m_strUserID);
    js.Add('cmd','SetClientUserID');
    js.Add('params',tmpParam);
    s := TlkJSON.GenerateText(js);
    CallInJson(pRtmp,PChar(s),@pRes);

    // StartPublish
    ZeroMemory(pRes,1024);
    js := TlkJSONobject.Create();
    tmpParam := TlkJSONobject.Create();
    js.Add('cmd','StartPublish');
    js.Add('params',tmpParam);
    s := TlkJSON.GenerateText(js);
    CallInJson(pRtmp,PChar(s),@pRes);


    js.Free;
    FreeMem(pRes);
end;

procedure TForm1.btn_stopClick(Sender: TObject);
var
  js:TlkJSONobject;
  tmpParam:TlkJSONobject;
  //:TlkJSONbase;
  //ws:TlkJSONstring;
  s:string;
  i:Integer;

begin
    //
    GetMem(pRes,1024);
    ZeroMemory(pRes,1024);
    js := TlkJSONobject.Create();
    tmpParam := TlkJSONobject.Create();
    js.Add('cmd','StopPublish');
    js.Add('params',tmpParam);
    s := TlkJSON.GenerateText(js);
    CallInJson(pRtmp,PChar(s),@pRes);

    js.Free;
    FreeMem(pRes);
end;

end.
