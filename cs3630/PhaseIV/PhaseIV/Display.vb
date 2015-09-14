Public Class Display

   Private staffBindingSource As New BindingSource()
   Private expBindingSource As New BindingSource()
   Private qualBindingSource As New BindingSource()

   Private staffDataView As New DataView()
   Private qualDataView As New DataView()
   Private expDataView As New DataView()

   Private Sub Display_Load(sender As Object, e As EventArgs) Handles MyBase.Load

      dob.Format = DateTimePickerFormat.Custom
      qualdate.Format = DateTimePickerFormat.Custom
      finishdate.Format = DateTimePickerFormat.Custom
      startdate.Format = DateTimePickerFormat.Custom
      dob.CustomFormat = "MM / dd / yyyy"
      qualdate.CustomFormat = "MM / dd / yyyy"
      finishdate.CustomFormat = "MM / dd / yyyy"
      startdate.CustomFormat = "MM / dd / yyyy"

      staffDataView = New DataView(Oracle.uwpstaff)
      staffBindingSource.DataSource = staffDataView
      qualDataView = New DataView(Oracle.uwpqual)
      qualBindingSource.DataSource = qualDataView
      expDataView = New DataView(Oracle.uwpworkexp)
      expBindingSource.DataSource = expDataView

      staffno.DataBindings.Add("Text", staffBindingSource, "staffNo")
      fname.DataBindings.Add("Text", staffBindingSource, "fName")
      lname.DataBindings.Add("Text", staffBindingSource, "lName")
      street.DataBindings.Add("Text", staffBindingSource, "street")
      city.DataBindings.Add("Text", staffBindingSource, "city")
      state.DataBindings.Add("Text", staffBindingSource, "state")
      zip.DataBindings.Add("Text", staffBindingSource, "zip")
      phone.DataBindings.Add("Text", staffBindingSource, "phone")
      dob.DataBindings.Add("Value", staffBindingSource, "DOB")
      gender.DataBindings.Add("Text", staffBindingSource, "gender")
      nin.DataBindings.Add("Text", staffBindingSource, "NIN")
      position.DataBindings.Add("Text", staffBindingSource, "position")
      cursalary.DataBindings.Add("Text", staffBindingSource, "curSalary")
      salaryscale.DataBindings.Add("Text", staffBindingSource, "salaryScale")
      hrsperweek.DataBindings.Add("Text", staffBindingSource, "hrsPerWk")
      pospermtemp.DataBindings.Add("Text", staffBindingSource, "posPermTemp")
      typeofpay.DataBindings.Add("Text", staffBindingSource, "typeOfPay")


      'qualDataView.RowFilter = "STAFFNO = '" & staffno.Text & "'"
      qualdate.DataBindings.Add("Value", qualBindingSource, "qualDate")
      type.DataBindings.Add("Text", qualBindingSource, "type")
      instname.DataBindings.Add("Text", qualBindingSource, "instName")



      'expDataView.RowFilter = "STAFFNO = '" & staffno.Text & "'"
      orgname.DataBindings.Add("Text", expBindingSource, "orgName")
      exp_position.DataBindings.Add("Text", expBindingSource, "position")
      startdate.DataBindings.Add("Value", expBindingSource, "startDate")
      finishdate.DataBindings.Add("Value", expBindingSource, "finishDate")

      expPosChange()
      qualPosChange()
      staffPosChange()

   End Sub

   Private Sub staffFirst_Click(sender As Object, e As EventArgs) Handles staffFirst.Click
      staffBindingSource.MoveFirst()
      staffPosChange()
   End Sub

   Private Sub staffPrev_Click(sender As Object, e As EventArgs) Handles staffPrev.Click
      staffBindingSource.MovePrevious()
      staffPosChange()
   End Sub

   Private Sub staffNext_Click(sender As Object, e As EventArgs) Handles staffNext.Click
      staffBindingSource.MoveNext()
      staffPosChange()
   End Sub

   Private Sub staffLast_Click(sender As Object, e As EventArgs) Handles staffLast.Click
      staffBindingSource.MoveLast()
      staffPosChange()
   End Sub

   Private Sub staffNew_Click(sender As Object, e As EventArgs) Handles staffNew.Click
      Dim r As DataRow
      r = Oracle.uwpstaff.NewRow
      For index As Integer = 0 To 16
         If index = 8 Then
            r(8) = DateTime.Now.ToString()
         ElseIf index = 12 Or index = 13 Or index = 14 Then
            r(index) = 0
         Else
            r(index) = ""
         End If
      Next
      Oracle.uwpstaff.Rows.Add(r)
      staffBindingSource.MoveLast()
      staffPos.Text = (staffBindingSource.Position + 1) & "/" & staffBindingSource.Count
      disableAllButtons()
      staffSave.Enabled = True
      staffDelete.Enabled = True
   End Sub

   Private Sub staffSave_Click(sender As Object, e As EventArgs) Handles staffSave.Click
      Try
         staffBindingSource.EndEdit()
         Oracle.myOracleDataAdapterStaff.Update(Oracle.uwpstaff)
      Catch ex As Exception
         MessageBox.Show(ex.Message)
      End Try
      enableAllButtons()

   End Sub

   Private Sub staffDelete_Click(sender As Object, e As EventArgs) Handles staffDelete.Click
      Try
         staffBindingSource.RemoveCurrent()
         staffPosChange()
      Catch ex As Exception
         MessageBox.Show(ex.Message)
      End Try
      enableAllButtons()

   End Sub

   Private Sub staffPosChange()
      staffPos.Text = (staffBindingSource.Position + 1) & "/" & staffBindingSource.Count
      staffFirst.Enabled = False
      staffPrev.Enabled = False
      staffLast.Enabled = False
      staffNext.Enabled = False
      If staffBindingSource.Count > 1 Then
         If staffBindingSource.Position = 0 Then
            staffLast.Enabled = True
            staffNext.Enabled = True
         ElseIf Not staffBindingSource.Position = (staffBindingSource.Count - 1) Then
            staffFirst.Enabled = True
            staffPrev.Enabled = True
            staffLast.Enabled = True
            staffNext.Enabled = True
         Else
            staffFirst.Enabled = True
            staffPrev.Enabled = True
         End If
      End If
      qualPosChange()
      expPosChange()
   End Sub

   Private Sub qualFirst_Click(sender As Object, e As EventArgs) Handles qualFirst.Click
      qualBindingSource.MoveFirst()
      qualPosChange()
   End Sub

   Private Sub qualPrev_Click(sender As Object, e As EventArgs) Handles qualPrev.Click
      qualBindingSource.MovePrevious()
      qualPosChange()
   End Sub

   Private Sub qualNext_Click(sender As Object, e As EventArgs) Handles qualNext.Click
      qualBindingSource.MoveNext()
      qualPosChange()
   End Sub

   Private Sub qualLast_Click(sender As Object, e As EventArgs) Handles qualLast.Click
      qualBindingSource.MoveLast()
      qualPosChange()
   End Sub

   Private Sub qualNew_Click(sender As Object, e As EventArgs) Handles qualNew.Click
      Dim r As DataRow
      r = Oracle.uwpqual.NewRow
      r(0) = staffno.Text
      r(1) = DateTime.Now.ToString()
      r(2) = ""
      r(3) = ""
      Oracle.uwpqual.Rows.Add(r)
      qualBindingSource.MoveLast()
      qualPos.Text = (qualBindingSource.Position + 1) & "/" & qualBindingSource.Count
      disableAllButtons()
      qualSave.Enabled = True
      qualDelete.Enabled = True

   End Sub

   Private Sub qualSave_Click(sender As Object, e As EventArgs) Handles qualSave.Click
      Try
         qualBindingSource.EndEdit()
         Oracle.myOracleDataAdapterQual.Update(Oracle.uwpqual)
      Catch ex As Exception
         MessageBox.Show(ex.Message)
      End Try
      enableAllButtons()
   End Sub

   Private Sub qualDelete_Click(sender As Object, e As EventArgs) Handles qualDelete.Click
      Try
         qualBindingSource.RemoveCurrent()
         qualPosChange()
      Catch ex As Exception
         MessageBox.Show(ex.Message)
      End Try
      enableAllButtons()

   End Sub

   Private Sub qualPosChange()
      qualDataView.RowFilter = "STAFFNO = '" & staffno.Text & "'"

      qualdate.Value = DateTime.Now
      qualdate.DataBindings.Clear()

      qualdate.DataBindings.Add("Value", qualBindingSource, "QUALDATE")

      qualBindingSource.ResumeBinding()
      qualPos.Text = (qualBindingSource.Position + 1) & "/" & qualBindingSource.Count
      qualFirst.Enabled = False
      qualPrev.Enabled = False
      qualLast.Enabled = False
      qualNext.Enabled = False
      If qualBindingSource.Count > 1 Then
         If qualBindingSource.Position = 0 Then
            qualLast.Enabled = True
            qualNext.Enabled = True
         ElseIf Not qualBindingSource.Position = qualBindingSource.Count - 1 Then
            qualLast.Enabled = True
            qualNext.Enabled = True
            qualFirst.Enabled = True
            qualPrev.Enabled = True
         Else
            qualFirst.Enabled = True
            qualPrev.Enabled = True
         End If
      End If

   End Sub

   Private Sub expFirst_Click(sender As Object, e As EventArgs) Handles expFirst.Click
      expBindingSource.MoveFirst()
      expPosChange()

   End Sub

   Private Sub expPrev_Click(sender As Object, e As EventArgs) Handles expPrev.Click
      expBindingSource.MovePrevious()
      expPosChange()

   End Sub

   Private Sub expNext_Click(sender As Object, e As EventArgs) Handles expNext.Click
      expBindingSource.MoveNext()
      expPosChange()

   End Sub

   Private Sub expLast_Click(sender As Object, e As EventArgs) Handles expLast.Click
      expBindingSource.MoveLast()
      expPosChange()

   End Sub

   Private Sub expNew_Click(sender As Object, e As EventArgs) Handles expNew.Click
      Dim r As DataRow
      r = Oracle.uwpworkexp.NewRow()
      r(0) = staffno.Text
      r(1) = ""
      r(2) = ""
      r(3) = DateTime.Now.ToString()
      r(4) = DateTime.Now.ToString()
      Oracle.uwpworkexp.Rows.Add(r)
      expBindingSource.MoveLast()
      expPos.Text = (expBindingSource.Position + 1) & "/" & expBindingSource.Count
      disableAllButtons()
      expSave.Enabled = True
      expDelete.Enabled = True

   End Sub

   Private Sub expSave_Click(sender As Object, e As EventArgs) Handles expSave.Click
      Try
         expBindingSource.EndEdit()
         Oracle.myOracleDataAdapterExp.Update(Oracle.uwpworkexp)
      Catch ex As Exception
         MessageBox.Show(ex.Message)
      End Try
      enableAllButtons()

   End Sub

   Private Sub expDelete_Click(sender As Object, e As EventArgs) Handles expDelete.Click
      Try
         expBindingSource.RemoveCurrent()
         expPosChange()
      Catch ex As Exception
         MessageBox.Show(ex.Message)
      End Try
      enableAllButtons()

   End Sub

   Private Sub expPosChange()
      expDataView.RowFilter = "STAFFNO = '" & staffno.Text & "'"

      startdate.Value = DateTime.Now
      finishdate.Value = DateTime.Now
      startdate.DataBindings.Clear()
      finishdate.DataBindings.Clear()
      startdate.DataBindings.Add("Value", expBindingSource, "STARTDATE")
      finishdate.DataBindings.Add("Value", expBindingSource, "FINISHDATE")
      expBindingSource.ResumeBinding()

      expPos.Text = (expBindingSource.Position + 1) & "/" & expBindingSource.Count

      expFirst.Enabled = False
      expPrev.Enabled = False
      expLast.Enabled = False
      expNext.Enabled = False
      If expBindingSource.Count > 1 Then
         If expBindingSource.Position = 0 Then
            expLast.Enabled = True
            expNext.Enabled = True
         ElseIf Not expBindingSource.Position = expBindingSource.Count - 1 Then
            expFirst.Enabled = True
            expPrev.Enabled = True
            expLast.Enabled = True
            expNext.Enabled = True
         Else
            expFirst.Enabled = True
            expPrev.Enabled = True
         End If
      End If

   End Sub

   Private Sub Button24_Click(sender As Object, e As EventArgs) Handles Button24.Click
      Me.Close()
   End Sub

   Private Sub Button22_Click(sender As Object, e As EventArgs) Handles allButton.Click
      Try
         Oracle.myOracleCommandStaff.CommandText = "Select * from UWP_Staff"

         dob.Value = DateTime.Now
         dob.DataBindings.Clear()
         dob.DataBindings.Add("Value", staffBindingSource, "DOB")
         Oracle.uwpstaff.Clear()
         staffBindingSource.ResumeBinding()
         Oracle.myOracleDataAdapterStaff.Fill(Oracle.uwpstaff)
         staffPosChange()
         qualPosChange()
         expPosChange()

      Catch ex As Exception
         MessageBox.Show(ex.Message)
      End Try
   End Sub

   Private Sub Button23_Click(sender As Object, e As EventArgs) Handles searchButton.Click
      If Not searchField.SelectedIndex = 0 Then
         Try
            Oracle.myOracleCommandStaff.CommandText = "Select Distinct S.* from UWP_STAFF S, UWP_WORKEXPERIENCE E where S.STAFFNO = E.STAFFNO and E.ORGNAME = '" & searchValue.Text & "'"
            Oracle.uwpstaff.Clear()
            Oracle.myOracleDataAdapterStaff.Fill(Oracle.uwpstaff)
         Catch ex As Exception
            MessageBox.Show(ex.Message)
         End Try
      Else
         Try
            Oracle.myOracleCommandStaff.CommandText = "Select DISTINCT S.* from UWP_STAFF S, UWP_QUALIFICATIONS Q where S.STAFFNO = Q.STAFFNO and Q.TYPE = '" & searchValue.Text & "'"
            Oracle.uwpstaff.Clear()
            Oracle.myOracleDataAdapterStaff.Fill(Oracle.uwpstaff)
         Catch ex As Exception
            MessageBox.Show(ex.Message)
         End Try
      End If
      dob.Value = DateTime.Now
      dob.DataBindings.Clear()
      dob.DataBindings.Add("Value", staffBindingSource, "DOB")

      Oracle.uwpstaff.Clear()
      staffBindingSource.ResumeBinding()
      Oracle.myOracleDataAdapterStaff.Fill(Oracle.uwpstaff)
      staffPosChange()
      qualPosChange()
      expPosChange()


   End Sub

   Private Sub disableAllButtons()
      staffFirst.Enabled = False
      staffPrev.Enabled = False
      staffNext.Enabled = False
      staffLast.Enabled = False
      staffNew.Enabled = False
      staffSave.Enabled = False
      staffDelete.Enabled = False
      qualFirst.Enabled = False
      qualPrev.Enabled = False
      qualNext.Enabled = False
      qualDelete.Enabled = False
      qualNew.Enabled = False
      qualSave.Enabled = False
      qualDelete.Enabled = False
      expFirst.Enabled = False
      expPrev.Enabled = False
      expNext.Enabled = False
      expLast.Enabled = False
      expNew.Enabled = False
      expSave.Enabled = False
      expDelete.Enabled = False
      allButton.Enabled = False
      searchButton.Enabled = False

   End Sub

   Private Sub enableAllButtons()
      staffFirst.Enabled = True
      staffPrev.Enabled = True
      staffNext.Enabled = True
      staffLast.Enabled = True
      staffNew.Enabled = True
      staffSave.Enabled = True
      staffDelete.Enabled = True
      qualFirst.Enabled = True
      qualPrev.Enabled = True
      qualNext.Enabled = True
      qualDelete.Enabled = True
      qualNew.Enabled = True
      qualSave.Enabled = True
      qualDelete.Enabled = True
      expFirst.Enabled = True
      expPrev.Enabled = True
      expNext.Enabled = True
      expLast.Enabled = True
      expNew.Enabled = True
      expSave.Enabled = True
      expDelete.Enabled = True
      allButton.Enabled = True
      searchButton.Enabled = True
      staffPosChange()
      qualPosChange()
      expPosChange()

   End Sub

End Class