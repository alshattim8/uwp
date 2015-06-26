<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Login
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
      Me.CancelButton = New System.Windows.Forms.Button()
      Me.AcceptButton = New System.Windows.Forms.Button()
      Me.label3 = New System.Windows.Forms.Label()
      Me.Label2 = New System.Windows.Forms.Label()
      Me.Label1 = New System.Windows.Forms.Label()
      Me.HostTextBox = New System.Windows.Forms.TextBox()
      Me.PasswordTextBox = New System.Windows.Forms.TextBox()
      Me.UsernameTextBox = New System.Windows.Forms.TextBox()
      Me.SuspendLayout()
      '
      'CancelButton
      '
      Me.CancelButton.Location = New System.Drawing.Point(179, 92)
      Me.CancelButton.Name = "CancelButton"
      Me.CancelButton.Size = New System.Drawing.Size(100, 23)
      Me.CancelButton.TabIndex = 15
      Me.CancelButton.Text = "Cancel"
      Me.CancelButton.UseVisualStyleBackColor = True
      '
      'AcceptButton
      '
      Me.AcceptButton.Location = New System.Drawing.Point(73, 92)
      Me.AcceptButton.Name = "AcceptButton"
      Me.AcceptButton.Size = New System.Drawing.Size(100, 23)
      Me.AcceptButton.TabIndex = 14
      Me.AcceptButton.Text = "OK"
      Me.AcceptButton.UseVisualStyleBackColor = True
      '
      'label3
      '
      Me.label3.AutoSize = True
      Me.label3.Location = New System.Drawing.Point(38, 73)
      Me.label3.Name = "label3"
      Me.label3.Size = New System.Drawing.Size(29, 13)
      Me.label3.TabIndex = 13
      Me.label3.Text = "Host"
      '
      'Label2
      '
      Me.Label2.AutoSize = True
      Me.Label2.Location = New System.Drawing.Point(14, 46)
      Me.Label2.Name = "Label2"
      Me.Label2.Size = New System.Drawing.Size(53, 13)
      Me.Label2.TabIndex = 12
      Me.Label2.Text = "Password"
      '
      'Label1
      '
      Me.Label1.AutoSize = True
      Me.Label1.Location = New System.Drawing.Point(12, 19)
      Me.Label1.Name = "Label1"
      Me.Label1.Size = New System.Drawing.Size(55, 13)
      Me.Label1.TabIndex = 11
      Me.Label1.Text = "Username"
      '
      'HostTextBox
      '
      Me.HostTextBox.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper
      Me.HostTextBox.Location = New System.Drawing.Point(73, 66)
      Me.HostTextBox.Name = "HostTextBox"
      Me.HostTextBox.Size = New System.Drawing.Size(206, 20)
      Me.HostTextBox.TabIndex = 10
      '
      'PasswordTextBox
      '
      Me.PasswordTextBox.Location = New System.Drawing.Point(73, 39)
      Me.PasswordTextBox.Name = "PasswordTextBox"
      Me.PasswordTextBox.PasswordChar = Global.Microsoft.VisualBasic.ChrW(42)
      Me.PasswordTextBox.Size = New System.Drawing.Size(206, 20)
      Me.PasswordTextBox.TabIndex = 9
      '
      'UsernameTextBox
      '
      Me.UsernameTextBox.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper
      Me.UsernameTextBox.Location = New System.Drawing.Point(73, 12)
      Me.UsernameTextBox.Name = "UsernameTextBox"
      Me.UsernameTextBox.Size = New System.Drawing.Size(206, 20)
      Me.UsernameTextBox.TabIndex = 8
      '
      'Login
      '
      Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
      Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
      Me.ClientSize = New System.Drawing.Size(291, 133)
      Me.Controls.Add(Me.CancelButton)
      Me.Controls.Add(Me.AcceptButton)
      Me.Controls.Add(Me.label3)
      Me.Controls.Add(Me.Label2)
      Me.Controls.Add(Me.Label1)
      Me.Controls.Add(Me.HostTextBox)
      Me.Controls.Add(Me.PasswordTextBox)
      Me.Controls.Add(Me.UsernameTextBox)
      Me.Name = "Login"
      Me.Text = "Login"
      Me.ResumeLayout(False)
      Me.PerformLayout()

   End Sub
   Friend WithEvents CancelButton As System.Windows.Forms.Button
   Friend WithEvents AcceptButton As System.Windows.Forms.Button
   Friend WithEvents label3 As System.Windows.Forms.Label
   Friend WithEvents Label2 As System.Windows.Forms.Label
   Friend WithEvents Label1 As System.Windows.Forms.Label
   Friend WithEvents HostTextBox As System.Windows.Forms.TextBox
   Friend WithEvents PasswordTextBox As System.Windows.Forms.TextBox
   Friend WithEvents UsernameTextBox As System.Windows.Forms.TextBox
End Class
