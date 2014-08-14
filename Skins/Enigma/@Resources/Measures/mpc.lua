function Initialize()
	sPlayerType = SELF:GetOption('PlayerType')
end

function Update()
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
	SKIN:Bang('C:\Program Files (x86)\mpc-0.22\mpc.exe', 'prev')
end

function PlayPause()
	SKIN:Bang('C:\Program Files (x86)\mpc-0.22\mpc.exe', 'toggle')
end

function Next()
	SKIN:Bang('C:\Program Files (x86)\mpc-0.22\mpc.exe', 'next')
end

function SetRepeat()
	SKIN:Bang('C:\Program Files (x86)\mpc-0.22\mpc.exe', 'repeat')
end

function SetShuffle()
	SKIN:Bang('C:\Program Files (x86)\mpc-0.22\mpc.exe', 'random')
end