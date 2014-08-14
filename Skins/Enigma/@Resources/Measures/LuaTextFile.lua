function Initialize()

	sFileToRead = SELF:GetOption('FileToRead')
	iIndexToReturn = SELF:GetNumberOption('IndexToReturn')
	
end

function Update()
	
	sFileToRead = SELF:GetOption('FileToRead')
	iIndexToReturn = SELF:GetNumberOption('IndexToReturn')
	
	hReadingFile = io.input(sFileToRead)
	
	sAllText = io.read("*all")
	
	tSplit = Split(sAllText,";")
	
	io.close(hReadingFile)
	
	return tostring(tSplit[iIndexToReturn])
	
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