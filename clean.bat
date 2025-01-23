@echo off
for /d %%D in (build\*) do if /i not "%%~nxD"=="_deps" rd /s /q "%%D"
for %%F in (build\*) do if not "%%~nxF"=="_deps" del /q "%%F"
del /Q bin