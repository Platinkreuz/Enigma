;---------------------------------------------------------------------
; MEASURES

[MeasureUTC]
Measure=Time
TimeZone=0

[MeasureUNIX]
Measure=Calc
Formula=MeasureUTC-11644473600

[MeasureTimeZone]
Measure=Plugin
Plugin=WebParser
UpdateRate=3600
Url=https://maps.googleapis.com/maps/api/timezone/xml?location=#CurrentCodeLat#,#CurrentCodeLon#&timestamp=[&MeasureUNIX]&sensor=false
RegExp=(?siU)<raw_offset>(.*)</dst_offset>
StringIndex=1
DynamicVariables=1
RegExpSubstitute=1
Substitute="(.*)</raw_offset>[^<]*<dst_offset>(.*)":"((\1+\2)/3600)"

[MeasureTime]
Measure=Time
TimeZone=[MeasureTimeZone]
DynamicVariables=1
DaylightSavingTime=0

[MeasureTimeSeconds]
Measure=Time
TimeZone=[MeasureTimeZone]
Format="%#S"
DynamicVariables=1
DaylightSavingTime=0

[MeasureClock]
Measure=Time
Format="%#I.%M %p"
TimeZone=[MeasureTimeZone]
Substitute="PM":"pm","AM":"am"
DynamicVariables=1
DaylightSavingTime=0

[MeasureBar]
Measure=Calc
Formula=MeasureTimeSeconds / 60

;---------------------------------------------------------------------
; METERS

[Background]
Meter=Image
MeterStyle=Style#Variant#Background

[Icon]
Meter=IMAGE
MeterStyle=Style#Variant#Icon | StyleClockIcon

[Seconds]
Meter=ROUNDLINE
MeterStyle=Style#Variant#Icon | StyleClockHands | StyleClockSeconds
MeasureName=MeasureTime

[Hours]
Meter=ROUNDLINE
MeterStyle=Style#Variant#Icon | StyleClockHands | StyleClockHours
MeasureName=MeasureTime

[Minutes]
Meter=ROUNDLINE
MeterStyle=Style#Variant#Icon | StyleClockHands | StyleClockMinutes
MeasureName=MeasureTime

[Text]
Meter=STRING
MeterStyle=Style#Variant#Text | StyleWorld#Variant#Text
MeasureName=MeasureClock
MeasureName2=MeasureWeatherCity

[Label]
Meter=STRING
MeterStyle=Style#Variant#Label | StyleWorld#Variant#Label
MeasureName=MeasureWeatherCity
MeasureName2=MeasureClock

[Bar]
Meter=BAR
MeterStyle=Style#Variant#Bar
MeasureName=MeasureBar
