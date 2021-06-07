### to windows compiler

run developer command prompt as administrator
```
cd /D ${file_path_to_cpp_file}  ## navigate to d drive
cl /EHsc ${file_name}.cpp       ## compile source file
echo %ERRORLEVEL%               ## to see the return status
```

cpp file ->translation unit -> obj file