Imports cuviLib
Imports System.Drawing.Imaging
Imports System.Runtime.InteropServices
Public Class Form1
    Dim cuviColor As CuviColorOps
    Dim cuviAL As CuviArithmeticLogical
    Dim cuviGT As CuviGeometryTransform

    Dim inData As Byte()
    Dim outData As Byte()
    Dim img2 As Byte()
    Dim inImgData32 As Byte()
    Dim inImgData32_2 As Byte()
    Dim outImgData32 As Byte()

    Dim img32f As Single()
    Dim histogram As UInt32()
    Dim histSize As Integer

    Dim data As IntPtr
    Dim retVal As Integer
    Dim bmp As Bitmap
    Dim bmpData As BitmapData
    Dim stream As IO.MemoryStream
    Dim rect As Rectangle


    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        cuviColor = New CuviColorOps(3384, 2708)
        cuviAL = New CuviArithmeticLogical(3384, 2708)
        cuviGT = New CuviGeometryTransform(3384, 2708)

        rect = New Rectangle(0, 0, 3384, 2708)
        outData = New Byte(cuviColor.outImgSize) {}
        img2 = New Byte(cuviColor.outImgSize) {}
        inImgData32 = New Byte(cuviAL.outImgSize32f) {}
        inImgData32_2 = New Byte(cuviAL.outImgSize32f) {}
        outImgData32 = New Byte(cuviAL.outImgSize32f) {}
        img32f = New Single(cuviAL.outImgSize) {}


        inData = My.Computer.FileSystem.ReadAllBytes("datasets/Fluorescence bytes")
        bmp = New Bitmap(3384, 2708, PixelFormat.Format24bppRgb)
        bmpData = bmp.LockBits(rect, ImageLockMode.ReadWrite, bmp.PixelFormat)
        cuviColor.DemosaicBytes(inData(0), outData(0))
        Marshal.Copy(outData, 0, bmpData.Scan0, outData.Length)
        bmp.UnlockBits(bmpData)
        PictureBox1.Image = bmp

        'Creating second image for testing
        Dim inData2 As Byte()
        inData2 = My.Computer.FileSystem.ReadAllBytes("datasets/Brightfield bytes")
        cuviColor.DemosaicBytes(inData2(0), img2(0))


    End Sub

    Public Sub GetBytes()
        bmpData = bmp.LockBits(rect, ImageLockMode.ReadWrite, bmp.PixelFormat)
        inData = New Byte(bmpData.Stride * bmp.Height) {}
        Marshal.Copy(bmpData.Scan0, inData, 0, bmpData.Stride * bmp.Height)
        bmp.UnlockBits(bmpData)
    End Sub

    Public Sub SetBytes()
        bmpData = bmp.LockBits(rect, ImageLockMode.ReadWrite, bmp.PixelFormat)
        Marshal.Copy(outData, 0, bmpData.Scan0, outData.Length)
        bmp.UnlockBits(bmpData)
        PictureBox1.Image = bmp
        PictureBox1.Refresh()
    End Sub

    Public Sub PlotHistogram(chrt As DataVisualization.Charting.Chart)

        chrt.Series(0).Points.Clear()

        For j = 0 To histSize
            chrt.Series(0).Points.AddXY(j + 1, histogram(j))
        Next

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles btnDemosaic.Click
        GetBytes()
        retVal = cuviColor.DemosaicBytes(inData(0), outData(0))
        SetBytes()
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles btnLowLight.Click
        GetBytes()
        retVal = cuviColor.LowLight(inData(0), outData(0))
        SetBytes()
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles btnAbs.Click
        GetBytes()
        retVal = cuviAL.Abs(inData(0), outData(0))
        SetBytes()
    End Sub


    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles btnAbsDiff.Click
        GetBytes()
        retVal = cuviAL.AbsDiff(inData(0), img2(0), outData(0))
        SetBytes()
    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        inData = My.Computer.FileSystem.ReadAllBytes("datasets/Fluorescence bytes")
        bmpData = bmp.LockBits(rect, ImageLockMode.ReadWrite, bmp.PixelFormat)
        Marshal.Copy(inData, 0, bmpData.Scan0, inData.Length)
        bmp.UnlockBits(bmpData)
        PictureBox1.Image = bmp
    End Sub

    Private Sub Button6_Click(sender As Object, e As EventArgs) Handles btnAdd.Click
        GetBytes()
        retVal = cuviAL.Add(inData(0), img2(0), outData(0))
        SetBytes()
    End Sub

    Private Sub Button7_Click(sender As Object, e As EventArgs) Handles btnFFT.Click
        GetBytes()
        cuviColor.FFT2D(inData(0), outData(0))
        SetBytes()
    End Sub

    Private Sub Button8_Click(sender As Object, e As EventArgs) Handles btnHistogram.Click
        GetBytes()

        histSize = cuviColor.GetHistSize(inData(0))
        histogram = New UInt32(histSize) {}
        cuviColor.CalcHist(inData(0), histogram(0))
        PlotHistogram(Chart1)

    End Sub

    Private Sub Button9_Click(sender As Object, e As EventArgs) Handles btnCbrt.Click
        GetBytes()
        cuviAL.cbrt(inData(0), outData(0))
        SetBytes()
    End Sub

    Private Sub Button10_Click(sender As Object, e As EventArgs) Handles btnNOT.Click
        GetBytes()
        cuviAL.NOT(inData(0), outData(0))
        SetBytes()
    End Sub

    Private Sub Button11_Click(sender As Object, e As EventArgs) Handles btnAND.Click
        GetBytes()
        cuviAL.AND(inData(0), img2(0), outData(0))
        SetBytes()
    End Sub

    Private Sub btnAutoColor_Click(sender As Object, e As EventArgs) Handles btnAutoColor.Click
        GetBytes()
        cuviColor.AutoColor(inData(0), outData(0))
        SetBytes()
    End Sub

    Private Sub btnMultiply_Click(sender As Object, e As EventArgs) Handles btnMultiply.Click
        GetBytes()
        cuviAL.Multiply(inData(0), img2(0), outData(0))
        SetBytes()
    End Sub

    Private Sub tbMultScalar_TextChanged(sender As Object, e As KeyEventArgs) Handles tbMultScalar.KeyDown
        If (e.KeyCode = Keys.KeyCode.Return) Then
            GetBytes()
            cuviAL.Multiply(inData(0), CInt(tbMultScalar.Text), outData(0))
            SetBytes()
        End If
    End Sub

    Private Sub Button2_Click_1(sender As Object, e As EventArgs) Handles Button2.Click
        GetBytes()
        cuviAL.Divide(inData(0), img2(0), outData(0))
        SetBytes()
    End Sub

    Private Sub Button3_Click_1(sender As Object, e As EventArgs) Handles Button3.Click
        GetBytes()

        cuviAL.UseFloats(True)
        cuviAL.ImgTo32(inData(0), inImgData32(0))
        cuviAL.ImgTo32(img2(0), inImgData32_2(0))
        cuviAL.Exp(inImgData32(0), inImgData32(0))
        cuviAL.FloatsToImg(inImgData32(0), outData(0))
        cuviAL.Add(inImgData32(0), inImgData32_2(0), inImgData32(0))
        cuviAL.FloatsToImg(inImgData32(0), outData(0))
        cuviAL.UseFloats(False)
        'bytesToFloats()

        SetBytes()
    End Sub

    Private Sub bytesToFloats()
        For i As Integer = 0 To inImgData32.Length - 5 Step 4
            img32f(i / 4) = BitConverter.ToSingle(inImgData32, i)
        Next
    End Sub

    Private Sub Button4_Click_1(sender As Object, e As EventArgs) Handles Button4.Click
        GetBytes()
        cuviAL.UseFloats(True)
        cuviAL.ImgTo32(inData(0), inImgData32(0))
        cuviAL.Ceil(inImgData32(0), inImgData32(0))
        cuviAL.FloatsToImg(inImgData32(0), outData(0))
        cuviAL.UseFloats(False)
        SetBytes()
    End Sub
End Class
