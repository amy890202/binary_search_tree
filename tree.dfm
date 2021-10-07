object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 616
  ClientWidth = 868
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 241
    Height = 616
    Align = alLeft
    Caption = 'Panel1'
    TabOrder = 0
    object PageControl2: TPageControl
      Left = 1
      Top = 1
      Width = 239
      Height = 614
      ActivePage = TabSheet2
      Align = alClient
      TabOrder = 0
      object TabSheet2: TTabSheet
        Caption = 'BST'
        object GroupBox1: TGroupBox
          Left = -3
          Top = 153
          Width = 231
          Height = 64
          Caption = 'stack  traverse'
          TabOrder = 0
          object Button8: TButton
            Left = 14
            Top = 25
            Width = 68
            Height = 25
            Caption = 'inorder'
            TabOrder = 0
            OnClick = Button8Click
          end
          object Button10: TButton
            Left = 88
            Top = 24
            Width = 69
            Height = 25
            Caption = 'preorder'
            TabOrder = 1
            OnClick = Button10Click
          end
          object Button11: TButton
            Left = 163
            Top = 24
            Width = 65
            Height = 25
            Caption = 'postorder'
            TabOrder = 2
            OnClick = Button11Click
          end
        end
        object GroupBox2: TGroupBox
          Left = 21
          Top = 223
          Width = 185
          Height = 105
          Caption = 'delete'
          TabOrder = 1
          object Edit2: TEdit
            Left = 32
            Top = 22
            Width = 121
            Height = 21
            TabOrder = 0
            Text = '100'
          end
          object Button9: TButton
            Left = 40
            Top = 77
            Width = 110
            Height = 25
            Caption = 'delete not recursion'
            TabOrder = 1
            OnClick = Button9Click
          end
          object Button2: TButton
            Left = 40
            Top = 46
            Width = 107
            Height = 25
            Caption = 'Delete from BST'
            TabOrder = 2
            OnClick = Button2Click
          end
        end
        object GroupBox4: TGroupBox
          Left = 3
          Top = 92
          Width = 225
          Height = 55
          Caption = 'recursion  traverse'
          TabOrder = 2
          object Button4: TButton
            Left = 6
            Top = 16
            Width = 75
            Height = 25
            Caption = 'preorder'
            TabOrder = 0
            OnClick = Button4Click
          end
          object Button5: TButton
            Left = 87
            Top = 16
            Width = 67
            Height = 28
            Caption = 'postorder'
            TabOrder = 1
            OnClick = Button5Click
          end
          object Button6: TButton
            Left = 160
            Top = 16
            Width = 62
            Height = 28
            Caption = 'level order'
            TabOrder = 2
            OnClick = Button6Click
          end
        end
        object GroupBox5: TGroupBox
          Left = 3
          Top = 345
          Width = 214
          Height = 194
          TabOrder = 3
          object Label1: TLabel
            Left = 18
            Top = 3
            Width = 115
            Height = 13
            Caption = '# of intergers(5 to 100)'
          end
          object Label2: TLabel
            Left = 18
            Top = 83
            Width = 100
            Height = 13
            Caption = 'range(100 to 10000)'
          end
          object TrackBar1: TTrackBar
            Left = 15
            Top = 20
            Width = 157
            Height = 22
            Max = 100
            Min = 5
            Position = 5
            TabOrder = 0
            OnChange = TrackBar1Change
          end
          object TrackBar2: TTrackBar
            Left = 14
            Top = 102
            Width = 158
            Height = 23
            Max = 10000
            Min = 100
            Position = 100
            TabOrder = 1
            OnChange = TrackBar2Change
          end
          object Button3: TButton
            Left = 98
            Top = 158
            Width = 113
            Height = 25
            Caption = 'Random intergers'
            TabOrder = 2
            OnClick = Button3Click
          end
          object Edit3: TEdit
            Left = 27
            Top = 48
            Width = 121
            Height = 21
            TabOrder = 3
            Text = '5'
          end
          object Edit4: TEdit
            Left = 27
            Top = 131
            Width = 121
            Height = 21
            TabOrder = 4
            Text = '100'
          end
        end
      end
    end
  end
  object Panel2: TPanel
    Left = 241
    Top = 0
    Width = 627
    Height = 616
    Align = alClient
    Caption = 'Panel2'
    TabOrder = 1
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 625
      Height = 614
      ActivePage = TabSheet1
      Align = alClient
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = 'sequence'
        object Memo1: TMemo
          Left = 0
          Top = 0
          Width = 617
          Height = 586
          Align = alClient
          Lines.Strings = (
            'Memo1')
          TabOrder = 0
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'drawing'
        ImageIndex = 1
        object Image1: TImage
          Left = 0
          Top = 0
          Width = 617
          Height = 586
          Align = alClient
          ExplicitLeft = 64
          ExplicitTop = 104
          ExplicitWidth = 433
          ExplicitHeight = 257
        end
      end
    end
  end
  object Button7: TButton
    Left = 64
    Top = 570
    Width = 115
    Height = 38
    Caption = 'draw'
    TabOrder = 2
    OnClick = Button7Click
  end
  object GroupBox3: TGroupBox
    Left = 4
    Top = 35
    Width = 231
    Height = 76
    Caption = 'insert '
    TabOrder = 3
    object Button1: TButton
      Left = 4
      Top = 48
      Width = 100
      Height = 25
      Caption = 'Insert into BST'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button12: TButton
      Left = 110
      Top = 48
      Width = 119
      Height = 25
      Caption = 'insert(not recursion)'
      TabOrder = 1
      OnClick = Button12Click
    end
    object Edit1: TEdit
      Left = 50
      Top = 16
      Width = 121
      Height = 21
      TabOrder = 2
      Text = '100'
    end
  end
end
