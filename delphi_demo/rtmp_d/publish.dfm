object Form1: TForm1
  Left = 709
  Top = 293
  Width = 836
  Height = 518
  Caption = 'y'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object lbl_width: TLabel
    Left = 432
    Top = 37
    Width = 38
    Height = 13
    Caption = #23485#24230
  end
  object lbl_height: TLabel
    Left = 536
    Top = 37
    Width = 29
    Height = 13
    Caption = #39640#24230
  end
  object lbl_fps: TLabel
    Left = 432
    Top = 61
    Width = 38
    Height = 13
    Caption = #24103#29575
  end
  object lbl_bits: TLabel
    Left = 536
    Top = 61
    Width = 29
    Height = 13
    Caption = #30721#29575
  end
  object lbl_iframe: TLabel
    Left = 396
    Top = 86
    Width = 74
    Height = 13
    Caption = #20851#38190#24103#38388#38548
  end
  object lbl_bframe: TLabel
    Left = 541
    Top = 89
    Width = 24
    Height = 13
    Caption = 'B'#24103
  end
  object lbl_qulity: TLabel
    Left = 408
    Top = 116
    Width = 62
    Height = 13
    Caption = #35270#39057#36136#37327
  end
  object lbl_videoparas: TLabel
    Left = 479
    Top = 14
    Width = 62
    Height = 13
    Caption = #35270#39057#21442#25968
  end
  object lbl_samplerate: TLabel
    Left = 661
    Top = 38
    Width = 36
    Height = 13
    Caption = #37319#26679#29575
  end
  object lbl_channels: TLabel
    Left = 661
    Top = 62
    Width = 36
    Height = 13
    Caption = #36890#36947#25968
  end
  object lbl_bitpersample: TLabel
    Left = 649
    Top = 86
    Width = 48
    Height = 13
    Caption = #37319#26679#31934#24230
  end
  object lbl_aubits: TLabel
    Left = 673
    Top = 110
    Width = 24
    Height = 13
    Caption = #30721#29575
  end
  object lbl_audioparas: TLabel
    Left = 649
    Top = 14
    Width = 62
    Height = 13
    Caption = #38899#39057#21442#25968
  end
  object lbl_volum: TLabel
    Left = 768
    Top = 14
    Width = 26
    Height = 13
    Caption = #38899#37327
  end
  object lbl_callback: TLabel
    Left = 456
    Top = 184
    Width = 111
    Height = 13
    Caption = #22238#35843#28040#24687#25552#31034#21306
  end
  object pnl_video: TPanel
    Left = 46
    Top = 17
    Width = 332
    Height = 241
    Caption = 'pnl_video'
    TabOrder = 0
  end
  object btn_start: TButton
    Left = 46
    Top = 385
    Width = 116
    Height = 49
    Caption = 'btn_start'
    TabOrder = 1
    OnClick = btn_startClick
  end
  object btn_stop: TButton
    Left = 214
    Top = 385
    Width = 116
    Height = 49
    Caption = 'btn_stop'
    TabOrder = 2
    OnClick = btn_stopClick
  end
  object cbb_cam: TComboBox
    Left = 46
    Top = 345
    Width = 100
    Height = 21
    ItemHeight = 13
    TabOrder = 3
    Text = 'cbb_cam'
  end
  object cbb_mic: TComboBox
    Left = 230
    Top = 345
    Width = 108
    Height = 21
    ItemHeight = 13
    TabOrder = 4
    Text = 'cbb_mic'
  end
  object edt_pubAddress: TEdit
    Left = 46
    Top = 273
    Width = 268
    Height = 21
    TabOrder = 5
    Text = 'rtmp://rtmp.aodianyun.com:1935'
  end
  object edt_app: TEdit
    Left = 46
    Top = 305
    Width = 100
    Height = 21
    TabOrder = 6
    Text = 'app'
  end
  object edt_stream: TEdit
    Left = 230
    Top = 305
    Width = 116
    Height = 21
    TabOrder = 7
    Text = 'stream'
  end
  object edt_width: TEdit
    Left = 480
    Top = 37
    Width = 41
    Height = 21
    TabOrder = 8
    Text = '320'
  end
  object edt_height: TEdit
    Left = 584
    Top = 37
    Width = 41
    Height = 21
    TabOrder = 9
    Text = '240'
  end
  object edt_fps: TEdit
    Left = 480
    Top = 61
    Width = 41
    Height = 21
    TabOrder = 10
    Text = '10'
  end
  object edt_bits: TEdit
    Left = 584
    Top = 61
    Width = 40
    Height = 21
    TabOrder = 11
    Text = '160'
  end
  object edt_iframe: TEdit
    Left = 480
    Top = 86
    Width = 49
    Height = 21
    TabOrder = 12
    Text = '30'
  end
  object edt_Bframe: TEdit
    Left = 584
    Top = 87
    Width = 41
    Height = 21
    TabOrder = 13
    Text = '0'
  end
  object edt_qulity: TEdit
    Left = 480
    Top = 116
    Width = 41
    Height = 21
    TabOrder = 14
    Text = '0'
  end
  object edt_asample: TEdit
    Left = 710
    Top = 36
    Width = 41
    Height = 21
    TabOrder = 15
    Text = '44100'
  end
  object edt_auchannels: TEdit
    Left = 710
    Top = 60
    Width = 40
    Height = 21
    TabOrder = 16
    Text = '2'
  end
  object edt_aubitpersample: TEdit
    Left = 710
    Top = 86
    Width = 41
    Height = 21
    TabOrder = 17
    Text = '16'
  end
  object edt_aubits: TEdit
    Left = 710
    Top = 110
    Width = 41
    Height = 21
    TabOrder = 18
    Text = '32'
  end
  object trckbr_volum: TTrackBar
    Left = 768
    Top = 51
    Width = 41
    Height = 81
    Max = 100
    Orientation = trVertical
    Position = 80
    TabOrder = 19
    OnChange = OnChange
  end
  object chk_bmute: TCheckBox
    Left = 768
    Top = 32
    Width = 44
    Height = 17
    Caption = #38745#38899
    TabOrder = 20
    OnClick = OnChange
  end
  object mmo_result: TMemo
    Left = 456
    Top = 208
    Width = 313
    Height = 229
    Lines.Strings = (
      'mmo_result')
    TabOrder = 21
  end
end
