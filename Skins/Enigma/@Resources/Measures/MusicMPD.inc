[MeasureTrack]
Measure=Plugin
Plugin=Webparser
Url=file://%TEMP%\mpc.txt
RegExp="(.*) - (.*)"
StringIndex=2
UpdateRate=1

[MeasureAlbum]
;Measure=Script
;ScriptFile=#@#Measures\mpc.lua
;PlayerType=ALBUM

[MeasureArtist]
Measure=Plugin
Plugin=Webparser
Url=file://%TEMP%\mpc.txt
RegExp="(.*) - (.*)"
StringIndex=1
UpdateRate=1

[MeasureCover]
;Measure=Plugin
;Plugin=NowPlaying
;PlayerName=[MeasureMediaPlayer]
;PlayerType=COVER

[MeasureTimeDuration]
Measure=Plugin
Plugin=Webparser
Url=file://%TEMP%\mpc.txt
RegExp="(\d+:\d+)/(\d+:\d+)"
StringIndex=2
UpdateRate=1

[MeasureTimePosition]
Measure=Plugin
Plugin=Webparser
Url=file://%TEMP%\mpc.txt
RegExp="(\d+:\d+)/(\d+:\d+)"
StringIndex=1
UpdateRate=1

[MeasureTimeProgressPercent]
Measure=Plugin
Plugin=Webparser
Url=file://%TEMP%\mpc.txt
RegExp="(\d+)%"
StringIndex=1
UpdateRate=1

[MeasureTimeProgress]
Measure=Calc
Formula=MeasureTimeProgressPercent / 100

[MeasureStateRaw]
Measure=Plugin
Plugin=Webparser
Url=file://%TEMP%\mpc.txt
RegExp="\[(\w+)\]"
StringIndex=1
UpdateRate=1

[MeasureState]
Measure=Calc
Formula=MeasureStateRaw = "playing" ? 1 : (MeasureStateRaw = "stopped" ? 0 : 2)

[MeasureRepeatRaw]
Measure=Plugin
Plugin=Webparser
Url=file://%TEMP%\mpc.txt
RegExp="repeat: (\w+)"
StringIndex=1
UpdateRate=1

[MeasureRepeat]
Measure=Calc
Formula=MeasureRepeatRaw = "on"

[MeasureShuffleRaw]
Measure=Plugin
Plugin=Webparser
Url=file://%TEMP%\mpc.txt
RegExp="random: (\w+)"
StringIndex=1
UpdateRate=1

[MeasureShuffle]
Measure=Calc
Formula=MeasureShuffleRaw = "on"