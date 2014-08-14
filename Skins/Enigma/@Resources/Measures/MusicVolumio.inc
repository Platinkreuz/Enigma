[Variables]
VolumioURL=http://192.168.0.118/_player_engine.php

[MeasureParent]
Measure=Plugin
Plugin=WebParser
;Url=http://volumio.local/_player_engine.php
Url=#VolumioURL#
RegExp=.*"repeat":"(.*?)","random":"(.*?)".*"state":"(.*?)".*"time":"(.*?)","elapsed":"(.*?)".*"song_percent":(.*?),.*"currentartist":"*(.*?)"*,"currentsong":"*(.*?)"*,"currentalbum":"*(.*?)"*,.*
UpdateRate=1

;[MeasurePing]
;Measure=Plugin
;Plugin=PingPlugin
;DestAddress=#VolumioURL#
;UpdateRate=60
;Timeout=5000
;TimeoutValue=999999
;IfBelowValue=10000
;IfBelowAction=[!EnableMeasureGroup Volumio][!ShowMeterGroup *]
;IfEqualValue=999999
;IfEqualAction=[!DisableMeasureGroup Volumio][!HideMeterGroup *]
;IfAboveValue=30000
;IfAboveAction=[!DisableMeasureGroup Volumio][!HideMeterGroup *]

[MeasureTrack]
Measure=Plugin
Plugin=WebParser
Url=[MeasureParent]
StringIndex=8
UpdateRate=1
Group=Volumio

[MeasureAlbum]
Measure=Plugin
Plugin=WebParser
Url=[MeasureParent]
StringIndex=9
UpdateRate=1
Group=Volumio

[MeasureArtist]
Measure=Plugin
Plugin=WebParser
Url=[MeasureParent]
StringIndex=7
UpdateRate=1
Group=Volumio

;[MeasureCover]
;Measure=Plugin
;Plugin=WebParser
;Url=[MeasureParent]
;UpdateRate=1
;RegExpSubstitute=1
;Substitute='(.*)"currentartist":"(.*?)"(.*)"currentalbum":"(.*?)"(.*)':"%userprofile%\My Music\\2\\4\\4.jpg"

;Format=([MeasureParent])
;RegExpSubstitute=1
;Substitute=
;DynamicVariables=1

[MeasureTimeDurationRaw]
Measure=Plugin
Plugin=WebParser
Url=[MeasureParent]
StringIndex=4
UpdateRate=1
Substitute="":"1"
Group=Volumio

[MeasureTimeDuration]
Measure=Time
TimeStamp=([MeasureTimeDurationRaw])
Format=%M:%S
Substitute="00:00":""
DynamicVariables=1
Group=Volumio

[MeasureTimePositionRaw]
Measure=Plugin
Plugin=WebParser
Url=[MeasureParent]
StringIndex=5
UpdateRate=1
Substitute="":"0"
Group=Volumio

[MeasureTimePosition]
Measure=Time
TimeStamp=([MeasureTimePositionRaw])
Format=%M:%S
Substitute="00:00":""
DynamicVariables=1
Group=Volumio

[MeasureTimeProgress]
Measure=Plugin
Plugin=WebParser
Url=[MeasureParent]
StringIndex=6
UpdateRate=1
MinValue=0
MaxValue=100
Group=Volumio

;[MeasureTimeProgress]
;Measure=Calc
;Formula=MeasureTimePositionRaw/MeasureTimeDurationRaw*100
;UpdateRate=1
;MinValue=0
;MaxValue=100
;Group=Volumio

[MeasureStateRaw]
Measure=Plugin
Plugin=WebParser
Url=[MeasureParent]
StringIndex=3
UpdateRate=1
Substitute="play":"1","pause":"2","stop":"0"
Group=Volumio

[MeasureState]
Measure=Calc
Formula=[MeasureStateRaw]
UpdateRate=1
DynamicVariables=1
Group=Volumio

[MeasureRepeat]
Measure=Plugin
Plugin=WebParser
Url=[MeasureParent]
StringIndex=1
UpdateRate=1
Group=Volumio

[MeasureShuffleRaw]
Measure=Plugin
Plugin=WebParser
Url=[MeasureParent]
StringIndex=2
UpdateRate=1
Group=Volumio