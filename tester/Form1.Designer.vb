<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
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
        Dim ChartArea1 As System.Windows.Forms.DataVisualization.Charting.ChartArea = New System.Windows.Forms.DataVisualization.Charting.ChartArea()
        Dim Legend1 As System.Windows.Forms.DataVisualization.Charting.Legend = New System.Windows.Forms.DataVisualization.Charting.Legend()
        Dim Series1 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.btnDemosaic = New System.Windows.Forms.Button()
        Me.btnLowLight = New System.Windows.Forms.Button()
        Me.btnAbs = New System.Windows.Forms.Button()
        Me.btnAbsDiff = New System.Windows.Forms.Button()
        Me.Button5 = New System.Windows.Forms.Button()
        Me.btnAdd = New System.Windows.Forms.Button()
        Me.btnFFT = New System.Windows.Forms.Button()
        Me.btnHistogram = New System.Windows.Forms.Button()
        Me.Chart1 = New System.Windows.Forms.DataVisualization.Charting.Chart()
        Me.btnCbrt = New System.Windows.Forms.Button()
        Me.btnNOT = New System.Windows.Forms.Button()
        Me.btnAND = New System.Windows.Forms.Button()
        Me.btnAutoColor = New System.Windows.Forms.Button()
        Me.btnMultiply = New System.Windows.Forms.Button()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.tbMultScalar = New System.Windows.Forms.TextBox()
        Me.Button2 = New System.Windows.Forms.Button()
        Me.Button3 = New System.Windows.Forms.Button()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Chart1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'PictureBox1
        '
        Me.PictureBox1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.PictureBox1.Cursor = System.Windows.Forms.Cursors.Arrow
        Me.PictureBox1.Location = New System.Drawing.Point(35, 41)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(929, 539)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.PictureBox1.TabIndex = 0
        Me.PictureBox1.TabStop = False
        '
        'btnDemosaic
        '
        Me.btnDemosaic.Location = New System.Drawing.Point(1056, 41)
        Me.btnDemosaic.Name = "btnDemosaic"
        Me.btnDemosaic.Size = New System.Drawing.Size(75, 23)
        Me.btnDemosaic.TabIndex = 1
        Me.btnDemosaic.Text = "Demosaic"
        Me.btnDemosaic.UseVisualStyleBackColor = True
        '
        'btnLowLight
        '
        Me.btnLowLight.Location = New System.Drawing.Point(1056, 70)
        Me.btnLowLight.Name = "btnLowLight"
        Me.btnLowLight.Size = New System.Drawing.Size(75, 23)
        Me.btnLowLight.TabIndex = 2
        Me.btnLowLight.Text = "Low Light"
        Me.btnLowLight.UseVisualStyleBackColor = True
        '
        'btnAbs
        '
        Me.btnAbs.Location = New System.Drawing.Point(1056, 99)
        Me.btnAbs.Name = "btnAbs"
        Me.btnAbs.Size = New System.Drawing.Size(75, 23)
        Me.btnAbs.TabIndex = 3
        Me.btnAbs.Text = "Abs"
        Me.btnAbs.UseVisualStyleBackColor = True
        '
        'btnAbsDiff
        '
        Me.btnAbsDiff.Location = New System.Drawing.Point(1056, 128)
        Me.btnAbsDiff.Name = "btnAbsDiff"
        Me.btnAbsDiff.Size = New System.Drawing.Size(75, 23)
        Me.btnAbsDiff.TabIndex = 4
        Me.btnAbsDiff.Text = "AbsDiff"
        Me.btnAbsDiff.UseVisualStyleBackColor = True
        '
        'Button5
        '
        Me.Button5.Location = New System.Drawing.Point(1152, 680)
        Me.Button5.Name = "Button5"
        Me.Button5.Size = New System.Drawing.Size(75, 23)
        Me.Button5.TabIndex = 5
        Me.Button5.Text = "Reload"
        Me.Button5.UseVisualStyleBackColor = True
        '
        'btnAdd
        '
        Me.btnAdd.Location = New System.Drawing.Point(1206, 41)
        Me.btnAdd.Name = "btnAdd"
        Me.btnAdd.Size = New System.Drawing.Size(75, 23)
        Me.btnAdd.TabIndex = 6
        Me.btnAdd.Text = "Add"
        Me.btnAdd.UseVisualStyleBackColor = True
        '
        'btnFFT
        '
        Me.btnFFT.BackColor = System.Drawing.SystemColors.ActiveCaption
        Me.btnFFT.Location = New System.Drawing.Point(1206, 70)
        Me.btnFFT.Name = "btnFFT"
        Me.btnFFT.Size = New System.Drawing.Size(75, 23)
        Me.btnFFT.TabIndex = 7
        Me.btnFFT.Text = "FFT"
        Me.btnFFT.UseVisualStyleBackColor = False
        '
        'btnHistogram
        '
        Me.btnHistogram.Location = New System.Drawing.Point(1056, 157)
        Me.btnHistogram.Name = "btnHistogram"
        Me.btnHistogram.Size = New System.Drawing.Size(75, 23)
        Me.btnHistogram.TabIndex = 9
        Me.btnHistogram.Text = "Histogram"
        Me.btnHistogram.UseVisualStyleBackColor = True
        '
        'Chart1
        '
        ChartArea1.Name = "ChartArea1"
        Me.Chart1.ChartAreas.Add(ChartArea1)
        Legend1.Name = "Legend1"
        Me.Chart1.Legends.Add(Legend1)
        Me.Chart1.Location = New System.Drawing.Point(994, 353)
        Me.Chart1.Name = "Chart1"
        Series1.ChartArea = "ChartArea1"
        Series1.Legend = "Legend1"
        Series1.Name = "Series1"
        Me.Chart1.Series.Add(Series1)
        Me.Chart1.Size = New System.Drawing.Size(301, 286)
        Me.Chart1.TabIndex = 10
        Me.Chart1.Text = "Chart1"
        '
        'btnCbrt
        '
        Me.btnCbrt.BackColor = System.Drawing.SystemColors.ControlLight
        Me.btnCbrt.Location = New System.Drawing.Point(1206, 99)
        Me.btnCbrt.Name = "btnCbrt"
        Me.btnCbrt.Size = New System.Drawing.Size(75, 23)
        Me.btnCbrt.TabIndex = 11
        Me.btnCbrt.Text = "cbrt"
        Me.btnCbrt.UseVisualStyleBackColor = False
        '
        'btnNOT
        '
        Me.btnNOT.Location = New System.Drawing.Point(1206, 128)
        Me.btnNOT.Name = "btnNOT"
        Me.btnNOT.Size = New System.Drawing.Size(75, 23)
        Me.btnNOT.TabIndex = 12
        Me.btnNOT.Text = "NOT"
        Me.btnNOT.UseVisualStyleBackColor = True
        '
        'btnAND
        '
        Me.btnAND.Location = New System.Drawing.Point(1206, 157)
        Me.btnAND.Name = "btnAND"
        Me.btnAND.Size = New System.Drawing.Size(75, 23)
        Me.btnAND.TabIndex = 13
        Me.btnAND.Text = "AND"
        Me.btnAND.UseVisualStyleBackColor = True
        '
        'btnAutoColor
        '
        Me.btnAutoColor.Location = New System.Drawing.Point(1206, 324)
        Me.btnAutoColor.Name = "btnAutoColor"
        Me.btnAutoColor.Size = New System.Drawing.Size(75, 23)
        Me.btnAutoColor.TabIndex = 14
        Me.btnAutoColor.Text = "AutoColor"
        Me.btnAutoColor.UseVisualStyleBackColor = True
        '
        'btnMultiply
        '
        Me.btnMultiply.Location = New System.Drawing.Point(1056, 186)
        Me.btnMultiply.Name = "btnMultiply"
        Me.btnMultiply.Size = New System.Drawing.Size(75, 23)
        Me.btnMultiply.TabIndex = 15
        Me.btnMultiply.Text = "Multiply"
        Me.btnMultiply.UseVisualStyleBackColor = True
        '
        'Button1
        '
        Me.Button1.BackColor = System.Drawing.SystemColors.ControlLight
        Me.Button1.Location = New System.Drawing.Point(1056, 215)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(75, 23)
        Me.Button1.TabIndex = 16
        Me.Button1.Text = "Multiply by"
        Me.Button1.UseVisualStyleBackColor = False
        '
        'tbMultScalar
        '
        Me.tbMultScalar.Location = New System.Drawing.Point(1137, 217)
        Me.tbMultScalar.Name = "tbMultScalar"
        Me.tbMultScalar.Size = New System.Drawing.Size(49, 20)
        Me.tbMultScalar.TabIndex = 17
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(1056, 244)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(75, 23)
        Me.Button2.TabIndex = 18
        Me.Button2.Text = "Divide"
        Me.Button2.UseVisualStyleBackColor = True
        '
        'Button3
        '
        Me.Button3.Location = New System.Drawing.Point(1056, 273)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(75, 23)
        Me.Button3.TabIndex = 19
        Me.Button3.Text = "Exp"
        Me.Button3.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1307, 734)
        Me.Controls.Add(Me.Button3)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.tbMultScalar)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.btnMultiply)
        Me.Controls.Add(Me.btnAutoColor)
        Me.Controls.Add(Me.btnAND)
        Me.Controls.Add(Me.btnNOT)
        Me.Controls.Add(Me.btnCbrt)
        Me.Controls.Add(Me.Chart1)
        Me.Controls.Add(Me.btnHistogram)
        Me.Controls.Add(Me.btnFFT)
        Me.Controls.Add(Me.btnAdd)
        Me.Controls.Add(Me.Button5)
        Me.Controls.Add(Me.btnAbsDiff)
        Me.Controls.Add(Me.btnAbs)
        Me.Controls.Add(Me.btnLowLight)
        Me.Controls.Add(Me.btnDemosaic)
        Me.Controls.Add(Me.PictureBox1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Chart1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents PictureBox1 As PictureBox
    Friend WithEvents btnDemosaic As Button
    Friend WithEvents btnLowLight As Button
    Friend WithEvents btnAbs As Button
    Friend WithEvents btnAbsDiff As Button
    Friend WithEvents Button5 As Button
    Friend WithEvents btnAdd As Button
    Friend WithEvents btnFFT As Button
    Friend WithEvents btnHistogram As Button
    Friend WithEvents Chart1 As DataVisualization.Charting.Chart
    Friend WithEvents btnCbrt As Button
    Friend WithEvents btnNOT As Button
    Friend WithEvents btnAND As Button
    Friend WithEvents btnAutoColor As Button
    Friend WithEvents btnMultiply As Button
    Friend WithEvents Button1 As Button
    Friend WithEvents tbMultScalar As TextBox
    Friend WithEvents Button2 As Button
    Friend WithEvents Button3 As Button
End Class
