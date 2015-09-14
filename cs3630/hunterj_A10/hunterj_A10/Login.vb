'----------------------------------------------------------------------
'  Name:    John W Hunter, Andre Fugure
'  Project: CS3630 Assignment 10
'  Purpose: Login form
'----------------------------------------------------------------------

Public Class Login
   Private Sub Button1_Click(sender As Object, e As EventArgs) Handles AcceptButton.Click
      Oracle.UserName = UsernameTextBox.Text()
      Oracle.PassWd = PasswordTextBox.Text()
      Oracle.Server = HostTextBox.Text()
      Oracle.Result = ResponseType.OK
      Me.Close()
   End Sub

   Private Sub Button2_Click(sender As Object, e As EventArgs) Handles CancelButton.Click
      Oracle.Result = ResponseType.Cancel
      Me.Close()
   End Sub

End Class
