object Form1: TForm1
  Left = 340
  Top = 100
  Caption = 'Form1'
  ClientHeight = 668
  ClientWidth = 1033
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  OnCreate = FormCreate
  OnPaint = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 384
    Top = 344
    Width = 28
    Height = 15
    Caption = 'Cinta'
  end
  object Button1: TButton
    Left = 8
    Top = 64
    Width = 126
    Height = 49
    Caption = 'MOSTRAR FORM 2'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 215
    Width = 126
    Height = 41
    Caption = 'MOSTRAR MATRIZ '
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 368
    Top = 432
    Width = 75
    Height = 25
    Caption = 'siguiente'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 186
    Top = 107
    Width = 121
    Height = 23
    TabOrder = 3
  end
  object Button4: TButton
    Left = 208
    Top = 76
    Width = 75
    Height = 25
    Caption = 'Estados '
    TabOrder = 4
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 376
    Top = 76
    Width = 75
    Height = 25
    Caption = 'Simbolos '
    TabOrder = 5
    OnClick = Button5Click
  end
  object Edit2: TEdit
    Left = 344
    Top = 107
    Width = 137
    Height = 23
    TabOrder = 6
  end
  object Button6: TButton
    Left = 752
    Top = 76
    Width = 75
    Height = 25
    Caption = 'Transiciones '
    TabOrder = 7
    OnClick = Button6Click
  end
  object Edit3: TEdit
    Left = 720
    Top = 107
    Width = 145
    Height = 23
    TabOrder = 8
  end
  object Edit4: TEdit
    Left = 344
    Top = 224
    Width = 145
    Height = 23
    TabOrder = 9
  end
  object Button7: TButton
    Left = 376
    Top = 193
    Width = 75
    Height = 25
    Caption = 'Entrada'
    TabOrder = 10
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 544
    Top = 76
    Width = 75
    Height = 25
    Caption = 'Vacio'
    TabOrder = 11
    OnClick = Button8Click
  end
  object Edit5: TEdit
    Left = 520
    Top = 107
    Width = 145
    Height = 23
    TabOrder = 12
  end
  object Edit6: TEdit
    Left = 248
    Top = 384
    Width = 393
    Height = 23
    TabOrder = 13
    Text = 'Edit6'
  end
end
