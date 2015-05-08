object Form1: TForm1
  Left = 640
  Top = 279
  Width = 836
  Height = 574
  Caption = 'Form1'
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
end
