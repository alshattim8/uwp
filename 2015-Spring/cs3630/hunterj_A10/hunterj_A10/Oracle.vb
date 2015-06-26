'----------------------------------------------------------------------
'  Name:    John W Hunter, Andre Fugure
'  Project: CS3630 Assignment 10
'  Purpose: Oracle class
'----------------------------------------------------------------------

Public Enum ResponseType
   OK
   Cancel
End Enum

Public Class Oracle
   Friend Shared UserName As String
   Friend Shared PassWd As String
   Friend Shared Server As String
   Friend Shared Result As ResponseType
   Private Shared frmLogin As New Login
   Private Shared frmBooking As New Booking
   Friend Shared myOracleDataAdapter As New System.Data.OracleClient.OracleDataAdapter
   Friend Shared myOracleCommand As New System.Data.OracleClient.OracleCommand
   Friend Shared myOracleConnection As New System.Data.OracleClient.OracleConnection
   Friend Shared myOracleCommandBuilder As System.Data.OracleClient.OracleCommandBuilder
   Friend Shared myTable As New System.Data.DataTable

   Public Shared Sub LogInAtRunTime()

      myOracleConnection.ConnectionString = "user id=" & UserName & ";data source=" & Server & _
                                            ";password=" & PassWd & ";persist security info=False"
      myOracleCommand.CommandType = CommandType.Text
      myOracleCommand.CommandText = "Select * from booking"
      myOracleCommand.Connection = myOracleConnection
      myOracleDataAdapter.SelectCommand = myOracleCommand
      myOracleCommandBuilder = New System.Data.OracleClient.OracleCommandBuilder(myOracleDataAdapter)
      myOracleDataAdapter.Fill(myTable)
   End Sub

   Public Shared Sub main()
      Dim good As Boolean
      While Not good
         frmLogin.ShowDialog()
         If Result = ResponseType.Cancel Then
            Exit While
         End If
         Try
            LogInAtRunTime()
            good = True
         Catch ex As Exception
            MessageBox.Show(ex.Message)
         End Try
      End While
      If good Then
         Application.Run(frmBooking)
      End If
   End Sub

End Class
