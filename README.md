# README

This repo is used to demo one issue about vstest.console.exe.

## Environment

- Windows 11 x64 22H2 22621.1635
- Visual Studio 2022 Community 17.5.0
- VS Code 1.78.0

## Startup and Good case

Run commands under root dir in git bash.

```shell
# restore packages
nuget restore
nuget restore packages.config -PackagesDirectory packages

# build
msbuild.exe -t:rebuild -p:configuration=release -p:platform=x64 UnitTestNetCppLab.sln

# run vstest.console.exe to collect code coverage data
packages/Microsoft.TestPlatform.17.5.0/tools/net462/Common7/IDE/Extensions/TestPlatform/vstest.console.exe x64/Release/GoogleTest.Tests.exe /TestAdapterPath:packages/GoogleTestAdapter.0.18.0/build/_common /Collect:"Code Coverage;Format=xml;CoverageFileName=coverage" /ResultsDirectory:build/unit-test
```

Now, the vstest.console.exe command is run successfully with the output file `build/unit-test/<id>/coverage.xml` which has right coverage result.

Next step to represent the bug of vstest.console.exe/datacollector.exe is to copy 2 folders into different sub-folders and re-run the vstest.console.exe command.

- x64
- packages

## The issue

In this repo, it already prepared different folders cases. When I re-run above vsteest.console.exe under certain sub-folder, it shows the error and no right content in the coverage.xml file.

The error message: `Data collect "Code Coverage" message: No code coverage data available. Profiler was not initialized.`

Below are good and bad cases for different sub-folders:

1st time: Under same folder, but different sub-dir name, shorter(length<=10) is good
- `$(solutionDir)sample/UnitTestNetCpp`: Bad Case
- `$(solutionDir)sample/UTNetCpp`: Good Case

2st time: Same folder name, under different folder
- `$(solutionDir)UnitTestNetCpp` : Good Case (although folder name length > 10)
- `$(solutionDir)sample/UnitTestNetCpp`: Bad Case

3rd time: Under same folder, but not sub-folder
- `$(solutionDir)aaaaaaaaaa` : Good Case
- `$(solutionDir)aaaaaaaaaaaaaaaaaaaaa`: Bad Case

4th time: The bad case folder but is good if put it in the driver root
- `$(solutionDir)aaaaaaaaaaaaaaaaaaaaa`: Bad Case
- `d:\aaaaaaaaaaaaaaaaaaaaa`: Good Case

So guess its behavior:
- depends on the length of folder name
- depends on the depth of folder
