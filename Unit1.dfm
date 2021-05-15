object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'MySudoku'
  ClientHeight = 470
  ClientWidth = 872
  Color = clWindow
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object StringGrid1: TStringGrid
    Left = 16
    Top = 8
    Width = 1
    Height = 1
    TabStop = False
    ColCount = 6
    Ctl3D = True
    DefaultColWidth = 25
    DefaultRowHeight = 25
    DrawingStyle = gdsClassic
    FixedCols = 0
    RowCount = 6
    FixedRows = 0
    GradientEndColor = clBtnFace
    GradientStartColor = clBtnFace
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goTabs]
    ParentCtl3D = False
    TabOrder = 0
  end
  object ComboBox1: TComboBox
    Left = 456
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 1
    Text = 'Choose difficulty'
  end
  object Button1: TButton
    Left = 480
    Top = 43
    Width = 75
    Height = 25
    Caption = 'Create'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 456
    Top = 136
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 3
    OnClick = Button2Click
  end
end
