[Variables]
VolumioURL=http://192.168.0.118/_player_engine.php

;[MeasureParent]
;Measure=Plugin
;Plugin=WebParser
;Url=#VolumioURL#
;RegExp=.*"repeat":"(.*?)","random":"(.*?)".*"state":"(.*?)".*(?(?="time")"time":"(.*?)","elapsed":"(.*?)".*"song_percent":(.*?),|"song_percent":(.*?),"elapsed":"(.*?)","time":(.*?),).*"currentartist":"*(.*?)"*,"currentsong":"*(.*?)"*,"currentalbum":"*(.*?)"*,.*
;RegExp=.*"repeat":"(.*?)","random":"(.*?)".*"state":"(.*?)".*"time":"(.*?)","elapsed":"(.*?)".*"song_percent":(.*?),.*"currentartist":"*(.*?)"*,"currentsong":"*(.*?)"*,"currentalbum":"*(.*?)"*,.*
;UpdateRate=1

[MeasureParent1]
Measure=Plugin
Plugin=WebParser
Url=#VolumioURL#
RegExp='"repeat":"(.*?)","random":"(.*?)".*"state":"(.*?)",'
UpdateRate=1

[MeasureParent2]
Measure=Plugin
Plugin=WebParser
Url=#VolumioURL#
RegExp='(?:"time":"(.*?)","elapsed":"(.*?)".*"song_percent":(.*?),)|(?:"song_percent":(.*?),"elapsed":"(.*?)","time":(.*?),)'
UpdateRate=1

[MeasureParent3]
Measure=Plugin
Plugin=WebParser
Url=#VolumioURL#
RegExp='"currentartist":"*(.*?)"*,"currentsong":"*(.*?)"*,"currentalbum":"*(.*?)"*,'
UpdateRate=1

[MeasureTrack]
Measure=Plugin
Plugin=WebParser
Url=[MeasureParent3]
StringIndex=2
UpdateRate=1
Group=Volumio

[MeasureAlbum]
Measure=Plugin
Plugin=WebParser
Url=[MeasureParent3]
StringIndex=3
UpdateRate=1
Group=Volumio

[MeasureArtist]
Measure=Plugin
Plugin=WebParser
Url=[MeasureParent3]
StringIndex=1
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
Url=[MeasureParent2]
StringIndex=1
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
Url=[MeasureParent2]
StringIndex=2
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
Url=[MeasureParent2]
StringIndex=3
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
Url=[MeasureParent1]
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
Url=[MeasureParent1]
StringIndex=1
UpdateRate=1
Group=Volumio

[MeasureShuffleRaw]
Measure=Plugin
Plugin=WebParser
Url=[MeasureParent1]
StringIndex=2
UpdateRate=1
Group=Volumio