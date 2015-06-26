<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Booking
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
      Me.DataGridView1 = New System.Windows.Forms.DataGridView()
      Me.UpdateButton = New System.Windows.Forms.Button()
      Me.SearchButton = New System.Windows.Forms.Button()
      Me.AllButton = New System.Windows.Forms.Button()
      Me.ExitButton = New System.Windows.Forms.Button()
      Me.FieldComboBox = New System.Windows.Forms.ComboBox()
      Me.OperatorComboBox = New System.Windows.Forms.ComboBox()
      Me.RequestTextBox = New System.Windows.Forms.TextBox()
      CType(Me.DataGridView1, System.ComponentModel.ISupportInitialize).BeginInit()
      Me.SuspendLayout()
      '
      'DataGridView1
      '
      Me.DataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize
      Me.DataGridView1.Location = New System.Drawing.Point(12, 12)
      Me.DataGridView1.Name = "DataGridView1"
      Me.DataGridView1.Size = New System.Drawing.Size(599, 389)
      Me.DataGridView1.TabIndex = 0
      '
      'UpdateButton
      '
      Me.UpdateButton.Location = New System.Drawing.Point(617, 12)
      Me.UpdateButton.Name = "UpdateButton"
      Me.UpdateButton.Size = New System.Drawing.Size(75, 23)
      Me.UpdateButton.TabIndex = 1
      Me.UpdateButton.Text = "Update"
      Me.UpdateButton.UseVisualStyleBackColor = True
      '
      'SearchButton
      '
      Me.SearchButton.Location = New System.Drawing.Point(536, 407)
      Me.SearchButton.Name = "SearchButton"
      Me.SearchButton.Size = New System.Drawing.Size(75, 23)
      Me.SearchButton.TabIndex = 2
      Me.SearchButton.Text = "Search"
      Me.SearchButton.UseVisualStyleBackColor = True
      '
      'AllButton
      '
      Me.AllButton.Location = New System.Drawing.Point(617, 41)
      Me.AllButton.Name = "AllButton"
      Me.AllButton.Size = New System.Drawing.Size(75, 23)
      Me.AllButton.TabIndex = 3
      Me.AllButton.Text = "All"
      Me.AllButton.UseVisualStyleBackColor = True
      '
      'ExitButton
      '
      Me.ExitButton.Location = New System.Drawing.Point(617, 70)
      Me.ExitButton.Name = "ExitButton"
      Me.ExitButton.Size = New System.Drawing.Size(75, 23)
      Me.ExitButton.TabIndex = 4
      Me.ExitButton.Text = "Exit"
      Me.ExitButton.UseVisualStyleBackColor = True
      '
      'FieldComboBox
      '
      Me.FieldComboBox.FormattingEnabled = True
      Me.FieldComboBox.Items.AddRange(New Object() {"Hotel_No", "Room_No", "Guest_No", "Date_From", "Date_To"})
      Me.FieldComboBox.Location = New System.Drawing.Point(12, 409)
      Me.FieldComboBox.Name = "FieldComboBox"
      Me.FieldComboBox.Size = New System.Drawing.Size(121, 21)
      Me.FieldComboBox.TabIndex = 5
      '
      'OperatorComboBox
      '
      Me.OperatorComboBox.FormattingEnabled = True
      Me.OperatorComboBox.Items.AddRange(New Object() {"=", ">", ">=", "<", "<="})
      Me.OperatorComboBox.Location = New System.Drawing.Point(139, 409)
      Me.OperatorComboBox.Name = "OperatorComboBox"
      Me.OperatorComboBox.Size = New System.Drawing.Size(121, 21)
      Me.OperatorComboBox.TabIndex = 6
      '
      'RequestTextBox
      '
      Me.RequestTextBox.Location = New System.Drawing.Point(266, 409)
      Me.RequestTextBox.Name = "RequestTextBox"
      Me.RequestTextBox.Size = New System.Drawing.Size(264, 20)
      Me.RequestTextBox.TabIndex = 7
      '
      'Booking
      '
      Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
      Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
      Me.ClientSize = New System.Drawing.Size(704, 442)
      Me.Controls.Add(Me.RequestTextBox)
      Me.Controls.Add(Me.OperatorComboBox)
      Me.Controls.Add(Me.FieldComboBox)
      Me.Controls.Add(Me.ExitButton)
      Me.Controls.Add(Me.AllButton)
      Me.Controls.Add(Me.SearchButton)
      Me.Controls.Add(Me.UpdateButton)
      Me.Controls.Add(Me.DataGridView1)
      Me.Name = "Booking"
      Me.Text = "CS3630 (hunterj && fugerea)"
      CType(Me.DataGridView1, System.ComponentModel.ISupportInitialize).EndInit()
      Me.ResumeLayout(False)
      Me.PerformLayout()

   End Sub
   Friend WithEvents DataGridView1 As System.Windows.Forms.DataGridView
   Friend WithEvents UpdateButton As System.Windows.Forms.Button
   Friend WithEvents SearchButton As System.Windows.Forms.Button
   Friend WithEvents AllButton As System.Windows.Forms.Button
   Friend WithEvents ExitButton As System.Windows.Forms.Button
   Friend WithEvents FieldComboBox As System.Windows.Forms.ComboBox
   Friend WithEvents OperatorComboBox As System.Windows.Forms.ComboBox
   Friend WithEvents RequestTextBox As System.Windows.Forms.TextBox
End Class
