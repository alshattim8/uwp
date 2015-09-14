'----------------------------------------------------------------------
'  Name:    John W Hunter, Andre Fugure
'  Project: CS3630 Phase IV
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
   Private Shared frmLogin As New Login()
   Private Shared frmDisplay As New Display()
   Friend Shared myOracleDataAdapterStaff As New System.Data.OracleClient.OracleDataAdapter
   Friend Shared myOracleCommandStaff As New System.Data.OracleClient.OracleCommand
   Friend Shared myOracleConnection As New System.Data.OracleClient.OracleConnection
   Friend Shared myOracleCommandBuilderStaff As System.Data.OracleClient.OracleCommandBuilder
   Friend Shared myOracleDataAdapterExp As New System.Data.OracleClient.OracleDataAdapter
   Friend Shared myOracleCommandExp As New System.Data.OracleClient.OracleCommand
   Friend Shared myOracleCommandBuilderExp As System.Data.OracleClient.OracleCommandBuilder
   Friend Shared myOracleDataAdapterQual As New System.Data.OracleClient.OracleDataAdapter
   Friend Shared myOracleCommandQual As New System.Data.OracleClient.OracleCommand
   Friend Shared myOracleCommandBuilderQual As System.Data.OracleClient.OracleCommandBuilder
   Friend Shared uwpstaff As New System.Data.DataTable("UWP_STAFF")
   Friend Shared uwpworkexp As New System.Data.DataTable("UWP_WorkExperience")
   Friend Shared uwpqual As New System.Data.DataTable("UWP_Qualifications")

   Public Shared Sub LogInAtRunTime()

      myOracleConnection.ConnectionString = "user id=" & UserName & ";data source=" & Server & _
                                            ";password=" & PassWd & ";persist security info=False"
      myOracleCommandStaff.CommandType = CommandType.Text
      myOracleCommandStaff.CommandText = "Select * from UWP_Staff"
      myOracleCommandStaff.Connection = myOracleConnection
      myOracleDataAdapterStaff.SelectCommand = myOracleCommandStaff
      myOracleCommandBuilderStaff = New System.Data.OracleClient.OracleCommandBuilder(myOracleDataAdapterStaff)
      myOracleDataAdapterStaff.Fill(uwpstaff)

      myOracleCommandExp.CommandType = CommandType.Text
      myOracleCommandExp.CommandText = "Select * from UWP_WorkExperience"
      myOracleCommandExp.Connection = myOracleConnection
      myOracleDataAdapterExp.SelectCommand = myOracleCommandExp
      myOracleCommandBuilderExp = New System.Data.OracleClient.OracleCommandBuilder(myOracleDataAdapterExp)
      myOracleDataAdapterExp.Fill(uwpworkexp)

      myOracleCommandQual.CommandType = CommandType.Text
      myOracleCommandQual.CommandText = "Select * from UWP_Qualifications"
      myOracleCommandQual.Connection = myOracleConnection
      myOracleDataAdapterQual.SelectCommand = myOracleCommandQual
      myOracleCommandBuilderQual = New System.Data.OracleClient.OracleCommandBuilder(myOracleDataAdapterQual)
      myOracleDataAdapterQual.Fill(uwpqual)
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
         Application.Run(frmDisplay)
      End If
   End Sub

End Class
