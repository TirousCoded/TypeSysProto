@echo off
echo Transcompiling grammars...
taulc compile specs proto\grammars\specs.taul proto\src\codegen\specs-codegen.h -i=taul -t
echo Done!
pause