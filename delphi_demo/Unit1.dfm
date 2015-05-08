object Form1: TForm1
  Left = 834
  Top = 249
  Width = 757
  Height = 598
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object pnl_video: TPanel
    Left = 62
    Top = 15
    Width = 321
    Height = 241
    Caption = 'pnl_video'
    TabOrder = 0
  end
  object btn_start: TButton
    Left = 62
    Top = 430
    Width = 97
    Height = 49
    Caption = 'btn_start'
    TabOrder = 1
    OnClick = btn_startClick
  end
  object btn_stop: TButton
    Left = 226
    Top = 430
    Width = 113
    Height = 49
    Caption = 'btn_stop'
    TabOrder = 2
    OnClick = btn_stopClick
  end
  object cbb_audiooutput: TComboBox
    Left = 62
    Top = 374
    Width = 129
    Height = 21
    ItemHeight = 13
    TabOrder = 3
    Text = 'cbb_audiooutput'
  end
  object edt_address: TEdit
    Left = 62
    Top = 278
    Width = 281
    Height = 21
    TabOrder = 4
    Text = 'rtmp://lssplay.aodianyun.com:1935'
  end
  object edt_app: TEdit
    Left = 62
    Top = 318
    Width = 97
    Height = 21
    TabOrder = 5
    Text = 'app'
  end
  object edt_stream: TEdit
    Left = 226
    Top = 318
    Width = 113
    Height = 21
    TabOrder = 6
    Text = 'stream'
  end
end
