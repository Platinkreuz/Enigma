;---------------------------------------------------------------------
; MEASURES

[MeasureName]
Measure=Plugin
Plugin=Plugins\GPUInfo_ohm.dll
mod=name
vidindex=0

[MeasureTemperature]
Measure=Plugin
Plugin=Plugins\GPUInfo_ohm.dll
mod=coretemperature
vidindex=0

[MeasureFanRPM]
Measure=Plugin
Plugin=Plugins\GPUInfo_ohm.dll
mod=coolerrpm
vidindex=0

[MeasureFan]
Measure=Plugin
Plugin=Plugins\GPUInfo_ohm.dll
mod=coolerlevel
vidindex=0
MaxValue=100

[MeasureUsage]
Measure=Plugin
Plugin=Plugins\GPUInfo_ohm.dll
mod=usage
vidindex=0
MaxValue=100

[MeasureVendor]
Measure=Plugin
Plugin=Plugins\GPUInfo_ohm.dll
mod=vendor
update=true
vidindex=0

;---------------------------------------------------------------------
; METERS

;-----------------------
; FRAME

[Background]
Meter=IMAGE
MeterStyle=StyleSidebarBackground | StyleSystem#Variant#Background

[Border1]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#Border | StyleSystem#Variant#Border1

[VerticalBorderA]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#VerticalBorderA

[VerticalBorderB]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#VerticalBorderB

[Border2]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#Border | StyleSystem#Variant#Border2

;-----------------------
; LABELS & TEXT

[LabelName]
;Meter=STRING
;MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label1
;X=10
;W=(#SidebarWidth#-80)
;MeasureName=MeasureName
;Text="%1"
;StringAlign=LEFT

[Name]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label1
X=10
W=(#SidebarWidth#-80)
MeasureName=MeasureName
Text="%1"
StringAlign=LEFT
;Meter=STRING
;MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text1

[LabelTemperature]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label2
Text="TMP"

[Temperature]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text2
MeasureName=MeasureTemperature
Text="%1 °C"

[LabelUsage]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label3

[Usage]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text3

[LabelFanRPM]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label4

[FanRPM]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text4

;-----------------------

;-----------------------
; GRAPH FRAME

[Border3]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#Border | StyleSystem#Variant#Border3

[VerticalBorderC]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#VerticalBorderC

[Border4]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#Border | StyleSystem#Variant#Border4

[Border5]
Meter=IMAGE
MeterStyle=StyleSystem#Variant#Border | StyleSystem#Variant#Border5
Hidden=#HideBordersBottom#

;-----------------------
; HISTOGRAMS

[UsageGraph]
Meter=Histogram
MeterStyle=StyleSystem#Variant#Graph | StyleSystem#Variant#Graph1
MeasureName=MeasureUsage
Autoscale=1

[FanGraph]
Meter=Line
MeterStyle=StyleSystem#Variant#Graph | StyleSystem#Variant#Graph1
MeasureName=MeasureFan
AutoScale=0

;-----------------------
; LOWER TEXT

[UsageLabel]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphLabel | StyleSystem#Variant#GraphLabel1
Text="GPU"

[UsageNumber]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphText | StyleSystem#Variant#GraphText1
MeasureName=MeasureUsage
Postfix="%"

[FanLabel]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphLabel | StyleSystem#Variant#GraphLabel2
Text="FAN"

[FanNumber]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphText | StyleSystem#Variant#GraphText2
MeasureName=MeasureFan
Postfix="%"
