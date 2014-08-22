;---------------------------------------------------------------------
; MEASURES

[MeasureParent]
Measure=Plugin
Plugin=WebParser
Url="file://%appdata%/johnsadventures.com/Background Switcher/Status.xml"
RegExp=(?s)<current_pictures>.*Info="(.*?)".*</current_pictures>
;RegExp=(?s)<current_pictures>.*Info="(.*?)&#xD;&#xA;(.*?)(?:&#xD;&#xA;(.*?))*".*</current_pictures>
;RegExp=(?s)<current_pictures>.*Info="(.*?)(?(?=&#xD;&#xA;)(.*?))&#xD;&#xA;(.*?)".*</current_pictures>
UpdateRate=1

[MeasureInfo]
Measure=Plugin
Plugin=WebParser
Url=[MeasureParent]
StringIndex=1
Substitute="&#xD;&#xA;":" | "
UpdateRate=1

;[MeasureInfo1]
;Measure=Plugin
;Plugin=WebParser
;Url=[MeasureParent]
;StringIndex=1
;UpdateRate=1

;[MeasureInfo2]
;Measure=Plugin
;Plugin=WebParser
;Url=[MeasureParent]
;StringIndex=2
;UpdateRate=1

;[MeasureInfo3]
;Measure=Plugin
;Plugin=WebParser
;Url=[MeasureParent]
;StringIndex=3
;UpdateRate=1

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text
Text=""

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label
MeasureName=MeasureInfo
;MeasureName2=MeasureInfo2
;MeasureName3=MeasureInfo3
;Text="%1 | %2 | %3"
H=10