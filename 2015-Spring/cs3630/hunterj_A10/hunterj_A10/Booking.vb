'----------------------------------------------------------------------
'  Name:    John W Hunter, Andre Fugure
'  Project: CS3630 Assignment 10
'  Purpose: Booking form
'----------------------------------------------------------------------

Public Class Booking
   Friend command As String

   Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
      DataGridView1.DataSource = Oracle.myTable
      FieldComboBox.SelectedIndex = 0
      OperatorComboBox.SelectedIndex = 0
   End Sub

   Private Sub Button1_Click(sender As Object, e As EventArgs) Handles UpdateButton.Click
      Try
         Me.BindingContext(Oracle.myTable).EndCurrentEdit()
         Oracle.myOracleDataAdapter.Update(Oracle.myTable)
      Catch ex As Exception
         MessageBox.Show(ex.Message)
      End Try
   End Sub

   Private Sub Button2_Click(sender As Object, e As EventArgs) Handles SearchButton.Click
      If FieldComboBox.Text = "Date_From" Or FieldComboBox.Text = "Date_To" Then
         Oracle.myOracleCommand.CommandText = _
            "Select * " & _
            "From Booking " & _
            "Where " & FieldComboBox.Text & OperatorComboBox.Text & _
            "to_Date('" & RequestTextBox.Text & "', 'mm/dd/yyyy')"
      Else
         Oracle.myOracleCommand.CommandText = _
            "Select * " & _
            "From Booking " & _
            "Where " & FieldComboBox.Text & OperatorComboBox.Text & " '" & RequestTextBox.Text & "'"
      End If
      Try
         Oracle.myTable.Clear()
         Oracle.myOracleDataAdapter.Fill(Oracle.myTable)
      Catch ex As Exception
         MsgBox(ex.Message)
      End Try
   End Sub

   Private Sub Button3_Click(sender As Object, e As EventArgs) Handles AllButton.Click
      Oracle.myOracleCommand.CommandText = "Select * from booking"
      Try
         Oracle.myTable.Clear()
         Oracle.myOracleDataAdapter.Fill(Oracle.myTable)
      Catch ex As Exception
         MsgBox(ex.Message)
      End Try
   End Sub

   Private Sub Button4_Click(sender As Object, e As EventArgs) Handles ExitButton.Click
      Me.Close()
   End Sub

End Class