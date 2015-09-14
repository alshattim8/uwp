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
      Me.UsernameTextBox = New System.Windows.Forms.TextBox()
      Me.PasswordTextBox = New System.Windows.Forms.TextBox()
      Me.HostTextBox = New System.Windows.Forms.TextBox()
      Me.Label1 = New System.Windows.Forms.Label()
      Me.Label2 = New System.Windows.Forms.Label()
      Me.label3 = New System.Windows.Forms.Label()
      Me.AcceptButton = New System.Windows.Forms.Button()
      Me.CancelButton = New System.Windows.Forms.Button()
      Me.SuspendLayout()
      '
      'UsernameTextBox
      '
      Me.UsernameTextBox.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper
      Me.UsernameTextBox.Location = New System.Drawing.Point(213, 75)
      Me.UsernameTextBox.Name = "UsernameTextBox"
      Me.UsernameTextBox.Size = New System.Drawing.Size(100, 20)
      Me.UsernameTextBox.TabIndex = 0
      '
      'PasswordTextBox
      '
      Me.PasswordTextBox.Location = New System.Drawing.Point(213, 102)
      Me.PasswordTextBox.Name = "PasswordTextBox"
      Me.PasswordTextBox.PasswordChar = Global.Microsoft.VisualBasic.ChrW(42)
      Me.PasswordTextBox.Size = New System.Drawing.Size(100, 20)
      Me.PasswordTextBox.TabIndex = 1
      '
      'HostTextBox
      '
      Me.HostTextBox.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper
      Me.HostTextBox.Location = New System.Drawing.Point(213, 129)
      Me.HostTextBox.Name = "HostTextBox"
      Me.HostTextBox.Size = New System.Drawing.Size(100, 20)
      Me.HostTextBox.TabIndex = 2
      '
      'Label1
      '
      Me.Label1.AutoSize = True
      Me.Label1.Location = New System.Drawing.Point(152, 82)
      Me.Label1.Name = "Label1"
      Me.Label1.Size = New System.Drawing.Size(55, 13)
      Me.Label1.TabIndex = 3
      Me.Label1.Text = "Username"
      '
      'Label2
      '
      Me.Label2.AutoSize = True
      Me.Label2.Location = New System.Drawing.Point(154, 109)
      Me.Label2.Name = "Label2"
      Me.Label2.Size = New System.Drawing.Size(53, 13)
      Me.Label2.TabIndex = 4
      Me.Label2.Text = "Password"
      '
      'label3
      '
      Me.label3.AutoSize = True
      Me.label3.Location = New System.Drawing.Point(178, 136)
      Me.label3.Name = "label3"
      Me.label3.Size = New System.Drawing.Size(29, 13)
      Me.label3.TabIndex = 5
      Me.label3.Text = "Host"
      '
      'AcceptButton
      '
      Me.AcceptButton.Location = New System.Drawing.Point(213, 155)
      Me.AcceptButton.Name = "AcceptButton"
      Me.AcceptButton.Size = New System.Drawing.Size(100, 23)
      Me.AcceptButton.TabIndex = 6
      Me.AcceptButton.Text = "OK"
      Me.AcceptButton.UseVisualStyleBackColor = True
      '
      'CancelButton
      '
      Me.CancelButton.Location = New System.Drawing.Point(213, 184)
      Me.CancelButton.Name = "CancelButton"
      Me.CancelButton.Size = New System.Drawing.Size(100, 23)
      Me.CancelButton.TabIndex = 7
      Me.CancelButton.Text = "Cancel"
      Me.CancelButton.UseVisualStyleBackColor = True
      '
      'Login
      '
      Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
      Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
      Me.ClientSize = New System.Drawing.Size(464, 282)
      Me.Controls.Add(Me.CancelButton)
      Me.Controls.Add(Me.AcceptButton)
      Me.Controls.Add(Me.label3)
      Me.Controls.Add(Me.Label2)
      Me.Controls.Add(Me.Label1)
      Me.Controls.Add(Me.HostTextBox)
      Me.Controls.Add(Me.PasswordTextBox)
      Me.Controls.Add(Me.UsernameTextBox)
      Me.Name = "Login"
      Me.Text = "Login (hunterj && fugerea)"
      Me.ResumeLayout(False)
      Me.PerformLayout()

   End Sub
   Friend WithEvents UsernameTextBox As System.Windows.Forms.TextBox
   Friend WithEvents PasswordTextBox As System.Windows.Forms.TextBox
   Friend WithEvents HostTextBox As System.Windows.Forms.TextBox
   Friend WithEvents Label1 As System.Windows.Forms.Label
   Friend WithEvents Label2 As System.Windows.Forms.Label
   Friend WithEvents label3 As System.Windows.Forms.Label
   Friend WithEvents AcceptButton As System.Windows.Forms.Button
   Friend WithEvents CancelButton As System.Windows.Forms.Button

End Class
