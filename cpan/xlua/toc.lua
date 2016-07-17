#!lua

--[[
# Table of contents
# one
## one two
### one two 3
]]

while true do
  local line = io.stdin:read()
  if not line then break end
  if not line:match('^#') then goto NEXT_LINE end
  local title, depth = line:gsub('#', '')
  title = title:gsub('^ *', '')
  title = title:gsub(' *$', '')
  lowered = title:lower()
  if lowered:match('[ ]+table[+]of[ ]+contents[+]') then goto NEXT_LINE end
  local href = lowered:gsub(' ', '-')
  io.stdout:write(string.format('%s* [%s](%s)\n', string.rep('  ', depth-1), title, href))
  ::NEXT_LINE::
end

