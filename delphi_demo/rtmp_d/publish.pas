unit publish;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs,typdef, StdCtrls, ExtCtrls,jpeg, ComCtrls;

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
    lbl_width: TLabel;
    lbl_height: TLabel;
    lbl_fps: TLabel;
    lbl_bits: TLabel;
    lbl_iframe: TLabel;
    lbl_bframe: TLabel;
    lbl_qulity: TLabel;
    edt_width: TEdit;
    edt_height: TEdit;
    edt_fps: TEdit;
    edt_bits: TEdit;
    edt_iframe: TEdit;
    edt_Bframe: TEdit;
    edt_qulity: TEdit;
    lbl_videoparas: TLabel;
    lbl_samplerate: TLabel;
    lbl_channels: TLabel;
    lbl_bitpersample: TLabel;
    lbl_aubits: TLabel;
    edt_asample: TEdit;
    edt_auchannels: TEdit;
    edt_aubitpersample: TEdit;
    edt_aubits: TEdit;
    lbl_audioparas: TLabel;
    trckbr_volum: TTrackBar;
    lbl_volum: TLabel;
    chk_bmute: TCheckBox;
    mmo_result: TMemo;
    lbl_callback: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure btn_startClick(Sender: TObject);
    procedure btn_stopClick(Sender: TObject);
    procedure showLogo();
    procedure OnChange(Sender: TObject);
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
var
//  js:TlkJSONobject;
//  tmpParam:TlkJSONobject;
//  tmp2:TlkJSONbase;
//  ws:TlkJSONstring;
  s:string;
//  cmd:string;
//  i:Integer;
//  total:Integer;
//  tmpbuffer:string;
//  f:Real;
//  start:Integer;
//  num:TlkJSONnumber;
begin
      if(pszJson = nil) then
      begin
        Result := False;
        Exit;
      end;
      s := UTF8Encode(pszJson);
      Application.ProcessMessages;
      Form1.mmo_result.Text := s;
      //SendMessage(Form1.mmo_result.Handle,WM_SETTEXT,0,LPARAM(s));
//      js := TlkJSONobject.Create();
//      tmpParam := TlkJSONobject.Create();
//      s := UTF8Encode(pszJson);
//      js := TlkJSON.ParseText(s) as TlkJSONobject;
//      cmd := js.Field['cmd'].Value;
//      tmpParam := js.Field['params'] as TlkJSONobject;
//      s := TlkJSON.GenerateText(tmpParam);
//      if(cmd = 'OnRtmpPublishManagerNetInfo') then
////      var
////        uPing:Integer;
////        uVideoBitSum:Integer;
////        fVideoBitRate:
//      begin
//
//      end
//      else if(cmd = 'OnRtmpPublishManagerComputerStatusInfo')then
//      begin
//
//      end
//      else if(cmd = 'OnRtmpPublishManagerNetInfo') then
//      begin
//
//      end
//      else if(cmd = 'OnShowVideo') then
//      begin
//
//      end
//      else if(cmd = 'OnAudioPercent') then
//      begin
//
//      end;
////      s := TlkJSON.GenerateText(tmpParam);
////      tmp3 := tmpParam.Field['mics'] as TlkJSONlist;
////      i := tmp3.Count;
//      js.Free;
  Result :=True;
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
  s:string;
  i:Integer;
begin
	 m_strScheduleSvr := edt_pubAddress.Text;
	 m_strPublishRoomInfo := edt_app.Text;
	 m_strPublishStageInfo := edt_stream.Text;
	 m_strUserID := '10000';
	 m_strKey := 'yun';
   strApp :=  m_strPublishRoomInfo+'?'+m_strKey;

	 //@ video paragment
	 m_iVdFps := strtoint(edt_fps.Text);
	 m_iVdBitRate := strtoint(edt_bits.Text)*1000;
	 m_iVdWidth := strtoint(edt_width.Text);
	 m_iVdHeight := strtoint(edt_height.Text);
	 m_iVdQuality := strtoint(edt_qulity.Text);
	 m_iVdInterval := strtoint(edt_iframe.Text);
	 m_iBFrame := strtoint(edt_Bframe.Text);
	 m_iQuality := strtoint(edt_qulity.Text);

	 //@ audio para
	 m_iAdSampleRate := strtoint(edt_asample.Text);
	 m_iAdBitRate := strtoint(edt_aubits.Text)*1000;
	 m_iAdChannels := strtoint(edt_auchannels.Text);
	 m_iAdBitPerSample := strtoint(edt_aubitpersample.Text);
	 m_iAdVolum := trckbr_volum.Position;
	 m_bAdMute := chk_bmute.Checked;
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
    s := '123';
end;

procedure TForm1.OnChange(Sender: TObject);
var
  bMute:Boolean;
  iAdVolum:Integer;

  js:TlkJSONobject;
  tmpParam:TlkJSONobject;
  s:string;
  i:Integer;

begin
    iAdVolum := trckbr_volum.Position;
    bMute := chk_bmute.Checked;

    GetMem(pRes,1024);
    ZeroMemory(pRes,1024);
    js := TlkJSONobject.Create();
    tmpParam := TlkJSONobject.Create();
    tmpParam.Add('uVolum',iAdVolum);
    tmpParam.Add('bMute',bMute);
    js.Add('cmd','SetPublishVolum');
    js.Add('params',tmpParam);
    s := TlkJSON.GenerateText(js);
    CallInJson(pRtmp,PChar(s),@pRes);

    js.Free;
    FreeMem(pRes);
end;

end.
