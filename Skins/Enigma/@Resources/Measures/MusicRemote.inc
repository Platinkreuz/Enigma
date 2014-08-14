[MeasureMediaPlayer]
Measure=Plugin
Plugin=NowPlaying
PlayerName=#MusicPlayer#
PlayerType=FILE

[MeasureTrack]
Measure=Script
ScriptFile=#@#Measures\LuaTextFile.lua
FileToRead=\\BRYERS\My Documents\NowPlaying.txt
IndexToReturn=2

[MeasureAlbum]
Measure=Script
ScriptFile=#@#Measures\LuaTextFile.lua
FileToRead=\\BRYERS\My Documents\NowPlaying.txt
IndexToReturn=4

[MeasureArtist]
Measure=Script
ScriptFile=#@#Measures\LuaTextFile.lua
FileToRead=\\BRYERS\My Documents\NowPlaying.txt
IndexToReturn=3

[MeasureCover]
Measure=Script
ScriptFile=#@#Measures\LuaTextFile.lua
FileToRead=\\BRYERS\My Documents\NowPlaying.txt
IndexToReturn=1

[MeasureTimeDuration]
Measure=Plugin
Plugin=NowPlaying
PlayerName=[MeasureMediaPlayer]
PlayerType=DURATION

[MeasureTimePosition]
Measure=Script
ScriptFile=#@#Measures\LuaTextFile.lua
FileToRead=\\BRYERS\My Documents\NowPlaying.txt
IndexToReturn=6
IfAboveValue=0

[MeasureTimeProgress]
Measure=Script
ScriptFile=#@#Measures\LuaTextFile.lua
FileToRead=\\BRYERS\My Documents\NowPlaying.txt
IndexToReturn=5
IfAboveAction=[!SetOption "Track" "Text" "%1"][!SetOption "Album" "Text" "%1"][!SetOption "Artist" "Text" "%1"][!SetOption "Time" "Text" "%1"]
IfEqualValue=0
IfEqualAction=[!SetOption "Track" "Text" " "][!SetOption "Album" "Text" " "][!SetOption "Artist" "Text" " "][!SetOption "Time" "Text" " "]

[MeasureState]
Measure=Plugin
Plugin=NowPlaying.dll
PlayerName=[MeasureMediaPlayer]
PlayerType=STATE

[MeasureRepeat]
Measure=Plugin
Plugin=NowPlaying
PlayerName=[MeasureMediaPlayer]
PlayerType=REPEAT

[MeasureShuffle]
Measure=Plugin
Plugin=NowPlaying
PlayerName=[MeasureMediaPlayer]
PlayerType=SHUFFLE