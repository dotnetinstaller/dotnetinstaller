VERSION 5.00
Object = "{22A83438-4B36-4CEC-9AF7-C0001674E2A8}#1.0#0"; "AxHTMLayout.dll"
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "comdlg32.ocx"
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   3090
   ClientLeft      =   165
   ClientTop       =   855
   ClientWidth     =   6135
   BeginProperty Font 
      Name            =   "Microsoft Sans Serif"
      Size            =   8.25
      Charset         =   204
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   ScaleHeight     =   3090
   ScaleWidth      =   6135
   StartUpPosition =   3  'Windows Default
   Begin VB.ListBox EventLog 
      Height          =   2220
      IntegralHeight  =   0   'False
      Left            =   2640
      TabIndex        =   2
      Top             =   0
      Width           =   3495
   End
   Begin HTMLayoutCtl.Engine Engine1 
      Height          =   1935
      Left            =   0
      OleObjectBlob   =   "Form1.frx":0000
      TabIndex        =   1
      Top             =   0
      Width           =   2415
   End
   Begin MSComctlLib.StatusBar StatusBar1 
      Align           =   2  'Align Bottom
      Height          =   375
      Left            =   0
      TabIndex        =   0
      Top             =   2715
      Width           =   6135
      _ExtentX        =   10821
      _ExtentY        =   661
      Style           =   1
      _Version        =   393216
      BeginProperty Panels {8E3867A5-8586-11D1-B16A-00C0F0283628} 
         NumPanels       =   1
         BeginProperty Panel1 {8E3867AB-8586-11D1-B16A-00C0F0283628} 
         EndProperty
      EndProperty
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "Microsoft Sans Serif"
         Size            =   8.25
         Charset         =   204
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
   End
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   1800
      Top             =   2160
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
      CancelError     =   -1  'True
      DefaultExt      =   "htm"
      DialogTitle     =   "Open html document"
      Filter          =   "HTML files (*.htm, *.html)|*.htm;*.html"
   End
   Begin VB.Menu File 
      Caption         =   "File"
      Begin VB.Menu OpenFile 
         Caption         =   "Open ..."
      End
      Begin VB.Menu Exit 
         Caption         =   "Exit"
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim WithEvents root As HTMLayoutCtl.Element
Attribute root.VB_VarHelpID = -1

Private Sub Engine1_DocumentComplete()
  Debug.Print "Event: DocumentComplete"
End Sub

Private Sub Engine1_DocumentLoaded()
  Debug.Print "Event: DocumentLoaded"
  Set root = Engine1.root ' bind root with events
End Sub

Private Sub Exit_Click()
  End
End Sub

Private Sub Form_Load()
  Set root = Engine1.root ' bind root with events
End Sub

Private Sub Form_Resize()
  On Error GoTo Abend
  Engine1.Width = Me.ScaleWidth - EventLog.Width
  Engine1.Height = Me.ScaleHeight - Engine1.Top - StatusBar1.Height
  EventLog.Left = Me.ScaleWidth - EventLog.Width
  EventLog.Height = Me.ScaleHeight - EventLog.Top - StatusBar1.Height
Abend:
End Sub

Private Sub OpenFile_Click()
  On Error GoTo CancelSelection
  CommonDialog1.ShowOpen
  Engine1.Load "file://" & CommonDialog1.FileName
  'MsgBox Engine1.Root.Tag
  'MsgBox Engine1.Root.Value
  'MsgBox Engine1.Root.Select("p").Value
      
  Dim els As Elements, el As Element
  Set els = Engine1.root.SelectAll("body > *") ' enumerate all immediate children of body element
  For Each el In els
      'Debug.Print el.Tag
      MsgBox el.Tag & "->" & el.Value
  Next
CancelSelection:
End Sub

Private Sub root_onControlEvent(ByVal target As HTMLayoutCtl.Element, ByVal eventType As Long, ByVal reason As Long, Handled As Boolean)
  If (eventType And HTMLayoutCtl.MASK_SINKING) = 0 Then
    Select Case eventType
      Case HTMLayoutCtl.BE_BUTTON_CLICK
         EventLog.AddItem "BUTTON_CLICK " & target.Tag & " id:" & target.attribute("id")
      Case HTMLayoutCtl.BE_BUTTON_STATE_CHANGED
         EventLog.AddItem "BUTTON_STATE_CHANGED " & target.Tag & " id:" & target.attribute("id")
      ' and so on
    End Select
  End If
End Sub

Private Sub root_onMouse(ByVal target As HTMLayoutCtl.Element, ByVal eventType As Long, ByVal x As Long, ByVal y As Long, ByVal buttons As Long, ByVal keys As Long, Handled As Boolean)
  'If (eventType And HTMLayoutCtl.MASK_SINKING) = 0 Then
  '  EventLog.AddItem "MOUSE " & eventType & " x:" & x & " y:" & y & " buttons:" & buttons & " keys:" & keys
  'End If
End Sub
