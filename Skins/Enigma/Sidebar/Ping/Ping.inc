;---------------------------------------------------------------------
; MEASURES

[Variables]
RemoteTarget=8.8.8.8

[MeasureGateway]
Measure=Plugin
Plugin=SysInfo
SysInfoType=GATEWAY_ADDRESS
;SysInfoType=ADAPTER_DESCRIPTION
SysInfoData=4

[MeasurePing]
Measure=Plugin
Plugin=PingPlugin
DestAddress=#RemoteTarget#
UpdateRate=5
Timeout=30000
TimeoutValue=0
MaxValue=30000

[MeasurePingTimeout]
Measure=Plugin
Plugin=PingPlugin
DestAddress=#RemoteTarget#
UpdateRate=5
Timeout=30000
TimeoutValue=60000
MaxValue=0
MinValue=0

[MeasureNetworkPing]
Measure=Plugin
Plugin=PingPlugin
DestAddress=[MeasureGateway]
UpdateRate=5
Timeout=30000
TimeoutValue=30000
MaxValue=30000
DynamicVariables=1

[MeasureNetInFloating]
Measure=NetIn
MaxValue=1000000
MinValue=0

[MeasureNetInPercent]
Measure=Calc
Formula=MeasureNetInFloating / #NetworkMaxDownload#

[MeasureNetOutFloating]
Measure=NetOut
MaxValue=1000000
MinValue=0

[MeasureNetOutPercent]
Measure=Calc
Formula=MeasureNetOutFloating / #NetworkMaxUpload#

[MeasureSSID]
Measure=Plugin
Plugin=WifiStatus
WifiInfoType=SSID
WifiIntfID=0
WifiListStyle=0

[MeasureWiFi]
Measure=Plugin
Plugin=WifiStatus
WifiInfoType=QUALITY
WifiIntfID=0
WifiListStyle=0

[MeasureLAN]
Measure=Plugin
Plugin=SysInfo
SysInfoType=IP_ADDRESS
SysInfoData=1

[MeasureWAN]
Measure=Plugin
Plugin=WebParser
UpdateRate=21600
Url=http://checkip.dyndns.org
RegExp="(?siU)Address: (.*)</body>"
StringIndex=1

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

[Label1]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label1
Text="REMOTE PING"
X=84

[Text1]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text3
Text=#RemoteTarget#
X=95
StringAlign=LEFT

[Label2]
Meter=STRING
MeterStyle=StyleSystem#Variant#Label | StyleSystem#Variant#Label2
Text="LOCAL PING"
X=84

[Text2]
Meter=STRING
MeterStyle=StyleSystem#Variant#Text | StyleSystem#Variant#Text4
MeasureName=MeasureGateway
X=95
StringAlign=LEFT

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

;[Border5]
;Meter=IMAGE
;MeterStyle=StyleSystem#Variant#Border | StyleSystem#Variant#Border5

;-----------------------
; HISTOGRAMS

[Ping]
Meter=Line
MeterStyle=StyleSystem#Variant#Graph | StyleSystem#Variant#Graph1
MeasureName=MeasurePing

[PingTimeout]
Meter=Histogram
MeterStyle=StyleSystem#Variant#Graph | StyleSystem#Variant#Graph1
MeasureName=MeasurePingTimeout
Autoscale=1

[PingNetwork]
Meter=Line
MeterStyle=StyleSystem#Variant#Graph | StyleSystem#Variant#Graph2
MeasureName=MeasureNetworkPing

;-----------------------
; LOWER TEXT

[RemotePingLabel]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphLabel | StyleSystem#Variant#GraphLabel1
; Prefix="· "
Text="REMOTE"

[RemotePingNumber]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphText | StyleSystem#Variant#GraphText1
MeasureName=MeasurePing
X=51
;AutoScale=1
NumOfDecimals=0

[LocalPingLabel]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphLabel | StyleSystem#Variant#GraphLabel2
Text="LOCAL"
; Postfix=" ·"

[LocalPingNumber]
Meter=STRING
MeterStyle=StyleSystem#Variant#GraphText | StyleSystem#Variant#GraphText2
MeasureName=MeasureNetworkPing
X=141
;AutoScale=1
NumOfDecimals=0