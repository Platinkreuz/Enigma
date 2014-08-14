require "C:\Users\Rodney Bryan Smith\Documents\GitHub\lua-mpd\mpd.lua"

function Initialize()
	sPlayerType = SELF:GetOption('PlayerType')
	
	m = mpd.connect("192.168.0.106", 6600)
	
end

function Update()
	local tSong = m:currentsong()
	local tStatus = m:status()
	
	if sPlayerType == "TITLE" then return tSong[5]
	elseif sPlayerType == "ALBUM" then return tSong[3]
	elseif sPlayerType == "ARTIST" then return tSong[4]
	elseif sPlayerType == "DURATION" then return tSong[2]
	elseif sPlayerType == "POSITION" then
		tSplit = Split(tStatus[10], ":")
		return tSplit[1]
	elseif sPlayerType == "PROGRESS" then
		tSplit = Split(tStatus[10], ":")
		return tSplit[1] / tSplit[2]
	elseif sPlayerType == "STATE" then
		if tStatus[7] == "play" then return 1
		elseif tStatus[7] == "stop" then return 0
		elseif tStatus[7] == "pause" then return 2
		end
	elseif sPlayerType == "REPEAT" then return tStatus[2]
	elseif sPlayerType == "SHUFFLE" then return tStatus[3]
	end
	
end

function Split(str,delimiter)
	assert(type(str)=="string","bad argument #1 to 'split' (string expected, got "..type(str))
	assert(type(delimiter)=="string","bad argument #2 to 'split' (string expected, got "..type(delimiter))
	
	local t = {}
	
	for m in str:gmatch("(.-)%"..delimiter) do
		table.insert(t,m)
	end
	
	return t
	
end

function Previous()
	m:previous()
end

function PlayPause()
	local tStatus = m:status()
	local sState = tStatus[7]
	
	if sState == "play" then m:pause()
	elseif sState == "stop" then m:play()
	elseif sState == "pause" then m:unpause()
	end
	
end

function Next()
	m:next()
end

function SetRepeat()
	local tStatus = m:status()
	local iRepeat = tStatus[2]
	
	if iRepeat == 0 then m:set_repeat(true)
	elseif iRepeat == 1 then m:set_repeat(false)
	end
	
end

function SetShuffle()
	local tStatus = m:status()
	local iRandom = tStatus[3]
	
	if iRandom == 0 then m:set_random(true)
	elseif iRandom == 1 then m:set_random(false)
	end
	
end